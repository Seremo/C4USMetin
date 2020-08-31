#include "stdafx.h"
#include "HookCore.h"

//##################################################################################################################################################
void _fastcall Hooks::NewCPythonApplicationRenderGame(void* This, void* EDX)
{
	if (!Settings::ProtectionDisableRender)
	{
		Device::pDevice->GetTransform(D3DTS_WORLD, &CRender::WorldStateCopy);
		nCPythonApplicationRenderGame(This);
		for (map< pair<DWORD, string>, pair<bool, std::shared_ptr<IAbstractModuleBase>>> ::iterator itor = MainCore::moduleList.begin(); itor != MainCore::moduleList.end(); itor++)
		{
			if (itor->second.first)
			{
				itor->second.second->OnRender();
			}
		}
	}
	else {
		Device::pDevice->Clear(0L, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xff000000, 1.0f, 0);
	}
}

//##################################################################################################################################################
bool _fastcall Hooks::NewCActorInstanceTestActorCollision(void* This, void* EDX, DWORD* rVictim)
{

	if (Settings::MainWallHackMob )
	{
		return false;
	}
	else
	{
		return nCActorInstanceTestActorCollision(This, rVictim);
	}
}

//##################################################################################################################################################
bool _fastcall Hooks::NewCInstanceBaseAvoidObject(void* This, void* EDX, DWORD* c_rkBGObj)
{

	if (Settings::MainWallHackObject)
	{
		return false;
	}
	else
	{
		return nCInstanceBaseAvoidObject(This, c_rkBGObj);
	}
}



//##################################################################################################################################################
void _fastcall Hooks::NewCInstanceBaseBlockMovement(void* This, void* EDX)
{

	if (Settings::MainWallHackTerrain)
	{
		return;
	}
	else
	{
		return nCInstanceBaseBlockMovement(This);
	}
}


//##################################################################################################


bool __cdecl Hooks::NewPyCallClassMemberFunc(PyObject* poClass, const char* c_szFunc, PyObject* poArgs)

{
	if (StringExtension::Equals(c_szFunc, "Update") ||
		StringExtension::Equals(c_szFunc, "OnRender") ||
		StringExtension::Equals(c_szFunc, "DownEvent") ||

		StringExtension::Equals(c_szFunc, "Render") ||
		StringExtension::Equals(c_szFunc, "OnMouseOverIn") ||
		StringExtension::Equals(c_szFunc, "OnMouseOverOut") ||
		StringExtension::Equals(c_szFunc, "ShowToolTip") ||
		StringExtension::Equals(c_szFunc, "HideToolTip") ||
		StringExtension::Equals(c_szFunc, "OnEndFrame") ||
		StringExtension::Equals(c_szFunc, "OnKeyFrame")
		)
	{

		return nPyCallClassMemberFunc(poClass, c_szFunc, poArgs);
	}

	if (StringExtension::Equals(c_szFunc, "SetLoginPhase"))
	{
		
	}
	/*	if (StringExtension::Equals(c_szFunc, "SetLoadingPhase") && Settings::ProtectionShowWisperLogs)
		{
			return true;
		}
	if (StringExtension::Equals(c_szFunc, "LoadData")&&Settings::ProtectionShowWisperLogs)
	{
		__SetProgress(0)

		return true;
	}*/
	if (StringExtension::Equals(c_szFunc, "BINARY_ServerCommand_Run"))
	{
	
		const char* com = Globals::PyString_AsString(Globals::PyTuple_GetItem(poArgs, 0));

		Logger::Add(Logger::MAIN, true, Logger::WHITE, com);
	}
	if (StringExtension::Equals(c_szFunc, "OnRecvWhisper"))
	{
		int type = Globals::PyInt_AsLong(Globals::PyTuple_GetItem(poArgs, 0));
		const char* name = Globals::PyString_AsString(Globals::PyTuple_GetItem(poArgs, 1));
		const char* line = Globals::PyString_AsString(Globals::PyTuple_GetItem(poArgs, 2));


		if (Settings::ProtectionShowWisperLogs)
		{

			Logger::Add(Logger::MAIN, true, Logger::WHITE, line);
			
		}
		if (Settings::ProtectionShowWisperBalloon)
		{

			string title = StringExtension::StringFormat("Whisper[%s]", GameFunctionsCustom::PlayerGetName());
			MiscExtension::UpdateBalloon(Globals::mainHwnd, title.c_str(), line, NULL);
		}

		if (Settings::ProtectionPlayWisperBeep)
		{
			CreateThread(0, NULL, (LPTHREAD_START_ROUTINE)MiscExtension::PlayAlerSound, NULL, NULL, NULL);

		}
		if (Settings::ProtectionRestoreWisperWindow)
		{

			ShowWindow(Globals::mainHwnd, SW_RESTORE);
		}
		if (Settings::ProtectionFlashWisperIcon)
		{
			FLASHWINFO fi;
			fi.cbSize = sizeof(FLASHWINFO);
			fi.hwnd = Globals::mainHwnd;
			fi.dwFlags = FLASHW_ALL | FLASHW_TIMERNOFG;;
			fi.uCount = 3;
			fi.dwTimeout = 0;
			FlashWindowEx(&fi);
		}
	}

	//Logger::Add(Logger::MAIN, true, Logger::WHITE, c_szFunc);
	return nPyCallClassMemberFunc(poClass, c_szFunc, poArgs);
}





