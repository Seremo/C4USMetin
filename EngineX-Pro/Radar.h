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
		ImGui::ColorEdit3("##Monsters", (float*)&Settings::monster_color, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Monsters", &Settings::monster_show);
		ImGui::ColorEdit3("##Bosses", (float*)&Settings::boss_color, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Boss", &Settings::boss_show);
		ImGui::ColorEdit3("##NPC", (float*)&Settings::npc_color, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Npc", &Settings::npc_show);
		ImGui::ColorEdit3("##ZYLY", (float*)&Settings::mining_color, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Veins", &Settings::mining_show);
		ImGui::ColorEdit3("##METIN", (float*)&Settings::metin_color, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Metin", &Settings::metin_show);
		ImGui::ColorEdit3("##Players", (float*)&Settings::pc_color, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Players", &Settings::pc_show);
		ImGui::ColorEdit3("##Waypoints", (float*)&Settings::waypoint_color, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs); ImGui::SameLine();
		ImGui::Checkbox("Waypoints", &Settings::waypoint_show);

		ImGui::EndChild();
		ImGui::PopStyleVar();
	}
};