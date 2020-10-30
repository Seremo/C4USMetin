
#pragma once


class Globals
{
public:
	//######################################################################################################################################
	static ServerName Server;
	static bool UsePythonFunctions;
	
	static map<DWORD, TCItemData*> itemProtoList;
	static map<DWORD, const char*> itemProtoNames;
	static map<DWORD, TGroundItemInstance*> groundItemList;

	static DWORD hEntryBaseAddress;
	static HMODULE hModule;
	static HWND mainHwnd;
	
	static vector<D3DVECTOR> farmCoords;


	static PyObject* m_apoPhaseWndGame;
	//###############################   PLAYER

	typedef int (*tPyRun_SimpleStringFlags)(const char* command, int flags);
	typedef char* (*tPyString_AsString)(PyObject* op);
	typedef long (*tPyInt_AsLong)(PyObject* op);
	typedef PyObject* (*tPyTuple_GetItem)(PyObject* op,  Py_ssize_t i);	
	typedef PyObject* (*tPy_BuildValue)(char* format, ...);

	typedef DWORD(__thiscall* tCPythonPlayerGetRace)(void* This);
	typedef bool(__thiscall* tCPythonPlayerIsSkillCoolTime)(void* This, DWORD dwSlotIndex);
	typedef int(__thiscall* tCPythonPlayerGetStatus)(void* This, DWORD dwType);
	typedef const char* (__thiscall* tCPythonPlayerGetName)(void* This);
	typedef void(__thiscall* tCPythonPlayerClickSkillSlot)(void* This, DWORD dwSlotIndex);
	typedef DWORD(__thiscall* tCPythonPlayerGetItemIndex)(void* This, TItemPos Cell);
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
	typedef bool(__thiscall* tCNetworkStreamSendAeldra)(void* This, int len, void* pDestBuf, bool instant);
	//typedef int(__stdcall* tCNetworkStreamSendAeldra)(SOCKET s, const char* pDestBuf, int len, int flags);
	typedef bool(__thiscall* tCNetworkStreamCheckPacket)(void* This, BYTE* header);

	typedef bool(__thiscall* tCNetworkStreamIsOnline)(void* This);
	
	typedef void(__thiscall* tCPythonNetworkStreamConnectGameServer)(void* This, UINT iChrSlot);

	typedef bool(__thiscall* tCPythonNetworkStreamSendItemUsePacket)(void* This, TItemPos pos);

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
	typedef bool(__thiscall* tCPythonNetworkStreamSendShopSellPacketNew)(void* This, BYTE bySlot, BYTE byCount);
	typedef bool(__thiscall* tCPythonNetworkStreamSendShopBuyPacket)(void* This, BYTE bPos);
	typedef bool(__thiscall* tCPythonNetworkStreamSendShopEndPacket)(void* This);
	

	typedef bool(__thiscall* tCPythonNetworkStreamSendRefinePacket)(void* This, BYTE byPos, BYTE byType);
	typedef bool(__thiscall* tCPythonNetworkStreamSendItemMovePacket)(void* This, TItemPos pos, TItemPos change_pos, BYTE num);
	
	
	typedef bool(__thiscall* tCPythonNetworkStreamSendCharacterStatePacket)(void* This, const D3DVECTOR& c_rkPPosDst, float fDstRot, UINT eFunc, UINT uArg);
	
	typedef void(__thiscall* tCPythonNetworkStreamServerCommand)(void* This, const char * c_szCommand);
	
	typedef bool(__thiscall* tCPythonNetworkStreamSendGiveItemPacket)(void* This, DWORD dwTargetVID, TItemPos ItemPos, int iItemCount);
	//############################### INSTANCE
	typedef bool(__thiscall* tCInstanceBaseIsMountingHorse)(void* This);
	typedef void(__thiscall* tCInstanceBaseNEW_GetPixelPosition)(DWORD* instance, D3DVECTOR * pPixelPosition);
	typedef bool(__thiscall* tCInstanceBaseNEW_MoveToDestPixelPositionDirection)(DWORD* instance, D3DVECTOR & c_rkPPosDst);

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

	typedef float(__thiscall* tCInstanceBaseGetRotation)(void* This);
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
	

	typedef void(__thiscall* tCPythonBackgroundLocalPositionToGlobalPosition)(void* This, LONG& rLocalX, LONG& rLocalY);
	typedef TMapInfo* (__thiscall* tCPythonBackgroundGlobalPositionToMapInfo)(void* This, DWORD dwGlobalX, DWORD dwGlobalY);
	typedef const char* (__thiscall* tCNetworkStreamGetAccountCharacterSlotDataz)(void* This, UINT iSlot, UINT eType);
	typedef void(__thiscall* tCPythonApplicationOnUIRender)(void* This);
	typedef void(__thiscall* tCInputKeyboardUpdateKeyboard)(void* This);



	typedef bool(__thiscall* tCInstanceBaseIsWaiting)(void* This);
	typedef void(__thiscall* tCInstanceBaseSetRotation)(void* This,float fRotation);
	typedef bool(__thiscall* tCPythonNetworkStreamSendCommandPacket)(void* This, DWORD a1, DWORD a2,const char* a3);
	typedef float(__cdecl* tCInstanceBase__GetBackgroundHeight)(float x, float y);


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
	static DWORD pCInstanceBaseSCRIPT_SetPixelPosition;
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
	static DWORD pCInstanceBase__GetBackgroundHeight;

	//python only
	//player
	static DWORD CythonPlayerGetStatus;
	static DWORD CythonPlayerGetMainCharacterIndex;
	static DWORD CythonPlayerGetItemIndex;
	static DWORD CythonPlayerGetName;
	static DWORD CythonPlayerGetItemMetinSocket;
	static DWORD CythonPlayerGetRace;
	static DWORD CythonPlayerSetSingleDIKKeyState;
	static DWORD CythonPlayerClickSkillSlot;
	static DWORD CythonPlayerIsSkillCoolTime;
	static DWORD CythonPlayerIsSkillActive;
	static DWORD CythonPlayerGetTargetVID;
	static DWORD CythonPlayerSetTarget;
	static DWORD CythonPlayerSetAttackKeyState;
	static DWORD CythonPlayerIsMountingHorse;
	//chr
	static DWORD CythonChrSelectInstance;
	static DWORD CythonChrGetPixelPosition;
	static DWORD CythonChrMoveToDestPosition;
	static DWORD CythonChrGetInstanceType;
	static DWORD CythonChrGetVirtualNumber;
	static DWORD CythonChrGetNameByVID;
	static DWORD CythonChrSetPixelPosition;
	static DWORD CythonChrSetRotation;
	static DWORD CythonChrGetRotation;
	static DWORD CythonChrmgrSetAffect;
	//net
	static DWORD CythonNetSendItemUsePacket;
	static DWORD CythonNetSendChatPacket;
	static DWORD CythonNetSendRefinePacket;
	static DWORD CythonNetSendExchangeStartPacket;
	static DWORD CythonNetSendExchangeItemAddPacket;
	static DWORD CythonNetSendExchangeAcceptPacket;
	static DWORD CythonNetSendWhisperPacket;
	static DWORD CythonNetSendItemPickUpPacket;
	static DWORD CythonNetSendItemDropPacketNew;
	static DWORD CythonNetSendOnClickPacket;
	static DWORD CythonNetSendShopSellPacketNew;
	static DWORD CythonNetSendShopBuyPacket;
	static DWORD CythonNetSendShopEndPacket;
	static DWORD CythonNetSendGiveItemPacket;
	static DWORD CythonNetSendItemMovePacket;
	static DWORD CythonNetDirectEnter;
	static DWORD CythonNetConnectTCP;
	static DWORD CythonNetIsConnect;
	static DWORD CythonNetGetMainActorSkillGroup;
	static DWORD CythonNetGetAccountCharacterSlotData;
	static DWORD CythonNetSendCommandPacket;
	//item
	static DWORD CythonItemSelectItem;
	static DWORD CythonItemGetItemName;
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
	static tCInstanceBaseSCRIPT_SetPixelPosition CInstanceBaseSCRIPT_SetPixelPosition;
	static tCInstanceBase__SetAffect CInstanceBase__SetAffect;
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
	static tCInstanceBase__GetBackgroundHeight CInstanceBase__GetBackgroundHeight;
	static tCItemDataGetName CItemDataGetName;

