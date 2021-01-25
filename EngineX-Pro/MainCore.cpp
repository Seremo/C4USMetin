#include "stdafx.h"
#include "MainCore.h"

bool MainCore::DXLoaded = false;

void MainCore::StartCrack()
{
	switch (Globals::Server)
	{
		case ServerName::METINPL:
		{
				//89 85 94 FE FF FF E8 ? ? ? ?
				break;
		}
		case ServerName::ARATHAR:
		{
			//0x21F8863
			MemoryExtension::MemSet(Globals::hEntryBaseAddress + 0x21F8863, 0x90, 5);
			break;
		}
		case ServerName::TASTRIA2:
		{
			MemoryExtension::MemSet(Globals::hEntryBaseAddress + 0x1E67E0, 0x90, 10);//89 85 94 FE FF FF E8 ? ? ? ?
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
		case ServerName::KEVRA:
			{
				MemoryExtension::MemSet(Globals::hEntryBaseAddress + 0x15CC54, 255, 1);
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
	else if (hwid == "4AD9C548-593B0FB5-48957683-468F1729")//laptop
	{
		return true;
	}
	else if (hwid == "45B6C023-28530FB7-329670E2-22F56148")//ser debug
	{
		return true;
	}
	else if (hwid == "49B7C030-4A2318A5-2A856192-47FB174A")//new seremo
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

bool MainCore::isInitialized = false;

///##################################################################################################################
void MainCore::Initialize()
{	
	if (!DynamicTimer::CheckAutoSet("Initialize", 300))
	{
		return;
	}
	if (!Device::pDevice)
	{
		Globals::ReAddressingInstances();
		if (Globals::pCGraphicBasems_lpd3dDevice != NULL)
		{
			Device::pDevice = *reinterpret_cast<DirectDevice2*>(Globals::pCGraphicBasems_lpd3dDevice);
		}
	}
	else
	{
#if defined( DEVELOPER_MODE) || defined(_DEBUG)
		if (!MainCore::CheckMembers())
		{
			MessageBox(NULL, "Cheat Wrong Version", "Error", 0);
			exit(0);
		}
#endif
		MainCore::Crack();
		ConsoleOutput("[+] Application detected.");
		Globals::ReDeclarationInstances();
		Globals::ReAddressingLocas();
		Globals::ReDeclarationLocals();
		if (Globals::Server == ServerName::METINPL || Globals::Server == ServerName::GLEVIA)
		{
			try
			{
				Globals::mainHwnd = (HWND)(*reinterpret_cast<DWORD*>(Globals::iCPythonApplicationInstance + 4));
			}
			catch (...)
			{
				ConsoleOutput("[-] Wrong Hwnd");
			}
		}
		if (Globals::UsePythonFunctions)
		{
			Globals::ReAddressingPython();
		}
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
		MiscExtension::ShowBalloon(Globals::mainHwnd, "C4US.PL - MultiHack", title.c_str(), NULL);
		isInitialized = true;
	}
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
		if (MainForm::Hotkey(Settings::MAIN_BOOST_KEY, 34))
		{
			GameFunctionsCustom::Boost();
		}

		if (MainForm::Hotkey(Settings::MAIN_HIDE_UI_KEY))
		{
			MainForm::SideBarIsOpen = !MainForm::SideBarIsOpen;
		}
	}
}