
#pragma once


class Globals
{
public:
	//######################################################################################################################################
	static map<DWORD, TCItemData*> itemProtoList;
	static DWORD hEntryBaseAddress;
	static HMODULE hModule;
	static HWND mainHwnd;
	
	static vector<D3DVECTOR> Coords;
	//###############################   PLAYER
	
	typedef DWORD(__thiscall* tCPythonPlayerGetRace)(void* This);
	typedef bool(__thiscall* tCPythonPlayerIsSkillCoolTime)(void* This, DWORD dwSlotIndex);
	typedef int(__thiscall* tCPythonPlayerGetStatus)(void* This, DWORD dwType);

	typedef void(__thiscall* tCPythonPlayerClickSkillSlot)(void* This, DWORD dwSlotIndex);
#ifdef BARIA
	typedef DWORD(__thiscall* tCPythonPlayerGetItemIndex)(void* This, TItemPos Cell, char unk);
#else
	typedef DWORD(__thiscall* tCPythonPlayerGetItemIndex)(void* This, TItemPos Cell);
#endif
	typedef DWORD(__thiscall* tCPythonPlayerGetItemMetinSocket)(void* This, TItemPos Cell, DWORD dwMetinSocketIndex);

	typedef void(__thiscall* tCPythonPlayerReviveGlobal)(void* This, int a2, int a3, char* a4);


	typedef void(__thiscall* tCPythonPlayerSetAttackKeyState)(void* This, bool isPress);
	typedef DWORD*(__thiscall* tCPythonPlayerNEW_GetMainActorPtr)(void* This);
	typedef DWORD(__thiscall* tCPythonPlayerGetMainCharacterIndex)(void* This);
	typedef bool(__thiscall* tCPythonPlayerIsSkillActive)(void* This, DWORD dwSlotIndex);
	typedef void(__thiscall* tCPythonPlayerNEW_Fishing)(void* This);
	typedef DWORD(__thiscall* tCPythonPlayerGetTargetVID)(void* This);
	typedef void(__thiscall* tCPythonPlayer__OnClickActor)(void* This, DWORD* rkInstMain, DWORD dwPickedActorID, bool isAuto);
	typedef void(__thiscall* tCPythonPlayer__OnPressActor)(void* This, DWORD* rkInstMain, DWORD dwPickedActorID, bool isAuto);
	typedef void(__thiscall* tCPythonPlayerNEW_SetSingleDIKKeyState)(void* This, int eDIKKey, bool isPress);
	typedef void(__thiscall* tCPythonPlayerSetTarget)(void* This, DWORD dwVID, BOOL bForceChange);
	
	//############################### NETWORK
	
	typedef DWORD(__thiscall* tCPythonNetworkStreamGetMainActorSkillGroup)(void* This);
	typedef bool(__thiscall* tCNetworkStreamSendSequence)(void* This);
	/*typedef bool(__thiscall* tCNetworkStreamPeek)(void* This, int len, void* pDestBuf);*/
	typedef bool(__thiscall* tCNetworkStreamRecv)(void* This, int len, void* pDestBuf);
	typedef bool(__thiscall* tCNetworkStreamSend)(void* This, int len, void* pDestBuf);
	typedef bool(__thiscall* tCNetworkStreamCheckPacket)(void* This, BYTE* header);

	typedef bool(__thiscall* tCNetworkStreamIsOnline)(void* This);
	
#if defined(EGORIA) || defined(SENTHIA)
	typedef void(__thiscall* tCPythonNetworkStreamConnectGameServer)(void* This, UINT iChrSlot, int a3);
#else
	typedef void(__thiscall* tCPythonNetworkStreamConnectGameServer)(void* This, UINT iChrSlot);
#endif
	
#ifdef BARIA
	typedef bool(__thiscall* tCPythonNetworkStreamSendItemUsePacket)(void* This, TItemPos pos, char unk);
#else
	typedef bool(__thiscall* tCPythonNetworkStreamSendItemUsePacket)(void* This, TItemPos pos);
#endif

	typedef bool(__thiscall* tCNetworkStreamConnect)(void* This, DWORD dwAddr, int port, int limitSec);
	typedef void(__thiscall* tCNetworkStream__DirectEnterMode_Set)(void* This, UINT uChrSlotIndex);
	typedef bool(__thiscall* tCPythonNetworkStreamSendItemDropPacketNew)(void* This, TItemPos pos, DWORD elk, DWORD count);
	typedef bool(__thiscall* tCPythonNetworkStreamSendChatPacket)(void* This, const char* c_szChat, BYTE byType);
	typedef bool(__thiscall* tCPythonNetworkStreamSendFishingPacket)(void* This, int iRotation);
	typedef bool(__thiscall* tCPythonNetworkStreamSendFishingGlobalPacket)(void* This, int count, float iRotation);
	typedef bool(__thiscall* tCPythonNetworkStreamSendEmoticon)(void* This, BYTE emoticon);
	typedef bool(__thiscall* tCPythonNetworkStreamSendExchangeStartPacket)(void* This, DWORD vid);
	typedef bool(__thiscall* tCPythonNetworkStreamSendExchangeItemAddPacket)(void* This, TItemPos ItemPos, BYTE byDisplayPos);
	typedef bool(__thiscall* tCPythonNetworkStreamSendExchangeAcceptPacket)(void* This);
	typedef bool(__thiscall* tCPythonNetworkStreamSendUseSkillPacket)(void* This, DWORD dwSkillIndex, DWORD dwTargetVID);
	typedef bool(__thiscall* tCPythonNetworkStreamSendAddFlyTargetingPacket)(void* This, DWORD dwTargetVID, D3DVECTOR& kPPosTarget);
	typedef bool(__thiscall* tCPythonNetworkStreamSendShootPacket)(void* This, UINT uSkill);
	typedef bool(__thiscall* tCPythonNetworkStreamSendItemPickUpPacket)(void* This, DWORD vid);
	typedef bool(__thiscall* tCPythonNetworkStreamSendScriptAnswerPacket)(void* This, int iAnswer);
	typedef bool(__thiscall* tCPythonNetworkStreamSendOnClickPacket)(void* This, DWORD vid);
	typedef bool(__thiscall* tCPythonNetworkStreamSendWhisperPacket)(void* This, const char* name, const char* c_szChat);
	typedef bool(__thiscall* tCPythonNetworkStreamSendSpecial)(void* This, int nLen, void* pvBuf);
	typedef bool(__thiscall* tCPythonNetworkStreamSendAttackPacket)(void* This, UINT uMotAttack, DWORD dwVIDVictim);
#ifdef METINPL
	typedef bool(__thiscall* tCPythonNetworkStreamSendShopSellPacketNew)(void* This, BYTE bySlot, BYTE byCount, BYTE unk);
#else
	typedef bool(__thiscall* tCPythonNetworkStreamSendShopSellPacketNew)(void* This, BYTE bySlot, BYTE byCount);
#endif
	typedef bool(__thiscall* tCPythonNetworkStreamSendShopBuyPacket)(void* This, BYTE bPos);
	typedef bool(__thiscall* tCPythonNetworkStreamSendShopEndPacket)(void* This);
	

#ifdef RUBINUM	
	typedef bool(__thiscall* tCPythonNetworkStreamSendRefinePacket)(void* This, BYTE byPos, BYTE byType, BYTE unk);
#else
	typedef bool(__thiscall* tCPythonNetworkStreamSendRefinePacket)(void* This, BYTE byPos, BYTE byType);
#endif
	typedef bool(__thiscall* tCPythonNetworkStreamSendItemMovePacket)(void* This, TItemPos pos, TItemPos change_pos, BYTE num);
	
	
	
#ifdef RUBINUM
	typedef bool(__thiscall* tCPythonNetworkStreamSendCharacterStatePacket)(void* This, const D3DVECTOR& c_rkPPosDst, float fDstRot, UINT eFunc, UINT uArg, BYTE unk);
#else
	typedef bool(__thiscall* tCPythonNetworkStreamSendCharacterStatePacket)(void* This, const D3DVECTOR& c_rkPPosDst, float fDstRot, UINT eFunc, UINT uArg);
#endif
	
	typedef void(__thiscall* tCPythonNetworkStreamServerCommand)(void* This, const char * c_szCommand);
	
#ifdef METINPL
	typedef bool(__thiscall* tCPythonNetworkStreamSendGiveItemPacket)(void* This, DWORD dwTargetVID, TItemPos ItemPos, int iItemCount);
#else
	typedef bool(__thiscall* tCPythonNetworkStreamSendGiveItemPacket)(void* This, DWORD dwTargetVID, TItemPos ItemPos, int iItemCount);
#endif
	//############################### INSTANCE
	typedef bool(__thiscall* tCInstanceBaseIsMountingHorse)(void* This);
	typedef void(__thiscall* tCInstanceBaseNEW_GetPixelPosition)(DWORD* instance, D3DVECTOR * pPixelPosition);
	typedef bool(__thiscall* tCInstanceBaseNEW_MoveToDestPixelPositionDirection)(DWORD* instance, D3DVECTOR & c_rkPPosDst);
	typedef void(__thiscall* tCInstanceBaseSetDirection)(void* This, int dir);
	
#ifdef SAMIAS2
	typedef void(__thiscall* tCInstanceBaseNEW_SetPixelPosition)(void* This, float v1, float v2, float v3);
#else
	typedef void(__thiscall* tCInstanceBaseNEW_SetPixelPosition)(void* This, const D3DVECTOR & c_rPixelPosition);
#endif
	typedef const char *(__thiscall* tCInstanceBaseGetNameString)(void* This);
	typedef int(__thiscall* tCInstanceBaseGetInstanceType)(void* This);


	typedef void(__thiscall* tCInstanceBaseBlockMovement)(void* This);

	typedef void(__thiscall* tCInstanceBase__SetAffect)(void* This, UINT eAffect, bool isVisible);
	typedef bool(__thiscall* tCInstanceBaseIsDead)(void* This);
	typedef bool(__thiscall* tCInstanceBaseAvoidObject)(void* This, const DWORD* c_rkBGObj);
	typedef bool(__thiscall* tCActorInstanceTestActorCollision)(void* This, DWORD* rVictim);
	typedef void(__thiscall* tCInstanceBaseSCRIPT_SetPixelPosition)(void* This, float fx, float fy);
	typedef void(__thiscall* tCInstanceBaseNEW_LookAtDestPixelPosition)(void* This, const D3DVECTOR& c_rkPPosDst);
	typedef int(__thiscall* tCInstanceBaseGetInstanceVirtualNumber)(void* This);

#ifdef RUBINUM
	typedef DWORD(__thiscall* tCInstanceBaseGetRotation)(void* This)
#else
	typedef float(__thiscall* tCInstanceBaseGetRotation)(void* This)
#endif


	;
	//############################### CHARACTER MANAGER
	typedef DWORD* (__thiscall* tCPythonCharacterManagerGetInstancePtr)(void* This, DWORD VirtualID);

	//############################### CHARACTER MANAGER

	typedef DWORD*(__thiscall* tCResourceManagerGetResourcePointer)(void* This, const char * c_szFileName);

	typedef void(__thiscall* tCPhysicsObjectIncreaseExternalForce)(void* This, const D3DVECTOR & c_rvBasePosition, float fForce);

	typedef const char *(__thiscall* tCItemDataGetName)(void* This);

	typedef bool(__thiscall* tCItemManagerGetItemDataPointer)(void* This, DWORD dwItemID, DWORD ** ppItemData);

	typedef bool(__cdecl* tPyCallClassMemberFunc)(PyObject* poClass, const char* c_szFunc, PyObject* poArgs);

	typedef void(__thiscall* tCPythonChatAppendChat)(void* This, int iType, const char * c_szChat);

	typedef void(__thiscall* tCPythonApplicationRenderGame)(void* This);
	typedef bool(__thiscall* tCPythonApplicationProcess)(void* This);
	
	typedef int(__thiscall* tCPythonEventManagerRegisterEventSetFromString)(void* This, const string& strScript);

	
	
	typedef DWORD*(__thiscall* tCResourceManagerGetResourcePointer)(void* This, const char* c_szFileName);
	typedef DWORD* (__thiscall* tCResourceManagerGetTexturePointer)(void* This);
	typedef DirectTexture(__thiscall* tCResourceManagerGetD3DTexture)(void* This);
	typedef void(__thiscall* tCTerrainLoadMiniMapTexture)(void* This, const char* c_pchMiniMapFileName);
	typedef DWORD*(__thiscall* tCPythonNonPlayerGetTable)(void* This, int vid);
	

	typedef const char*(__thiscall* tCPythonBackgroundGetWarpMapName)(void* This);
	typedef void(__thiscall* tCPythonBackgroundLocalPositionToGlobalPosition)(void* This, LONG& rLocalX, LONG& rLocalY);
	typedef TMapInfo* (__thiscall* tCPythonBackgroundGlobalPositionToMapInfo)(void* This, DWORD dwGlobalX, DWORD dwGlobalY);
	typedef const char* (__thiscall* tCNetworkStreamGetAccountCharacterSlotDataz)(void* This, UINT iSlot, UINT eType);
	typedef void(__thiscall* tCPythonApplicationOnUIRender)(void* This);
	typedef void(__thiscall* tCInputKeyboardUpdateKeyboard)(void* This);
	
	static DWORD iCEterPackManagerInstance;
	static DWORD iCPythonApplicationInstance;
	static DWORD iCPythonBackgroundInstance;
	static DWORD iCPythonCharacterManagerInstance;
	static DWORD iCPythonItemInstance;
	static DWORD iCPythonNetworkStreamInstance;
	static DWORD iCPythonNonPlayerInstance;
	static DWORD iCPythonPlayerInstance;
	static DWORD iCResourceManagerInstance;
	static DWORD iCItemManagerInstance;


	static DWORD pCPythonCharacterManagerInstance;
	static DWORD pCPythonBackgroundInstance;
	static DWORD pCPythonItemInstance;
	static DWORD pCPythonApplicationInstance;
	static DWORD pCPythonNetworkStreamInstance;
	static DWORD pCItemManagerInstance;
	static DWORD pCResourceManagerInstance;
	static DWORD pCPythonNonPlayerInstance;




	static DWORD pCActorInstanceTestActorCollision;
	

	static DWORD pCPythonBackgroundGetWarpMapName;
	static DWORD pCPythonBackgroundGlobalPositionToMapInfo;
	static DWORD pCPythonBackgroundLocalPositionToGlobalPosition;

