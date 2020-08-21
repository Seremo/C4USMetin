#pragma once
class Security
{
private:
	static char NtAllocateVirtualMemoryOriginal[6];
public:
	static void SaveOriginalNT()
	{
		LPVOID NtAllocateVirtualMemory = GetProcAddress(LoadLibraryA("ntdll"), "NtAllocateVirtualMemory");
		if (NtAllocateVirtualMemory)
		{
			memcpy(NtAllocateVirtualMemoryOriginal, NtAllocateVirtualMemory, 6);
		}
	}

	static void RestoreOriginalNT()
	{
		LPVOID NtAllocateVirtualMemory = GetProcAddress(GetModuleHandleA("ntdll"), "NtAllocateVirtualMemory");
		if (NtAllocateVirtualMemory) {
			WriteProcessMemory(GetModuleHandle(NULL), NtAllocateVirtualMemory, NtAllocateVirtualMemoryOriginal, 6, NULL);
		}

		//LPVOID NtAllocateVirtualMemoryEx = GetProcAddress(LoadLibraryW(L"ntdll"), "NtAllocateVirtualMemoryEx");
		//if (NtAllocateVirtualMemoryEx) {
		//	char originalBytes[6];
		//	memcpy(originalBytes, NtAllocateVirtualMemoryEx, 6);
		//	WriteProcessMemory(GetModuleHandle(NULL), NtAllocateVirtualMemoryEx, originalBytes, 6, NULL);
		//}
		//HMODULE ntdllModule = LoadLibraryW(L"ntdll");
		//DWORD NtAllocateVirtualMemory = (DWORD)GetProcAddress(ntdllModule, "NtAllocateVirtualMemory");
		//if (NtAllocateVirtualMemory)
		//{
		//	MemoryExtension::MemSet(NtAllocateVirtualMemory, 0xB8, 1);
		//	MemoryExtension::MemSet(NtAllocateVirtualMemory, 0x18, 1);
		//	MemoryExtension::MemSet(NtAllocateVirtualMemory, 0x0, 1);
		//	MemoryExtension::MemSet(NtAllocateVirtualMemory, 0x0, 1);
		//	MemoryExtension::MemSet(NtAllocateVirtualMemory, 0x0, 1);
		//	MemoryExtension::MemSet(NtAllocateVirtualMemory, 0xBA, 1);
		//}
		//DWORD NtAllocateVirtualMemoryEx = (DWORD)GetProcAddress(ntdllModule, "NtAllocateVirtualMemoryEx");
		//MemoryExtension::MemSet(NtAllocateVirtualMemoryEx, 0xB1, 1);
		//MemoryExtension::MemSet(NtAllocateVirtualMemoryEx, 0x74, 1);
		//MemoryExtension::MemSet(NtAllocateVirtualMemoryEx, 0x0, 1);
		//MemoryExtension::MemSet(NtAllocateVirtualMemoryEx, 0x0, 1);
		//MemoryExtension::MemSet(NtAllocateVirtualMemoryEx, 0x0, 1);	
	}
};

char Security::NtAllocateVirtualMemoryOriginal[6] = "";