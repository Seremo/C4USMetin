#pragma once

class GameFunctions
{
public:
	//#################################################################################################################################
	static DWORD* PlayerNEW_GetMainActorPtr()
	{
		return Globals::CPythonPlayerNEW_GetMainActorPtr((void*)(Globals::iCPythonPlayerInstance + 4));
	}
	//#################################################################################################################################
	static void InstanceBaseSetDirection(DWORD* chr, int dir)
	{
		Globals::CInstanceBaseSetDirection(chr, dir);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendFishingPacket(int rot)
	{
		return Globals::CPythonNetworkStreamSendFishingPacket((void*)Globals::iCPythonNetworkStreamInstance, rot);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendFishingQuitPacket(int count, float rot)
	{
		return Globals::CPythonNetworkStreamSendFishingQuitPacket((void*)Globals::iCPythonNetworkStreamInstance, count, rot);
	}

	static bool NetworkStreamSendEmoticon(BYTE emoticon)
	{
		return Globals::CPythonNetworkStreamSendEmoticon((void*)Globals::iCPythonNetworkStreamInstance, emoticon);
	}
	//#################################################################################################################################
	static void PythonPlayerNEW_Fishing()
	{
		Globals::CPythonPlayerNEW_Fishing((void*)Globals::iCPythonPlayerInstance);
	}
	//#################################################################################################################################
	static void NetworkStreamSendItemUsePacket(TItemPos cell)
	{
#ifdef BARIA
		Globals::CPythonNetworkStreamSendItemUsePacket((void*)Globals::iCPythonNetworkStreamInstance, TItemPos(INVENTORY, slot), '\0');
#else
		Globals::CPythonNetworkStreamSendItemUsePacket((void*)Globals::iCPythonNetworkStreamInstance, cell);
#endif
	}
	//#################################################################################################################################
	static bool InstanceBaseIsMountingHorse(DWORD* instance)
	{
		return Globals::CInstanceBaseIsMountingHorse(instance);
	}
	//#################################################################################################################################
	static void NetworkStreamSendChatPacket(const char* c_szChat, BYTE byType = CHAT_TYPE_TALKING)
	{
		Globals::CPythonNetworkStreamSendChatPacket((void*)Globals::iCPythonNetworkStreamInstance, c_szChat, byType);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendRefinePacket(BYTE pos, BYTE type)
	{
#ifdef RUBINUM	
		return Globals::CPythonNetworkStreamSendRefinePacket((void*)Globals::iCPythonNetworkStreamInstance, pos, type,0);
#else
		return Globals::CPythonNetworkStreamSendRefinePacket((void*)Globals::iCPythonNetworkStreamInstance, pos, type);
#endif

		
	}
	//#################################################################################################################################
	static void PlayerClickSkillSlot(int skillIndex)
	{
		Globals::CPythonPlayerClickSkillSlot((void*)Globals::iCPythonPlayerInstance, skillIndex);
	}
	//#################################################################################################################################
	static bool PlayerIsSkillCoolTime(int skillIndex)
	{
		return Globals::CPythonPlayerIsSkillCoolTime((void*)Globals::iCPythonPlayerInstance, skillIndex);
	}
	//#################################################################################################################################
	static DWORD* CharacterManagerGetInstancePtr(int vid)
	{
		return Globals::CPythonCharacterManagerGetInstancePtr((void*)(Globals::iCPythonCharacterManagerInstance + 4), vid);
	}
	//#################################################################################################################################
	static const char* InstanceBaseGetNameString(DWORD* instance)
	{
		if (instance)
		{
			Globals::CInstanceBaseGetNameString(instance);
		}
		else
		{
			return "";
		}
	}
	//#################################################################################################################################
	static DWORD PlayerGetTargetVID()
	{
		return Globals::CPythonPlayerGetTargetVID((void*)Globals::iCPythonPlayerInstance);
	}

	static void PlayerSetTarget(DWORD dwVID, BOOL bForceChange = true)
	{
		return Globals::CPythonPlayerSetTarget((void*)(Globals::iCPythonPlayerInstance + 4), dwVID, bForceChange);
	}
	//#################################################################################################################################
	static bool PlayerIsSkillActive(DWORD dwSlotIndex)
	{
		return Globals::CPythonPlayerIsSkillActive((void*)Globals::iCPythonPlayerInstance, dwSlotIndex);
	}
	//#################################################################################################################################
	static void PlayerSetAttackKeyState(bool state)
	{
		Globals::CPythonPlayerSetAttackKeyState((void*)Globals::iCPythonPlayerInstance, state);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendSendExchangeStartPacket(DWORD vid)
	{
		return Globals::CPythonNetworkStreamSendExchangeStartPacket((void*)Globals::iCPythonNetworkStreamInstance, vid);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendSendExchangeItemAddPacket(TItemPos ItemPos, BYTE byDisplayPos)
	{
		return  Globals::CPythonNetworkStreamSendExchangeItemAddPacket((void*)Globals::iCPythonNetworkStreamInstance, ItemPos, byDisplayPos);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendSendExchangeAcceptPacket()
	{
		return Globals::CPythonNetworkStreamSendExchangeAcceptPacket((void*)Globals::iCPythonNetworkStreamInstance);
	}	
	//#################################################################################################################################
	static void InstanceBaseNEW_GetPixelPosition(DWORD* instance, D3DVECTOR* pPixelPosition)
	{
		if (!instance)
		{
			return;
		}
		return Globals::CInstanceBaseNEW_GetPixelPosition(instance, pPixelPosition);
	}
	//#################################################################################################################################
	static bool InstanceBaseNEW_MoveToDestPixelPositionDirection(DWORD* instance, D3DVECTOR& c_rkPPosDst)
	{
		return Globals::CInstanceBaseNEW_MoveToDestPixelPositionDirection(instance, c_rkPPosDst);
	}
	//#################################################################################################################################
	static int	InstanceBaseGetInstanceType(DWORD* instance)
	{
		if (!instance)
		{
			return -1;
		}
		return Globals::CInstanceBaseGetInstanceType(instance);
	}
	//#################################################################################################################################
	static int	InstanceBaseGetVirtualNumber(DWORD* instance)
	{
		if (!instance)
		{
			return -1;
		}
		return Globals::CInstanceBaseGetInstanceVirtualNumber(instance);
	}
	//#################################################################################################################################
	static DWORD PlayerGetMainCharacterIndex()
	{
		return Globals::CPythonPlayerGetMainCharacterIndex((void*)(Globals::iCPythonPlayerInstance + 4));
	}
	//#################################################################################################################################
	static int GameFunctions::PlayerGetStatus(DWORD dwType)
	{
		return Globals::CPythonPlayerGetStatus((void*)(Globals::iCPythonPlayerInstance + 4), dwType);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendSpecial(int nLen, void* pvBuf)
	{
		return Globals::CPythonNetworkStreamSendSpecial((void*)Globals::iCPythonNetworkStreamInstance, nLen, pvBuf);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendWhisperPacket(const char* name, const char* c_szChat)
	{
		return Globals::CPythonNetworkStreamSendWhisperPacket((void*)Globals::iCPythonNetworkStreamInstance, name, c_szChat);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendWhisperStringPacket(const char* name, string s_szChat)
	{
		return Globals::CPythonNetworkStreamSendWhisperPacket((void*)Globals::iCPythonNetworkStreamInstance, name, s_szChat.c_str());
	}
	//#################################################################################################################################
	static bool NetworkStreamSendAttackPacket(UINT uMotAttack, DWORD dwVIDVictim)
	{
		return Globals::CPythonNetworkStreamSendAttackPacket((void*)Globals::iCPythonNetworkStreamInstance, uMotAttack, dwVIDVictim);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendUseSkillPacket(DWORD dwSkillIndex, DWORD dwTargetVID)
	{
		return Globals::CPythonNetworkStreamSendUseSkillPacket((void*)Globals::iCPythonNetworkStreamInstance, dwSkillIndex, dwTargetVID);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendAddFlyTargetingPacket(DWORD dwTargetVID, D3DVECTOR& kPPosTarget)
	{
		return Globals::CPythonNetworkStreamSendAddFlyTargetingPacket((void*)Globals::iCPythonNetworkStreamInstance, dwTargetVID, kPPosTarget);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendShootPacket(UINT uSkill)
	{
		return Globals::CPythonNetworkStreamSendShootPacket((void*)Globals::iCPythonNetworkStreamInstance, uSkill);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendItemPickUpPacket(DWORD vid) 
	{
		return Globals::CPythonNetworkStreamSendItemPickUpPacket((void*)Globals::iCPythonNetworkStreamInstance, vid);
	}
	//#################################################################################################################################

	static DWORD PlayerGetItemIndex(TItemPos cell)
	{
#ifdef BARIA
		return Globals::CPythonPlayerGetItemIndex((void*)(Globals::iCPythonPlayerInstance + 4), cell,'\0');
#else
		return Globals::CPythonPlayerGetItemIndex((void*)(Globals::iCPythonPlayerInstance + 4), cell);
#endif
	}

	static const char* GameFunctions::PlayerGetName() 
	{
		return Globals::CPythonPlayerGetName((void*)(Globals::iCPythonPlayerInstance + 4));
	}
	//#################################################################################################################################
	static DWORD PlayerGetItemMetinSocket(int slot, DWORD dwMetinSocketIndex)
	{
		return Globals::CPythonPlayerGetItemMetinSocket((void*)(Globals::iCPythonPlayerInstance), TItemPos(INVENTORY, slot), dwMetinSocketIndex);
	}
	//#################################################################################################################################
	static DWORD PlayerGetItemMetinSocket(TItemPos cell, DWORD dwMetinSocketIndex)
	{
		return Globals::CPythonPlayerGetItemMetinSocket((void*)(Globals::iCPythonPlayerInstance), cell, dwMetinSocketIndex);
	}
	//#################################################################################################################################
	static DWORD PlayerGetRace()
	{
		return Globals::CPythonPlayerGetRace((void*)Globals::iCPythonPlayerInstance);
	}
	//#################################################################################################################################
	static const char* ItemDataGetName(DWORD* cItemData)
	{
		return Globals::CItemDataGetName(cItemData);
	}
	//#################################################################################################################################
	static bool  ItemManagerGetItemDataPointer(DWORD dwItemID, DWORD** ppItemData)
	{
		return Globals::CItemManagerGetItemDataPointer((void*)(Globals::iCItemManagerInstance), dwItemID, ppItemData);
	}
	
	//#################################################################################################################################
	static void InstanceBaseNEW_SetPixelPosition(DWORD* instance, const D3DVECTOR& c_rPixelPosition)
	{
#ifdef SAMIAS2
		return Globals::CInstanceBaseNEW_SetPixelPosition(instance, c_rPixelPosition.x, c_rPixelPosition.y, c_rPixelPosition.z);
#else
		return Globals::CInstanceBaseNEW_SetPixelPosition(instance, c_rPixelPosition);
#endif
	}
	//#################################################################################################################################
	static bool NetworkStreamSendItemDropPacketNew(TItemPos cell, DWORD elk, DWORD count)
	{
		return Globals::CPythonNetworkStreamSendItemDropPacketNew((void*)Globals::iCPythonNetworkStreamInstance, cell, elk, count);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendScriptAnswerPacket(int iAnswer)
	{
		return Globals::CPythonNetworkStreamSendScriptAnswerPacket((void*)Globals::iCPythonNetworkStreamInstance, iAnswer);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendOnClickPacket(DWORD vid)
	{
		return Globals::CPythonNetworkStreamSendOnClickPacket((void*)Globals::iCPythonNetworkStreamInstance, vid);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendShopSellPacketNew(BYTE bySlot, BYTE byCount)
	{
#ifdef METINPL
		return Globals::CPythonNetworkStreamSendShopSellPacketNew((void*)Globals::iCPythonNetworkStreamInstance, bySlot, byCount,  1);
#else
		return Globals::CPythonNetworkStreamSendShopSellPacketNew((void*)Globals::iCPythonNetworkStreamInstance, bySlot,  byCount);
#endif
	}
	//#################################################################################################################################
	static bool NetworkStreamSendShopBuyPacket(BYTE bPos)
	{
		return Globals::CPythonNetworkStreamSendShopBuyPacket((void*)Globals::iCPythonNetworkStreamInstance, bPos);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendShopEndPacket()
	{
		return Globals::CPythonNetworkStreamSendShopEndPacket((void*)Globals::iCPythonNetworkStreamInstance);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendGiveItemPacket(DWORD dwTargetVID, TItemPos ItemPos, int iItemCount)
	{
#ifdef METINPL
		return Globals::CPythonNetworkStreamSendGiveItemPacket((void*)Globals::iCPythonNetworkStreamInstance, dwTargetVID, ItemPos,  iItemCount);
#else
		return Globals::CPythonNetworkStreamSendGiveItemPacket((void*)Globals::iCPythonNetworkStreamInstance, dwTargetVID, ItemPos, iItemCount);
#endif
	}
	//#################################################################################################################################
	static bool NetworkStreamSendItemMovePacket(TItemPos pos, TItemPos change_pos, BYTE num)
	{
		return Globals::CPythonNetworkStreamSendItemMovePacket((void*)Globals::iCPythonNetworkStreamInstance, pos, change_pos, num);
	}
	//#################################################################################################################################
	static bool NetworkStreamRecv(int len, void* pSrcBuf)
	{
		return Globals::CNetworkStreamRecv((void*)Globals::iCPythonNetworkStreamInstance, len, pSrcBuf);
	}
	//#################################################################################################################################
	static bool NetworkStreamSend(int len, void* pSrcBuf)
	{
		return Globals::CNetworkStreamSend((void*)Globals::iCPythonNetworkStreamInstance, len, pSrcBuf);
	}
	//#################################################################################################################################
	/*static bool NetworkStreamPeek(int nLen, void* pvBuf)
	{
		return Globals::CNetworkStreamPeek((void*)Globals::iCPythonNetworkStreamInstance, nLen, pvBuf);
	}*/
	//#################################################################################################################################
	static bool NetworkStreamSendSequence()
	{
		return Globals::CNetworkStreamSendSequence((void*)Globals::iCPythonNetworkStreamInstance);
	}
	//#################################################################################################################################
	static bool NetworkStreamSendCharacterStatePacket(const D3DVECTOR& c_rkPPosDst, float fDstRot, UINT eFunc, UINT uArg)
	{
#ifdef RUBINUM
		return Globals::CPythonNetworkStreamSendCharacterStatePacket((void*)Globals::iCPythonNetworkStreamInstance, c_rkPPosDst, fDstRot, eFunc, uArg,0);
	}
#else
		return Globals::CPythonNetworkStreamSendCharacterStatePacket((void*)Globals::iCPythonNetworkStreamInstance, c_rkPPosDst, fDstRot, eFunc, uArg);
	}
#endif
		
	//#################################################################################################################################
	static void NetworkStreamConnectGameServer(UINT iChrSlot)
	{
#if defined(EGORIA) || defined(SENTHIA)
		return Globals::CPythonNetworkStreamConnectGameServer((void*)Globals::iCPythonNetworkStreamInstance, iChrSlot, 0);
#else
		return Globals::CPythonNetworkStreamConnectGameServer((void*)Globals::iCPythonNetworkStreamInstance, iChrSlot);
#endif
	}
	//#################################################################################################################################
	static void NetworkStream__DirectEnterMode_Set(UINT charSlot)
	{
		return Globals::CNetworkStream__DirectEnterMode_Set((void*)Globals::iCPythonNetworkStreamInstance, charSlot);
	}
	//#################################################################################################################################
	static bool NetworkStreamConnect(DWORD dwAddr, int port, int limitSec = 3)
	{
		return Globals::CNetworkStreamConnect((void*)Globals::iCPythonNetworkStreamInstance, dwAddr, port, limitSec);
	}
	//#################################################################################################################################
	static bool NetworkStreamIsOnline()
	{
#ifdef METINPL
		return *reinterpret_cast<bool*>((*reinterpret_cast<DWORD*>(Globals::iCPythonNetworkStreamInstance) + 104));
#else
		return Globals::CNetworkStreamIsOnline((void*)Globals::iCPythonNetworkStreamInstance);
#endif
	}
	//########################################################################## b nm,                                                                                                                                                                             #######################################################
	static DWORD NetworkStreamGetMainActorSkillGroup()
	{
		return Globals::CPythonNetworkStreamGetMainActorSkillGroup((void*)Globals::iCPythonNetworkStreamInstance);
	}
	//#################################################################################################################################
	static void InstanceBase__SetAffect(DWORD* instance, UINT eAffect, bool isVisible)
	{
		return Globals::CInstanceBase__SetAffect(instance, eAffect, isVisible);
	}
	//#################################################################################################################################
	static void Player__OnPressActor(DWORD* rkInstMain, DWORD dwPickedActorID, bool isAuto)
	{
		return Globals::CPythonPlayer__OnPressActor((void*)Globals::iCPythonPlayerInstance, rkInstMain, dwPickedActorID, isAuto);
	}
	//#################################################################################################################################
	static void Player__OnClickActor(DWORD* rkInstMain, DWORD dwPickedActorID, bool isAuto)
	{
		return Globals::CPythonPlayer__OnClickActor((void*)Globals::iCPythonPlayerInstance, rkInstMain, dwPickedActorID, isAuto);
	}
	//#################################################################################################################################
	static bool InstanceBaseIsDead(DWORD* instance)
	{
		if (!instance)
		{
			return false;
		}
		return Globals::CInstanceBaseIsDead(instance);
	}	
	//#################################################################################################################################
	static void InstanceBaseSCRIPT_SetPixelPosition(DWORD* instance, float x, float y)
	{
#if defined(EGORIA) || defined(RUBINUM)
		__asm
		{
			mov     eax, [0x481CF0]
			mov     ecx, instance
			movss   xmm2, [y]
			movss   xmm1, [x]
			call	eax
	}
#else
		return Globals::CInstanceBaseSCRIPT_SetPixelPosition(instance, x, y);
#endif
	}
	//#################################################################################################################################
	static void PlayerNEW_SetSingleDIKKeyState(int eDIKKey, bool isPress)
	{
		return Globals::CPythonPlayerNEW_SetSingleDIKKeyState((void*)Globals::iCPythonPlayerInstance, eDIKKey, isPress);
	}
	//#################################################################################################################################
	static void NetworkStreamServerCommand(const char* c_szCommand)
	{
		return Globals::CPythonNetworkStreamServerCommand((void*)Globals::iCPythonNetworkStreamInstance, c_szCommand);
	}
	//#################################################################################################################################
	static bool NetworkStreamUseSequence()
	{
		return *reinterpret_cast<BYTE*>(Globals::iCPythonNetworkStreamInstance + 116);
	}
	//#################################################################################################################################
	static float InstanceBaseGetRotation(DWORD* instance)
	{
		return Globals::CInstanceBaseGetRotation(instance);
	}
	//#################################################################################################################################
	static DWORD* ResourceManagerGetResourcePointer(const char* name)
	{
		return Globals::CResourceManagerGetResourcePointer((void*)Globals::iCResourceManagerInstance, name);
	}
	//#################################################################################################################################
	static DWORD* GraphicImageGetTexturePointer(DWORD* instance)
	{
		return Globals::CGraphicImageGetTexturePointer((void*)instance);
	}
	//#################################################################################################################################
	static DirectTexture GraphicTextureGetD3DTexture(DWORD* instance)
	{
		return Globals::CGraphicTextureGetD3DTexture((void*)instance);
	}
	//#################################################################################################################################
	static const TMobTable* NonPlayerGetTable(int vid)
	{
		return (const TMobTable*)Globals::CPythonNonPlayerGetTable((void*)Globals::iCPythonNonPlayerInstance, vid);
	}
	//#################################################################################################################################
	static void BackgroundLocalPositionToGlobalPosition(LONG& rLocalX, LONG& rLocalY)
	{
		return Globals::CPythonBackgroundLocalPositionToGlobalPosition((void*)Globals::iCPythonBackgroundInstance, rLocalX, rLocalY);
	}
	//#################################################################################################################################
	static TMapInfo* BackgroundGlobalPositionToMapInfo(DWORD dwGlobalX, DWORD dwGlobalY)
	{
		return Globals::CBackgroundGlobalPositionToMapInfo((void*)Globals::iCPythonBackgroundInstance, dwGlobalX, dwGlobalY);
	}
	//#################################################################################################################################
	static const char* NetworkStreamGetAccountCharacterSlotDataz(UINT iSlot, UINT eType)
	{
		return Globals::CNetworkStreamGetAccountCharacterSlotDataz((void*)Globals::iCPythonNetworkStreamInstance, iSlot, eType);
	}

	//#################################################################################################################################
	static const bool InstanceIsWaiting(DWORD* instance)
	{
		return Globals::CInstanceBaseIsWaiting((void*)instance);
	}
	//#################################################################################################################################
	static const void InstanceSetRotation(DWORD* instance, float fRotation)
	{
		Globals::CInstanceBaseSetRotation((void*)instance, fRotation);
	}
};

