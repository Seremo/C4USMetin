#pragma once
class Radar :public IAbstractModuleBase, public Singleton<Radar>
{
private:
public:
	virtual void OnStart()
	{

	}

	virtual void OnStop()
	{
	}

	virtual void OnUpdate()
	{

	}

	virtual void OnRender()
	{

	}

	virtual void OnMenu()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("RadarBorder", ImVec2(645, 250), true);
		ImGui::ColorEdit3("##Monsters", (float*)&Settings::RADAR_MONSTER_COLOR, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Monsters", &Settings::RADAR_MONSTER_SHOW_ENABLE);
		ImGui::ColorEdit3("##Bosses", (float*)&Settings::RADAR_BOSS_COLOR, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Boss", &Settings::RADAR_BOSS_SHOW_ENABLE);
		ImGui::ColorEdit3("##NPC", (float*)&Settings::RADAR_NPC_COLOR, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Npc", &Settings::RADAR_NPC_SHOW_ENABLE);
		ImGui::ColorEdit3("##ZYLY", (float*)&Settings::RADAR_MINE_COLOR, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Veins", &Settings::RADAR_MINING_SHOW_ENABLE);
		ImGui::ColorEdit3("##METIN", (float*)&Settings::RADAR_STONE_COLOR, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Metin", &Settings::RADAR_STONE_SHOW_ENABLE);
		ImGui::ColorEdit3("##Players", (float*)&Settings::RADAR_PLAYER_COLOR, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Players", &Settings::RADAR_PLAYER_SHOW_ENABLE);
		ImGui::ColorEdit3("##Waypoints", (float*)&Settings::RADAR_WAYPOINT_COLOR, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Waypoints", &Settings::RADAR_WAYPOINT_SHOW_ENABLE);

		ImGui::EndChild();
		ImGui::PopStyleVar();
	}
};