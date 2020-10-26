#pragma once
class Item :public IAbstractModuleBase, public Singleton<Item>
{
	vector<TCItemData*> ItemsListDisplay;
private:
	
	



	map< DWORD, pair<string, bool>> itemPickupFilteredList;
	string filterItemLine=  string(60, 0x00);;
	string filterItemLineLast = string(60, 0x00);;


	DWORD itemPickupFilteredListSelected = 0;
	DWORD itemPickupSelectedListSelected = 0;
public:
	void OnStart()
	{

	}
	void OnStop()
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
		/*if (!Globals::itemProtoList.size())
		{
			Globals::itemProtoList = GameFunctionsCustom::GetItemProtoList();
		}*/
		if (!Globals::itemProtoNames.size())
		{
			Globals::itemProtoNames = GameFunctionsCustom::GetItemProtoNames();
		}
		
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("PickupBorder", ImVec2(420, 420), true);
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
		ImGui::Checkbox("Pickup Enable", &Settings::ITEM_PICKUP_ENABLE); 
		ImGui::SliderInt("Pickup Delay(ms)", &Settings::ITEM_PICKUP_TIME, 0, 3000);
		ImGui::PushItemWidth(100); ImGui::InputInt("Pickup Distance", &Settings::ITEM_PICKUP_DISTANCE, 100, 1000);
		ImGui::RadioButton("Normal", &Settings::ITEM_PICKUP_TYPE, 0); ImGui::SameLine();
		ImGui::RadioButton("Range", &Settings::ITEM_PICKUP_TYPE, 1); 
		ImGui::Checkbox("Filter", &Settings::ITEM_PICKUP_FILTER); ImGui::SameLine();
		ImGui::InputText("Search", &filterItemLine[0], filterItemLine.size());
		ImGui::Separator();
		ImGui::Columns(2, "PickupList", false);
		ImGui::BeginChild("ItemProtoList", ImVec2(190, 255), true);
		if (strlen(&filterItemLine[0]) >= 2)
		{
			if (filterItemLine != filterItemLineLast)
			{
				filterItemLineLast = filterItemLine;
				itemPickupFilteredList.clear();
				for (map<DWORD, const char*>::iterator itor = Globals::itemProtoNames.begin(); itor != Globals::itemProtoNames.end(); itor++)
				{
					switch (Globals::Server)
					{
						case ServerName::AELDRA:
						{
							if (!StringExtension::Equals(itor->second, "") && StringExtension::Contains(itor->second, filterItemLine.c_str()))
							{
								itemPickupFilteredList.insert(std::make_pair(itor->first, std::make_pair(string(itor->second) + " " + to_string(itor->first), false)));
							}
							break;
						}
						default:
						{
							if (!StringExtension::Equals(itor->second, "") && StringExtension::Contains(itor->second, filterItemLine.c_str()))
							{
								itemPickupFilteredList.insert(std::make_pair(itor->first, std::make_pair(StringExtension::to_utf8(itor->second) + " " + to_string(itor->first), false)));
							}
							break;
						}
					}
				}
			}	
		}
		if(!itemPickupFilteredList.size())
		{
			ImGui::Text("Type 3 Letters...");
		}
		else
		{
			for (map< DWORD, pair<string, bool>>::iterator itor = itemPickupFilteredList.begin(); itor != itemPickupFilteredList.end(); itor++)
			{
				if (ImGui::Selectable(itor->second.first.c_str(), itor->second.second))
				{
					itemPickupFilteredListSelected = itor->first;
				}
				if (itor->first == itemPickupFilteredListSelected)
				{
					itor->second.second = true;
				}
				else
				{
					itor->second.second = false;
				}

			}
		}	
		ImGui::EndChild();
		ImGui::NextColumn();
		ImGui::BeginChild("ItemProtoListFiltered", ImVec2(190, 255), true);
		for (map< DWORD, pair<string, bool>>::iterator itor = Settings::ITEM_PICKUP_SELECTED_LIST.begin(); itor != Settings::ITEM_PICKUP_SELECTED_LIST.end(); itor++)
		{
			if (ImGui::Selectable(itor->second.first.c_str(), itor->second.second))
			{
				itemPickupSelectedListSelected = itor->first;
			}
			if (itor->first == itemPickupSelectedListSelected)
			{
				itor->second.second = true;
			}
			else
			{
				itor->second.second = false;
			}
		}
		ImGui::EndChild();
		ImGui::EndColumns();
		if (ImGui::Button("Add")) 
		{
			for (map< DWORD, pair<string, bool>>::iterator itor = itemPickupFilteredList.begin(); itor != itemPickupFilteredList.end(); itor++)
			{
				if (itor->second.second)
				{
					if (Settings::ITEM_PICKUP_SELECTED_LIST.count(itor->first))
					{

					}
					else
					{
						Settings::ITEM_PICKUP_SELECTED_LIST.insert(std::make_pair(itor->first, std::make_pair(itor->second.first,false)));
					}
					
				}

			}
		}
		ImGui::SameLine(); ImGui::Dummy(ImVec2(160.0f, 0.0f)); ImGui::SameLine();
		if (ImGui::Button("Remove"))
		{

			DWORD key = 0;
			for (map< DWORD, pair<string, bool>>::iterator itor = Settings::ITEM_PICKUP_SELECTED_LIST.begin(); itor != Settings::ITEM_PICKUP_SELECTED_LIST.end(); itor++)
			{
				if (itor->second.second)
				{

					key = itor->first;
				}

			}
			Settings::ITEM_PICKUP_SELECTED_LIST.erase(key);

		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
		ImGui::SameLine();
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);

