
#pragma once


class Globals
{
public:
	//######################################################################################################################################
	static map<DWORD, TCItemData*> itemProtoList;
	static map<DWORD, const char*> itemProtoNames;
	static map<DWORD, TGroundItemInstance*> groundItemList;

	static DWORD hEntryBaseAddress;
	static HMODULE hModule;
	static HWND mainHwnd;
	
	static vector<D3DVECTOR> farmCoords;
	//###############################   PLAYER

	typedef int (*tPyRun_SimpleStringFlags)(const char* command, int flags);
	typedef char* (*tPyString_AsString)(PyObject* op);
	typedef long (*tPyInt_AsLong)(PyObject* op);
	typedef PyObject* (*tPyTuple_GetItem)(PyObject* op,  Py_ssize_t i);	

	typedef DWORD(__thiscall* tCPythonPlayerGetRace)(void* This);
	typedef bool(__thiscall* tCPythonPlayerIsSkillCoolTime)(void* This, DWORD dwSlotIndex);
	typedef int(__thiscall* tCPythonPlayerGetStatus)(void* This, DWORD dwType);
	typedef const char* (__thiscall* tCPythonPlayerGetName)(void* This);
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
	typedef bool(__thiscall* tCPythonNetworkStreamSendFishingQuitPacket)(void* This, int count, float iRotation);
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

	typedef float(__thiscall* tCInstanceBaseGetRotation)(void* This)



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



	typedef bool(__thiscall* tCInstanceBaseIsWaiting)(void* This);
	typedef void(__thiscall* tCInstanceBaseSetRotation)(void* This,float fRotation);
	typedef bool(__thiscall* tCPythonNetworkStreamSendCommandPacket)(void* This, DWORD a1, DWORD a2,const char* a3);
	
	
	

	





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
	static DWORD pCPythonNetworkStreamSendFishingQuitPacket;
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
	//####################################
	static DWORD pCInstanceBaseIsWaiting;
	static DWORD pCInstanceBaseSetRotation;
	static DWORD pCPythonNetworkStreamSendCommandPacket;
public:
	//#####################################################################################################################################
	/*static tCNetworkStreamPeek CNetworkStreamPeek;*/

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
	static tCPythonNetworkStreamSendFishingQuitPacket CPythonNetworkStreamSendFishingQuitPacket;
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
	static tCPythonPlayerGetName CPythonPlayerGetName;
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
	static tCInstanceBaseIsWaiting CInstanceBaseIsWaiting;
	static tCInstanceBaseSetRotation CInstanceBaseSetRotation;
	static tCPythonNetworkStreamSendCommandPacket CPythonNetworkStreamSendCommandPacket;




	//#####################################################################################################################################

	static tPyRun_SimpleStringFlags PyRun_SimpleStringFlags;
	static tPyString_AsString PyString_AsString;
	static tPyTuple_GetItem PyTuple_GetItem;
	static tPyInt_AsLong PyInt_AsLong;
	

	static void ReAddressingLocas();
	static void ReDeclarationLocals();
};
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



map<DWORD, TCItemData*> Globals::itemProtoList;
map<DWORD, TGroundItemInstance*> Globals::groundItemList;
map<DWORD, const char*>  Globals::itemProtoNames;

HMODULE	Globals::hModule = NULL;
DWORD	Globals::hEntryBaseAddress = (DWORD)GetModuleHandle(NULL);

HWND Globals::mainHwnd;

vector<D3DVECTOR> Globals::farmCoords;








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
DWORD Globals::pCPythonNetworkStreamSendFishingQuitPacket = NULL;
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
//#############################################
DWORD Globals::pCInstanceBaseIsWaiting = NULL;
DWORD Globals::pCInstanceBaseSetRotation = NULL;
DWORD Globals::pCPythonNetworkStreamSendCommandPacket = NULL;





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
Globals::tCPythonNetworkStreamSendFishingQuitPacket Globals::CPythonNetworkStreamSendFishingQuitPacket = NULL;
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
Globals::tCPythonPlayerGetName Globals::CPythonPlayerGetName = NULL;
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
//################################
Globals::tCInstanceBaseIsWaiting Globals::CInstanceBaseIsWaiting = NULL;
Globals::tCInstanceBaseSetRotation Globals::CInstanceBaseSetRotation = NULL;
Globals::tCPythonNetworkStreamSendCommandPacket Globals::CPythonNetworkStreamSendCommandPacket = NULL;
//####Globals::#################################################################################################################################

