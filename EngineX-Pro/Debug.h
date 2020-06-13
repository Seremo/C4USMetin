#pragma once
class Debug :public IAbstractModuleBase, public Singleton<Debug>
{
private:
	int recv_limit = 3;
	string packetHex = string(300, '\0');;
	
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

		if (ImGui::InputInt("Recv Limit Game Phase", &recv_limit))
		{
			MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x1E1597), recv_limit, 1);
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
		ImGui::Text("Inventory Eq Percent Usage "); ImGui::SameLine(); ImGui::Text(to_string(GameFunctionsCustom::InventoryEquippedPercentage()).c_str());
		ImGui::Text("ID First Slot Item  "); ImGui::SameLine();
		ImGui::Text(to_string(GameFunctions::PlayerGetItemIndex(TItemPos(INVENTORY, 0))).c_str());
		ImGui::InputText("Packet Hex", &packetHex[0], packetHex.size());
		if (ImGui::Button("Send Packet"))
		{
			
			GameFunctionsCustom::SendPacket(string(packetHex));
			
		}
		D3DVECTOR oldPosition;
		GameFunctions::InstanceBaseNEW_GetPixelPosition(GameFunctions::PlayerNEW_GetMainActorPtr(), &oldPosition);

		if (ImGui::Button("TEST 3"))
		{
			GameFunctionsCustom::LookAtDestPixelPosition(GameFunctions::PlayerGetTargetVID());
		}
		if (ImGui::Button("TEST 1"))
		{
			/*vector< D3DVECTOR> gf = Misc::DivideTwoPointsByDistance(1800, oldPosition, NewPosition);
			for (vector< D3DVECTOR>::iterator it = gf.begin(); it != gf.end(); ++it)
			{
				MainForm::orbital_log_uart(0, string("(" + to_string(it->x) + " " + to_string(it->y) + ")").c_str());

			}*/
		
		}
		if (ImGui::Button("TEST 2"))
		{


		}

		if (ImGui::Button("TEST 4"))
		{
			
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();


	}
};