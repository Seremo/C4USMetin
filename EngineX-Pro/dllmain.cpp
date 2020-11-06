#include "stdafx.h"



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
				/*MessageBox(NULL, "Dev BP", "BP", 0);*/
#ifdef _DEBUG
				_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
				_set_se_translator(ErrorTranslator);
#ifdef DEVELOPER_MODE
				AllocConsole();
				freopen("CONOUT$", "w", stdout);
#else
				//MiscExtension::OpenWebiste("http://www.cheats4us.pl");
#endif
				Security::Initialize();
				Globals::hModule = hModule;
				bool DXIsAlreadyLoaded = GetModuleHandleA("d3d8.dll") || GetModuleHandleA("d3d9.dll");
				while (!MainCore::DXLoaded && !DXIsAlreadyLoaded)
				{
					Sleep(100);
				}
#ifdef NETWORK_MODE
				const HANDLE hThreadNetword = CreateThreadSafe(&MainCore::NetworkThread, hModule);
				if (hThreadNetword)
				{
					CloseHandle(hThreadNetword);
				}
				//CreateThread(0, NULL, (LPTHREAD_START_ROUTINE)MainCore::NetworkThread, NULL, NULL, NULL);
#endif
		//CreateThread(0, NULL, (LPTHREAD_START_ROUTINE)MainCore::Initialize, NULL, NULL, NULL);
				HANDLE hThreadInit = ProcessExtension::CreateThreadSafe((LPTHREAD_START_ROUTINE)&MainCore::Initialize, hModule);
				if (hThreadInit)
				{
					CloseHandle(hThreadInit);
				}
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