	static DWORD pCInstanceBaseAvoidObject;
	static DWORD pCInstanceBaseBlockMovement;
	static DWORD pCInstanceBaseGetInstanceType;
	static DWORD pCInstanceBaseGetInstanceVirtualNumber;
	static DWORD pCInstanceBaseGetNameString;
	static DWORD pCInstanceBaseGetRotation;
	static DWORD pCInstanceBaseIsDead;
	static DWORD pCInstanceBaseIsMountingHorse;
	static DWORD pCInstanceBaseNEW_GetPixelPosition;
	static DWORD pCInstanceBaseNEW_LookAtDestPixelPosition;
	static DWORD pCInstanceBaseNEW_MoveToDestPixelPositionDirection;
	static DWORD pCInstanceBaseNEW_SetPixelPosition;
	static DWORD pCInstanceBaseSCRIPT_SetPixelPosition;
	static DWORD pCInstanceBaseSetDirection;
	static DWORD pCInstanceBase__SetAffect;
	static DWORD pCItemDataGetName;
	static DWORD pCItemManagerGetItemDataPointer;

	

	static DWORD pCNetworkStreamConnect;
	static DWORD pCNetworkStream__DirectEnterMode_Set;
	static DWORD pCNetworkStreamGetAccountCharacterSlotDataz;
	static DWORD pCNetworkStreamIsOnline;
	static DWORD pCNetworkStreamPeek;
	static DWORD pCNetworkStreamRecv;
	static DWORD pCNetworkStreamSend;
	static DWORD pCNetworkStreamSendSequence;

	static DWORD pCPhysicsObjectIncreaseExternalForce;



	static DWORD pCPythonApplicationProcess;
	static DWORD pCPythonApplicationRenderGame;


	static DWORD pCPythonCharacterManagerGetInstancePtr;
	static DWORD pCPythonChatAppendChat;
	static DWORD pCPythonEventManagerRegisterEventSetFromString;

	static DWORD pCPythonNetworkStreamConnectGameServer;
	static DWORD pCPythonNetworkStreamGetMainActorSkillGroup;

	static DWORD pCPythonNetworkStreamSendAddFlyTargetingPacket;
	static DWORD pCPythonNetworkStreamSendAttackPacket;
	static DWORD pCPythonNetworkStreamSendCharacterStatePacket;
	static DWORD pCPythonNetworkStreamSendChatPacket;
	static DWORD pCPythonNetworkStreamSendEmoticon;
	static DWORD pCPythonNetworkStreamSendExchangeAcceptPacket;
	static DWORD pCPythonNetworkStreamSendExchangeItemAddPacket;
	static DWORD pCPythonNetworkStreamSendExchangeStartPacket;
	static DWORD pCPythonNetworkStreamSendFishingGlobalPacket;
	static DWORD pCPythonNetworkStreamSendFishingPacket;
	static DWORD pCPythonNetworkStreamSendGiveItemPacket;
	static DWORD pCPythonNetworkStreamSendItemDropPacketNew;
	static DWORD pCPythonNetworkStreamSendItemMovePacket;
	static DWORD pCPythonNetworkStreamSendItemPickUpPacket;
	static DWORD pCPythonNetworkStreamSendItemUsePacket;
	static DWORD pCPythonNetworkStreamSendOnClickPacket;
	static DWORD pCPythonNetworkStreamSendRefinePacket;
	static DWORD pCPythonNetworkStreamSendScriptAnswerPacket;
	static DWORD pCPythonNetworkStreamSendShootPacket;
	static DWORD pCPythonNetworkStreamSendShopBuyPacket;
	static DWORD pCPythonNetworkStreamSendShopEndPacket;
	static DWORD pCPythonNetworkStreamSendShopSellPacketNew;
	static DWORD pCPythonNetworkStreamSendSpecial;
	static DWORD pCPythonNetworkStreamSendUseSkillPacket;
	static DWORD pCPythonNetworkStreamSendWhisperPacket;
	static DWORD pCPythonNetworkStreamServerCommand;
	static DWORD pCPythonNonPlayerGetTable;


	static DWORD pCPythonPlayerReviveGlobal;
	static DWORD pCPythonPlayerClickSkillSlot;
	static DWORD pCPythonPlayerGetItemIndex;
	static DWORD pCPythonPlayerGetItemMetinSocket;
	static DWORD pCPythonPlayerGetMainCharacterIndex;
	static DWORD pCPythonPlayerGetName;
	static DWORD pCPythonPlayerGetRace;
	static DWORD pCPythonPlayerGetStatus;
	static DWORD pCPythonPlayerGetTargetVID;
	static DWORD pCPythonPlayerInstance;
	static DWORD pCPythonPlayerIsSkillActive;
	static DWORD pCPythonPlayerIsSkillCoolTime;
	static DWORD pCPythonPlayerNEW_Fishing;
	static DWORD pCPythonPlayerNEW_GetMainActorPtr;
	static DWORD pCPythonPlayerNEW_SetSingleDIKKeyState;
	static DWORD pCPythonPlayerSetAttackKeyState;
	static DWORD pCPythonPlayerSetTarget;
	static DWORD pCPythonPlayer__OnClickActor;
	static DWORD pCPythonPlayer__OnPressActor;

	static DWORD pCGraphicTextureGetD3DTexture;
	static DWORD pCResourceManagerGetResourcePointer;
	static DWORD pCGraphicImageGetTexturePointer;

	

	static DWORD pPyCallClassMemberFunc;
	static DWORD pCPythonApplicationOnUIRender;
	static DWORD pCGraphicBasems_lpd3dDevice;
	static DWORD pCInputKeyboardUpdateKeyboard;

public:
	//#####################################################################################################################################
	/*static tCNetworkStreamPeek CNetworkStreamPeek;*/
	/*static tCPythonApplicationGetCenterPosition CPythonApplicationGetCenterPosition;*/
	//static tCScreenProjectPosition CScreenProjectPosition;
	static tCActorInstanceTestActorCollision CActorInstanceTestActorCollision;

	
	static tCPythonBackgroundGlobalPositionToMapInfo CBackgroundGlobalPositionToMapInfo;
	static tCInstanceBaseAvoidObject CInstanceBaseAvoidObject;
	static tCInstanceBaseBlockMovement CInstanceBaseBlockMovement;
	static tCInstanceBaseGetInstanceType CInstanceBaseGetInstanceType;
	static tCInstanceBaseGetInstanceVirtualNumber CInstanceBaseGetInstanceVirtualNumber;
	static tCInstanceBaseGetNameString CInstanceBaseGetNameString;
	static tCInstanceBaseGetRotation CInstanceBaseGetRotation;
	static tCInstanceBaseIsDead CInstanceBaseIsDead;
	static tCInstanceBaseIsMountingHorse CInstanceBaseIsMountingHorse;
	static tCInstanceBaseNEW_GetPixelPosition CInstanceBaseNEW_GetPixelPosition;
	static tCInstanceBaseNEW_LookAtDestPixelPosition CInstanceBaseNEW_LookAtDestPixelPosition;
	static tCInstanceBaseNEW_MoveToDestPixelPositionDirection CInstanceBaseNEW_MoveToDestPixelPositionDirection;
	static tCInstanceBaseNEW_SetPixelPosition CInstanceBaseNEW_SetPixelPosition;
	static tCInstanceBaseSCRIPT_SetPixelPosition CInstanceBaseSCRIPT_SetPixelPosition;
	static tCInstanceBaseSetDirection CInstanceBaseSetDirection;
	static tCInstanceBase__SetAffect CInstanceBase__SetAffect;
	static tCItemDataGetName CItemDataGetName;
	static tCItemManagerGetItemDataPointer CItemManagerGetItemDataPointer;
	static tCPythonBackgroundLocalPositionToGlobalPosition CPythonBackgroundLocalPositionToGlobalPosition;
	static tCNetworkStreamConnect CNetworkStreamConnect;
	static tCNetworkStream__DirectEnterMode_Set CNetworkStream__DirectEnterMode_Set;
	static tCNetworkStreamGetAccountCharacterSlotDataz CNetworkStreamGetAccountCharacterSlotDataz;
	static tCNetworkStreamIsOnline CNetworkStreamIsOnline;
	static tCNetworkStreamRecv CNetworkStreamRecv;
	static tCNetworkStreamSend CNetworkStreamSend;
	static tCNetworkStreamSendSequence CNetworkStreamSendSequence;
	static tCPhysicsObjectIncreaseExternalForce CPhysicsObjectIncreaseExternalForce;
	static tCPythonPlayerReviveGlobal CPythonPlayerReviveGlobal;
	static tCPythonApplicationProcess CPythonApplicationProcess;
	static tCPythonApplicationRenderGame CPythonApplicationRenderGame;
	static tCPythonBackgroundGetWarpMapName CPythonBackgroundGetWarpMapName;
	static tCPythonCharacterManagerGetInstancePtr CPythonCharacterManagerGetInstancePtr;
	static tCPythonChatAppendChat CPythonChatAppendChat;
	static tCPythonEventManagerRegisterEventSetFromString CPythonEventManagerRegisterEventSetFromString;
	static tCPythonNetworkStreamConnectGameServer CPythonNetworkStreamConnectGameServer;
	static tCPythonNetworkStreamGetMainActorSkillGroup CPythonNetworkStreamGetMainActorSkillGroup;
	static tCPythonNetworkStreamSendAddFlyTargetingPacket CPythonNetworkStreamSendAddFlyTargetingPacket;
	static tCPythonNetworkStreamSendAttackPacket CPythonNetworkStreamSendAttackPacket;
	static tCPythonNetworkStreamSendCharacterStatePacket CPythonNetworkStreamSendCharacterStatePacket;
	static tCPythonNetworkStreamSendChatPacket CPythonNetworkStreamSendChatPacket;
	static tCPythonNetworkStreamSendEmoticon CPythonNetworkStreamSendEmoticon;
	static tCPythonNetworkStreamSendExchangeAcceptPacket CPythonNetworkStreamSendExchangeAcceptPacket;
	static tCPythonNetworkStreamSendExchangeItemAddPacket CPythonNetworkStreamSendExchangeItemAddPacket;
	static tCPythonNetworkStreamSendExchangeStartPacket CPythonNetworkStreamSendExchangeStartPacket;
	static tCPythonNetworkStreamSendFishingGlobalPacket CPythonNetworkStreamSendFishingGlobalPacket;
	static tCPythonNetworkStreamSendFishingPacket CPythonNetworkStreamSendFishingPacket;
	static tCPythonNetworkStreamSendGiveItemPacket CPythonNetworkStreamSendGiveItemPacket;
	static tCPythonNetworkStreamSendItemDropPacketNew CPythonNetworkStreamSendItemDropPacketNew;
	static tCPythonNetworkStreamSendItemMovePacket CPythonNetworkStreamSendItemMovePacket;
	static tCPythonNetworkStreamSendItemPickUpPacket CPythonNetworkStreamSendItemPickUpPacket;
	static tCPythonNetworkStreamSendItemUsePacket CPythonNetworkStreamSendItemUsePacket;
	static tCPythonNetworkStreamSendOnClickPacket CPythonNetworkStreamSendOnClickPacket;
	static tCPythonNetworkStreamSendRefinePacket CPythonNetworkStreamSendRefinePacket;
	static tCPythonNetworkStreamSendScriptAnswerPacket CPythonNetworkStreamSendScriptAnswerPacket;
	static tCPythonNetworkStreamSendShootPacket CPythonNetworkStreamSendShootPacket;
	static tCPythonNetworkStreamSendShopBuyPacket CPythonNetworkStreamSendShopBuyPacket;
	static tCPythonNetworkStreamSendShopEndPacket CPythonNetworkStreamSendShopEndPacket;
	static tCPythonNetworkStreamSendShopSellPacketNew CPythonNetworkStreamSendShopSellPacketNew;
	static tCPythonNetworkStreamSendSpecial CPythonNetworkStreamSendSpecial;
	static tCPythonNetworkStreamSendUseSkillPacket CPythonNetworkStreamSendUseSkillPacket;
	static tCPythonNetworkStreamSendWhisperPacket CPythonNetworkStreamSendWhisperPacket;
	static tCPythonNetworkStreamServerCommand CPythonNetworkStreamServerCommand;
	static tCPythonNonPlayerGetTable CPythonNonPlayerGetTable;
	static tCPythonPlayerClickSkillSlot CPythonPlayerClickSkillSlot;
	static tCPythonPlayerGetItemIndex CPythonPlayerGetItemIndex;
	static tCPythonPlayerGetItemMetinSocket CPythonPlayerGetItemMetinSocket;
	static tCPythonPlayerGetMainCharacterIndex CPythonPlayerGetMainCharacterIndex;
	static tCPythonPlayerGetRace CPythonPlayerGetRace;
	static tCPythonPlayerGetStatus CPythonPlayerGetStatus;
	static tCPythonPlayerGetTargetVID CPythonPlayerGetTargetVID;
	static tCPythonPlayerIsSkillActive CPythonPlayerIsSkillActive;
	static tCPythonPlayerIsSkillCoolTime CPythonPlayerIsSkillCoolTime;
	static tCPythonPlayerNEW_Fishing CPythonPlayerNEW_Fishing;
	static tCPythonPlayerNEW_GetMainActorPtr CPythonPlayerNEW_GetMainActorPtr;
	static tCPythonPlayerNEW_SetSingleDIKKeyState CPythonPlayerNEW_SetSingleDIKKeyState;
	static tCPythonPlayerSetAttackKeyState CPythonPlayerSetAttackKeyState;
	static tCPythonPlayerSetTarget CPythonPlayerSetTarget;
	static tCPythonPlayer__OnClickActor CPythonPlayer__OnClickActor;
	static tCPythonPlayer__OnPressActor CPythonPlayer__OnPressActor;
	static tCResourceManagerGetD3DTexture CGraphicTextureGetD3DTexture;
	static tCResourceManagerGetResourcePointer CResourceManagerGetResourcePointer;
	static tCResourceManagerGetTexturePointer CGraphicImageGetTexturePointer;
	static tCTerrainLoadMiniMapTexture CTerrainLoadMiniMapTexture;
	static tPyCallClassMemberFunc PyCallClassMemberFunc;
	static tCPythonApplicationOnUIRender CPythonApplicationOnUIRender;
	static tCInputKeyboardUpdateKeyboard CInputKeyboardUpdateKeyboard;
	//#####################################################################################################################################
	
	static void ReAddressingLocas();
	static void ReDeclarationLocals();
};
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



map<DWORD, TCItemData*> Globals::itemProtoList;

HMODULE	Globals::hModule = NULL;
DWORD	Globals::hEntryBaseAddress = (DWORD)GetModuleHandle(NULL);

HWND Globals::mainHwnd;




vector<D3DVECTOR> Globals::Coords;
///###################################################################################################################################################
DWORD Globals::iCItemManagerInstance = NULL;
DWORD Globals::iCPythonItemInstance = NULL;
DWORD Globals::iCPythonApplicationInstance = NULL;
DWORD Globals::iCPythonCharacterManagerInstance = NULL;
DWORD Globals::iCPythonNetworkStreamInstance = NULL;
DWORD Globals::iCPythonPlayerInstance = NULL;
DWORD Globals::iCPythonNonPlayerInstance = NULL;
DWORD Globals::iCPythonBackgroundInstance = NULL;
DWORD Globals::iCResourceManagerInstance = NULL;






