#include "stdafx.h"
#include "MainCore.h"

 void MainCore::Crack()
{
	 

#ifdef RUBINUM
	 const char* version = "1591958395";
	 MemoryExtension::SetMemory((Globals::hEntryBaseAddress + 0x18F2E4C), (void*)version, strlen(version));
#endif
#ifdef VIDGAR


#ifdef DEVELOPER_MODE

	/* const char* version = "000040";
	 MemoryExtension::SetMemory((Globals::hEntryBaseAddress + 0x2920DD0), (void*)version, strlen(version));*/
#endif
#endif

#ifdef BARIA
	//	MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x1EACF34), 0x90, 5); //E8 ? ? ? ? 8B 4D F8 E8 ? ? ? ? EB 12
		//MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x1EACF21), 0x90, 5); //E8 ? ? ? ? 8B 4D F8 E8 ? ? ? ? EB 12
	MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x1D52E22), 0x90, 5); //E8 ? ? ? ? 8B 4D F8 E8 ? ? ? ? EB 12
#endif

#ifdef VALIUM
	MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x142B4F), 0x90, 5); //E8 ? ? ? ? 8B 4D F8 E8 ? ? ? ? EB 12
#endif
#ifdef MEDIUM
	//MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x1AC6D), 0x90, 5);
	//MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x6A312), 0x90, 5);
	//MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0xECE6E), 0x90, 5);//hwnd
	MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x929FE), 0x90, 5);
	MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x92A71), 0x90, 5);

	MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x36EC), 0x90, 5); // 68 54 E4 74 00
	MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x8D411), 0x90, 15); //E8 ? ? ? ? E8 ? ? ? ? 8D 83 ? ? ? ? 

#endif
#ifdef ELITEMT2
//	DWORD pCode1 = PatternScan::FindPattern("E8 ? ? ? ? 0F B6 D0 85 D2 75 07 33 C0 E9 ? ? ? ? C6 85");
	//DWORD pCode2 = PatternScan::FindPattern("E8 ? ? ? ? 83 BD ? ? ? ? ? 74 17 8B 95");
	//DWORD pCode3 = PatternScan::FindPattern("50 E8 ? ? ? ? 83 C4 04 0F B6 C0 85 C0 75 5B");

//	if (!pCode1 || !pCode2 || !pCode3)
//	{
//		MessageBoxA(NULL, "Zła Wersja Exe", "Error", MB_OK);
//		exit(0);
//	}
//	MemoryExtension::MemSet((pCode1), 0x90, 19);
//	MemoryExtension::MemSet((pCode2), 0x90, 5);
//  MemoryExtension::MemSet((pCode3), 0x90, 107);

#endif
#ifdef ESGAROTH

	DWORD pCode1 = PatternScan::FindPattern("55 8B EC E8 ? ? ? ? 68");
	DWORD pCode2 = PatternScan::FindPattern("55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 B8 ? ? ? ? E8 ? ? ? ? A1 ? ? ? ? 33 C5 89 45 F0 50 8D 45 F4 64 A3 ? ? ? ? 68");


	if (!pCode1 || !pCode2)
	{
		MessageBoxA(NULL, "Zła Wersja Exe", "Error", MB_OK);
		exit(0);
	}
	MemoryExtension::MemSet((pCode1), 0x00, 161);
	MemoryExtension::MemSet((pCode2), 0x00, 25672);
#endif
#ifdef GLADOR
	//DWORD pCode1 =PatternScan::FindPattern("55 8B EC 81 EC ? ? ? ? A1 ? ? ? ? 33 C5 89 45 FC 89 8D ? ? ? ? 68 ? ? ? ? 8B 85");
	//DWORD pCode2 = PatternScan::FindPattern("E8 ? ? ? ? 2B 05 ? ? ? ? 3D ? ? ? ? 76 49");
	//MemoryExtension::MemSet((pCode1), 0x00, 198);
	//MemoryExtension::MemSet((pCode2), 0x90, 91);
	DWORD BattleAttackBypass = PatternScan::FindPattern("E8 F7 25 00 00 8B CE 8A D8");
	MemoryExtension::MemSet(BattleAttackBypass, 0xB3, 1);
	MemoryExtension::MemSet(BattleAttackBypass + 1, 0x01, 1);
	MemoryExtension::MemSet(BattleAttackBypass + 2, 0x90, 3);
	MemoryExtension::MemSet(BattleAttackBypass + 9, 0xB0, 1);
	MemoryExtension::MemSet(BattleAttackBypass + 10, 0x01, 1);
	MemoryExtension::MemSet(BattleAttackBypass + 11, 0x90, 3);
