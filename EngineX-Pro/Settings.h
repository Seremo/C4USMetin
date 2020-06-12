#pragma once


class Settings
{
public:

	static vector<string> DETECT_PLAYER_WHITE_LIST_NAMES;
	static map< pair<DWORD, bool>, pair<DWORD, string>> FISHBOT_KILL_FISH_LIST;
	static map< pair<DWORD, bool>, pair<DWORD, string>> FISHBOT_BAIT_LIST;
	static map< pair<DWORD, bool>, pair<DWORD, string>> FISHBOT_DROP_LIST;
	static map< pair<DWORD, bool>, pair<DWORD, string>> FISHBOT_SELL_LIST;


	static map< pair<DWORD, pair<string, string>>, pair<DWORD, string>> Settings::SERVER_INFO_LIST;

	static DWORD INVENTORY_PAGE_SIZE;
	static DWORD INVENTORY_PAGE_COUNT;


	

	

	static void Load(const char* name) 
	{
	
	}

	static void Save(const char* name)
	{
	
	}
	static bool DropBotEnable;
	static bool LevelBotEnable;
	static bool LevelBotMob;
	static bool LevelBotBoss;
	static bool LevelBotMetin;
	static int	LevelBotDistance;
	static int	LevelBotMoveType;
	static int	LevelBotAttackType;
	static float LevelBotCoordsX[250];
	static float LevelBotCoordsY[250];
	static bool FishBotEnable;
	static int FishBotSuccesPercentValue;
	static int FishBotCastTimeMinValue;
	static int FishBotCastTimeMaxValue;
	static int FishBotRoundTimeMinValue;
	static int FishBotRoundTimeMaxValue;
	static int FishBotEmergencyRunTimeValue;

	static bool FishBotSuccesPercent;
	static bool FishBotCastTime;
	static bool FishBotRoundTime;
	static bool FishBotEmergencyRunTime;
	static bool FISHBOT_DETECT_PLAYER;
	static bool FishBotKillTillSize;
	static double FishBotKillTillSizeValue;
	



	static bool FishBotUseFirstSlot;
	static bool FISHBOT_KILL_FISH;
	static bool FISHBOT_SELL_TRASH;
	static int FISHBOT_SELL_TRASH_AFTER_PERCENTAGE;
	static bool FISHBOT_DROP_TRASH;
	static bool FISHBOT_BUY_BAIT;
	static int FISHBOT_BUY_BAIT_SHOP_SLOT;
	static int FISHBOT_BUY_BAIT_SHOP_COUNT;

	static bool FISHBOT_SHOP_CAST_TELEPORT;
	static int FISHBOT_CAST_ROTATION;
	static D3DVECTOR FISHBOT_SHOP_TELEPORT_CORDS;
	static D3DVECTOR FISHBOT_CAST_TELEPORT_CORDS;

	static bool FishBotStopIfPositionChanged;
	static bool FishBotStopIfInventoryFull;
	static bool StatusEnable;
	static bool MainInfoStonesViewportShow;
	static bool StatusInfoMinesViewportShow;
	static bool StatusInfoBossesViewportShow;
	//################################################################################################
	static bool GLOBAL_SWITCH;
	static bool MiniMHAttackEnable;
	static bool MiniMHRotation;
	static int MiniMHRotationValue;
	static bool MAIN_SKILL_ENABLE;
	static bool MAIN_SLOT_ENABLE_3;
	static bool MAIN_SLOT_ENABLE_4;
	static bool MAIN_SLOT_ENABLE_5;
	static bool MAIN_SLOT_ENABLE_6;
	static bool MAIN_SLOT_ENABLE_7;
	static bool MAIN_SLOT_ENABLE_8;
	static bool MAIN_SLOT_ENABLE_9;
	static bool MAIN_SLOT_ENABLE_10;
	static bool MAIN_SLOT_ENABLE_11;
	static bool MAIN_SLOT_ENABLE_12;
	static bool MAIN_SLOT_ENABLE_13;
	static bool MAIN_SLOT_ENABLE_14;
	static bool MAIN_SLOT_ENABLE_15;
	static bool MAIN_SLOT_ENABLE_16;
	



