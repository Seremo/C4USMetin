#pragma once

class Hooks
{
public:
	static Globals::tCNetworkStreamSendSequence nCNetworkStreamSendSequence;
	static Globals::tPyCallClassMemberFunc nPyCallClassMemberFunc;
	static Globals::tCNetworkStreamRecv nCNetworkStreamRecv;
	//static Globals::tCNetworkStreamPeek nCNetworkStreamPeek;
	static Globals::tCNetworkStreamSend nCNetworkStreamSend;
	static Globals::tCNetworkStreamSendAeldra nCNetworkStreamSendAeldra;
	static Globals::tCNetworkStreamCheckPacket	nCNetworkStreamCheckPacket;
	static Globals::tCPythonChatAppendChat nCPythonChatAppendChat;
	static Globals::tCPythonNetworkStreamSendChatPacket nCPythonNetworkStreamSendChatPacket;
	static Globals::tCResourceManagerGetResourcePointer nCResourceManagerGetResourcePointer;
	static Globals::tCInstanceBaseBlockMovement nCInstanceBaseBlockMovement;
	static Globals::tCInstanceBaseAvoidObject nCInstanceBaseAvoidObject;
	static Globals::tCActorInstanceTestActorCollision nCActorInstanceTestActorCollision;
	static Globals::tCPhysicsObjectIncreaseExternalForce nCPhysicsObjectIncreaseExternalForce;
	static Globals::tCPythonApplicationRenderGame nCPythonApplicationRenderGame;
	static Globals::tCPythonApplicationProcess nCPythonApplicationProcess;
	static Globals::tCPythonEventManagerRegisterEventSetFromString nCPythonEventManagerRegisterEventSetFromString;


	static Globals::tCPythonApplicationOnUIRender nCPythonApplicationOnUIRender;
	static Globals::tCInputKeyboardUpdateKeyboard nCInputKeyboardUpdateKeyboard;

	static void _fastcall Hooks::NewCPythonApplicationRenderGame(void* This, void* EDX);
	static bool _fastcall Hooks::NewCActorInstanceTestActorCollision(void* This, void* EDX, DWORD* rVictim);
	static bool _fastcall Hooks::NewCInstanceBaseAvoidObject(void* This, void* EDX, DWORD* c_rkBGObj);
	static void _fastcall Hooks::NewCInstanceBaseBlockMovement(void* This, void* EDX);
	static bool __cdecl Hooks::NewPyCallClassMemberFunc(PyObject* poClass, const char* c_szFunc, PyObject* poArgs);
	static bool _fastcall NewCPythonEventManagerRegisterEventSetFromString(void* This, void* EDX, const string& strScript);
	static void _fastcall NewCPhysicsObjectIncreaseExternalForce(void* This, void* EDX, const D3DVECTOR& c_rvBasePosition, float fForce);
	//bool _fastcall NewCNetworkStreamPeek(void* This, void* EDX, int len, void* pDestBuf);
	static bool _fastcall NewCNetworkStreamCheckPacket(void* This, void* EDX, BYTE* header);
	static bool _fastcall Hooks::NewCNetworkStreamRecv(void* This, void* EDX, int len, void* pDestBuf);

	static bool _fastcall Hooks::NewCNetworkStreamSend(void* This, void* EDX, int len, void* pDestBuf);

	static int _stdcall Hooks::NewCNetworkStreamSendAeldra(SOCKET s, const char* pDestBuf, int len, int flags);

	static bool _fastcall Hooks::NewCNetworkStreamSendSequence(void* This, void* EDX);
	static void _fastcall Hooks::NewCPythonChatAppendChat(void* This, void* EDX, int iType, const char* c_szChat);
	static bool _fastcall Hooks::NewCPythonNetworkStreamSendChatPacket(void* This, void* EDX, const char* c_szChat, BYTE byType);
	static DWORD* _fastcall Hooks::NewCResourceManagerGetResourcePointer(void* This, void* EDX, const char* c_szFileName);
	static bool _fastcall Hooks::NewCPythonApplicationProcess(void* This, void* EDX);
	static void _fastcall Hooks::NewCPythonApplicationOnUIRender(void* This, void* EDX);
	static void _fastcall Hooks::NewCInputKeyboardUpdateKeyboard(void* This, void* EDX);
	//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	static void Hooks::Initialize();


};

Globals::tCNetworkStreamSendSequence Hooks::nCNetworkStreamSendSequence = NULL;
Globals::tCNetworkStreamRecv Hooks::nCNetworkStreamRecv = NULL;
//Globals::tCNetworkStreamPeek Hooks::nCNetworkStreamPeek = NULL;
Globals::tCNetworkStreamSend Hooks::nCNetworkStreamSend = NULL;
Globals::tCNetworkStreamSendAeldra Hooks::nCNetworkStreamSendAeldra = NULL;
Globals::tCNetworkStreamCheckPacket Hooks::nCNetworkStreamCheckPacket = NULL;
Globals::tCPythonChatAppendChat Hooks::nCPythonChatAppendChat = NULL;
Globals::tCPhysicsObjectIncreaseExternalForce Hooks::nCPhysicsObjectIncreaseExternalForce = NULL;
Globals::tCPythonNetworkStreamSendChatPacket Hooks::nCPythonNetworkStreamSendChatPacket = NULL;
Globals::tPyCallClassMemberFunc Hooks::nPyCallClassMemberFunc = NULL;
Globals::tCResourceManagerGetResourcePointer Hooks::nCResourceManagerGetResourcePointer = NULL;
Globals::tCInstanceBaseBlockMovement Hooks::nCInstanceBaseBlockMovement = NULL;
Globals::tCInstanceBaseAvoidObject Hooks::nCInstanceBaseAvoidObject = NULL;
Globals::tCActorInstanceTestActorCollision Hooks::nCActorInstanceTestActorCollision = NULL;
Globals::tCPythonApplicationRenderGame Hooks::nCPythonApplicationRenderGame = NULL;
Globals::tCPythonApplicationProcess Hooks::nCPythonApplicationProcess = NULL;
Globals::tCPythonEventManagerRegisterEventSetFromString Hooks::nCPythonEventManagerRegisterEventSetFromString = NULL;
Globals::tCPythonApplicationOnUIRender Hooks::nCPythonApplicationOnUIRender = NULL;
Globals::tCInputKeyboardUpdateKeyboard Hooks::nCInputKeyboardUpdateKeyboard = NULL;