bool _fastcall Hooks::NewCPythonEventManagerRegisterEventSetFromString(void* This, void* EDX, const string& strScript)
{
	const char* str_base = strScript.c_str();
	/*MainForm::LogSniffer(0, (str_base));
	MainForm::LogSniffer(0, "\n");*/
	switch (Globals::Server)
	{
	case ServerName::SAMIAS2:
		if (StringExtension::Contains(strScript.c_str(), "Kontrola obecności"))
		{
			if (StringExtension::Contains(strScript.c_str(), "Wybierz cyfrę '1'"))
			{
				if (StringExtension::Contains(strScript.c_str(), "1;1"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(1);
				}
				if (StringExtension::Contains(strScript.c_str(), "2;1"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(2);
				}
				if (StringExtension::Contains(strScript.c_str(), "3;1"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(3);
				}
				if (StringExtension::Contains(strScript.c_str(), "4;1"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(4);
				}
			}
			if (StringExtension::Contains(strScript.c_str(), "Wybierz cyfrę '2'"))
			{
				if (StringExtension::Contains(strScript.c_str(), "1;2"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(1);
				}
				if (StringExtension::Contains(strScript.c_str(), "2;2"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(2);
				}
				if (StringExtension::Contains(strScript.c_str(), "3;2"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(3);
				}
				if (StringExtension::Contains(strScript.c_str(), "4;2"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(4);
				}
			}
			if (StringExtension::Contains(strScript.c_str(), "Wybierz cyfrę '3'"))
			{
				if (StringExtension::Contains(strScript.c_str(), "1;3"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(1);
				}
				if (StringExtension::Contains(strScript.c_str(), "2;3"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(2);
				}
				if (StringExtension::Contains(strScript.c_str(), "3;3"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(3);
				}
				if (StringExtension::Contains(strScript.c_str(), "4;3"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(4);
				}
			}
			if (StringExtension::Contains(strScript.c_str(), "Wybierz cyfrę '4'"))
			{
				if (StringExtension::Contains(strScript.c_str(), "1;4"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(1);
				}
				if (StringExtension::Contains(strScript.c_str(), "2;4"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(2);
				}
				if (StringExtension::Contains(strScript.c_str(), "3;4"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(3);
				}
				if (StringExtension::Contains(strScript.c_str(), "4;4"))
				{
					GameFunctions::NetworkStreamSendScriptAnswerPacket(4);
				}
			}
			return -1;
		}
		break;
	}
	return nCPythonEventManagerRegisterEventSetFromString(This, strScript);
}
//##################################################################################################
void _fastcall Hooks::NewCPhysicsObjectIncreaseExternalForce(void* This, void* EDX, const D3DVECTOR& c_rvBasePosition, float fForce)
{
	if (!Settings::MiniMHNOK)
	{

		nCPhysicsObjectIncreaseExternalForce(This, c_rvBasePosition, fForce);

	}
	else
	{

	}
	return;
}


//##################################################################################################
//bool _fastcall Hooks::NewCNetworkStreamPeek(void* This, void* EDX, int len, void* pDestBuf)
//{
//	bool ret = nCNetworkStreamPeek(This, len, pDestBuf);
//	BYTE* destBuf = (BYTE*)pDestBuf;
//
//	BYTE header;
//	memcpy(&header, destBuf, sizeof(header));
//	if (len >= 1)
//	{
//		PacketSniffer::ProcessRecvPacket(len, pDestBuf);
//	}
//	return ret;
//}
//##################################################################################################
bool _fastcall Hooks::NewCNetworkStreamCheckPacket(void* This, void* EDX, BYTE* header)
{
	bool ret = nCNetworkStreamCheckPacket(This, header);
	PacketSniffer::Instance().ProcessRecvPacket(1, header, (DWORD)_ReturnAddress() - Globals::hEntryBaseAddress);
	return ret;
}
//##################################################################################################
bool _fastcall Hooks::NewCNetworkStreamRecv(void* This, void* EDX, int len, void* pDestBuf)
{
	bool ret;
	ret = nCNetworkStreamRecv(This, len, pDestBuf);
	BYTE* destBuf = (BYTE*)pDestBuf;

	BYTE header;
	memcpy(&header, destBuf, sizeof(header));
	switch (Globals::Server)
	{
	//case ServerName::VIDGAR:
	//	if (header == HEADER_GC_ITEM_GROUND_DEL && len == sizeof(TPacketGCItemGroundDel))
	//	{
	//		TPacketGCItemGroundDel	packet_item_ground_del;
	//		memcpy(&packet_item_ground_del, destBuf, sizeof(TPacketGCItemGroundDel));
	//		if (Globals::groundItemList.count(packet_item_ground_del.vid))
	//		{
	//			Globals::groundItemList.erase(packet_item_ground_del.vid);
	//		}
	//	}
	//	if (header == HEADER_GC_ITEM_GROUND_ADD && len == 58)
	//	{
	//		TPacketGCItemGroundAdd packet_item_ground_add;
	//		memcpy(&packet_item_ground_add, destBuf, sizeof(TPacketGCItemGroundAdd));
	//		/*__GlobalPositionToLocalPosition(packet_item_ground_add.lX, packet_item_ground_add.lY);*/

	//		TGroundItemInstance* pGroundItemInstance = new TGroundItemInstance();
	//		GameFunctionsCustom::GlobalPositionToLocalPosition(packet_item_ground_add.lX, packet_item_ground_add.lY);
	//		pGroundItemInstance->Instance = NULL;
	//		pGroundItemInstance->dwVirtualNumber = packet_item_ground_add.dwVnum;
	//		pGroundItemInstance->v3EndPosition.x = packet_item_ground_add.lX;
	//		pGroundItemInstance->v3EndPosition.y = -packet_item_ground_add.lY;
	//		pGroundItemInstance->v3EndPosition.z = packet_item_ground_add.lZ;
	//		pGroundItemInstance->v3RotationAxis = D3DVECTOR{ 0, 0, 0 };
	//		pGroundItemInstance->qEnd = D3DXQUATERNION{ 0, 0, 0,0 };
	//		pGroundItemInstance->v3Center = D3DVECTOR{ 0, 0, 0 };
	//		pGroundItemInstance->ThingInstance = NULL;
	//		pGroundItemInstance->dwStartTime = 0;
	//		pGroundItemInstance->dwEndTime = 0;
	//		pGroundItemInstance->eDropSoundType = 0;
	//		pGroundItemInstance->stOwnership = "";
	//		Globals::groundItemList.insert(std::make_pair(packet_item_ground_add.dwVID, pGroundItemInstance));
	//	}
	//	if (header == HEADER_GC_ITEM_OWNERSHIP) {
	//		TPacketGCItemOwnership packet_item_ownership;
	//		memcpy(&packet_item_ownership, destBuf, sizeof(TPacketGCItemOwnership));
	//		if (Globals::groundItemList.count(packet_item_ownership.dwVID))
	//		{
	//			Globals::groundItemList[packet_item_ownership.dwVID]->stOwnership = string(packet_item_ownership.szName);
	//		}
	//	}
	//	break;
	case ServerName::PANGEA:
		if (header == 0x32 && len == 8)
		{
			TPacketGCFishingPangea packetGCFishingPangea;
			memcpy(&packetGCFishingPangea, destBuf, sizeof(TPacketGCFishingPangea));
			DWORD vid = GameFunctions::PlayerGetMainCharacterIndex();
			if (packetGCFishingPangea.subheader == 2 && packetGCFishingPangea.vid == vid)
			{
				Fish::Instance().AppendCastDirect(packetGCFishingPangea.count);
			}
		}
		break;
	case ServerName::METINPL:
		if (header == 42 && len >= sizeof(TPacketGCFishing) && Settings::FishBotEnable)
		{
			TPacketGCFishing packetGCFishing;
			memcpy(&packetGCFishing, destBuf, sizeof(TPacketGCFishing));
			//if (/*packetGCFishing.subheader == 3 || packetGCFishing.subheader == 4 ||*/ packetGCFishing.subheader == 5 && packetGCFishing.info == GameFunctions::PlayerGetMainCharacterIndex())
			//{
			//	return false;
			//}
			if (packetGCFishing.subheader == 2 && packetGCFishing.info == GameFunctions::PlayerGetMainCharacterIndex())
			{
				Fish::Instance().AppendCastDirect(1);
				return false;
			}
		}
		break;
	}
#ifdef DEVELOPER_MODE
	if (len > 1)
	{
		
		PacketSniffer::Instance().ProcessRecvPacket(len, pDestBuf, (DWORD)_ReturnAddress() - Globals::hEntryBaseAddress);
	}
#endif
	return ret;
}

static char hwid[39] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
static string hwid1;
static string hwid2;
static string hwid3;
//##################################################################################################################################################
bool _fastcall Hooks::NewCNetworkStreamSend(void* This, void* EDX, int len, void* pDestBuf)
{
	BYTE header;
	memcpy(&header, pDestBuf, sizeof(header));
	switch (Globals::Server)
	{
	case ServerName::VIDGAR:
		if (header == HEADER_CG_LOGIN3 && len == 361)
		{
			strncpy((char*)pDestBuf + 70, hwid1.c_str(), 43);
			strncpy((char*)pDestBuf + 167, hwid2.c_str(), 43);
			strncpy((char*)pDestBuf + 264, hwid3.c_str(), 43);
		}
		break;
	case ServerName::VALIUM:
		if (header == HEADER_CG_LOGIN3 && len == 140)
		{
			strncpy((char*)pDestBuf + 91, StringExtension::ToUpper(MiscExtension::RandomString(32)).c_str(), 32);
		}
		break;
	case ServerName::SG2:
		if (hwid[0] == NULL)
		{
			for (int i = 0; i < 39; i++)
			{
				if (MiscExtension::RandomInt(0, 1))
				{
					hwid[i] = MiscExtension::RandomInt(0x41, 0x46);
				}
				else
				{
					hwid[i] = MiscExtension::RandomInt(0x30, 0x39);
				}
			}
	}
		if (header == 0x6D && len == 93)
		{
			for (int i = 0; i < 39; i++)
			{
				if (MiscExtension::RandomInt(0, 1))
				{
					MemoryExtension::MemSet((DWORD)pDestBuf + 53 + i, hwid[i], 1);
				}
				else
				{
					MemoryExtension::MemSet((DWORD)pDestBuf + 53 + i, hwid[i], 1);
				}
			}


		}
		if (header == 0x6F && len == 106)
		{
			for (int i = 0; i < 39; i++)
			{
				if (MiscExtension::RandomInt(0, 1))
				{
					MemoryExtension::MemSet((DWORD)pDestBuf + 66 + i, hwid[i], 1);
				}
				else
				{
					MemoryExtension::MemSet((DWORD)pDestBuf + 66 + i, hwid[i], 1);
				}
			}
		}

		if (header == 0xF1 && len == 67)
		{
			char u[3] = { 0x62, 0x69, 0x6e };
			int o = 0;
			for (int i = 14; i < 17; i++)
			{

				MemoryExtension::MemSet((DWORD)pDestBuf + i, (int)u[o], 1);
			}
		}
		break;
	}
	bool ret = nCNetworkStreamSend(This, len, pDestBuf);
	BYTE* destBuf = (BYTE*)pDestBuf;
#ifdef DEVELOPER_MODE
	PacketSniffer::Instance().ProcessSendPacket(len, pDestBuf, (DWORD)_ReturnAddress() - Globals::hEntryBaseAddress);
#endif
	return ret;
}

bool _fastcall Hooks::NewCNetworkStreamSendAeldra(void* This, void* EDX, int len, void* pDestBuf, bool instant)
{
	BYTE header;
	memcpy(&header, pDestBuf, sizeof(header));

	//if (header == 0x02 && len == 6)
	//{
	//	strncpy((char*)pDestBuf + 2, "\xB5", 1);
	//}
	if (header == 0x0A && len > 120)
	{
		for (int i = 0; i < len; i++)
		{
			BYTE check1 = 0;
			BYTE check2 = 0;
			BYTE check3 = 0;
			BYTE check4 = 0;
			memcpy(&check1, static_cast<char*>(pDestBuf) + i, sizeof(check1));
			memcpy(&check2, static_cast<char*>(pDestBuf) + (i + 1), sizeof(check2));
			memcpy(&check3, static_cast<char*>(pDestBuf) + (i + 2), sizeof(check3));
			memcpy(&check4, static_cast<char*>(pDestBuf) + (i + 3), sizeof(check4));
			if (check1 == 0xDD && check2 == 0xFC && check3 == 0xDF && check4 == 0xF9)
			{
				strncpy((char*)pDestBuf + (i), "\xBD\xDE\xA0\xFA", 4); //83 d8 9f fa
				break;
			}
		}
	}

	bool ret = nCNetworkStreamSendAeldra(This, len, pDestBuf, 1);
	//BYTE* destBuf = (BYTE*)pDestBuf;
#ifdef DEVELOPER_MODE
	PacketSniffer::Instance().ProcessSendPacket(len, (void*)pDestBuf, (DWORD)_ReturnAddress() - Globals::hEntryBaseAddress);
#endif
	return ret;
}

//int _stdcall Hooks::NewCNetworkStreamSendAeldra(SOCKET s, const char* pDestBuf, int len, int flags)
//{
//	BYTE header;
//	memcpy(&header, pDestBuf, sizeof(header));
//
//	if (header == 0x02 && len == 6)
//	{
//		strncpy((char*)pDestBuf + 2, "\xA7", 1);
//	}
//	if (header == 0x0A && len > 150)
//	{
//		strncpy((char*)pDestBuf + (len - 85), "\x9C\xBF\xFE\xF9", 4);
//		//strncpy((char*)pDestBuf + (len - 85), "\xB1\xC4\x90\xFA", 4);
//	}
//
//	int ret = nCNetworkStreamSendAeldra(s, pDestBuf, len, flags);
//	BYTE* destBuf = (BYTE*)pDestBuf;
//#ifdef DEVELOPER_MODE
//	PacketSniffer::Instance().ProcessSendPacket(len, (void*)pDestBuf, (DWORD)_ReturnAddress() - Globals::hEntryBaseAddress);
//#endif
//	return ret;
//}

bool _fastcall Hooks::NewCNetworkStreamSendSequence(void* This, void* EDX)
{
	bool ret = nCNetworkStreamSendSequence(This);
	return ret;
}
//##################################################################################################################################################
void _fastcall Hooks::NewCPythonChatAppendChat(void* This, void* EDX, int iType, const char* c_szChat)
{
	if (iType == CHAT_TYPE_TALKING)
	{
		if (Settings::ProtectionShowTalkBalloon)
		{
			string title = StringExtension::StringFormat("Normal[%s]", GameFunctionsCustom::PlayerGetName());
			MiscExtension::UpdateBalloon(Globals::mainHwnd, title.c_str(), c_szChat, NULL);
		}
		if (Settings::ProtectionPlayTalkBeep)
		{
			CreateThread(0, NULL, (LPTHREAD_START_ROUTINE)MiscExtension::PlayAlerSound, NULL, NULL, NULL);
		}

		if (Settings::ProtectionFlashTalkIcon)
		{
			FLASHWINFO fi;
			fi.cbSize = sizeof(FLASHWINFO);
			fi.hwnd = Globals::mainHwnd;
			fi.dwFlags = FLASHW_ALL;
			fi.uCount = 3;
			fi.dwTimeout = 0;
			FlashWindowEx(&fi);


		}

		if (Settings::ProtectionShowTalkLogs)
		{
			Logger::Add(Logger::MAIN, true, Logger::WHITE, c_szChat);
			
		}
		
	}

#ifdef FISHBOT
	if (iType == CHAT_TYPE_NOTICE || iType == CHAT_TYPE_INFO)
	{
		Fish::Instance().ParseMessage(c_szChat);
	}
#endif
//#ifdef DEVELOPER_MODE
//	if (StringExtension::Contains(c_szChat, "|cff0AFF0A|h[Informacja] |h|r") && StringExtension::Contains(c_szChat, " dolaczyl na serwer Vidgar.pl!")) {
//		string Text1 = StringExtension::ReplaceString(c_szChat, "|cff0AFF0A|h[Informacja] |h|r", "");
//		string Text2 = StringExtension::ReplaceString(Text1, " dolaczyl na serwer Vidgar.pl!", "");
//		string Text3 = Text2 + "\n";
//		std::ofstream outfile;
//		outfile.open("nicki.txt", std::ios_base::app);
//		outfile << Text3;
//	}
//#endif

	nCPythonChatAppendChat(This, iType, c_szChat);
}
//##################################################################################################################################################
bool _fastcall Hooks::NewCPythonNetworkStreamSendChatPacket(void* This, void* EDX, const char* c_szChat, BYTE byType)
{
	return nCPythonNetworkStreamSendChatPacket(This, c_szChat, byType);
}


//##################################################################################################################################################


DWORD* _fastcall Hooks::NewCResourceManagerGetResourcePointer(void* This, void* EDX, const char* c_szFileName)
{
#if defined(VALIUM)
	Fish::Instance().ParseMessage(c_szFileName);

#endif
#if defined(GLADOR)
	FishBot::ParseMessage(c_szFileName);
#endif

	/*MainForm::LogSniffer(0, c_szFileName);
	MainForm::LogSniffer(0, "\n");
	string line = std::to_string((DWORD)_ReturnAddress() - Globals::hEntryBaseAddress);
	line += "\n";
	MainForm::LogSniffer(0, line.c_str());*/
	return nCResourceManagerGetResourcePointer(This, c_szFileName);
}



bool _fastcall Hooks::NewCPythonApplicationProcess(void* This, void* EDX)
{
	if (MainForm::IsInitialized) 
	{
		MainCore::UpdateLoop();
	}
	bool ret =  nCPythonApplicationProcess(This);
	return ret;
}

void _fastcall Hooks::NewCPythonApplicationOnUIRender(void* This, void* EDX)
{
	nCPythonApplicationOnUIRender(This);
	if (Device::pDevice != NULL) 
	{
		if (!MainForm::IsInitialized)
		{
			MainForm::Initialize();
		}
		else 
		{
			MainForm::Menu();
		}
	}
}

Globals::tCPythonNetworkStreamSendCharacterStatePacket nCPythonNetworkStreamSendCharacterStatePacket;
bool _fastcall NewCPythonNetworkStreamSendCharacterStatePacket(void* This, void* EDX, const D3DVECTOR& c_rkPPosDst, float fDstRot, UINT eFunc, UINT uArg /*,BYTE unk*/)
{

	string u =StringExtension::StringFormat( "z[%f] y[% f] z[%f]   fDstRot [%f]    eFunc [%d]  uArg [%d]  unk [%d]\n", c_rkPPosDst.x, c_rkPPosDst.y, c_rkPPosDst.z, fDstRot,  eFunc,  uArg/*,  unk*/);
	Logger::Add(Logger::MAIN, true, Logger::WHITE, u.c_str());
	return nCPythonNetworkStreamSendCharacterStatePacket( This, c_rkPPosDst,  fDstRot, eFunc, uArg/*, unk*/);
}


Globals::tCPythonNetworkStreamSendCommandPacket nCPythonNetworkStreamSendCommandPacket;
bool _fastcall NewCPythonNetworkStreamSendCommandPacket(void* This, void* EDX,  DWORD a1, DWORD a2, const char* a3)
{

	string u = StringExtension::StringFormat("z[%d] y[% d] z[%s]  ", a1, a2, a3);
	Logger::Add(Logger::MAIN, true, Logger::WHITE, u.c_str());
	return nCPythonNetworkStreamSendCommandPacket(This, a1,a2,a3);
}

void _fastcall Hooks::NewCInputKeyboardUpdateKeyboard(void* This, void* EDX) 
{
	if (MainForm::IsInitialized && MainForm::SideBarIsOpen) 
	{
		ImGuiIO& io = ImGui::GetIO();
		if (io.WantCaptureKeyboard || io.WantTextInput)
		{
			return;
		}
	}
	nCInputKeyboardUpdateKeyboard(This);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Hooks::Initialize()
{
	switch (Globals::Server)
	{
	case ServerName::AELDRA:
		//nCPythonApplicationProcess = (Globals::tCPythonApplicationProcess)DetourFunction((PBYTE)Globals::CPythonApplicationProcess, (PBYTE)NewCPythonApplicationProcess);
		/*nCNetworkStreamRecv = (Globals::tCNetworkStreamRecv)DetourFunction((PBYTE)Globals::CNetworkStreamRecv, (PBYTE)NewCNetworkStreamRecv);*/
		//nCNetworkStreamSendAeldra = (Globals::tCNetworkStreamSendAeldra)DetourFunction((PBYTE)Globals::CNetworkStreamSend, (PBYTE)NewCNetworkStreamSendAeldra);
		nCPythonApplicationOnUIRender = (Globals::tCPythonApplicationOnUIRender)DetourFunction((PBYTE)Globals::CPythonApplicationOnUIRender, (PBYTE)NewCPythonApplicationOnUIRender);
		//nCPythonApplicationRenderGame = (Globals::tCPythonApplicationRenderGame)DetourFunction((PBYTE)Globals::CPythonApplicationRenderGame, (PBYTE)NewCPythonApplicationRenderGame);
	    //nPyCallClassMemberFunc = (Globals::tPyCallClassMemberFunc)DetourFunction((PBYTE)Globals::PyCallClassMemberFunc, (PBYTE)NewPyCallClassMemberFunc);
		//nCPhysicsObjectIncreaseExternalForce = (Globals::tCPhysicsObjectIncreaseExternalForce)DetourFunction((PBYTE)Globals::CPhysicsObjectIncreaseExternalForce, (PBYTE)NewCPhysicsObjectIncreaseExternalForce);
		//nCInstanceBaseAvoidObject = (Globals::tCInstanceBaseAvoidObject)DetourFunction((PBYTE)Globals::CInstanceBaseAvoidObject, (PBYTE)NewCInstanceBaseAvoidObject);
		//nCInstanceBaseBlockMovement = (Globals::tCInstanceBaseBlockMovement)DetourFunction((PBYTE)Globals::CInstanceBaseBlockMovement, (PBYTE)NewCInstanceBaseBlockMovement);
		//nCActorInstanceTestActorCollision = (Globals::tCActorInstanceTestActorCollision)DetourFunction((PBYTE)Globals::CActorInstanceTestActorCollision, (PBYTE)NewCActorInstanceTestActorCollision);
		//nCInputKeyboardUpdateKeyboard = (Globals::tCInputKeyboardUpdateKeyboard)DetourFunction((PBYTE)Globals::CInputKeyboardUpdateKeyboard, (PBYTE)NewCInputKeyboardUpdateKeyboard);
		//nCPythonChatAppendChat = (Globals::tCPythonChatAppendChat)DetourFunction((PBYTE)Globals::CPythonChatAppendChat, (PBYTE)NewCPythonChatAppendChat);
		break;
	case ServerName::ORIGINS:
		nCPythonApplicationProcess = (Globals::tCPythonApplicationProcess)DetourFunction((PBYTE)Globals::CPythonApplicationProcess, (PBYTE)NewCPythonApplicationProcess);
		/*nCNetworkStreamRecv = (Globals::tCNetworkStreamRecv)DetourFunction((PBYTE)Globals::CNetworkStreamRecv, (PBYTE)NewCNetworkStreamRecv);*/
		nCNetworkStreamSend = (Globals::tCNetworkStreamSend)DetourFunction((PBYTE)Globals::CNetworkStreamSend, (PBYTE)NewCNetworkStreamSend);
		nCPythonApplicationOnUIRender = (Globals::tCPythonApplicationOnUIRender)DetourFunction((PBYTE)Globals::CPythonApplicationOnUIRender, (PBYTE)NewCPythonApplicationOnUIRender);
		nCPythonApplicationRenderGame = (Globals::tCPythonApplicationRenderGame)DetourFunction((PBYTE)Globals::CPythonApplicationRenderGame, (PBYTE)NewCPythonApplicationRenderGame);
		nPyCallClassMemberFunc = (Globals::tPyCallClassMemberFunc)DetourFunction((PBYTE)Globals::PyCallClassMemberFunc, (PBYTE)NewPyCallClassMemberFunc);
		nCPhysicsObjectIncreaseExternalForce = (Globals::tCPhysicsObjectIncreaseExternalForce)DetourFunction((PBYTE)Globals::CPhysicsObjectIncreaseExternalForce, (PBYTE)NewCPhysicsObjectIncreaseExternalForce);
		nCInstanceBaseAvoidObject = (Globals::tCInstanceBaseAvoidObject)DetourFunction((PBYTE)Globals::CInstanceBaseAvoidObject, (PBYTE)NewCInstanceBaseAvoidObject);
		nCInstanceBaseBlockMovement = (Globals::tCInstanceBaseBlockMovement)DetourFunction((PBYTE)Globals::CInstanceBaseBlockMovement, (PBYTE)NewCInstanceBaseBlockMovement);
		nCActorInstanceTestActorCollision = (Globals::tCActorInstanceTestActorCollision)DetourFunction((PBYTE)Globals::CActorInstanceTestActorCollision, (PBYTE)NewCActorInstanceTestActorCollision);
		nCInputKeyboardUpdateKeyboard = (Globals::tCInputKeyboardUpdateKeyboard)DetourFunction((PBYTE)Globals::CInputKeyboardUpdateKeyboard, (PBYTE)NewCInputKeyboardUpdateKeyboard);
		nCPythonChatAppendChat = (Globals::tCPythonChatAppendChat)DetourFunction((PBYTE)Globals::CPythonChatAppendChat, (PBYTE)NewCPythonChatAppendChat);
		break;
	case ServerName::CALLIOPE:
		nCPythonApplicationProcess = (Globals::tCPythonApplicationProcess)DetourFunction((PBYTE)Globals::CPythonApplicationProcess, (PBYTE)NewCPythonApplicationProcess);
		/*nCNetworkStreamRecv = (Globals::tCNetworkStreamRecv)DetourFunction((PBYTE)Globals::CNetworkStreamRecv, (PBYTE)NewCNetworkStreamRecv);*/
		nCNetworkStreamSend = (Globals::tCNetworkStreamSend)DetourFunction((PBYTE)Globals::CNetworkStreamSend, (PBYTE)NewCNetworkStreamSend);
		nCPythonApplicationOnUIRender = (Globals::tCPythonApplicationOnUIRender)DetourFunction((PBYTE)Globals::CPythonApplicationOnUIRender, (PBYTE)NewCPythonApplicationOnUIRender);
		nCPythonApplicationRenderGame = (Globals::tCPythonApplicationRenderGame)DetourFunction((PBYTE)Globals::CPythonApplicationRenderGame, (PBYTE)NewCPythonApplicationRenderGame);
		nPyCallClassMemberFunc = (Globals::tPyCallClassMemberFunc)DetourFunction((PBYTE)Globals::PyCallClassMemberFunc, (PBYTE)NewPyCallClassMemberFunc);
		nCPhysicsObjectIncreaseExternalForce = (Globals::tCPhysicsObjectIncreaseExternalForce)DetourFunction((PBYTE)Globals::CPhysicsObjectIncreaseExternalForce, (PBYTE)NewCPhysicsObjectIncreaseExternalForce);
		nCInstanceBaseAvoidObject = (Globals::tCInstanceBaseAvoidObject)DetourFunction((PBYTE)Globals::CInstanceBaseAvoidObject, (PBYTE)NewCInstanceBaseAvoidObject);
		nCInstanceBaseBlockMovement = (Globals::tCInstanceBaseBlockMovement)DetourFunction((PBYTE)Globals::CInstanceBaseBlockMovement, (PBYTE)NewCInstanceBaseBlockMovement);
		nCActorInstanceTestActorCollision = (Globals::tCActorInstanceTestActorCollision)DetourFunction((PBYTE)Globals::CActorInstanceTestActorCollision, (PBYTE)NewCActorInstanceTestActorCollision);
		nCInputKeyboardUpdateKeyboard = (Globals::tCInputKeyboardUpdateKeyboard)DetourFunction((PBYTE)Globals::CInputKeyboardUpdateKeyboard, (PBYTE)NewCInputKeyboardUpdateKeyboard);
		nCPythonChatAppendChat = (Globals::tCPythonChatAppendChat)DetourFunction((PBYTE)Globals::CPythonChatAppendChat, (PBYTE)NewCPythonChatAppendChat);
		break;
	case ServerName::MEDIUMMT2:
		nCPythonApplicationProcess = (Globals::tCPythonApplicationProcess)DetourFunction((PBYTE)Globals::CPythonApplicationProcess, (PBYTE)NewCPythonApplicationProcess);
		nCNetworkStreamRecv = (Globals::tCNetworkStreamRecv)DetourFunction((PBYTE)Globals::CNetworkStreamRecv, (PBYTE)NewCNetworkStreamRecv);
		nCNetworkStreamSend = (Globals::tCNetworkStreamSend)DetourFunction((PBYTE)Globals::CNetworkStreamSend, (PBYTE)NewCNetworkStreamSend);
		nCPythonApplicationOnUIRender = (Globals::tCPythonApplicationOnUIRender)DetourFunction((PBYTE)Globals::CPythonApplicationOnUIRender, (PBYTE)NewCPythonApplicationOnUIRender);
		nCPythonApplicationRenderGame = (Globals::tCPythonApplicationRenderGame)DetourFunction((PBYTE)Globals::CPythonApplicationRenderGame, (PBYTE)NewCPythonApplicationRenderGame);
		nPyCallClassMemberFunc = (Globals::tPyCallClassMemberFunc)DetourFunction((PBYTE)Globals::PyCallClassMemberFunc, (PBYTE)NewPyCallClassMemberFunc);
		nCPhysicsObjectIncreaseExternalForce = (Globals::tCPhysicsObjectIncreaseExternalForce)DetourFunction((PBYTE)Globals::CPhysicsObjectIncreaseExternalForce, (PBYTE)NewCPhysicsObjectIncreaseExternalForce);
		nCInstanceBaseAvoidObject = (Globals::tCInstanceBaseAvoidObject)DetourFunction((PBYTE)Globals::CInstanceBaseAvoidObject, (PBYTE)NewCInstanceBaseAvoidObject);
		nCInstanceBaseBlockMovement = (Globals::tCInstanceBaseBlockMovement)DetourFunction((PBYTE)Globals::CInstanceBaseBlockMovement, (PBYTE)NewCInstanceBaseBlockMovement);
		//nCActorInstanceTestActorCollision = (Globals::tCActorInstanceTestActorCollision)DetourFunction((PBYTE)Globals::CActorInstanceTestActorCollision, (PBYTE)NewCActorInstanceTestActorCollision);
		nCInputKeyboardUpdateKeyboard = (Globals::tCInputKeyboardUpdateKeyboard)DetourFunction((PBYTE)Globals::CInputKeyboardUpdateKeyboard, (PBYTE)NewCInputKeyboardUpdateKeyboard);
		nCPythonChatAppendChat = (Globals::tCPythonChatAppendChat)DetourFunction((PBYTE)Globals::CPythonChatAppendChat, (PBYTE)NewCPythonChatAppendChat);
		break;
	case ServerName::VEDNAR:
		nCPythonApplicationProcess = (Globals::tCPythonApplicationProcess)DetourFunction((PBYTE)Globals::CPythonApplicationProcess, (PBYTE)NewCPythonApplicationProcess);
		nCNetworkStreamRecv = (Globals::tCNetworkStreamRecv)DetourFunction((PBYTE)Globals::CNetworkStreamRecv, (PBYTE)NewCNetworkStreamRecv);
		nCNetworkStreamSend = (Globals::tCNetworkStreamSend)DetourFunction((PBYTE)Globals::CNetworkStreamSend, (PBYTE)NewCNetworkStreamSend);
		nCPythonApplicationOnUIRender = (Globals::tCPythonApplicationOnUIRender)DetourFunction((PBYTE)Globals::CPythonApplicationOnUIRender, (PBYTE)NewCPythonApplicationOnUIRender);
		nCPythonApplicationRenderGame = (Globals::tCPythonApplicationRenderGame)DetourFunction((PBYTE)Globals::CPythonApplicationRenderGame, (PBYTE)NewCPythonApplicationRenderGame);
		nPyCallClassMemberFunc = (Globals::tPyCallClassMemberFunc)DetourFunction((PBYTE)Globals::PyCallClassMemberFunc, (PBYTE)NewPyCallClassMemberFunc);
		nCPhysicsObjectIncreaseExternalForce = (Globals::tCPhysicsObjectIncreaseExternalForce)DetourFunction((PBYTE)Globals::CPhysicsObjectIncreaseExternalForce, (PBYTE)NewCPhysicsObjectIncreaseExternalForce);
		nCInstanceBaseAvoidObject = (Globals::tCInstanceBaseAvoidObject)DetourFunction((PBYTE)Globals::CInstanceBaseAvoidObject, (PBYTE)NewCInstanceBaseAvoidObject);
		nCInstanceBaseBlockMovement = (Globals::tCInstanceBaseBlockMovement)DetourFunction((PBYTE)Globals::CInstanceBaseBlockMovement, (PBYTE)NewCInstanceBaseBlockMovement);
		nCActorInstanceTestActorCollision = (Globals::tCActorInstanceTestActorCollision)DetourFunction((PBYTE)Globals::CActorInstanceTestActorCollision, (PBYTE)NewCActorInstanceTestActorCollision);
		nCInputKeyboardUpdateKeyboard = (Globals::tCInputKeyboardUpdateKeyboard)DetourFunction((PBYTE)Globals::CInputKeyboardUpdateKeyboard, (PBYTE)NewCInputKeyboardUpdateKeyboard);
		nCPythonChatAppendChat = (Globals::tCPythonChatAppendChat)DetourFunction((PBYTE)Globals::CPythonChatAppendChat, (PBYTE)NewCPythonChatAppendChat);
		break;
	case ServerName::BARIA:
		nCPythonApplicationProcess = (Globals::tCPythonApplicationProcess)DetourFunction((PBYTE)Globals::CPythonApplicationProcess, (PBYTE)NewCPythonApplicationProcess);
		nCNetworkStreamRecv = (Globals::tCNetworkStreamRecv)DetourFunction((PBYTE)Globals::CNetworkStreamRecv, (PBYTE)NewCNetworkStreamRecv);
		nCNetworkStreamSend = (Globals::tCNetworkStreamSend)DetourFunction((PBYTE)Globals::CNetworkStreamSend, (PBYTE)NewCNetworkStreamSend);
		nCPythonApplicationOnUIRender = (Globals::tCPythonApplicationOnUIRender)DetourFunction((PBYTE)Globals::CPythonApplicationOnUIRender, (PBYTE)NewCPythonApplicationOnUIRender);
		nCPythonApplicationRenderGame = (Globals::tCPythonApplicationRenderGame)DetourFunction((PBYTE)Globals::CPythonApplicationRenderGame, (PBYTE)NewCPythonApplicationRenderGame);
		nPyCallClassMemberFunc = (Globals::tPyCallClassMemberFunc)DetourFunction((PBYTE)Globals::PyCallClassMemberFunc, (PBYTE)NewPyCallClassMemberFunc);
		nCPhysicsObjectIncreaseExternalForce = (Globals::tCPhysicsObjectIncreaseExternalForce)DetourFunction((PBYTE)Globals::CPhysicsObjectIncreaseExternalForce, (PBYTE)NewCPhysicsObjectIncreaseExternalForce);
		nCInstanceBaseAvoidObject = (Globals::tCInstanceBaseAvoidObject)DetourFunction((PBYTE)Globals::CInstanceBaseAvoidObject, (PBYTE)NewCInstanceBaseAvoidObject);
		nCInstanceBaseBlockMovement = (Globals::tCInstanceBaseBlockMovement)DetourFunction((PBYTE)Globals::CInstanceBaseBlockMovement, (PBYTE)NewCInstanceBaseBlockMovement);
		nCActorInstanceTestActorCollision = (Globals::tCActorInstanceTestActorCollision)DetourFunction((PBYTE)Globals::CActorInstanceTestActorCollision, (PBYTE)NewCActorInstanceTestActorCollision);
		nCInputKeyboardUpdateKeyboard = (Globals::tCInputKeyboardUpdateKeyboard)DetourFunction((PBYTE)Globals::CInputKeyboardUpdateKeyboard, (PBYTE)NewCInputKeyboardUpdateKeyboard);
		//nCPythonChatAppendChat = (Globals::tCPythonChatAppendChat)DetourFunction((PBYTE)Globals::CPythonChatAppendChat, (PBYTE)NewCPythonChatAppendChat);
		break;
	case ServerName::METINPL:
		nCPythonApplicationProcess = (Globals::tCPythonApplicationProcess)DetourFunction((PBYTE)Globals::CPythonApplicationProcess, (PBYTE)NewCPythonApplicationProcess);
		nCNetworkStreamRecv = (Globals::tCNetworkStreamRecv)DetourFunction((PBYTE)Globals::CNetworkStreamRecv, (PBYTE)NewCNetworkStreamRecv);
		nCNetworkStreamSend = (Globals::tCNetworkStreamSend)DetourFunction((PBYTE)Globals::CNetworkStreamSend, (PBYTE)NewCNetworkStreamSend);
		nCPythonApplicationOnUIRender = (Globals::tCPythonApplicationOnUIRender)DetourFunction((PBYTE)Globals::CPythonApplicationOnUIRender, (PBYTE)NewCPythonApplicationOnUIRender);
		nCPythonApplicationRenderGame = (Globals::tCPythonApplicationRenderGame)DetourFunction((PBYTE)Globals::CPythonApplicationRenderGame, (PBYTE)NewCPythonApplicationRenderGame);
		nPyCallClassMemberFunc = (Globals::tPyCallClassMemberFunc)DetourFunction((PBYTE)Globals::PyCallClassMemberFunc, (PBYTE)NewPyCallClassMemberFunc);
		nCPhysicsObjectIncreaseExternalForce = (Globals::tCPhysicsObjectIncreaseExternalForce)DetourFunction((PBYTE)Globals::CPhysicsObjectIncreaseExternalForce, (PBYTE)NewCPhysicsObjectIncreaseExternalForce);
		nCInstanceBaseAvoidObject = (Globals::tCInstanceBaseAvoidObject)DetourFunction((PBYTE)Globals::CInstanceBaseAvoidObject, (PBYTE)NewCInstanceBaseAvoidObject);
		nCInstanceBaseBlockMovement = (Globals::tCInstanceBaseBlockMovement)DetourFunction((PBYTE)Globals::CInstanceBaseBlockMovement, (PBYTE)NewCInstanceBaseBlockMovement);
		nCActorInstanceTestActorCollision = (Globals::tCActorInstanceTestActorCollision)DetourFunction((PBYTE)Globals::CActorInstanceTestActorCollision, (PBYTE)NewCActorInstanceTestActorCollision);
		//nCPythonChatAppendChat = (Globals::tCPythonChatAppendChat)DetourFunction((PBYTE)Globals::CPythonChatAppendChat, (PBYTE)NewCPythonChatAppendChat);
		nCInputKeyboardUpdateKeyboard = (Globals::tCInputKeyboardUpdateKeyboard)DetourFunction((PBYTE)Globals::CInputKeyboardUpdateKeyboard, (PBYTE)NewCInputKeyboardUpdateKeyboard);
		break;
	}
}