//#####################################################################################################################################

DWORD Globals::pCPythonNetworkStreamInstance = NULL;

DWORD Globals::pCActorInstanceTestActorCollision = NULL;

DWORD Globals::pCPythonBackgroundInstance = NULL;
DWORD Globals::pCItemManagerInstance = NULL;
DWORD Globals::pCPythonItemInstance = NULL;

DWORD Globals::pCPythonBackgroundGetWarpMapName = NULL;
DWORD Globals::pCPythonBackgroundGlobalPositionToMapInfo = NULL;
DWORD Globals::pCInstanceBaseAvoidObject = NULL;
DWORD Globals::pCInstanceBaseBlockMovement = NULL;
DWORD Globals::pCInstanceBaseGetInstanceType = NULL;
DWORD Globals::pCInstanceBaseGetInstanceVirtualNumber = NULL;
DWORD Globals::pCInstanceBaseGetNameString = NULL;
DWORD Globals::pCInstanceBaseGetRotation = NULL;
DWORD Globals::pCInstanceBaseIsDead = NULL;
DWORD Globals::pCInstanceBaseIsMountingHorse = NULL;

DWORD Globals::pCInstanceBaseNEW_GetPixelPosition = NULL;
DWORD Globals::pCInstanceBaseNEW_LookAtDestPixelPosition = NULL;;
DWORD Globals::pCInstanceBaseNEW_MoveToDestPixelPositionDirection = NULL;
DWORD Globals::pCInstanceBaseNEW_SetPixelPosition = NULL;
DWORD Globals::pCInstanceBaseSCRIPT_SetPixelPosition = NULL;;
DWORD Globals::pCInstanceBaseSetDirection = NULL;
DWORD Globals::pCInstanceBase__SetAffect = NULL;
DWORD Globals::pCItemDataGetName = NULL;
DWORD Globals::pCItemManagerGetItemDataPointer = NULL;

DWORD Globals::pCPythonBackgroundLocalPositionToGlobalPosition = NULL;
DWORD Globals::pCNetworkStreamConnect = NULL;
DWORD Globals::pCNetworkStream__DirectEnterMode_Set = NULL;
DWORD Globals::pCNetworkStreamGetAccountCharacterSlotDataz = NULL;
DWORD Globals::pCNetworkStreamIsOnline = NULL;
DWORD Globals::pCNetworkStreamPeek = NULL;
DWORD Globals::pCNetworkStreamRecv = NULL;
DWORD Globals::pCNetworkStreamSend = NULL;
DWORD Globals::pCNetworkStreamSendSequence = NULL;
DWORD Globals::pCPhysicsObjectIncreaseExternalForce = NULL;
DWORD Globals::pCPythonPlayerReviveGlobal = NULL;
DWORD Globals::pCPythonApplicationInstance = NULL;
DWORD Globals::pCPythonApplicationProcess = NULL;
DWORD Globals::pCPythonApplicationRenderGame = NULL;

DWORD Globals::pCPythonCharacterManagerGetInstancePtr = NULL;
DWORD Globals::pCPythonCharacterManagerInstance = NULL;
DWORD Globals::pCPythonChatAppendChat = NULL;
DWORD Globals::pCPythonEventManagerRegisterEventSetFromString = NULL;;

DWORD Globals::pCPythonNetworkStreamConnectGameServer = NULL;
DWORD Globals::pCPythonNetworkStreamGetMainActorSkillGroup = NULL;

DWORD Globals::pCPythonNetworkStreamSendAddFlyTargetingPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendAttackPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendCharacterStatePacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendChatPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendEmoticon = NULL;
DWORD Globals::pCPythonNetworkStreamSendExchangeAcceptPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendExchangeItemAddPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendExchangeStartPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendFishingGlobalPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendFishingPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendGiveItemPacket = NULL;;
DWORD Globals::pCPythonNetworkStreamSendItemDropPacketNew = NULL;
DWORD Globals::pCPythonNetworkStreamSendItemMovePacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendItemPickUpPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendItemUsePacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendOnClickPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendRefinePacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendScriptAnswerPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendShootPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendShopBuyPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendShopEndPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendShopSellPacketNew = NULL;
DWORD Globals::pCPythonNetworkStreamSendSpecial = NULL;;
DWORD Globals::pCPythonNetworkStreamSendUseSkillPacket = NULL;
DWORD Globals::pCPythonNetworkStreamSendWhisperPacket = NULL;;
DWORD Globals::pCPythonNetworkStreamServerCommand = NULL;
DWORD Globals::pCPythonNonPlayerGetTable = NULL;
DWORD Globals::pCPythonNonPlayerInstance = NULL;
DWORD Globals::pCPythonPlayerClickSkillSlot = NULL;
DWORD Globals::pCPythonPlayerGetItemIndex = NULL;
DWORD Globals::pCPythonPlayerGetItemMetinSocket = NULL;
DWORD Globals::pCPythonPlayerGetMainCharacterIndex = NULL;
DWORD Globals::pCPythonPlayerGetName = NULL;
DWORD Globals::pCPythonPlayerGetRace = NULL;
DWORD Globals::pCPythonPlayerGetStatus = NULL;
DWORD Globals::pCPythonPlayerGetTargetVID = NULL;
DWORD Globals::pCPythonPlayerInstance = NULL;
DWORD Globals::pCPythonPlayerIsSkillActive = NULL;
DWORD Globals::pCPythonPlayerIsSkillCoolTime = NULL;
DWORD Globals::pCPythonPlayerNEW_Fishing = NULL;
DWORD Globals::pCPythonPlayerNEW_GetMainActorPtr = NULL;
DWORD Globals::pCPythonPlayerNEW_SetSingleDIKKeyState = NULL;;
DWORD Globals::pCPythonPlayerSetAttackKeyState = NULL;
DWORD Globals::pCPythonPlayerSetTarget = NULL;
DWORD Globals::pCPythonPlayer__OnClickActor = NULL;
DWORD Globals::pCPythonPlayer__OnPressActor = NULL;
DWORD Globals::pCResourceManagerInstance = NULL;
DWORD Globals::pCGraphicTextureGetD3DTexture = NULL;
DWORD Globals::pCResourceManagerGetResourcePointer = NULL;
DWORD Globals::pCGraphicImageGetTexturePointer = NULL;


DWORD Globals::pPyCallClassMemberFunc = NULL;
DWORD Globals::pCPythonApplicationOnUIRender = NULL;
DWORD Globals::pCGraphicBasems_lpd3dDevice = NULL;
DWORD Globals::pCInputKeyboardUpdateKeyboard = NULL;
//Globals::tCNetworkStreamPeek Globals::CNetworkStreamPeek = NULL;

Globals::tCActorInstanceTestActorCollision Globals::CActorInstanceTestActorCollision = NULL;


Globals::tCPythonBackgroundGlobalPositionToMapInfo Globals::CBackgroundGlobalPositionToMapInfo = NULL;
Globals::tCInstanceBaseAvoidObject Globals::CInstanceBaseAvoidObject = NULL;
Globals::tCInstanceBaseBlockMovement Globals::CInstanceBaseBlockMovement = NULL;;
Globals::tCInstanceBaseGetInstanceType Globals::CInstanceBaseGetInstanceType = NULL;
Globals::tCInstanceBaseGetInstanceVirtualNumber Globals::CInstanceBaseGetInstanceVirtualNumber = NULL;
Globals::tCInstanceBaseGetNameString Globals::CInstanceBaseGetNameString = NULL;
Globals::tCInstanceBaseGetRotation Globals::CInstanceBaseGetRotation = NULL;
Globals::tCInstanceBaseIsDead Globals::CInstanceBaseIsDead = NULL;
Globals::tCInstanceBaseIsMountingHorse Globals::CInstanceBaseIsMountingHorse = NULL;
Globals::tCInstanceBaseNEW_GetPixelPosition Globals::CInstanceBaseNEW_GetPixelPosition = NULL;
Globals::tCInstanceBaseNEW_LookAtDestPixelPosition Globals::CInstanceBaseNEW_LookAtDestPixelPosition = NULL;
Globals::tCInstanceBaseNEW_MoveToDestPixelPositionDirection Globals::CInstanceBaseNEW_MoveToDestPixelPositionDirection = NULL;
Globals::tCInstanceBaseNEW_SetPixelPosition Globals::CInstanceBaseNEW_SetPixelPosition = NULL;
Globals::tCInstanceBaseSCRIPT_SetPixelPosition Globals::CInstanceBaseSCRIPT_SetPixelPosition = NULL;
Globals::tCInstanceBaseSetDirection Globals::CInstanceBaseSetDirection = NULL;
Globals::tCInstanceBase__SetAffect Globals::CInstanceBase__SetAffect = NULL;
Globals::tCItemDataGetName Globals::CItemDataGetName = NULL;
Globals::tCItemManagerGetItemDataPointer Globals::CItemManagerGetItemDataPointer = NULL;
Globals::tCPythonBackgroundLocalPositionToGlobalPosition Globals::CPythonBackgroundLocalPositionToGlobalPosition = NULL;
Globals::tCNetworkStreamConnect Globals::CNetworkStreamConnect = NULL;
Globals::tCNetworkStream__DirectEnterMode_Set Globals::CNetworkStream__DirectEnterMode_Set = NULL;
Globals::tCNetworkStreamGetAccountCharacterSlotDataz Globals::CNetworkStreamGetAccountCharacterSlotDataz = NULL;
Globals::tCNetworkStreamIsOnline Globals::CNetworkStreamIsOnline = NULL;
Globals::tCNetworkStreamRecv Globals::CNetworkStreamRecv = NULL;
Globals::tCNetworkStreamSend Globals::CNetworkStreamSend = NULL;
Globals::tCNetworkStreamSendSequence Globals::CNetworkStreamSendSequence = NULL;
Globals::tCPhysicsObjectIncreaseExternalForce Globals::CPhysicsObjectIncreaseExternalForce = NULL;
Globals::tCPythonPlayerReviveGlobal Globals::CPythonPlayerReviveGlobal = NULL;
Globals::tCPythonApplicationProcess Globals::CPythonApplicationProcess = NULL;
Globals::tCPythonApplicationRenderGame Globals::CPythonApplicationRenderGame = NULL;
Globals::tCPythonBackgroundGetWarpMapName Globals::CPythonBackgroundGetWarpMapName = NULL;
Globals::tCPythonCharacterManagerGetInstancePtr Globals::CPythonCharacterManagerGetInstancePtr = NULL;
Globals::tCPythonChatAppendChat Globals::CPythonChatAppendChat = NULL;
Globals::tCPythonEventManagerRegisterEventSetFromString Globals::CPythonEventManagerRegisterEventSetFromString = NULL;
Globals::tCPythonNetworkStreamConnectGameServer Globals::CPythonNetworkStreamConnectGameServer = NULL;
Globals::tCPythonNetworkStreamGetMainActorSkillGroup Globals::CPythonNetworkStreamGetMainActorSkillGroup = NULL;
Globals::tCPythonNetworkStreamSendAddFlyTargetingPacket Globals::CPythonNetworkStreamSendAddFlyTargetingPacket = NULL;
Globals::tCPythonNetworkStreamSendAttackPacket Globals::CPythonNetworkStreamSendAttackPacket = NULL;
Globals::tCPythonNetworkStreamSendCharacterStatePacket Globals::CPythonNetworkStreamSendCharacterStatePacket = NULL;;
Globals::tCPythonNetworkStreamSendChatPacket Globals::CPythonNetworkStreamSendChatPacket = NULL;
Globals::tCPythonNetworkStreamSendEmoticon Globals::CPythonNetworkStreamSendEmoticon = NULL;
Globals::tCPythonNetworkStreamSendExchangeAcceptPacket Globals::CPythonNetworkStreamSendExchangeAcceptPacket = NULL;
Globals::tCPythonNetworkStreamSendExchangeItemAddPacket Globals::CPythonNetworkStreamSendExchangeItemAddPacket = NULL;
Globals::tCPythonNetworkStreamSendExchangeStartPacket Globals::CPythonNetworkStreamSendExchangeStartPacket = NULL;
Globals::tCPythonNetworkStreamSendFishingGlobalPacket Globals::CPythonNetworkStreamSendFishingGlobalPacket = NULL;
Globals::tCPythonNetworkStreamSendFishingPacket Globals::CPythonNetworkStreamSendFishingPacket = NULL;
Globals::tCPythonNetworkStreamSendGiveItemPacket Globals::CPythonNetworkStreamSendGiveItemPacket = NULL;
Globals::tCPythonNetworkStreamSendItemDropPacketNew Globals::CPythonNetworkStreamSendItemDropPacketNew = NULL;
Globals::tCPythonNetworkStreamSendItemMovePacket Globals::CPythonNetworkStreamSendItemMovePacket = NULL;
Globals::tCPythonNetworkStreamSendItemPickUpPacket Globals::CPythonNetworkStreamSendItemPickUpPacket = NULL;
Globals::tCPythonNetworkStreamSendItemUsePacket Globals::CPythonNetworkStreamSendItemUsePacket = NULL;
Globals::tCPythonNetworkStreamSendOnClickPacket Globals::CPythonNetworkStreamSendOnClickPacket = NULL;
Globals::tCPythonNetworkStreamSendRefinePacket Globals::CPythonNetworkStreamSendRefinePacket = NULL;
Globals::tCPythonNetworkStreamSendScriptAnswerPacket Globals::CPythonNetworkStreamSendScriptAnswerPacket = NULL;
Globals::tCPythonNetworkStreamSendShootPacket Globals::CPythonNetworkStreamSendShootPacket = NULL;
Globals::tCPythonNetworkStreamSendShopBuyPacket Globals::CPythonNetworkStreamSendShopBuyPacket = NULL;
Globals::tCPythonNetworkStreamSendShopEndPacket Globals::CPythonNetworkStreamSendShopEndPacket = NULL;
Globals::tCPythonNetworkStreamSendShopSellPacketNew Globals::CPythonNetworkStreamSendShopSellPacketNew = NULL;
Globals::tCPythonNetworkStreamSendSpecial Globals::CPythonNetworkStreamSendSpecial = NULL;
Globals::tCPythonNetworkStreamSendUseSkillPacket Globals::CPythonNetworkStreamSendUseSkillPacket = NULL;
Globals::tCPythonNetworkStreamSendWhisperPacket Globals::CPythonNetworkStreamSendWhisperPacket = NULL;
Globals::tCPythonNetworkStreamServerCommand Globals::CPythonNetworkStreamServerCommand = NULL;
Globals::tCPythonNonPlayerGetTable Globals::CPythonNonPlayerGetTable = NULL;
Globals::tCPythonPlayerClickSkillSlot Globals::CPythonPlayerClickSkillSlot = NULL;
Globals::tCPythonPlayerGetItemIndex Globals::CPythonPlayerGetItemIndex = NULL;
Globals::tCPythonPlayerGetItemMetinSocket Globals::CPythonPlayerGetItemMetinSocket = NULL;
Globals::tCPythonPlayerGetMainCharacterIndex Globals::CPythonPlayerGetMainCharacterIndex = NULL;
Globals::tCPythonPlayerGetRace Globals::CPythonPlayerGetRace = NULL;
Globals::tCPythonPlayerGetStatus Globals::CPythonPlayerGetStatus = NULL;
Globals::tCPythonPlayerGetTargetVID Globals::CPythonPlayerGetTargetVID = NULL;
Globals::tCPythonPlayerIsSkillActive Globals::CPythonPlayerIsSkillActive = NULL;
Globals::tCPythonPlayerIsSkillCoolTime Globals::CPythonPlayerIsSkillCoolTime = NULL;
Globals::tCPythonPlayerNEW_Fishing Globals::CPythonPlayerNEW_Fishing = NULL;
Globals::tCPythonPlayerNEW_GetMainActorPtr Globals::CPythonPlayerNEW_GetMainActorPtr = NULL;
Globals::tCPythonPlayerNEW_SetSingleDIKKeyState Globals::CPythonPlayerNEW_SetSingleDIKKeyState = NULL;
Globals::tCPythonPlayerSetAttackKeyState Globals::CPythonPlayerSetAttackKeyState = NULL;
Globals::tCPythonPlayerSetTarget Globals::CPythonPlayerSetTarget = NULL;
Globals::tCPythonPlayer__OnClickActor Globals::CPythonPlayer__OnClickActor = NULL;
Globals::tCPythonPlayer__OnPressActor Globals::CPythonPlayer__OnPressActor = NULL;
Globals::tCResourceManagerGetD3DTexture Globals::CGraphicTextureGetD3DTexture = NULL;
Globals::tCResourceManagerGetResourcePointer Globals::CResourceManagerGetResourcePointer = NULL;
Globals::tCResourceManagerGetTexturePointer Globals::CGraphicImageGetTexturePointer = NULL;
Globals::tCTerrainLoadMiniMapTexture Globals::CTerrainLoadMiniMapTexture = NULL;
Globals::tPyCallClassMemberFunc  Globals::PyCallClassMemberFunc = NULL;
Globals::tCPythonApplicationOnUIRender Globals::CPythonApplicationOnUIRender = NULL;
Globals::tCInputKeyboardUpdateKeyboard Globals::CInputKeyboardUpdateKeyboard = NULL;
//####Globals::#################################################################################################################################




