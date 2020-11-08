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


	void Rozdzielacz(int vnum)
	{
		int index = GameFunctionsCustom::FindItemSlotInInventory(vnum);
		for (int i = 0; i < (Settings::INVENTORY_PAGE_SIZE * 4); i++)
		{
			int current_vnum = GameFunctions::PlayerGetItemIndex(TItemPos(INVENTORY, i));
			if (current_vnum == 0)
			{
				GameFunctions::NetworkStreamSendItemMovePacket(TItemPos(INVENTORY, index), TItemPos(INVENTORY, i), 1);
			}

		}
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
		ImGui::Text("ID First Slot Item  "); ImGui::SameLine(); ImGui::Text(to_string(GameFunctions::PlayerGetItemIndex(TItemPos(INVENTORY, 0))).c_str());
		ImGui::Text("ID Weapon Slot Item  "); ImGui::SameLine(); ImGui::Text(to_string(GameFunctions::PlayerGetItemIndex(TItemPos(EQUIPMENT, 4))).c_str());






		ImGui::InputText("Packet Hex", &packetHex[0], packetHex.size());
		if (ImGui::Button("Send Packet"))
		{

			GameFunctionsCustom::SendPacket(string(packetHex.c_str()));

		}

		if (ImGui::Button("TEST 1"))
		{
			cout << GameFunctionsCustom::PlayerIsRodEquipped() << endl;
		}
		if (ImGui::Button("TEST 2"))
		{
			GameFunctions::NetworkStreamSendGiveItemPacket(GameFunctions::PlayerGetTargetVID(), TItemPos(EQUIPMENT, 4), 0);
		}
		if (ImGui::Button("TEST 3"))
		{
			cout << GameFunctions::PlayerGetItemMetinSocket(TItemPos(INVENTORY, 0), 0) << endl;
		}
		if (ImGui::Button("TEST 4"))
		{
			GameFunctions::NetworkStreamSendGiveItemPacket(GameFunctions::PlayerGetTargetVID(), TItemPos(INVENTORY, 0), 0);
		}
		if (ImGui::Button("TEST 6"))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(EQUIPMENT, 4));
		}
		if (ImGui::Button("TEST 7"))
		{
			DWORD fishermanVid = GameFunctionsCustom::GetCloseObjectByVnum(9009);
			/*27400*/
			/*int slot = GameFunctionsCustom::FindItemSlotInInventory(27420);*/
			GameFunctions::NetworkStreamSendGiveItemPacket(fishermanVid, TItemPos(INVENTORY, 0), 1);
		}
#ifdef DEVELOPER_MODE
		if (ImGui::Button("Rozdziel raka!"))
		{
			Rozdzielacz(27887);
		}
		if (ImGui::Button("Rozdziel Biala Perla!"))
		{
			Rozdzielacz(27992);
		}
		if (ImGui::Button("Rozdziel Niebieska Perla!"))
		{
			Rozdzielacz(27993);
		}
		if (ImGui::Button("Rozdziel Czerwona Perla!"))
		{
			Rozdzielacz(27994);
		}
#endif
		if (ImGui::Button("TEST 8"))
		{
			if (GameFunctionsCustom::PlayerIsRodEquipped())
			{
				if (GameFunctions::PlayerGetItemMetinSocket(TItemPos(EQUIPMENT, 4), 0) == Settings::FISH_ROD_REFINE_POINTS[GameFunctions::PlayerGetItemIndex(TItemPos(EQUIPMENT, 4))].second)
				{
					GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(EQUIPMENT, 4));
					if (GameFunctionsCustom::PlayerIsRodEquipped())
					{
						/*MessageBox(NULL, "Cant unequipt rod", "Error", 0);*/
					}
				}
			}
			vector<DWORD> rodsList = GameFunctionsCustom::FindItemSlotsInInventory(27400, 27590);
			for (vector<DWORD>::iterator it = rodsList.begin(); it != rodsList.end(); ++it)
			{
				

				if (GameFunctions::PlayerGetItemMetinSocket(TItemPos(INVENTORY, *it), 0) == Settings::FISH_ROD_REFINE_POINTS[GameFunctions::PlayerGetItemIndex(TItemPos(INVENTORY, *it))].second  )
				{
					DWORD fishermanVid = GameFunctionsCustom::GetCloseObjectByVnum(9009);
					GameFunctions::NetworkStreamSendGiveItemPacket(fishermanVid, TItemPos(INVENTORY, *it), 1);
					GameFunctions::NetworkStreamSendScriptAnswerPacket(0);
				}

			}
			if (rodsList.size() > 0)
			{
				GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, rodsList[0]));
			}
		}
		if (ImGui::Button("TEST 9"))
		{
			GameFunctions::NetworkStreamSendScriptAnswerPacket(0);
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
	}
	void DebugMsgBoxNoBlocking(string message,...)
	{
		MessageBox(NULL, "Cheat Wrong Version", "Error", 0);
	}
};