	static float ITEM_SLOT_TIME_3;
	static float ITEM_SLOT_TIME_4;
	static float ITEM_SLOT_TIME_5;
	static float ITEM_SLOT_TIME_6;
	static float ITEM_SLOT_TIME_7;
	static float ITEM_SLOT_TIME_8;
	static float ITEM_SLOT_TIME_9;
	static float ITEM_SLOT_TIME_10;
	static float ITEM_SLOT_TIME_11;
	static float ITEM_SLOT_TIME_12;
	static float ITEM_SLOT_TIME_13;
	static float ITEM_SLOT_TIME_14;
	static float ITEM_SLOT_TIME_15;
	static float ITEM_SLOT_TIME_16;

	static bool MAIN_SKILL_1;
	static bool MAIN_SKILL_2;
	static bool MAIN_SKILL_3;
	static bool MAIN_SKILL_4;
	static bool MAIN_SKILL_5;
	static bool MAIN_SKILL_6;
	static bool MiniMHNOK;
	static bool MiniMHNOP;

	
	static bool MainWallHackMob;
	static bool MainWallHackObject;
	static bool MainWallHackTerrain;


	static bool MiniMHMoveSpeed;
	static int MiniMHMoveSpeedValue;
	static bool MiniMHAttackSpeed;
	static int MiniMHAttackSpeedValue;
	static bool MiniMHWaitHackEnable;
	static int MiniMHWaitHackDistanceValue;
	static int  MiniMHWaitHackType;
	static bool MiniMHWaitHackSwordRange;
	static int MiniMHWaitHackSkillDelay;
	static int MiniMHWaitHackTime;
	static int MiniMHWaitHackOneTarget;
	static bool MiniMHAttackStopAttackNoMobDistance;
	static bool ITEM_PICKUP_ENABLE;
	static bool ITEM_PICKUP_FILTER;
	static int ITEM_PICKUP_TIME;
	static int ITEM_PICKUP_TYPE;
	static map< DWORD, pair<string, bool>> ITEM_PICKUP_SELECTED_LIST;
	static bool MiniMHUseRedPotion;
	static int MiniMHUseRedPotionValue;
	static int MiniMHUseRedPotionSpeed;
	static bool MiniMHUseBluePotion;
	static int MiniMHUseBluePotionValue;
	static int MiniMHUseBluePotionSpeed;
	static bool MiniMHAutoRevive;
	static int MiniMHAutoReviveHpPercentValue;
	static bool ProtectionShowWisperLogs;
	static bool ProtectionShowWisperBalloon;
	static bool ProtectionShowTalkBalloon;
	static bool ProtectionPlayWisperBeep;;
	static bool ProtectionPlayTalkBeep;
	static bool ProtectionFlashTalkIcon;
	static bool ProtectionShowTalkLogs;
	static bool ProtectionRestoreWisperWindow;;
	static bool ProtectionFlashWisperIcon;
	static bool BUFF_ENABLE;
	static bool BUFF_SKILL_1;
	static bool BUFF_SKILL_2;
	static bool BUFF_SKILL_3;
	static int BUFF_SKILL_1_TIME;
	static int BUFF_SKILL_2_TIME;
	static int BUFF_SKILL_3_TIME;

	static bool SPAM_NORMAL_ENABLE;
	static bool SPAM_SHOUT_ENABLE;
	static bool SPAM_WISPER_ENABLE;

	static int  SPAM_NORMAL_TIME;
	static int  SPAM_WHISPER_TIME;
	static int  SPAM_SHOUT_TIME;




	static ImVec4 SPAM_NORMAL_COLOR;
	static ImVec4 SPAM_WHISPER_COLOR;
	static ImVec4 SPAM_SHOUT_COLOR;


	static bool SPAM_NORMAL_COLOR_ENABLE;
	static bool SPAM_WHISPER_COLOR_ENABLE;
	static bool SPAM_SHOUT_COLOR_ENABLE;

	static bool ProtectionDisableRender;
	static bool PerformanceDisableRenerFrames;
	static bool MinerBotEnable;
	static bool MetinerBotEnable;
	static DWORD MinerValueDistance;
	static int  MetinerValueDistance;
	static bool MetinerWallHackTerrain;
	static bool MetinerWallHackObject;
	static bool MetinerWallHackMob;
	static bool MinerWallHackTerrain;
	static bool MinerWallHackObject;
	static bool MinerWallHackMob;
	static bool ProtectionAutoLogin;
	static int	BoostKey;
	static int	RelogKey;
	static int  OnOffMH;
	static DWORD HotkeyTime;
	static int BoostSpeed1;
	static int BoostSpeed2;
	static int BoostSpeed3;
	static bool MiniMHWaitHackDetect;
	//render
	static ImVec4 renderwh_color;
	static bool renderwh;
	//radar
	static ImVec4 monster_color;
	static ImVec4 boss_color;
	static ImVec4 npc_color;
	static ImVec4 mining_color;
	static ImVec4 metin_color;
	static ImVec4 pc_color;
	static ImVec4 waypoint_color;
	static bool monster_show;
	static bool boss_show;
	static bool npc_show;
	static bool mining_show;
	static bool metin_show;
	static bool pc_show;
	static bool waypoint_show;
	static float radar_zoom;
	static float box_posx;
	static float box_posy;
	static float box_posz;
	static int MiniMHSkillNumber;


