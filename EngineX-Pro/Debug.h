#pragma once



class Debug :public IAbstractModuleBase, public Singleton<Debug>
{
private:
	int recv_limit = 3;
	string packetHex = string(900, '\0');;

	D3DVECTOR NewPosition;
public:
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
		ImGui::BeginChild("DebugBorder", ImVec2(645, 445), true);

		ImGui::Checkbox("Use Python", &Globals::UsePythonFunctions);




		if (ImGui::InputInt("Recv Limit Game Phase", &recv_limit))
		{
			switch (Globals::Server)
			{
			case ServerName::MEDIUMMT2:
				MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x8D035), recv_limit, 1);
				break;

			case ServerName::METINPL:
				MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x1F4387), recv_limit, 1);
				break;
			}
		}

		ImGui::Text("BaseAddress  "); ImGui::SameLine();
		ImGui::Text(StringExtension::DWORDToHexString(Globals::hEntryBaseAddress).c_str());
		ImGui::Text("CPythonPlayerInstance  "); ImGui::SameLine();
		ImGui::Text(StringExtension::DWORDToHexString(Globals::iCPythonPlayerInstance).c_str());
		ImGui::Text("CPythonCharacterManagerInstance  "); ImGui::SameLine();
		ImGui::Text(StringExtension::DWORDToHexString(Globals::iCPythonCharacterManagerInstance).c_str());
		ImGui::Text("CPythonNetworkStreamInstance  "); ImGui::SameLine();
		ImGui::Text(StringExtension::DWORDToHexString(Globals::iCPythonNetworkStreamInstance).c_str());
		ImGui::Text("CPythonItemInstance  "); ImGui::SameLine();
		ImGui::Text(StringExtension::DWORDToHexString(Globals::iCPythonItemInstance).c_str());
		ImGui::Text("CItemManagerInstance  "); ImGui::SameLine();
		ImGui::Text(StringExtension::DWORDToHexString(Globals::iCItemManagerInstance).c_str());
		ImGui::Text("CPythonApplicationInstance  "); ImGui::SameLine();
		ImGui::Text(StringExtension::DWORDToHexString(Globals::iCPythonApplicationInstance).c_str());






		ImGui::Text("Inventory Eq Percent Usage "); ImGui::SameLine(); ImGui::Text(to_string(GameFunctionsCustom::InventoryEquippedPercentage()).c_str());
		ImGui::Text("ID First Slot Item  "); ImGui::SameLine();







		ImGui::InputText("Packet Hex", &packetHex[0], packetHex.size());
		if (ImGui::Button("Send Packet"))
		{

			GameFunctionsCustom::SendPacket(string(packetHex.c_str()));

		}



		if (ImGui::Button("TEST 4"))
		{

		}
		if (ImGui::Button("TEST 6"))
		{




		}
		if (ImGui::Button("TEST 7"))
		{

			Settings::Save( "Settings",FileExtension::GetAppDataDirectory() + "\\EngineX\\");
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
	}
};