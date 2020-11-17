#include "stdafx.h"
#include "MainCore.h"

bool MainCore::DXLoaded = false;

void MainCore::StartCrack()
{
	switch (Globals::Server)
	{
		case ServerName::TASTRIA2:
		{
			MemoryExtension::MemSet(Globals::hEntryBaseAddress + 0x1E5FE0, 0x90, 10);//89 85 94 FE FF FF E8 ? ? ? ?
			break;
		}
		default:
		{
			break;
		}
	}
}

void MainCore::Crack()
{
	switch (Globals::Server)
	{
		//case ServerName::AELDRA:
		//{
		//	DWORD addr1 = Globals::pCPythonNetworkStreamSendAttackPacket + 0x29;
		//	MemoryExtension::MemSet(addr1, 0x90, 16);
		//	break;
		//}
		case ServerName::METINPL:
			{
				MemoryExtension::MemSet(Globals::iCPythonNetworkStreamInstance + 31409, 0x0, 1);
				break;
			}
		case ServerName::LUNA:
			{
				MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x12F0E4), 0x90, 29); //83 C4 ? E8 ? ? ? ? 6A ? 6A
				break;
			}
		default:
			{
				break;
			}
	}
}
///##################################################################################################################
bool MainCore::CheckMembers()
{
	string hwid = GetHardwareId();
#ifdef DEVELOPER_MODE
	printf(hwid.c_str());
	printf("\n");
#endif
	if ( hwid == "21D7B04A-523B0BDA-3B9C1E8A-40E0655B")//ja
	{
		return true;
	}
	else if (hwid == "45B6C023-28530FB7-329670E2-22F56148")//ser debug
	{
		return true;
	}
	else if (hwid == "45B6C023-D6ADF1B7-CC688E1C-DC0B9FB6")//ser release
	{
		return true;
	}
	else if (hwid == "51A0C122-47476FA5-3BF219E5-3F881758")//adi
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

void MainCore::ConsoleOutput(const char* txt, ...)
{
#ifdef DEVELOPER_MODE
	printf(txt);
	printf("\n");
#endif
}

void MainCore::NetworkThread()
{
	Network::Initialize();
	Network::SetRecvBufferSize(9999999);
	Network::SetSendBufferSize(4256);
	if (!Network::Connect(AUTH_IP_ADDRESS, AUTH_PORT))
	{
		ExitProcess(0);
	}
	PacketHandler::SendAuthPacket();
	while (true)
	{
		Network::Process();
		PacketHandler::Process();
		Sleep(1);
	}
}
///##################################################################################################################
void MainCore::Initialize()
{	
	/*MessageBox(NULL, "Dev BP", "BP", 0);*/
#if defined( DEVELOPER_MODE) || defined(_DEBUG)
	if (!MainCore::CheckMembers())
	{
		MessageBox(NULL, "Cheat Wrong Version", "Error", 0);
		exit(0);
	}
#endif
	MainCore::StartCrack();
#ifdef NETWORK_MODE
	while (!Device::pDevice || !PacketHandler::AddressReceived)
#else
	while (!Device::pDevice)
#endif
	{
		try
		{		
#ifndef NETWORK_MODE
			Globals::ReAddressingInstances();
#endif
			Globals::ReDeclarationInstances();
			Sleep(500);
		}
		catch (...)
		{
			Sleep(1000);
		}
	}
	MainCore::Crack();
	ConsoleOutput("[+] Application detected.");
	Globals::ReAddressingLocas();
	Globals::ReDeclarationLocals();
	if (Globals::UsePythonFunctions)
	{
		Globals::ReAddressingPython();
	}
	Globals::mainHwnd = (HWND)(*reinterpret_cast<DWORD*>(Globals::iCPythonApplicationInstance + 4));
	Configuration::Instance().OnStart();
	Hooks::Initialize();
	string title = "";
	title += "Version ";
	title += DLL_VERSION;
	title += " ";
#ifdef _DEBUG
	title += "Debug";
#else
	title += "Relase \n(Free - If you paid u have been scammed) ";
#endif
	title += " ";
	MiscExtension::ShowBalloon(Globals::mainHwnd, "EngineX", title.c_str(), NULL);
}
///##################################################################################################################
void  MainCore::UpdateLoop()
{
	DelayActions::Update();
	for (map< pair<DWORD , DWORD>, pair<bool, std::shared_ptr<IAbstractModuleBase>>> ::iterator itor = MainCore::moduleList.begin(); itor != MainCore::moduleList.end(); itor++)
	{
		if (itor->second.first)
		{
			itor->second.second->OnUpdate();
		}
	}
	if (GetForegroundWindow() == Globals::mainHwnd)
	{
		if (MainForm::Hotkey(Settings::MAIN_GLOBAL_SWITCH_KEY))
		{
			Settings::GLOBAL_SWITCH_ENABLE = !Settings::GLOBAL_SWITCH_ENABLE;
			if (Settings::GLOBAL_SWITCH_ENABLE == true)
			{
				Main::Instance().OnStart();
			}
			else
			{
				Main::Instance().OnStop();
			}
		}
		if (MainForm::Hotkey(Settings::MAIN_RELOG_KEY))
		{
			if (Globals::Server == ServerName::METINPL)
			{
				GameFunctions::NetworkStreamConnectGameServer(0);
				Main::Instance().ResetSkillTimer();
			}
			else
			{
				int lastSlot = GameFunctionsCustom::GetCharSlotByName(GameFunctions::PlayerGetName());
				if (lastSlot != -1)
				{
					GameFunctions::NetworkStreamConnectGameServer(lastSlot);
					Main::Instance().ResetSkillTimer();
				}
			}
		}
		if (MainForm::Hotkey(Settings::MAIN_BOOST_KEY, 14))
		{
			GameFunctionsCustom::Boost();
		}

		if (MainForm::Hotkey(Settings::MAIN_HIDE_UI_KEY))
		{
			MainForm::SideBarIsOpen = !MainForm::SideBarIsOpen;
		}
	}
}