	static int REFINE_UPGRADE_TYPE;
	static int REFINE_UPGRADE_COUNT;
	static int REFINE_ITEM_SLOT;
};
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

DWORD Settings::INVENTORY_PAGE_SIZE = 45;
#ifdef METINPL
DWORD Settings::INVENTORY_PAGE_COUNT = 2;
#else
DWORD Settings::INVENTORY_PAGE_COUNT = 5;
#endif
map< pair<DWORD, pair<string, string>>, pair<DWORD, string>> Settings::SERVER_INFO_LIST =
{
	{ make_pair(1,  make_pair("Amicicia","CH1")), make_pair(12100, "79.110.92.173") },
	{ make_pair(2,  make_pair("Amicicia","CH2")), make_pair(12200, "79.110.92.176") },
	{ make_pair(3,  make_pair("Amicicia","CH3")), make_pair(12300, "79.110.92.181") },
	{ make_pair(4,  make_pair("Amicicia","CH4")), make_pair(12400, "79.110.92.173") },
	{ make_pair(5,  make_pair("Amicicia","CH5")), make_pair(12500, "79.110.92.176") },
	{ make_pair(6,  make_pair("Amicicia","CH6")), make_pair(12600, "79.110.92.181") },
	{ make_pair(7,  make_pair("Amicicia","CH7")), make_pair(12700, "79.110.92.173") },
	{ make_pair(8,  make_pair("Amicicia","CH8")), make_pair(12800, "79.110.92.176") },
	{ make_pair(9,  make_pair("Amicicia","CH9")), make_pair(12900, "79.110.92.181") },


	{ make_pair(10,  make_pair("Carptura","CH1")), make_pair(12100, "79.110.92.187") },
	{ make_pair(11,  make_pair("Carptura","CH2")), make_pair(12200, "79.110.92.189") },
	{ make_pair(12,  make_pair("Carptura","CH3")), make_pair(12300, "79.110.92.190") },
	{ make_pair(13,  make_pair("Carptura","CH4")), make_pair(12400, "79.110.92.187") },
	{ make_pair(14,  make_pair("Carptura","CH5")), make_pair(12500, "79.110.92.189") },
	{ make_pair(15,  make_pair("Carptura","CH6")), make_pair(12600, "79.110.92.190") },
	{ make_pair(16,  make_pair("Carptura","CH7")), make_pair(12700, "79.110.92.187") },
	{ make_pair(17,  make_pair("Carptura","CH8")), make_pair(12800, "79.110.92.189") },
	{ make_pair(18,  make_pair("Carptura","CH9")), make_pair(12900, "79.110.92.190") },

	{ make_pair(19,  make_pair("Vidgar","CH1")), make_pair(60103, "137.74.5.73") },
	{ make_pair(20,  make_pair("Vidgar","CH2")), make_pair(60203, "137.74.5.73") },
	{ make_pair(21,  make_pair("Vidgar","CH3")), make_pair(60303, "137.74.5.73") },
	{ make_pair(22,  make_pair("Vidgar","CH4")), make_pair(60403, "137.74.5.73") },
	{ make_pair(23,  make_pair("Vidgar","CH5")), make_pair(60503, "137.74.5.73") },
	{ make_pair(24,  make_pair("Vidgar","CH6")), make_pair(60603, "137.74.5.73") },



	{ make_pair(25,  make_pair("Rubinum","CH1")), make_pair(13010, "51.83.151.177") },
	{ make_pair(26,  make_pair("Rubinum","CH2")), make_pair(13000, "51.83.151.177") },
	{ make_pair(27,  make_pair("Rubinum","CH3")), make_pair(13070, "51.83.151.177") },
	{ make_pair(28,  make_pair("Rubinum","CH4")), make_pair(13340, "51.210.33.62") },
	{ make_pair(29,  make_pair("Rubinum","CH5")), make_pair(13130, "51.83.151.177") },
	{ make_pair(30,  make_pair("Rubinum","CH6")), make_pair(13160, "51.210.33.62") },
	{ make_pair(31,  make_pair("Rubinum","CH7")), make_pair(13190, "51.83.151.177") },
	{ make_pair(32,  make_pair("Rubinum","CH8")), make_pair(13220, "51.210.33.62") },
	{ make_pair(32,  make_pair("Rubinum","CH9")), make_pair(13250, "185.100.87.115") },
	{ make_pair(33,  make_pair("Rubinum","CH10")), make_pair(13280, "185.100.87.115") },
	{ make_pair(34,  make_pair("Rubinum","CH11")), make_pair(13310, "185.100.87.115") },
	{ make_pair(35,  make_pair("Rubinum","CH12")), make_pair(13340, "185.100.87.115") },
	
};


