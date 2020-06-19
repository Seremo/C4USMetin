#pragma once
class Fish : public IAbstractModuleBase, public Singleton<Fish>
{
private:

	
public:

#ifdef IVEYA
	 const char* actionString ="";
#endif
	int action = 0;
	int couting = 0;
	bool isEnable = false;
	DWORD lastTimeFishing = 0;
	bool isNeedRoundTimeCast = false;
#ifdef IVEYA
	const char* FishBot::actionString = NULL;
#endif
	DWORD  lastTimeBotCast = 0;
	DWORD  lastTimeBotRoundTime = 0;
	D3DVECTOR standingPosition;
	void OnStart()
	{
		isEnable = true;
		lastTimeFishing = GetTickCount();

		lastTimeBotCast = GetTickCount();
		lastTimeBotRoundTime = GetTickCount();
		Logger::Add(Logger::FISH, true, Logger::GREEN, "START");
		
		standingPosition = GameFunctionsCustom::PlayerGetPixelPosition();
		Logger::Add(Logger::FISH, true, Logger::WHITE,"POSITION %f %f", (standingPosition.x / 100) ,(standingPosition.y / 100) );
		NewCast();


	}
	void OnStop()
	{
		isEnable = false;
		Logger::Add(Logger::FISH, true, Logger::RED, "STOP");
		standingPosition = { 0, 0, 0 };

#ifdef METINPL
		GameFunctions::NetworkStreamSendEmoticon(116);
		GameFunctions::NetworkStreamSendFishingGlobalPacket(3, 0);
#endif

	}
	void OnUpdate()
	{

		if (isEnable)
		{
			if (Settings::FishBotEmergencyRunTime)
			{
				if ((GetTickCount() - lastTimeFishing) > Settings::FishBotEmergencyRunTimeValue && lastTimeFishing != 0)
				{
					action = -1;
					Logger::Add(Logger::FISH, true, Logger::RED, "RESUME");
#ifdef METINPL
					Cast2();
#endif
					NewCast();
					lastTimeFishing = GetTickCount();
				}
			}
			if (action > 0 && action < 7)
			{
				if (Settings::FishBotSuccesPercent)
				{
					int loseRandom = MiscExtension::Random(1, 100);
					if (loseRandom <= Settings::FishBotSuccesPercentValue)
					{
						Logger::Add(Logger::FISH, true, Logger::WHITE, "RANDOM FALSE");
						action += 1;
					}
					else
					{
						

					}
				}
				if (Settings::FishBotCastTime)
				{
					int clickTime = MiscExtension::Random(Settings::FishBotCastTimeMinValue, Settings::FishBotCastTimeMaxValue);
					if ((GetTickCount() - lastTimeBotCast) > clickTime)
					{
						
#ifdef METINPL

						Cast2();
#else
						Cast();
#endif
						action--;
						Logger::Add(Logger::FISH, true, Logger::WHITE, "CLICK %d AFTER %d (ms)", action, clickTime);
						lastTimeBotCast = GetTickCount();
						if (action == 0)
						{
							lastTimeBotRoundTime = GetTickCount();
							isNeedRoundTimeCast = true;
						}
					}
				}
				else
				{
				
#ifdef METINPL

					Cast2();
#else
					Cast();
#endif
					action--;
					Logger::Add(Logger::FISH, true, Logger::WHITE, "CLICK %d" , action);
					if (action == 0)
					{
						lastTimeBotRoundTime = GetTickCount();
						isNeedRoundTimeCast = true;
					}
				}
			}
			else
			{
				if (Settings::FishBotRoundTime)
				{
					int waitTime = MiscExtension::Random(Settings::FishBotRoundTimeMinValue, Settings::FishBotRoundTimeMaxValue);
					if ((GetTickCount() - lastTimeBotRoundTime) > waitTime && isNeedRoundTimeCast)
					{
						
						Logger::Add(Logger::FISH, true, Logger::WHITE, "WAIT FOR ENDING %d (ms)", waitTime);//GREEN
						NewCast();
						action = -1;
						lastTimeBotRoundTime = GetTickCount();
						isNeedRoundTimeCast = false;
					}
				}
				else
				{
					if ((GetTickCount() - lastTimeBotRoundTime) > 0 && isNeedRoundTimeCast)
					{

						
						Logger::Add(Logger::FISH, true, Logger::WHITE, "NEW START");
						NewCast();
						action = -1;
						lastTimeBotRoundTime = GetTickCount();
						isNeedRoundTimeCast = false;
					}
				}
#ifdef IVEYA
				if (actionString != NULL)
				{


					vector<int> mili;
					string str1 = (const char*)actionString;
					string str2 = StringExtension::ReplaceString(str1, "LowienieRn ", "");

					std::string delimiter = "|";

					size_t pos = 0;
					std::string token;
					while ((pos = str2.find(delimiter)) != std::string::npos) {
						token = str2.substr(0, pos);
						mili.push_back(stoi(token));
						str2.erase(0, pos + delimiter.length());
					}
					mili.push_back(stoi(str2));
					int u[4];
					u[0] = (mili[0]) * 9;
					u[1] = (mili[1] - mili[0]) * 9;
					u[2] = (mili[2] - mili[1]) * 9;
					u[3] = (mili[3] - mili[2]) * 9;

					string uu = "/fevent " + to_string((mili[0] + mili[1] + mili[2] + mili[3]) - 8);
					Hooks::nCPythonNetworkStreamSendChatPacket((void*)Globals::iCPythonNetworkStreamInstance, uu.c_str(), 0);


					actionString = NULL;
				}
#endif
			}
			/*int extraWait = Misc::Random(1, 9000);
			if (extraWait < 5)
			{
			//QMetaObject::invokeMethod(Globals::mainform, "AppendFishBotLog", Q_ARG(QString, "WYLOSOWANO DODATKOWA PRZERWE SORRY :" ));
			Sleep(9000);
			}*/
		}
	}

