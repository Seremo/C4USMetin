#include "stdafx.h"
#include "MainCore.h"

 void MainCore::Crack()
{

}
///##################################################################################################################
bool MainCore::CheckMembers()
{
	string hwid = GetHardwareId();
	if ( hwid == "21D7B04A-523B0BDA-3B9C1E8A-40E0655B")//ja
	{
		return true;
	}
	else if (hwid == "45B6C023-28530FB7-329670E2-22F56148")//ser
	{
		return true;
	}
	else if (hwid == "51A0C122-B9B991A5-C50CE71B-C176E9A6")//adi
	{
		return true;
	}
	else if (hwid == "2CBFC55D-47476FA5-3CE60CE5-36F71640")//kom
	{
		return true;
	}
	else if (hwid == "28C3A75F-5C347AB3-39E4738A-328A642E")
	{
		return true;
	}
	return false;
}
 

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