#endif
#ifdef CLASSIC
	/*DWORD pCode2 = PatternScan::FindPattern("\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x81\xEC\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\xF0\x53\x56\x57\x50\x8D\x45\xF4\x64\xA3\x00\x00\x00\x00\x8B\x7D\x08\x8B\x5D\x0C", "xxxxxx????xx????xxx????x????xxxxxxxxxxxxxx????xxxxxx");
	MemoryExtension::MemSet((pCode2), 0x90, 379);*/
#endif
#if defined(VESTERIS) && defined(AKADEMIA_VESTERIS)

	DWORD pCode5 = PatternScan::FindPattern("E8 ? ? ? ? 83 C4 18 88 85");
	MemoryExtension::MemSet((pCode5), 0x90, 80);


	DWORD pCode6 = PatternScan::FindPattern("68 ? ? ? ? 8B 8D ? ? ? ? E8 ? ? ? ? 8B 95");
	MemoryExtension::MemSet((pCode6), 0x90, 16);
	if (pCode5 == NULL || pCode6 == NULL)
	{
		MessageBox(NULL, L"Zla Wersja Exe", L"Error", 0);
		exit(0);
	}
#endif

#ifdef VAROS
	DWORD pCode1 = PatternScan::FindPattern("? ? ? ? 83 3D ? ? ? ? ? 75 15");
	int th1 = *reinterpret_cast<DWORD*>(pCode1);
	int th2 = *reinterpret_cast<DWORD*>(th1);
	SuspendThread((HANDLE)th1);
	SuspendThread((HANDLE)th2);
	DWORD pCode2 = PatternScan::FindPattern("55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 81 EC ? ? ? ? A1 ? ? ? ? 33 C5 89 45 F0 50 8D 45 F4 64 A3 ? ? ? ? 6A 24");
	MemoryExtension::MemSet((pCode2), 0x00, 0x2C3);

#endif
#if defined(PANGEA) && defined(VERSION_ELITE)
	//DWORD pCode2 = PatternScan::FindPattern("8B CE E8 ? ? ? ? 85 C0 0F 84 ? ? ? ? FF 75 F7");

	//MemoryExtension::MemSet(pCode2, 0x90, 15);
#endif 
#ifdef XENOX	
	MemoryExtension::MemSet((0x005219D4), 0x90, 5);
	//DWORD pCode2 = PatternScan::FindPattern("E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? 50 E8 ? ? ? ? 8D 85");
	//MemoryExtension::MemSet(pCode2, 0x90, 5);

	//int th1 = *reinterpret_cast<DWORD *>(0x006CB4A8);
	////int th2 = *reinterpret_cast<DWORD *>(0x006CB4AC);
	////int th3 = *reinterpret_cast<DWORD *>(0x006CB4B0);
	//SuspendThread((HANDLE)th1);
	//SuspendThread((HANDLE)th2);
	//SuspendThread((HANDLE)th3);
#endif
}
///##################################################################################################################

 

///##################################################################################################################
 void MainCore::Initialize()
 {
	/* Sleep(2000);*/
	 Globals::ReAddressingLocas();
	 Globals::ReDeclarationLocals();

	 Globals::mainHwnd = (HWND)(*reinterpret_cast<DWORD*>(Globals::iCPythonApplicationInstance + 4));
	 Hooks::Initialize();
	 
	 string title = "";
	 title += "Version ";
	 title += DLL_VERSION;
	 title += " ";
#ifdef _DEBUG
	 title += "Debug";
#else
	 title += "Relase";
#endif
	 title += " ";
	 title += SERVER_NAME;
	 MiscExtension::ShowBalloon(Globals::mainHwnd, "EngineX", title.c_str(), NULL);




 }
///##################################################################################################################
 void  MainCore::UpdateLoop()
{
	DelayActions::Update();
	for (map< pair<DWORD, string>, pair<bool, std::shared_ptr<IAbstractModuleBase>>> ::iterator itor = MainCore::moduleList.begin(); itor != MainCore::moduleList.end(); itor++)
	{
		if (itor->second.first)
		{
			itor->second.second->OnUpdate();
		}
	}

}