vector<string> Settings::DETECT_PLAYER_WHITE_LIST_NAMES;
map< pair<DWORD, bool>, pair<DWORD, string>> Settings::FISHBOT_KILL_FISH_LIST =
{
	{ make_pair(0, false), make_pair(27987, "Małż") },
	{ make_pair(1, true), make_pair(27803, "Karaś")},	
	{ make_pair(2, true), make_pair(27804, "Ryba Mandaryna")},
	{ make_pair(3, true), make_pair(27805, "Duży Karaś")},
	{ make_pair(4, true), make_pair(27806, "Karp")},
	{ make_pair(5, true), make_pair(27807, "Losoś")},
	{ make_pair(6, true), make_pair(27808, "Amur")},
	{ make_pair(7, true), make_pair(27809, "Pstrag")},
	{ make_pair(8, true), make_pair(27810, "Węgorz")},
	{ make_pair(9, true), make_pair(27811, "Teczowy Pstrąg")},
	{ make_pair(10, true), make_pair(27812, "Rzeczny Pstrąg")},
	{ make_pair(11, true), make_pair(27813, "Krasnopiórka")},
	{ make_pair(12, true), make_pair(27814, "Okoń")},
	{ make_pair(13, true), make_pair(27815, "Tenchi")},
	{ make_pair(14, true), make_pair(27816, "Sum")},
	{ make_pair(15, true), make_pair(27817, "Piskorz")},
	{ make_pair(16, true), make_pair(27818, "Ryba Lotosu")},
	{ make_pair(17, true), make_pair(27819, "Słodka Ryba")},
	{ make_pair(18, true), make_pair(27820, "Gromadnik")},
	{ make_pair(19, true), make_pair(27821, "Shiri")},
	{ make_pair(20, true), make_pair(27822, "Lustrzany Karp")},
	{ make_pair(21, true), make_pair(27823, "Złoty Karał")},

#ifdef METINPL
	{ make_pair(22, true), make_pair(27824, "Weżoglów")},
	{ make_pair(23, true), make_pair(27825, "Skaber")},
	{ make_pair(24, true), make_pair(27826, "Krab Królewski")},
	{ make_pair(25, true), make_pair(27827, "Rak Niebiański")},

#endif
};
//##########################################################################################
map< pair<DWORD, bool>, pair<DWORD, string>> Settings::FISHBOT_BAIT_LIST =
{
#ifdef METINPL
	{ make_pair(1, true), make_pair(27798, "Krewetki Słodkowodne")},
#endif
	{ make_pair(2, true), make_pair(27802, "Drobne Ryby")},
	{ make_pair(3, true), make_pair(27801, "Robak")},
	{ make_pair(4, true), make_pair(27800, "Papka")},

};



