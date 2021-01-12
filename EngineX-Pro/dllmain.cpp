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
				if (Globals::Server != ServerName::AELDRA)
				{
#ifdef _DEBUG
					_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
#ifdef DEVELOPER_MODE
					AllocConsole();
					freopen("CONOUT$", "w", stdout);
					Security::Initialize();
#endif
				}
				_set_se_translator(ErrorTranslator);
				Globals::hModule = hModule;
				MainCore::StartCrack();
				//Initialize VEH HOOK
				Hooks::screenToClientHook.Hook((uintptr_t)ScreenToClient, (uintptr_t)Hooks::NewScreenToClient);
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