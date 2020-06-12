#pragma once
class Fish : public IAbstractModuleBase, public Singleton<Fish>
{
private:

	
public:

	Fish(void)
	{
	}
	virtual ~Fish(void)
	{
	}

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
		MainForm::LogFish(0, "Start\n");
		standingPosition = GameFunctionsCustom::PlayerGetPixelPosition();
		MainForm::LogFish(0, ("Pozycja " + to_string((int)(standingPosition.x / 100)) + " " + to_string((int)(standingPosition.y / 100)) + "\n").c_str());//GREEN
		NewCast();


	}
	void OnStop()
	{
		isEnable = false;
		MainForm::LogFish(0, "Stop\n");
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
					MainForm::LogFish(0, "Rozruch\n");
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
						MainForm::LogFish(0, "Celowa przegrana.\n");
						action += 1;
					}
					else
					{
						MainForm::LogFish(0, ("Wymagane Klikniecia :" + to_string(action) + "\n").c_str());

					}
				}
				if (Settings::FishBotCastTime)
				{
					int clickTime = MiscExtension::Random(Settings::FishBotCastTimeMinValue, Settings::FishBotCastTimeMaxValue);
					if ((GetTickCount() - lastTimeBotCast) > clickTime)
					{
						string clickInfo = "Klik: " + to_string(action) + " Po: " + to_string(clickTime) + "ms";
#ifdef METINPL

						Cast2();
#else
						Cast();
#endif
						action--;
						MainForm::LogFish(0, (clickInfo + "\n").c_str());//GREEN
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
					string clickInfo = "Klik: " + to_string(action);
#ifdef METINPL

					Cast2();
#else
					Cast();
#endif
					action--;
					MainForm::LogFish(0, (clickInfo + "\n").c_str());//GREEN
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
						string waitInfo = "Odczekanie Konca Rundy: " + to_string(waitTime) + "ms";;
						MainForm::LogFish(0, (waitInfo + "\n").c_str());//GREEN
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

						string waitInfo = "Nowa Runda";;
						MainForm::LogFish(0, (waitInfo + "\n").c_str());//WHITE
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
		
		//Randomizer
		
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("RandomizerBorder", ImVec2(400, 200), true);
		MainForm::orbital_logs_draw(MainForm::ui.logs_fishing, "Fishbot Output", &MainForm::ShowFishLog);
		//Przyciski
		ImGui::Checkbox("STOP - Equipment Full", &Settings::FishBotStopIfPositionChanged); 	ImGui::SameLine();
		ImGui::Checkbox("STOP - Equipment Full", &Settings::FishBotStopIfInventoryFull);
		ImGui::Text("Randomizer(1000=1sekunda)");
		ImGui::Columns(2, "randomizer", false);  // 3-ways, no border
		ImGui::Checkbox("Celowy % porazki", &Settings::FishBotSuccesPercent);
		ImGui::SliderInt("%", &Settings::FishBotSuccesPercentValue, 0, 100);
		ImGui::Checkbox("Losowe Czasy Klikniec", &Settings::FishBotCastTime);
		ImGui::InputInt("##randclick", &Settings::FishBotCastTimeMinValue, 100, 1000);
		ImGui::InputInt("##randclick2", &Settings::FishBotCastTimeMaxValue, 100, 1000);
		ImGui::NextColumn();
		ImGui::Checkbox("Detect Player", &Settings::FISHBOT_DETECT_PLAYER);
		ImGui::Checkbox("Rozruch Po Czasie", &Settings::FishBotEmergencyRunTime);
		ImGui::InputInt("##emergencytimeout", &Settings::FishBotEmergencyRunTimeValue, 100, 1000);
		ImGui::Checkbox("Losowe Czasy Tury", &Settings::FishBotRoundTime);
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
#ifdef DEVELOPER_MODE
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
#ifdef DEVELOPER_MODE
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
				MainForm::LogFish(0, "Inna Pozycja - Stop\n");
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
				MainForm::LogFish(0, "Teleport Wiekszy Niz 2000\n");
			}

		}
		else
		{

			GameFunctions::NetworkStreamSendFishingPacket(Settings::FISHBOT_CAST_ROTATION);
		}