	//#####################################################################################################################################

	static tPyRun_SimpleStringFlags PyRun_SimpleStringFlags;
	static tPyString_AsString PyString_AsString;
	static tPyTuple_GetItem PyTuple_GetItem;
	static tPyInt_AsLong PyInt_AsLong;
	static tPy_BuildValue Py_BuildValue;

	static void ReAddressingInstances();
	static void ReDeclarationInstances();
	static void ReAddressingLocas();
	static void ReDeclarationLocals();

	static void ReAddressingPython();
};
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


ServerName Globals::Server = ServerName::METINPL;
bool Globals::UsePythonFunctions = false;

map<DWORD, TCItemData*> Globals::itemProtoList;
map<DWORD, TGroundItemInstance*> Globals::groundItemList;
map<DWORD, const char*>  Globals::itemProtoNames;

HMODULE	Globals::hModule = NULL;
DWORD	Globals::hEntryBaseAddress = (DWORD)GetModuleHandle(NULL);

HWND Globals::mainHwnd;

vector<D3DVECTOR> Globals::farmCoords;



PyObject* Globals::m_apoPhaseWndGame = NULL;




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
DWORD Globals::pCInstanceBaseSCRIPT_SetPixelPosition = NULL;;
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
DWORD Globals::pCInstanceBase__GetBackgroundHeight = NULL;

//python only
//player
DWORD Globals::CythonPlayerGetStatus = NULL;
DWORD Globals::CythonPlayerGetMainCharacterIndex = NULL;
DWORD Globals::CythonPlayerGetItemIndex = NULL;
DWORD Globals::CythonPlayerGetName = NULL;
DWORD Globals::CythonPlayerGetItemMetinSocket = NULL;
DWORD Globals::CythonPlayerGetRace = NULL;
DWORD Globals::CythonPlayerSetSingleDIKKeyState = NULL;
DWORD Globals::CythonPlayerClickSkillSlot = NULL;
DWORD Globals::CythonPlayerIsSkillCoolTime = NULL;
DWORD Globals::CythonPlayerIsSkillActive = NULL;
DWORD Globals::CythonPlayerGetTargetVID = NULL;
DWORD Globals::CythonPlayerSetTarget = NULL;
DWORD Globals::CythonPlayerSetAttackKeyState = NULL;
DWORD Globals::CythonPlayerIsMountingHorse = NULL;
//chr
DWORD Globals::CythonChrSelectInstance = NULL;
DWORD Globals::CythonChrGetPixelPosition = NULL;
DWORD Globals::CythonChrMoveToDestPosition = NULL;
DWORD Globals::CythonChrGetInstanceType = NULL;
DWORD Globals::CythonChrGetVirtualNumber = NULL;
DWORD Globals::CythonChrGetNameByVID = NULL;
DWORD Globals::CythonChrSetPixelPosition = NULL;
DWORD Globals::CythonChrSetRotation = NULL;
DWORD Globals::CythonChrGetRotation = NULL;
DWORD Globals::CythonChrmgrSetAffect = NULL;
//net
DWORD Globals::CythonNetSendItemUsePacket = NULL;
DWORD Globals::CythonNetSendChatPacket = NULL;
DWORD Globals::CythonNetSendRefinePacket = NULL;
DWORD Globals::CythonNetSendExchangeStartPacket = NULL;
DWORD Globals::CythonNetSendExchangeItemAddPacket = NULL;
DWORD Globals::CythonNetSendExchangeAcceptPacket = NULL;
DWORD Globals::CythonNetSendWhisperPacket = NULL;
DWORD Globals::CythonNetSendItemPickUpPacket = NULL;
DWORD Globals::CythonNetSendItemDropPacketNew = NULL;
DWORD Globals::CythonNetSendOnClickPacket = NULL;
DWORD Globals::CythonNetSendShopSellPacketNew = NULL;
DWORD Globals::CythonNetSendShopBuyPacket = NULL;
DWORD Globals::CythonNetSendShopEndPacket = NULL;
DWORD Globals::CythonNetSendGiveItemPacket = NULL;
DWORD Globals::CythonNetSendItemMovePacket = NULL;
DWORD Globals::CythonNetDirectEnter = NULL;
DWORD Globals::CythonNetConnectTCP = NULL;
DWORD Globals::CythonNetIsConnect = NULL;
DWORD Globals::CythonNetGetMainActorSkillGroup = NULL;
DWORD Globals::CythonNetGetAccountCharacterSlotData = NULL;
DWORD Globals::CythonNetSendCommandPacket = NULL;
//item
DWORD Globals::CythonItemSelectItem = NULL;
DWORD Globals::CythonItemGetItemName = NULL;

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
Globals::tCInstanceBaseSCRIPT_SetPixelPosition Globals::CInstanceBaseSCRIPT_SetPixelPosition = NULL;
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
Globals::tCInstanceBase__GetBackgroundHeight Globals::CInstanceBase__GetBackgroundHeight = NULL;
//####Globals::#################################################################################################################################

Globals::tPyRun_SimpleStringFlags Globals::PyRun_SimpleStringFlags = NULL;
Globals::tPyString_AsString Globals::PyString_AsString = NULL;
Globals::tPyTuple_GetItem Globals::PyTuple_GetItem = NULL;
Globals::tPyInt_AsLong Globals::PyInt_AsLong = NULL;
Globals::tPy_BuildValue Globals::Py_BuildValue = NULL;

