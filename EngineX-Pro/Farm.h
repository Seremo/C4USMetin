#pragma once
class Farm :public IAbstractModuleBase, public Singleton<Farm>
{
public:
	int LastTeleport = 0;
	int LastTeleportTemp = 0;
	DWORD targetVID = 0;
	int MoveStep;
	vector<D3DVECTOR> cordsMaps;
	int BoostCount = 0;
	

	void TeleportToDestination(D3DVECTOR pos) {
		int Count = 0;
		int Crap = 0;
		D3DVECTOR TempPos = GameFunctionsCustom::GetTempPosition(pos, Count);
		for (int TmpCount = 0; TmpCount < Count; TmpCount++) 
		{
			TempPos = GameFunctionsCustom::GetTempPosition(pos, Crap);
			DelayActions::AppendBlock(false, 34 * (TmpCount + 1), &GameFunctionsCustom::Teleport, TempPos);
		}
	}

	

	

	void CheckClosestCoord()
	{
		int index = 0;
		int ClosestIndex = 0;
		D3DVECTOR mainPosition;
		GameFunctions::InstanceBaseNEW_GetPixelPosition(GameFunctions::PlayerNEW_GetMainActorPtr(), &mainPosition);
		DWORD LowestDistance = MiscExtension::CountDistanceTwoPoints(mainPosition.x, mainPosition.y, cordsMaps.begin()->x, cordsMaps.begin()->y);
		for (auto itor = cordsMaps.begin(); itor != cordsMaps.end(); itor++) {

			float Distance = MiscExtension::CountDistanceTwoPoints(mainPosition.x, mainPosition.y, itor->x, itor->y);
			if (Distance < LowestDistance) {
				ClosestIndex = index;
			}
			index++;
		}
		MoveStep = ClosestIndex;
	}

	void OnStart()
	{
		if (cordsMaps.size() <= 0)
		{
			cordsMaps.push_back(GameFunctionsCustom::PlayerGetPixelPosition());
		}
		CheckClosestCoord();
	}

	void OnStop()
	{
		D3DVECTOR mainPosition;
		GameFunctions::InstanceBaseNEW_GetPixelPosition(GameFunctions::PlayerNEW_GetMainActorPtr(), &mainPosition);
		GameFunctionsCustom::PlayerMoveToDestPixelPositionDirection(mainPosition);
	}

	void OnUpdate()
	{
		if (Settings::GLOBAL_SWITCH && Settings::LevelBotEnable && GameFunctionsCustom::PlayerIsInstance())
		{
			if (GameFunctions::InstanceBaseIsDead(GameFunctions::PlayerNEW_GetMainActorPtr()))
			{
				return;
			}
				
			int CordsLength = cordsMaps.size();
			if (CordsLength > 0)
			{
				map<DWORD, DWORD*> mobList;
				map<DWORD, DWORD*> stoneList;
				map<DWORD, DWORD*> bossList;
				if (Settings::LevelBotMob)
				{
					mobList = GameFunctionsCustom::GetObjectList(OBJECT_MOB , Settings::LevelBotDistance);
				}
				if (Settings::LevelBotBoss)
				{
					bossList = GameFunctionsCustom::GetObjectList( OBJECT_BOSS, Settings::LevelBotDistance);
				}
				if (Settings::LevelBotMetin)
				{
					stoneList	 = GameFunctionsCustom::GetObjectList(OBJECT_STONE , Settings::LevelBotDistance);
				}
					
					
					


				

				
				D3DVECTOR playerPosition = GameFunctionsCustom::PlayerGetPixelPosition();
				if (mobList.size()|| stoneList.size()|| bossList.size())
				{
				
					if (!mobList.count(targetVID) && !stoneList.count(targetVID) && !bossList.count(targetVID))
					{
						targetVID = 0;
						if (!targetVID)
						{
							for (map<DWORD, DWORD*>::iterator itor = mobList.begin(); itor != mobList.end(); itor++)
							{
								targetVID = itor->first;
							}
						}
						if (!targetVID)
						{
							for (map<DWORD, DWORD*>::iterator itor = stoneList.begin(); itor != stoneList.end(); itor++)
							{
								targetVID = itor->first;
							}
						}
						if (!targetVID)
						{
							for (map<DWORD, DWORD*>::iterator itor = bossList.begin(); itor != bossList.end(); itor++)
							{
								targetVID = itor->first;
							}
						}
						
						
					}
					if (targetVID && DynamicTimer::Check("FarmOnPressActor", 1000))
					{
						GameFunctions::Player__OnPressActor(GameFunctions::PlayerNEW_GetMainActorPtr(), targetVID, true);
					}
				}
				else
				{
					bool isINDistance = MathExtension::PointInCircle(playerPosition, cordsMaps[MoveStep], 300);
					if (isINDistance)
					{
						MoveStep ++;
					}

					if (MoveStep == CordsLength)
					{
						reverse(cordsMaps.begin(), cordsMaps.end());
						MoveStep = 0;
					}
					if (CordsLength >= 2 && !isINDistance)
					{
						if (Settings::LevelBotMoveType == 1)
						{
							TeleportToDestination(cordsMaps[MoveStep]);
						}
						else 
						{
							GameFunctionsCustom::PlayerMoveToDestPixelPositionDirection(cordsMaps[MoveStep]);
						}
					}
				}
			}
			else 
			{
				cordsMaps.push_back(GameFunctionsCustom::PlayerGetPixelPosition());
			}
		}
	}