Globals::tPyRun_SimpleStringFlags Globals::PyRun_SimpleStringFlags = NULL;
Globals::tPyString_AsString Globals::PyString_AsString = NULL;
Globals::tPyTuple_GetItem Globals::PyTuple_GetItem = NULL;
Globals::tPyInt_AsLong Globals::PyInt_AsLong = NULL;

void Globals::ReAddressingLocas()
{

#ifdef  VIDGAR

	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x2ddaa4c; // [100 ] [104 / 104]
	pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x2dd165c; // [100 ] [65 / 65]
	pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x2dd164c; // [100 ] [41 / 41]
	pCItemManagerInstance = Globals::hEntryBaseAddress + 0x2dd1664; // [100 ] [50 / 50]
	pCPythonItemInstance = Globals::hEntryBaseAddress + 0x2ddaa74; // [100 ] [7 / 7]
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x2DDCD38; // [100 ] [72 / 72]
	pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x2dd1650; // [100 ] [7 / 7]
	pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x2dd1658; // [100 ] [130 / 130]
	pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x2ddaa30; // [100 ] [4 / 4]
	pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x303bc0; // [100 ] [1 / 1]
	pCPythonBackgroundGetWarpMapName = Globals::hEntryBaseAddress + 0x191390; // [100 ] [2 / 2]
	pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x191300; // [100 ] [2 / 2]
	pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x3037c0; // [100 ] [2 / 2]
	pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x16bf70; // [100 ] [1 / 1]
	pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x16acc0; // [100 ] [2 / 2]
	pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x16ad70; // [100 ] [2 / 2]
	pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x16ac80; // [100 ] [2 / 2]
	pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x18b8e0; // [100 ] [2 / 2]
	pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x16bcf0; // [100 ] [2 / 2]
	pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x16b940; // [100 ] [2 / 2]
	pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x18b820; // [100 ] [2 / 2]
	pCInstanceBaseNEW_LookAtDestPixelPosition = Globals::hEntryBaseAddress + 0x17f030; // [100 ] [2 / 2]
	pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x18b100; // [100 ] [2 / 2]
	pCInstanceBaseNEW_SetPixelPosition = Globals::hEntryBaseAddress + 0x18b780; // [100 ] [2 / 2]
	pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x18b7a0; // [100 ] [2 / 2]
	pCInstanceBaseSetDirection = Globals::hEntryBaseAddress + 0x18b990; // [100 ] [2 / 2]
	pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x182c10; // [100 ] [2 / 2]
	pCItemDataGetName = Globals::hEntryBaseAddress + 0x2f9560; // [100 ] [2 / 2]
	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x309830; // [100 ] [2 / 2]
	pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x18f610; // [100 ] [2 / 2]
	pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x2b1620; // [50 ] [1 / 2]

	pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x24f480; // [100 ] [2 / 2]
	pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x24e840; // [100 ] [2 / 2]
	pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x2b17f0; // [100 ] [2 / 2]
	pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x2b1860; // [100 ] [2 / 2]
	pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x2b1a70; // [100 ] [2 / 2]
	pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x2b1ab0; // [100 ] [2 / 2]
	pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x2b1b30; // [100 ] [2 / 2]
	pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x31d710; // [100 ] [2 / 2]

	pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x22e120; // [100 ] [2 / 2]
	pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x22d9f0; // [100 ] [2 / 2]
	pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x19b770; // [100 ] [2 / 2]
	pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x1fafa0; // [100 ] [2 / 2]
	pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x1a71d0; // [100 ] [2 / 2]
	pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x24e9c0; // [100 ] [2 / 2]
	pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x24ebe0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x259760; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x258e90; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x258ef0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x25ae20; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x24e3a0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x259330; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x2591d0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x259150; // [100 ] [2 / 2]

	pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x25a560; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x25a5c0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x265b80; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x265c00; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x265de0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x2658e0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x259680; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x25a7b0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x259460; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x2597e0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x265fd0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x265f70; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x266100; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x258be0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x259000; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x25af40; // [100 ] [2 / 2]
	pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x250e80; // [100 ] [2 / 2]
	pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x1c2170; // [100 ] [2 / 2]
	pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x1d8850; // [100 ] [2 / 2]
	pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x1c6d50; // [100 ] [2 / 2]
	pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x1c7010; // [100 ] [2 / 2]
	pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x1c63f0; // [100 ] [2 / 2]
	pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x1c6620; // [100 ] [2 / 2]
	pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x1c6680; // [100 ] [2 / 2]
	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x1c6880; // [100 ] [2 / 2]
	pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x1ce120; // [100 ] [2 / 2]
	pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x1c7e30; // [100 ] [2 / 2]
	pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x1c7e60; // [100 ] [2 / 2]
	pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x1cdb20; // [100 ] [2 / 2]
	pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x1c5c70; // [100 ] [2 / 2]
	pCPythonPlayerNEW_SetSingleDIKKeyState = Globals::hEntryBaseAddress + 0x1cf260; // [100 ] [2 / 2]
	pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x1cf130; // [100 ] [2 / 2]
	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x1cde90; // [100 ] [2 / 2]
	pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x1ce400; // [100 ] [2 / 2]
	pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x1ce210; // [100 ] [2 / 2]
	pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x2b69e0; // [100 ] [2 / 2]
	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x2a6210; // [100 ] [2 / 2]
	pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x2c5c10; // [100 ] [2 / 2]
	pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x357970; // [100 ] [2 / 2]
	pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x232810; // [100 ] [2 / 2]
	pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x2DDF2DC;
	pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x2b2080; // [100 ] [1 / 1]
#endif
#ifdef FORNAX
	pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x134150;
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x1DC1E84; // [98 %] [56 / 57]

#endif
#ifdef DREIKON
#endif

#ifdef PANGEA

	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x32e40a4; // [100 ] [52 / 52]
	pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x32e40d0; // [100 ] [15 / 15]
	pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x32e40b0; // [100 ] [7 / 7]
	pCItemManagerInstance = Globals::hEntryBaseAddress + 0x32e4128; // [100 ] [30 / 30]
	pCPythonItemInstance = Globals::hEntryBaseAddress + 0x32ec0d8; // [100 ] [2 / 2]
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x32EC0E8;
	pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x32e4118; // [100 ] [1 / 1]
	pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x32e4120; // [98 ] [65 / 66]
	pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x32E40B8; // [100 ] [1 / 1]
	pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x222eb0; // [100 ] [1 / 1]
	pCPythonBackgroundGetWarpMapName = Globals::hEntryBaseAddress + 0x127f60; // [100 ] [1 / 1]
	pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x127fa0; // [100 ] [1 / 1]
	pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x2229c0; // [100 ] [1 / 1]
	pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0xf6d30; // [100 ] [1 / 1]
	pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0xf7eb0; // [100 ] [1 / 1]
	pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0xf80c0; // [100 ] [1 / 1]
	pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0xf8020; // [100 ] [1 / 1]
	pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x104080; // [100 ] [1 / 1]
	pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0xf84f0; // [100 ] [1 / 1]
	pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0xf93a0; // [100 ] [1 / 1]
	pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x104090; // [100 ] [1 / 1]
	pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x103a20; // [100 ] [1 / 1]
	pCInstanceBaseNEW_SetPixelPosition = Globals::hEntryBaseAddress + 0x104130; // [100 ] [1 / 1]
	pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x104140; // [100 ] [1 / 1]
	pCInstanceBaseSetDirection = Globals::hEntryBaseAddress + 0x1041a0; // [100 ] [1 / 1]
	pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x102540; // [100 ] [1 / 1]
	pCItemDataGetName = Globals::hEntryBaseAddress + 0x218200; // [50 ] [1 / 2]
	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x2262f0; // [100 ] [1 / 1]
	pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x128220; // [100 ] [1 / 1]
	pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x1c77e0; // [100 ] [1 / 1]
	pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x157260; // [100 ] [1 / 1]
	pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x156970; // [100 ] [1 / 1]
	pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x1c7900; // [100 ] [1 / 1]
	pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x1c7970; // [100 ] [1 / 1]
	pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x1c7b80; // [100 ] [1 / 1]
	pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x1c7bc0; // [100 ] [1 / 1]
	pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x1c7c40; // [100 ] [1 / 1]
	pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x23ee20; // [100 ] [1 / 1]
	pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x11fc40; // [100 ] [1 / 1]
	pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x120370; // [100 ] [1 / 1]
	pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x12dbf0; // [100 ] [1 / 1]
	pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x135060; // [100 ] [1 / 1]
	pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x13e650; // [100 ] [1 / 1]
	pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x156750; // [100 ] [1 / 1]
	pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x156a70; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x165100;
	pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x1632a0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x163540; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x1636b0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x156d70; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x163c00; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x163d30; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x163db0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x163e40; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x163f30; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x167b50; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x167bd0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x167d00; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x167d60; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x164890; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x164c90; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x164f10; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x164ff0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x1684b0; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x168530; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x168600; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x165040; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x165150; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x1651c0; // [100 ] [2 / 2]
	pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x1575e0; // [100 ] [1 / 1]
	pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x16b4e0; // [100 ] [1 / 1]
	pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x178270; // [100 ] [1 / 1]
	pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x16DF80;
	pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x16dfe0; // [100 ] [1 / 1]
	pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x16e070; // [100 ] [1 / 1]
	pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x16e080; // [100 ] [1 / 1]
	pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x16e140; // [100 ] [1 / 1]
	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x16e300; // [100 ] [1 / 1]
	pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x172000; // [100 ] [1 / 1]
	pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x16e7d0; // [100 ] [1 / 1]
	pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x16e800; // [100 ] [1 / 1]
	pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x171690; // [100 ] [1 / 1]
	pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x16eba0; // [100 ] [1 / 1]
	pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x172890; // [100 ] [1 / 1]
	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x171bb0; // [100 ] [1 / 1]
	pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x172090;
	pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x172190; // [100 ] [1 / 1]
	pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x1f1820; // [100 ] [1 / 1]
	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x1d0d40; // [100 ] [1 / 1]
	pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x1d40d0; // [100 ] [1 / 1]
	pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x276240; // [100 ] [1 / 1]
	pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x122D50; // [100 ] [1 / 1]
	pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x32EF55C;
	pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x1e6d40; // [100 ] [1 / 1]

	pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x103760;
	pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x1041E0;


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


	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x635124; // [100 ] [103 / 103]
	pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x635344; // [100 ] [93 / 93]
	pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x635130; // [100 ] [42 / 42]
	pCItemManagerInstance = Globals::hEntryBaseAddress + 0x6353c0; // [100 ] [50 / 50]
	pCPythonItemInstance = Globals::hEntryBaseAddress + 0x63b078; // [100 ] [7 / 7]
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x63B0D4; // [100 ] [59 / 59]
	pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x6353ac; // [100 ] [6 / 6]
	pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x6353b4; // [100 ] [129 / 129]
	pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x63529c; // [100 ] [4 / 4]
	pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x30C3A0; // [100 ] [3 / 3]
	pCPythonBackgroundGetWarpMapName = Globals::hEntryBaseAddress + 0x150940; // [100 ] [1 / 1]
	pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x1e254; // [100 ] [1 / 1]
	pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0xfaf70; // [100 ] [1 / 1]
	pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x14f10; // [100 ] [3 / 3]
	pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x9c64; // [100 ] [1 / 1]
	pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0xF9780;
	pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0xead4; // [100 ] [2 / 2]
	pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x21f58; // [100 ] [1 / 1]
	pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0xb893; // [80 ] [4 / 5] 
	pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0xa006; // [100 ] [1 / 1]
	pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0xfdda; // [100 ] [4 / 4]
	pCInstanceBaseNEW_LookAtDestPixelPosition = Globals::hEntryBaseAddress + 0x11e660; // [100 ] [1 / 1] 
	pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x1b45; // [100 ] [1 / 1]
	pCInstanceBaseNEW_SetPixelPosition = Globals::hEntryBaseAddress + 0x23c18; // [100 ] [1 / 1]
	pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0xee17; // [100 ] [1 / 1]
	pCInstanceBaseSetDirection = Globals::hEntryBaseAddress + 0x136ba; // [100 ] [1 / 1]
	pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x1106a0; // [100 ] [1 / 1]
	pCItemDataGetName = Globals::hEntryBaseAddress + 0x11b8; // [100 ] [8 / 8]
	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x275c; // [75 ] [3 / 4]
	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x30ff80; // [25 ] [1 / 4]
	pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x1cb0c; // [100 ] [1 / 1]
	pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x1C8FF; // [100 ] [1 / 1]
	pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x1C8680;
	pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x1C7A30;
	pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x5718; // [100 ] [1 / 1]
	//pCNetworkStreamPeek = Globals::hEntryBaseAddress + (null); 
	pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x284AF0;
	pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x284B40;
	pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x11f0e; // [100 ] [21 / 21]
	pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x113fb; // [100 ] [1 / 1]
	pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x141300; // [100 ] [1 / 1]
	pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x140bd0; // [94 ] [17 / 18]
	pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x1dde0; // [100 ] [29 / 29]
	pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0xbed8; // [100 ] [1 / 1]
	pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x876a; // [100 ] [1 / 1]
	pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x18737; // [100 ] [1 / 1]
	pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x1c7df0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x1d5de0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x1d4cb0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x1d4d10; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x16b08; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0xb27b; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x22f02; // [50 ] [1 / 2]
	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x1d51e0; // [50 ] [1 / 2]
	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x2212e; // [50 ] [1 / 2]
	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x1d5080; // [50 ] [1 / 2]
	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x1f537; // [33 ] [1 / 3]
	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x1d5000; // [66 ] [2 / 3]
	pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x1774c; // [75 ] [3 / 4] 
	pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x1007d; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x1ebfa; // [100 ] [2 / 2]
	pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x138f4; // [50 ] [1 / 2]
	pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x1e7c20; // [50 ] [1 / 2]
	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x7a0e; // [50 ] [1 / 2]
	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x1e7dd0; // [50 ] [1 / 2]
	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x22719; // [50 ] [1 / 2]
	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x1e78e0; // [50 ] [1 / 2]
	pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x1d5b10; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0xf0d8; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x1d5310; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x1d5e60; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x1577b; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0xefa2; // [50 ] [1 / 2]
	pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x1e7f60; // [50 ] [1 / 2]
	pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x1b171; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x1d4a00; // [50 ] [1 / 2]
	pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x1d4e70; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x175df; // [100 ] [1 / 1]
	pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x1cace0; // [100 ] [24 / 24]
	pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x14f15; // [100 ] [2 / 2]
	pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x1c95e; // [100 ] [1 / 1]
	pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x1b43c; // [100 ] [6 / 6]
	pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x1b199; // [100 ] [1 / 1]
	pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x10ab9; // [100 ] [1 / 1]
	pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x1e849; // [100 ] [3 / 3]
	pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xf920; // [100 ] [2 / 2]
	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xf22c; // [80 ] [4 / 5]
	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x1f6c40; // [20 ] [1 / 5]
	pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x1d0bb; // [100 ] [1 / 1]
	pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x1e196; // [100 ] [1 / 1]
	pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xa844; // [100 ] [1 / 1]
	pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x2011c0; // [100 ] [1 / 1]
	pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x14182; // [100 ] [13 / 13]
	pCPythonPlayerNEW_SetSingleDIKKeyState = Globals::hEntryBaseAddress + 0x94b2; // [100 ] [1 / 1]
	pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x7ed7; // [100 ] [1 / 1]
	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x25f9; // [100 ] [2 / 2]
	pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x201ab0; // [50 ] [1 / 2]
	pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x2018d0; // [50 ] [1 / 2]
	pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x3314; // [75 ] [3 / 4]
	pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x2b3400; // [25 ] [1 / 4]
	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x70ea; // [75 ] [3 / 4]
	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x28f290; // [25 ] [1 / 4]
	pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x291d30; // [100 ] [1 / 1]
	pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x372780;
	pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x147ea0; // [100 ] [1 / 1]
	pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x640824;
	pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x2A7BE0;
#endif

#ifdef   EGORIA
#endif

#ifdef IVEYA
#endif

#ifdef AELDRA
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
#endif

#ifdef ELITEMT2
#endif

#ifdef AVENTUS2
#endif

#ifdef CLASSIC
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
	for (p = NULL; VirtualQueryEx(process, p, &info, sizeof(info)) == sizeof(info); p += info.RegionSize)
	{
		if ((info.State == MEM_COMMIT) && ((info.Type & MEM_MAPPED) || (info.Type & MEM_PRIVATE)) && info.Protect == 0x40) {
			if (info.RegionSize >= 0x02000000) {
				Globals::hEntryBaseAddress = (DWORD)info.BaseAddress;
			}
		}
	}
	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x1e9e5d8; // [100 ] [1 / 1]
	pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x1e9b284; // [100 ] [1 / 1]
	pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x1e9b280; // [100 ] [1 / 1]
	pCItemManagerInstance = Globals::hEntryBaseAddress + 0x1e9b27c; // [100 ] [1 / 1]
	pCPythonItemInstance = Globals::hEntryBaseAddress + 0x1e9e6a8; // [100 ] [1 / 1]
	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x1ea0934; // [100 ] [1 / 1]
	pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x1e9b28c; // [100 ] [1 / 1]
	pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x1e9b278; // [100 ] [1 / 1]
	pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x1e9e664; // [100 ] [1 / 1]
	pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x390fc0; // [100 ] [1 / 1]
	pCPythonBackgroundGetWarpMapName = Globals::hEntryBaseAddress + 0x775f0; // [100 ] [1 / 1]
	pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x76ad0; // [100 ] [1 / 1]
	pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x54cb0; // [100 ] [1 / 1]
	pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x54c70; // [100 ] [1 / 1]
	pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x598a0; // [100 ] [1 / 1]
	pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x598f0; // [100 ] [1 / 1]
	pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x58e50; // [100 ] [1 / 1]
	pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x73140; // [100 ] [1 / 1]
	pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x56a80; // [100 ] [1 / 1]
	pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x56590; // [100 ] [1 / 1]
	pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x73030; // [100 ] [1 / 1]
	pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x72b80; // [100 ] [1 / 1]
	pCInstanceBaseNEW_SetPixelPosition = Globals::hEntryBaseAddress + 0x73010; // [100 ] [1 / 1]
	pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x72fc0; // [100 ] [1 / 1]
	pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x6a250; // [100 ] [1 / 1]
	pCItemDataGetName = Globals::hEntryBaseAddress + 0x393930; // [100 ] [1 / 1]
	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x3960a0; // [100 ] [1 / 1]
	pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x76a10; // [100 ] [1 / 1]
	pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x419bd0; // [100 ] [1 / 1]
	pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x1dd6f0; // [100 ] [1 / 1]
	pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x1db840; // [100 ] [1 / 1]
	pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x419a40; // [100 ] [1 / 1]
	pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x4199f0; // [100 ] [1 / 1]
	pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x41a080; // [100 ] [1 / 1]
	pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x41a0b0; // [100 ] [1 / 1]
	pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x41a120; // [100 ] [1 / 1]
	pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x3b8e90; // [100 ] [1 / 1]
	pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x1b85f0; // [100 ] [1 / 1]
	pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x1b7ab0; // [100 ] [1 / 1]
	pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x834a0; // [100 ] [1 / 1]
	pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x149b50; // [100 ] [1 / 1]
	pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x99d10; // [100 ] [1 / 1]
	pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x1db920; // [100 ] [1 / 1]
	pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x1dd640; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x1f2060; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x1f1bd0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x1ec2d0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x1ec490; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x200790; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x1f0fa0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x1f0f00; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x1f0dd0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendFishingQuitPacket = Globals::hEntryBaseAddress + 0x1f6c20; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x1f6bd0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x1f88c0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x20e770; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x20e980; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x20ebe0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x20e570; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x1ee500; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x1f7720; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x1f1310; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x1f2000; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x20e3d0; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x20e370; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x20e480; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x1f1c30; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x1ec440; // [100 ] [1 / 1]
	pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x1ede60; // [100 ] [1 / 1]
	pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x1dea60; // [100 ] [1 / 1]
	pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xe3970; // [100 ] [1 / 1]
	pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x11b5a0; // [100 ] [1 / 1]
	pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xed350; // [100 ] [1 / 1]
	pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0xed860; // [100 ] [1 / 1]
	pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xec6e0; // [100 ] [1 / 1]
	pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xecf00; // [100 ] [1 / 1]
	pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xec850; // [100 ] [1 / 1]
	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xecec0; // [100 ] [1 / 1]
	pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x103780; // [100 ] [1 / 1]
	pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xeefa0; // [100 ] [1 / 1]
	pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xeef70; // [100 ] [1 / 1]
	pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x1043f0; // [100 ] [1 / 1]
	pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xec1e0; // [100 ] [1 / 1]
	pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x1052d0; // [100 ] [1 / 1]
	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x1037e0; // [100 ] [1 / 1]
	pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x103c90; // [100 ] [1 / 1]
	pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x103dd0; // [100 ] [1 / 1]
	pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x41cd70; // [100 ] [1 / 1]
	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x408090; // [100 ] [1 / 1]
	pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x42fb80; // [100 ] [1 / 1]
	pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x453890; // [100 ] [1 / 1]
	pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x3ff070; // [100 ] [1 / 1]
	pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x1EA7988;
	pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x41a900; // [100 ] [1 / 1]

	pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x72A40;
	pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x73060;
	pCPythonNetworkStreamSendCommandPacket = Globals::hEntryBaseAddress + 0x201690;
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
#endif

}