void Globals::ReAddressingInstances()
{
	switch (Globals::Server)
	{
		case ServerName::METINPL:
		{
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
			pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x1ff56b8; // [100 ] [1 / 1]
			pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x1ff2244; // [100 ] [1 / 1]
			pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x1ff2240; // [100 ] [1 / 1]
			pCItemManagerInstance = Globals::hEntryBaseAddress + 0x1ff223c; // [100 ] [1 / 1]
			pCPythonItemInstance = Globals::hEntryBaseAddress + 0x1ff5788; // [100 ] [1 / 1]
			pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x1ff7a14; // [100 ] [1 / 1]
			pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x1ff224c; // [100 ] [1 / 1]
			pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x1ff2238; // [100 ] [1 / 1]
			pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x1ff5744; // [100 ] [1 / 1]
			pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x1FFEA70;
			break;
		}
		case ServerName::ORIGINS:
		{
			pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x1C826D0;
			pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x1c7f970; // [100 ] [1 / 1]
			pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x1c7f960; // [100 ] [1 / 1]
			pCItemManagerInstance = Globals::hEntryBaseAddress + 0x1C7F97C;
			pCPythonItemInstance = Globals::hEntryBaseAddress + 0x1C82754;
			pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x1C850A4;
			pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x1c7f964; // [100 ] [1 / 1]
			pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x1C7F96C;
			pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x1c82714; // [100 ] [1 / 1]
			pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x1C885DC;
			break;
		}
		case ServerName::CALLIOPE:
		{
			pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x380db4; // [100 ] [1 / 1]
			pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x380DD0; // [100 ] [1 / 1]
			pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x380dc0; // [100 ] [1 / 1]
			pCItemManagerInstance = Globals::hEntryBaseAddress + 0x380df0; // [100 ] [1 / 1]
			pCPythonItemInstance = Globals::hEntryBaseAddress + 0x3b8e6c; // [100 ] [4 / 4]
			pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x381280; // [100 ] [1 / 1]
			pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x380ddc; // [100 ] [1 / 1]
			pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x380de8; // [100 ] [1 / 1]
			pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x380dc4; // [100 ] [1 / 1]
			pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x34340C;
			break;
		}
		case ServerName::MEDIUMMT2:
		{
			pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x3ef29c; // [100 ] [1 / 1]
			pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x3ecf1c; // [100 ] [1 / 1]
			pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x3ecf0c; // [100 ] [1 / 1]
			pCItemManagerInstance = Globals::hEntryBaseAddress + 0x3ecf24; // [100 ] [1 / 1]
			pCPythonItemInstance = Globals::hEntryBaseAddress + 0x3ef304; // [100 ] [1 / 1]
			pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x3f1330; // [100 ] [1 / 1]
			pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x3ecf10; // [100 ] [1 / 1]
			pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x3ecf18; // [100 ] [1 / 1]
			pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x3ef2e0; // [100 ] [1 / 1]
			pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x3F3A94;
			break;
		}

		case ServerName::ASENIS:
		{
			//pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x360f138; // [100 ] [47 / 47]
			//pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x360f164; // [100 ] [23 / 23]
			//pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x31f74f0; // [7 ] [1 / 13]
			//pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x360f148; // [92 ] [12 / 13]
			//pCItemManagerInstance = Globals::hEntryBaseAddress + 0x367a380; // [100 ] [32 / 32]
			//pCPythonItemInstance = Globals::hEntryBaseAddress + 0x367a3a4; // [100 ] [3 / 3]
			//pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x3616858;
			//pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x367a370; // [100 ] [4 / 4]
			//pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x367a378; // [100 ] [65 / 65]
			//pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x3552A4C;

			pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x3628828; // [100 ] [103 / 103]
			pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x3628854; // [98 ] [76 / 77]
			pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x3628838; // [95 ] [40 / 42]
			pCItemManagerInstance = Globals::hEntryBaseAddress + 0x3693a70; // [100 ] [41 / 41]
			pCPythonItemInstance = Globals::hEntryBaseAddress + 0x3693a94; // [100 ] [5 / 5]
			pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x362FF48;
			pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x3693a60; // [100 ] [7 / 7]
			pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x3693a68; // [100 ] [103 / 103]
			pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x3628848; // [100 ] [1 / 1]
			pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x356BE2C;
			break;
		}
		
		case ServerName::CLASSIC:
		{
			pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x44cb08; // [100 ] [98 / 98]
			pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x44a8dc; // [98 ] [78 / 79]
			pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x44a8cc; // [95 ] [41 / 43]
			pCItemManagerInstance = Globals::hEntryBaseAddress + 0x44a8e4; // [98 ] [49 / 50]
			pCPythonItemInstance = Globals::hEntryBaseAddress + 0x44cb18; // [100 ] [3 / 3]
			pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x44EB48;
			pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x44a8d0; // [100 ] [3 / 3]
			pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x44a8d8; // [100 ] [106 / 106]
			pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x44caf4; // [100 ] [3 / 3]
			pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x450EAC;
			break;
		}

	}
}

