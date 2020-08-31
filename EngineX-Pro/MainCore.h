#pragma once
class MainCore
{
public:
	static bool DXLoaded;
	static void Crack();
	static bool CheckMembers();	
	static void Initialize();
	static void UpdateLoop();
	static void ConsoleOutput(const char* txt, ...);
	static map < pair<DWORD, string>, pair<bool, shared_ptr<IAbstractModuleBase>>> moduleList;
};

map < pair<DWORD, string>, pair<bool, std::shared_ptr<IAbstractModuleBase>>>  MainCore::moduleList =
{
	{ make_pair(1, "Main"), make_pair(true, shared_ptr<IAbstractModuleBase >(new Main()))},
	{ make_pair(2, "Item"), make_pair(true,shared_ptr<IAbstractModuleBase >(new Item()))},
#ifdef FISHBOT
	{ make_pair(3, "Fish"), make_pair(true, shared_ptr<IAbstractModuleBase >(new Fish()))},
#endif
    { make_pair(4, "Farm"), make_pair(true, shared_ptr<IAbstractModuleBase >(new Farm()))},
	{ make_pair(5, "Spam"), make_pair(true,shared_ptr<IAbstractModuleBase >(new Spam()))},
	{ make_pair(6, "Refine"), make_pair(true,shared_ptr<IAbstractModuleBase >(new Refine()))},
	{ make_pair(7, "Buff"), make_pair(true,shared_ptr<IAbstractModuleBase >(new Buff()))},
	{ make_pair(8, "Status"), make_pair(true, shared_ptr<IAbstractModuleBase >(new Status()))},
#if defined( DEVELOPER_MODE) || defined( METINPL)
	{ make_pair(9, "PythonScript"), make_pair(true, shared_ptr<IAbstractModuleBase >(new PythonScript()))},
#endif
	{ make_pair(10, "Protection"), make_pair(true, shared_ptr<IAbstractModuleBase >(new Protection()))},
//	{ make_pair(11, "AutoTalk"), make_pair(false, shared_ptr<IAbstractModuleBase >(new AutoTalk()))},
	{ make_pair(12, "Radar"), make_pair(true,shared_ptr<IAbstractModuleBase >(new Radar()))},
//	{ make_pair(13, "Configuration"), make_pair(true,shared_ptr<IAbstractModuleBase >(new Configuration()))},
#ifdef DEVELOPER_MODE
	{ make_pair(14, "Debug"), make_pair(true, shared_ptr<IAbstractModuleBase >(new Debug()))},
	{ make_pair(15, "PacketSniffer"), make_pair(true, shared_ptr<IAbstractModuleBase >(new PacketSniffer()))},
	{ make_pair(16, "Dungeons"), make_pair(true, shared_ptr<IAbstractModuleBase >(new MainDungs()))},
#endif
};
