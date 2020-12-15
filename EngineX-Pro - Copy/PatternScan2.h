#pragma once
class PatternScan2
{
public:


	static  PBYTE FindPattern(DWORD base, const char* pPattern);
	static  PBYTE findPattern_v2(const PBYTE rangeStart, DWORD len, const char* pattern);

};