void Globals::ReAddressingLocas()
{
	switch (Globals::Server)
	{
		case ServerName::METINPL:
		{
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
			pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x39c240; // [100 ] [1 / 1]
			pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x76c80; // [100 ] [1 / 1]
			pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x54cb0; // [100 ] [1 / 1]
			pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x54c70; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x598c0; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x59910; // [100 ] [1 / 1]
			pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x58e60; // [100 ] [1 / 1]
			pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x732f0; // [100 ] [1 / 1]
			pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x56a90; // [100 ] [1 / 1]
			pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x565a0; // [100 ] [1 / 1]
			pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x731e0; // [100 ] [1 / 1]
			pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x72d30; // [100 ] [1 / 1]
			pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x73170; // [100 ] [1 / 1]
			pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x6a3d0; // [100 ] [1 / 1]
			pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x550A0;
			pCItemDataGetName = Globals::hEntryBaseAddress + 0x39ebb0; // [100 ] [1 / 1]
			pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x3a1340; // [100 ] [1 / 1]
			pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x76bc0; // [100 ] [1 / 1]
			pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x426ba0; // [100 ] [1 / 1]
			pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x1e7800; // [100 ] [1 / 1]
			pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x1e58d0; // [100 ] [1 / 1]
			pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x426a10; // [100 ] [1 / 1]
			pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x4269c0; // [100 ] [1 / 1]
			pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x4270D0; // [100 ] [1 / 1]
			pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x427080; // [100 ] [1 / 1]
			pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x4270f0; // [100 ] [1 / 1]
			pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x3c4d50; // [100 ] [1 / 1]
			pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x1c23a0; // [100 ] [1 / 1]
			pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x1c1860; // [100 ] [1 / 1]
			pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x83710; // [100 ] [1 / 1]
			pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x14c3a0; // [100 ] [1 / 1]
			pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x9a300; // [100 ] [1 / 1]
			pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x1e59b0; // [100 ] [1 / 1]
			pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x1e7750; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x1fc720; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x1fc290; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x1f6760; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x1f6920; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x20aa00; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x1fb660; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x1fb5c0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x1fb490; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendFishingQuitPacket = Globals::hEntryBaseAddress + 0x200bb0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x200b60; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x202950; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x219930; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x219b40; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x219db0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x219700; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x1f8aa0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x2016b0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x1fb9d0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x1fc6c0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x219560; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x219500; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x219610; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x1fc2f0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x1f68d0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x1f82f0; // [100 ] [1 / 1]
			pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x1e8b80; // [100 ] [1 / 1]
			pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xe5180; // [100 ] [1 / 1]
			pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x11dc90; // [100 ] [1 / 1]
			pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xeeba0; // [100 ] [1 / 1]
			pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0xef0e0; // [100 ] [1 / 1]
			pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xedef0; // [100 ] [1 / 1]
			pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xee750; // [100 ] [1 / 1]
			pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xee060; // [100 ] [1 / 1]
			pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xee710; // [100 ] [1 / 1]
			pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x105410; // [100 ] [1 / 1]
			pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xf0a40; // [100 ] [1 / 1]
			pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xf0a10; // [100 ] [1 / 1]
			pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x106080; // [100 ] [1 / 1]
			pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xed9f0; // [100 ] [1 / 1]
			pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x106fa0; // [100 ] [1 / 1]
			pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x105470; // [100 ] [1 / 1]
			pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x105920; // [100 ] [1 / 1]
			pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x105a60; // [100 ] [1 / 1]
			pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x429d40; // [100 ] [1 / 1]
			pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x414820; // [100 ] [1 / 1]
			pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x43cb50; // [100 ] [1 / 1]
			pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x460830; // [100 ] [1 / 1]
			pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x40b710; // [100 ] [1 / 1]
			pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x4278d0; // [100 ] [1 / 1]
			pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x72BF0;
			pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x73210;
			pCPythonNetworkStreamSendCommandPacket = Globals::hEntryBaseAddress + 0x20B9F0;
			break;
		}
		case ServerName::ORIGINS:
		{
			pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x40dce0; // [100 %] [1 / 1]
			pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x3bc2b0; // [100 %] [1 / 1]
			pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x3a7660; // [100 %] [1 / 1]
			pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x3a3b90; // [100 %] [1 / 1]
			pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x40d8a0; // [100 %] [1 / 1]
			pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x16e080; // [100 %] [1 / 1]
			pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x16cd80; // [100 %] [1 / 1]
			pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x16ce80; // [100 %] [1 / 1]
			pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x16cd20; // [100 %] [1 / 1]
			pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x18f5a0; // [100 %] [1 / 1]
			pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x16ddd0; // [100 %] [1 / 1]
			pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x16d980; // [100 %] [1 / 1]
			pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x18e330; // [100 %] [1 / 1]
			pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x18f4d0; // [100 %] [1 / 1]
			pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x18e8f0; // [100 %] [1 / 1]
			pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x18f460; // [100 %] [1 / 1]
			pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x18f5e0; // [100 %] [1 / 1]
			pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x171f00; // [100 %] [1 / 1]
			pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x1823c0; // [100 %] [1 / 1]
			pCItemDataGetName = Globals::hEntryBaseAddress + 0x400620; // [100 %] [1 / 1]
			pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x414a70; // [100 %] [1 / 1]
			pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x3a2dd0; // [100 %] [1 / 1]
			pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x30c3c0; // [100 %] [1 / 1]
			pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x3a3060; // [100 %] [1 / 1]
			pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x3a30d0; // [100 %] [2 / 2]
			pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x3a3330; // [100 %] [1 / 1]
			pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x3a33b0; // [100 %] [1 / 1]
			pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x30d130; // [100 %] [1 / 1]
			pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x42ad90; // [100 %] [1 / 1]
			pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x2c3710; // [100 %] [1 / 1]
			pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x2bbc40; // [100 %] [1 / 1]
			pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x2bb9e0; // [100 %] [1 / 1]
			pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x195b40; // [100 %] [1 / 1]
			pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x193650; // [100 %] [1 / 1]
			pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x1a4220; // [100 %] [1 / 1]
			pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x2392c0; // [100 %] [1 / 1]
			pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x1bd8d0; // [100 %] [1 / 1]
			pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x30c550; // [100 %] [1 / 1]
			pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x30c7e0; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x31dda0; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x31d510; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x31d570; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x3204b0; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x31d9e0; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x31d8c0; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x31d830; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x31ebe0; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x336f00; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x337100; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x336b40; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x31dcc0; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x31f050; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x31dac0; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x31de20; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x337350; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x3372f0; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x31cfe0; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x31d6d0; // [100 %] [1 / 1]
			pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x320670; // [100 %] [1 / 1]
			pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x30fd20; // [100 %] [1 / 1]
			pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x1d81b0; // [100 %] [1 / 1]
			pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x2091b0; // [100 %] [1 / 1]
			pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x1e3d10; // [100 %] [1 / 1]
			pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x1e3e80; // [100 %] [1 / 1]
			pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x1e30d0; // [100 %] [1 / 1]
			pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x16cd20; // [100 %] [1 / 1]
			pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x417360; // [100 %] [1 / 1]
			pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x1e3660; // [100 %] [1 / 1]
			pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x1f7ed0; // [100 %] [1 / 1]
			pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x1e50b0; // [100 %] [1 / 1]
			pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x1e50e0; // [100 %] [1 / 1]
			pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x1e2580; // [100 %] [1 / 1]
			pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x1f9590; // [100 %] [1 / 1]
			pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x1f7ba0; // [100 %] [1 / 1]
			pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x1f81b0; // [100 %] [1 / 1]
			pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x1f7fb0; // [100 %] [1 / 1]
			pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x394a70; // [100 %] [1 / 1]
			pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x477df0; // [100 %] [1 / 1]
			break;
		}
		case ServerName::CALLIOPE:
		{
			pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x17c3a0; // [100 ] [1 / 1]
			pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x85780;
			pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x17bf20; // [100 ] [1 / 1]
			pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x69cc0; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x6de90; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x6deb0; // [100 ] [1 / 1]
			pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x6d050; // [100 ] [1 / 1]
			pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x761e0; // [100 ] [7 / 7]
			pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x6b840; // [100 ] [4 / 4]
			pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x6b480; // [100 ] [1 / 1]
			pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x76100; // [100 ] [10 / 10]
			pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x75d80; // [100 ] [3 / 3]
			pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x760a0; // [100 ] [1 / 1]
			pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x72fa0; // [100 ] [1 / 1]
			pCItemDataGetName = Globals::hEntryBaseAddress + 0x17fcb0; // [100 ] [1 / 1]
			pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x17dd30; // [100 ] [5 / 5]
			pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x856b0; // [100 ] [1 / 1]
			pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x12fb70; // [100 ] [4 / 4]
			pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0xadca0; // [100 ] [1 / 1]
			pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0xad4d0; // [100 ] [1 / 1]
			pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x12fd40; // [100 ] [3 / 3]
			pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x12fd80; // [100 ] [2 / 2]
			pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x12ff50; // [100 ] [1 / 1]
			pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x12ffc0; // [100 ] [1 / 1]
			pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x69c10; // [100 ] [1 / 1]
			pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x192e70; // [100 ] [1 / 1]
			pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x7c5f0; // [100 ] [1 / 1]
			pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x7c190; // [100 ] [1 / 1]
			pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x88e90; // [100 ] [1 / 1]
			pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x8fda0; // [100 ] [1 / 1]
			pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x96000; // [100 ] [1 / 1]
			pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0xad5c0; // [100 ] [1 / 1]
			pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x6d0c0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0xB7960;
			pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0xb74c0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0xb4c10; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0xb4de0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0xadd90; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0xb6a10; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0xb6990; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0xb6890; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendFishingQuitPacket = Globals::hEntryBaseAddress + (null); 
			pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0xb9b20; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0xb9b80; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0xbdc20; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0xbdf80; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0xbe1a0; // [100 ] [3 / 3]
			pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0xbda60; // [100 ] [3 / 3]
			pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0xb5aa0; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0xBA280;
			pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0xb6ca0; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0xb7860; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0xbd880; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0xbd830; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0xbd980; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0xB7550;
			pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0xb4d70; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0xb55d0; // [100 ] [1 / 1]
			pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0xae930; // [100 ] [1 / 1]
			pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xc0e80; // [100 ] [1 / 1]
			pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0xd0d90; // [100 ] [1 / 1]
			pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xC2F70;
			pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0xc35b0; // [100 ] [1 / 1]
			pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xc2540; // [100 ] [1 / 1]
			pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xc2a40; // [100 ] [1 / 1]
			pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x9afc0; // [100 ] [1 / 1]
			pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xc2a10; // [100 ] [1 / 1]
			pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0xc7460; // [100 ] [1 / 1]
			pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xc43c0; // [100 ] [1 / 1]
			pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xc43a0; // [100 ] [1 / 1]
			pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0xc7c20; // [100 ] [1 / 1]
			pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xc2240; // [100 ] [1 / 1]
			pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0xc84d0; // [100 ] [1 / 1]
			pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0xc7490; // [100 ] [1 / 1]
			pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0xC7710;
			pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0xC77B0;
			pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x87DB0; // [100 ] [11 / 11]
			pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x133b70; // [100 ] [2 / 2]
			pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x1354A0; // [100 ] [1 / 1]
			pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x1bcba0; // [100 ] [1 / 1]
			pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x7F190;
			pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x139e60; // [100 ] [1 / 1]
			pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x75cc0; // [100 ] [4 / 4]
			pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x76130; // [100 ] [4 / 4]
			pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x69FC0; // [100 %] [1 / 1]
			break;
		}
		case ServerName::MEDIUMMT2:
		{
			pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x19b30; // [100 ] [1 / 1]
			pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x1309a0; // [100 ] [1 / 1]
			pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0xa490; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0xba40; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0xbbe0; // [100 ] [1 / 1]
			pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0xbb70; // [100 ] [1 / 1]
			pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x16780; // [100 ] [1 / 1]
			pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0xc120; // [100 ] [1 / 1]
			pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0xc300; // [100 ] [1 / 1]
			pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x16790; // [100 ] [1 / 1]
			pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x16100; // [100 ] [1 / 1]
			pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x16840; // [100 ] [1 / 1]
			pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x134f0; // [100 ] [1 / 1]
			pCItemDataGetName = Globals::hEntryBaseAddress + 0x126a70; // [100 ] [1 / 1]
			pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x135ee0; // [100 ] [1 / 1]
			pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x19d90; // [100 ] [1 / 1]
			pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0xe0220; // [100 ] [1 / 1]
			pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x872e0; // [100 ] [1 / 1]
			pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x86ac0; // [100 ] [1 / 1]
			pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0xe0340; // [100 ] [1 / 1]
			pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0xe03b0; // [100 ] [1 / 1]
			pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0xe03d0; // [100 ] [1 / 1]
			pCNetworkStreamSend = Globals::hEntryBaseAddress + 0xe05f0; // [100 ] [1 / 1]
			pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0xb6090; // [100 ] [1 / 1]
			pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x147120; // [100 ] [1 / 1]
			pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x6b140; // [100 ] [1 / 1]
			pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x6b840; // [100 ] [1 / 1]
			pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x1ec50; // [100 ] [1 / 1]
			pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x4eb30; // [100 ] [1 / 1]
			pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x280c0; // [100 ] [1 / 1]
			pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x868a0; // [100 ] [1 / 1]
			pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x86bc0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x939c0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x92f80; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x930d0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x93250; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x86e50; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x93740; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x93870; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x938e0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendFishingQuitPacket = Globals::hEntryBaseAddress + (null); 
			pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x93960; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x93a50; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x97070; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x970e0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x97210; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x97260; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x942b0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x94690; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x946c0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x94770; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x97600; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x97670; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x97730; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x947b0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x948e0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x94940; // [100 ] [1 / 1]
			pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x87830; // [100 ] [1 / 1]
			pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x2ee20; // [100 ] [1 / 1]
			pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x3c9c0; // [100 ] [1 / 1]
			pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x32230;
			pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x32290; // [100 ] [1 / 1]
			pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x32480; // [100 ] [1 / 1]
			pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x32490; // [100 ] [1 / 1]
			pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x32570; // [100 ] [1 / 1]
			pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x32730; // [100 ] [1 / 1]
			pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x36b40; // [100 ] [1 / 1]
			pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x32bd0; // [100 ] [1 / 1]
			pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x32c00; // [100 ] [1 / 1]
			pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x35f70; // [100 ] [1 / 1]
			pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x32fc0; // [100 ] [1 / 1]
			pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x373c0; // [100 ] [1 / 1]
			pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x366f0; // [100 ] [1 / 1]
			//pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + (null); 
			pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x36cd0; // [100 ] [1 / 1]
			pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0xe3cd0; // [100 ] [1 / 1]
			pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0xd5f90; // [100 ] [1 / 1]
			pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0xf26e0; // [100 ] [1 / 1]
			pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x183f20; // [100 ] [1 / 1]
			pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x6e030; // [100 ] [1 / 1]
			pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0xe0c90; // [100 ] [1 / 1]
			pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x15e40; // [100 ] [1 / 1]
			pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x168e0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendCommandPacket = Globals::hEntryBaseAddress + (null); 
			pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0xeb60; // [100 %] [1 / 1]
			break;
		}
		case ServerName::ASENIS:
		{
			
			//pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x199410; // [100 ] [1 / 1]
			//pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x625c0; // [100 ] [1 / 1]
			//pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x45870; // [100 ] [1 / 1]
			//pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x45850; // [100 ] [1 / 1]
			//pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x48da0; // [100 ] [1 / 1]
			//pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x48dc0; // [100 ] [1 / 1]
			//pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x3c8e0; // [83 ] [5 / 6]
			//pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x53a20; // [100 ] [1 / 1]
			//pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x46c80; // [100 ] [1 / 1]
			//pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x46920; // [100 ] [1 / 1]
			//pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x53940; // [100 ] [1 / 1]
			//pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x535c0; // [100 ] [1 / 1]
			//pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x538e0; // [100 ] [1 / 1]
			//pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x508c0; // [100 ] [1 / 1]
			//pCItemDataGetName = Globals::hEntryBaseAddress + 0x19d160; // [100 ] [1 / 1]
			//pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x19b0c0; // [100 ] [1 / 1]
			//pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x624d0; // [100 ] [1 / 1]
			//pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x14a270; // [100 ] [1 / 1]
			//pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x8c830; // [100 ] [1 / 1]
			//pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x8bfd0; // [100 ] [1 / 1]
			//pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x14a440; // [100 ] [1 / 1]
			//pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x14a480; // [100 ] [1 / 1]
			//pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x14a690; // [100 ] [1 / 1]
			//pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x14a6d0; // [100 ] [1 / 1]
			//pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x14a720; // [100 ] [1 / 1]
			//pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x1af940; // [100 ] [1 / 1]
			//pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x5ad70; // [100 ] [1 / 1]
			//pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x5a3d0; // [100 ] [1 / 1]
			//pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x660b0; // [50 ] [1 / 2]
			//pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x6ce40; // [100 ] [1 / 1]
			//pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x71c80; // [100 ] [1 / 1]
			//pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x8c0c0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x8c770; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x98a30; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x985b0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x95a70; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x95c50; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x8c920; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x97bc0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x97b40; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x979e0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x9aad0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x9ab30; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0xa1e40; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0xa1fb0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0xa2100; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0xa1c60; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x96a90; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x97e20; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x98950; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0xa1ab0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0xa1a60; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0xa1bb0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x98630; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x95be0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x96520; // [100 ] [1 / 1]
			//pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x8d680; // [100 ] [1 / 1]
			//pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xa5270; // [100 ] [1 / 1]
			//pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0xb5e70; // [100 ] [1 / 1]
			//pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xAACF0;
			//pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x19d250; // [50 ] [1 / 2]
			//pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xaa320; // [100 ] [1 / 1]
			//pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x3c8e0; // [100 ] [2 / 2]
			//pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xaa380; // [100 ] [1 / 1]
			//pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xaa810; // [100 ] [1 / 1]
			//pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0xae750; // [100 ] [1 / 1]
			//pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xabbe0; // [100 ] [1 / 1]
			//pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xabbc0; // [100 ] [1 / 1]
			//pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0xaef20; // [100 ] [1 / 1]
			//pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xaa020; // [100 ] [1 / 1]
			//pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0xaf6f0; // [100 ] [1 / 1]
			//pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0xae790; // [100 ] [1 / 1]
			//pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0xaec40; // [100 ] [1 / 1]
			//pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0xaeab0; // [100 ] [1 / 1]
			//pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x65920; // [100 ] [13 / 13]
			//pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x14ea70; // [100 ] [20 / 20]
			//pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x1533c0; // [100 ] [2 / 2]
			//pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x1db7a0; // [100 ] [1 / 1]
			//pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x5D820;
			//pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x157d70; // [100 ] [1 / 1]
			//pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x53500; // [100 ] [1 / 1]
			//pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x53970; // [100 ] [1 / 1]
			//pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x45b40; // [100 ] [1 / 1]




			
			pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x199410; // [100 ] [1 / 1]
			pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x625c0; // [100 ] [1 / 1]
			pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x45870; // [100 ] [1 / 1]
			pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x45850; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x48da0; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x48dc0; // [100 ] [1 / 1]
			pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x3c8e0; // [83 ] [5 / 6]
			pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x53a20; // [100 ] [1 / 1]
			pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x46c80; // [100 ] [1 / 1]
			pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x46920; // [100 ] [1 / 1]
			pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x53940; // [100 ] [1 / 1]
			pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x535c0; // [100 ] [1 / 1]
			pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x538e0; // [100 ] [1 / 1]
			pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x508c0; // [100 ] [1 / 1]
			pCItemDataGetName = Globals::hEntryBaseAddress + 0x19d160; // [100 ] [1 / 1]
			pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x19b0c0; // [100 ] [1 / 1]
			pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x624d0; // [100 ] [1 / 1]
			pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x14A320; // [100 ] [1 / 1]
			pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x8c830; // [100 ] [1 / 1]
			pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x8bfd0; // [100 ] [1 / 1]
			pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x14a440; // [100 ] [1 / 1]
			pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x14a480; // [100 ] [1 / 1]
			pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x14a690; // [100 ] [1 / 1]
			pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x14a6d0; // [100 ] [1 / 1]
			pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x14a720; // [100 ] [1 / 1]
			pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x1af940; // [100 ] [1 / 1]
			pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x5ad70; // [100 ] [1 / 1]
			pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x5a3d0; // [100 ] [1 / 1]

			pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x660b0; // [50 ] [1 / 2]
			pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x6ce40; // [100 ] [1 / 1]
			pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x71c80; // [100 ] [1 / 1]
			pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x8c0c0; // [100 ] [1 / 1]
			pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x8c770; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x98a30; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x985b0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x95a70; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x95c50; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x8c920; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x97bc0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x97b40; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x979e0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x9aad0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x9ab30; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0xa1e40; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0xa1fb0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0xa2100; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0xa1c60; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x96a90; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x97e20; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x98950; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0xa1ab0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0xa1a60; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0xa1bb0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x98630; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x95be0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x96520; // [100 ] [1 / 1]
			pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x8d680; // [100 ] [1 / 1]
			pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xa5270; // [100 ] [1 / 1]
			pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0xb5e70; // [100 ] [1 / 1]
			pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xAACF0; 

			pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x19d250; // [50 ] [1 / 2]
			pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xaa320; // [100 ] [1 / 1]
			pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x3c8e0; // [100 ] [2 / 2]
			pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xaa380; // [100 ] [1 / 1]
			pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xaa810; // [100 ] [1 / 1]
			pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0xae750; // [100 ] [1 / 1]
			pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xabbe0; // [100 ] [1 / 1]
			pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xabbc0; // [100 ] [1 / 1]
			pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0xaef20; // [100 ] [1 / 1]
			pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xaa020; // [100 ] [1 / 1]
			pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0xaf6f0; // [100 ] [1 / 1]
			pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0xae790; // [100 ] [1 / 1]
			pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0xaec40; // [100 ] [1 / 1]
			pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0xaeab0; // [100 ] [1 / 1]
			pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x65920; // [100 ] [13 / 13]
			pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x14ea70; // [100 ] [20 / 20]
			pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x1533C0; // [100 ] [1 / 1]
			pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x1db7a0; // [100 ] [1 / 1]
			pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x5D820;
			pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x157d70; // [100 ] [1 / 1]
			pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x53500; // [100 ] [1 / 1]
			pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x53970; // [100 ] [1 / 1]
			pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x45b40; // [100 ] [1 / 1]
			break;
		}
		case ServerName::PANGEA:
		{
			pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x3297924; // [100 ] [103 / 103]
			pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x3297950; // [98 ] [65 / 66]
			pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x3297930; // [100 ] [16 / 16]
			pCItemManagerInstance = Globals::hEntryBaseAddress + 0x32979a8; // [100 ] [48 / 48]
			pCPythonItemInstance = Globals::hEntryBaseAddress + 0x32b5888; // [100 ] [3 / 3]
			pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x32B5898;
			pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x3297998; // [100 ] [1 / 1]
			pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x32979a0; // [99 ] [106 / 107]
			pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x3297938; // [100 ] [6 / 6]
			pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x222150; // [100 ] [3 / 3]
			pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x222150; // [100 ] [1 / 1]
			pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x129240; // [100 ] [1 / 1]
			pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x221c60; // [100 ] [1 / 1]
			pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0xf6d10; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0xf7f60; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0xf8200; // [100 ] [1 / 1]
			pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0xf80d0; // [100 ] [1 / 1]
			pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x105170; // [100 ] [1 / 1]
			pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0xf8650; // [100 ] [1 / 1]
			pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0xf9540; // [75 ] [3 / 4]
			pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x105180; // [100 ] [1 / 1]
			pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x104b10; // [100 ] [1 / 1]
			pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x105230; // [100 ] [1 / 1]
			pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x103300; // [100 ] [1 / 1]
			pCItemDataGetName = Globals::hEntryBaseAddress + 0x217490; // [50 ] [1 / 2]
			pCItemDataGetName = Globals::hEntryBaseAddress + 0x275b40; // [50 ] [1 / 2]
			pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x225590; // [100 ] [1 / 1]
			pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x1294c0; // [100 ] [1 / 1]
			pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x1c6650; // [100 ] [1 / 1]
			pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x1584e0; // [100 ] [1 / 1]
			pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x157bf0; // [100 ] [1 / 1]
			pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x1c6770; // [100 ] [1 / 1]
			pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x1c67e0; // [100 ] [1 / 1]
			pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x1c69f0; // [100 ] [1 / 1]
			pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x1c6a30; // [100 ] [1 / 1]
			pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x1c6ab0; // [100 ] [1 / 1]
			pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x23e0b0; // [100 ] [1 / 1]
			pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x120db0; // [100 ] [1 / 1]
			pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x1214e0; // [100 ] [1 / 1]
			pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x12ee90; // [100 ] [1 / 1]
			pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x136350; // [100 ] [1 / 1]
			pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x13f980; // [100 ] [1 / 1]
			pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x1579d0; // [100 ] [1 / 1]
			pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x157cf0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x165110;
			pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x1644a0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x164740; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x1648b0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x157ff0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x164e00; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x164f30; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x165020; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x1650b0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x1651a0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x168e00; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x168e80; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x168fb0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x169010; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x165a60; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x165e60; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x1660e0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x1661c0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + (null); 
			pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x169820; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x1698f0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x166210; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x166320; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x166390; // [100 ] [2 / 2]
			pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x158860; // [100 ] [1 / 1]
			pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x16c7d0; // [100 ] [1 / 1]
			pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x179850; // [100 ] [1 / 1]
			pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x16F270;
			pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x16f2d0; // [100 ] [1 / 1]
			pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x16f360; // [100 ] [1 / 1]
			pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x16f370; // [100 ] [1 / 1]
			pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x16f430; // [100 ] [1 / 1]
			pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x16f6d0; // [100 ] [1 / 1]
			pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x173480; // [100 ] [1 / 1]
			pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x16fb90; // [100 ] [1 / 1]
			pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x16fbc0; // [100 ] [1 / 1]
			pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x172b10; // [100 ] [1 / 1]
			pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x16ff60; // [100 ] [1 / 1]
			pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x173d10; // [100 ] [1 / 1]
			pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x173030; // [100 ] [1 / 1]
			pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x16F270;
			pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x173610; // [100 ] [1 / 1]
			pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x1f0690; // [100 ] [1 / 1]
			pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x1cfbb0; // [100 ] [1 / 1]
			pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x1d2f40; // [100 ] [1 / 1]
			pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x275660; // [100 ] [1 / 1]
			pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x123F60; // [100 ] [1 / 1]
			pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x32B8D0C;
			pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x1e5bb0; // [100 ] [1 / 1]
			pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x104850; // [100 ] [1 / 1]
			pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x1052d0; // [100 ] [1 / 1]
			pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0xFC990;
			break;
		}
		case ServerName::CLASSIC:
		{
			
			pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x65ea0; // [100 ] [1 / 1] 
			pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x72d70; // [100 ] [1 / 1]
			pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x17d840; // [100 ] [1 / 1]
			pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x64cb0; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x65d70; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x65f10; // [100 ] [1 / 1]
			pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x65ea0; // [83 ] [5 / 6]
			pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x70190; // [100 ] [2 / 2]
			pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x662e0; // [100 ] [2 / 2]
			pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x664c0; // [66 ] [2 / 3]
			pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x701a0; // [100 ] [1 / 1]
			pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x6fb10; // [100 ] [1 / 1]
			pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x70250; // [100 ] [1 / 1]
			pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x6e850; // [100 ] [1 / 1]
			pCItemDataGetName = Globals::hEntryBaseAddress + 0x1738c0; // [66 ] [2 / 3]
			pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x182d80; // [50 ] [1 / 2]
			pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x72fd0; // [100 ] [1 / 1]
			pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x12CB60; // [100 ] [1 / 1]
			pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0xd6270; // [100 ] [1 / 1]
			pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0xd5a40; // [100 ] [1 / 1]
			pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x12cc80; // [100 ] [2 / 2]
			pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x12ccf0; // [100 ] [2 / 2]
			pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x12cef0; // [100 ] [2 / 2]
			pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x12cf30; // [100 ] [2 / 2]
			pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x16c3b0; // [100 ] [2 / 2]
			pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x1937a0; // [100 ] [1 / 1]
			pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0xc27a0; // [100 ] [2 / 2]
			pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0xc2ea0; // [100 ] [17 / 17]
			pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x77e90; // [100 ] [20 / 20]
			pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0xa6200; // [100 ] [2 / 2]
			pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x80b50; // [100 ] [2 / 2]
			pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0xd5830; // [100 ] [1 / 1]
			pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0xd5b50; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0xE14C0; 
			pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0xe0ac0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0xe0c10; // [100 ] [5 / 5]
			pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0xe0d60; // [100 ] [5 / 5]
			pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0xd5de0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0xe1250; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0xe1370; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0xe13e0; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0xe1460; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0xe1550; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0xe48f0; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0xe4960; // [66 ] [2 / 3]
			pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0xe4a90; // [100 ] [4 / 4]
			pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0xe4ae0; // [100 ] [3 / 3]
			pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0xe1db0; // [100 ] [3 / 3]
			pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0xe2150; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0xe2200; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0xe4e80; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0xe4ef0; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0xe4fb0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0xe2240; // [100 ] [2 / 2]
			pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0xe2340; // [100 ] [3 / 3]
			pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0xe23a0; // [100 ] [2 / 2]
			pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0xd67c0; // [100 ] [25 / 25]
			pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x876c0; // [71 ] [5 / 7]
			pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x93f00; // [100 ] [4 / 4]
			pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x899c0; // [100 ] [5 / 5]
			pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x89a20; // [50 ] [1 / 2]

			pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x89c10; // [50 ] [1 / 2]
			pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x89c20; // [100 ] [3 / 3]
			pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x89d00; // [66 ] [2 / 3]

			pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x89ec0; // [100 ] [4 / 4]
			pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x8d430; // [100 ] [1 / 1]
			pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x8a360; // [100 ] [2 / 2]
			pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x8a390; // [100 ] [2 / 2]
			pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x8d650; // [100 ] [1 / 1]
			pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x8a750; // [100 ] [10 / 10]
			pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x8e960; // [100 ] [1 / 1]
			pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x8dc90; // [100 ] [2 / 2]
			pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x8e220; // [100 ] [1 / 1]
			pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x8E270;
			pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x130610; // [93 ] [15 / 16]

			pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x123130; // [100 ] [14 / 14]
			pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x13f020; // [100 ] [4 / 4]
			pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x1d08f0; // [100 ] [2 / 2]
			pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0xC5680; // [100 ] [1 / 1]
			pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x12d5d0; // [100 ] [1 / 1]
			pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x6f850; // [100 ] [1 / 1]
			pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x702f0; // [100 ] [2 / 2]
			pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x68a50; // [100 ] [1 / 1]
			break;
		}
	}
}

