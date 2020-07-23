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




//#define VISERION

//#define DIAMOND
//#define ATYVA
//#define VIDGAR
//#define AELDRA
//#define FORNAX
//#define RAFON
//#define DREIKON
//#define RUBINUM
//#define ITANOS
//#define NODIA
//#define SENTHIA
//#define MORAH
#define METINPL
//#define PANGEA
//#define MATADIA
//#define BARIA
//#define ASGARDION
//#define MEDIUM
//#define EGORIA
//#define VESTERIS
//#define CLASSIC
//#define GLADOR
//#define ZERIOS
//#define SENEA
//#define ZAMORIA
//#define IVEYA
//#define ESGAROTH
//#define VALIUM
//#define VAROS
//#define MULA
//#define LOTHIA
//#define AVENTUS
//#define XENOX
//#define HERMAS
//#define XANTHIA
//#define VIRTUALMT2
//#define MASTIAMT2
//#define NERWIA
//#define SAMIAS2
//#define TAMIDIA_SE
//#define AKADEMIA_NERWIA
//#define TENELIS
//#define DIUMAR
//#define ELENIUM
//#define AVENTUS2
//#define SG2
//#define ELITEMT2
//#define AZENTIS
//#define BALMORA
//#define VAROS
//#define NERWIAS2
//#define VERESTHIA
//#define ALTRIC
//#define AKADEMIA_VESTERIS




#define VERSION_ELITE
//#define VERSION_PUBLIC
//#define VERSION_PREMIUM

//#define PYTHON_CUSTOM

//#define DEVELOPER_MODE

#define DLL_VERSION "0.0.59 Beta"

#ifdef DIAMOND
#define SERVER_NAME "DIAMOND"
#endif

#ifdef VISERION
#define SERVER_NAME "VISERION"
#endif

#ifdef ATYVA
#define SERVER_NAME "Atyva"
#endif

#ifdef VIDGAR
#define SERVER_NAME "Vidgar"
#endif

#ifdef AELDRA
#define SERVER_NAME "Aeldra"
#endif

#ifdef FORNAX
#define SERVER_NAME "Fornax"
#endif

#ifdef DREIKON
#define SERVER_NAME "Dreikon"
#endif

#ifdef RAFON
#define SERVER_NAME "RAFON"
#endif

#ifdef RUBINUM
#define SERVER_NAME "Rubinum"
#endif

#ifdef MORAH
#define SERVER_NAME "MORAH"
#endif

#ifdef   VERESTHIA
#define SERVER_NAME "VERESTHIA"
#endif
#ifdef  AKADEMIA_VESTERIS
#define SERVER_NAME "AKADEMIA VESTERIS"
#endif

#ifdef  SENTHIA
#define SERVER_NAME "SENTHIA"
#endif

#ifdef  CLASSIC
#define SERVER_NAME "ClassicMt2"
#endif

#ifdef  ALTRIC
#define SERVER_NAME "ALTRIC"
#endif

#ifdef  VAROS
#define SERVER_NAME "VAROS"
#endif

#ifdef  BALMORA
#define SERVER_NAME "BALMORA"
#endif

#ifdef  AZENTIS
#define SERVER_NAME "AZENTIS"
#endif

#ifdef  ELITEMT2
#define SERVER_NAME "ELITEMT2"
#endif

#ifdef  SG2
#define SERVER_NAME "SG2"
#endif

#ifdef  AVENTUS2
#define SERVER_NAME "AVENTUS2"
#endif

#ifdef  TENELIS
#define SERVER_NAME "TENELIS"
#endif

#ifdef  ELENIUM
#define SERVER_NAME "ELENIUM"
#endif

#ifdef  DIUMAR
#define SERVER_NAME "DIUMAR"
#endif

#ifdef  SAMIAS2
#define SERVER_NAME "Samia"
#endif

#ifdef  METINPL
#define SERVER_NAME "METINPL"
#endif

#ifdef  NERWIA
#define SERVER_NAME "NERWIA"
#endif

#ifdef  MASTIAMT2
#define SERVER_NAME "MASTIAMT2"
#endif

#ifdef IVEYA
#define SERVER_NAME "IVEYA"
#endif

#ifdef VIRTUALMT2
#define SERVER_NAME "VIRTUALMT2"

#endif
#ifdef XANTHIA
#define SERVER_NAME "XANTHIA"

#endif
#ifdef XENOX
#define SERVER_NAME "XENOX"

#endif
#ifdef EGORIA
#define SERVER_NAME "EGORIA"
#endif

#ifdef PANGEA
#define SERVER_NAME "Pangea"
#endif

#ifdef HERMAS
#define SERVER_NAME "HERMAS"
#endif

#ifdef VESTERIS
#define SERVER_NAME "VESTERIS"
#endif

#ifdef VALIUM
#define SERVER_NAME "VALIUM"
#endif

#ifdef ESGAROTH
#define SERVER_NAME "ESGAROTH"
#endif
            
#ifdef TAMIDIA_SE
#define SERVER_NAME "TAMIDIA_SE"
#endif

#ifdef AKADEMIA_NERWIA
#define SERVER_NAME "AKADEMIA_NERWIA"
#endif

#ifdef MEDIUM
#define SERVER_NAME "MEDIUM"
#endif

#ifdef GLADOR
#define SERVER_NAME "GLADOR"
#endif

#ifdef BARIA
#define SERVER_NAME "BARIA"
#endif

#ifdef  NERWIAS2
#define SERVER_NAME "NERWIAS2"
#endif

#ifdef  NODIA
#define SERVER_NAME "NODIA"
#endif

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_internal.h"

#ifdef MEDIUM
#include "ImGui/imgui_impl_dx9.h"
#include <d3d9.h>
#include <d3dx9.h>
#define DIRECTINPUT_VERSION 0x0800
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
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

//#ifndef PYTHON_CUSTOM
//
//#ifdef _DEBUG
//#define DEBUG_WAS_DEFINED
//#undef _DEBUG
//#endif
//#include "Python.h"
//#pragma comment(lib, "python27.lib")
//
//#ifdef DEBUG_WAS_DEFINED
//#define _DEBUG
//#endif
//
//
//
//
//#else
//
//#endif 

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
#include "MainForm.h"
#include "SimpleIni.h"

#include "Globals.h"

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
#include "HookCore.h"
#include "MainCore.h"