	void OnRender()
	{
	}


	void OnMenu()
	{
		Logger::Draw(Logger::FISH);
		
		
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("RandomizerBorder", ImVec2(400, 200), true);
		
		//Przyciski
		ImGui::Checkbox("Stop - Position Changed", &Settings::FishBotStopIfPositionChanged); 	ImGui::SameLine();
		ImGui::Checkbox("Stop - Equipment Full", &Settings::FishBotStopIfInventoryFull);
		/*ImGui::Text("Randomizer(1000=1sekunda)");*/
		ImGui::Columns(2, "randomizer", false);  // 3-ways, no border
		ImGui::Checkbox("Random Falsa %", &Settings::FishBotSuccesPercent);
		ImGui::SliderInt("%", &Settings::FishBotSuccesPercentValue, 0, 100);
		ImGui::Checkbox("Random Click Time", &Settings::FishBotCastTime);
		ImGui::InputInt("##randclick", &Settings::FishBotCastTimeMinValue, 100, 1000);
		ImGui::InputInt("##randclick2", &Settings::FishBotCastTimeMaxValue, 100, 1000);
		ImGui::NextColumn();
		ImGui::Checkbox("Detect Player", &Settings::FISHBOT_DETECT_PLAYER);
		ImGui::Checkbox("Emergency Resume", &Settings::FishBotEmergencyRunTime);
		ImGui::InputInt("##emergencytimeout", &Settings::FishBotEmergencyRunTimeValue, 100, 1000);
		ImGui::Checkbox("Random End Times", &Settings::FishBotRoundTime);
		ImGui::InputInt("##randtour", &Settings::FishBotRoundTimeMinValue, 100, 1000);
		ImGui::InputInt("##randtour2", &Settings::FishBotRoundTimeMaxValue, 100, 1000);
		ImGui::EndChild();
		ImGui::PopStyleVar(); ImGui::SameLine();
		//Przynety
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("BaitBorder", ImVec2(235, 200), true);
		ImGui::Text("Bait Type Use");
		ImGui::Checkbox("1 slot", &Settings::FishBotUseFirstSlot);

		for (map< pair<DWORD, bool>, pair<DWORD, string>> ::iterator itor = Settings::FISHBOT_BAIT_LIST.begin(); itor != Settings::FISHBOT_BAIT_LIST.end(); itor++)
		{

			ImGui::Checkbox(itor->second.second.c_str(), (bool*)&itor->first.second);
			ImGui::NextColumn();

		}
#ifdef VERSION_PREMIUM
		ImGui::Checkbox("Buy Bait", &Settings::FISHBOT_BUY_BAIT);
		ImGui::InputInt("Count", &Settings::FISHBOT_BUY_BAIT_SHOP_COUNT);
		ImGui::InputInt("Slot", &Settings::FISHBOT_BUY_BAIT_SHOP_SLOT);
		ImGui::InputInt("Roration", &Settings::FISHBOT_CAST_ROTATION);
		ImGui::Checkbox("Teleport", &Settings::FISHBOT_SHOP_CAST_TELEPORT);
		if (ImGui::Button("Add Shop Pos")) 
		{
			Settings::FISHBOT_SHOP_TELEPORT_CORDS = GameFunctionsCustom::PlayerGetPixelPosition();
		}
		ImGui::SameLine(); ImGui::Text((to_string(DWORD(Settings::FISHBOT_SHOP_TELEPORT_CORDS.x / 100)) + " " + to_string(DWORD(Settings::FISHBOT_SHOP_TELEPORT_CORDS.y / 100))).c_str());
		if (ImGui::Button("Add Cast Pos"))
		{
			Settings::FISHBOT_CAST_TELEPORT_CORDS = GameFunctionsCustom::PlayerGetPixelPosition();
		}
		ImGui::SameLine(); ImGui::Text((to_string(DWORD(Settings::FISHBOT_CAST_TELEPORT_CORDS.x / 100)) + " " + to_string(DWORD(Settings::FISHBOT_CAST_TELEPORT_CORDS.y / 100))).c_str());
#endif
		ImGui::EndChild();
		ImGui::PopStyleVar();

		//##########################################################################################

		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("KillBorder", ImVec2(635, 290), true);
		ImGui::Checkbox("Kill Fish", &Settings::FISHBOT_KILL_FISH);
		ImGui::Columns(3, "KillColumns", false);

		ImGui::Separator();

		for (map< pair<DWORD, bool>, pair<DWORD, string>>::iterator itor = Settings::FISHBOT_KILL_FISH_LIST.begin(); itor != Settings::FISHBOT_KILL_FISH_LIST.end(); itor++)
		{
			ImGui::Checkbox(itor->second.second.c_str(), (bool*)&itor->first.second);
			ImGui::NextColumn();
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
		//##########################################################################################


		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("DropBorder", ImVec2(635, 190), true);
		ImGui::Checkbox("Drop Trash", &Settings::FISHBOT_DROP_TRASH);
		ImGui::Separator();
		ImGui::Columns(3, "DropColumns", false);
		for (map< pair<DWORD, bool>, pair<DWORD, string>>::iterator itor = Settings::FISHBOT_DROP_LIST.begin(); itor != Settings::FISHBOT_DROP_LIST.end(); itor++)
		{
			ImGui::Checkbox(itor->second.second.c_str(), (bool*)&itor->first.second);
			ImGui::NextColumn();
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
		//##########################################################################################
#ifdef VERSION_PREMIUM
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("SellBorder", ImVec2(635, 190), true);
		ImGui::PushItemWidth(150); ImGui::Checkbox("Sell Trash", &Settings::FISHBOT_SELL_TRASH); ImGui::SameLine();
		ImGui::InputInt("After % EQ Filled", &Settings::FISHBOT_SELL_TRASH_AFTER_PERCENTAGE, 5, 100);
		ImGui::Separator();
		ImGui::Columns(3, "SellColumns", false);
		for (map< pair<DWORD, bool>, pair<DWORD, string>>::iterator itor = Settings::FISHBOT_SELL_LIST.begin(); itor != Settings::FISHBOT_SELL_LIST.end(); itor++)
		{
			ImGui::Checkbox(itor->second.second.c_str(), (bool*)&itor->first.second);
			ImGui::NextColumn();
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
#endif
	}



	void AppendCastDirect(int num)
	{
		if (!isEnable)
		{
			return;
		}
		action = num;
		Logger::Add(Logger::FISH, true, Logger::WHITE, string("REQUEST CLICK COUNT " + to_string(action) + "\n").c_str());
		
	}
	void AppendCastDirectString(int num, const char* message)
	{
		if (!isEnable)
		{
			return;
		}
#ifdef IVEYA
		actionString = message;
#endif
		action = num;
	}




	
	void CheckPosition()
	{
		if (Settings::FishBotStopIfPositionChanged)
		{

			D3DVECTOR currentPosition = GameFunctionsCustom::PlayerGetPixelPosition();
			if (standingPosition.x != currentPosition.x || standingPosition.y != currentPosition.y)
			{
				Logger::Add(Logger::FISH, true, Logger::RED, "DIFFRENT POSITION ABORT!");
				Settings::FishBotEnable = false;;
				isEnable = false;
				return;
			}

		}
	}

	void Cast()
	{

		if (!isEnable)
		{
			return;
		}
		CheckPosition();
		if (Settings::FishBotStopIfInventoryFull)
		{
			//if (GameFunctionsCustom::InventoryEquippedPercentage() > 80)
			//{
			   // MainForm::orbital_log_fishing(0, "##### Prawie Pelny ekwipunek - Stop   ######\n");
			   // ;
			   ///* Settings::FishBotEnable = false;
			   // isEnable = false;*/
			//}
		}
#if defined( GLADOR )||defined( VALIUM ) 
		TPacketCGFishing kPacketAtk;
		kPacketAtk.header = 82;
		GameFunctions::NetworkStreamSend(1, &kPacketAtk);
		TPacketCGFishing kPacketAtk2;
		kPacketAtk2.header = 0;
		GameFunctions::NetworkStreamSend(1, &kPacketAtk2);
		GameFunctions::NetworkStreamSendSequence();
		//GameFunctions::PlayerSetAttackKeyState(true);

	




#elif defined(DEVELOPER_MODE)

		if (Settings::FISHBOT_SHOP_CAST_TELEPORT)
		{

			if (DWORD(MiscExtension::CountDistanceTwoPoints(standingPosition.x, standingPosition.y, Settings::FISHBOT_CAST_TELEPORT_CORDS.x, Settings::FISHBOT_CAST_TELEPORT_CORDS.y) <= 2000))
			{
				GameFunctions::NetworkStreamSendCharacterStatePacket(Settings::FISHBOT_CAST_TELEPORT_CORDS, 0, 0, 0);
				GameFunctions::NetworkStreamSendFishingPacket(Settings::FISHBOT_CAST_ROTATION);
				GameFunctions::NetworkStreamSendCharacterStatePacket(standingPosition, 0, 0, 0);
			}
			else
			{
				Logger::Add(Logger::FISH, true, Logger::RED, "TP DISTANCE MORE THAN 2000");
			}

		}
		else
		{

			/*GameFunctions::NetworkStreamSendFishingPacket(Settings::FISHBOT_CAST_ROTATION);*/
			GameFunctions::PlayerSetAttackKeyState(true);
			/*GameFunctions::PythonPlayerNEW_Fishing();*/
		}
#else
		GameFunctions::PlayerSetAttackKeyState(true);
		/*GameFunctions::PythonPlayerNEW_Fishing();*/
#endif
		lastTimeFishing = GetTickCount();
	}

	void Cast2()
	{
		if (Settings::FISHBOT_DETECT_PLAYER)
		{
			if (GameFunctionsCustom::DetectPlayer(Settings::DETECT_PLAYER_WHITE_LIST_NAMES))
			{

				Logger::Add(Logger::FISH, true, Logger::RED, "DETECT PLAYER WAIT TO RESUME");
				return;
			}
		}
		GameFunctions::NetworkStreamSendEmoticon(116);
		if (!isEnable)
		{
			return;
		}
		CheckPosition();
		if (Settings::FishBotStopIfInventoryFull)
		{
			if (GameFunctionsCustom::IsFullInventory())
			{
				Logger::Add(Logger::FISH, true, Logger::WHITE, "EQUPMENT FULL ABORT!");
				Settings::FishBotEnable = false;
				isEnable = false;
			}
		}
		GameFunctions::NetworkStreamSendFishingGlobalPacket(3, 0);
		lastTimeFishing = GetTickCount();
	}

	void NewCast()
	{
		if (!isEnable)
		{
			return;
		}
		if (Settings::FISHBOT_DETECT_PLAYER)
		{
			if (GameFunctionsCustom::DetectPlayer(Settings::DETECT_PLAYER_WHITE_LIST_NAMES))
			{

				Logger::Add(Logger::FISH, true, Logger::WHITE, "DETECT PLAYER WAIT TO RESUME");
				return;
			}
		}
		if (Settings::FISHBOT_SELL_TRASH && GameFunctionsCustom::InventoryEquippedPercentage() > Settings::FISHBOT_SELL_TRASH_AFTER_PERCENTAGE)
		{
			SellItems();
		}
		if (Settings::FISHBOT_DROP_TRASH)
		{
			DropItems();
		}
		if (Settings::FISHBOT_KILL_FISH)
		{
			KillFishes();
		}
		if (!UseBait())
		{
			if (Settings::FISHBOT_BUY_BAIT) 
			{
				BuyBait();
				if (!UseBait()) 
				{
					/*Settings::FishBotEnable = false;*/
					Logger::Add(Logger::FISH, true, Logger::WHITE, "NO BAITS ABORT!");
					return;
				}
			}
		}
		Cast();
	}


	bool BuyBait()
	{
		DWORD fishermanVid = GameFunctionsCustom::GetCloseObjectByVnum(9009);
		if (!fishermanVid)
		{
			Logger::Add(Logger::FISH, true, Logger::WHITE, "NO FISHERMAN!");
			return false;
		}
		GameFunctions::NetworkStreamSendOnClickPacket(fishermanVid);
		GameFunctions::NetworkStreamSendScriptAnswerPacket(1);
		for (int i = 0; i < Settings::FISHBOT_BUY_BAIT_SHOP_COUNT; i++)
		{
			GameFunctions::NetworkStreamSendShopBuyPacket(Settings::FISHBOT_BUY_BAIT_SHOP_SLOT - 1);
		}
		GameFunctions::NetworkStreamSendShopEndPacket();
		return true;
	}

	bool SellItems()
	{
		DWORD fishermanVid = GameFunctionsCustom::GetCloseObjectByVnum(9009);
		if (!fishermanVid)
		{
			Logger::Add(Logger::FISH, true, Logger::WHITE, "NO FISHERMAN!");
			return false;
		}
		GameFunctions::NetworkStreamSendOnClickPacket(fishermanVid);
		GameFunctions::NetworkStreamSendScriptAnswerPacket(1);
		for (map< pair<DWORD, bool>, pair<DWORD, string>>::iterator itor = Settings::FISHBOT_SELL_LIST.begin(); itor != Settings::FISHBOT_SELL_LIST.end(); itor++)
		{
			if (itor->first.second)
			{
				int i = 1;
				vector<DWORD> slotList = GameFunctionsCustom::FindItemSlotsInInventory(itor->second.first);
				for (vector<DWORD>::iterator it = slotList.begin(); it != slotList.end(); ++it, i++)
				{

					GameFunctions::NetworkStreamSendShopSellPacketNew(*it, 255);
					Logger::Add(Logger::FISH, true, Logger::WHITE,"SELLED %s FROM SLOT %d",  itor->second.second.c_str(), *it);
				}
			}
		}

		GameFunctions::NetworkStreamSendShopEndPacket();
		return true;
	}

	void DropItems()
	{
		for (map< pair<DWORD, bool>, pair<DWORD, string>>::iterator itor = Settings::FISHBOT_DROP_LIST.begin(); itor != Settings::FISHBOT_DROP_LIST.end(); itor++)
		{
			if (itor->first.second)
			{
				int i = 1;
				vector<DWORD> slotList = GameFunctionsCustom::FindItemSlotsInInventory(itor->second.first);
				for (vector<DWORD>::iterator it = slotList.begin(); it != slotList.end(); ++it, i++)
				{

					GameFunctions::NetworkStreamSendItemDropPacketNew(TItemPos(INVENTORY, *it), 0, 255);
					Logger::Add(Logger::FISH, true, Logger::WHITE, "DROPED %s FROM SLOT %d", itor->second.second.c_str(),*it);
				}
			}
		}
	}

	void KillFishes()
	{
		int i = 1;
		for (map< pair<DWORD, bool>, pair<DWORD, string>>::iterator itor = Settings::FISHBOT_KILL_FISH_LIST.begin(); itor != Settings::FISHBOT_KILL_FISH_LIST.end(); itor++)
		{
			if (itor->first.second)
			{

				vector<DWORD> slotList = GameFunctionsCustom::FindItemSlotsInInventory(itor->second.first);
				for (vector<DWORD>::iterator it = slotList.begin(); it != slotList.end(); ++it, i++)
				{

					GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, *it));
					Logger::Add(Logger::FISH, true, Logger::WHITE, "KILLED %s FROM SLOT %d" , itor->second.second.c_str(),*it);
				}
			}
		}
	}

	bool UseBait()
	{
		for (map< pair<DWORD, bool>, pair<DWORD, string>> ::iterator itor = Settings::FISHBOT_BAIT_LIST.begin(); itor != Settings::FISHBOT_BAIT_LIST.end(); itor++)
		{
			if (itor->first.second)
			{
				int slot = GameFunctionsCustom::FindItemSlotInInventory(itor->second.first);
				if (slot != -1)
				{
					GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, slot));
					Logger::Add(Logger::FISH, true, Logger::WHITE, "USED %s FROM SLOT %d",  itor->second.second.c_str() ,slot);
					return true;
				}
				else
				{
					Logger::Add(Logger::FISH, true, Logger::WHITE, "MISSING %s", itor->second.second.c_str());
				}
			}
		}
		if (Settings::FishBotUseFirstSlot)
		{
			Logger::Add(Logger::FISH, true, Logger::WHITE, "BAIT 1 SLOT");
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 0));
			return true;
		}
		return false;
	}

	void ParseMessage(const char* message)
	{
		if (!isEnable)
		{
			return;
		}
		for (map< DWORD, pair<string, DWORD>>::iterator itor = Settings::FISHBOT_COMMAND_LIST.begin(); itor != Settings::FISHBOT_COMMAND_LIST.end(); itor++)
		{
			string messageASCI = StringExtension::UTF8ToANSI((char*)itor->second.first.c_str());
			
			if (StringExtension::Contains(message, messageASCI))
			{
				
				action = itor->second.second;
				Logger::Add(Logger::FISH, true, Logger::WHITE, string("REQUEST CLICK COUNT " + to_string(action)+"\n").c_str());
			}
		}
	}


};