map< pair<DWORD, bool>, pair<DWORD, string>> Settings::FISHBOT_DROP_LIST =
{

	{ make_pair(1, false), make_pair(50002, "Złoty Pierścień") },
	{ make_pair(2, false), make_pair(70201, "Wybielacz") },
	{ make_pair(3, false), make_pair(70202, "Biała Farba Do Włosów") },
	{ make_pair(4, false), make_pair(70203, "Blond Farba Do Włosów") },
	{ make_pair(5, false), make_pair(70204, "Czerw.Farba Do Włosów") },
	{ make_pair(6, false), make_pair(70205, "Brązowa Farba Do Włosów") },
	{ make_pair(7, false), make_pair(70206, "Czarna Farba Do Włosów") },

	{ make_pair(8, false), make_pair(50043, "Klucz Nimfy Wodnej") },
	{ make_pair(9, false), make_pair(70050, "Symb. Króla Przepowiedni") },
	{ make_pair(10, false), make_pair(70048, "Peleryna Maskująca") },
	{ make_pair(11, false), make_pair(50009, "Srebny Klucz") },


	{ make_pair(12, false), make_pair(50008, "Złoty Klucz") },
	{ make_pair(13, false), make_pair(70049, "Pierścień Lucy") },
	{ make_pair(14, false), make_pair(70051, "Rękawica Króla Przepowiedni") },

	{ make_pair(16, false), make_pair(80008, "Bryła Złota") },
	{ make_pair(17, false), make_pair(27799, "Rybia Ość") },
	{ make_pair(18, false), make_pair(27990, "Kawałek Kamienia") },
	{ make_pair(19, false), make_pair(27987, "Małż") },
	{ make_pair(20, false), make_pair(27833, "Martwy Karaś") },
	{ make_pair(21, false), make_pair(27834, "Martwa Ryba Mandaryna") },
	{ make_pair(22, false), make_pair(27835, "Martwy Duży Karś") },
	{ make_pair(23, false), make_pair(27836, "Martwy Karp") },
	{ make_pair(24, false), make_pair(27837, "Martwy Łosoś") },

	{ make_pair(26, false), make_pair(27838, "Martwy Amur") },
	{ make_pair(27, false), make_pair(27839, "Martwy Pstrąg") },
	{ make_pair(28, false), make_pair(27840, "Martwy Węgorz") },
	{ make_pair(29, false), make_pair(27841, "Martwy Tęczowy Pstrąg") },
	{ make_pair(30, false), make_pair(27842, "Martwy Rzeczny Pstrąg") },
	{ make_pair(31, false), make_pair(27843, "Martwa Krasnopiórka") },
	{ make_pair(32, false), make_pair(27844, "Martwy Okoń") },
	{ make_pair(33, false), make_pair(27845, "Martwa Tenchi") },
	{ make_pair(34, false), make_pair(27846, "Martwy Sum") },
	{ make_pair(35, false), make_pair(27847, "Martwy Piskorz") },
	{ make_pair(36, false), make_pair(27848, "Martwa Ryba Lotosu") },
	{ make_pair(37, false), make_pair(27849, "Martwa Słodka Ryba") },
	{ make_pair(38, false), make_pair(27850, "Martwy Gromadnik") },
	{ make_pair(39, false), make_pair(27851, "Martwa Shiri") },
	{ make_pair(40, false), make_pair(27852, "Martwy Lustrzany Karp") },
	{ make_pair(41, false), make_pair(27853, "Martwy Złoty Karaś") },




#ifdef METINPL
{ make_pair(42, false), make_pair(27854, "Martwy Wężogóów") },
{ make_pair(43, false), make_pair(27855, "Martwy Skaber") },
{ make_pair(44, false), make_pair(27856, "Martwy Krab Królewski") },
{ make_pair(45, false), make_pair(27857, "Martwy Rak Niebieski") },

#endif
};
map< pair<DWORD, bool>, pair<DWORD, string>> Settings::FISHBOT_SELL_LIST =
{

	{ make_pair(1, true), make_pair(50002, "Złoty Pierścień") },
	{ make_pair(2, true), make_pair(70201, "Wybielacz") },
	{ make_pair(3, true), make_pair(70202, "Biała Farba Do Włosów") },
	{ make_pair(4, true), make_pair(70203, "Blond Farba Do Włosów") },
	{ make_pair(5, true), make_pair(70204, "Czerw.Farba Do Włosów") },
	{ make_pair(6, true), make_pair(70205, "Brązowa Farba Do Włosów") },
	{ make_pair(7, true), make_pair(70206, "Czarna Farba Do Włosów") },

	{ make_pair(8, true), make_pair(50043, "Klucz Nimfy Wodnej") },
	{ make_pair(9, true), make_pair(70050, "Symb. Króla Przepowiedni") },
	{ make_pair(10, true), make_pair(70048, "Peleryna Maskująca") },
	{ make_pair(11, true), make_pair(50009, "Srebny Klucz") },


	{ make_pair(12, true), make_pair(50008, "Złoty Klucz") },
	{ make_pair(13, true), make_pair(70049, "Pierścień Lucy") },
	{ make_pair(14, true), make_pair(70051, "Rękawica Króla Przepowiedni") },

	{ make_pair(16, true), make_pair(80008, "Bryła Złota") },
	{ make_pair(17, true), make_pair(27799, "Rybia Ość") },
	{ make_pair(18, true), make_pair(27990, "Kawałek Kamienia") },
	{ make_pair(19, false), make_pair(27987, "Małż") },
	{ make_pair(20, true), make_pair(27833, "Martwy Karaś") },
	{ make_pair(21, true), make_pair(27834, "Martwa Ryba Mandaryna") },
	{ make_pair(22, true), make_pair(27835, "Martwy Duży Karś") },
	{ make_pair(23, true), make_pair(27836, "Martwy Karp") },

	{ make_pair(25, true), make_pair(27837, "Martwy Łosoś") },
	{ make_pair(26, true), make_pair(27838, "Martwy Amur") },
	{ make_pair(27, true), make_pair(27839, "Martwy Pstrąg") },
	{ make_pair(28, true), make_pair(27840, "Martwy Węgorz") },
	{ make_pair(29, true), make_pair(27841, "Martwy Tęczowy Pstrąg") },
	{ make_pair(30, true), make_pair(27842, "Martwy Rzeczny Pstrąg") },
	{ make_pair(31, true), make_pair(27843, "Martwa Krasnopiórka") },
	{ make_pair(32, true), make_pair(27844, "Martwy Okoń") },
	{ make_pair(33, true), make_pair(27845, "Martwa Tenchi") },
	{ make_pair(34, true), make_pair(27846, "Martwy Sum") },
	{ make_pair(35, true), make_pair(27847, "Martwy Piskorz") },
	{ make_pair(36, true), make_pair(27848, "Martwa Ryba Lotosu") },
	{ make_pair(37, true), make_pair(27849, "Martwa Słodka Ryba") },
	{ make_pair(38, false), make_pair(27850, "Martwy Gromadnik") },
	{ make_pair(39, true), make_pair(27851, "Martwa Shiri") },
	{ make_pair(40, true), make_pair(27852, "Martwy Lustrzany Karp") },
	{ make_pair(41, true), make_pair(27853, "Martwy Złoty Karaś") },




#ifdef METINPL
{ make_pair(42, false), make_pair(27854, "Martwy Wężogóów") },
{ make_pair(43, false), make_pair(27855, "Martwy Skaber") },
{ make_pair(44, false), make_pair(27856, "Martwy Krab Królewski") },
{ make_pair(45, false), make_pair(27857, "Martwy Rak Niebieski") },

#endif
};


