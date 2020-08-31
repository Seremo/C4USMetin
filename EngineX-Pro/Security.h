#pragma once
class Security
{
	typedef enum _SECTION_INHERIT {
		ViewShare = 1,
		ViewUnmap = 2
	} SECTION_INHERIT;
private:
	//ntdll
	typedef NTSTATUS(__stdcall* tNtAllocateVirtualMemory)(HANDLE ProcessHandle,PVOID* BaseAddress,ULONG_PTR ZeroBits,PSIZE_T RegionSize,ULONG AllocationType,ULONG Protect);
	typedef NTSTATUS(__stdcall* tNtFreeVirtualMemory)(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T RegionSize, ULONG FreeType);
	typedef NTSTATUS(__stdcall* tNtMapViewOfSection)(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_PTR ZeroBits, SIZE_T CommitSize, PLARGE_INTEGER SectionOffset, PSIZE_T ViewSize, SECTION_INHERIT InheritDisposition, ULONG AllocationType, ULONG Win32Protect);
	typedef NTSTATUS(__stdcall* tNtUnmapViewOfSection)(HANDLE ProcessHandle, PVOID BaseAddress);

	//user32
	typedef LRESULT(__stdcall* tCallNextHookEx)(HHOOK hhk, int nCode, WPARAM wParam, LPARAM lParam);

	//other
	typedef HANDLE(__stdcall* tCreateThread)(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, __drv_aliasesMem LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
	typedef HMODULE(__stdcall* tLoadLibraryA)(LPCSTR lpLibFileName);
	typedef BOOL(__stdcall* tIsDebuggerPresent)();

	static tNtAllocateVirtualMemory nNtAllocateVirtualMemory;
	static tNtFreeVirtualMemory nNtFreeVirtualMemory;
	static tNtMapViewOfSection nNtMapViewOfSection;
	static tNtUnmapViewOfSection nNtUnmapViewOfSection;

	static tCallNextHookEx nCallNextHookEx;

	static tCreateThread nCreateThread;
	static tLoadLibraryA nLoadLibraryA;
	static tIsDebuggerPresent nIsDebuggerPresent;

public:
	static NTSTATUS _stdcall NewNtAllocateVirtualMemory(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_PTR ZeroBits, PSIZE_T RegionSize, ULONG AllocationType, ULONG Protect)
	{
		return nNtAllocateVirtualMemory(ProcessHandle, BaseAddress, ZeroBits, RegionSize, AllocationType, Protect);
	}

	static NTSTATUS _stdcall NewNtFreeVirtualMemory(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T RegionSize, ULONG FreeType)
	{
		return nNtFreeVirtualMemory(ProcessHandle, BaseAddress, RegionSize, FreeType);
	}

	static NTSTATUS _stdcall NewNtMapViewOfSection(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_PTR ZeroBits, SIZE_T CommitSize, PLARGE_INTEGER SectionOffset, PSIZE_T ViewSize, SECTION_INHERIT InheritDisposition, ULONG AllocationType, ULONG Win32Protect)
	{
		return nNtMapViewOfSection(SectionHandle, ProcessHandle, BaseAddress, ZeroBits, CommitSize, SectionOffset, ViewSize, InheritDisposition, AllocationType, Win32Protect);
	}

	static NTSTATUS _stdcall NewNtUnmapViewOfSection(HANDLE ProcessHandle, PVOID BaseAddress)
	{
		return nNtUnmapViewOfSection(ProcessHandle, BaseAddress);
	}

	static LRESULT _stdcall NewCallNextHookEx(HHOOK hhk, int nCode, WPARAM wParam, LPARAM lParam)
	{
		return nCallNextHookEx(hhk, nCode, wParam, lParam);
	}

	static HANDLE _stdcall NewCreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, __drv_aliasesMem LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId)
	{
		return nCreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
	}

	static HMODULE _stdcall NewLoadLibraryA(LPCTSTR lpLibFileName) {
		if (StringExtension::Contains(lpLibFileName, "d3d8") || StringExtension::Contains(lpLibFileName, "d3d9"))
		{
			MainCore::DXLoaded = true;
		}
		return nLoadLibraryA(lpLibFileName);
	}

	static BOOL _stdcall NewIsDebuggerPresent() {
		return nIsDebuggerPresent();
	}

