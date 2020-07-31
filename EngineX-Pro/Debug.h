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

	bool DoAnimation = false;
	int eFunc = 3;
	int uArg = 133;

	void OnUpdate()
	{
		if (DoAnimation)
		{
			D3DVECTOR myPosition;
			GameFunctions::InstanceBaseNEW_GetPixelPosition(GameFunctions::PlayerNEW_GetMainActorPtr(), &myPosition);
			GameFunctions::NetworkStreamSendCharacterStatePacket(myPosition, GameFunctions::InstanceBaseGetRotation(GameFunctions::PlayerNEW_GetMainActorPtr()), eFunc, uArg);
			GameFunctions::InstanceBase__SetAffect(GameFunctions::PlayerNEW_GetMainActorPtr(), eFunc, true);
		}
	}

	void OnRender()
	{
	}

	
	void OnMenu()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("DebugBorder", ImVec2(645, 445), true);

		if (ImGui::Button("Open Shop Search")) {
			DWORD h = *reinterpret_cast<DWORD*>(Globals::iCPythonNetworkStreamInstance + (244*4));
			Globals::PyCallClassMemberFunc((PyObject*)h, "OpenPShopSearchDialogCash", Globals::Py_BuildValue("()"));
		}

		if (ImGui::Button("Open Shop Search 2")) {
			DWORD h = *reinterpret_cast<DWORD*>(Globals::iCPythonNetworkStreamInstance + (244 * 4));
			Globals::PyCallClassMemberFunc((PyObject*)h, "OpenPShopSearchDialog", Globals::Py_BuildValue("()"));
		}

		ImGui::Checkbox("Do Animation", &DoAnimation);
		ImGui::InputInt("eFunc:", &eFunc);
		ImGui::InputInt("uArg:", &uArg);


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

	/*	if (GameFunctions::PlayerGetTargetVID())
		{
		DWORD mob_vnum = GameFunctions::InstanceBaseGetVirtualNumber(GameFunctions::CharacterManagerGetInstancePtr(GameFunctions::PlayerGetTargetVID()));
		const TMobTable* mob_info = GameFunctions::NonPlayerGetTable(mob_vnum);
		ImGui::Text(to_string(mob_info->bRank).c_str());
		ImGui::Text(to_string(mob_info->bType).c_str());
		ImGui::Text(mob_info->szLocaleName);
		ImGui::Text(mob_info->szName);
		}*/
		static float v = 0;
		if (ImGui::InputFloat("vcxcvcxve", &v, 1, 1))
		{
			GameFunctions::NetworkStreamServerCommand(string("FishingCheckCode "+ to_string((int)v)).c_str());
		}
		/*ImGui::Text(GameFunctions::NetworkStreamGetAccountCharacterSlotDataz(0, (int)v));*/
		
		ImGui::Text(GameFunctions::PlayerGetName());
		
		ImGui::Text(to_string(GameFunctions::NetworkStreamIsOnline()).c_str());
		
		ImGui::InputText("Packet Hex", &packetHex[0], packetHex.size());
		if (ImGui::Button("Send Packet"))
		{
			
			GameFunctionsCustom::SendPacket(string(packetHex.c_str()));
			
		}
		

		if (ImGui::Button("TEST 3"))
		{
			
		}
		

		if (ImGui::Button("TEST 2"))
		{
			
		}

		if (ImGui::Button("TEST 4"))
		{
			
		}
		if (ImGui::Button("TEST 6"))
		{
			GameFunctions::NetworkStreamConnectGameServer(GameFunctionsCustom::GetCharSlotByName(GameFunctions::PlayerGetName()));
		}
		if (ImGui::Button("TEST 7"))
		{
			
			GameFunctionsCustom::PlayerDirectEnter();
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();


	}
};