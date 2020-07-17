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
		Logger::Draw(Logger::MAIN);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("ProtectionBorder", ImVec2(655, 310), true);;
		ImGui::Checkbox("ON/OFF Render Scene", &Settings::ProtectionDisableRender);
		ImGui::Checkbox("ON/OFF Update Scene", &Settings::ProtectionDisableUpdate);
		ImGui::Checkbox("Whisper Logs", &Settings::ProtectionShowWisperLogs);
		ImGui::Checkbox("Whisper Balloon", &Settings::ProtectionShowWisperBalloon);
		ImGui::Checkbox("Whisper Beep", &Settings::ProtectionPlayWisperBeep);
		ImGui::Checkbox("Whisper Restore Window", &Settings::ProtectionRestoreWisperWindow);
		ImGui::Checkbox("Whisper Window Flash", &Settings::ProtectionFlashWisperIcon);


		ImGui::Checkbox("Normal Logs", &Settings::ProtectionShowTalkLogs);
		ImGui::Checkbox("Normal Balloon", &Settings::ProtectionShowTalkBalloon);
		ImGui::Checkbox("Normal Beep", &Settings::ProtectionPlayTalkBeep);
		ImGui::Checkbox("Normal Window Flash", &Settings::ProtectionFlashTalkIcon);
		
		ImGui::EndChild();
		ImGui::PopStyleVar();
	}

	void OnRender()
	{
	}

	void OnUpdate()
	{
#ifdef METINPL
		if ( Settings::ProtectionAutoLogin && DynamicTimer::CheckAutoSet("AutoLogin", 5000) )
		{
			if (GameFunctionsCustom::PlayerDirectEnter())
			{
#else
		if (DynamicTimer::CheckAutoSet("AutoLogin", 3000) && Settings::ProtectionAutoLogin)
		{
			if(GameFunctionsCustom::PlayerDirectEnter())
			{
			
#endif
				Main::Instance().ResetSkillTimer();
				
			}
		}


	}


};