bool Settings::DropBotEnable = false;

bool Settings::LevelBotEnable = false;
bool Settings::LevelBotMob = false;
bool Settings::LevelBotBoss = false;
bool Settings::LevelBotMetin = true;
int Settings::LevelBotDistance = 3000;
int Settings::LevelBotMoveType = 0;
int Settings::LevelBotAttackType = 0;
float Settings::LevelBotCoordsX[250] = { 0 };
float Settings::LevelBotCoordsY[250] = { 0 };
bool Settings::FishBotEnable = false;
bool Settings::StatusEnable = false;
bool Settings::MainInfoStonesViewportShow = false;
bool Settings::StatusInfoMinesViewportShow = false;
bool Settings::StatusInfoBossesViewportShow = false;



bool Settings::GLOBAL_SWITCH = false;
bool Settings::MiniMHAttackEnable = false;
bool Settings::MiniMHRotation = false;
int Settings::MiniMHRotationValue = 30;

bool Settings::MAIN_SKILL_ENABLE = false;
bool Settings::MAIN_SLOT_ENABLE_3 = false;
bool Settings::MAIN_SLOT_ENABLE_4 = false;
bool Settings::MAIN_SLOT_ENABLE_5 = false;
bool Settings::MAIN_SLOT_ENABLE_6 = false;
bool Settings::MAIN_SLOT_ENABLE_7 = false;
bool Settings::MAIN_SLOT_ENABLE_8 = false;
bool Settings::MAIN_SLOT_ENABLE_9 = false;
bool Settings::MAIN_SLOT_ENABLE_10 = false;
bool Settings::MAIN_SLOT_ENABLE_11 = false;
bool Settings::MAIN_SLOT_ENABLE_12 = false;
bool Settings::MAIN_SLOT_ENABLE_13 = false;
bool Settings::MAIN_SLOT_ENABLE_14 = false;
bool Settings::MAIN_SLOT_ENABLE_15 = false;
bool Settings::MAIN_SLOT_ENABLE_16 = false;


