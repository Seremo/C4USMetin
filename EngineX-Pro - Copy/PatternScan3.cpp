#include "stdafx.h"
//#include "PatternScan.h"
//
//
//
//DWORD PatternScan::FindPattern(const char * pattern, const char * mask)
//{
//	{
//		HMODULE handle = GetModuleHandle(NULL);
//		PIMAGE_DOS_HEADER pDsHeader = PIMAGE_DOS_HEADER(handle);
//		PIMAGE_NT_HEADERS pPeHeader = PIMAGE_NT_HEADERS((LONG)handle + pDsHeader->e_lfanew);
//		PIMAGE_OPTIONAL_HEADER pOptionalHeader = &pPeHeader->OptionalHeader;
//		DWORD base = (ULONG)handle + pOptionalHeader->BaseOfCode;
//		DWORD size = pOptionalHeader->SizeOfCode;
//		DWORD patternLength = (DWORD)strlen(mask);
//
//		for (DWORD i = 0; i < size - patternLength; i++)
//		{
//			bool found = true;
//			for (DWORD j = 0; j < patternLength; j++)
//			{
//				found &= mask[j] == '?' || pattern[j] == *(char*)(base + i + j);
//			}
//			if (found)
//			{
//				return base + i;
//			}
//		}
//		return NULL;
//	}
//}
//
//
//ULONG PatternScan::GetAddress(HMODULE hmModule, PBYTE pbPattern, std::string sMask, ULONG uCodeBase, ULONG uSizeOfCode)
//{
//	BOOL bPatternDidMatch = FALSE;
//	HMODULE hModule = hmModule;
//
//	if (!hModule)
//		return 0x0;
//
//	PIMAGE_DOS_HEADER pDsHeader = PIMAGE_DOS_HEADER(hModule);
//	PIMAGE_NT_HEADERS pPeHeader = PIMAGE_NT_HEADERS(LONG(hModule) + pDsHeader->e_lfanew);
//	PIMAGE_OPTIONAL_HEADER pOptionalHeader = &pPeHeader->OptionalHeader;
//
//	if (uCodeBase == 0x0)
//		uCodeBase = (ULONG)hModule + pOptionalHeader->BaseOfCode;
//
//	if (uSizeOfCode == 0x0)
//		uSizeOfCode = pOptionalHeader->SizeOfCode;
//
//	ULONG uArraySize = sMask.length();
//
//	if (!uCodeBase || !uSizeOfCode || !uArraySize)
//		return 0x0;
//
//	for (size_t i = uCodeBase; i <= uCodeBase + uSizeOfCode; i++)
//	{
//		for (size_t t = 0; t < uArraySize; t++)
//		{
//			if (*((PBYTE)i + t) == pbPattern[t] || sMask.c_str()[t] == '?')
//				bPatternDidMatch = TRUE;
//
//			else
//			{
//				bPatternDidMatch = FALSE;
//				break;
//			}
//		}
//
//		if (bPatternDidMatch)
//			return i;
//	}
//
//	return 0x0;
//} 