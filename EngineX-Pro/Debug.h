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
			if (DynamicTimer::CheckAutoSet("DoAnimation", 500))
			{
				D3DVECTOR myPosition;
				GameFunctions::InstanceBaseNEW_GetPixelPosition(GameFunctions::PlayerNEW_GetMainActorPtr(), &myPosition);
				GameFunctions::NetworkStreamSendCharacterStatePacket(myPosition, GameFunctions::InstanceBaseGetRotation(GameFunctions::PlayerNEW_GetMainActorPtr()), eFunc, uArg);
			}
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

		if (ImGui::Button("Test")) {
			DWORD h = *reinterpret_cast<DWORD*>(Globals::iCPythonNetworkStreamInstance + 0x178);
			Globals::PyCallClassMemberFunc((PyObject*)h, "SetGamePhase", Globals::Py_BuildValue("()"));
		}
		ImGui::Checkbox("Do Animation", &DoAnimation);
		ImGui::InputInt("eFunc:", &eFunc);
		ImGui::InputInt("uArg:", &uArg);


		if (ImGui::InputInt("Recv Limit Game Phase", &recv_limit))
		{
			switch (Globals::Server)
			{
			case ServerName::MEDIUMMT2:
				MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x8D035), recv_limit, 1);
				break;

			case ServerName::METINPL:
				MemoryExtension::MemSet((Globals::hEntryBaseAddress + 0x1EA1F7), recv_limit, 1);
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
		ImGui::Text("My instance  "); ImGui::SameLine();
		ImGui::Text(StringExtension::DWORDToHexString((DWORD)GameFunctions::PlayerNEW_GetMainActorPtr()).c_str());

		//DWORD targetVID = GameFunctions::PlayerGetTargetVID();
		//if (targetVID)
		//{
		//	DWORD mob_vnum = GameFunctions::InstanceBaseGetVirtualNumber(GameFunctions::CharacterManagerGetInstancePtr(targetVID));
		//	const TMobTable* mob_info = GameFunctions::NonPlayerGetTable(mob_vnum);
		//	if (mob_info != NULL)
		//	{
		//		BYTE bRank = (*(BYTE*)(mob_info + 55));
		//		ImGui::Text("TARGET bRANK:  "); ImGui::SameLine();
		//		ImGui::Text(to_string(bRank).c_str());
		//	}
		//}
		//ImGui::Text("GetItemIndex  "); ImGui::SameLine();
		//DWORD addres = *reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(Globals::iCPythonPlayerInstance + 4) + 68);
		//ImGui::Text(StringExtension::DWORDToHexString(addres - Globals::hEntryBaseAddress).c_str());
		//ImGui::Text("GetStatus  "); ImGui::SameLine();
		//DWORD addres2 = *reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(Globals::iCPythonPlayerInstance) + 16);
		//ImGui::Text(StringExtension::DWORDToHexString(addres2 - Globals::hEntryBaseAddress).c_str());
		ImGui::Text("VALUE:  "); ImGui::SameLine();
		DWORD addres = *(unsigned __int8*)(Globals::iCPythonApplicationInstance + 37) + 4;
		if (addres)
		{
			ImGui::Text(StringExtension::DWORDToHexString(addres - Globals::hEntryBaseAddress).c_str());
		}
		ImGui::Text("VID TARGET:  "); ImGui::SameLine();
		DWORD vid = GameFunctions::PlayerGetTargetVID();
		if (vid)
		{
			ImGui::Text(StringExtension::DWORDToHexString(vid).c_str());
		}


		ImGui::Text("Inventory Eq Percent Usage "); ImGui::SameLine(); ImGui::Text(to_string(GameFunctionsCustom::InventoryEquippedPercentage()).c_str());
		ImGui::Text("ID First Slot Item  "); ImGui::SameLine();


		
		//ImGui::Text(to_string(GameFunctions::PlayerGetItemIndex(TItemPos(INVENTORY, 0))).c_str());

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

		static float x, y, z;
		ImGui::InputFloat("X:", &x, 1.0f, 10.0f, 1);
		ImGui::InputFloat("y:", &y, 1.0f, 10.0f, 1);
		ImGui::InputFloat("z:", &z, 1.0f, 10.0f, 1);
		if (ImGui::Button("SetPixelPos"))
		{
			GameFunctions::InstanceBaseSCRIPT_SetPixelPosition(GameFunctions::PlayerNEW_GetMainActorPtr(), x, y);
		}
		if (ImGui::Button("SetPixelPos2"))
		{
			GameFunctions::InstanceBaseSCRIPT_SetPixelPosition(GameFunctions::PlayerNEW_GetMainActorPtr(), y, x);
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