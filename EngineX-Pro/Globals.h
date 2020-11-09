
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


ServerName Globals::Server = ServerName::DEVERIA;
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



//"CPythonGraphic::SetViewport(%d, %d, %d, %d) - Error"
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
					if ((info.State == MEM_COMMIT) && ((info.Type & MEM_MAPPED) || (info.Type & MEM_PRIVATE)) && info.Protect == 0x40)
					{
						if (info.RegionSize >= 0x02000000)
						{
							Globals::hEntryBaseAddress = (DWORD)info.BaseAddress;
						}
					}
				}
				//pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x1ff56b8; // [100 ] [1 / 1]
				//pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x1ff2244; // [100 ] [1 / 1]
				//pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x1ff2240; // [100 ] [1 / 1]
				//pCItemManagerInstance = Globals::hEntryBaseAddress + 0x1ff223c; // [100 ] [1 / 1]
				//pCPythonItemInstance = Globals::hEntryBaseAddress + 0x1ff5788; // [100 ] [1 / 1]
				//pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x1ff7a14; // [100 ] [1 / 1]
				//pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x1ff224c; // [100 ] [1 / 1]
				//pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x1ff2238; // [100 ] [1 / 1]
				//pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x1ff5744; // [100 ] [1 / 1]
				//pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x1FFEA70;

				pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x201ef80; // [97 ] [35 / 36]
				pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x201bb04; // [100 ] [19 / 19]
				pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x201bb00; // [100 ] [7 / 7]
				pCItemManagerInstance = Globals::hEntryBaseAddress + 0x201bafc; // [100 ] [27 / 27]
				pCPythonItemInstance = Globals::hEntryBaseAddress + 0x201f05c; // [100 ] [1 / 1]
				pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x20212e4; // [100 ] [1 / 1]
				pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x201bb0c; // [100 ] [1 / 1]
				pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x201baf8; // [100 ] [56 / 56]
				pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x201f018; // [100 ] [1 / 1]
				pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x2028340;
				break;
			}
		case ServerName::ORIGINS2:
			{
				pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x1d02bd0; // [98 ] [54 / 55]
				pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x1cffe70; // [100 ] [26 / 26]
				pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x1cffe60; // [88 ] [15 / 17]
				pCItemManagerInstance = Globals::hEntryBaseAddress + 0x1cffe7c; // [100 ] [32 / 32]
				pCPythonItemInstance = Globals::hEntryBaseAddress + 0x1d02c58; // [100 ] [3 / 3]
				pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x1D055AC;
				pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x1cffe64; // [100 ] [13 / 13]
				pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x1cffe6c; // [100 ] [66 / 66]
				pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x1d02c14; // [100 ] [5 / 5]
				pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x1D08AE4;
				break;
			}
		case ServerName::CALLIOPE2:
			{
				pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x37ee28; // [100 ] [97 / 97]
				pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x37ee44; // [98 ] [81 / 82]
				pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x37ee34; // [95 ] [39 / 41]
				pCItemManagerInstance = Globals::hEntryBaseAddress + 0x37ee64; // [100 ] [46 / 46]
				pCPythonItemInstance = Globals::hEntryBaseAddress + 0x3b6ee4; // [100 ] [4 / 4]
				pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x37F2F0;
				pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x37ee50; // [100 ] [17 / 17]
				pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x37ee5c; // [99 ] [103 / 104]
				pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x37ee38; // [100 ] [5 / 5]
				pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x34148C;
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
				pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x37a1178; // [100 ] [103 / 103]
				pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x336f4f0; // [1 ] [1 / 77]
				pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x37a11a4; // [98 ] [76 / 77]
				pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x336f4f0; // [4 ] [2 / 42]
				pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x37a1188; // [95 ] [40 / 42]
				pCItemManagerInstance = Globals::hEntryBaseAddress + 0x380c3c0; // [100 ] [41 / 41]
				pCPythonItemInstance = Globals::hEntryBaseAddress + 0x380c3e4; // [100 ] [5 / 5]
				pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x37A8898;
				pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x380c3b0; // [100 ] [7 / 7]
				pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x380c3b8; // [100 ] [103 / 103]
				pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x37a1198; // [100 ] [5 / 5]
				pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x36E064C; 
				break;
			}
		
		case ServerName::CLASSIC:
			{
				pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x44cb08; // [100 ] [98 / 98]
				pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x44a8dc; // [98 ] [78 / 79]
				pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x44a8cc; // [95 ] [41 / 43]
				pCItemManagerInstance = Globals::hEntryBaseAddress + 0x44a8e4; // [97 ] [47 / 48]
				pCPythonItemInstance = Globals::hEntryBaseAddress + 0x44cb18; // [100 ] [3 / 3]
				pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x44EB48;
				pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x44a8d0; // [100 ] [3 / 3]
				pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x44a8d8; // [100 ] [106 / 106]
				pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x44caf4; // [100 ] [3 / 3]
				pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x450EAC;
				break;
			}
		case ServerName::VALIUM://"CPythonGraphic::SetViewport(%d, %d, %d, %d) - Error"
			{
				pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x285cf50; // [100 ] [103 / 103]
				pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x285aadc; // [100 ] [88 / 88]
				pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x285aacc; // [100 ] [40 / 40]
				pCItemManagerInstance = Globals::hEntryBaseAddress + 0x285aae8; // [100 ] [48 / 48]
				pCPythonItemInstance = Globals::hEntryBaseAddress + 0x285d040; // [100 ] [7 / 7]
				pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x285F180; // [98 ] [74 / 75]
				pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x285aad0; // [100 ] [6 / 6]
				pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x285aad8; // [100 ] [120 / 120]
				pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x285cf88; // [100 ] [4 / 4]
				pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x28615A4;
				break;
			}
		case ServerName::DEVERIA://"CPythonGraphic::SetViewport(%d, %d, %d, %d) - Error"
			{
				pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x31aadc; // [100 ] [103 / 103]
				pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x31e7b0; // [98 ] [81 / 82]
				pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x31aae4; // [95 ] [42 / 44]
				pCItemManagerInstance = Globals::hEntryBaseAddress + 0x31e7c4; // [96 ] [48 / 50]
				pCPythonItemInstance = Globals::hEntryBaseAddress + 0x31e7f4; // [100 ] [4 / 4]
				pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x31B048; 
				pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x31e7d8; // [100 ] [8 / 8]
				pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x31e7d0; // [99 ] [102 / 103]
				pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x31aaf0; // [100 ] [6 / 6]
				pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x2DE2AC; 
				break;
			}
		case ServerName::DRAGON://"CPythonGraphic::SetViewport(%d, %d, %d, %d) - Error"
			{
				pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x2492f58; // [100 ] [1 / 1]
				pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x249c330; // [100 ] [1 / 1]
				pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x2492f60; // [100 ] [1 / 1]
				pCItemManagerInstance = Globals::hEntryBaseAddress + 0x249c344; // [100 ] [1 / 1]
				pCPythonItemInstance = Globals::hEntryBaseAddress + 0x249c37c; // [100 ] [1 / 1]
				pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x24940E0;
				pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x249c354; // [100 ] [1 / 1]
				pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x249c34c; // [100 ] [1 / 1]
				pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x2492f68; // [100 ] [7 / 7]
				pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x2409A44;
				break;
			}
		case ServerName::NEVILLA://"CPythonGraphic::SetViewport(%d, %d, %d, %d) - Error"
			{
				pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x124e85c; // [100 ] [103 / 103]
				pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x124e874; // [98 ] [84 / 85]					
				pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x124e860; // [95 ] [41 / 43]
				pCItemManagerInstance = Globals::hEntryBaseAddress + 0x1252bc4; // [97 ] [45 / 46]
				pCPythonItemInstance = Globals::hEntryBaseAddress + 0x1252be4; // [100 ] [4 / 4]
				pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x124F0E8;
				pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x1252bc0; // [100 ] [8 / 8]
				pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x1252bb0; // [100 ] [106 / 106]
				pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x124e86c; // [100 ] [3 / 3]
				pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x11CFB7C;
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
					if ((info.State == MEM_COMMIT) && ((info.Type & MEM_MAPPED) || (info.Type & MEM_PRIVATE)) && info.Protect == 0x40)
					{
						if (info.RegionSize >= 0x02000000)
						{
							Globals::hEntryBaseAddress = (DWORD)info.BaseAddress;
						}
					}
				}
				//pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x39c240; // [100 ] [1 / 1]
				//pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x76c80; // [100 ] [1 / 1]
				//pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x54cb0; // [100 ] [1 / 1]
				//pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x54c70; // [100 ] [1 / 1]
				//pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x598c0; // [100 ] [1 / 1]
				//pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x59910; // [100 ] [1 / 1]
				//pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x58e60; // [100 ] [1 / 1]
				//pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x732f0; // [100 ] [1 / 1]
				//pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x56a90; // [100 ] [1 / 1]
				//pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x565a0; // [100 ] [1 / 1]
				//pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x731e0; // [100 ] [1 / 1]
				//pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x72d30; // [100 ] [1 / 1]
				//pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x73170; // [100 ] [1 / 1]
				//pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x6a3d0; // [100 ] [1 / 1]
				//pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x550A0;
				//pCItemDataGetName = Globals::hEntryBaseAddress + 0x39ebb0; // [100 ] [1 / 1]
				//pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x3a1340; // [100 ] [1 / 1]
				//pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x76bc0; // [100 ] [1 / 1]
				//pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x426ba0; // [100 ] [1 / 1]
				//pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x1e7800; // [100 ] [1 / 1]
				//pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x1e58d0; // [100 ] [1 / 1]
				//pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x426a10; // [100 ] [1 / 1]
				//pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x4269c0; // [100 ] [1 / 1]
				//pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x4270D0; // [100 ] [1 / 1]
				//pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x427080; // [100 ] [1 / 1]
				//pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x4270f0; // [100 ] [1 / 1]
				//pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x3c4d50; // [100 ] [1 / 1]
				//pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x1c23a0; // [100 ] [1 / 1]
				//pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x1c1860; // [100 ] [1 / 1]
				//pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x83710; // [100 ] [1 / 1]
				//pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x14c3a0; // [100 ] [1 / 1]
				//pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x9a300; // [100 ] [1 / 1]
				//pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x1e59b0; // [100 ] [1 / 1]
				//pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x1e7750; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x1fc720; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x1fc290; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x1f6760; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x1f6920; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x20aa00; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x1fb660; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x1fb5c0; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x1fb490; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendFishingQuitPacket = Globals::hEntryBaseAddress + 0x200bb0; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x200b60; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x200C00; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x219930; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x219b40; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x219db0; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x219700; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x1f8aa0; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x2016b0; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x1fb9d0; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x1fc6c0; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x219560; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x219500; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x219610; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x1fc2f0; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x1f68d0; // [100 ] [1 / 1]
				//pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x1f82f0; // [100 ] [1 / 1]
				//pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x1e8b80; // [100 ] [1 / 1]
				//pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xe5180; // [100 ] [1 / 1]
				//pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x11dc90; // [100 ] [1 / 1]
				//pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xeeba0; // [100 ] [1 / 1]
				//pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0xef0e0; // [100 ] [1 / 1]
				//pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xedef0; // [100 ] [1 / 1]
				//pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xee750; // [100 ] [1 / 1]
				//pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xee060; // [100 ] [1 / 1]
				//pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xee710; // [100 ] [1 / 1]
				//pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x105410; // [100 ] [1 / 1]
				//pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xf0a40; // [100 ] [1 / 1]
				//pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xf0a10; // [100 ] [1 / 1]
				//pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x106080; // [100 ] [1 / 1]
				//pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xed9f0; // [100 ] [1 / 1]
				//pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x106fa0; // [100 ] [1 / 1]
				//pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x105470; // [100 ] [1 / 1]
				//pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x105920; // [100 ] [1 / 1]
				//pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x105a60; // [100 ] [1 / 1]
				//pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x429d40; // [100 ] [1 / 1]
				//pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x414820; // [100 ] [1 / 1]
				//pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x43cb50; // [100 ] [1 / 1]
				//pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x460830; // [100 ] [1 / 1]
				//pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x40b710; // [100 ] [1 / 1]
				//pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x4278d0; // [100 ] [1 / 1]
				//pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x72BF0;
				//pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x73210;
				//pCPythonNetworkStreamSendCommandPacket = Globals::hEntryBaseAddress + 0x20B9F0;

				pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x3a2280; // [100 ] [1 / 1]
				pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x76ea0; // [100 ] [1 / 1]
				pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x54cb0; // [100 ] [1 / 1]
				pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x54c70; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x599c0; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x59a10; // [100 ] [1 / 1]
				pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x58f30; // [100 ] [1 / 1]
				pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x734c0; // [100 ] [1 / 1]
				pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x56B30; // [100 ] [1 / 1]
				pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x56620; // [100 ] [1 / 1]
				pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x733b0; // [100 ] [1 / 1]
				pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x72f00; // [100 ] [1 / 1]
				pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x73340; // [100 ] [1 / 1]
				pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x6a5a0; // [100 ] [1 / 1]
				pCItemDataGetName = Globals::hEntryBaseAddress + 0x3a4bf0; // [100 ] [1 / 1]
				pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x3a7380; // [100 ] [1 / 1]
				pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x76de0; // [100 ] [1 / 1]
				pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x42d2c0; // [100 ] [1 / 1]
				pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x1e99a0; // [100 ] [1 / 1]
				pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x1e7a00; // [100 ] [1 / 1]
				pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x42d130; // [100 ] [1 / 1]
				pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x42d0e0; // [100 ] [1 / 1]
				pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x42d770; // [100 ] [1 / 1]
				pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x42d7a0; // [100 ] [1 / 1]
				pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x42d810; // [100 ] [1 / 1]
				pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x3cae10; // [100 ] [1 / 1]
				pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x1c4260; // [100 ] [1 / 1]
				pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x1c36f0; // [100 ] [1 / 1]
				pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x841f0; // [100 ] [1 / 1]
				pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x14d6d0; // [100 ] [1 / 1]
				pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x9afa0; // [100 ] [1 / 1]
				pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x1e7ae0; // [100 ] [1 / 1]
				pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x1e98f0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x1FF460; // 
				pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x1fef90; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x1f8f90; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x1f9190; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x20E810; 
				pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x1fdf80; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x1fdec0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x1fdd50; // [100 ] [2 / 2]
				pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x1070E0; 
				pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x203EE0; 
				pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x21f640; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x21f870; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x21fb00; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x21f3d0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x1fb340; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x1fe330; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x1ff3e0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x21f1d0; // [100 ] [1 / 1] 
				pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x21f150; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x1EF6F0; 
				pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x1ff010; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x1f9120; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x1FAB70; 
				pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x1ead20; // [100 ] [1 / 1]
				pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xe5f50; // [100 ] [1 / 1]
				pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x11ee60; // [100 ] [1 / 1]
				pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xef900; // [100 ] [1 / 1]
				pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0xefe40; // [100 ] [1 / 1]
				pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xeec00; // [100 ] [1 / 1]
				pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xef460; // [100 ] [1 / 1]
				pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xeed70; // [100 ] [1 / 1]
				pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xef420; // [100 ] [1 / 1]
				pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x1063d0; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xf17a0; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xf1770; // [100 ] [1 / 1]
				pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x1070e0; // [100 ] [1 / 1]
				pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xee6c0; // [100 ] [1 / 1]
				pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x108000; // [100 ] [1 / 1]
				pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x106430; // [100 ] [1 / 1]
				pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x106960; // [100 ] [1 / 1]
				pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x106ac0; // [100 ] [1 / 1]
				pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x430460; // [100 ] [1 / 1]
				pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x41af40; // [93 ] [14 / 15]
				pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x443270; // [100 ] [1 / 1]
				pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x466f50; // [100 ] [1 / 1]
				pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x4119c0; // [100 ] [1 / 1]
				pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x42dff0; // [100 ] [1 / 1]
				pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x72dc0; // [100 ] [1 / 1]
				pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x733e0; // [100 ] [1 / 1]
				pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x550a0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendCommandPacket = Globals::hEntryBaseAddress + 0x20F8D0;
				break;
			}
		case ServerName::ORIGINS2:
		{
				pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x41cb10; // [100 ] [1 / 1]
				pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x19c750; // [100 ] [1 / 1]
				pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x41c6d0; // [100 ] [1 / 1]
				pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x174c10; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x173910; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x173a10; // [100 ] [1 / 1]
				pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x1738b0; // [100 ] [1 / 1]
				pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x196190; // [100 ] [1 / 1]
				pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x174960; // [100 ] [1 / 1]
				pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x174510; // [100 ] [1 / 1]
				pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x1960c0; // [100 ] [1 / 1]
				pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x1954e0; // [100 ] [1 / 1]
				pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x196050; // [100 ] [1 / 1]
				pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x188fb0; // [100 ] [1 / 1]
				pCItemDataGetName = Globals::hEntryBaseAddress + 0x40f3e0; // [100 ] [1 / 1]
				pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x4238a0; // [100 ] [1 / 1]
				pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x19a240; // [100 ] [1 / 1]
				pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x3b1b60; // [100 ] [1 / 1]
				pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x319f80; // [100 ] [1 / 1]
				pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x319210; // [100 ] [1 / 1]
				pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x3b1df0; // [100 ] [1 / 1]
				pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x3b1e60; // [100 ] [2 / 2]
				pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x3b20c0; // [100 ] [1 / 1]
				pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x3b2140; // [100 ] [1 / 1]
				pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x3B21D0; 
				pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x439bc0; // [100 ] [1 / 1]
				pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x2c8ab0; // [100 ] [1 / 1]
				pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x2c8850; // [100 ] [1 / 1]
				pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x1aae40; // [100 ] [1 / 1]
				pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x245d00; // [100 ] [1 / 1]
				pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x1c4620; // [100 ] [1 / 1]
				pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x3193a0; // [100 ] [1 / 1]
				pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x319630; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x32ac70; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x32a3e0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x32a440; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x32d380; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x66ae; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x32a8b0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x32a790; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x32a700; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x32bab0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x32BB10; 
				pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x18787; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x3441b0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x3443b0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x343df0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x32ab90; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x32a990; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x32acf0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x344600; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x3445a0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x344730; 
				pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x329eb0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x32a5a0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x32d540; // [100 ] [1 / 1]
				pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x31cbf0; // [100 ] [1 / 1]
				pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x1e3340; // [100 ] [1 / 1]
				pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x215bf0; // [100 ] [1 / 1]
				pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x1eef00; // [100 ] [1 / 1]
				pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x1ef070; // [100 ] [1 / 1]
				pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x1ee2c0; // [100 ] [1 / 1]
				pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x1738b0; // [100 ] [1 / 1]
				pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x426190; // [100 ] [1 / 1]
				pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x1ee850; // [100 ] [1 / 1]
				pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x2047a0; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x1f02a0; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x1f02d0; // [100 ] [1 / 1]
				pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x204080;
				pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x1ed760; // [100 ] [1 / 1]
				pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x205e60; // [100 ] [1 / 1]
				pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x204470; // [100 ] [1 / 1]
				pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x204a80; // [100 ] [1 / 1]
				pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x204880; // [100 ] [1 / 1]
				pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x3b63f0; // [100 ] [1 / 1]
				pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x3a37b0; // [100 ] [1 / 1]
				pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x3cb040; // [100 ] [1 / 1]
				pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x486c20; // [100 ] [1 / 1]
				pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x2d0580; // [100 ] [1 / 1]
				pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x3b2920; // [100 ] [1 / 1]
				pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x194f20; // [100 ] [1 / 1]
				pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x1961d0; // [100 ] [1 / 1]
				pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x178ac0; // [100 ] [1 / 1]
			break;
		}
		case ServerName::CALLIOPE2:
			{
				pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x17b9d0; // [100 ] [1 / 1]
				pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x854D0;
				pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x17b540; // [100 ] [1 / 1]
				pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x69dd0; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x6e070; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x6e090; // [100 ] [1 / 1]
				pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x6d210; // [100 ] [1 / 1]
				pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x76120; // [100 ] [1 / 1]
				pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x6b990; // [100 ] [1 / 1]
				pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x6b580; // [100 ] [1 / 1]
				pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x76040; // [100 ] [1 / 1]
				pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x75cc0; // [100 ] [1 / 1]
				pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x75fe0; // [100 ] [1 / 1]
				pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x73100; // [100 ] [1 / 1]
				pCItemDataGetName = Globals::hEntryBaseAddress + 0x17f390; // [100 ] [1 / 1]
				pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x17d450; // [100 ] [1 / 1]
				pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x85400; // [100 ] [1 / 1]
				pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x12f860; // [100 ] [1 / 1]
				pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0xad870; // [100 ] [1 / 1]
				pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0xad090; // [100 ] [1 / 1]
				pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x12fa30; // [100 ] [1 / 1]
				pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x12fa70; // [100 ] [1 / 1]
				pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x12fc70; // [100 ] [2 / 2]
				pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x12fcb0; // [100 ] [1 / 1]
				pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x69d20; // [100 ] [1 / 1]
				pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x191e00; // [100 ] [1 / 1]
				pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x7c450; // [100 ] [1 / 1]
				pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x7bff0; // [100 ] [1 / 1]
				pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x88b50; // [100 ] [21 / 21] 
				pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x8f870; // [100 ] [1 / 1]
				pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x95b30; // [100 ] [1 / 1]
				pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0xad180; // [100 ] [1 / 1]
				pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x6d2a0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0xb74b0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0xb7010; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0xb45e0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0xb47b0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0xad960; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0xb6560; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0xb64e0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0xb63e0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0xb9670; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0xb96d0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0xbd7c0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0xbdb20; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0xbdd40; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0xbd600; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0xb55f0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0xb67f0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0xb73b0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0xbd420; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0xbd3d0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0xbd520; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0xb70a0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0xb4740; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0xb5120; // [100 ] [1 / 1]
				pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0xae440; // [100 ] [1 / 1]
				pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xc0a40; // [82 ] [14 / 17]
				pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0xd08d0; // [100 ] [1 / 1]
				pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xC2B30;
				pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0xc3060; // [100 ] [1 / 1]
				pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xc20d0; // [100 ] [1 / 1]
				pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xc25d0; // [100 ] [2 / 2]
				pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x9ab30; // [100 ] [1 / 1]
				pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xc25a0; // [100 ] [1 / 1]
				pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0xc6f20; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xc3e70; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xc3e50; // [100 ] [1 / 1]
				pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0xc7700; // [100 ] [1 / 1]
				pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xc1dd0; // [100 ] [1 / 1]
				pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0xc7fb0; // [100 ] [1 / 1]
				pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0xc6f60; // [100 ] [1 / 1]
				pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0xc71e0; // [100 ] [1 / 1]
				pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0xc7280; // [100 ] [1 / 1]
				pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x879d0; // [100 ] [1 / 1]
				pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x133810; // [100 ] [1 / 1]
				pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x135020; // [100 ] [1 / 1]
				pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x1b9ac0; // [100 ] [1 / 1]
				pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x7efe0; // [100 ] [1 / 1]
				pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x1399c0; // [100 ] [1 / 1]
				pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x75c00; // [100 ] [1 / 1]
				pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x76070; // [100 ] [1 / 1]
				pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x6a0d0; // [100 ] [1 / 1]
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
			
				pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x199250; // [100 ] [1 / 1]
				pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x625e0; // [100 ] [1 / 1]
				pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x45870; // [100 ] [1 / 1]
				pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x45850; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x48da0; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x48dc0; // [100 ] [1 / 1]
				pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x3c8e0; // [100 ] [1 / 1]
				pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x53a20; // [100 ] [1 / 1]
				pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x46c80; // [100 ] [1 / 1]
				pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x46920; // [100 ] [1 / 1]
				pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x53940; // [100 ] [1 / 1]
				pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x535c0; // [100 ] [1 / 1]
				pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x538e0; // [100 ] [1 / 1]
				pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x508c0; // [100 ] [1 / 1]
				pCItemDataGetName = Globals::hEntryBaseAddress + 0x19cfa0; // [100 ] [1 / 1]
				pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x19af00; // [100 ] [1 / 1]
				pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x624f0; // [100 ] [1 / 1]
				pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x14a170; // [100 ] [1 / 1]
				pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x8c720; // [100 ] [1 / 1]
				pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x8bec0; // [100 ] [1 / 1]
				pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x14a290; // [100 ] [1 / 1]
				pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x14a2d0; // [100 ] [1 / 1]
				pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x14a4e0; // [100 ] [1 / 1]
				pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x14a520; // [100 ] [1 / 1]
				pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x14a570; // [100 ] [1 / 1]
				pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x1af790; // [100 ] [1 / 1]
				pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x5ad70; // [100 ] [1 / 1]
				pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x5a3d0; // [100 ] [1 / 1]
				pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x660c0; // [100 ] [1 / 1]
				pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x6ce40; // [100 ] [1 / 1]
				pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x71c80; // [100 ] [1 / 1]
				pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x8bfb0; // [100 ] [1 / 1]
				pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x8c660; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x98900; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x98480; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x95940; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x95b20; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x8c810; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x97a90; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x97a10; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x978b0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x9a9a0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x9aa00; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0xa1d10; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0xa1e80; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0xa1fd0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0xa1b30; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x96960; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x97cf0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x98820; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0xa1980; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0xa1930; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0xa1a80; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x98500; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x95ab0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x963f0; // [100 ] [1 / 1]
				pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x8d570; // [100 ] [1 / 1]
				pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xa5140; // [100 ] [1 / 1]
				pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0xb5d30; // [100 ] [1 / 1]
				pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xAABB0; 
				pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x19d090; // [100 ] [1 / 1]
				pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xaa1e0; // [100 ] [1 / 1]
				pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x3c8e0; // [100 ] [1 / 1]
				pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xaa240; // [100 ] [1 / 1]
				pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xaa6d0; // [100 ] [1 / 1]
				pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0xae610; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xabaa0; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xaba80; // [100 ] [1 / 1]
				pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0xaede0; // [100 ] [1 / 1]
				pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xa9ee0; // [100 ] [1 / 1]
				pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0xaf5b0; // [100 ] [1 / 1]
				pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0xae650; // [100 ] [1 / 1]
				pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0xaeb00; // [100 ] [1 / 1]
				pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0xae970; // [100 ] [1 / 1]
				pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x65930; // [100 ] [1 / 1]
				pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x14e8c0; // [100 ] [1 / 1]
				pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x153210; // [100 ] [1 / 1]
				pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x1db5d0; // [100 ] [1 / 1]
				pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x5d820; // [100 ] [1 / 1]
				pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x157bc0; // [100 ] [1 / 1]
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
				pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x65e60; // [100 ] [1 / 1]
				pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x72d20; // [100 ] [1 / 1]
				pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x17d550; // [100 ] [1 / 1]
				pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x64cb0; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x65d30; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x65ed0; // [100 ] [1 / 1]
				pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x65e60; // [100 ] [1 / 1]
				pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x70140; // [100 ] [1 / 1]
				pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x662a0; // [100 ] [1 / 1]
				pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x66480; // [100 ] [1 / 1]
				pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x70150; // [100 ] [1 / 1]
				pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x6fac0; // [100 ] [1 / 1]
				pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x70200; // [100 ] [1 / 1]
				pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x6e800; // [100 ] [1 / 1]
				pCItemDataGetName = Globals::hEntryBaseAddress + 0x1735d0; // [100 ] [1 / 1]
				pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x182a90; // [100 ] [1 / 1]
				pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x72f80; // [100 ] [1 / 1]
				pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x12c870; // [100 ] [1 / 1]
				pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0xd5fb0; // [100 ] [1 / 1]
				pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0xd5780; // [100 ] [1 / 1]
				pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x12c990; // [100 ] [1 / 1]
				pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x12ca00; // [100 ] [1 / 1]
				pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x12cc00; // [100 ] [1 / 1]
				pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x12cc40; // [100 ] [1 / 1]
				pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x16c0c0; // [100 ] [1 / 1]
				pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x1934b0; // [100 ] [1 / 1]
				pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0xc2510; // [100 ] [1 / 1]
				pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0xc2c10; // [100 ] [1 / 1]
				pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x77e40; // [100 ] [1 / 1]
				pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0xa5f60; // [100 ] [1 / 1]
				pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x80af0; // [100 ] [1 / 1]
				pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0xd5570; // [100 ] [1 / 1]
				pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0xd5890; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0xe1200; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0xe0800; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0xe0950; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0xe0aa0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0xd5b20; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0xe0f90; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0xe10b0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0xe1120; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0xe11a0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0xe1290; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0xe4600; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0xe4670; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0xe47a0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0xe47f0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0xe1af0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0xe1e90; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0xe1f40; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0xe4b90; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0xe4c00; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0xe4cc0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0xe1f80; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0xe2080; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0xe20e0; // [100 ] [1 / 1]
				pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0xd6500; // [100 ] [1 / 1]
				pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x87620; // [100 ] [1 / 1]
				pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x93e60; // [100 ] [1 / 1]
				pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x89920; 
				pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x89980; // [100 ] [1 / 1]
				pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x89b70; // [100 ] [1 / 1]
				pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x89b80; // [100 ] [1 / 1]
				pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x89c60; // [100 ] [1 / 1]
				pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x89e20; // [100 ] [1 / 1]
				pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x8e040; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x8a2c0; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x8a2f0; // [100 ] [1 / 1]
				pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x8d5b0; // [100 ] [1 / 1]
				pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x8a6b0; // [100 ] [1 / 1]
				pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x8e8c0; // [100 ] [1 / 1]
				pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x8dbf0; // [100 ] [1 / 1]
				pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x8e180; // [100 ] [1 / 1]
				pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x8e1d0; // [100 ] [1 / 1]
				pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x130320; // [100 ] [1 / 1]
				pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x122e40; // [100 ] [1 / 1]
				pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x13ed30; // [100 ] [1 / 1]
				pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x1d0600; // [100 ] [1 / 1]
				pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0xc53f0; // [100 ] [1 / 1]
				pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x12d2e0; // [100 ] [1 / 1]
				pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x6f800; // [100 ] [1 / 1]
				pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x702a0; // [100 ] [1 / 1]
				pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x68a00; // [100 ] [1 / 1]
				break;
			}
		case ServerName::VALIUM:
			{
				pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x1d0740; // [100 ] [1 / 1]
				pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0xac760; // [100 ] [1 / 1]
				pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x98e50; // [100 ] [1 / 1]
				pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x98e90; // [100 ] [4 / 4]
				pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x97ae0; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x97ba0; // [100 ] [1 / 1]
				pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x97ac0; // [100 ] [1 / 1]
				pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0xa7220; // [100 ] [1 / 1]
				pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x98c10; // [100 ] [1 / 1]
				pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x98860; // [100 ] [1 / 1]
				pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0xa7160; // [100 ] [1 / 1]
				pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0xa6a20; // [100 ] [1 / 1]
				pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0xa70e0; // [100 ] [1 / 1]
				pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0xa1290; // [100 ] [1 / 1]
				pCItemDataGetName = Globals::hEntryBaseAddress + 0x1c6e00; // [100 ] [4 / 4]
				pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x1d4940; // [100 ] [1 / 1]
				pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0xaa8b0; // [100 ] [1 / 1]
				pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x195e70; // [100 ] [1 / 1]
				pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x144d00; // [100 ] [1 / 1]
				pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x144100; // [100 ] [1 / 1]
				pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x196060; // [100 ] [1 / 1]
				pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x1960a0; // [100 ] [1 / 1]
				pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x1962b0; // [100 ] [1 / 1]
				pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x1962f0; // [100 ] [1 / 1]
				pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x196340; // [100 ] [1 / 1]
				pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x1e0140; // [100 ] [1 / 1]
				pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x127c90; // [100 ] [1 / 1]
				pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x1275c0; // [100 ] [1 / 1]
				pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0xb4490; // [100 ] [1 / 1]
				pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0xfa0d0; // [100 ] [1 / 1]
				pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0xbe350; // [100 ] [1 / 1]
				pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x144280; // [100 ] [1 / 1]
				pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x1444a0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x14e310; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x14d9d0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x14da40; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x14ffa0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x143c80; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x14df00; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x14dda0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x14dd20; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x14f0f0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x14f180; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x15ba00; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x15ba80; // [100 ] [2 / 2]
				pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x15bde0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x15b7c0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x14e230; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x14e030; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x14e390; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x15bfe0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x15bf80; // [100 ] [2 / 2]
				pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x15c110; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x14d5f0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x14dbd0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x1500c0; // [100 ] [1 / 1]
				pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x1463b0; // [100 ] [1 / 1]
				pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xc9540; // [100 ] [1 / 1]
				pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0xdf810; // [100 ] [1 / 1]
				pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xcc120; // [100 ] [1 / 1]
				pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0xcc3e0; // [100 ] [1 / 1]
				pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xcb800; // [100 ] [1 / 1]
				pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xcba30; // [100 ] [1 / 1]
				pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xcbc90; // [83 ] [5 / 6] 
				pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xcba90; // [100 ] [2 / 2][1 / 1]
				pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0xd4100; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xcd1f0; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xcd220; // [100 ] [1 / 1]
				pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0xd3a70; // [100 ] [2 / 2]
				pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xcb090; // [100 ] [1 / 1]
				pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0xd50f0; // [100 ] [1 / 1]
				pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0xd3e70; // [100 ] [1 / 1]
				pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0xd43d0; // [100 ] [1 / 1]
				pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0xd41f0; // [100 ] [1 / 1]
				pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x5cd10; // [100 ] [1 / 1]
				pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x18ecc0; // [100 ] [1 / 1]
				pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x1952B0; // [100 ] [1 / 1]
				pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x211620; // [100 ] [1 / 1]
				pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x12b5c0; // [100 ] [1 / 1]
				pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x196840; // [100 ] [1 / 1]
				pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0xa6560; // [100 ] [6 / 6]
				pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0xa7260; // [100 ] [4 / 4]
				pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x9c010; // [100 ] [4 / 4]
			}
		case ServerName::DEVERIA:
			{
				pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x1981e0; // [100 ] [1 / 1]
				pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x78b10; // [100 ] [1 / 1]
				pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x5eca0; // [100 ] [1 / 1]
				pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x5ec80; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x61cc0; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x61ce0; // [100 ] [1 / 1]
				pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x61690; // [100 ] [1 / 1]
				pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x6b1c0; // [100 ] [1 / 1]
				pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x5ff20; // [100 ] [1 / 1]
				pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x5fbe0; // [100 ] [1 / 1]
				pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x6b0e0; // [100 ] [1 / 1]
				pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x6ad60; // [100 ] [1 / 1]
				pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x6b080; // [100 ] [1 / 1]
				pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x67c10; // [100 ] [1 / 1]
				pCItemDataGetName = Globals::hEntryBaseAddress + 0x19be80; // [83 ] [5 / 6]
				pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x199f40; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0xa7b70; // [100 ] [1 / 1]
				pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x14a4b0; // [100 ] [1 / 1]
				pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0xa08f0; // [100 ] [1 / 1]
				pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0xa00e0; // [100 ] [1 / 1]
				pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x14a6a0; // [100 ] [1 / 1]
				pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x14a6e0; // [100 ] [1 / 1]
				pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x14a8f0; // [100 ] [1 / 1]
				pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x14a930; // [100 ] [1 / 1]
				pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x14a980; // [100 ] [1 / 1]
				pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x1adfe0; // [100 ] [1 / 1]
				pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x71500; // [100 ] [1 / 1]
				pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x70b40; // [100 ] [1 / 1]
				pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x7c0a0; // [100 ] [1 / 1]
				pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x82cc0; // [100 ] [1 / 1]
				pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x882e0; // [100 ] [1 / 1]
				pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0xa01c0; // [100 ] [1 / 1]
				pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0xa0840; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0xa9d50; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0xa98c0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0xa7160; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0xa7350; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0xa09e0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0xa8fb0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0xa8f30; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0xa8dc0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0xabcd0; // [75 ] [3 / 4]
				pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0xabd30; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0xafa70; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0xafc30; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0xafd60; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0xaf8b0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0xa8070; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0xa91f0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0xa9c70; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0xaf6e0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0xaf680; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0xaf800; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0xa9930; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0xa72e0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0xa7b70; // [100 ] [1 / 1]
				pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0xa13d0; // [100 ] [1 / 1]
				pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xb2c70; // [80 ] [8 / 10]
				pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0xcddf0; // [100 ] [1 / 1]
				pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xB4550;
				pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0xb4880; // [100 ] [1 / 1]
				pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xb3c30; // [100 ] [1 / 1]
				pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xb40d0; // [100 ] [1 / 1]
				pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x8d730; // [100 ] [1 / 1]
				pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xb40a0; // [100 ] [1 / 1]
				pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0xb8010; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xb54a0; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xb5480; // [100 ] [1 / 1]
				pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0xb8830; // [100 ] [1 / 1]
				pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xb3920; // [100 ] [1 / 1]
				pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0xb9070; // [100 ] [1 / 1]
				pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0xb8050; // [100 ] [1 / 1]
				pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0xb8520; // [100 ] [1 / 1]
				pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0xb8390; // [100 ] [1 / 1]
				pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x7b870; // [100 ] [1 / 1]
				pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x150a10; // [100 ] [1 / 1]
				pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x1604F0; // [100 ] [1 / 1]
				pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x1d8b10; // [100 ] [1 / 1]
				pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x74000; // [100 ] [1 / 1]
				pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x156640; // [100 ] [1 / 1]
				pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x6aca0; // [100 ] [1 / 1]
				pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x6b110; // [100 ] [1 / 1]
				pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x5ef80; // [100 ] [1 / 1]
				break;
			}
		case ServerName::DRAGON:
			{
				pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x2f6e70; // [100 ] [1 / 1]
				pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0xce080; // [100 ] [1 / 1]
				pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x90440; // [100 ] [1 / 1]
				pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x90420; // [100 ] [1 / 1] 
				pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x93860; // [100 ] [1 / 1]
				pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x93880; // [100 ] [1 / 1]
				pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x805b0; // [100 ] [1 / 1]
				pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0xa6ac0; // [100 ] [1 / 1]
				pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x91680; // [100 ] [1 / 1]
				pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x91320; // [100 ] [1 / 1]
				pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0xa69e0; // [100 ] [1 / 1]
				pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0xa65a0; // [100 ] [1 / 1]
				pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0xa6980; // [100 ] [1 / 1]
				pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0xa1340; // [100 ] [1 / 1]
				pCItemDataGetName = Globals::hEntryBaseAddress + 0x2fd490; // [100 ] [1 / 1]
				pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x39980c; // [100 ] [1 / 1]
				pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0xcdf90; // [100 ] [1 / 1]
				pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x25ce60; // [100 ] [1 / 1]
				pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x510AE0;
				pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x110290;
				pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x25cfd0; // [100 ] [1 / 1]
				pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x25d040; // [100 ] [1 / 1]
				pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x25d250; // [100 ] [1 / 1] 
				pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x25D290; // [100 ] [1 / 1]
				pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x25d310; // [100 ] [1 / 1]
				pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x322400; // [100 ] [1 / 1]
				pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0xc4e40; // [100 ] [1 / 1]
				pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0xc4480; // [100 ] [1 / 1]
				pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0xd50d0; // [100 ] [1 / 1]
				pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0xdeeb0; // [100 ] [1 / 1]
				pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0xea6a0; // [100 ] [3 / 3]
				pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x110370; // [100 ] [1 / 1]
				pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x110180; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x11BF40;
				pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x11bb50; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x1190e0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x1192c0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x110bf0; // [100 ] [2 / 2]
				pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x11b0e0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x11b060; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x11aef0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x11df40; // [100 ] [3 / 3]
				pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x11dfa0; // [100 ] [2 / 2]
				pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x128250; // [100 ] [2 / 2]
				pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x1283d0; // [100 ] [3 / 3]
				pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x128520; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x128030; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x11a0c0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x11b370; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x11bef0; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x127e80; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x127e30; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x127f80; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x11BBD0;
				pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x119250; // [100 ] [1 / 1]
				pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x119b60; // [100 ] [1 / 1]
				pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x111c90; // [100 ] [1 / 1]
				pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x12B930; // [28 ] [2 / 7]
				//##########pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x12b930; // [71 ] [5 / 7]
				pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x143210; // [100 ] [1 / 1]
				pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x1350D0;
				pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x1353f0; // [66 ] [2 / 3]
				//########pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x2fd570; // [33 ] [1 / 3]
				pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x134690; // [100 ] [1 / 1]
				pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x805b0; // [100 ] [1 / 1]
				pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xf2be0; // [100 ] [1 / 1]
				pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x134bc0; // [100 ] [1 / 1]
				pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x13a5d0; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x1360e0; // [100 ] [1 / 1]
				pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x1360c0; // [100 ] [1 / 1] 
				pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x13ae60; // [100 ] [1 / 1]
				pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x134370; // [100 ] [1 / 1]
				pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x13b690; // [100 ] [1 / 1]
				pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x13a660; // [100 ] [1 / 1]
				pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x13ab50; // [100 ] [1 / 1]
				pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x13a9c0; // [100 ] [1 / 1]
				pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x2985b0; // [100 ] [1 / 1]
				pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x2684a0; // [100 ] [2 / 2]
				pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x26c9d0; // [100 ] [5 / 5]
				pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x36FB30;
				pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0xc8940; // [100 ] [1 / 1]
				pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x2743f0; // [100 ] [1 / 1]
				pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0xa64d0; // [100 ] [1 / 1]
				pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0xa6a10; // [100 ] [1 / 1]
				pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x90760; // [100 ] [1 / 1]
				break;
			}
		case ServerName::NEVILLA:
			{
				
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