void Globals::ReAddressingPython()
{
	//player
	CythonPlayerGetStatus = PythonExtension::ModulesMap["playerGetStatus"];
	CythonPlayerGetMainCharacterIndex = PythonExtension::ModulesMap["playerGetMainCharacterIndex"];
	CythonPlayerGetItemIndex = PythonExtension::ModulesMap["playerGetItemIndex"];
	CythonPlayerGetName = PythonExtension::ModulesMap["playerGetName"];
	CythonPlayerGetItemMetinSocket = PythonExtension::ModulesMap["playerGetItemMetinSocket"];
	CythonPlayerGetRace = PythonExtension::ModulesMap["playerGetRace"];
	CythonPlayerSetSingleDIKKeyState = PythonExtension::ModulesMap["playerSetSingleDIKKeyState"];
	CythonPlayerClickSkillSlot = PythonExtension::ModulesMap["playerClickSkillSlot"];
	CythonPlayerIsSkillCoolTime = PythonExtension::ModulesMap["playerIsSkillCoolTime"];
	CythonPlayerIsSkillActive = PythonExtension::ModulesMap["playerIsSkillActive"];
	CythonPlayerGetTargetVID = PythonExtension::ModulesMap["playerGetTargetVID"];
	CythonPlayerSetTarget = PythonExtension::ModulesMap["playerSetTarget"];
	CythonPlayerSetAttackKeyState = PythonExtension::ModulesMap["playerSetAttackKeyState"];
	CythonPlayerIsMountingHorse = PythonExtension::ModulesMap["playerIsMountingHorse"];
	//chr
	CythonChrSelectInstance = PythonExtension::ModulesMap["chrSelectInstance"];
	CythonChrGetPixelPosition = PythonExtension::ModulesMap["chrGetPixelPosition"];
	CythonChrMoveToDestPosition = PythonExtension::ModulesMap["chrMoveToDestPosition"];
	CythonChrGetInstanceType = PythonExtension::ModulesMap["chrGetInstanceType"];
	CythonChrGetVirtualNumber = PythonExtension::ModulesMap["chrGetVirtualNumber"];
	CythonChrGetNameByVID = PythonExtension::ModulesMap["chrGetNameByVID"];
	CythonChrSetPixelPosition = PythonExtension::ModulesMap["chrSetPixelPosition"];
	CythonChrSetRotation = PythonExtension::ModulesMap["chrSetRotation"];
	CythonChrGetRotation = PythonExtension::ModulesMap["chrGetRotation"];
	CythonChrmgrSetAffect = PythonExtension::ModulesMap["chrmgrSetAffect"];
	//net
	CythonNetSendItemUsePacket = PythonExtension::ModulesMap["netSendItemUsePacket"];
	CythonNetSendChatPacket = PythonExtension::ModulesMap["netSendChatPacket"];
	CythonNetSendRefinePacket = PythonExtension::ModulesMap["netSendRefinePacket"];
	CythonNetSendExchangeStartPacket = PythonExtension::ModulesMap["netSendExchangeStartPacket"];
	CythonNetSendExchangeItemAddPacket = PythonExtension::ModulesMap["netSendExchangeItemAddPacket"];
	CythonNetSendExchangeAcceptPacket = PythonExtension::ModulesMap["netSendExchangeAcceptPacket"];
	CythonNetSendWhisperPacket = PythonExtension::ModulesMap["netSendWhisperPacket"];
	CythonNetSendItemPickUpPacket = PythonExtension::ModulesMap["netSendItemPickUpPacket"];
	CythonNetSendItemDropPacketNew = PythonExtension::ModulesMap["netSendItemDropPacketNew"];
	CythonNetSendOnClickPacket = PythonExtension::ModulesMap["netOnClickPacket"];
	CythonNetSendShopSellPacketNew = PythonExtension::ModulesMap["netSendShopSellPacketNew"];
	CythonNetSendShopBuyPacket = PythonExtension::ModulesMap["netSendShopBuyPacket"];
	CythonNetSendShopEndPacket = PythonExtension::ModulesMap["netSendShopEndPacket"];
	CythonNetSendGiveItemPacket = PythonExtension::ModulesMap["netSendGiveItemPacket"];
	CythonNetSendItemMovePacket = PythonExtension::ModulesMap["netSendItemMovePacket"];
	CythonNetDirectEnter = PythonExtension::ModulesMap["netDirectEnter"];
	CythonNetConnectTCP = PythonExtension::ModulesMap["netConnectTCP"];
	CythonNetIsConnect = PythonExtension::ModulesMap["netIsConnect"];
	CythonNetGetMainActorSkillGroup = PythonExtension::ModulesMap["netGetMainActorSkillGroup"];
	CythonNetGetAccountCharacterSlotData = PythonExtension::ModulesMap["netGetAccountCharacterSlotDataString"];
	CythonNetSendCommandPacket = PythonExtension::ModulesMap["netSendCommandPacket"];
	//item
	CythonItemSelectItem = PythonExtension::ModulesMap["itemSelectItem"];
	CythonItemGetItemName = PythonExtension::ModulesMap["itemGetItemName"];
}

