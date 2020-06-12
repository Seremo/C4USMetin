#pragma once
class Status :public IAbstractModuleBase, public Singleton<Status>
{
	 DWORD lastTimeCheckStatus = 0;
	
	 string stringPlayerName ="";
	 string stringPlayerID = "";
	 string stringPlayerPositionX = "";
	 string stringPlayerPositionY = "";
	 string stringTargetIndex = "";
	 string stringTargetDistance = "";
	 string stringTargetType = "";
	 string stringTargetName = "";
	 string stringPlayersCount = "";
	 string stringNpcCount = "";
	 string stringMetinCount = "";
public:
	void OnStart()
	{

	}

	void OnStop()
	{
	}

	void OnRender()
	{
	}

	void OnMenu()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("StatusBorder", ImVec2(645, 430), true);
		ImGui::Checkbox("Status Enable", &Settings::StatusEnable); 
		
		ImGui::Text("Nazwa Postaci:");
		ImGui::SameLine();
		ImGui::Text(stringPlayerName.c_str());
		ImGui::Text("Pozycja XY:"); 
		ImGui::SameLine();
		ImGui::Text(stringPlayerPositionX.c_str());
		ImGui::SameLine();
		ImGui::Text("/"); 
		ImGui::SameLine();
		ImGui::Text(stringPlayerPositionY.c_str());
		ImGui::Text("ID Postaci:"); 
		ImGui::SameLine();
		ImGui::Text(stringPlayerID.c_str());
		ImGui::Text("ID Celu:"); 
		ImGui::SameLine();
		ImGui::Text(stringTargetIndex.c_str());
		ImGui::Text("Dystans Celu:");
		ImGui::SameLine();
		ImGui::Text(stringTargetDistance.c_str());
		ImGui::Text("Typ Celu:"); 
		ImGui::SameLine();
		ImGui::Text(stringTargetType.c_str());
		ImGui::Text("Nazwa Celu:"); 
		ImGui::SameLine();
		ImGui::Text(stringTargetName.c_str());
		ImGui::Text("Gracze w zasiegu:");
		ImGui::SameLine();
		ImGui::Text(stringPlayersCount.c_str());
		ImGui::Text("NPC w zasiegu:");
		ImGui::SameLine();
		ImGui::Text(stringNpcCount.c_str());
		ImGui::Text("Metiny w zasiegu:");
		ImGui::SameLine();
		ImGui::Text(stringMetinCount.c_str());

		ImGui::EndChild();
		ImGui::PopStyleVar();
	}

	void OnUpdate()
	{


		if (Settings::StatusEnable)
		{

			if (!GameFunctionsCustom::PlayerIsInstance() || (GetTickCount() - lastTimeCheckStatus) < 1000)
			{
				return;
			}
			else
			{
				lastTimeCheckStatus = GetTickCount();
			}
			const char* playerName = GameFunctionsCustom::PlayerGetName();
			int playerIndex = GameFunctions::PlayerGetMainCharacterIndex();
			int targetIndex = GameFunctions::PlayerGetTargetVID();
			int targetType = GameFunctionsCustom::GetTypeByVid(targetIndex);
			const char* targetName = GameFunctionsCustom::InstanceGetNameByVID(targetIndex);
			float distance = GameFunctionsCustom::PlayerGetCharacterDistance(targetIndex);
			int hpPercent = GameFunctionsCustom::GetHpProcentageStatus();
			int mpPercent = GameFunctionsCustom::GetMpProcentageStatus();


			int NPCViewportCount = GameFunctionsCustom::GetObjectListCount(OBJECT_NPC);
			int PlayersViewportCount = GameFunctionsCustom::GetObjectListCount(OBJECT_PC);
			int StonesViewportCount = GameFunctionsCustom::GetObjectListCount(OBJECT_STONE);




			D3DVECTOR playerPosition = GameFunctionsCustom::PlayerGetPixelPosition();

			int playerIsAlive = !GameFunctionsCustom::PlayerIsDead();
			int playerIsMouting = GameFunctionsCustom::PlayerIsMountingHorse();
			if (playerName != NULL)
			{
				stringPlayerName = string(playerName);
			}
			else
			{
				stringPlayerName = "-/-";
			}
			if (playerPosition.x != 0 && playerPosition.y != 0)
			{
				stringPlayerPositionX = to_string(playerPosition.x);
				stringPlayerPositionY = to_string(playerPosition.y);
			}
			else
			{
				stringPlayerPositionX = "-";
				stringPlayerPositionY = "-";
			}

			if (targetIndex != 0)
			{
				stringTargetIndex = to_string(targetIndex);
			}
			else
			{
				stringTargetIndex = "-/-";
			}

			if (playerIndex != 0)
			{
				stringPlayerID = to_string(playerIndex);
			}
			else
			{
				stringPlayerID = "-/-";
			}

			if (distance != -1)
			{
				stringTargetDistance = to_string(distance);
			}
			else
			{
				stringTargetDistance = "-/-";
			}

			if (targetType == -1)
			{
				stringTargetType = "-/-";
			}
			else if (targetType == 0)
			{
				stringTargetType = "MOB";
			}
			else if (targetType == 1)
			{
				stringTargetType = "NPC";
			}
			else if (targetType == 2)
			{
				stringTargetType = "METIN";
			}
			else if (targetType == 6)
			{
				stringTargetType = "GRACZ";
			}
			else
			{
				stringTargetType = to_string(targetType);
			}


			if (targetName != NULL)
			{
				stringTargetName = targetName;
			}
			else
			{
				stringTargetName = "-/-";
			}
			if (hpPercent != 0)
			{

			}
			if (mpPercent != 0)
			{

			}
			if (NPCViewportCount > 0)
			{
				stringNpcCount = to_string(NPCViewportCount);
			}
			else
			{
				stringNpcCount = "-/-";
			}
			if (PlayersViewportCount > 0)
			{
				stringPlayersCount = to_string(PlayersViewportCount);
			}
			else
			{
				stringPlayersCount = "-/-";
			}
			if (StonesViewportCount > 0)
			{
				stringMetinCount = to_string(StonesViewportCount);
			}
			else
			{
				stringMetinCount = "-/-";
			}
			if (playerIsAlive != -1)
			{

			}
			if (playerIsMouting != -1)
			{

			}

			

		}

	}

};


