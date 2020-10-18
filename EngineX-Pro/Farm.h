#pragma once
class Farm :public IAbstractModuleBase, public Singleton<Farm>
{
public:
	int LastTeleport = 0;
	int LastTeleportTemp = 0;
	DWORD targetVID = 0;
	DWORD * targetInstance = NULL;
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
		for (vector<D3DVECTOR>::iterator itor = cordsMaps.begin(); itor != cordsMaps.end(); itor++)
		{

			float Distance = MiscExtension::CountDistanceTwoPoints(mainPosition.x, mainPosition.y, itor->x, itor->y);
			if (Distance < LowestDistance) 
			{
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
		if (Settings::GLOBAL_SWITCH && Settings::FARM_ENABLE && GameFunctionsCustom::PlayerIsInstance())
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
				map<DWORD, DWORD*> mineList;
				if (Settings::FARM_MOB_ENABLE)
				{
					mobList = GameFunctionsCustom::GetObjectList(OBJECT_MOB , Settings::FARM_DISTANCE);
				}
				if (Settings::FARM_BOSS_ENABLE)
				{
					bossList = GameFunctionsCustom::GetObjectList( OBJECT_BOSS, Settings::FARM_DISTANCE);
				}
				if (Settings::FARM_METIN_ENABLE)
				{
					stoneList	 = GameFunctionsCustom::GetObjectList(OBJECT_STONE , Settings::FARM_DISTANCE);
				}
				if (Settings::FARM_MINE_ENABLE)
				{
					mineList = GameFunctionsCustom::GetObjectList(OBJECT_MINE, Settings::FARM_DISTANCE);
				}
					


				

				
				D3DVECTOR playerPosition = GameFunctionsCustom::PlayerGetPixelPosition();
				if (targetInstance== NULL)
				{
					targetVID = 0;
					/*targetInstance = NULL;*/
				}
				if (targetVID &&( GameFunctions::InstanceBaseIsDead(targetInstance) || !GameFunctionsCustom::IsMapHaveInstance(targetInstance)))
				{
					targetVID = 0;
					targetInstance = NULL;
					DynamicTimer::CheckAutoSet("DropDelay", Settings::FARM_DROP_WAIT_DELAY);
				}
				if (DynamicTimer::IsActive("DropDelay", Settings::FARM_DROP_WAIT_DELAY))
				{
					return;
				}
				
				if (mobList.size()|| stoneList.size()|| bossList.size() || mineList.size())
				{
				
					if (!mobList.count(targetVID) && !stoneList.count(targetVID) && !bossList.count(targetVID))
					{
						/*targetVID = 0;*/
						if (!targetVID)
						{
							for (map<DWORD, DWORD*>::iterator itor = mobList.begin(); itor != mobList.end(); itor++)
							{
								targetVID = itor->first;
								targetInstance = itor->second;
							}
						}
						if (!targetVID)
						{
							for (map<DWORD, DWORD*>::iterator itor = stoneList.begin(); itor != stoneList.end(); itor++)
							{
								targetVID = itor->first;
								targetInstance = itor->second;
							}
						}
						if (!targetVID)
						{
							for (map<DWORD, DWORD*>::iterator itor = bossList.begin(); itor != bossList.end(); itor++)
							{
								targetVID = itor->first;
								targetInstance = itor->second;
							}
						}
						if (!targetVID)
						{
							for (map<DWORD, DWORD*>::iterator itor = mineList.begin(); itor != mineList.end(); itor++)
							{
								targetVID = itor->first;
								targetInstance = itor->second;
							}
						}
						
					}
					if (targetVID && DynamicTimer::CheckAutoSet("FarmOnPressActor", 1500))
					{
						if (GameFunctionsCustom::InstanceIsResource(targetVID) && GameFunctions::InstanceIsWaiting(GameFunctions::PlayerNEW_GetMainActorPtr()))
						{
							GameFunctions::Player__OnClickActor(GameFunctions::PlayerNEW_GetMainActorPtr(), targetVID, true);
						}
						else
						{
							GameFunctions::Player__OnPressActor(GameFunctions::PlayerNEW_GetMainActorPtr(), targetVID, true);
						}

						
					}
				}
				else
				{
					bool isInCircle = MathExtension::PointInCircle(playerPosition, cordsMaps[MoveStep], 300);
					if (isInCircle)
					{
						MoveStep ++;
					}

					if (MoveStep == CordsLength)
					{
						reverse(cordsMaps.begin(), cordsMaps.end());
						MoveStep = 0;
					}
					if (CordsLength >= 2 && !isInCircle)
					{
						if (Settings::FARM_MOVE_TYPE == 1)
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
		for (auto itor = Farm::Instance().cordsMaps.begin(); itor != Farm::Instance().cordsMaps.end(); itor++)
		{
			auto ItorNext = itor;
			ItorNext++;
			if (ItorNext == Farm::Instance().cordsMaps.end())
				break;

			vector< D3DVECTOR> gf = MiscExtension::DivideTwoPointsByDistance(100, *itor, *ItorNext);
			int i = 0;
			for (vector< D3DVECTOR>::iterator it = gf.begin(); it != gf.end(); ++it)
			{
				auto itNext = it;
				itNext++;
				if (itNext == gf.end())
					break;
				float z1 = GameFunctions::GetBackgroundHeight(it->x, it->y) + 5.0f;
				float z2 = GameFunctions::GetBackgroundHeight(itNext->x, itNext->y) + 5.0f;
				D3DVECTOR LinePos1 = { it->x, -it->y, z1 };
				D3DVECTOR LinePos2 = { itNext->x, -itNext->y, z2 };
				CRender::Line3D(LinePos1.x, LinePos1.y, LinePos1.z, LinePos2.x, LinePos2.y, LinePos2.z, Settings::waypoint_color);
				//CRender::RenderBox(Device::ms_lpCylinderMesh, LinePos1.x, LinePos1.y, LinePos1.z, 10.0f, D3DFILL_SOLID, D3DCOLOR_RGBA(255, 0, 0, 50));
				//CRender::RenderBox(Device::ms_lpCylinderMesh, LinePos2.x, LinePos2.y, LinePos2.z, 10.0f, D3DFILL_SOLID, D3DCOLOR_RGBA(0, 255, 0, 50));
				i++;
			}
		}
	}

	void OnMenu()
	{
		
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("FarmBotBorder", ImVec2(655, 160), true);
		if (ImGui::Checkbox("Farm Enable", &Settings::FARM_ENABLE)) 
		{
			if (Settings::FARM_ENABLE == true)
			{
				OnStart();
			}
			else
			{
				OnStop();
			}
		} ImGui::SameLine();
		ImGui::ColorEdit4("##RendeFarm", (float*)&Settings::waypoint_color, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Render Path", &Settings::renderfarmbot);
		ImGui::Text("Move Type      "); ImGui::SameLine();
		ImGui::RadioButton("Move", &Settings::FARM_MOVE_TYPE, 0); ImGui::SameLine();
		ImGui::RadioButton("Teleport", &Settings::FARM_MOVE_TYPE, 1);
		/*ImGui::RadioButton("Normal", &Settings::LevelBotAttackType, 0); ImGui::SameLine();
		ImGui::RadioButton("WaitHack", &Settings::LevelBotAttackType, 1);*/
		ImGui::PushItemWidth(200); ImGui::InputInt("Distance", &Settings::FARM_DISTANCE, 100, 1000);
		ImGui::Checkbox("Mob", &Settings::FARM_MOB_ENABLE); ImGui::SameLine();
		ImGui::Checkbox("Boss", &Settings::FARM_BOSS_ENABLE); ImGui::SameLine();
		ImGui::Checkbox("Metin", &Settings::FARM_METIN_ENABLE); ImGui::SameLine();

		ImGui::Checkbox("Mine", &Settings::FARM_MINE_ENABLE); /*ImGui::SameLine();*/

		ImGui::InputFloatMinMax("Drop Wait Delay (s)", &Settings::FARM_DROP_WAIT_DELAY, 0, 100, 0.100, 1);
		
		/*ImGui::Checkbox("Plant", &Settings::FARM_PLANT_ENABLE);*/
		ImGui::EndChild();
		ImGui::PopStyleVar();
		
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
				std::string& item_name = "[ X:" + to_string((DWORD)(item.x /100)) + "],[ Y:" + to_string((DWORD)(item.y / 100)) + "]";
				if (ImGui::Selectable(item_name.c_str(), is_selected))
				{

				}
			}
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
	}

	
};
