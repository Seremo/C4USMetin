#pragma once
class Protection :public IAbstractModuleBase, public Singleton<Protection>
{
private:
	DWORD lastTimeAutoLogin =0;
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
		MainForm::orbital_logs_draw(MainForm::ui.logs_main, "Logs", &this->isShowLogs);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("ProtectionBorder", ImVec2(655, 310), true);;
		ImGui::Checkbox("ON/OFF Render Scene", &Settings::ProtectionDisableRender);
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
		if ((GetTickCount() - lastTimeAutoLogin) > 16000 && Settings::ProtectionAutoLogin)
		{
			if (!GameFunctions::PlayerNEW_GetMainActorPtr())
			{
				GameFunctions::NetworkStreamConnectGameServer(0);
#else
		if ((GetTickCount() - lastTimeAutoLogin) > 1000 && Settings::ProtectionAutoLogin)
		{
			if (GameFunctionsCustom::PlayerDirectEnter())
			{
			
#endif
				Main::Instance().ResetSkillTimer();
				lastTimeAutoLogin = GetTickCount();
			}
		}


	}


};