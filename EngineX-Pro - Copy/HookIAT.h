#define PtrFromRva( base, rva ) ( ( ( PBYTE ) base ) + rva )
#pragma once
class HookIAT
{
private:
public:
	static BOOL Hook(const char* szModuleName, const char* szFuncName, PVOID pNewFunc, PVOID* pOldFunc)
	{
		PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)GetModuleHandle(NULL);
		PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)PtrFromRva(pDosHeader, pDosHeader->e_lfanew);

		// Make sure we have valid data
		if (pNtHeader->Signature != IMAGE_NT_SIGNATURE)
		{
			printf("[IAT] Failed\n");
			return FALSE;
		}		

		// Grab a pointer to the import data directory
		PIMAGE_IMPORT_DESCRIPTOR pImportDescriptor = (PIMAGE_IMPORT_DESCRIPTOR)PtrFromRva(pDosHeader, pNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);

		for (UINT uIndex = 0; pImportDescriptor[uIndex].Characteristics != 0; uIndex++)
		{
			char* szDllName = (char*)PtrFromRva(pDosHeader, pImportDescriptor[uIndex].Name);

			// Is this our module?
			if (_strcmpi(szDllName, szModuleName) != 0)
				continue;

			if (!pImportDescriptor[uIndex].FirstThunk || !pImportDescriptor[uIndex].OriginalFirstThunk)
			{
				printf("[IAT] Failed 2\n");
				return FALSE;
			}

			PIMAGE_THUNK_DATA pThunk = (PIMAGE_THUNK_DATA)PtrFromRva(pDosHeader, pImportDescriptor[uIndex].FirstThunk);
			PIMAGE_THUNK_DATA pOrigThunk = (PIMAGE_THUNK_DATA)PtrFromRva(pDosHeader, pImportDescriptor[uIndex].OriginalFirstThunk);

			for (; pOrigThunk->u1.Function != NULL; pOrigThunk++, pThunk++)
			{
				// We can't process ordinal imports just named
				if (pOrigThunk->u1.Ordinal & IMAGE_ORDINAL_FLAG)
					continue;

				PIMAGE_IMPORT_BY_NAME import = (PIMAGE_IMPORT_BY_NAME)PtrFromRva(pDosHeader, pOrigThunk->u1.AddressOfData);

				// Is this our function?
				if (_strcmpi(szFuncName, (char*)import->Name) != 0)
					continue;

				DWORD dwJunk = 0;
				MEMORY_BASIC_INFORMATION mbi;

				// Make the memory section writable
				VirtualQuery(pThunk, &mbi, sizeof(MEMORY_BASIC_INFORMATION));
				if (!VirtualProtect(mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &mbi.Protect))
				{
					printf("[IAT] Failed 3\n");
					return FALSE;
				}
					

				// Save the old pointer
				*pOldFunc = (PVOID*)(DWORD_PTR)pThunk->u1.Function;

				// Write the new pointer based on CPU type
				pThunk->u1.Function = (DWORD)(DWORD_PTR)pNewFunc;

				//if (VirtualProtect(mbi.BaseAddress, mbi.RegionSize, mbi.Protect, &dwJunk))
				if (VirtualProtect(mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READ, &dwJunk))
				{
					printf("[IAT] Success\n");
					return TRUE;
				}				
			}
		}
		printf("[IAT] Failed 4\n");
		return FALSE;
	}
};