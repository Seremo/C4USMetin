#pragma once
class Configuration :public IAbstractModuleBase, public Singleton<Configuration>
{
private:
	/*vector<string> configs;*/
	int configSelected  = 0;
	string newFileName;
	int currentIndex = 0;

public:

	string str0 ="";
	void OnStart()
	{
		vector<string> configs = FileExtension::GetDirectoryFiles(FileExtension::GetAppDataDirectory() + "\\EngineX\\", "mc"   /*format "exe"*/);
		for (auto const& value : configs)
		{
			if (value == "Default")
			{
				Settings::Load("Default", FileExtension::GetAppDataDirectory() + "\\EngineX\\");
				return;
			}
		}
		Settings::Save("Default", FileExtension::GetAppDataDirectory() + "\\EngineX\\");
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
		ImGui::BeginChild("ConfBorder", ImVec2(645, 250), true);
		vector<string> configs = FileExtension::GetDirectoryFiles(FileExtension::GetAppDataDirectory() + "\\EngineX\\", "mc"   /*format "exe"*/);
		ImGui::PushItemWidth(200);
		if (ImGui::ListBox("Configs", &currentIndex, configs))
		{
			newFileName = configs[currentIndex];
		}
		ImGui::InputText("##FileName", &newFileName);
		if (ImGui::Button("Load Settings"))
		{
			Settings::Load(newFileName,FileExtension::GetAppDataDirectory()+"\\EngineX\\");
		}
		ImGui::SameLine();
		if (ImGui::Button("Save Settings"))
		{		
			Settings::Save(newFileName,FileExtension::GetAppDataDirectory() + "\\EngineX\\" );
		}
		ImGui::SameLine();
		if (ImGui::Button("Remove Settings"))
		{
			if (newFileName != "Default")
			{
				Settings::Remove(newFileName, FileExtension::GetAppDataDirectory() + "\\EngineX\\");
			}
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
	}

};
