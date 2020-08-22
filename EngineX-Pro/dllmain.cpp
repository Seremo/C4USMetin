#include "stdafx.h"
#include "MainCore.h"
#include "tlhelp32.h"
//#include "C:\Program Files\VMProtect Lite\Include\C\VMProtectSDK.h"

LONG WINAPI Handler(EXCEPTION_POINTERS* pException)
{
	DWORD dwExceptionAddress = pException->ContextRecord->Eip;
	DWORD dwExceptionAddress2 = (DWORD)pException->ExceptionRecord->ExceptionAddress;
	DWORD dllexcepAddress = dwExceptionAddress2 - (DWORD)GetModuleHandle("EngineX.dll");

	printf("\n===========================================================\n");
	printf("[+] Exception occured!\n");
	printf("[+] EIP: 0x%X\n", dwExceptionAddress);
	printf("[+] DLL Exception Address: 0x%X\n", dwExceptionAddress2);
	printf("[+] DLL RVA Exception Address: 0x%X\n", dllexcepAddress);
	printf("[+] Exception Code: 0x%X\n", pException->ExceptionRecord->ExceptionCode);
	printf("[+] Registers: \n\tEAX: 0x%08X\n\tEBX: 0x%08X\n\tECX: 0x%08X\n\tEDX: 0x%08X\n\tEBP: 0x%08X\n\tESP: 0x%08X\n\tESI: 0x%08X\n\tEDI: 0x%08X\n", pException->ContextRecord->Eax, pException->ContextRecord->Ebx, pException->ContextRecord->Ecx, pException->ContextRecord->Edx, pException->ContextRecord->Ebp, pException->ContextRecord->Esp, pException->ContextRecord->Esi, pException->ContextRecord->Edi);
	printf("===========================================================\n");
	system("pause");
	return EXCEPTION_CONTINUE_SEARCH;
}

typedef BOOL(__stdcall* tIsDebuggerPresent)();
typedef HMODULE(__stdcall* tLoadLibraryA)(LPCSTR lpLibFileName);

tIsDebuggerPresent oIsDebuggerPresent;
tLoadLibraryA oLoadLibrary;

BOOL WINAPI mIsDebuggerPresent() {
	MainCore::ConsoleOutput("[+] IsDebugger");
	return false;
}

HMODULE WINAPI mLoadLibrary(LPCTSTR dllName) {
	string d = dllName;
	MainCore::ConsoleOutput(d.c_str());
	if (d == "htrap3/HackTrap.dll")
	{
		return (HMODULE)1;
	}
	if (d == "htrap2/HackTrap.dll")
	{
		return (HMODULE)1;
	}
	if (d == "htrap/HackTrap.dll")
	{
		return (HMODULE)1;
	}
	return oLoadLibrary(dllName);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
#ifdef DEVELOPER_MODE
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
#endif
		oLoadLibrary = (tLoadLibraryA)DetourFunction((PBYTE)GetProcAddress(GetModuleHandle("KERNEL32.dll"), "LoadLibraryA"), (PBYTE)mLoadLibrary);
		oIsDebuggerPresent = (tIsDebuggerPresent)DetourFunction((PBYTE)IsDebuggerPresent, (PBYTE)mIsDebuggerPresent);
		Globals::hModule = hModule;
		//MessageBox(NULL, "Cheat Wrong Version", "Error", 0);
		CreateThread(0, NULL, (LPTHREAD_START_ROUTINE)MainCore::Initialize, NULL, NULL, NULL);

	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	{

	}
	case DLL_PROCESS_DETACH:

		break;
	}
	return TRUE;

}