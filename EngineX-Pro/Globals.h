
#pragma once


class Globals
{
public:
	//######################################################################################################################################
	static ServerName Server;
	static bool PythonCustom;
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

	static void ReAddressingLocas();
	static void ReDeclarationLocals();
};
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


ServerName Globals::Server = ServerName::METINPL;
bool Globals::PythonCustom = false;
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
			pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x1fb3098; // [100 ] [1 / 1]
			pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x1fafc24; // [100 ] [1 / 1]
			pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x1fafc20; // [100 ] [1 / 1]
			pCItemManagerInstance = Globals::hEntryBaseAddress + 0x1fafc1c; // [100 ] [1 / 1]
			pCPythonItemInstance = Globals::hEntryBaseAddress + 0x1fb3168; // [100 ] [1 / 1]
			pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x1fb53f4; // [100 ] [1 / 1]
			pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x1fafc2c; // [100 ] [1 / 1]
			pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x1fafc18; // [100 ] [1 / 1]
			pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x1fb3124; // [100 ] [1 / 1]
			pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x39bfb0; // [100 ] [1 / 1]
			pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x76ca0; // [100 ] [1 / 1]
			pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x54cb0; // [100 ] [1 / 1]
			pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x54c70; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x598c0; // [100 ] [1 / 1]
			pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x59910; // [100 ] [1 / 1]
			pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x58e60; // [100 ] [1 / 1]
			pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x73310; // [100 ] [1 / 1]
			pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x56a90; // [100 ] [1 / 1]
			pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x565a0; // [100 ] [1 / 1]
			pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x73200; // [100 ] [1 / 1]
			pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x72d50; // [100 ] [1 / 1]
			pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x73190; // [100 ] [1 / 1]
			pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x6a3f0; // [100 ] [1 / 1]
			pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x550A0;
			pCItemDataGetName = Globals::hEntryBaseAddress + 0x39e920; // [100 ] [1 / 1]
			pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x3a10b0; // [100 ] [1 / 1]
			pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x76be0; // [100 ] [1 / 1]
			pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x426900; // [100 ] [1 / 1]
			pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x1e75d0; // [100 ] [1 / 1]
			pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x1e56a0; // [100 ] [1 / 1]
			pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x426770; // [100 ] [1 / 1]
			pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x426720; // [100 ] [1 / 1]
			pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x426db0; // [100 ] [1 / 1]
			pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x426de0; // [100 ] [1 / 1]
			pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x426e50; // [100 ] [1 / 1]
			pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x3c4ac0; // [100 ] [1 / 1]
			pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x1c2180; // [100 ] [1 / 1]
			pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x1c1640; // [100 ] [1 / 1]
			pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x83730; // [100 ] [1 / 1]
			pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x14c340; // [100 ] [1 / 1]
			pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x9a320; // [100 ] [1 / 1]
			pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x1e5780; // [100 ] [1 / 1]
			pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x1e7520; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x1fc4e0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x1fc050; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x1f6520; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x1f66e0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x20a7c0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x1fb420; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x1fb380; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x1fb250; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendFishingQuitPacket = Globals::hEntryBaseAddress + 0x200970; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x200920; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x202710; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x2196a0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x2198b0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x219b20; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x219470; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x1f8860; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x201470; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x1fb790; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x1fc480; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x2192d0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x219270; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x219380; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x1fc0b0; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x1f6690; // [100 ] [1 / 1]
			pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x1f80b0; // [100 ] [1 / 1]
			pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x1e8940; // [100 ] [1 / 1]
			pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xe51a0; // [100 ] [1 / 1]
			pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x11dc30; // [100 ] [1 / 1]
			pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xeebc0; // [100 ] [1 / 1]
			pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0xef0d0; // [100 ] [1 / 1]
			pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xedf10; // [100 ] [1 / 1]
			pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xee770; // [100 ] [1 / 1]
			pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xee080; // [100 ] [1 / 1]
			pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xee730; // [100 ] [1 / 1]
			pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x1053c0; // [100 ] [1 / 1]
			pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xf0a30; // [100 ] [1 / 1]
			pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xf0a00; // [100 ] [1 / 1]
			pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x106030; // [100 ] [1 / 1]
			pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xeda10; // [100 ] [1 / 1]
			pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x106f50; // [100 ] [1 / 1]
			pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x105420; // [100 ] [1 / 1]
			pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x1058d0; // [100 ] [1 / 1]
			pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x105a10; // [100 ] [1 / 1]
			pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x429aa0; // [100 ] [1 / 1]
			pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x414590; // [100 ] [1 / 1]
			pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x43c8b0; // [100 ] [1 / 1]
			pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x460590; // [100 ] [1 / 1]
			pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x40b480; // [100 ] [1 / 1]
			pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x1FBC450;
			pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x427630; // [100 ] [1 / 1]
			pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x72C10;
			pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x73230;
			//pCPythonNetworkStreamSendCommandPacket = Globals::hEntryBaseAddress + (null); 

			//pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x1e9e5d8; // [100 ] [1 / 1]
			//pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x1e9b284; // [100 ] [1 / 1]
			//pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x1e9b280; // [100 ] [1 / 1]
			//pCItemManagerInstance = Globals::hEntryBaseAddress + 0x1e9b27c; // [100 ] [1 / 1]
			//pCPythonItemInstance = Globals::hEntryBaseAddress + 0x1e9e6a8; // [100 ] [1 / 1]
			//pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x1ea0934; // [100 ] [1 / 1]
			//pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x1e9b28c; // [100 ] [1 / 1]
			//pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x1e9b278; // [100 ] [1 / 1]
			//pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x1e9e664; // [100 ] [1 / 1]
			//pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x390fc0; // [100 ] [1 / 1]
			//pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x76ad0; // [100 ] [1 / 1]
			//pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x54cb0; // [100 ] [1 / 1]
			//pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x54c70; // [100 ] [1 / 1]
			//pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x598a0; // [100 ] [1 / 1]
			//pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x598f0; // [100 ] [1 / 1]
			//pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x58e50; // [100 ] [1 / 1]
			//pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x73140; // [100 ] [1 / 1]
			//pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x56A60; // [100 ] [1 / 1]
			//pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x56590; // [100 ] [1 / 1]
			//pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x73030; // [100 ] [1 / 1]
			//pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x72b80; // [100 ] [1 / 1]
			//pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x72fc0; // [100 ] [1 / 1]
			//pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x6a250; // [100 ] [1 / 1]
			//pCItemDataGetName = Globals::hEntryBaseAddress + 0x393930; // [100 ] [1 / 1]
			//pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x3960a0; // [100 ] [1 / 1]
			//pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x76a10; // [100 ] [1 / 1]
			//pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x419bd0; // [100 ] [1 / 1]
			//pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x1dd6f0; // [100 ] [1 / 1]
			//pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x1DB840; // [100 ] [1 / 1]
			//pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x419a40; // [100 ] [1 / 1]
			//pCNetworkStreamPeek = Globals::hEntryBaseAddress + 0x4199f0; // [100 ] [1 / 1]
			//pCNetworkStreamRecv = Globals::hEntryBaseAddress + 0x41a080; // [100 ] [1 / 1]
			//pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x41a0b0; // [100 ] [1 / 1]
			//pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x41a120; // [100 ] [1 / 1]
			//pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x3b8e90; // [100 ] [1 / 1]
			//pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x1b85f0; // [100 ] [1 / 1]
			//pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x1b7ab0; // [100 ] [1 / 1]
			//pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x834a0; // [100 ] [1 / 1]
			//pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x149b50; // [100 ] [1 / 1]
			//pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x99d10; // [100 ] [1 / 1]
			//pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x1db920; // [100 ] [1 / 1]
			//pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x1dd640; // [100 ] [1 / 1]                         
			//pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x1f2060; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x1f1bd0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x1ec2d0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x1ec490; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x200790; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x1f0fa0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x1f0f00; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x1f0dd0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendFishingQuitPacket = Globals::hEntryBaseAddress + 0x1f6c20; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x1f6bd0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x1f88c0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x20e770; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x20e980; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x20ebe0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x20e570; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x1ee500; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x1f7720; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x1f1310; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x1f2000; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x20e3d0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x20e370; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x20e480; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendSpecial = Globals::hEntryBaseAddress + 0x1f1c30; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x1ec440; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x1ede60; // [100 ] [1 / 1]
			//pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x1dea60; // [100 ] [1 / 1]
			//pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0xe3970; // [100 ] [1 / 1]
			//pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x11b5a0; // [100 ] [1 / 1]
			//pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0xed350; // [100 ] [1 / 1]
			//pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0xed860; // [100 ] [1 / 1]
			//pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0xec6e0; // [100 ] [1 / 1]
			//pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0xecf00; // [100 ] [1 / 1]
			//pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0xec850; // [100 ] [1 / 1]
			//pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0xecec0; // [100 ] [1 / 1]
			//pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x103780; // [100 ] [1 / 1]
			//pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0xeefa0; // [100 ] [1 / 1]
			//pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0xeef70; // [100 ] [1 / 1]
			//pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x1043f0; // [100 ] [1 / 1]
			//pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0xec1e0; // [100 ] [1 / 1]
			//pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x1052d0; // [100 ] [1 / 1]
			//pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x1037e0; // [100 ] [1 / 1]
			//pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x103c90; // [100 ] [1 / 1]
			//pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x103dd0; // [100 ] [1 / 1]
			//pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x41cd70; // [100 ] [1 / 1]
			//pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x408090; // [100 ] [1 / 1]
			//pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x42fb80; // [100 ] [1 / 1]
			//pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x453890; // [100 ] [1 / 1]
			//pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x3ff070; // [100 ] [1 / 1]
			//pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x1EA7988;
			//pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x41a900; // [100 ] [1 / 1]
			//pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x72A40;
			//pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x73060;
			//pCPythonNetworkStreamSendCommandPacket = Globals::hEntryBaseAddress + 0x201690;
			//pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x550A0;
			break;
		}
		//case ServerName::AELDRA:
		//{
		//	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x2c72c94; // [100 ] [79 / 79]
		//	pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x2c72d20; // [100 ] [21 / 21]
		//	pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x2c72cb0; // [91 ] [11 / 12]
		//	pCItemManagerInstance = Globals::hEntryBaseAddress + 0x2c72cf0; // [80 ] [4 / 5]
		//	pCPythonItemInstance = Globals::hEntryBaseAddress + 0x2C75A7C;
		//	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x2c75a84; // [100 ] [1 / 1]
		//	pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x2c72cf4; // [100 ] [1 / 1]
		//	pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x2c72d54; // [98 ] [84 / 85]
		//	pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x2C72CE0; // [100 ] [1 / 1]
		//	pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x3E7A90; // [100 ] [1 / 1]
		//	pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x2A9A90;
		//	pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x2888D0; // [100 ] [2 / 2] 
		//	pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x2888e0; // [100 ] [1 / 1]
		//	pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x289a00; // [100 ] [1 / 1]
		//	pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x289b50; // [100 ] [1 / 1]
		//	pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x289af0; // [100 ] [2 / 2]
		//	pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x296030; // [100 ] [3 / 3]
		//	pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x289f80; // [100 ] [2 / 2]
		//	pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x28a190; // [100 ] [1 / 1]
		//	pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x296040; // [100 ] [2 / 2]
		//	pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x2959d0; // [100 ] [1 / 1]
		//	pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x2960f0; // [100 ] [1 / 1]
		//	pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x294820; // [100 ] [1 / 1]
		//	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x3d9970; // [100 ] [1 / 1]
		//	pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x2a9ba0; // [100 ] [1 / 1]
		//	pCNetworkStreamConnect = Globals::hEntryBaseAddress + 0x372110; // [100 ] [2 / 2]
		//	pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x2e9e50; // [100 ] [1 / 1]
		//	pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x2E96D0;
		//	pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x3722e0; // [100 ] [1 / 1]
		//	pCNetworkStreamSend = Globals::hEntryBaseAddress + 0x3728b0; // [100 ] [1 / 1]
		//	pCNetworkStreamSendSequence = Globals::hEntryBaseAddress + 0x12fb70; // [100 ] [1 / 1]
		//	pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x408320; // [100 ] [1 / 1]
		//	pCPythonApplicationProcess = Globals::hEntryBaseAddress + 0x2a0e80; // [100 ] [2 / 2]
		//	pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x2a1590; // [100 ] [1 / 1]
		//	pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x2ae5a0; // [100 ] [11 / 11]
		//	pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x2c1510; // [100 ] [1 / 1]
		//	pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x2ceed0; // [100 ] [2 / 2]
		//	pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x2e94e0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x2e97c0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x303920;
		//	pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + 0x303AE0;
		//	pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x304620; // [100 ] [3 / 3]
		//	pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x3047a0; // [100 ] [3 / 3]
		//	pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x2e99c0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x304ad0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x304bd0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x304d10; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x304dc0; // [100 ] [3 / 3]
		//	pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x304f20; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x30b6c0; // [100 ] [2 / 2]
		//	pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x30b7d0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x30bb70; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x30bc20; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x3067c0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x306c40; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x306EC0;
		//	pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x30c560; // [100 ] [2 / 2]
		//	pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x30c630; // [100 ] [2 / 2]
		//	pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x30c760; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x307220; // [100 ] [1 / 1] 
		//	pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x3072c0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x2ea130; // [100 ] [1 / 1]
		//	pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x30f5c0; // [100 ] [2 / 2]
		//	pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x320160; // [100 ] [1 / 1]
		//	pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x313380;
		//	pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x313400; // [100 ] [2 / 2]
		//	pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x3134f0; // [100 ] [1 / 1]
		//	pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x313500; // [100 ] [2 / 2]
		//	pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x3135c0; // [100 ] [2 / 2]
		//	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x3137D0;
		//	pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x317f50; // [100 ] [1 / 1]
		//	pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x313cb0; // [100 ] [2 / 2]
		//	pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x313ce0; // [100 ] [2 / 2]
		//	pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x317470; // [100 ] [1 / 1]
		//	pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x314150; // [100 ] [11 / 11]
		//	pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x318810; // [100 ] [1 / 1]
		//	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x317b00; // [100 ] [3 / 3]
		//	pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x317fe0; // [100 ] [1 / 1]
		//	pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x3180e0; // [100 ] [1 / 1]
		//	pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x39a150; // [100 ] [2 / 2]
		//	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x3782b0; // [100 ] [1 / 1]
		//	pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x383720;
		//	pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x439010; // [100 ] [2 / 2]
		//	pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x2A3E20; // [100 ] [1 / 1]
		//	pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x2C7A828;
		//	pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x391440; // [100 ] [1 / 1]
		//	pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x295710; // [100 ] [1 / 1]
		//	pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x296190; // [66 ] [2 / 3] 
		//	pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x28cdf0; // [100 %] [1 / 1]
		//	pCItemDataGetName = Globals::hEntryBaseAddress + 0x3CF110;
		//	break;
		//}
		//case ServerName::AELDRA:
		//{
		//	pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x20c5ce0; // [100 ] [1 / 1]
		//	pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x20c5da8; // [100 ] [1 / 1]
		//	pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x20c5d34; // [100 ] [1 / 1]
		//	pCItemManagerInstance = Globals::hEntryBaseAddress + 0x20C5D78; // [100 ] [1 / 1]
		//	pCPythonItemInstance = Globals::hEntryBaseAddress + 0x20c8b04; // [100 ] [1 / 1]
		//	pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x20c8b0c; // [100 ] [1 / 1]
		//	pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x20c5d7c; // [100 ] [1 / 1]
		//	pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x20c5dd0; // [100 ] [1 / 1]
		//	pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x20c5d68; // [100 ] [1 / 1]
		//	pCActorInstanceTestActorCollision = Globals::hEntryBaseAddress + 0x3e9ea0; // [100 ] [1 / 1]
		//	pCPythonBackgroundGlobalPositionToMapInfo = Globals::hEntryBaseAddress + 0x2b0840; // [100 ] [1 / 1]
		//	pCInstanceBaseAvoidObject = Globals::hEntryBaseAddress + 0x28de60; // [100 ] [1 / 1]
		//	pCInstanceBaseBlockMovement = Globals::hEntryBaseAddress + 0x28de70; // [100 ] [1 / 1]
		//	pCInstanceBaseGetInstanceType = Globals::hEntryBaseAddress + 0x28ef90; // [100 ] [1 / 1]
		//	pCInstanceBaseGetInstanceVirtualNumber = Globals::hEntryBaseAddress + 0x28f0e0; // [100 ] [1 / 1]
		//	pCInstanceBaseGetNameString = Globals::hEntryBaseAddress + 0x28f080; // [100 ] [1 / 1]
		//	pCInstanceBaseGetRotation = Globals::hEntryBaseAddress + 0x29b440; // [100 ] [1 / 1]
		//	pCInstanceBaseIsDead = Globals::hEntryBaseAddress + 0x28f510; // [100 ] [1 / 1]
		//	pCInstanceBaseIsMountingHorse = Globals::hEntryBaseAddress + 0x28f720; // [100 ] [1 / 1]
		//	pCInstanceBaseNEW_GetPixelPosition = Globals::hEntryBaseAddress + 0x29b450; // [100 ] [1 / 1]
		//	pCInstanceBaseNEW_MoveToDestPixelPositionDirection = Globals::hEntryBaseAddress + 0x29add0; // [100 ] [1 / 1]
		//	pCInstanceBaseSCRIPT_SetPixelPosition = Globals::hEntryBaseAddress + 0x29b500; // [100 ] [1 / 1]
		//	pCInstanceBase__SetAffect = Globals::hEntryBaseAddress + 0x299c60; // [100 ] [1 / 1]
		//	pCItemDataGetName = Globals::hEntryBaseAddress + 0x3d14e0; // [100 ] [1 / 1]
		//	pCItemManagerGetItemDataPointer = Globals::hEntryBaseAddress + 0x3dbd70; // [100 ] [1 / 1]
		//	pCPythonBackgroundLocalPositionToGlobalPosition = Globals::hEntryBaseAddress + 0x2b0950; // [100 ] [1 / 1]
		//	//pCNetworkStreamConnect = Globals::hEntryBaseAddress + (null); 
		//	pCNetworkStream__DirectEnterMode_Set = Globals::hEntryBaseAddress + 0x2f0bf0; // [100 ] [1 / 1]
		//	pCNetworkStreamGetAccountCharacterSlotDataz = Globals::hEntryBaseAddress + 0x2f0460; // [100 ] [1 / 1]
		//	pCNetworkStreamIsOnline = Globals::hEntryBaseAddress + 0x3744f0; // [100 ] [1 / 1]
		//	pCPhysicsObjectIncreaseExternalForce = Globals::hEntryBaseAddress + 0x40a730; // [100 ] [1 / 1]
		//	//pCPythonApplicationProcess = Globals::hEntryBaseAddress + (null); 
		//	pCPythonApplicationRenderGame = Globals::hEntryBaseAddress + 0x2a7280; // [100 ] [1 / 1]
		//	pCPythonCharacterManagerGetInstancePtr = Globals::hEntryBaseAddress + 0x2b5360; // [100 ] [1 / 1]
		//	pCPythonChatAppendChat = Globals::hEntryBaseAddress + 0x2c8260; // [100 ] [1 / 1]
		//	pCPythonEventManagerRegisterEventSetFromString = Globals::hEntryBaseAddress + 0x2d5bc0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamConnectGameServer = Globals::hEntryBaseAddress + 0x2F0240;
		//	pCPythonNetworkStreamGetMainActorSkillGroup = Globals::hEntryBaseAddress + 0x2F0560;
		//	pCPythonNetworkStreamSendAddFlyTargetingPacket = Globals::hEntryBaseAddress + 0x309e70; // [100 ] [1 / 1]
		//	//pCPythonNetworkStreamSendAttackPacket = Globals::hEntryBaseAddress + (null); 
		//	pCPythonNetworkStreamSendCharacterStatePacket = Globals::hEntryBaseAddress + 0x30aa20; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendChatPacket = Globals::hEntryBaseAddress + 0x30aba0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendEmoticon = Globals::hEntryBaseAddress + 0x2f0760; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendExchangeAcceptPacket = Globals::hEntryBaseAddress + 0x30aed0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendExchangeItemAddPacket = Globals::hEntryBaseAddress + 0x30afd0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendExchangeStartPacket = Globals::hEntryBaseAddress + 0x30b110; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendFishingPacket = Globals::hEntryBaseAddress + 0x30b1c0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendGiveItemPacket = Globals::hEntryBaseAddress + 0x30b320; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendItemDropPacketNew = Globals::hEntryBaseAddress + 0x3119b0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendItemMovePacket = Globals::hEntryBaseAddress + 0x311ac0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendItemPickUpPacket = Globals::hEntryBaseAddress + 0x311e60; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendItemUsePacket = Globals::hEntryBaseAddress + 0x311f10; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendOnClickPacket = Globals::hEntryBaseAddress + 0x30C510;
		//	pCPythonNetworkStreamSendRefinePacket = Globals::hEntryBaseAddress + 0x30cbc0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendScriptAnswerPacket = Globals::hEntryBaseAddress + 0x30d040; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendShootPacket = Globals::hEntryBaseAddress + 0x30d2c0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendShopBuyPacket = Globals::hEntryBaseAddress + 0x312850; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendShopEndPacket = Globals::hEntryBaseAddress + 0x312920; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendShopSellPacketNew = Globals::hEntryBaseAddress + 0x312a50; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendUseSkillPacket = Globals::hEntryBaseAddress + 0x30d620; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamSendWhisperPacket = Globals::hEntryBaseAddress + 0x30d6c0; // [100 ] [1 / 1]
		//	pCPythonNetworkStreamServerCommand = Globals::hEntryBaseAddress + 0x2f0ee0; // [100 ] [1 / 1]
		//	pCPythonNonPlayerGetTable = Globals::hEntryBaseAddress + 0x315900; // [100 ] [1 / 1]
		//	pCPythonPlayerClickSkillSlot = Globals::hEntryBaseAddress + 0x326640; // [100 ] [1 / 1]
		//	pCPythonPlayerGetItemIndex = Globals::hEntryBaseAddress + 0x3196c0; // [100 ] [1 / 1]
		//	pCPythonPlayerGetItemMetinSocket = Globals::hEntryBaseAddress + 0x319740; // [100 ] [1 / 1]
		//	pCPythonPlayerGetMainCharacterIndex = Globals::hEntryBaseAddress + 0x319830; // [100 ] [1 / 1]
		//	pCPythonPlayerGetName = Globals::hEntryBaseAddress + 0x319840; // [100 ] [1 / 1]
		//	pCPythonPlayerGetRace = Globals::hEntryBaseAddress + 0x319900; // [100 ] [1 / 1]
		//	pCPythonPlayerGetStatus = Globals::hEntryBaseAddress + 0x319b10; // [100 ] [1 / 1]
		//	pCPythonPlayerGetTargetVID = Globals::hEntryBaseAddress + 0x31e420; // [100 ] [1 / 1]
		//	pCPythonPlayerIsSkillActive = Globals::hEntryBaseAddress + 0x319ff0; // [100 ] [1 / 1]
		//	pCPythonPlayerIsSkillCoolTime = Globals::hEntryBaseAddress + 0x31a020; // [100 ] [1 / 1]
		//	pCPythonPlayerNEW_Fishing = Globals::hEntryBaseAddress + 0x31d940; // [100 ] [1 / 1]
		//	pCPythonPlayerNEW_GetMainActorPtr = Globals::hEntryBaseAddress + 0x31a490; // [100 ] [1 / 1]
		//	pCPythonPlayerSetAttackKeyState = Globals::hEntryBaseAddress + 0x31ece0; // [100 ] [1 / 1]
		//	pCPythonPlayerSetTarget = Globals::hEntryBaseAddress + 0x31dfd0; // [100 ] [1 / 1]
		//	pCPythonPlayer__OnClickActor = Globals::hEntryBaseAddress + 0x31e4b0; // [100 ] [1 / 1]
		//	pCPythonPlayer__OnPressActor = Globals::hEntryBaseAddress + 0x31e5b0; // [100 ] [1 / 1]
		//	pCGraphicTextureGetD3DTexture = Globals::hEntryBaseAddress + 0x39c500; // [100 ] [1 / 1]
		//	pCResourceManagerGetResourcePointer = Globals::hEntryBaseAddress + 0x37a650; // [100 ] [1 / 1]
		//	pCGraphicImageGetTexturePointer = Globals::hEntryBaseAddress + 0x385ad0; // [100 ] [1 / 1]
		//	pPyCallClassMemberFunc = Globals::hEntryBaseAddress + 0x43b430; // [100 ] [1 / 1]
		//	pCPythonApplicationOnUIRender = Globals::hEntryBaseAddress + 0x2a9b90; // [100 ] [1 / 1]
		//	pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x20CEB00;
		//	pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x3937f0; // [100 ] [1 / 1]
		//	pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x29ab10; // [100 ] [1 / 1]
		//	pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x29b5a0; // [100 ] [1 / 1]
		//}
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
			pCPythonNetworkStreamInstance = Globals::hEntryBaseAddress + 0x380db4; // [100 ] [1 / 1]
			pCPythonCharacterManagerInstance = Globals::hEntryBaseAddress + 0x380DD0; // [100 ] [1 / 1]
			pCPythonBackgroundInstance = Globals::hEntryBaseAddress + 0x380dc0; // [100 ] [1 / 1]
			pCItemManagerInstance = Globals::hEntryBaseAddress + 0x380df0; // [100 ] [1 / 1]
			pCPythonItemInstance = Globals::hEntryBaseAddress + 0x3b8e6c; // [100 ] [4 / 4]
			pCPythonApplicationInstance = Globals::hEntryBaseAddress + 0x381280; // [100 ] [1 / 1]
			pCPythonNonPlayerInstance = Globals::hEntryBaseAddress + 0x380ddc; // [100 ] [1 / 1]
			pCPythonPlayerInstance = Globals::hEntryBaseAddress + 0x380de8; // [100 ] [1 / 1]
			pCResourceManagerInstance = Globals::hEntryBaseAddress + 0x380dc4; // [100 ] [1 / 1]
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
			pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x34340C;
			pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0x139e60; // [100 ] [1 / 1]
			pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x75cc0; // [100 ] [4 / 4]
			pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x76130; // [100 ] [4 / 4]
			pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0x69FC0; // [100 %] [1 / 1]
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
			pCGraphicBasems_lpd3dDevice = Globals::hEntryBaseAddress + 0x3F3A94;
			pCInputKeyboardUpdateKeyboard = Globals::hEntryBaseAddress + 0xe0c90; // [100 ] [1 / 1]
			pCInstanceBaseIsWaiting = Globals::hEntryBaseAddress + 0x15e40; // [100 ] [1 / 1]
			pCInstanceBaseSetRotation = Globals::hEntryBaseAddress + 0x168e0; // [100 ] [1 / 1]
			//pCPythonNetworkStreamSendCommandPacket = Globals::hEntryBaseAddress + (null); 
			pCInstanceBase__GetBackgroundHeight = Globals::hEntryBaseAddress + 0xeb60; // [100 %] [1 / 1]
			break;
		}
	}
}

void Globals::ReDeclarationLocals()
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

