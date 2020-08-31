#include "stdafx.h"
#include "MainCore.h"
#include "tlhelp32.h"
//#include "C:\Program Files\VMProtect Lite\Include\C\VMProtectSDK.h"

void ErrorTranslator(unsigned int exceptionCode, PEXCEPTION_POINTERS exceptionRecord)
{
	switch (exceptionRecord->ExceptionRecord->ExceptionCode)
	{
		case EXCEPTION_ACCESS_VIOLATION:
		{
			break;
		}
		default:
		{
			throw "1";
		}
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		_set_se_translator(ErrorTranslator);
#ifdef DEVELOPER_MODE
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
#endif
		Security::Initialize();
		Globals::hModule = hModule;
		CreateThread(0, NULL, (LPTHREAD_START_ROUTINE)MainCore::NetworkThread, NULL, NULL, NULL);
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