	static void Initialize()
	{
		HMODULE ntdllLibrary = LoadLibraryA("ntdll");
		HMODULE user32Library = LoadLibraryA("user32");
		HMODULE kernel32Library = LoadLibraryA("kernel32");

		LPVOID NtAllocateVirtualMemory = GetProcAddress(ntdllLibrary, "NtAllocateVirtualMemory");
		nNtAllocateVirtualMemory = (tNtAllocateVirtualMemory)DetourFunction((PBYTE)NtAllocateVirtualMemory, (PBYTE)NewNtAllocateVirtualMemory);
		VirtualProtect(NtAllocateVirtualMemory, 15, PAGE_EXECUTE_READ, NULL);

		LPVOID NtFreeVirtualMemory = GetProcAddress(ntdllLibrary, "NtFreeVirtualMemory");
		nNtFreeVirtualMemory = (tNtFreeVirtualMemory)DetourFunction((PBYTE)NtFreeVirtualMemory, (PBYTE)NewNtFreeVirtualMemory);
		VirtualProtect(NtFreeVirtualMemory, 15, PAGE_EXECUTE_READ, NULL);

		LPVOID NtMapViewOfSection = GetProcAddress(ntdllLibrary, "NtMapViewOfSection");
		nNtMapViewOfSection = (tNtMapViewOfSection)DetourFunction((PBYTE)NtMapViewOfSection, (PBYTE)NewNtMapViewOfSection);
		VirtualProtect(NtMapViewOfSection, 15, PAGE_EXECUTE_READ, NULL);

		LPVOID NtUnmapViewOfSection = GetProcAddress(ntdllLibrary, "NtUnmapViewOfSection");
		nNtUnmapViewOfSection = (tNtUnmapViewOfSection)DetourFunction((PBYTE)NtUnmapViewOfSection, (PBYTE)NewNtUnmapViewOfSection);
		VirtualProtect(NtUnmapViewOfSection, 15, PAGE_EXECUTE_READ, NULL);

		LPVOID CallNextHookEx = GetProcAddress(user32Library, "CallNextHookEx");
		nCallNextHookEx = (tCallNextHookEx)DetourFunction((PBYTE)CallNextHookEx, (PBYTE)NewCallNextHookEx);
		VirtualProtect(CallNextHookEx, 0x97, PAGE_EXECUTE_READ, NULL);

		LPVOID LoadLibraryA = GetProcAddress(kernel32Library, "LoadLibraryA");
		nLoadLibraryA = (tLoadLibraryA)DetourFunction((PBYTE)LoadLibraryA, (PBYTE)NewLoadLibraryA);
		VirtualProtect(LoadLibraryA, 5, PAGE_EXECUTE_READ, NULL);

		LPVOID CreateThread = GetProcAddress(kernel32Library, "CreateThread");
		nCreateThread = (tCreateThread)DetourFunction((PBYTE)CreateThread, (PBYTE)NewCreateThread);
		VirtualProtect(CreateThread, 5, PAGE_EXECUTE_READ, NULL);

		LPVOID IsDebuggerPresent = GetProcAddress(kernel32Library, "IsDebuggerPresent");
		nIsDebuggerPresent = (tIsDebuggerPresent)DetourFunction((PBYTE)IsDebuggerPresent, (PBYTE)NewIsDebuggerPresent);
		VirtualProtect(IsDebuggerPresent, 5, PAGE_EXECUTE_READ, NULL);

		//HookIAT::Hook("kernel32.dll", "CreateThread", (PVOID)NewCreateThread, (PVOID*)&nCreateThread);
		//HookIAT::Hook("kernel32.dll", "LoadLibraryA", (PVOID)NewLoadLibraryA, (PVOID*)&nLoadLibraryA);
		//HookIAT::Hook("kernel32.dll", "IsDebuggerPresent", (PVOID)NewIsDebuggerPresent, (PVOID*)&nIsDebuggerPresent);
	}
};

Security::tNtAllocateVirtualMemory Security::nNtAllocateVirtualMemory = NULL;
Security::tNtFreeVirtualMemory Security::nNtFreeVirtualMemory = NULL;
Security::tNtMapViewOfSection Security::nNtMapViewOfSection = NULL;
Security::tNtUnmapViewOfSection Security::nNtUnmapViewOfSection = NULL;
Security::tCallNextHookEx Security::nCallNextHookEx = NULL;
Security::tCreateThread Security::nCreateThread = NULL;
Security::tLoadLibraryA Security::nLoadLibraryA = NULL;
Security::tIsDebuggerPresent Security::nIsDebuggerPresent = NULL;