void Globals::ReDeclarationInstances()
{
	if (!GetModuleHandle("python27.dll"))
	{
		switch (Globals::Server)
		{
		default:
		{
			Globals::PyRun_SimpleStringFlags = (tPyRun_SimpleStringFlags)PatternScan::FindPattern("55 8B EC 83 EC ? 68 ? ? ? ? E8 ? ? ? ? 83 C4 ? 89 45 ? 83 7D ? ? 75 ? 83 C8");
			Globals::PyString_AsString = (tPyString_AsString)PatternScan::FindPattern("55 8B EC 8B 45 ? 8B 48 ? 8B 51 ? 81 E2 ? ? ? ? 75 ? 8B 45 ? 50 E8 ? ? ? ? 83 C4 ? EB ? 8B 45");
			Globals::PyTuple_GetItem = (tPyTuple_GetItem)PatternScan::FindPattern("55 8B EC 8B 45 ? 8B 48 ? 8B 51 ? 81 E2 ? ? ? ? 75 ? 6A ? 68 ? ? ? ? E8 ? ? ? ? 83 C4 ? 33 C0");
			Globals::PyInt_AsLong = (tPyInt_AsLong)PatternScan::FindPattern("55 8B EC 83 EC ? 83 7D ? ? 74 ? 8B 45 ? 8B 48 ? 8B 51 ? 81 E2 ? ? ? ? 74 ? 8B 45 ? 8B 40 ? E9 ? ? ? ? 83 7D ? ? 74 ? 8B 4D ? 8B 51 ? 8B 42 ? 89 45");
			Globals::Py_BuildValue = (tPy_BuildValue)PatternScan::FindPattern("");
			break;
		}
		}
	}
	else
	{
		Globals::PyRun_SimpleStringFlags = (tPyRun_SimpleStringFlags)GetProcAddress(GetModuleHandle("python27.dll"), "PyRun_SimpleString");
		Globals::PyString_AsString = (tPyString_AsString)GetProcAddress(GetModuleHandle("python27.dll"), "PyString_AsString");
		Globals::PyTuple_GetItem = (tPyTuple_GetItem)GetProcAddress(GetModuleHandle("python27.dll"), "PyTuple_GetItem");
		Globals::PyInt_AsLong = (tPyInt_AsLong)GetProcAddress(GetModuleHandle("python27.dll"), "PyInt_AsLong");
		Globals::Py_BuildValue = (tPy_BuildValue)GetProcAddress(GetModuleHandle("python27.dll"), "Py_BuildValue");
	}
	if (pCPythonCharacterManagerInstance != NULL)
	{
		Globals::iCPythonCharacterManagerInstance = *reinterpret_cast<DWORD*>(pCPythonCharacterManagerInstance);
	}
	if (pCResourceManagerInstance != NULL)
	{
		Globals::iCResourceManagerInstance = *reinterpret_cast<DWORD*>(pCResourceManagerInstance);
	}
	if (pCPythonPlayerInstance != NULL)
	{
		Globals::iCPythonPlayerInstance = *reinterpret_cast<DWORD*>(pCPythonPlayerInstance);
	}
	if (pCPythonNonPlayerInstance != NULL)
	{
		Globals::iCPythonNonPlayerInstance = *reinterpret_cast<DWORD*>(pCPythonNonPlayerInstance);
	}
	if (pCPythonNetworkStreamInstance != NULL)
	{
		Globals::iCPythonNetworkStreamInstance = *reinterpret_cast<DWORD*>(pCPythonNetworkStreamInstance);
	}
	if (pCItemManagerInstance != NULL)
	{
		Globals::iCItemManagerInstance = *reinterpret_cast<DWORD*>(pCItemManagerInstance);
	}
	if (pCPythonItemInstance != NULL)
	{
		Globals::iCPythonItemInstance = *reinterpret_cast<DWORD*>(pCPythonItemInstance);
	}
	if (pCPythonApplicationInstance != NULL)
	{
		Globals::iCPythonApplicationInstance = *reinterpret_cast<DWORD*>(pCPythonApplicationInstance);
	}
	if (pCPythonBackgroundInstance != NULL)
	{
		Globals::iCPythonBackgroundInstance = *reinterpret_cast<DWORD*>(pCPythonBackgroundInstance);
	}
	if (pCGraphicBasems_lpd3dDevice != NULL) {
		Device::pDevice = *reinterpret_cast<DirectDevice2*>(pCGraphicBasems_lpd3dDevice);
	}
}

void Globals::ReDeclarationLocals()
{
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
	if (pCInstanceBase__GetBackgroundHeight != NULL)
	{
		CInstanceBase__GetBackgroundHeight = (tCInstanceBase__GetBackgroundHeight)(pCInstanceBase__GetBackgroundHeight);
	}
}

//#####################################################################################################################################}