	void OnRender()
	{
	}

	void OnMenu()
	{
		
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("FarmBotBorder", ImVec2(655, 160), true);
		if (ImGui::Checkbox("Farm Enable", &Settings::LevelBotEnable)) {
			if (Settings::LevelBotEnable == true)
			{
				OnStart();
			}
			else
			{
				OnStop();
			}
		}
		ImGui::Text("Move Type      "); ImGui::SameLine();
		ImGui::RadioButton("Move", &Settings::LevelBotMoveType, 0); ImGui::SameLine();
		ImGui::RadioButton("Teleport", &Settings::LevelBotMoveType, 1);
		/*ImGui::RadioButton("Normal", &Settings::LevelBotAttackType, 0); ImGui::SameLine();
		ImGui::RadioButton("WaitHack", &Settings::LevelBotAttackType, 1);*/
		ImGui::PushItemWidth(200); ImGui::InputInt("Distance", &Settings::LevelBotDistance, 100, 1000);
		ImGui::Checkbox("Mob", &Settings::LevelBotMob); ImGui::SameLine();
		ImGui::Checkbox("Boss", &Settings::LevelBotBoss); ImGui::SameLine();
		ImGui::Checkbox("Metin", &Settings::LevelBotMetin);
		ImGui::EndChild();
		ImGui::PopStyleVar();
		if (Settings::LevelBotAttackType == 1) 
		{
			ImGui::SameLine();
			ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
			ImGui::SetNextWindowBgAlpha(0.75f);
			ImGui::BeginChild("WHBorder", ImVec2(200, 210), true);
			ImGui::Checkbox("WH", &Settings::MiniMHWaitHackEnable); ImGui::SameLine();
			ImGui::Checkbox("Teleport", &Settings::MiniMHWaitHackSwordRange);
			ImGui::RadioButton("Standard", &Settings::MiniMHWaitHackOneTarget, 0); ImGui::SameLine();
			ImGui::RadioButton("Target", &Settings::MiniMHWaitHackOneTarget, 1);
			ImGui::InputInt("Time", &Settings::MiniMHWaitHackTime, 5, 100);
			ImGui::InputInt("Range", &Settings::MiniMHWaitHackDistanceValue, 100, 1000);
			ImGui::RadioButton("Sword", &Settings::MiniMHWaitHackType, 0); ImGui::SameLine();
			ImGui::RadioButton("Bow", &Settings::MiniMHWaitHackType, 1);
			ImGui::Checkbox("Detect Player", &Settings::MiniMHWaitHackDetect);
#ifdef DEVELOPER_MODE
			ImGui::RadioButton("Skill", &Settings::MiniMHWaitHackType, 2);
			ImGui::InputInt("SkillNumber", &Settings::MiniMHSkillNumber, 1, 111);
			ImGui::InputInt("##STime", &Settings::MiniMHWaitHackSkillDelay, 1, 10);
#endif	
			ImGui::EndChild();
			ImGui::PopStyleVar();
		}
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("CordsBorder", ImVec2(655, 210), true);
		if (ImGui::Button("Add Position")) 
		{
			cordsMaps.push_back(GameFunctionsCustom::PlayerGetPixelPosition());
		}
		ImGui::SameLine();
		if (ImGui::Button("Delete All Position")) 
		{
			cordsMaps.clear();
		}
		ImGui::Separator();
		if (cordsMaps.size() > 0)
		{
			for (auto item : cordsMaps)
			{
				bool is_selected = true;
				std::string& item_name = "[X:" + to_string(item.x) + "],[Y:" + to_string(item.y) + "]";
				if (ImGui::Selectable(item_name.c_str(), is_selected))
				{
				}
			}
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
	}

	
};