void Globals::ReDeclarationLocals()
{
	

#ifdef PYTHON_CUSTOM
	 Globals::PyRun_SimpleStringFlags = (tPyRun_SimpleStringFlags)PatternScan::FindPattern("55 8B EC 83 EC ? 68 ? ? ? ? E8 ? ? ? ? 83 C4 ? 89 45 ? 83 7D ? ? 75 ? 83 C8");
	 Globals::PyString_AsString = (tPyString_AsString)PatternScan::FindPattern("55 8B EC 8B 45 ? 8B 48 ? 8B 51 ? 81 E2 ? ? ? ? 75 ? 8B 45 ? 50 E8 ? ? ? ? 83 C4 ? EB ? 8B 45");
	 Globals::PyTuple_GetItem = (tPyTuple_GetItem)PatternScan::FindPattern("55 8B EC 8B 45 ? 8B 48 ? 8B 51 ? 81 E2 ? ? ? ? 75 ? 6A ? 68 ? ? ? ? E8 ? ? ? ? 83 C4 ? 33 C0");
	 Globals::PyInt_AsLong = (tPyInt_AsLong)PatternScan::FindPattern("55 8B EC 83 EC ? 83 7D ? ? 74 ? 8B 45 ? 8B 48 ? 8B 51 ? 81 E2 ? ? ? ? 74 ? 8B 45 ? 8B 40 ? E9 ? ? ? ? 83 7D ? ? 74 ? 8B 4D ? 8B 51 ? 8B 42 ? 89 45");
#else
	 Globals::PyRun_SimpleStringFlags = (tPyRun_SimpleStringFlags)GetProcAddress(GetModuleHandle("python27.dll"), "PyRun_SimpleString");
	 Globals::PyString_AsString = (tPyString_AsString)GetProcAddress(GetModuleHandle("python27.dll"), "PyString_AsString");
	 Globals::PyTuple_GetItem = (tPyTuple_GetItem)GetProcAddress(GetModuleHandle("python27.dll"), "PyTuple_GetItem");
	 Globals::PyInt_AsLong = (tPyInt_AsLong)GetProcAddress(GetModuleHandle("python27.dll"), "PyInt_AsLong");
	 
#endif




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
	if (pCPythonNetworkStreamSendFishingQuitPacket != NULL)
	{
		CPythonNetworkStreamSendFishingQuitPacket = (tCPythonNetworkStreamSendFishingQuitPacket)(Globals::pCPythonNetworkStreamSendFishingQuitPacket);
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
	
	if (pCPythonPlayerGetName != NULL)
	{
		CPythonPlayerGetName = (tCPythonPlayerGetName)(pCPythonPlayerGetName);
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
	if (pCInputKeyboardUpdateKeyboard != NULL)
	{
		CInputKeyboardUpdateKeyboard = (tCInputKeyboardUpdateKeyboard)(pCInputKeyboardUpdateKeyboard);
	}
	//#################################################################################
	if (pCInstanceBaseIsWaiting != NULL)
	{
		CInstanceBaseIsWaiting = (tCInstanceBaseIsWaiting)(pCInstanceBaseIsWaiting);
	}

	if (pCInstanceBaseSetRotation != NULL)
	{
		CInstanceBaseSetRotation = (tCInstanceBaseSetRotation)(pCInstanceBaseSetRotation);
	}
	if (pCPythonNetworkStreamSendCommandPacket != NULL)
	{
		CPythonNetworkStreamSendCommandPacket = (tCPythonNetworkStreamSendCommandPacket)(pCPythonNetworkStreamSendCommandPacket);
	}
	
}

//#####################################################################################################################################}