float Settings::ITEM_SLOT_TIME_3 = 0.700;
float Settings::ITEM_SLOT_TIME_4 = 0.700;
float Settings::ITEM_SLOT_TIME_5 = 0.700;
float Settings::ITEM_SLOT_TIME_6 = 0.700;
float Settings::ITEM_SLOT_TIME_7 = 0.700;
float Settings::ITEM_SLOT_TIME_8 = 0.700;
float Settings::ITEM_SLOT_TIME_9 = 0.700;
float Settings::ITEM_SLOT_TIME_10 = 0.700;
float Settings::ITEM_SLOT_TIME_11 = 0.700;
float Settings::ITEM_SLOT_TIME_12 = 0.700;
float Settings::ITEM_SLOT_TIME_13 = 0.700;
float Settings::ITEM_SLOT_TIME_14 = 0.700;
float Settings::ITEM_SLOT_TIME_15 = 0.700;
float Settings::ITEM_SLOT_TIME_16 = 0.700;



bool Settings::MiniMHNOK = false;
bool Settings::MiniMHNOP = false;


bool Settings::MainWallHackMob = false;
bool Settings::MainWallHackObject = false;
bool Settings::MainWallHackTerrain = false;


bool Settings::MiniMHMoveSpeed = false;
int Settings::MiniMHMoveSpeedValue = 350;
bool Settings::MiniMHAttackSpeed = false;
int Settings::MiniMHAttackSpeedValue = 200;
bool Settings::MiniMHAttackStopAttackNoMobDistance = false;
bool Settings::MiniMHUseRedPotion = false;
bool Settings::MiniMHUseBluePotion = false;
int Settings::MiniMHUseRedPotionValue = 80;
int Settings::MiniMHUseRedPotionSpeed = 100;


int Settings::MiniMHUseBluePotionValue = 80;
int Settings::MiniMHUseBluePotionSpeed = 100;
bool Settings::MiniMHAutoRevive = false;
int Settings::MiniMHAutoReviveHpPercentValue = 60;




bool Settings::MAIN_SKILL_1 = false;
bool Settings::MAIN_SKILL_2 = false;
bool Settings::MAIN_SKILL_3 = false;
bool Settings::MAIN_SKILL_4 = false;
bool Settings::MAIN_SKILL_5 = false;
bool Settings::MAIN_SKILL_6 = false;
bool Settings::MiniMHWaitHackEnable = false;
int Settings::MiniMHWaitHackDistanceValue = 4000;
int Settings::MiniMHWaitHackType = 0;
int Settings::MiniMHWaitHackSkillDelay = 25;
bool Settings::MiniMHWaitHackSwordRange = false;
int Settings::MiniMHWaitHackTime = 50;
int Settings::MiniMHWaitHackOneTarget = 0;
bool Settings::MiniMHWaitHackDetect = false;


bool Settings::ITEM_PICKUP_ENABLE = false;
bool Settings::ITEM_PICKUP_FILTER = false;
int Settings::ITEM_PICKUP_TIME = 100;
int Settings::ITEM_PICKUP_TYPE = 0;
map< DWORD, pair<string, bool>> Settings::ITEM_PICKUP_SELECTED_LIST;
//#############################################################################################
bool Settings::ProtectionShowWisperLogs = false;
bool Settings::ProtectionShowWisperBalloon = false;
bool Settings::ProtectionShowTalkBalloon = false;
bool Settings::ProtectionPlayWisperBeep = false;
bool Settings::ProtectionPlayTalkBeep = false;
bool Settings::ProtectionRestoreWisperWindow = false;
bool Settings::ProtectionFlashWisperIcon = false;
bool Settings::ProtectionFlashTalkIcon = false;
bool Settings::ProtectionShowTalkLogs = false;

bool Settings::BUFF_ENABLE = false;
bool Settings::BUFF_SKILL_1 = false;
bool Settings::BUFF_SKILL_2 = false;
bool Settings::BUFF_SKILL_3 = false;
int Settings::BUFF_SKILL_1_TIME = 11000;
int Settings::BUFF_SKILL_2_TIME = 11000;
int Settings::BUFF_SKILL_3_TIME = 11000;

