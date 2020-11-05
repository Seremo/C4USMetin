#pragma once
class Protection :public IAbstractModuleBase, public Singleton<Protection>
{
private:
	
	string lastPlayerName="";
	bool isShowLogs = false;
public:
	void OnStart()
	{

	}
	void OnStop()
	{

	}
	void OnMenu()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("ProtectionBorder", ImVec2(655, 310), true);;
		ImGui::Checkbox("ON/OFF Render Scene", &Settings::PROTECTION_DISABLE_RENDER_ENABLE);
		ImGui::Checkbox("ON/OFF Update Scene", &Settings::PROTECTION_DISABLE_UPDATE_ENABLE);
		ImGui::Checkbox("Whisper Logs", &Settings::PROTECTION_SHOW_WHISPER_LOGS_ENABLE);
		ImGui::Checkbox("Whisper Balloon", &Settings::PROTECTION_SHOW_WHISPER_BALLOON_ENABLE);
		ImGui::Checkbox("Whisper Beep", &Settings::PROTECTION_PLAY_WHISPER_BEEP_ENABLE);
		ImGui::Checkbox("Whisper Restore Window", &Settings::PROTECTION_RESTORE_WISPER_WINDOW_ENABLE);
		ImGui::Checkbox("Whisper Window Flash", &Settings::PROTECTION_FLASH_WHISPER_ICON_ENABLE);


		ImGui::Checkbox("Normal Logs", &Settings::PROTECTION_SHOW_TALK_LOGS_ENABLE);
		ImGui::Checkbox("Normal Balloon", &Settings::PROTECTION_SHOW_TALK_BALLOON_ENABLE);
		ImGui::Checkbox("Normal Beep", &Settings::PROTECTION_PLAY_TALK_BEEP_ENABLE);
		ImGui::Checkbox("Normal Window Flash", &Settings::PROTECTION_FLASH_TALK_ICON_ENABLE);
		
		ImGui::EndChild();
		ImGui::PopStyleVar();
	}

	void OnRender()
	{
	}

	void OnUpdate()
	{
		if (Globals::Server == ServerName::METINPL)
		{
			if (Settings::PROTECTION_AUTO_LOGIN_ENABLE && DynamicTimer::CheckAutoSet("AutoLogin", 7000))
			{
				if (GameFunctionsCustom::PlayerDirectEnter())
				{
					Main::Instance().ResetSkillTimer();
				}
			}
		}
		else 
		{
			if (DynamicTimer::CheckAutoSet("AutoLogin", 3000) && Settings::PROTECTION_AUTO_LOGIN_ENABLE)
			{
				if (GameFunctionsCustom::PlayerDirectEnter())
				{
					Main::Instance().ResetSkillTimer();
				}
			}
		}
	}
};