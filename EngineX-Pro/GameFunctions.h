#pragma once

class GameFunctions
{
public:
	//#################################################################################################################################
	static DWORD* CharacterManagerGetInstancePtr(int vid)
	{
		try
		{
			return Globals::CPythonCharacterManagerGetInstancePtr((void*)(Globals::iCPythonCharacterManagerInstance + 4), vid);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static const char* ItemDataGetName(DWORD* cItemData)
	{
		try
		{
			return Globals::CItemDataGetName(cItemData);
		}
		catch (...)
		{
			return "";
		}
	}
	//#################################################################################################################################
	static bool  ItemManagerGetItemDataPointer(DWORD dwItemID, DWORD** ppItemData)
	{
		try
		{
			return Globals::CItemManagerGetItemDataPointer((void*)(Globals::iCItemManagerInstance), dwItemID, ppItemData);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static DWORD PlayerGetMainCharacterIndex()
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				return PythonExtension::GetPythonInteger0(Globals::pCPythonPlayerGetMainCharacterIndex);
			}
			else
			{
				return Globals::CPythonPlayerGetMainCharacterIndex((void*)(Globals::iCPythonPlayerInstance + 4));
			}
		}
		catch (...)
		{
			return 0;
		}
	}
	//#################################################################################################################################
	static int PlayerGetStatus(DWORD dwType)
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				return PythonExtension::GetPythonInteger1(Globals::pCPythonPlayerGetStatus, 1);
			}
			else
			{
				return Globals::CPythonPlayerGetStatus((void*)(Globals::iCPythonPlayerInstance + 4), dwType);
			}
		}
		catch (...)
		{
			return 0;
		}
	}
	//#################################################################################################################################
	static DWORD PlayerGetItemIndex(TItemPos cell)
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				return PythonExtension::GetPythonInteger2(Globals::pCPythonPlayerGetItemIndex, cell.window_type, cell.cell);
			}
			else
			{
				switch (Globals::Server)
				{
				case ServerName::BARIA:
				{
					typedef DWORD(__thiscall* GetItemIndex)(void* This, TItemPos Cell, char unk);
					GetItemIndex ItemUse = (GetItemIndex)Globals::pCPythonPlayerGetItemIndex;
					return ItemUse((void*)(Globals::iCPythonPlayerInstance + 4), cell, '\0');
					break;
				}
				default:
				{
					return Globals::CPythonPlayerGetItemIndex((void*)(Globals::iCPythonPlayerInstance + 4), cell);
					break;
				}
				}
			}
		}
		catch (...)
		{
			return 0;
		}
	}
	//#################################################################################################################################

	static const char* PlayerGetName() 
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				return PythonExtension::GetPythonString0(Globals::pCPythonPlayerGetName);
			}
			else
			{
				return Globals::CPythonPlayerGetName((void*)(Globals::iCPythonPlayerInstance + 4));
			}
		}
		catch (...)
		{
			return "";
		}
	}
	//#################################################################################################################################
	static DWORD PlayerGetItemMetinSocket(int slot, DWORD dwMetinSocketIndex)
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				return PythonExtension::GetPythonInteger2(Globals::pCPythonPlayerGetItemMetinSocket, slot, dwMetinSocketIndex);
			}
			else
			{
				return Globals::CPythonPlayerGetItemMetinSocket((void*)(Globals::iCPythonPlayerInstance), TItemPos(INVENTORY, slot), dwMetinSocketIndex);
			}
		}
		catch (...)
		{
			return 0;
		}
	}
	//#################################################################################################################################
	static DWORD PlayerGetItemMetinSocket(TItemPos cell, DWORD dwMetinSocketIndex)
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				return PythonExtension::GetPythonInteger3(Globals::pCPythonPlayerGetItemMetinSocket, cell.window_type, cell.cell, dwMetinSocketIndex);
			}
			else
			{
				return Globals::CPythonPlayerGetItemMetinSocket((void*)(Globals::iCPythonPlayerInstance), cell, dwMetinSocketIndex);
			}
		}
		catch (...)
		{
			return 0;
		}
	}
	//#################################################################################################################################
	static DWORD PlayerGetRace()
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				return PythonExtension::GetPythonInteger0(Globals::pCPythonPlayerGetRace);
			}
			else
			{
				return Globals::CPythonPlayerGetRace((void*)Globals::iCPythonPlayerInstance);
			}
		}
		catch (...)
		{
			return 0;
		}
	}
	//#################################################################################################################################
	static void PlayerNEW_SetSingleDIKKeyState(int eDIKKey, bool isPress)
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				PythonExtension::CallPythonInteger2(Globals::pCPythonPlayerNEW_SetSingleDIKKeyState, eDIKKey, isPress);
			}
			else
			{
				return Globals::CPythonPlayerNEW_SetSingleDIKKeyState((void*)Globals::iCPythonPlayerInstance, eDIKKey, isPress);
			}
		}
		catch (...)
		{
		}
	}
	//#################################################################################################################################
	static void PlayerClickSkillSlot(int skillIndex)
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				PythonExtension::CallPythonInteger1(Globals::pCPythonPlayerClickSkillSlot, skillIndex);
			}
			else
			{
				Globals::CPythonPlayerClickSkillSlot((void*)Globals::iCPythonPlayerInstance, skillIndex);
			}
		}
		catch (...)
		{

		}
	}
	//#################################################################################################################################
	static bool PlayerIsSkillCoolTime(int skillIndex)
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				return PythonExtension::GetPythonInteger1(Globals::pCPythonPlayerIsSkillCoolTime, skillIndex);
			}
			else
			{
				return Globals::CPythonPlayerIsSkillCoolTime((void*)Globals::iCPythonPlayerInstance, skillIndex);
			}
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool PlayerIsSkillActive(DWORD dwSlotIndex)
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				return PythonExtension::GetPythonInteger1(Globals::pCPythonPlayerIsSkillActive, dwSlotIndex);
			}
			else
			{
				return Globals::CPythonPlayerIsSkillActive((void*)Globals::iCPythonPlayerInstance, dwSlotIndex);
			}
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static DWORD PlayerGetTargetVID()
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				return PythonExtension::GetPythonInteger0(Globals::pCPythonPlayerGetTargetVID);
			}
			else
			{
				return Globals::CPythonPlayerGetTargetVID((void*)Globals::iCPythonPlayerInstance);
			}
		}
		catch (...)
		{
			return 0;
		}
	}

	static void PlayerSetTarget(DWORD dwVID, BOOL bForceChange = true)
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				return PythonExtension::CallPythonInteger1(Globals::pCPythonPlayerSetTarget, dwVID);
			}
			else
			{
				return Globals::CPythonPlayerSetTarget((void*)(Globals::iCPythonPlayerInstance + 4), dwVID, bForceChange);
			}
		}
		catch (...)
		{

		}
	}
	//#################################################################################################################################
	static void PlayerSetAttackKeyState(bool state)
	{
		try
		{
			if (Globals::UsePythonFunctions)
			{
				return PythonExtension::CallPythonInteger1(Globals::pCPythonPlayerSetAttackKeyState, state);
			}
			else
			{
				Globals::CPythonPlayerSetAttackKeyState((void*)Globals::iCPythonPlayerInstance, state);
			}
		}
		catch (...)
		{
		}
	}
	//#################################################################################################################################
	static void Player__OnPressActor(DWORD* rkInstMain, DWORD dwPickedActorID, bool isAuto)
	{
		try
		{
			return Globals::CPythonPlayer__OnPressActor((void*)Globals::iCPythonPlayerInstance, rkInstMain, dwPickedActorID, isAuto);
		}
		catch (...)
		{
		}
	}
	//#################################################################################################################################
	static void Player__OnClickActor(DWORD* rkInstMain, DWORD dwPickedActorID, bool isAuto)
	{
		try
		{
			return Globals::CPythonPlayer__OnClickActor((void*)Globals::iCPythonPlayerInstance, rkInstMain, dwPickedActorID, isAuto);
		}
		catch (...)
		{
		}
	}
	//#################################################################################################################################
	static DWORD* PlayerNEW_GetMainActorPtr()
	{
		try
		{
			return Globals::CPythonPlayerNEW_GetMainActorPtr((void*)(Globals::iCPythonPlayerInstance + 4));
		}
		catch (...)
		{
			return NULL;
		}
	}
	//#################################################################################################################################
	static void PythonPlayerNEW_Fishing()
	{
		try
		{
			Globals::CPythonPlayerNEW_Fishing((void*)Globals::iCPythonPlayerInstance);
		}
		catch (...)
		{

		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendFishingPacket(int rot)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendFishingPacket((void*)Globals::iCPythonNetworkStreamInstance, rot);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendFishingQuitPacket(int count, float rot)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendFishingQuitPacket((void*)Globals::iCPythonNetworkStreamInstance, count, rot);
		}
		catch (...)
		{
			return false;
		}
	}

	static bool NetworkStreamSendEmoticon(BYTE emoticon)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendEmoticon((void*)Globals::iCPythonNetworkStreamInstance, emoticon);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static void NetworkStreamSendItemUsePacket(TItemPos cell)
	{
		try
		{
			switch (Globals::Server)
			{
			case ServerName::BARIA:
			{
				typedef bool(__thiscall* SendItemUsePacket)(void* This, TItemPos pos, char unk);
				SendItemUsePacket ItemUse = (SendItemUsePacket)Globals::pCPythonNetworkStreamSendItemUsePacket;
				ItemUse((void*)Globals::iCPythonNetworkStreamInstance, cell, '\0');
				break;
			}
			default:
			{
				Globals::CPythonNetworkStreamSendItemUsePacket((void*)Globals::iCPythonNetworkStreamInstance, cell);
				break;
			}
			}
		}
		catch (...)
		{

		}
	}
	//#################################################################################################################################
	static void NetworkStreamSendChatPacket(const char* c_szChat, BYTE byType = CHAT_TYPE_TALKING)
	{
		try
		{
			Globals::CPythonNetworkStreamSendChatPacket((void*)Globals::iCPythonNetworkStreamInstance, c_szChat, byType);
		}
		catch (...)
		{

		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendRefinePacket(BYTE pos, BYTE type)
	{
		try
		{
			switch (Globals::Server)
			{
			case ServerName::AELDRA:
			{
				try
				{
					typedef bool(__thiscall* SendRefinePacket)(void* This, BYTE byPos, BYTE byType, bool unk);
					SendRefinePacket sendRefine = (SendRefinePacket)Globals::pCPythonNetworkStreamSendRefinePacket;
					return sendRefine((void*)Globals::iCPythonNetworkStreamInstance, pos, type, 0);
				}
				catch (...)
				{
					return false;
				}
				break;
			}
			case ServerName::CALLIOPE:
			{
				try
				{
					typedef bool(__thiscall* SendRefinePacket)(void* This, BYTE byPos, BYTE byType, BYTE unk1, BYTE unk2, BYTE unk3, BYTE unk4);
					SendRefinePacket sendRefine = (SendRefinePacket)Globals::pCPythonNetworkStreamSendRefinePacket;
					return sendRefine((void*)Globals::iCPythonNetworkStreamInstance, pos, type, 0, 0, 0, 0);
				}
				catch (...)
				{
					return false;
				}
				break;
			}
			default:
			{
				return Globals::CPythonNetworkStreamSendRefinePacket((void*)Globals::iCPythonNetworkStreamInstance, pos, type);
				break;
			}
			}
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendSendExchangeStartPacket(DWORD vid)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendExchangeStartPacket((void*)Globals::iCPythonNetworkStreamInstance, vid);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendSendExchangeItemAddPacket(TItemPos ItemPos, BYTE byDisplayPos)
	{
		try
		{
			return  Globals::CPythonNetworkStreamSendExchangeItemAddPacket((void*)Globals::iCPythonNetworkStreamInstance, ItemPos, byDisplayPos);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendSendExchangeAcceptPacket()
	{
		try
		{
			return Globals::CPythonNetworkStreamSendExchangeAcceptPacket((void*)Globals::iCPythonNetworkStreamInstance);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendSpecial(int nLen, void* pvBuf)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendSpecial((void*)Globals::iCPythonNetworkStreamInstance, nLen, pvBuf);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendWhisperPacket(const char* name, string s_szChat)
	{
		try
		{
			switch (Globals::Server)
			{
			case ServerName::AELDRA:
			{
				try
				{
					typedef bool(__thiscall* SendWhisperPacket)(void* This, const char* name, const char* c_szChat, bool unk);
					SendWhisperPacket sendWhisper = (SendWhisperPacket)Globals::pCPythonNetworkStreamSendWhisperPacket;
					return sendWhisper((void*)Globals::iCPythonNetworkStreamInstance, name, s_szChat.c_str(), false);
				}
				catch (...)
				{
					return false;
				}
				break;
			}
			default:
			{
				return Globals::CPythonNetworkStreamSendWhisperPacket((void*)Globals::iCPythonNetworkStreamInstance, name, s_szChat.c_str());
				break;
			}
			}
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendAttackPacket(UINT uMotAttack, DWORD dwVIDVictim)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendAttackPacket((void*)Globals::iCPythonNetworkStreamInstance, uMotAttack, dwVIDVictim);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendUseSkillPacket(DWORD dwSkillIndex, DWORD dwTargetVID)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendUseSkillPacket((void*)Globals::iCPythonNetworkStreamInstance, dwSkillIndex, dwTargetVID);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendAddFlyTargetingPacket(DWORD dwTargetVID, D3DVECTOR& kPPosTarget)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendAddFlyTargetingPacket((void*)Globals::iCPythonNetworkStreamInstance, dwTargetVID, kPPosTarget);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendShootPacket(UINT uSkill)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendShootPacket((void*)Globals::iCPythonNetworkStreamInstance, uSkill);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendItemPickUpPacket(DWORD vid)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendItemPickUpPacket((void*)Globals::iCPythonNetworkStreamInstance, vid);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendItemDropPacketNew(TItemPos cell, DWORD elk, DWORD count)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendItemDropPacketNew((void*)Globals::iCPythonNetworkStreamInstance, cell, elk, count);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendScriptAnswerPacket(int iAnswer)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendScriptAnswerPacket((void*)Globals::iCPythonNetworkStreamInstance, iAnswer);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendOnClickPacket(DWORD vid)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendOnClickPacket((void*)Globals::iCPythonNetworkStreamInstance, vid);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendShopSellPacketNew(BYTE bySlot, BYTE byCount)
	{
		try
		{
			switch (Globals::Server)
			{
				case ServerName::METINPL:
				{
					typedef bool(__thiscall* SendShopSellPacketNew)(void* This, BYTE bySlot, BYTE byCount, BYTE unk);
					SendShopSellPacketNew SendShopSell = (SendShopSellPacketNew)Globals::pCPythonNetworkStreamSendShopSellPacketNew;
					SendShopSell((void*)Globals::iCPythonNetworkStreamInstance, bySlot, byCount, 1);
					break;
				}
				default:
				{
					return Globals::CPythonNetworkStreamSendShopSellPacketNew((void*)Globals::iCPythonNetworkStreamInstance, bySlot, byCount);
					break;
				}
			}
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendShopBuyPacket(BYTE bPos)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendShopBuyPacket((void*)Globals::iCPythonNetworkStreamInstance, bPos);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendShopEndPacket()
	{
		try
		{
			return Globals::CPythonNetworkStreamSendShopEndPacket((void*)Globals::iCPythonNetworkStreamInstance);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendGiveItemPacket(DWORD dwTargetVID, TItemPos ItemPos, int iItemCount)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendGiveItemPacket((void*)Globals::iCPythonNetworkStreamInstance, dwTargetVID, ItemPos, iItemCount);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendItemMovePacket(TItemPos pos, TItemPos change_pos, BYTE num)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendItemMovePacket((void*)Globals::iCPythonNetworkStreamInstance, pos, change_pos, num);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamRecv(int len, void* pSrcBuf)
	{
		try
		{
			return Globals::CNetworkStreamRecv((void*)Globals::iCPythonNetworkStreamInstance, len, pSrcBuf);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSend(int len, void* pSrcBuf)
	{
		try
		{
			switch (Globals::Server)
			{
				case ServerName::AELDRA:
				{
					typedef bool(__thiscall* NetworkStreamSend)(void* This, int len, void* pDestBuf, bool sendInstant);
					NetworkStreamSend Send = (NetworkStreamSend)Globals::pCNetworkStreamSend;
					return Send((void*)Globals::iCPythonNetworkStreamInstance, len, pSrcBuf, 0);
					break;
				}
				default:
				{
					return Globals::CNetworkStreamSend((void*)Globals::iCPythonNetworkStreamInstance, len, pSrcBuf);
					break;
				}
			}
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	/*static bool NetworkStreamPeek(int nLen, void* pvBuf)
	{
		return Globals::CNetworkStreamPeek((void*)Globals::iCPythonNetworkStreamInstance, nLen, pvBuf);
	}*/
	//#################################################################################################################################
	static bool NetworkStreamSendSequence()
	{
		try
		{
			return Globals::CNetworkStreamSendSequence((void*)Globals::iCPythonNetworkStreamInstance);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamSendCharacterStatePacket(const D3DVECTOR& c_rkPPosDst, float fDstRot, UINT eFunc, UINT uArg)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendCharacterStatePacket((void*)Globals::iCPythonNetworkStreamInstance, c_rkPPosDst, fDstRot, eFunc, uArg);
		}
		catch (...)
		{
			return false;
		}
	}
		
	//#################################################################################################################################
	static void NetworkStreamConnectGameServer(UINT iChrSlot)
	{
		try
		{
#if defined(EGORIA) || defined(SENTHIA)
			Globals::CPythonNetworkStreamConnectGameServer((void*)Globals::iCPythonNetworkStreamInstance, iChrSlot, 0);
#else
			Globals::CPythonNetworkStreamConnectGameServer((void*)Globals::iCPythonNetworkStreamInstance, iChrSlot);
#endif		
		}
		catch (...)
		{

		}
	}
	//#################################################################################################################################
	static void NetworkStream__DirectEnterMode_Set(UINT charSlot)
	{
		try
		{
			return Globals::CNetworkStream__DirectEnterMode_Set((void*)Globals::iCPythonNetworkStreamInstance, charSlot);
		}
		catch (...)
		{

		}
	}
	//#################################################################################################################################
	static bool NetworkStreamConnect(DWORD dwAddr, int port, int limitSec = 3)
	{
		try
		{
			return Globals::CNetworkStreamConnect((void*)Globals::iCPythonNetworkStreamInstance, dwAddr, port, limitSec);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamIsOnline()
	{
		try
		{
			return Globals::CNetworkStreamIsOnline((void*)Globals::iCPythonNetworkStreamInstance);
		}
		catch (...)
		{
			return false;
		}
	}
	//########################################################################## b nm,                                                                                                                                                                             #######################################################
	static DWORD NetworkStreamGetMainActorSkillGroup()
	{
		try
		{
			return Globals::CPythonNetworkStreamGetMainActorSkillGroup((void*)Globals::iCPythonNetworkStreamInstance);
		}
		catch (...)
		{
			return 0;
		}
	}
	//#################################################################################################################################
	static void NetworkStreamServerCommand(const char* c_szCommand)
	{
		try
		{
			return Globals::CPythonNetworkStreamServerCommand((void*)Globals::iCPythonNetworkStreamInstance, c_szCommand);
		}
		catch (...)
		{
		}
	}
	//#################################################################################################################################
	static bool NetworkStreamUseSequence()
	{
		try
		{
			return *reinterpret_cast<BYTE*>(Globals::iCPythonNetworkStreamInstance + 116);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static const char* NetworkStreamGetAccountCharacterSlotDataz(UINT iSlot, UINT eType)
	{
		try
		{
			return Globals::CNetworkStreamGetAccountCharacterSlotDataz((void*)Globals::iCPythonNetworkStreamInstance, iSlot, eType);
		}
		catch (...)
		{
			return "";
		}
	}
	//#################################################################################################################################
	static bool  NetworkStreamSendCommandPacket(DWORD a1, DWORD a2, const char* a3)
	{
		try
		{
			return Globals::CPythonNetworkStreamSendCommandPacket((void*)Globals::iCPythonNetworkStreamInstance, a1, a2, a3);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static void InstanceBase__SetAffect(DWORD* instance, UINT eAffect, bool isVisible)
	{
		try
		{
			return Globals::CInstanceBase__SetAffect(instance, eAffect, isVisible);
		}
		catch (...)
		{
		}
	}
	//#################################################################################################################################
	static void InstanceBaseNEW_GetPixelPosition(DWORD* instance, D3DVECTOR* pPixelPosition)
	{
		if (!instance)
		{
			return;
		}
		try
		{
			if (Globals::UsePythonFunctions)
			{
				*pPixelPosition = PythonExtension::GetPythonD3DVECTOR1(Globals::pCInstanceBaseNEW_GetPixelPosition, InstanceBaseGetVirtualNumber(instance));
			}
			else
			{
				Globals::CInstanceBaseNEW_GetPixelPosition(instance, pPixelPosition);
			}
		}
		catch (...)
		{
		}
	}
	//#################################################################################################################################
	static bool InstanceBaseNEW_MoveToDestPixelPositionDirection(DWORD* instance, D3DVECTOR& c_rkPPosDst)
	{
		try
		{
			return Globals::CInstanceBaseNEW_MoveToDestPixelPositionDirection(instance, c_rkPPosDst);
		}
		catch (...)
		{
			return false;
		}
		}
	//#################################################################################################################################
	static int InstanceBaseGetInstanceType(DWORD* instance)
	{
		if (!instance)
		{
			return -1;
		}
		try
		{
			return Globals::CInstanceBaseGetInstanceType(instance);
		}
		catch (...)
		{
			return -1;
		}
	}
	//#################################################################################################################################
	static int	InstanceBaseGetVirtualNumber(DWORD* instance)
	{
		if (!instance)
		{
			return -1;
		}
		try
		{
			return Globals::CInstanceBaseGetInstanceVirtualNumber(instance);
		}
		catch (...)
		{
			return -1;
		}
	}
	//#################################################################################################################################
	static bool InstanceBaseIsMountingHorse(DWORD* instance)
	{
		try
		{
			return Globals::CInstanceBaseIsMountingHorse(instance);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static const char* InstanceBaseGetNameString(DWORD* instance)
	{
		if (instance)
		{
			try
			{
				Globals::CInstanceBaseGetNameString(instance);
			}
			catch (...)
			{
				return "";
			}
		}
		else
		{
			return "";
		}
	}
	//#################################################################################################################################
	static bool InstanceBaseIsDead(DWORD* instance)
	{
		if (!instance)
		{
			return false;
		}
		try
		{
			return Globals::CInstanceBaseIsDead(instance);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static void InstanceBaseSCRIPT_SetPixelPosition(DWORD* instance, float x, float y)
	{
		try
		{
			DWORD address = Globals::pCInstanceBaseSCRIPT_SetPixelPosition;
			switch (Globals::Server)
			{
			case ServerName::VEDNAR:
			{
				__asm
				{
					mov     eax, [address]
					mov     ecx, instance
					movss   xmm2, [y]
					movss   xmm1, [x]
					call	eax
				}
				break;
			}
			case ServerName::CALLIOPE:
			{
				__asm
				{
					mov     eax, [address]
					mov     ecx, instance
					movss   xmm2, [y]
					movss   xmm1, [x]
					call	eax
				}
				break;
			}
			default:
			{
				Globals::CInstanceBaseSCRIPT_SetPixelPosition(instance, x, y);
				break;
			}
			}
		}
		catch (...)
		{

		}
	}
	//#################################################################################################################################
	static const bool InstanceIsWaiting(DWORD* instance)
	{
		try
		{
			return Globals::CInstanceBaseIsWaiting((void*)instance);
		}
		catch (...)
		{
			return false;
		}
	}
	//#################################################################################################################################
	static const void InstanceSetRotation(DWORD* instance, float fRotation)
	{
		try
		{
			Globals::CInstanceBaseSetRotation((void*)instance, fRotation);
		}
		catch (...)
		{
		}
	}
	//#################################################################################################################################
	static float InstanceBaseGetRotation(DWORD* instance)
	{
		try
		{
			return Globals::CInstanceBaseGetRotation(instance);
		}
		catch (...)
		{
			return 0.0f;
		}
	}
	//#################################################################################################################################
	static DWORD* ResourceManagerGetResourcePointer(const char* name)
	{
		try
		{
			return Globals::CResourceManagerGetResourcePointer((void*)Globals::iCResourceManagerInstance, name);
		}
		catch (...)
		{
			return NULL;
		}
	}
	//#################################################################################################################################
	static DWORD* GraphicImageGetTexturePointer(DWORD* instance)
	{
		try
		{
			return Globals::CGraphicImageGetTexturePointer((void*)instance);
		}
		catch (...)
		{
			return NULL;
		}
	}
	//#################################################################################################################################
	static DirectTexture GraphicTextureGetD3DTexture(DWORD* instance)
	{
		try
		{
			return Globals::CGraphicTextureGetD3DTexture((void*)instance);
		}
		catch (...)
		{
			return NULL;
		}
	}
	//#################################################################################################################################
	static const TMobTable* NonPlayerGetTable(int vid)
	{
		try
		{
			return (const TMobTable*)Globals::CPythonNonPlayerGetTable((void*)Globals::iCPythonNonPlayerInstance, vid);
		}
		catch (...)
		{
			return NULL;
		}
	}
	//#################################################################################################################################
	static void BackgroundLocalPositionToGlobalPosition(LONG& rLocalX, LONG& rLocalY)
	{
		try
		{
			return Globals::CPythonBackgroundLocalPositionToGlobalPosition((void*)Globals::iCPythonBackgroundInstance, rLocalX, rLocalY);
		}
		catch (...)
		{

		}
	}
	//#################################################################################################################################
	static TMapInfo* BackgroundGlobalPositionToMapInfo(DWORD dwGlobalX, DWORD dwGlobalY)
	{
		try
		{
			return Globals::CBackgroundGlobalPositionToMapInfo((void*)Globals::iCPythonBackgroundInstance, dwGlobalX, dwGlobalY);
		}
		catch (...)
		{
			return NULL;
		}
	}
	//#################################################################################################################################
	static float GetBackgroundHeight(float x, float y)
	{
		try
		{
			DWORD address = Globals::pCInstanceBase__GetBackgroundHeight;
			float height = 0;
			switch (Globals::Server)
			{
			case ServerName::CALLIOPE:
			{
				DWORD* instance = PlayerNEW_GetMainActorPtr();
				if (instance)
				{
					__asm
					{
						mov     eax, [address]
						mov     ecx, instance
						movss   xmm2, [y]
						movss   xmm1, [x]
						call	eax
						movss[height], xmm0
					}
				}
				break;
			}
			default:
			{
				height = Globals::CInstanceBase__GetBackgroundHeight(x, y);
				break;
			}
			}
			return height;
		}
		catch (...)
		{
			return 0.0f;
		}
	}
};