int Settings::FishBotSuccesPercentValue = 0;
int Settings::FishBotCastTimeMinValue = 250;
int Settings::FishBotCastTimeMaxValue = 500;
int Settings::FishBotRoundTimeMinValue = 9000;
int Settings::FishBotRoundTimeMaxValue = 10000;
int  Settings::FishBotEmergencyRunTimeValue = 50500;
bool Settings::FISHBOT_DETECT_PLAYER = true;


bool Settings::FishBotStopIfPositionChanged = false;
bool Settings::FishBotStopIfInventoryFull = true;
bool Settings::FishBotUseFirstSlot = false;
bool Settings::FISHBOT_KILL_FISH = false;
bool Settings::FISHBOT_SELL_TRASH = false;
bool Settings::FISHBOT_DROP_TRASH = false;

int Settings::FISHBOT_SELL_TRASH_AFTER_PERCENTAGE = 60;

bool Settings::FISHBOT_BUY_BAIT = false;;
int Settings::FISHBOT_BUY_BAIT_SHOP_SLOT = 8;
int Settings::FISHBOT_BUY_BAIT_SHOP_COUNT =10;
int Settings::FISHBOT_CAST_ROTATION = 200;
bool Settings::FISHBOT_SHOP_CAST_TELEPORT = false;
D3DVECTOR Settings::FISHBOT_SHOP_TELEPORT_CORDS  = { 0, 0, 0 };;
D3DVECTOR Settings::FISHBOT_CAST_TELEPORT_CORDS = { 0, 0, 0 };;



bool Settings::FishBotSuccesPercent = false;
bool Settings::FishBotCastTime = true;
bool Settings::FishBotRoundTime = true;
bool Settings::FishBotEmergencyRunTime = true;
bool Settings::FishBotKillTillSize = false;
double Settings::FishBotKillTillSizeValue = 10;
//#################################################################################################





bool Settings::ProtectionDisableRender = false;
bool Settings::PerformanceDisableRenerFrames = false;


//##################################################################################################


bool Settings::SPAM_NORMAL_ENABLE = false;
bool Settings::SPAM_SHOUT_ENABLE = false;
bool Settings::SPAM_WISPER_ENABLE = false;
int	Settings::SPAM_NORMAL_TIME = 15000;
int	Settings::SPAM_WHISPER_TIME = 15000;
int  Settings::SPAM_SHOUT_TIME = 15000;
ImVec4 Settings::SPAM_NORMAL_COLOR = ImColor(255, 0, 102);
ImVec4 Settings::SPAM_WHISPER_COLOR = ImColor(255, 0, 102);
ImVec4 Settings::SPAM_SHOUT_COLOR = ImColor(255, 0, 102);


bool Settings::SPAM_NORMAL_COLOR_ENABLE = false;
bool Settings::SPAM_WHISPER_COLOR_ENABLE = false;
bool Settings::SPAM_SHOUT_COLOR_ENABLE = false;









bool Settings::ProtectionAutoLogin = false;
int Settings::BoostKey = VK_TAB;
int Settings::RelogKey = VK_F9;
int Settings::OnOffMH = VK_OEM_3;
DWORD Settings::HotkeyTime = 0;
int Settings::BoostSpeed1 = 14;
int Settings::BoostSpeed2 = 1;
int Settings::BoostSpeed3 = 47;
//render
ImVec4 Settings::renderwh_color = ImColor(255, 0, 0, 15);
bool Settings::renderwh = true;
//
ImVec4 Settings::monster_color = ImVec4(255, 0, 0, 255);
ImVec4 Settings::boss_color = ImColor(255, 64, 0);
ImVec4 Settings::npc_color = ImVec4(0, 255, 0, 255);
ImVec4 Settings::mining_color = ImColor(255, 0, 102);
ImVec4 Settings::metin_color = ImVec4(0, 0, 255, 255);
ImVec4 Settings::pc_color = ImVec4(239, 255, 0, 255);
ImVec4 Settings::waypoint_color = ImColor(43, 211, 120, 255);
bool Settings::monster_show = true;
bool Settings::boss_show = true;
bool Settings::npc_show = true;
bool Settings::mining_show = true;
bool Settings::metin_show = true;
bool Settings::pc_show = true;
bool Settings::waypoint_show = true;
float Settings::box_posx;
float Settings::box_posy;
float Settings::box_posz;
float Settings::radar_zoom = 1.0f;
int Settings::MiniMHSkillNumber = 35;

int Settings::REFINE_UPGRADE_TYPE = 0;
int Settings::REFINE_UPGRADE_COUNT = 1;
int Settings::REFINE_ITEM_SLOT = 1;