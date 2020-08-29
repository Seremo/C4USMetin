#include "stdafx.h"
#include "MainCore.h"
#include "tlhelp32.h"
//#include "C:\Program Files\VMProtect Lite\Include\C\VMProtectSDK.h"

typedef BOOL(__stdcall* tIsDebuggerPresent)();
typedef HMODULE(__stdcall* tLoadLibraryA)(LPCSTR lpLibFileName);

tIsDebuggerPresent oIsDebuggerPresent;
tLoadLibraryA oLoadLibrary;

BOOL WINAPI mIsDebuggerPresent() {
	//MainCore::ConsoleOutput("[+] IsDebugger");
	return false;
}

HMODULE WINAPI mLoadLibrary(LPCTSTR dllName) {
	string d = dllName;
	if (d == "htrap2/HackTrap.dll")
	{
		return oLoadLibrary("htrap4/HackTrap.dll");
	}
	return oLoadLibrary(dllName);
}

void mySEHtranslator(unsigned int exceptionCode, PEXCEPTION_POINTERS exceptionRecord)
{
	if (exceptionRecord->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION)
	{
		//puts("access violation not count");
	}
	else
	{
		throw "1"; // does not suppose to be caught.
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		_set_se_translator(mySEHtranslator);
#ifdef DEVELOPER_MODE
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
#endif
		//if (Globals::Server == ServerName::AELDRA)
		//{
		//	oLoadLibrary = (tLoadLibraryA)DetourFunction((PBYTE)GetProcAddress(GetModuleHandle("KERNEL32.dll"), "LoadLibraryA"), (PBYTE)mLoadLibrary);
		//	oIsDebuggerPresent = (tIsDebuggerPresent)DetourFunction((PBYTE)IsDebuggerPresent, (PBYTE)mIsDebuggerPresent);
		//}
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