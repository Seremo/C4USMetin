#include "stdafx.h"
#include "PatternScan2.h"
#define INRANGE(x,a,b)        (x >= a && x <= b) 
#define getBits( x )        (INRANGE(x,'0','9') ? (x - '0') : ((x&(~0x20)) - 'A' + 0xa))
#define getByte( x )        (getBits(x[0]) << 4 | getBits(x[1]))

inline
bool isMatch(const PBYTE addr, const PBYTE pat, const PBYTE msk)
{
	size_t n = 0;
	while (addr[n] == pat[n] || msk[n] == (BYTE)'?') {
		if (!msk[++n]) {
			return true;
		}
	}
	return false;
}

PBYTE PatternScan2::findPattern_v2(const PBYTE rangeStart, DWORD len, const char* pattern)
{
	size_t l = strlen(pattern);
	PBYTE patt_base = static_cast<PBYTE>(_alloca(l >> 1));
	PBYTE msk_base = static_cast<PBYTE>(_alloca(l >> 1));
	PBYTE pat = patt_base;
	PBYTE msk = msk_base;
	l = 0;
	while (*pattern) {
		if (*(PBYTE)pattern == (BYTE)'\?') {
			*pat++ = 0;
			*msk++ = '?';
			pattern += ((*(PWORD)pattern == (WORD)'\?\?') ? 3 : 2);
		}
		else {
			*pat++ = getByte(pattern);
			*msk++ = 'x';
			pattern += 3;
		}
		l++;
	}
	*msk = 0;
	pat = patt_base;
	msk = msk_base;
	for (DWORD n = 0; n < (len - l); ++n)
	{
		if (isMatch(rangeStart + n, patt_base, msk_base)) {
			return rangeStart + n;
		}
	}
	return NULL;
}

PBYTE PatternScan2::FindPattern(DWORD base, const char* pPattern)
{
	auto handle = base;
	PIMAGE_DOS_HEADER pDsHeader = PIMAGE_DOS_HEADER(handle);
	PIMAGE_NT_HEADERS pPeHeader = PIMAGE_NT_HEADERS((LONG)handle + pDsHeader->e_lfanew);
	PIMAGE_OPTIONAL_HEADER pOptionalHeader = &pPeHeader->OptionalHeader;
	PBYTE basex = (PBYTE)handle + pOptionalHeader->BaseOfCode;
	DWORD size = pOptionalHeader->SizeOfCode;
	return    PatternScan2::findPattern_v2(basex, size, pPattern);
}