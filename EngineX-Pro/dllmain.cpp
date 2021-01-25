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

VEHHook sleepHook;
void __stdcall NewSleep(DWORD miliseconds)
{
	Hooks::screenToClientHwBpHook = std::make_shared<PLH::HWBreakPointHook>((char*)&ScreenToClient, (char*)&Hooks::NewScreenToClient, GetCurrentThread());
	Hooks::screenToClientHwBpHook->hook();
	//Security::Initialize();
	sleepHook.Unhook();
}

void Initialize()
{
	while (!MainCore::isInitialized)
	{
		MainCore::Initialize();
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		
		case DLL_PROCESS_ATTACH:
			{
#ifdef DEVELOPER_MODE
				if (Globals::Server != ServerName::AELDRA)
				{
#ifdef _DEBUG
					_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
					AllocConsole();
					freopen("CONOUT$", "w", stdout);
				}
#endif
				_set_se_translator(ErrorTranslator);
				Globals::hModule = hModule;
				MainCore::StartCrack();
				if (Globals::Server == ServerName::METINPL || Globals::Server == ServerName::GLEVIA)
				{
					HANDLE hThreadInit = ProcessExtension::CreateThreadSafe((LPTHREAD_START_ROUTINE)&Initialize, hModule);
					if (hThreadInit)
					{
						CloseHandle(hThreadInit);
					}
				}
				else
				{
					sleepHook.Hook((uintptr_t)Sleep, (uintptr_t)NewSleep);
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