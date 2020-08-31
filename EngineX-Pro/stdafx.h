#include <winsock2.h>
#define _WINSOCK2API_

#include <Windows.h>
#include <io.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <memory>
#include <memory.h>
#include <tchar.h>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <shlobj.h>
#include <direct.h>
#include <vector>
#include "strsafe.h"
#include <map>
#include <stdarg.h>
#include "resource.h"
#include <iomanip>
#include <intrin.h>       
#include <iphlpapi.h>   
#include <mutex>
#include <WinInet.h>
#include <chrono>
#include <thread>
#include <functional>
#include <psapi.h>
#include <regex>
#include <winver.h>
#include <codecvt>

#pragma comment(lib, "detours.lib")
#include "detours.h"
using namespace std;


#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "Wininet")


enum ServerName
{
	METINPL,
	MEDIUMMT2,
	VIDGAR,
	PANGEA,
	SAMIAS2,
	BARIA,
	VALIUM,
	SG2,
	VEDNAR,
	AELDRA,
	ORIGINS,
	CALLIOPE
};


//#define DX9

#define VERSION_ELITE
//#define VERSION_PUBLIC
//#define VERSION_PREMIUM

//#define PYTHON_CUSTOM
//#define FISHBOT
#define DEVELOPER_MODE

#define DLL_VERSION "0.0.62 Beta"

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_internal.h"

#ifdef DX9
#include "ImGui/imgui_impl_dx9.h"
#include <d3d9.h>
#include <d3dx9.h>
#define DIRECTINPUT_VERSION 0x0800
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#define DirectDevice IDirect3DDevice9*
#define DirectDevice2 LPDIRECT3DDEVICE9
#define DirectTexture LPDIRECT3DTEXTURE9
#define IMGUI_DEFINE_MATH_OPERATORS
#else
#include "ImGui/imgui_impl_dx8.h"
#include <d3d8.h>
#include <d3dx8.h>
#define DIRECTINPUT_VERSION 0x0800
#pragma comment(lib, "d3d8.lib")
#pragma comment(lib, "d3dx8.lib")
#define DirectDevice IDirect3DDevice8*
#define DirectDevice2 LPDIRECT3DDEVICE8
#define DirectTexture LPDIRECT3DTEXTURE8
#define IMGUI_DEFINE_MATH_OPERATORS
#endif

//#include "Python.h"
//#pragma comment(lib, "python27.lib")

typedef unsigned long       PyObject;
typedef int                 Py_ssize_t;

#include "DynamicTimer.h"


#include "StopWatch.h"
#include "DelayActions.h"


#include "StdV80-110.h"
#include "Defines.h"



#include "TAbstractSingleton.h"
#include "Singleton.h"

#include "MiscExtension.h"
#include "CryptExtension.h"
#include "FileExtension.h"
#include "MathExtension.h"
#include "MemoryExtension.h"
#include "StringExtension.h"
#include "ProtectExtension.h"
#include "PatternScan.h"
#include "PatternScan2.h"


#include "Settings.h"
#include "Hotkey.h"
#include "Device.h"
#include "CRender.h"
#include"SplashScreen.h"
#include "Logger.h"
#include "popinsmedium.h"
#include "MainForm.h"
#include "SimpleIni.h"

#include "Globals.h"
//NETWORK
#include "Packet.h"
#include "Network.h"
#include "PacketHandler.h"

#include "GameFunctions.h"
#include "GameFunctionsCustom.h"



#include "IAbstractModuleBase.h"

#include "Main.h"
#include "Protection.h"
#include "PacketSniffer.h"
#include "Fish.h"

#include "Buff.h"
#include "Item.h"
#include "Farm.h"
#include "Status.h"
#include "Spam.h"
#include "AutoTalk.h"
#include "Misc.h"
#include "PythonScript.h"
#include "Refine.h"
#include "MainDungs.h"

#include "Debug.h"
#include "Radar.h"
#include "Configuration.h"
#include "HookIAT.h"
#include "HookCore.h"
#include "MainCore.h"
#include "Security.h"