		static float ITEM_SLOT_RANDOM_MIN_TIME;
		static float ITEM_SLOT_RANDOM_MAX_TIME;

		ImGui::BeginChild("SlotsBorder", ImVec2(225, 445), true);
		ImGui::Checkbox("Random +/- (s.ms)  ", &Settings::ITEM_SLOT_RANDOM_ENABLE); /*ImGui::SameLine();*/
	/*	ImGui::InputFloatMinMax("Min", &Settings::ITEM_SLOT_RANDOM_MIN_TIME, 0, 100, 0.100, 1);
		ImGui::InputFloatMinMax("Max", &Settings::ITEM_SLOT_RANDOM_MAX_TIME, 0, 100, 0.100, 1);*/


		ImGui::InputFloat("Min", &Settings::ITEM_SLOT_RANDOM_MIN_TIME,  0.100, 1);
		ImGui::InputFloat("Max", &Settings::ITEM_SLOT_RANDOM_MAX_TIME,  0.100, 1);
		ImGui::Separator();
		ImGui::Text("Slots(s.ms)");
		ImGui::Checkbox("3  ", &Settings::ITEM_SLOT_ENABLE_3); ImGui::SameLine();
		ImGui::InputFloat("##slot3time", &Settings::ITEM_SLOT_TIME_3, 0.100, 1);
		ImGui::Checkbox("4  ", &Settings::ITEM_SLOT_ENABLE_4); ImGui::SameLine();
		ImGui::InputFloat("##slot4time", &Settings::ITEM_SLOT_TIME_4, 0.100, 1);
		ImGui::Checkbox("5  ", &Settings::ITEM_SLOT_ENABLE_5); ImGui::SameLine();
		ImGui::InputFloat("##slot5time", &Settings::ITEM_SLOT_TIME_5, 0.100, 1);
		ImGui::Checkbox("6  ", &Settings::ITEM_SLOT_ENABLE_6); ImGui::SameLine();
		ImGui::InputFloat("##slot6time", &Settings::ITEM_SLOT_TIME_6, 0.100, 1);
		ImGui::Checkbox("7  ", &Settings::ITEM_SLOT_ENABLE_7); ImGui::SameLine();
		ImGui::InputFloat("##slot7time", &Settings::ITEM_SLOT_TIME_7, 0.100, 1);
		ImGui::Checkbox("8  ", &Settings::ITEM_SLOT_ENABLE_8); ImGui::SameLine();
		ImGui::InputFloat("##slot8time", &Settings::ITEM_SLOT_TIME_8, 0.100, 1);
		ImGui::Checkbox("9  ", &Settings::ITEM_SLOT_ENABLE_10); ImGui::SameLine();
		ImGui::InputFloat("##slot9time", &Settings::ITEM_SLOT_TIME_9, 0.100, 1);
		ImGui::Checkbox("10", &Settings::ITEM_SLOT_ENABLE_10); ImGui::SameLine();
		ImGui::InputFloat("##slot10time", &Settings::ITEM_SLOT_TIME_10, 0.100, 1);
		ImGui::Checkbox("11", &Settings::ITEM_SLOT_ENABLE_11); ImGui::SameLine();
		ImGui::InputFloat("##slot11time", &Settings::ITEM_SLOT_TIME_11, 0.100, 1);
		ImGui::Checkbox("12", &Settings::ITEM_SLOT_ENABLE_12); ImGui::SameLine();
		ImGui::InputFloat("##slot12time", &Settings::ITEM_SLOT_TIME_12, 0.100, 1);
		ImGui::Checkbox("13", &Settings::ITEM_SLOT_ENABLE_14); ImGui::SameLine();
		ImGui::InputFloat("##slot13time", &Settings::ITEM_SLOT_TIME_13, 0.100, 1);
		ImGui::Checkbox("14", &Settings::ITEM_SLOT_ENABLE_14); ImGui::SameLine();
		ImGui::InputFloat("##slot14time", &Settings::ITEM_SLOT_TIME_14, 0.100, 1);
		ImGui::Checkbox("15", &Settings::ITEM_SLOT_ENABLE_15); ImGui::SameLine();
		ImGui::InputFloat("##slot15time", &Settings::ITEM_SLOT_TIME_15, 0.100, 1);
		ImGui::Checkbox("16", &Settings::ITEM_SLOT_ENABLE_16); ImGui::SameLine();
		ImGui::InputFloat("##slot15time", &Settings::ITEM_SLOT_TIME_16, 0.100, 1);
		ImGui::EndChild();
		ImGui::PopStyleVar(); ImGui::SameLine();
	}
	void OnUpdate()
	{
		
		if (Settings::GLOBAL_SWITCH && GameFunctionsCustom::PlayerIsInstance())
		{		
			Pickup();
			Slots();
//#ifdef VIDGAR
//			vector<DWORD> eraseList;
//			for (map<DWORD, TGroundItemInstance*>::iterator itor = Globals::GroundItemList.begin(); itor != Globals::GroundItemList.end(); itor++)
//			{			
//				D3DVECTOR playerPosition = GameFunctionsCustom::PlayerGetPixelPosition();
//				LONG GlobalX = playerPosition.x;
//				LONG GlobalY = playerPosition.y;	
//				float Distance = MiscExtension::CountDistanceTwoPoints(GlobalX, GlobalY, itor->second->v3EndPosition.x, -itor->second->v3EndPosition.y);
//				if (Distance > 30000)
//				{
//					eraseList.push_back(itor->first);
//				}		
//			}
//			for (auto itor = eraseList.begin(); itor != eraseList.end(); itor++)
//			{
//				Globals::GroundItemList.erase(*itor);
//			}
//#endif
		}

	} 
	void Slots()
	{
		float randomMinMax = 0;
		if (Settings::ITEM_SLOT_RANDOM_ENABLE)
		{
			randomMinMax = MiscExtension::RandomFloat(Settings::ITEM_SLOT_RANDOM_MIN_TIME, Settings::ITEM_SLOT_RANDOM_MAX_TIME);
		}
		if (  Settings::ITEM_SLOT_ENABLE_3 && DynamicTimer::CheckAutoSet ("UseSlot3", (randomMinMax + Settings::ITEM_SLOT_TIME_3) *1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 2));
		}
		if (Settings::ITEM_SLOT_ENABLE_4 && DynamicTimer::CheckAutoSet("UseSlot4", (randomMinMax + Settings::ITEM_SLOT_TIME_4)* 1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 3));
		}
		if (Settings::ITEM_SLOT_ENABLE_5 && DynamicTimer::CheckAutoSet("UseSlot5", (randomMinMax + Settings::ITEM_SLOT_TIME_5) * 1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 4));
		}
		if (Settings::ITEM_SLOT_ENABLE_6 && DynamicTimer::CheckAutoSet("UseSlot6", (randomMinMax + Settings::ITEM_SLOT_TIME_6) * 1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 5));
		}
		if (Settings::ITEM_SLOT_ENABLE_7 && DynamicTimer::CheckAutoSet("UseSlot7", (randomMinMax + Settings::ITEM_SLOT_TIME_7) * 1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 6));
		}
		if (Settings::ITEM_SLOT_ENABLE_8 && DynamicTimer::CheckAutoSet("UseSlot8", (randomMinMax + Settings::ITEM_SLOT_TIME_8) * 1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 7));

		}
		if (Settings::ITEM_SLOT_ENABLE_9 && DynamicTimer::CheckAutoSet("UseSlot9", (randomMinMax + Settings::ITEM_SLOT_TIME_9 )* 1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 8));
		}
		if (Settings::ITEM_SLOT_ENABLE_10 && DynamicTimer::CheckAutoSet("UseSlot10", (randomMinMax + Settings::ITEM_SLOT_TIME_10) * 1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 9));
		}
		if (Settings::ITEM_SLOT_ENABLE_11 && DynamicTimer::CheckAutoSet("UseSlot11", (randomMinMax + Settings::ITEM_SLOT_TIME_11 )* 1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 10));
		}
		if (Settings::ITEM_SLOT_ENABLE_12 && DynamicTimer::CheckAutoSet("UseSlot12", (randomMinMax + Settings::ITEM_SLOT_TIME_12) * 1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 11));
		}
		if (Settings::ITEM_SLOT_ENABLE_13 && DynamicTimer::CheckAutoSet("UseSlot13", (randomMinMax + Settings::ITEM_SLOT_TIME_13) * 1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 12));
		}
		if (Settings::ITEM_SLOT_ENABLE_14 && DynamicTimer::CheckAutoSet("UseSlot14", (randomMinMax + Settings::ITEM_SLOT_TIME_14) * 1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 13));
		}
		if (Settings::ITEM_SLOT_ENABLE_15 && DynamicTimer::CheckAutoSet("UseSlot15", (randomMinMax + Settings::ITEM_SLOT_TIME_15 )* 1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 14));
		}
		if (Settings::ITEM_SLOT_ENABLE_16 && DynamicTimer::CheckAutoSet("UseSlot16", (randomMinMax + Settings::ITEM_SLOT_TIME_16) * 1000))
		{
			GameFunctions::NetworkStreamSendItemUsePacket(TItemPos(INVENTORY, 15));
		}
	}
	void Pickup()
	{
		if (DynamicTimer::CheckAutoSet("PickUp", Settings::ITEM_PICKUP_TIME) && Settings::ITEM_PICKUP_ENABLE)
		{
			map<DWORD, TGroundItemInstance*> groundItemList = GameFunctionsCustom::GetGroundItemList();
			for (map<DWORD, TGroundItemInstance*>::iterator itor = groundItemList.begin(); itor != groundItemList.end(); itor++)
			{
				DWORD itemVID = itor->first;
				TGroundItemInstance* groundItemInstance = itor->second;
				if (Settings::ITEM_PICKUP_FILTER)
				{
					if (!Settings::ITEM_PICKUP_SELECTED_LIST.count(groundItemInstance->dwVirtualNumber))
					{
						continue;
					}		
				}
				D3DVECTOR playerPosition = GameFunctionsCustom::PlayerGetPixelPosition();
				float distance = MiscExtension::CountDistanceTwoPoints(playerPosition.x, playerPosition.y, groundItemInstance->v3EndPosition.x, -groundItemInstance->v3EndPosition.y);
				switch (Settings::ITEM_PICKUP_TYPE)
				{
				case 0://normal
					if (distance < 300)
					{
						GameFunctions::NetworkStreamSendItemPickUpPacket(itemVID);
						if (Settings::ITEM_PICKUP_TIME == 0)
						{
							continue;
						}
						else
						{
							return;
						}
						
					}
					break;
				case 1://range
					if (distance < 300)
					{
						GameFunctions::NetworkStreamSendItemPickUpPacket(itemVID);
						if (Settings::ITEM_PICKUP_TIME == 0)
						{
							continue;
						}
						else
						{
							return;
						}
					}
					else if (distance > 300 && distance < Settings::ITEM_PICKUP_DISTANCE)
					{
						vector< D3DVECTOR> steps = MiscExtension::DivideTwoPointsByDistance(1500, playerPosition, D3DVECTOR{ groundItemInstance->v3EndPosition.x, -groundItemInstance->v3EndPosition.y, groundItemInstance->v3EndPosition.z });
						int i = 0;
						for (vector< D3DVECTOR>::iterator it = steps.begin(); it != steps.end(); ++it)
						{
							GameFunctions::NetworkStreamSendCharacterStatePacket(D3DVECTOR{ it->x, it->y, it->z }, 0, 0, 0);
						}
						GameFunctions::NetworkStreamSendItemPickUpPacket(itemVID);
						steps = MiscExtension::DivideTwoPointsByDistance(1500, D3DVECTOR{ groundItemInstance->v3EndPosition.x, -groundItemInstance->v3EndPosition.y, groundItemInstance->v3EndPosition.z }, playerPosition);
						for (vector< D3DVECTOR>::iterator it = steps.begin(); it != steps.end(); ++it)
						{
							GameFunctions::NetworkStreamSendCharacterStatePacket(D3DVECTOR{ it->x, it->y, it->z }, 0, 0, 0);
						}
						if (Settings::ITEM_PICKUP_TIME == 0)
						{
							continue;
						}
						else
						{
							return;
						}
					}
					break;
				}
			}
			
		}
	}
};