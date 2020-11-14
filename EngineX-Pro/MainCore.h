#pragma once
class MainCore
{
public:
	static bool DXLoaded;
	static void Crack();
	static void NetworkThread();
	static bool CheckMembers();	
	static void Initialize();
	static void UpdateLoop();
	static void ConsoleOutput(const char* txt, ...);
	static map < pair<pair<DWORD, DWORD>, string>, pair<bool, shared_ptr<IAbstractModuleBase>>> moduleList;
	static map < DWORD, pair<string, DWORD>> TabMenuList;
};

map < DWORD, pair<string, DWORD>> MainCore::TabMenuList =
{
	{1, make_pair("Main", 1)},
	{2, make_pair("Visuals", 15)},
	{3, make_pair("Settings", 16)},
#ifdef DEVELOPER_MODE
	{4, make_pair("Developer", 16)}
#endif
};

map < pair<pair<DWORD, DWORD>, string>, pair<bool, std::shared_ptr<IAbstractModuleBase>>>  MainCore::moduleList =
{
	{ make_pair(make_pair(1, 1), "Main"), make_pair(true, shared_ptr<IAbstractModuleBase >(new Main()))},
	{ make_pair(make_pair(2, 1), "Item"), make_pair(true,shared_ptr<IAbstractModuleBase >(new Item()))},
#ifdef FISHBOT
	{ make_pair(make_pair(3, 1), "Fish"), make_pair(true, shared_ptr<IAbstractModuleBase >(new Fish()))},
#endif
    { make_pair(make_pair(4, 1), "Farm"), make_pair(true, shared_ptr<IAbstractModuleBase >(new Farm()))},
	{ make_pair(make_pair(5, 1), "Spam"), make_pair(true,shared_ptr<IAbstractModuleBase >(new Spam()))},
	{ make_pair(make_pair(6, 1), "Refine"), make_pair(true,shared_ptr<IAbstractModuleBase >(new Refine()))},
	{ make_pair(make_pair(7, 1), "Buff"), make_pair(true,shared_ptr<IAbstractModuleBase >(new Buff()))},
	{ make_pair(make_pair(8, 1), "Status"), make_pair(true, shared_ptr<IAbstractModuleBase >(new Status()))},
#if defined( DEVELOPER_MODE) || defined( METINPL)
	{ make_pair(make_pair(9, 1), "PythonScript"), make_pair(true, shared_ptr<IAbstractModuleBase >(new PythonScript()))},
#endif
	{ make_pair(make_pair(10, 1), "Protection"), make_pair(true, shared_ptr<IAbstractModuleBase >(new Protection()))},
//	{ make_pair(make_pair(11, 1), "AutoTalk"), make_pair(false, shared_ptr<IAbstractModuleBase >(new AutoTalk()))},
	{ make_pair(make_pair(12, 2), "Radar"), make_pair(true,shared_ptr<IAbstractModuleBase >(new Radar()))},
	{ make_pair(make_pair(13, 3), "Configuration"), make_pair(true,shared_ptr<IAbstractModuleBase >(new Configuration()))},
#ifdef DEVELOPER_MODE
	{ make_pair(make_pair(14, 4), "Debug"), make_pair(true, shared_ptr<IAbstractModuleBase >(new Debug()))},
	{ make_pair(make_pair(15, 4), "PacketSniffer"), make_pair(true, shared_ptr<IAbstractModuleBase >(new PacketSniffer()))},
	{ make_pair(make_pair(16, 4), "Dungeons"), make_pair(true, shared_ptr<IAbstractModuleBase >(new MainDungs()))},
#endif
};