#else
		GameFunctions::PythonPlayerNEW_Fishing();
#endif
		lastTimeFishing = GetTickCount();
	}

	void Cast2()
	{
		if (Settings::FISHBOT_DETECT_PLAYER)
		{
			if (GameFunctionsCustom::DetectPlayer(Settings::DETECT_PLAYER_WHITE_LIST_NAMES))
			{

				MainForm::LogFish(0, "Player Detect - Czekanie na rozruch\n");
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
				MainForm::LogFish(0, "Pelny ekwipunek - Stop\n");
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

				MainForm::LogFish(0, "Player Detect - Czekanie na rozruch\n");
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
			if (Settings::FISHBOT_BUY_BAIT) {
				BuyBait();
				if (!UseBait()) {
					/*Settings::FishBotEnable = false;*/
					MainForm::LogFish(0, "Brak przynet - STOP\n");
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
			MainForm::LogFish(0, "Brak Rybaka");
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
			MainForm::LogFish(0, "Brak Rybaka");
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
					MainForm::LogFish(0, string("Sprzedano " + itor->second.second + " z slotu " + to_string(*it) + " \n").c_str());
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
					MainForm::LogFish(0, string("Wywalono " + itor->second.second + " z slotu " + to_string(*it) + " \n").c_str());
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
					MainForm::LogFish(0, string("Zabito " + itor->second.second + " z slotu " + to_string(*it) + " \n").c_str());
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
					MainForm::LogFish(0, string("Użyto " + itor->second.second + "z slotu " + to_string(slot) + " \n").c_str());
					return true;
				}
				else
				{
					MainForm::LogFish(0, string("Brak " + itor->second.second + "\n").c_str());
				}
			}
		}
		if (Settings::FishBotUseFirstSlot)
		{
			MainForm::LogFish(0, "Przynęta 1 Slot\n");
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
#ifdef XENOX

		if (StringExtension::Contains(message, "Uzyj ponownie, aby zakonczyc lowienie"))
		{

			Cast();

		}
		if (StringExtension::Contains(message, "Nacisnij 1 razy spacje"))
		{

			action = 1;
		
		}
		else if (StringExtension::Contains(message, "Nacisnij 2 razy spacje"))
		{

			action = 2;
			
		}
		else if (StringExtension::Contains(message, "Nacisnij 3 razy spacje"))
		{

			action = 3;
			
		}
		else if (StringExtension::Contains(message, "Nacisnij 4 razy spacje"))
		{

			action = 4;
		
		}
		else if (StringExtension::Contains(message, "Nacisnij 5 razy spacje"))
		{

			action = 5;

		}
		if (action > 0)
		{

		}
		else
		{
			return;
		}
#endif
#ifdef VALIUM
		if (StringExtension::Contains(message, "hohfcthbhy.sub"))
		{
			action = 1;
		}
		else if (StringExtension::Contains(message, "klnbahqfuk.sub"))
		{
			action = 1;
		}
		else if (StringExtension::Contains(message, "zqsdlotxlt.sub"))
		{
			action = 1;
		}
		else if (StringExtension::Contains(message, "gkxegfenjh.sub"))
		{
			action = 1;
		}



		else if (StringExtension::Contains(message, "gulnvvwzbm.sub"))
		{
			action = 2;
		}
		else if (StringExtension::Contains(message, "blsvtqsbdr.sub"))
		{
			action = 2;
		}
		else if (StringExtension::Contains(message, "cfqdfqfnpl.sub"))
		{
			action = 2;
		}
		else if (StringExtension::Contains(message, "znvtfvjjlg.sub"))
		{
			action = 2;
		}




		else if (StringExtension::Contains(message, "addjvbzupo.sub"))
		{
			action = 3;
		}
		else if (StringExtension::Contains(message, "wxzcbjqoau.sub"))
		{
			action = 3;
		}
		else if (StringExtension::Contains(message, "izpjrgxwmk.sub"))
		{
			action = 3;
		}
		else if (StringExtension::Contains(message, "ulvnibygka.sub"))
		{
			action = 3;
		}







		else if (StringExtension::Contains(message, "mdscnufuca.sub"))
		{
			action = 4;
		}
		else if (StringExtension::Contains(message, "egyfkgjofh.sub"))
		{
			action = 4;
		}
		else if (StringExtension::Contains(message, "volexihnrf.sub"))
		{
			action = 4;
		}
		else if (StringExtension::Contains(message, "okgeihgbod.sub"))
		{
			action = 4;
		}




		else if (StringExtension::Contains(message, "mbiuatlxoc.sub"))
		{
			action = 5;
		}
		else if (StringExtension::Contains(message, "aehpjaevyo.sub"))
		{
			action = 5;
		}
		else if (StringExtension::Contains(message, "hmmngdctvb.sub"))
		{
			action = 5;
		}
		else if (StringExtension::Contains(message, "frwikxzsrn.sub"))
		{
			action = 5;
		}
		if (action > 0)
		{
			MainForm::orbital_log_fishing(0, (to_string(action) + " Ilosc Klikniec\n").c_str());//
		}

#endif
#ifdef GLADOR
		if (action < 5) {
			if (StringExtension::Contains(message, "mieso.tga"))
			{
				action += 1;
			}
			else if (StringExtension::Contains(message, "rozgwiazda.tga"))
			{
				action += 1;
			}
			else if (StringExtension::Contains(message, "osmiornica.tga"))
			{
				action += 1;
			}
		}
#endif
#ifdef VAROS
		if (StringExtension::Contains(message, "Naciśnij 1 razy"))
		{

			action = 1;
		}
		else if (StringExtension::Contains(message, "Naciśnij 2 razy"))
		{

			action = 2;
		}
		else if (StringExtension::Contains(message, "Naciśnij 3 razy"))
		{

			action = 3;
		}
		else if (StringExtension::Contains(message, "Naciśnij 4 razy"))
		{

			action = 4;
		}
		else if (StringExtension::Contains(message, "Naciśnij 5 razy"))
		{

			action = 5;
		}
		else
		{
			return;
		}
		MainForm::orbital_log_fishing(0, ("WYMAGANE KLIKNIECIA :" + to_string(action) + "\n").c_str());//
#endif
#ifdef ZAMORIA
		if (StringExtension::Contains(message, "Kliknij 1 razy"))
		{

			action = 1;
		}
		else if (StringExtension::Contains(message, "Kliknij 2 razy"))
		{

			action = 2;
		}
		else if (StringExtension::Contains(message, "Kliknij 3 razy"))
		{

			action = 3;
		}
		else if (StringExtension::Contains(message, "Kliknij 4 razy"))
		{

			action = 4;
		}
		else if (StringExtension::Contains(message, "Kliknij 5 razy"))
		{

			action = 5;
		}
		else
		{
			return;
		}
		MainForm::orbital_log_fishing(0, ("WYMAGANE KLIKNIECIA :" + to_string(action) + "\n").c_str());//
#endif
#ifdef DIUMAR
		if (StringExtension::Contains(message, "ile jest niebieskich kulek (1)"))
		{

			action = 1;
		}
		else if (StringExtension::Contains(message, "ile jest niebieskich kulek (2)"))
		{

			action = 2;
		}
		else if (StringExtension::Contains(message, "ile jest niebieskich kulek (3)"))
		{

			action = 3;
		}
		else if (StringExtension::Contains(message, "ile jest niebieskich kulek (4)"))
		{

			action = 4;
		}
		else if (StringExtension::Contains(message, "ile jest niebieskich kulek (5)"))
		{

			action = 5;
		}
		else
		{
			return;
		}
		MainForm::orbital_log_fishing(0, ("WYMAGANE KLIKNIECIA :" + to_string(action) + "\n").c_str());//
#endif
#ifdef AVENTUS2
		if (StringExtension::Contains(message, "Kliknij 1 razy spację, aby spróbować wyłowić rybę"))
		{

			action = 1;
		}
		else if (StringExtension::Contains(message, "Kliknij 2 razy spację, aby spróbować wyłowić rybę"))
		{

			action = 2;
		}
		else if (StringExtension::Contains(message, "Kliknij 3 razy spację, aby spróbować wyłowić rybę"))
		{

			action = 3;
		}
		else if (StringExtension::Contains(message, "Kliknij 4 razy spację, aby spróbować wyłowić rybę"))
		{

			action = 4;
		}
		else if (StringExtension::Contains(message, "Kliknij 5 razy spację, aby spróbować wyłowić rybę"))
		{

			action = 5;
		}
		else
		{
			return;
		}
		MainForm::orbital_log_fishing(0, ("WYMAGANE KLIKNIECIA :" + to_string(action) + "\n").c_str());//
#endif
#ifdef ELENIUM
		if (StringExtension::Contains(message, "1x|h|r aby wyłowić"))
		{

			action = 1;
		}
		else if (StringExtension::Contains(message, "2x|h|r aby wyłowić"))
		{

			action = 2;
		}
		else if (StringExtension::Contains(message, "3x|h|r aby wyłowić"))
		{

			action = 3;
		}
		else if (StringExtension::Contains(message, "4x|h|r aby wyłowić"))
		{

			action = 4;
		}
		else if (StringExtension::Contains(message, "5x|h|r aby wyłowić"))
		{

			action = 5;
		}
		else
		{
			return;
		}
		MainForm::orbital_log_fishing(0, ("WYMAGANE KLIKNIECIA :" + to_string(action) + "\n").c_str());//
#endif
#ifdef BALMORA
		if (StringExtension::Contains(message, "Zatnij rybę 1 razy"))
		{

			action = 1;
		}
		else if (StringExtension::Contains(message, "Zatnij rybę 2 razy"))
		{

			action = 2;
		}
		else if (StringExtension::Contains(message, "Zatnij rybę 3 razy"))
		{

			action = 3;
		}
		else if (StringExtension::Contains(message, "Zatnij rybę 4 razy"))
		{

			action = 4;
		}
		else if (StringExtension::Contains(message, "Zatnij rybę 5 razy"))
		{

			action = 5;
		}
		else
		{
			return;
		}
		MainForm::orbital_log_fishing(0, ("WYMAGANE KLIKNIECIA :" + to_string(action) + "\n").c_str());//
#endif
#ifdef TENELIS
		if (StringExtension::Contains(message, "Kliknij 1 razy"))
		{

			action = 1;
		}
		else if (StringExtension::Contains(message, "Kliknij 2 razy"))
		{

			action = 2;
		}
		else if (StringExtension::Contains(message, "Kliknij 3 razy"))
		{

			action = 3;
		}
		else if (StringExtension::Contains(message, "Kliknij 4 razy"))
		{

			action = 4;
		}
		else if (StringExtension::Contains(message, "Kliknij 5 razy"))
		{

			action = 5;
		}
		else
		{
			return;
		}
		MainForm::orbital_log_fishing(0, ("WYMAGANE KLIKNIECIA :" + to_string(action) + "\n").c_str());//
#endif
#ifdef ZERIOS
		if (StringExtension::Contains(message, "Wylosowano: 1"))
		{

			action = 1;
		}
		else if (StringExtension::Contains(message, "Wylosowano: 2"))
		{

			action = 2;
		}
		else if (StringExtension::Contains(message, "Wylosowano: 3"))
		{

			action = 3;
		}
		else if (StringExtension::Contains(message, "Wylosowano: 4"))
		{

			action = 4;
		}
		else if (StringExtension::Contains(message, "Wylosowano: 5"))
		{

			action = 5;
		}
		else
		{
			return;
		}
		MainForm::orbital_log_fishing(0, ("WYMAGANE KLIKNIECIA :" + to_string(action) + "\n").c_str());//
#endif
#ifdef GLADOROLD
		if (StringExtension::Contains(message, "1"))
		{

			action = 1;
		}
		else if (StringExtension::Contains(message, "2"))
		{

			action = 2;
		}
		else if (StringExtension::Contains(message, "3"))
		{

			action = 3;
		}
		else if (StringExtension::Contains(message, "4"))
		{

			action = 4;
		}
		else if (StringExtension::Contains(message, "5"))
		{

			action = 5;
		}
		else
		{
			return;
		}
		MainForm::orbital_log_fishing(0, ("WYMAGANE KLIKNIECIA :" + to_string(action) + "\n").c_str());//	
#endif
#ifdef CLASSIC
		if (StringExtension::Contains(message, "liczba to... 1"))
		{

			action = 1;
		}
		else if (StringExtension::Contains(message, "liczba to... 2"))
		{

			action = 2;
		}
		else if (StringExtension::Contains(message, "liczba to... 3"))
		{

			action = 3;
		}
		else if (StringExtension::Contains(message, "liczba to... 4"))
		{

			action = 4;
		}
		else if (StringExtension::Contains(message, "liczba to... 5"))
		{

			action = 5;
		}

		else
		{
			return;
		}
		MainForm::orbital_log_fishing(0, ("WYMAGANE KLIKNIECIA :" + to_string(action) + "\n").c_str());//
#endif
#ifdef PANGEA
		if (StringExtension::Contains(message, "piscis_unum.mse"))
		{
			action = 1;
		}
		if (StringExtension::Contains(message, "piscis_duo.mse"))
		{
			action = 2;
		}
		if (StringExtension::Contains(message, "piscis_tribus.mse"))
		{
			action = 3;
		}
		if (StringExtension::Contains(message, "piscis_quattuor.mse"))
		{
			action = 4;
		}
		if (StringExtension::Contains(message, "piscis_quinque.mse"))
		{
			action = 5;
		}

#endif
#if defined(AKADEMIA_VESTERIS) || defined(VESTERIS)
		//VMProtectBeginMutation("VesterisFB");
		if (StringExtension::Contains(message, "użyj animacji: Klaszcz"))
		{

			GameFunctions::NetworkStreamSendChatPacket("/clap", 0);
			MainForm::orbital_log_fishing(0, "Kontrola!\n");//
			Start();
		}
		else if (StringExtension::Contains(message, "użyj animacji: Zgoda"))
		{

			GameFunctions::NetworkStreamSendChatPacket("/congratulation", 0);
			Start();
			MainForm::orbital_log_fishing(0, "Kontrola!\n");//
		}
		else if (StringExtension::Contains(message, "użyj animacji: DenerwowaĆ"))
		{

			GameFunctions::NetworkStreamSendChatPacket("/angry", 0);
			Start();
			MainForm::orbital_log_fishing(0, "Kontrola!\n");//
		}
		else if (StringExtension::Contains(message, "użyj animacji: WybaczyĆ"))
		{

			GameFunctions::NetworkStreamSendChatPacket("/forgive", 0);
			Start();
			MainForm::orbital_log_fishing(0, "Kontrola!\n");//
		}
		else if (StringExtension::Contains(message, "użyj animacji: Smutek"))
		{

			GameFunctions::NetworkStreamSendChatPacket("/sad", 0);
			Start();
			MainForm::orbital_log_fishing(0, "Kontrola!\n");//
		}



		else if (StringExtension::Contains(message, "użyj animacji: Odmowa"))
		{

			GameFunctions::NetworkStreamSendChatPacket("/shy", 0);
			Start();
			MainForm::orbital_log_fishing(0, "Kontrola!\n");//
		}
		else if (StringExtension::Contains(message, "użyj animacji: RozweselaĆ"))
		{

			GameFunctions::NetworkStreamSendChatPacket("/cheerup", 0);
			Start();
			MainForm::orbital_log_fishing(0, "Kontrola!\n");//
		}
		else if (StringExtension::Contains(message, "użyj animacji: DrwiĆ"))
		{

			GameFunctions::NetworkStreamSendChatPacket("/banter", 0);
			Start();
			MainForm::orbital_log_fishing(0, "Kontrola!\n");//
		}
		else if (StringExtension::Contains(message, "użyj animacji: RadoŚĆ"))
		{

			GameFunctions::NetworkStreamSendChatPacket("/joy", 0);
			Start();
			MainForm::orbital_log_fishing(0, "Kontrola!\n");//
		}
		else if (StringExtension::Contains(message, "użyj animacji: Powitanie 1"))
		{

			GameFunctions::NetworkStreamSendChatPacket("/cheer1", 0);
			Start();
			MainForm::orbital_log_fishing(0, "Kontrola!\n");//
		}
		if (StringExtension::Contains(message, "użyj spacji 1"))
		{

			action = 1;
		}
		else if (StringExtension::Contains(message, "użyj spacji 2"))
		{

			action = 2;
		}
		else if (StringExtension::Contains(message, "użyj spacji 3"))
		{

			action = 3;
		}
		else if (StringExtension::Contains(message, "użyj spacji 4"))
		{

			action = 4;
		}
		else if (StringExtension::Contains(message, "użyj spacji 5"))
		{

			action = 5;
		}
		else
		{
			return;
		}	//VMProtectEnd();
		MainForm::orbital_log_fishing(0, ("Wymagane Klikniecia :" + to_string(action) + "\n").c_str());//
#endif
#ifdef EGORIA
		if (StringExtension::Contains(message, "Aby wyciągnąć Rybę wciśnij: J"))
		{
			action = 1;


		}
		else if (StringExtension::Contains(message, "Aby wyciągnąć Rybę wciśnij: D"))
		{
			action = 2;


		}
		else if (StringExtension::Contains(message, "Aby wyciągnąć Rybę wciśnij: T"))
		{
			action = 3;


		}
		else if (StringExtension::Contains(message, "Aby wyciągnąć Rybę wciśnij: C"))
		{
			action = 4;


		}
		else if (StringExtension::Contains(message, "Aby wyciągnąć Rybę wciśnij: P"))
		{
			action = 5;


		}
		else if (StringExtension::Contains(message, "Aby wyciągnąć Rybę wciśnij: 1"))
		{
			action = 1;


		}
		else if (StringExtension::Contains(message, "Aby wyciągnąć Rybę wciśnij: 2"))
		{
			action = 2;


		}
		else if (StringExtension::Contains(message, "Aby wyciągnąć Rybę wciśnij: 3"))
		{
			action = 3;


		}
		else if (StringExtension::Contains(message, "Aby wyciągnąć Rybę wciśnij: 4"))
		{
			action = 4;


		}
		else if (StringExtension::Contains(message, "Aby wyciągnąć Rybę wciśnij: 5"))
		{
			action = 5;


		}
		if (action > 0)
		{
			MainForm::orbital_log_fishing(0, ("Wymagane Klikniecia :" + to_string(action) + "\n").c_str());//
		}
#endif	
#ifdef MATADIA
		if (StringExtension::Contains(message, "Kliknij 1 razy"))
		{
			action = 1;


		}
		else if (StringExtension::Contains(message, "Kliknij 2 razy"))
		{
			action = 2;


		}
		else if (StringExtension::Contains(message, "Kliknij 3 razy"))
		{
			action = 3;


		}
		else if (StringExtension::Contains(message, "Kliknij 4 razy"))
		{
			action = 4;


		}
		else if (StringExtension::Contains(message, "Kliknij 5 razy"))
		{
			action = 5;


		}
		if (action > 0)
		{
			MainForm::orbital_log_fishing(0, ("Wymagane Klikniecia :" + to_string(action) + "\n").c_str());//
		}

#endif	
	}


};

