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
__declspec(dllexport) void __cdecl ImportAttach(void)
{

}
typedef HMODULE(__stdcall* tLoadLibraryA)(LPCSTR lpLibFileName);
tLoadLibraryA nLoadLibraryA;
HMODULE __stdcall NewLoadLibraryA(LPCSTR lpLibFileName)
{
	string d = lpLibFileName;
	if (d == "htrap2/HackTrap.dll")
	{
		DWORD d = (DWORD)_ReturnAddress();
		MessageBox(NULL, to_string(d).c_str(), "Error", 0);
		return (HMODULE)1;
		/*return NULL;*/
	}
	if (d == "htrap/HackTrap.dll")
	{
		DWORD d = (DWORD)_ReturnAddress();
		MessageBox(NULL, to_string(d).c_str(), "Error2", 0);
		return (HMODULE)1;
		/*return NULL;*/
	}
	return nLoadLibraryA(lpLibFileName);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
	
	
		FARPROC f2 = NULL;
		HMODULE kernel32Module = GetModuleHandle("KERNEL32.dll");
		
		f2 = GetProcAddress(kernel32Module, "LoadLibraryA");
		nLoadLibraryA = (tLoadLibraryA)DetourFunction((PBYTE)f2, (PBYTE)NewLoadLibraryA);


		/*CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)DLLAction, NULL, 0, NULL);*/
		
	/*	MainCore::Crack();*/
	/*	MessageBox(NULL, "Cheat Wrong Version", "Error", 0);*/
#ifdef _DEBUG
		/*if (!MainCore::CheckMembers())
		{
			MessageBox(NULL, "Cheat Wrong Version", "Error", 0);
			exit(0);
		}*/
#endif	
#ifdef DEVELOPER_MODE
		/*if (!MainCore::CheckMembers())
		{
			MessageBox(NULL, "Cheat Wrong Version", "Error", 0);
			exit(0);
		}*/
	/*	HMODULE a = GetModuleHandle("HackTrap.dll");
		BOOL b =FreeLibrary(a);*/
		/*AllocConsole();
		freopen("CONOUT$", "w", stdout);
		std::cout << "Debug Console" << std::endl;
		//*///MessageBox(NULL, "Break Point", "BP", 0);
#endif
	/*	Globals::hModule = hModule;*/
		

		/*MessageBox(NULL, "Break Point", "BP", 0)*/;

		/*MainCore::Initialize();*/

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