void Globals::ReAddressingLocas()
{

#ifdef  VIDGAR

	//pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x2D38B6C;
	//pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x2d34344; // [100 ] [104 / 104]
	//pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x2d2af9c; // [100 ] [67 / 67]
	//pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x2d2af8c; // [100 ] [41 / 41]
	//pCItemManagerInstance = Globals::hEntryBaseAddress + 0x2d2afa4; // [100 ] [50 / 50]
	//pCPythonItemInstance = Globals::hEntryBaseAddress + 0x2d3436c; // [100 ] [7 / 7]
	//pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x2D36604;//0x1bf780; // [100 ] [58 / 58]
	//pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x2d2af90; // [100 ] [7 / 7]
	//pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x2d2af98; // [100 ] [130 / 130]
	//pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x2d34328; // [100 ] [4 / 4]
	//pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x300e50; // [100 ] [1 / 1]
	//pCPythonBackgroundGetWarpMapName = Globals::hEntryBaseAddress + 0x1904b0; // [100 ] [1 / 1]
	//pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x190420; // [100 ] [1 / 1]
	//pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x300a50; // [100 ] [1 / 1]
	//pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x16bc60; // [100 ] [1 / 1]
	//pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x16a9b0; // [100 ] [1 / 1]
	//pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x16aa60; // [100 ] [1 / 1]
	//pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x16a970; // [100 ] [2 / 2]
	//pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x18aa00; // [100 ] [1 / 1]
	//pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x16b9e0; // [100 ] [1 / 1]
	//pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x16b630; // [100 ] [1 / 1]
	//pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x18a940; // [100 ] [3 / 3]
	//pCInstanceBaseNEW_LookAtDestPixelPosition = Globals::hEntryBaseAddress + 0x17e9f0; // [100 ] [1 / 1]
	//pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x18a220; // [100 ] [1 / 1] 
	//pCInstanceBaseNEW_SetPixelPosition = Globals::hEntryBaseAddress + 0x18a8a0; // [100 ] [1 / 1]
	//pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x18a8c0; // [100 ] [1 / 1]
	//pCInstanceBaseSetDirection = Globals::hEntryBaseAddress + 0x18aab0; // [100 ] [1 / 1]
	//pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x182420; // [100 ] [1 / 1]
	//pCItemDataGetName = Globals::hEntryBaseAddress + 0x2f69f0; // [100 ] [2 / 2]
	//pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x306010; // [100 ] [4 / 4]
	//pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x18e730; // [100 ] [1 / 1]
	//pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x2aeb10; // [100 ] [1 / 1]
	//pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x24DCD0;
	//pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x24D0A0; 
	//pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x2aece0; // [100 ] [1 / 1]
	//pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x2aed50; // [100 ] [1 / 1]
	//pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x2AEF60; // [100 ] [1 / 1]
	//pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x2aefa0; // [100 ] [1 / 1]
	//pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x2AF020;
	//pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x3198c0; // [100 ] [1 / 1]
	//pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x22cfe0; // [100 ] [1 / 1]
	//pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x22c8b0; // [100 ] [18 / 18]
	//pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x19a890; // [100 ] [20 / 20]
	//pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x1fa050; // [100 ] [1 / 1]
	//pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x1a63d0; // [100 ] [1 / 1]
	//pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x24d220; // [100 ] [1 / 1]
	//pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x24d440; // [100 ] [1 / 1]
	//pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x257fd0; // [100 ] [1 / 1]
	//pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x2576b0; // [100 ] [1 / 1]
	//pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x257710; // [100 ] [1 / 1]
	//pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x2596a0; // [100 ] [1 / 1]
	//pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x24cc00; // [100 ] [1 / 1]
	//pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x257ba0; // [100 ] [2 / 2]
	//pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x257a40; // [100 ] [2 / 2]
	//pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x2579c0; // [100 ] [3 / 3]
	//pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x258de0; // [100 ] [1 / 1]
	//pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x258e40; // [100 ] [2 / 2]
	//pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x2642c0; // [100 ] [2 / 2]
	//pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x264340; // [100 ] [3 / 3]
	//pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x2644f0; // [100 ] [3 / 3]
	//pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x264080; // [100 ] [3 / 3]
	//pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x257ef0; // [100 ] [3 / 3]
	//pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x259030; // [100 ] [1 / 1]
	//pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x257cd0; // [100 ] [1 / 1]
	//pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x258050; // [100 ] [1 / 1]
	//pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x2646e0; // [100 ] [1 / 1]
	//pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x264680; // [100 ] [2 / 2]
	//pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x264810; // [100 ] [3 / 3]
	//pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x257400; // [100 ] [1 / 1]
	//pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x257870; // [100 ] [2 / 2]
	//pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x2597c0; // [100 ] [1 / 1]
	//pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x24f6b0; // [100 ] [11 / 11]
	//pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x1c1390; // [100 ] [3 / 3]
	//pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x1d7a00; // [100 ] [2 / 2]
	//pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x1c5f10; // [100 ] [7 / 7]
	//pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x1c61d0; // [100 ] [3 / 3]
	//pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x1c55b0; // [100 ] [2 / 2]
	//pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x1c57e0; // [100 ] [3 / 3]
	//pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x1c5840; // [66 ] [2 / 3]
	//pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x1c5a40; // [100 ] [5 / 5]
	//pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x1cd2d0; // [100 ] [1 / 1]
	//pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x1c6ff0; // [100 ] [1 / 1]
	//pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x1c7020; // [100 ] [2 / 2]
	//pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x1cccd0; // [100 ] [1 / 1]
	//pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x1c4e30; // [100 ] [14 / 14]
	//pCPythonPlayerNEW_SetSingleDIKKeyState = Globals::hEntryBaseAddress + 0x1ce410; // [100 ] [2 / 2]
	//pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x1ce2e0; // [100 ] [2 / 2]
	//pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x1cd040; // [100 ] [3 / 3]
	//pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x1cd5b0; // [100 ] [1 / 1]
	//pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x1cd3c0; // [100 ] [1 / 1]
	//pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x2b3eb0; // [100 ] [1 / 1]
	//pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x2a36b0; // [100 ] [4 / 4]
	//pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x2c30e0; // [100 ] [1 / 1]
	//pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x353B50; 
	//pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x231680; // [100 ] [1 / 1] 
	
	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x2d4ec44; // [100 ] [104 / 104]
	pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x2d4589c; // [100 ] [67 / 67]
	pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x2d4588c; // [100 ] [41 / 41]
	pCItemManagerInstance = Globals::hEntryBaseAddress + 0x2d458a4; // [100 ] [50 / 50]
	pCPythonItemInstance = Globals::hEntryBaseAddress + 0x2d4ec6c; // [100 ] [7 / 7]
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x2D50F04; // [100 ] [69 / 69]
	pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x2d45890; // [100 ] [7 / 7]
	pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x2d45898; // [100 ] [130 / 130]
	pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x2d4ec28; // [100 ] [4 / 4]
	pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x301170; // [100 ] [1 / 1]
	pCPythonBackgroundGetWarpMapName = Globals::hEntryBaseAddress + 0x190630; // [100 ] [4 / 4]
	pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x1905a0; // [100 ] [3 / 3]
	pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x16bd80; // [50 ] [1 / 2]
	//pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x300d70; // [50 ] [1 / 2]
	pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x16bdc0; // [100 ] [2 / 2]
	pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x16ab10; // [100 ] [3 / 3]
	pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x16abc0; // [100 ] [1 / 1]
	pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x16aad0; // [100 ] [10 / 10]
	pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x18ab80; // [100 ] [9 / 9]
	pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x16bb40; // [100 ] [9 / 9]
	pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x16b790; // [100 ] [14 / 14]
	pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x18aac0; // [100 ] [25 / 25]
	//pCInstanceBaseNEW_LookAtDestPixelPosition = Globals::hEntryBaseAddress + 0x17eb90; // [50 ] [1 / 2]
	pCInstanceBaseNEW_LookAtDestPixelPosition = Globals::hEntryBaseAddress + 0x18ab40; // [50 ] [1 / 2]
	pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x18a3a0; // [100 ] [8 / 8]
	pCInstanceBaseNEW_SetPixelPosition = Globals::hEntryBaseAddress + 0x18aa20; // [100 ] [5 / 5]
	pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x18aa40; // [100 ] [5 / 5]
	pCInstanceBaseSetDirection = Globals::hEntryBaseAddress + 0x18ac30; // [100 ] [3 / 3]
	pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x1825a0; // [100 ] [4 / 4]
	pCItemDataGetName = Globals::hEntryBaseAddress + 0x2f6d10; // [100 ] [4 / 4]
	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x306340; // [91 ] [11 / 12]

	pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x18e8b0; // [100 ] [3 / 3]
	pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x2AEEC0; // [100 ] [6 / 6]
	pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x24df00; // [100 ] [1 / 1]
	pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x24d2d0; // [100 ] [1 / 1]
	pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x2aefe0; // [100 ] [3 / 3]
	pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x2af050; // [77 ] [7 / 9]
	pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x2AF260; // [75 ] [3 / 4]
	pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x2af2a0; // [100 ] [6 / 6]
	pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x2af320; // [100 ] [82 / 82]
	pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x319bf0; // [100 ] [1 / 1]
	//pCPythonPlayerReviveGlobal = Globals::hEntryBaseAddress + (null); 
	pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x22d130; // [100 ] [4 / 4]
	pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x22ca00; // [100 ] [19 / 19]
	pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x19a9e0; // [45 ] [22 / 48]

	pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x1fa1a0; // [66 ] [2 / 3]
	pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x1a6510; // [100 ] [4 / 4]
	pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x24d450; // [100 ] [3 / 3]
	pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x24d670; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x258200; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x2578e0; // [100 ] [3 / 3]
	pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x257940; // [100 ] [11 / 11]
	pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x2598d0; // [100 ] [8 / 8]
	pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x24ce30; // [100 ] [3 / 3]
	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x257dd0; // [100 ] [3 / 3]
	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x257c70; // [100 ] [4 / 4]
	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x257bf0; // [100 ] [4 / 4]
	//pCPythonNetworkStreamSendFishingGlobalPacket = Globals::hEntryBaseAddress + (null); 
	pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x259010; // [100 ] [5 / 5]
	pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x259070; // [100 ] [3 / 3]
	pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x2645a0; // [100 ] [4 / 4]
	pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x264620; // [100 ] [4 / 4]
	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x2647d0; // [100 ] [4 / 4]
	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x264360; // [100 ] [5 / 5]
	pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x258120; // [100 ] [4 / 4]
	pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x259260; // [100 ] [3 / 3]
	pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x257f00; // [100 ] [4 / 4]
	pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x258280; // [100 ] [3 / 3]
	pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x2649c0; // [100 ] [3 / 3]
	pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x264960; // [100 ] [3 / 3]
	pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x264af0; // [100 ] [4 / 4]
	pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x257630; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x257aa0; // [100 ] [6 / 6]
	pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x2599f0; // [100 ] [3 / 3]
	pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x24f8d0; // [100 ] [12 / 12]
	pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x1c14c0; // [100 ] [11 / 11]
	pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x1d7b40; // [100 ] [5 / 5]
	pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x1c6040; // [81 ] [9 / 11]

	pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x1c6300; // [100 ] [5 / 5]
	pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x1c56e0; // [100 ] [2 / 2]
	pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x1c5910; // [71 ] [5 / 7]
	//pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xff9c00ed; // [28 ] [2 / 7]
	pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x1c5970; // [100 ] [4 / 4]
	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x1c5b70; // [85 ] [6 / 7]

	pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x1cd400; // [100 ] [3 / 3]
	pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x1c7120; // [100 ] [4 / 4]
	pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x1c7150; // [100 ] [3 / 3]
	pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x1cce00; // [100 ] [4 / 4]
	pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x1c4f60; // [83 ] [15 / 18]
	pCPythonPlayerNEW_SetSingleDIKKeyState = Globals::hEntryBaseAddress + 0x1ce540; // [100 ] [3 / 3]
	pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x1ce410; // [100 ] [3 / 3]
	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x1cd170; // [75 ] [3 / 4]
	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0xff9c00ed; // [25 ] [1 / 4]
	pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x1cd6e0; // [100 ] [3 / 3]
	pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x1cd4f0; // [100 ] [3 / 3]
	pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x2b41b0; // [100 ] [5 / 5]
	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x2a39b0; // [100 ] [9 / 9]
	pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x2c33e0; // [100 ] [2 / 2]
	pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x353e80; // [100 ] [1 / 1]
	pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x2317d0; // [100 ] [2 / 2]
	pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x2D5346C; 
#endif




#ifdef FORNAX
	pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x134150;
	
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x1DC1E84; // [98 %] [56 / 57]
	
#endif





#ifdef DREIKON

	
	pCItemManagerInstance = Globals::hEntryBaseAddress + 0x184f6fc; // [100 %] [50 / 50]
	pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x184f6e4; // [100 %] [43 / 43]
	pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x184f6f4; // [100 %] [77 / 77]
	pCPythonItemInstance = Globals::hEntryBaseAddress + 0x1879230; // [100 %] [5 / 5]
	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x1879224; // [100 %] [104 / 104]
	pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x184f6e8; // [100 %] [6 / 6]
	pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x184f6f0; // [100 %] [123 / 123]
	pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x18791f0; // [100 %] [4 / 4]
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x187B46C; // [98 %] [56 / 57]




	pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x54700;
	pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x49910;
	pCInstanceBaseNEW_SetPixelPosition = Globals::hEntryBaseAddress + 0x49910;
	pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x54690;
	pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x45C40;
	
	
	pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x481f0; // [100 %] [1 / 1]
	pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x47850; // [100 %] [2 / 2]
	
	pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x54810; // [100 %] [1 / 1]

	
	pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x45740; // [100 %] [1 / 1]

	
	pCInstanceBaseSetDirection = Globals::hEntryBaseAddress + 0x54850; // [100 %] [1 / 1]
	
	pCItemDataGetName = Globals::hEntryBaseAddress + 0x178550; // [100 %] [3 / 3]
	
	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x179900; // [100 %] [2 / 2]
	
	
	
	
	pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x140870; // [100 %] [1 / 1]

	pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x140b10; // [100 %] [1 / 1]
	
	
	
	
	
	pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0xcecc0; // [100 %] [1 / 1]
	pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0xce230; // [100 %] [1 / 1]

	
	pCPythonBackgroundGetWarpMapName = Globals::hEntryBaseAddress + 0x59760; // [100 %] [1 / 1]
	
	pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x594b0; // [100 %] [1 / 1]
	
	pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x62100; // [100 %] [25 / 25]
	
	pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x9ee10; // [100 %] [1 / 1]
	
	
	
	
	
	pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0xe9500; // [100 %] [2 / 2]

	
	pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0xf6260; // [100 %] [2 / 2]
	
	pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0xf3710; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0xf38a0; // [100 %] [1 / 1]
	
	pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0xe9f10; // [100 %] [2 / 2]
	
	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0xf5830; // [100 %] [2 / 2]
	
	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0xf5740; // [100 %] [3 / 3]
	
	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0xf5650; // [100 %] [4 / 4]
	pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0xf8d80; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0xf8de0; // [100 %] [1 / 1]

	pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x101b30; // [100 %] [3 / 3]
	pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x101d30; // [100 %] [3 / 3]
	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x101ed0; // [100 %] [3 / 3]
	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x101900; // [100 %] [3 / 3]
	
	pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0xf4720; // [100 %] [3 / 3]
	
	pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0xf9440; // [100 %] [2 / 2]
	
	pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0xf5ae0; // [100 %] [1 / 1]
	
	pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0xf6680; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x101710; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x1016b0; // [100 %] [1 / 1]
	
	pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x101840; // [100 %] [3 / 3]
	pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0xf62d0; // [100 %] [1 / 1]
	
	pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0xf3850; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0xf4250; // [100 %] [1 / 1]
	pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0xebd50; // [100 %] [9 / 9]
	
	
	pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x140AF0;
	pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x140B00;
	pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x140DD0;


	pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x75e80; // [100 %] [2 / 2]
	
	pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x87050; // [100 %] [1 / 1]

	pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x77c20; // [100 %] [7 / 7]
	pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x77d70; // [100 %] [2 / 2]

	pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x77090; // [100 %] [1 / 1]
	pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x77820; // [100 %] [4 / 4]

	pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x77180; // [100 %] [3 / 3]
	
	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x777e0; // [100 %] [4 / 4]
	pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x7d9e0; // [100 %] [2 / 2]

	
	pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x78bf0; // [100 %] [1 / 1]
	pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x78bc0; // [100 %] [2 / 2]
	
	pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x7e510; // [100 %] [1 / 1]
	pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x76c10; // [100 %] [13 / 13]
	
	pCPythonPlayerNEW_SetSingleDIKKeyState = Globals::hEntryBaseAddress + 0x7f140; // [100 %] [2 / 2]

	
	pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x7f0e0; // [100 %] [2 / 2]
	
	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x7dac0; // [100 %] [2 / 2]


	pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x7de80; // [100 %] [1 / 1]
	
	pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x7df60; // [100 %] [1 / 1]
	
	
	
	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x139460; // [100 %] [3 / 3]
	




#endif

#ifdef PANGEA
#endif

#ifdef  ALTRIC
#endif

#ifdef  DIUMAR
#endif

#ifdef TENELIS
#endif

#ifdef AKADEMIA_NERWIA
#endif		

#ifdef SAMIAS2
#endif

#ifdef   EGORIA
#endif

#ifdef IVEYA
#endif

#ifdef AELDRA
	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x16B7D08;
	
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x16C0E6C;
	pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x44A690;
#endif



#ifdef RUBINUM





	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x1bf0730; // [100 ] [95 / 95]

	pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x1bf070c; // [98 ] [83 / 84]

	pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x1baad24; // [95 ] [40 / 42]

	pCItemManagerInstance = Globals::hEntryBaseAddress + 0x1bf0708; // [97 ] [48 / 49]
	pCPythonItemInstance = Globals::hEntryBaseAddress + 0x1bf0768; // [100 ] [4 / 4]
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x1BAD174; // [100 ] [1 / 1]
	pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x1bf0704; // [100 ] [15 / 15]

	pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x1bf06f8; // [98 ] [96 / 97]
	pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x1bf0740; // [100 ] [5 / 5]
	
	pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x2D6E20; // [100 ] [1 / 1]
	pCPythonBackgroundGetWarpMapName = Globals::hEntryBaseAddress + 0x85360; // [100 ] [3 / 3]
	pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x850B0;
	pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x2d6a20; // [100 ] [1 / 1]
	pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x6def0; // [100 ] [2 / 2]
	pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x717c0; // [100 ] [1 / 1]
	pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x717e0; // [100 ] [1 / 1]
	pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x71020; // [80 ] [4 / 5]

	pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x81e30; // [100 ] [5 / 5]
	pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x6f720; // [100 ] [2 / 2]
	pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x6f390; // [80 ] [4 / 5]
	
	pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x81d50; // [100 ] [10 / 10]
	pCInstanceBaseNEW_LookAtDestPixelPosition = Globals::hEntryBaseAddress + 0x710f0; // [100 ] [1 / 1]
	pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x819d0; // [100 ] [3 / 3]
	pCInstanceBaseNEW_SetPixelPosition = Globals::hEntryBaseAddress + 0x81d40; // [100 ] [2 / 2]
	pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x81cf0; // [100 ] [1 / 1]
	pCInstanceBaseSetDirection = Globals::hEntryBaseAddress + 0x81e70; // [100 ] [2 / 2]
	pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x7c030; // [100 ] [1 / 1]
	pCItemDataGetName = Globals::hEntryBaseAddress + 0x2e2f80; // [75 ] [3 / 4]
	

	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x2e73a0; // [80 ] [4 / 5]
	
	pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x84fe0; // [50 ] [1 / 2]
	pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x29C300; // [100 ] [4 / 4]
	pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x1499F0; 
	pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x149190; 
	pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x29c430; // [100 ] [3 / 3]
	pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x29c4a0; // [100 ] [2 / 2]
	pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x29C6A0; // [100 ] [1 / 1]
	pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x29c6e0; // [75 ] [3 / 4]

	pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x359b69; // [100 ] [5 / 5]
	pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x2f7710; // [100 ] [2 / 2]

	pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x1263b0; // [100 ] [1 / 1]
	pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x125a50; // [100 ] [18 / 18]
	pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x8d230; // [96 ] [25 / 26]

	pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0xe8360; // [100 ] [1 / 1]
	pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0xa4530; // [100 ] [2 / 2]
	pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x149280; // [100 ] [1 / 1]
	pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x149930; 
	pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x1566A0;// 0x156620; 
	pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x156240; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x152e60; // [100 ] [3 / 3]152E60
	pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x153080; // [100 ] [6 / 6]
	pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x149b00; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x155670; // [100 ] [3 / 3]
	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x1555a0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x155380; // [100 ] [3 / 3]

	pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x1586e0; // [100 ] [3 / 3]
	pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x158740; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x15e110; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x15e270; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x15e3a0; // [100 ] [4 / 4]
	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x15deb0; // [100 ] [3 / 3]
	pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x1545c0; // [100 ] [3 / 3]
	pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x158de0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x155910; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x1565e0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x15dd00; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x15dca0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x15dde0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x1562c0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x153020; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x153b60; // [100 ] [2 / 2]
	pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x14ad00; // [100 ] [9 / 9]
	
	pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xb6ff0; // [83 ] [10 / 12]
	pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0xcb160; // [100 ] [3 / 3]
	pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xBBB50; 
	pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0xbbe60; // [100 ] [1 / 1]
	pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xbb0d0; // [100 ] [1 / 1]
	pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xbb6f0; // [100 ] [1 / 1]
	pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xbb180; // [100 ] [2 / 2]
	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xbb6c0; // [100 ] [4 / 4]
	pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0xc2350; // [100 ] [2 / 2]
	pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xbcb20; // [100 ] [2 / 2]
	pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xbcb00; // [100 ] [2 / 2]
	pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0xc2e00; // [100 ] [1 / 1]
	pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xbae00; // [100 ] [10 / 10]
	pCPythonPlayerNEW_SetSingleDIKKeyState = Globals::hEntryBaseAddress + 0xc3690; // [100 ] [1 / 1]
	pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0xc3650; // [100 ] [1 / 1]
	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0xc23e0; // [100 ] [2 / 2]
	//pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + (null); 
	pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0xC2960; 
	pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x29f720; // [100 ] [15 / 15]
	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x28f220; // [100 ] [22 / 22]
	pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x29bdf0; // [100 ] [3 / 3]
	pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x335540; // [100 ] [1 / 1]
	pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x12a4f0; // [100 ] [1 / 1]
	pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x1B2F7C4; 
	pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x29CDD0;




#endif
#ifdef VALIUM
	pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x26aedd4;
	pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x26aedcc;
	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x26b11fc;
	pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x26aedd8;
	pCItemManagerInstance = Globals::hEntryBaseAddress + 0x26aede4;
	pCPythonItemInstance = Globals::hEntryBaseAddress + 0x26b12f0;
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x26b33f8;
	pCEterPackManagerInstance = Globals::hEntryBaseAddress + 0x26b1154;
	pCResource = Globals::hEntryBaseAddress + 0x2419d48;
	//pCPythonChatInstance = Globals::hEntryBaseAddress + 0x26b1304;
	pCScreen = Globals::hEntryBaseAddress + 0x2419d48;
	pCCameraManagerInstance = Globals::hEntryBaseAddress + 0x26b10a4;
	pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x26aedc8;
	pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0xd49a0;
	pCPythonPlayerPickCloseItem = Globals::hEntryBaseAddress + 0x20f9b0;
	pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xcdde0;
	pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xce070;
	pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xcf7f0;
	pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xce010;
	pCPythonPlayerSetStatus = Globals::hEntryBaseAddress + 0xce0e0;
	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xce270;
	pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0xde9f0;
	pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xce700;
	pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xcd670;
	pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0xd5990;
	pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xcf7c0;
	pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0xce9c0;
	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0xd4710;
	pCPythonPlayerNEW_SetSingleDIKKeyState = Globals::hEntryBaseAddress + 0xd5ac0;
	pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x2489e0;
	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x158e00;
	pCPythonNetworkStreamGetMainActorVID = Globals::hEntryBaseAddress + 0x142670;
	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x14bc40;
	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x14bcc0;
	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x20f9b0;
	pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x159040;
	pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x14ddb0;
	pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x14ded0;
	pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x142440;
	pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x1424b0;
	pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x14d2f0;
	pCNetworkStreamDirectEnterModeSet = Globals::hEntryBaseAddress + 0x142f30;
	//pCNetworkStreamConnect1 = Globals::hEntryBaseAddress + 0x192210;
	pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x192290;
	pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x14c150;
	pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x192340;
	pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x142330;
	pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x14baf0;
	pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x14b8f0;
	pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x14c230;
	pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x14c2b0;
	pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x14b960;
	pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x1444a0;
	pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x14bf50;
	//pCPythonNetworkStreamRecvTargetPacket = Globals::hEntryBaseAddress + 0x152860;
	//pCActorInstanceProcessDataAttackSuccess = Globals::hEntryBaseAddress + 0x1cb0c0;
	//pCPythonPlayerUseSkill = Globals::hEntryBaseAddress + 0xdf720;
	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x159420;
	pCInstanceBaseNEW_LookAtDestPixelPosition = Globals::hEntryBaseAddress + 0x9e620;
	//pCPythonCharacterManagerUpdate = Globals::hEntryBaseAddress + 0xb4f60;
	//pCPythonCharacterManagerUpdateTransform = Globals::hEntryBaseAddress + 0xb5a90;
	pCInstanceBaseCheckAdvancing = Globals::hEntryBaseAddress + 0x9d310;
	//pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x00;
	//pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x00;
	pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x1925c0;
	pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x174100;
	pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x192620;
	//ClickActor = Globals::hEntryBaseAddress + 0xd4f20;
	pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0xd4df0;
	pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x1dcf60;

	//pCPythonCharacterManagerSetAffect = Globals::hEntryBaseAddress + 0xb8d50;
	pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0xa0d30;
	pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0xd4a90;
	pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x978b0;
	pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x978d0;

	pCInstanceBaseGetDistance = Globals::hEntryBaseAddress + 0x98d70;
	pCInstanceBaseSetDirection = Globals::hEntryBaseAddress + 0xa7030;
	pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x98610;
	pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0xa6ec0;
	pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0xa6780;
	pCInstanceBaseNEW_SetPixelPosition = Globals::hEntryBaseAddress + 0xa6e20;
	pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0xa6e40;
	//pCInstanceBaseRevive = Globals::hEntryBaseAddress + 0x9ddb0;
	pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0xa6f80;
	pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0xb56c0;
	pCPythonCharacterManagerIsAliveVID = Globals::hEntryBaseAddress + 0xb4a50;
	pCPythonCharacterManagerPickAll = Globals::hEntryBaseAddress + 0xb57b0;
	pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0xf8100;
	pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x126460;
	pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x20f9b0;
	pCPythonItemCreateItem = Globals::hEntryBaseAddress + 0xc5dc0;
	pCPythonItemGetPickedItemID = Globals::hEntryBaseAddress + 0xc6e50;
	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x1d1b30;
	pCItemDataGetName = Globals::hEntryBaseAddress + 0x1c40b0;

	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x18b000;
	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x18b000;
	pCInstanceBaseSetAddColor = Globals::hEntryBaseAddress + 0x98ce0;
	pCInstanceBaseSetAddRenderMode = Globals::hEntryBaseAddress + 0xc8250;
	pCInstanceBaseRestoreRenderMode = Globals::hEntryBaseAddress + 0x98c60;
	pCGetWarpMapName = Globals::hEntryBaseAddress + 0xac610;
	pCLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0xaa6d0;
	pCGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x20f930;
	pCEterPackManagerGet = Globals::hEntryBaseAddress + 0x173f30;
	//MapFile = Globals::hEntryBaseAddress + 0x20f010;
	pCMappedFileConstructor = Globals::hEntryBaseAddress + 0x1753a0;
	//MapFile2 = Globals::hEntryBaseAddress + 0x194d70;
	pCMappedFileSize = Globals::hEntryBaseAddress + 0x174cf0;
	pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x5cb20;
	pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x1a3b60;
	//pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x00;
	pCPythonIsAtlas = Globals::hEntryBaseAddress + 0xaf120;

#endif
#ifdef ELITEMT2
#endif
#ifdef AVENTUS2




#endif
#ifdef CLASSIC
	pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x44b938;
	pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x44b930;
	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x44db68;
	pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x44b93c;
	pCItemManagerInstance = Globals::hEntryBaseAddress + 0x44b944;
	pCPythonItemInstance = Globals::hEntryBaseAddress + 0x44db78;
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x44fba8;
	pCEterPackManagerInstance = Globals::hEntryBaseAddress + 0x44db14;
	pCResource = Globals::hEntryBaseAddress + 0x44db54;
	//pCPythonChatInstance = Globals::hEntryBaseAddress + 0x44dc5c;
	pCScreen = Globals::hEntryBaseAddress + 0x44db28;
	pCCameraManagerInstance = Globals::hEntryBaseAddress + 0x44db0c;
	pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x44b92c;
	pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x8b500;
	pCPythonPlayerPickCloseItem = Globals::hEntryBaseAddress + 0x8bb20;
	pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x87ce0;
	pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x87dd0;
	pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x88460;
	pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x87cf0;
	pCPythonPlayerSetStatus = Globals::hEntryBaseAddress + 0x89640;
	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x87f90;
	pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x91f80;
	pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x88820;
	pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x8ca30;
	pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x88430;
	pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x87af0;
	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x8bd60;
	pCPythonPlayerNEW_SetSingleDIKKeyState = Globals::hEntryBaseAddress + 0x8c900;
	pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x85790;
	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0xe59e0;
	pCPythonNetworkStreamGetMainActorVID = Globals::hEntryBaseAddress + 0xd3a90;
	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0xe0b70;
	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0xe0b00;
	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0xe09e0;
	pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0xe57f0;
	pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0xe0410;
	pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0xe1b30;
	pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0xd3a80;
	pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0xd3760;
	pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0xe18b0;
	pCNetworkStreamDirectEnterModeSet = Globals::hEntryBaseAddress + 0xd41a0;
	//pCNetworkStreamConnect1 = Globals::hEntryBaseAddress + 0x12da80;
	pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x12daf0;
	pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0xe1540;
	pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x12dba0;
	pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0xd3970;
	pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0xe1ad0;
	pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0xe0080;
	pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0xdff80;
	pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0xe1990;
	pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0xe02c0;
	pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0xd46f0;
	pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0xe18e0;
	//pCPythonNetworkStreamRecvTargetPacket = Globals::hEntryBaseAddress + 0xdc0b0;
	//pCActorInstanceProcessDataAttackSuccess = Globals::hEntryBaseAddress + 0x1798e0;
	//pCPythonPlayerUseSkill = Globals::hEntryBaseAddress + 0x92d10;
	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0xe5990;
	pCInstanceBaseNEW_LookAtDestPixelPosition = Globals::hEntryBaseAddress + 0x6e320;
	//pCPythonCharacterManagerUpdate = Globals::hEntryBaseAddress + 0x76780;
	//pCPythonCharacterManagerUpdateTransform = Globals::hEntryBaseAddress + 0x76880;
	pCInstanceBaseCheckAdvancing = Globals::hEntryBaseAddress + 0x67cb0;
	pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x67410;
	pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x63fc0;
	pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x12de40;
	pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x12de90;
	pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x104960;
	//ClickActor = Globals::hEntryBaseAddress + 0x8c5e0;
	pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x64400;
	pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x193a10;

	//pCPythonCharacterManagerSetAffect = Globals::hEntryBaseAddress + 0x775f0;
	pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x6b100;
	pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x8c340;
	pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x63fc0;
	pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x63ea0;

	pCInstanceBaseGetDistance = Globals::hEntryBaseAddress + 0x63c10;
	pCInstanceBaseSetDirection = Globals::hEntryBaseAddress + 0x6e400;
	pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x645e0;
	pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x6e2f0;
	pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x6dc60;
	pCInstanceBaseNEW_SetPixelPosition = Globals::hEntryBaseAddress + 0x6e390;
	pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x6e3a0;
	//pCInstanceBaseRevive = Globals::hEntryBaseAddress + 0x760c0;
	pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x6e2e0;
	pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x75fe0;
	pCPythonCharacterManagerIsAliveVID = Globals::hEntryBaseAddress + 0x76120;
	pCPythonCharacterManagerPickAll = Globals::hEntryBaseAddress + 0x76280;
	pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0xa4280;
	pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0xc07e0;
	pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0xc0ee0;
	pCPythonItemCreateItem = Globals::hEntryBaseAddress + 0x813d0;
	pCPythonItemGetPickedItemID = Globals::hEntryBaseAddress + 0x825b0;
	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x173bd0;
	pCItemDataGetName = Globals::hEntryBaseAddress + 0x6ced0;

	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x124050;
	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x124050;
	pCInstanceBaseSetAddColor = Globals::hEntryBaseAddress + 0x65a30;
	pCInstanceBaseSetAddRenderMode = Globals::hEntryBaseAddress + 0x65a40;
	pCInstanceBaseRestoreRenderMode = Globals::hEntryBaseAddress + 0x65a20;
	pCGetWarpMapName = Globals::hEntryBaseAddress + 0x70e80;
	pCLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x71120;
	pCGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x70ec0;
	pCEterPackManagerGet = Globals::hEntryBaseAddress + 0x149710;
	//MapFile = Globals::hEntryBaseAddress + 0x1d0590;
	pCMappedFileConstructor = Globals::hEntryBaseAddress + 0x107280;
	//MapFile2 = Globals::hEntryBaseAddress + 0x131130;
	pCMappedFileSize = Globals::hEntryBaseAddress + 0x1077e0;
	pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x131530;
	pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x13ff40;
	pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x17daf0;
	pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x87a90;
	pCPythonIsAtlas = Globals::hEntryBaseAddress + 0xb1b40;

	pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x1D0BB0;
#endif

#ifdef BALMORA
#endif

#ifdef AZENTIS
#endif

#ifdef VERESTHIA
#endif


#ifdef VAROS
#endif
#ifdef  AKADEMIA_VESTERIS

#endif
#ifdef MEDIUM

#endif
#ifdef METINPL
	HANDLE process = GetCurrentProcess();
	MEMORY_BASIC_INFORMATION info;
	unsigned char* p = NULL;
	for (p = NULL; VirtualQueryEx(process, p, &info, sizeof(info)) == sizeof(info);p += info.RegionSize)
	{
		if ((info.State == MEM_COMMIT) && ((info.Type & MEM_MAPPED) || (info.Type & MEM_PRIVATE)) && info.Protect == 0x40) {
			if (info.RegionSize >= 0x02000000) {
				Globals::hEntryBaseAddress = (DWORD)info.BaseAddress;
			}
		}
	}
	//pCEterPackManagerInstance = Globals::hEntryBaseAddress + 0x1daeb9c; // [100 %] [1 / 1]
	pCItemManagerInstance = Globals::hEntryBaseAddress + 0x1dab8fc; // [100 %] [1 / 1]
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x1db0fb4; // [100 %] [1 / 1]
	pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x1dab900; // [100 %] [1 / 1]
	pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x1dab904; // [100 %] [1 / 1]
	//pCPythonChatInstance = Globals::hEntryBaseAddress + 0x1daeea4; // [100 %] [1 / 1]
	pCPythonItemInstance = Globals::hEntryBaseAddress + 0x1daed28; // [100 %] [1 / 1]
	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x1daec58; // [100 %] [1 / 1]
	pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x1dab90c; // [100 %] [1 / 1]
	pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x1dab8f8; // [100 %] [1 / 1]
	pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x1daece4; // [100 %] [1 / 1]
	//D3DDEVICE = Globals::hEntryBaseAddress + 0x403730; // [100 %] [1 / 1]
	//GetTextures = Globals::hEntryBaseAddress + 0x3eebd0; // [100 %] [1 / 1]
	//MapFile = Globals::hEntryBaseAddress + 0x43f910; // [100 %] [1 / 1]
	//MapFile2 = Globals::hEntryBaseAddress + 0x41cb70; // [100 %] [1 / 1]
	//pCActorInstanceProcessDataAttackSuccess = Globals::hEntryBaseAddress + 0x38da30; // [100 %] [1 / 1]
	pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x3909a0; // [100 %] [1 / 1]
	//pCActorInstance__CanPushDestActor = Globals::hEntryBaseAddress + 0x38d0a0; // [100 %] [1 / 1]
	//pCEterPackManagerGet = Globals::hEntryBaseAddress + 0x4ae6e0; // [100 %] [1 / 1]
	pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x42f510; // [100 %] [1 / 1]
	//pCGraphicImageInstanceGetTexturePointer = Globals::hEntryBaseAddress + 0x485ba0; // [100 %] [1 / 1]
	pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x41c700; // [100 %] [1 / 1]
	pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x54cb0; // [100 %] [1 / 1]
	pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x54c70; // [100 %] [1 / 1]
	//pCInstanceBaseCheckAdvancing = Globals::hEntryBaseAddress + 0x657c0; // [100 %] [1 / 1]
	//pCInstanceBaseGetDistance = Globals::hEntryBaseAddress + 0x599e0; // [100 %] [1 / 1]
	pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x598a0; // [100 %] [1 / 1]
	pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x598f0; // [100 %] [1 / 1]
	pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x58e50; // [100 %] [1 / 1]
	pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x73140; // [100 %] [1 / 1]
	//pCInstanceBaseGetRotation2 = Globals::hEntryBaseAddress + 0x5acf0; // [100 %] [1 / 1]
	pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x56a60; // [100 %] [1 / 1]
	pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x565b0; // [100 %] [1 / 1]
	pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x73030; // [100 %] [1 / 1]
	pCInstanceBaseNEW_LookAtDestPixelPosition = Globals::hEntryBaseAddress + 0x103a10; // [100 %] [1 / 1]
	pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x72b80; // [100 ] [1 / 1]
	pCInstanceBaseNEW_SetPixelPosition = Globals::hEntryBaseAddress + 0x73010; // [100 %] [1 / 1]
	//pCInstanceBaseRestoreRenderMode = Globals::hEntryBaseAddress + 0x59af0; // [100 %] [1 / 1]
	//pCInstanceBaseRevive = Globals::hEntryBaseAddress + 0x201110; // [100 %] [1 / 1]
	pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x72fc0; // [100 %] [1 / 1]
	//pCInstanceBaseSetAddColor = Globals::hEntryBaseAddress + 0x59b50; // [100 %] [1 / 1]
	//pCInstanceBaseSetAddRenderMode = Globals::hEntryBaseAddress + 0x59b10; // [100 %] [1 / 1]
	pCInstanceBaseSetDirection = Globals::hEntryBaseAddress + 0x65520; // [100 %] [1 / 1]
	pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x6a250; // [100 %] [1 / 1]
	pCItemDataGetName = Globals::hEntryBaseAddress + 0x4f2198; // [100 %] [1 / 1]
	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x4f2198; // [100 %] [1 / 1]
	//pCMappedFileConstructor = Globals::hEntryBaseAddress + 0x444290; // [100 %] [1 / 1]
	//pCMappedFileSize = Globals::hEntryBaseAddress + 0x4444f0; // [100 %] [1 / 1]
	pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x4192d0; // [100 %] [1 / 1]
	//pCNetworkStreamConnect1 = Globals::hEntryBaseAddress + 0x419560; // [100 %] [1 / 1]
	pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x1dcf30; // [100 %] [1 / 1]
	pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x1db0d0; // [100 %] [1 / 1]
	pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x419a90; // [100 %] [1 / 1]
	pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x4422a0; // [100 %] [1 / 1]
	pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x419ab0; // [100 %] [1 / 1]
	pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x3b8820; // [100 %] [1 / 1]
	pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x3fea00; // [100 %] [1 / 1]
	pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x1b7ea0; // [100 %] [1 / 1]
	//pCPythonApplicationProcess2 = Globals::hEntryBaseAddress + 0x1b8b80; // [100 %] [1 / 1]
	pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x1b7360; // [100 %] [1 / 1]
	pCPythonBackgroundGetWarpMapName = Globals::hEntryBaseAddress + 0x77530; // [100 %] [1 / 1]
	pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x76ad0; // [100 %] [1 / 1]
	pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x76a10; // [100 %] [1 / 1]
	pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x834a0; // [100 %] [1 / 1]

	pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x149400; // [100 %] [1 / 1]
	//pCPythonIsAtlas = Globals::hEntryBaseAddress + 0x1934d0; // [100 %] [1 / 1]
	//pCPythonItemGetPickedItemID = Globals::hEntryBaseAddress + 0xbbb50; // [100 %] [1 / 1]
	pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x1db1b0; // [100 %] [1 / 1]
	pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x1dce80; // [100 %] [1 / 1]
	//pCPythonNetworkStreamRecvTargetPacket = Globals::hEntryBaseAddress + 0x1f1390; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x1f1ad0; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x1f1640; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x1ebd40; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x1ebf00; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x200210; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x452cf0; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x1f0970; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x1f0840; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendFishingGlobalPacket = Globals::hEntryBaseAddress + 0x1f6690; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x1f6640; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x20e150; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x20e5c0; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x20df50; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x1edf70; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x1f7190; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x1f0d80; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x1f1a70; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x20ddb0; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x20dd50; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x20f400; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x1f16a0; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x1ebeb0; // [100 %] [1 / 1]
	pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x1ed8d0; // [100 %] [1 / 1]
	pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x1de2c0; // [100 %] [1 / 1]
	pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xe3930; // [100 %] [1 / 1]
	pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x11b330; // [100 %] [1 / 1]
	pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xed2d0; // [100 %] [1 / 1]
	pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0xed7e0; // [100 %] [1 / 1]
	pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xec6a0; // [100 %] [1 / 1]
	pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xece80; // [100 %] [1 / 1]
	pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xec7d0; // [100 %] [1 / 1]
	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xece40; // [100 %] [1 / 1]
	pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x103680; // [100 %] [1 / 1]
	pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xeef60; // [100 %] [1 / 1]
	pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xeef30; // [100 %] [1 / 1]
	pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xec1a0; // [100 %] [1 / 1]
	//pCPythonPlayerPickCloseItem = Globals::hEntryBaseAddress + 0x103590; // [100 %] [1 / 1]
	pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x1051d0; // [100 %] [1 / 1]
	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x1036e0; // [100 %] [1 / 1]
	//pCPythonPlayerUseSkill = Globals::hEntryBaseAddress + 0x11bf90; // [100 %] [1 / 1]
	pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x104e90; // [100 %] [1 / 1]
	pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x103cd0; // [100 %] [1 / 1]
	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x407a20; // [100 %] [1 / 1]
	pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x3fea00;
	pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x1DB8008;

#endif
#ifdef BARIA

#endif
#ifdef GLADOR
	
#endif
#ifdef NERWIAS2
	
#endif
#ifdef MORAH

#endif
#ifdef SENTHIA

#endif
#ifdef NODIA

#endif
#ifdef ITANOS

#endif


#ifdef RAFON
	pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x25552dc;
	pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x25552d4;
	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x2564ff0;
	pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x25552e0;
	pCItemManagerInstance = Globals::hEntryBaseAddress + 0x25552e8;
	pCPythonItemInstance = Globals::hEntryBaseAddress + 0x2565064;
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x2567198;
	pCEterPackManagerInstance = Globals::hEntryBaseAddress + 0x2564f04;
	pCResource = Globals::hEntryBaseAddress + 0x2565020;
	//pCPythonChatInstance = Globals::hEntryBaseAddress + 0x2565150;
	pCScreen = Globals::hEntryBaseAddress + 0x22dfbc8;
	pCCameraManagerInstance = Globals::hEntryBaseAddress + 0x2564eac;
	pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x25552d0;
	pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x1ce46f0;
	pCPythonPlayerPickCloseItem = Globals::hEntryBaseAddress + 0x1e96c40;
	pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x1cdaff0;
	pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x1cdb280;
	pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x1cdc840;
	pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x1cdb220;
	pCPythonPlayerSetStatus = Globals::hEntryBaseAddress + 0x1cdb2f0;
	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x1cdb480;
	pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x1cf01d0;
	pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x1cdb810;
	pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x1cda8f0;
	pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x1ce5700;
	pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x1cdc810;
	pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x1cdbad0;
	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x1ce4460;
	pCPythonPlayerNEW_SetSingleDIKKeyState = Globals::hEntryBaseAddress + 0x1ce5830;
	pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x1cd5a50;
	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x1d98e10;
	pCPythonNetworkStreamGetMainActorVID = Globals::hEntryBaseAddress + 0x1d822e0;
	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x1d8c110;
	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x1d8c190;
	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x1e96c40;
	pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x1d99050;
	pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x1d8de60;
	pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x1d8df80;
	pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x1d820b0;
	pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x1d82120;
	pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x1d8d770;
	pCNetworkStreamDirectEnterModeSet = Globals::hEntryBaseAddress + 0x1d82bc0;
	//pCNetworkStreamConnect1 = Globals::hEntryBaseAddress + 0x1dea4a0;
	pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x1dea520;
	pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x1d8c5b0;
	pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x1dea5d0;
	pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x1d81fa0;
	pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x1d8bf80;
	pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x1d8bdc0;
	pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x1d8c690;
	pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x1d8c710;
	pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x1d8be20;
	pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x1d84820;
	pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x1d8c3b0;
	//pCPythonNetworkStreamRecvTargetPacket = Globals::hEntryBaseAddress + 0x1d926b0;
	//pCActorInstanceProcessDataAttackSuccess = Globals::hEntryBaseAddress + 0x1e3bd90;
	//pCPythonPlayerUseSkill = Globals::hEntryBaseAddress + 0x1cf0e60;
	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x1d992f0;
	pCInstanceBaseNEW_LookAtDestPixelPosition = Globals::hEntryBaseAddress + 0x1c8b7f0;
	//pCPythonCharacterManagerUpdate = Globals::hEntryBaseAddress + 0x1c86540;
	//pCPythonCharacterManagerUpdateTransform = Globals::hEntryBaseAddress + 0x00;
	//pCInstanceBaseCheckAdvancing = Globals::hEntryBaseAddress + 0x00;
	////pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x00;
	//pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x00;
	pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x1dea880;
	pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x1dc14f0;
	pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x1dea910;
	//ClickActor = Globals::hEntryBaseAddress + 0x1ce4c80;
	pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x1c7e700;
	pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x1e55d60;

	//pCPythonCharacterManagerSetAffect = Globals::hEntryBaseAddress + 0x1cb6290;
	pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x1c90940;
	pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x1ce47e0;
	pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x1c7d5c0;
	pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x1c7d6a0;

	pCInstanceBaseGetDistance = Globals::hEntryBaseAddress + 0x1c7eab0;
	pCInstanceBaseSetDirection = Globals::hEntryBaseAddress + 0x1c9cc20;
	pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x1c7e350;
	pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x1c9cab0;
	pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x1c9c390;
	pCInstanceBaseNEW_SetPixelPosition = Globals::hEntryBaseAddress + 0x1c9ca10;
	pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x1c9ca30;
	//pCInstanceBaseRevive = Globals::hEntryBaseAddress + 0x1c8b000;
	pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x1c9cb70;
	pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x1caf9b0;
	pCPythonCharacterManagerIsAliveVID = Globals::hEntryBaseAddress + 0x1caed50;
	pCPythonCharacterManagerPickAll = Globals::hEntryBaseAddress + 0x1cafaa0;
	pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x1d12830;
	pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x1d5bdc0;
	pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x1e96c40;
	pCPythonItemCreateItem = Globals::hEntryBaseAddress + 0x1cc86e0;
	pCPythonItemGetPickedItemID = Globals::hEntryBaseAddress + 0x1cc96e0;
	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x1e444f0;
	pCItemDataGetName = Globals::hEntryBaseAddress + 0x1e334e0;
	
	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x1de06a0;
	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x1de06a0;
	pCInstanceBaseSetAddColor = Globals::hEntryBaseAddress + 0x1c7ea20;
	pCInstanceBaseSetAddRenderMode = Globals::hEntryBaseAddress + 0x1c96170;
	pCInstanceBaseRestoreRenderMode = Globals::hEntryBaseAddress + 0x1c7e9a0;
	pCGetWarpMapName = Globals::hEntryBaseAddress + 0x1ca2920;
	pCLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x1ca0c50;
	pCGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x1ca2890;
	pCEterPackManagerGet = Globals::hEntryBaseAddress + 0x1dc3820;
	//MapFile = Globals::hEntryBaseAddress + 0x1e96140;
	pCMappedFileConstructor = Globals::hEntryBaseAddress + 0x1dc3820;
	//MapFile2 = Globals::hEntryBaseAddress + 0x1dee4c0;
	pCMappedFileSize = Globals::hEntryBaseAddress + 0x1e088a0;
	pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x1deea80;
	pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x1dfe360;
	//pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x00;
	pCPythonIsAtlas = Globals::hEntryBaseAddress + 0x1ca7f80;



#endif

}

