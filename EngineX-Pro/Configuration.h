#pragma once
class Configuration :public IAbstractModuleBase, public Singleton<Configuration>
{
private:
public:

	string str0 ="";
	void OnStart()
	{

	}

	void OnStop()
	{
	}

	void OnUpdate()
	{

	}

	void OnRender()
	{
	}

	void OnMenu()
	{

		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("RadarBorder", ImVec2(645, 250), true);
	/*	ImGui::Text("Key Bind");
		ImGui::Separator();
		ImGui::Hotkey(Settings::HotkeyTime, "Boost", &Settings::BoostKey);
		ImGui::Hotkey(Settings::HotkeyTime, "Relog", &Settings::RelogKey);
		ImGui::InputInt("Boost Distance", &Settings::BoostSpeed3, 5, 100);*/
		
		/*ImGui::Columns(2, "config", false);
		ImGui::NextColumn();
		ImGui::Text("Nazwa");
		ImGui::InputTextWithHint("##namecfg", "Create Or Replace.", &str0[0], 128);}*/
		if (ImGui::Button("Load Settings"))
		{
			/*Settings::Load(str0.c_str());*/
		}
		/*ImGui::SameLine();*/
		if (ImGui::Button("Save Settings"))
		{
			/*Settings::Save(str0.c_str());*/
		}
	/*	ImGui::SameLine();
		if (ImGui::Button("Delete"))
		{
		}*/
		


		ImGui::EndChild();
		ImGui::PopStyleVar();
	}

};