void Globals::ReDeclarationLocals()
{
	if (pCPythonCharacterManagerInstance != NULL)
	{
		Globals::iCPythonCharacterManagerInstance = *reinterpret_cast<DWORD *>(pCPythonCharacterManagerInstance);
	}
	if (pCResourceManagerInstance != NULL) 
	{
		Globals::iCResourceManagerInstance = *reinterpret_cast<DWORD*>(pCResourceManagerInstance);
	}
	if (pCPythonPlayerInstance != NULL)
	{
		Globals::iCPythonPlayerInstance = *reinterpret_cast<DWORD *>(pCPythonPlayerInstance);
	}
	if (pCPythonNonPlayerInstance != NULL)
	{
		Globals::iCPythonNonPlayerInstance = *reinterpret_cast<DWORD*>(pCPythonNonPlayerInstance);
	}
	if (pCPythonNetworkStreamInstance != NULL)
	{
		Globals::iCPythonNetworkStreamInstance = *reinterpret_cast<DWORD *>(pCPythonNetworkStreamInstance);
	}
	if (pCItemManagerInstance != NULL)
	{
		Globals::iCItemManagerInstance = *reinterpret_cast<DWORD *>(pCItemManagerInstance);
	}
	if (pCPythonItemInstance != NULL)
	{
		Globals::iCPythonItemInstance = *reinterpret_cast<DWORD*>(pCPythonItemInstance);
	}
	if (pCPythonApplicationInstance != NULL)
	{
		Globals::iCPythonApplicationInstance = *reinterpret_cast<DWORD *>(pCPythonApplicationInstance);
	}
	if (pCPythonBackgroundInstance != NULL) 
	{
		Globals::iCPythonBackgroundInstance = *reinterpret_cast<DWORD*>(pCPythonBackgroundInstance);
	}
	if (pCGraphicBasems_lpd3dDevice != NULL) {
		Device::pDevice = *reinterpret_cast<DirectDevice2*>(pCGraphicBasems_lpd3dDevice);
	}
	if (pPyCallClassMemberFunc != NULL)
	{
		PyCallClassMemberFunc = (tPyCallClassMemberFunc)(pPyCallClassMemberFunc);
	}
	if (pCNetworkStreamRecv != NULL)
	{
		CNetworkStreamRecv = (tCNetworkStreamRecv)(Globals::pCNetworkStreamRecv);
	}
	if (pCNetworkStreamSend != NULL)
	{
		CNetworkStreamSend = (tCNetworkStreamSend)(Globals::pCNetworkStreamSend);
	}
	if (pCPythonNetworkStreamSendItemUsePacket != NULL)
	{
		CPythonNetworkStreamSendItemUsePacket = (tCPythonNetworkStreamSendItemUsePacket)(Globals::pCPythonNetworkStreamSendItemUsePacket);
	}
	if (pCPythonPlayerNEW_Fishing != NULL)
	{
		CPythonPlayerNEW_Fishing = (tCPythonPlayerNEW_Fishing)(Globals::pCPythonPlayerNEW_Fishing);
	}
	if (pCPythonChatAppendChat != NULL)
	{
		CPythonChatAppendChat = (tCPythonChatAppendChat)(Globals::pCPythonChatAppendChat);
	}
	if (pCPythonPlayerSetAttackKeyState != NULL)
	{
		CPythonPlayerSetAttackKeyState = (tCPythonPlayerSetAttackKeyState)(Globals::pCPythonPlayerSetAttackKeyState);
	}
	if (pCPythonNetworkStreamSendFishingPacket != NULL)
	{
		CPythonNetworkStreamSendFishingPacket = (tCPythonNetworkStreamSendFishingPacket)(Globals::pCPythonNetworkStreamSendFishingPacket);
	}
	if (pCPythonNetworkStreamSendFishingGlobalPacket != NULL)
	{
		CPythonNetworkStreamSendFishingGlobalPacket = (tCPythonNetworkStreamSendFishingGlobalPacket)(Globals::pCPythonNetworkStreamSendFishingGlobalPacket);
	}
	if (pCPythonNetworkStreamSendEmoticon != NULL)
	{
		CPythonNetworkStreamSendEmoticon = (tCPythonNetworkStreamSendEmoticon)(Globals::pCPythonNetworkStreamSendEmoticon);
	}
	if (pCPythonNetworkStreamSendItemPickUpPacket != NULL)
	{
		CPythonNetworkStreamSendItemPickUpPacket = (tCPythonNetworkStreamSendItemPickUpPacket)(pCPythonNetworkStreamSendItemPickUpPacket);;
	}
	if (pCInstanceBaseSetDirection != NULL)
	{
		CInstanceBaseSetDirection = (tCInstanceBaseSetDirection)(pCInstanceBaseSetDirection);
	}
	if (pCPythonPlayerNEW_GetMainActorPtr != NULL)
	{
		CPythonPlayerNEW_GetMainActorPtr = (tCPythonPlayerNEW_GetMainActorPtr)(pCPythonPlayerNEW_GetMainActorPtr);
	}
	if (pCInstanceBaseIsMountingHorse != NULL)
	{
		CInstanceBaseIsMountingHorse = (tCInstanceBaseIsMountingHorse)(pCInstanceBaseIsMountingHorse);
	}
	if (pCPythonNetworkStreamSendChatPacket != NULL)
	{
		CPythonNetworkStreamSendChatPacket = (tCPythonNetworkStreamSendChatPacket)(pCPythonNetworkStreamSendChatPacket);
	}
	if (pCPythonPlayerIsSkillCoolTime != NULL)
	{
		CPythonPlayerIsSkillCoolTime = (tCPythonPlayerIsSkillCoolTime)(pCPythonPlayerIsSkillCoolTime);
	}
	if (pCPythonPlayerClickSkillSlot != NULL)
	{
		CPythonPlayerClickSkillSlot = (tCPythonPlayerClickSkillSlot)(pCPythonPlayerClickSkillSlot);
	}
	if (pCPythonCharacterManagerGetInstancePtr != NULL)
	{
		CPythonCharacterManagerGetInstancePtr = (tCPythonCharacterManagerGetInstancePtr)(pCPythonCharacterManagerGetInstancePtr);
	}
	if (pCPythonNetworkStreamSendChatPacket != NULL)
	{
		CPythonNetworkStreamSendChatPacket = (tCPythonNetworkStreamSendChatPacket)(pCPythonNetworkStreamSendChatPacket);
	}
	if (pCPythonPlayerGetTargetVID != NULL)
	{
		CPythonPlayerGetTargetVID = (tCPythonPlayerGetTargetVID)(pCPythonPlayerGetTargetVID);
	}
	if (pCInstanceBaseGetNameString != NULL)
	{
		CInstanceBaseGetNameString = (tCInstanceBaseGetNameString)(pCInstanceBaseGetNameString);
	}
	if (pCPythonPlayerGetItemMetinSocket != NULL)
	{
		CPythonPlayerGetItemMetinSocket = (tCPythonPlayerGetItemMetinSocket)(pCPythonPlayerGetItemMetinSocket);
	}
	if (pCInstanceBaseGetInstanceType != NULL)
	{
		CInstanceBaseGetInstanceType = (tCInstanceBaseGetInstanceType)(pCInstanceBaseGetInstanceType);
	}
	
	if (pCPythonNetworkStreamSendExchangeStartPacket != NULL)
	{
		CPythonNetworkStreamSendExchangeStartPacket = (tCPythonNetworkStreamSendExchangeStartPacket)(pCPythonNetworkStreamSendExchangeStartPacket);
	}
	if (pCPythonNetworkStreamSendExchangeItemAddPacket != NULL)
	{
		CPythonNetworkStreamSendExchangeItemAddPacket = (tCPythonNetworkStreamSendExchangeItemAddPacket)(pCPythonNetworkStreamSendExchangeItemAddPacket);
	}
	if (pCPythonNetworkStreamSendExchangeAcceptPacket != NULL)
	{
		CPythonNetworkStreamSendExchangeAcceptPacket = (tCPythonNetworkStreamSendExchangeAcceptPacket)(pCPythonNetworkStreamSendExchangeAcceptPacket);
	}
	if (pCPythonPlayerGetMainCharacterIndex != NULL)
	{
		CPythonPlayerGetMainCharacterIndex = (tCPythonPlayerGetMainCharacterIndex)(pCPythonPlayerGetMainCharacterIndex);
	}
	if (pCPythonNetworkStreamSendUseSkillPacket != NULL)
	{
		CPythonNetworkStreamSendUseSkillPacket = (tCPythonNetworkStreamSendUseSkillPacket)(pCPythonNetworkStreamSendUseSkillPacket);
	}
	if (pCPythonNetworkStreamSendAddFlyTargetingPacket != NULL)
	{
		CPythonNetworkStreamSendAddFlyTargetingPacket = (tCPythonNetworkStreamSendAddFlyTargetingPacket)(pCPythonNetworkStreamSendAddFlyTargetingPacket);
	}
	if (pCPythonNetworkStreamSendShootPacket != NULL)
	{
		CPythonNetworkStreamSendShootPacket = (tCPythonNetworkStreamSendShootPacket)(pCPythonNetworkStreamSendShootPacket);
	}
	if (pCPythonPlayerGetStatus != NULL)
	{
		CPythonPlayerGetStatus = (tCPythonPlayerGetStatus)(pCPythonPlayerGetStatus);
	}
	if (pCInstanceBaseNEW_MoveToDestPixelPositionDirection != NULL)
	{
		CInstanceBaseNEW_MoveToDestPixelPositionDirection = (tCInstanceBaseNEW_MoveToDestPixelPositionDirection)(pCInstanceBaseNEW_MoveToDestPixelPositionDirection);
	}
	if (pCInstanceBaseNEW_GetPixelPosition != NULL)
	{
		CInstanceBaseNEW_GetPixelPosition = (tCInstanceBaseNEW_GetPixelPosition)(pCInstanceBaseNEW_GetPixelPosition);
	}
	if (pCPhysicsObjectIncreaseExternalForce != NULL)
	{
		CPhysicsObjectIncreaseExternalForce = (tCPhysicsObjectIncreaseExternalForce)(pCPhysicsObjectIncreaseExternalForce);
	}
	if (pCPythonPlayerGetRace != NULL)
	{
		CPythonPlayerGetRace = (tCPythonPlayerGetRace)(pCPythonPlayerGetRace);
	}
	if (pCPythonPlayerGetItemIndex != NULL)
	{
		CPythonPlayerGetItemIndex = (tCPythonPlayerGetItemIndex)(pCPythonPlayerGetItemIndex);
	}
	if (pCItemDataGetName != NULL)
	{
		CItemDataGetName = (tCItemDataGetName)(pCItemDataGetName);
	}
	if (pCItemManagerGetItemDataPointer != NULL)
	{
		CItemManagerGetItemDataPointer = (tCItemManagerGetItemDataPointer)(pCItemManagerGetItemDataPointer);
	}
	if (pCInstanceBaseNEW_SetPixelPosition != NULL)
	{
		CInstanceBaseNEW_SetPixelPosition = (tCInstanceBaseNEW_SetPixelPosition)(pCInstanceBaseNEW_SetPixelPosition);
	}
	if (pCPythonNetworkStreamSendItemDropPacketNew != NULL)
	{
		CPythonNetworkStreamSendItemDropPacketNew = (tCPythonNetworkStreamSendItemDropPacketNew)(pCPythonNetworkStreamSendItemDropPacketNew);
	}
	if (pCPythonNetworkStreamSendScriptAnswerPacket != NULL)
	{
		CPythonNetworkStreamSendScriptAnswerPacket = (tCPythonNetworkStreamSendScriptAnswerPacket)(pCPythonNetworkStreamSendScriptAnswerPacket);
	}
	if (pCPythonNetworkStreamSendOnClickPacket != NULL)
	{
		CPythonNetworkStreamSendOnClickPacket = (tCPythonNetworkStreamSendOnClickPacket)(pCPythonNetworkStreamSendOnClickPacket);
	}
	if (pCPythonPlayerReviveGlobal != NULL)
	{
		CPythonPlayerReviveGlobal = (tCPythonPlayerReviveGlobal)(pCPythonPlayerReviveGlobal);
	}
	if (pCInstanceBaseBlockMovement != NULL)
	{
		CInstanceBaseBlockMovement = (tCInstanceBaseBlockMovement)(pCInstanceBaseBlockMovement);
	}
	if (pCPythonPlayerIsSkillActive != NULL)
	{
		CPythonPlayerIsSkillActive = (tCPythonPlayerIsSkillActive)(pCPythonPlayerIsSkillActive);
	}
	if (pCPythonNetworkStreamSendItemMovePacket != NULL)
	{
		CPythonNetworkStreamSendItemMovePacket = (tCPythonNetworkStreamSendItemMovePacket)(pCPythonNetworkStreamSendItemMovePacket);
	}
	if (pCNetworkStreamSendSequence != NULL)
	{
		CNetworkStreamSendSequence = (tCNetworkStreamSendSequence)(pCNetworkStreamSendSequence);
	}
	if (pCPythonNetworkStreamSendCharacterStatePacket != NULL)
	{
		CPythonNetworkStreamSendCharacterStatePacket = (tCPythonNetworkStreamSendCharacterStatePacket)(pCPythonNetworkStreamSendCharacterStatePacket);
	}
	if (pCPythonNetworkStreamConnectGameServer != NULL)
	{
		CPythonNetworkStreamConnectGameServer = (tCPythonNetworkStreamConnectGameServer)(pCPythonNetworkStreamConnectGameServer);
	}
	if (pCNetworkStreamIsOnline != NULL)
	{
		CNetworkStreamIsOnline = (tCNetworkStreamIsOnline)(pCNetworkStreamIsOnline);
	}
	if (pCPythonApplicationRenderGame != NULL)
	{
		CPythonApplicationRenderGame = (tCPythonApplicationRenderGame)(pCPythonApplicationRenderGame);
	}
	if (pCPythonNetworkStreamGetMainActorSkillGroup != NULL)
	{
		CPythonNetworkStreamGetMainActorSkillGroup = (tCPythonNetworkStreamGetMainActorSkillGroup)(pCPythonNetworkStreamGetMainActorSkillGroup);
	}
	if (pCPythonNetworkStreamSendWhisperPacket != NULL)
	{
		CPythonNetworkStreamSendWhisperPacket = (tCPythonNetworkStreamSendWhisperPacket)(pCPythonNetworkStreamSendWhisperPacket);
	}
	if (pCPythonNetworkStreamSendSpecial != NULL)
	{
		CPythonNetworkStreamSendSpecial = (tCPythonNetworkStreamSendSpecial)(pCPythonNetworkStreamSendSpecial);
	}
	if (pCPythonNetworkStreamSendAttackPacket != NULL)
	{
		CPythonNetworkStreamSendAttackPacket = (tCPythonNetworkStreamSendAttackPacket)(pCPythonNetworkStreamSendAttackPacket);
	}
	if (pCInstanceBase__SetAffect != NULL)
	{
		CInstanceBase__SetAffect = (tCInstanceBase__SetAffect)(pCInstanceBase__SetAffect);
	}
	if (pCInstanceBaseAvoidObject != NULL)
	{
		CInstanceBaseAvoidObject = (tCInstanceBaseAvoidObject)(pCInstanceBaseAvoidObject);
	}
	if (pCPythonPlayer__OnPressActor != NULL)
	{
		CPythonPlayer__OnPressActor = (tCPythonPlayer__OnPressActor)(pCPythonPlayer__OnPressActor);
	}
	if (pCPythonPlayer__OnClickActor != NULL)
	{
		CPythonPlayer__OnClickActor = (tCPythonPlayer__OnClickActor)(pCPythonPlayer__OnClickActor);
	}
	if (pCInstanceBaseIsDead != NULL)
	{
		CInstanceBaseIsDead = (tCInstanceBaseIsDead)(pCInstanceBaseIsDead);
	}
	if (pCActorInstanceTestActorCollision != NULL)
	{
		CActorInstanceTestActorCollision = (tCActorInstanceTestActorCollision)(pCActorInstanceTestActorCollision);
	}
	if (pCInstanceBaseSCRIPT_SetPixelPosition != NULL)
	{
		CInstanceBaseSCRIPT_SetPixelPosition = (tCInstanceBaseSCRIPT_SetPixelPosition)(pCInstanceBaseSCRIPT_SetPixelPosition);
	}
	if (pCPythonPlayerNEW_SetSingleDIKKeyState != NULL)
	{
		CPythonPlayerNEW_SetSingleDIKKeyState = (tCPythonPlayerNEW_SetSingleDIKKeyState)(pCPythonPlayerNEW_SetSingleDIKKeyState);
	}

	if (pCPythonEventManagerRegisterEventSetFromString != NULL)
	{
		CPythonEventManagerRegisterEventSetFromString = (tCPythonEventManagerRegisterEventSetFromString)(pCPythonEventManagerRegisterEventSetFromString);
	}
	if (pCPythonApplicationProcess != NULL)
	{
		CPythonApplicationProcess = (tCPythonApplicationProcess)(pCPythonApplicationProcess);
	}
	if (pCInstanceBaseNEW_LookAtDestPixelPosition != NULL)
	{
		CInstanceBaseNEW_LookAtDestPixelPosition = (tCInstanceBaseNEW_LookAtDestPixelPosition)(pCInstanceBaseNEW_LookAtDestPixelPosition);
	}

	
	/*if (pCNetworkStreamPeek != NULL)
	{
		CNetworkStreamPeek = (tCNetworkStreamPeek)(pCNetworkStreamPeek);
	}*/
	if (pCPythonNetworkStreamServerCommand != NULL)
	{
		CPythonNetworkStreamServerCommand = (tCPythonNetworkStreamServerCommand)(pCPythonNetworkStreamServerCommand);
	}
	if (pCInstanceBaseGetRotation != NULL)
	{
		CInstanceBaseGetRotation = (tCInstanceBaseGetRotation)(pCInstanceBaseGetRotation);
	}
	if (pCPythonPlayerSetTarget != NULL)
	{
		CPythonPlayerSetTarget = (tCPythonPlayerSetTarget)(pCPythonPlayerSetTarget);
	}
	if (pCResourceManagerGetResourcePointer != NULL)
	{
		CResourceManagerGetResourcePointer = (tCResourceManagerGetResourcePointer)(pCResourceManagerGetResourcePointer);
	}
	if (pCGraphicImageGetTexturePointer != NULL) 
	{
		CGraphicImageGetTexturePointer = (tCResourceManagerGetTexturePointer)(pCGraphicImageGetTexturePointer);
	}
	if (pCGraphicTextureGetD3DTexture != NULL) 
	{
		CGraphicTextureGetD3DTexture = (tCResourceManagerGetD3DTexture)(pCGraphicTextureGetD3DTexture);
	}
	if (pCPythonNonPlayerGetTable != NULL) 
	{
		CPythonNonPlayerGetTable = (tCPythonNonPlayerGetTable)(pCPythonNonPlayerGetTable);
	}	
	if (pCPythonBackgroundGetWarpMapName != NULL) 
	{
		CPythonBackgroundGetWarpMapName = (tCPythonBackgroundGetWarpMapName)(pCPythonBackgroundGetWarpMapName);
	}
	if (pCPythonBackgroundLocalPositionToGlobalPosition != NULL) 
	{
		CPythonBackgroundLocalPositionToGlobalPosition = (tCPythonBackgroundLocalPositionToGlobalPosition)(pCPythonBackgroundLocalPositionToGlobalPosition);
	}
	if (pCPythonBackgroundGlobalPositionToMapInfo != NULL) 
	{
		CBackgroundGlobalPositionToMapInfo = (tCPythonBackgroundGlobalPositionToMapInfo)(pCPythonBackgroundGlobalPositionToMapInfo);
	}
	if (pCNetworkStreamGetAccountCharacterSlotDataz != NULL) 
	{
		CNetworkStreamGetAccountCharacterSlotDataz = (tCNetworkStreamGetAccountCharacterSlotDataz)(pCNetworkStreamGetAccountCharacterSlotDataz);
	}
	if (pCNetworkStreamConnect != NULL) 
	{
		CNetworkStreamConnect = (tCNetworkStreamConnect)(pCNetworkStreamConnect);
	}
	if (pCNetworkStream__DirectEnterMode_Set != NULL)
	{
		CNetworkStream__DirectEnterMode_Set = (tCNetworkStream__DirectEnterMode_Set)(pCNetworkStream__DirectEnterMode_Set);
	}
	if (pCPythonNetworkStreamSendRefinePacket != NULL) 
	{
		CPythonNetworkStreamSendRefinePacket = (tCPythonNetworkStreamSendRefinePacket)(pCPythonNetworkStreamSendRefinePacket);
	}
	if (pCPythonNetworkStreamSendShopSellPacketNew != NULL) 
	{
		CPythonNetworkStreamSendShopSellPacketNew = (tCPythonNetworkStreamSendShopSellPacketNew)(pCPythonNetworkStreamSendShopSellPacketNew);
	}
	if (pCPythonNetworkStreamSendShopBuyPacket != NULL) 
	{
		CPythonNetworkStreamSendShopBuyPacket = (tCPythonNetworkStreamSendShopBuyPacket)(pCPythonNetworkStreamSendShopBuyPacket);
	}
	if (pCPythonNetworkStreamSendShopEndPacket != NULL)
	{
		CPythonNetworkStreamSendShopEndPacket = (tCPythonNetworkStreamSendShopEndPacket)(pCPythonNetworkStreamSendShopEndPacket);
	}
	if (pCPythonNetworkStreamSendGiveItemPacket != NULL) 
	{
		CPythonNetworkStreamSendGiveItemPacket = (tCPythonNetworkStreamSendGiveItemPacket)(pCPythonNetworkStreamSendGiveItemPacket);
	}
	if (pCPythonApplicationOnUIRender != NULL)
	{
		CPythonApplicationOnUIRender = (tCPythonApplicationOnUIRender)(pCPythonApplicationOnUIRender);
	}
	if (pCInstanceBaseGetInstanceVirtualNumber != NULL)
	{
		CInstanceBaseGetInstanceVirtualNumber = (tCInstanceBaseGetInstanceVirtualNumber)(pCInstanceBaseGetInstanceVirtualNumber);
	}
	if (pCInputKeyboardUpdateKeyboard != NULL) {
		CInputKeyboardUpdateKeyboard = (tCInputKeyboardUpdateKeyboard)(pCInputKeyboardUpdateKeyboard);
	}
}

//#####################################################################################################################################}

