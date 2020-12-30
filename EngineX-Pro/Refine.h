#pragma once
class Refine :public IAbstractModuleBase, public Singleton<Refine>
{
private:
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

	int Page = 1;
	int selctedSlot = 0;
	std::map<DWORD, pair<DWORD, DirectTexture>> itemIcons;

	void OnTab1()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("RefineBorder", ImVec2(ImGui::GetWindowWidth() - 20, ImGui::GetWindowHeight() - 10), true);
		/*ImGui::RadioButton("Blacksmith", &Settings::REFINE_UPGRADE_TYPE, 0);
		ImGui::SameLine();
		ImGui::RadioButton("DT Blacksmith", &Settings::REFINE_UPGRADE_TYPE, 4);
		ImGui::SameLine();
		ImGui::RadioButton("Guild Blacksmith", &Settings::REFINE_UPGRADE_TYPE, 1);
		ImGui::PushItemWidth(150); ImGui::InputInt("Item Slot", &Settings::REFINE_ITEM_SLOT);
		ImGui::PushItemWidth(150); ImGui::InputInt("Count", &Settings::REFINE_UPGRADE_COUNT, 1, 3);
		if (ImGui::Button("Upgrade Item Slot"))
		{
			int itemVnum = GameFunctions::PlayerGetItemIndex(TItemPos(INVENTORY, Settings::REFINE_ITEM_SLOT - 1));
			if (itemVnum == 0)
			{

			}
			for (int i = 0; i < Settings::REFINE_UPGRADE_COUNT; i++)
			{
				GameFunctions::NetworkStreamSendRefinePacket(Settings::REFINE_ITEM_SLOT - 1, Settings::REFINE_UPGRADE_TYPE);
			}
		}*/
		ImGui::BeginTable("##table1", 2);
		ImGui::TableNextRow();
		ImGui::TableSetColumnIndex(0);
		if (GameFunctionsCustom::PlayerIsInstance())
		{
			int Multipler = (Page - 1) * 45;
			int i = 0;
			static ImGuiTableFlags flags = ImGuiTableFlags_Borders;//ImGuiTableFlags_RowBg
			ImGui::BeginTable("##tableinventory", 5, flags, ImVec2(0.0f, 0.0f));
			float width = 32.0f;
			float height = 31.0f;
			ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, width);
			ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, width);
			ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, width);
			ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, width);
			ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, width);
			for (int row = 0; row < 9; row++)
			{
				ImGui::TableNextRow(ImGuiTableRowFlags_None, height);
				for (int column = 0; column < 5; column++)
				{
					ImGui::TableSetColumnIndex(column);
					int current_i = i + Multipler;
					int currentVnum = GameFunctions::PlayerGetItemIndex(TItemPos(INVENTORY, current_i));
					if (currentVnum > 0)
					{
						DWORD* pItemData;
						GameFunctions::ItemManagerGetItemDataPointer(currentVnum, &pItemData);
						std::string iconPath = GetStr((DWORD)pItemData + 76);
						DirectTexture D3DTexture = NULL;
						if (!MainForm::ResourceMap.count(iconPath))
						{
							MainForm::ResourceMap.insert(make_pair(iconPath, GameFunctionsCustom::LoadD3DTexture(iconPath.c_str())));
						}
						D3DTexture = MainForm::ResourceMap[iconPath];
						D3DSURFACE_DESC desc;
						desc.Width = 32;
						desc.Height = 32;
						if (D3DTexture)
						{
							D3DTexture->GetLevelDesc(0, &desc);
						}
						std::string itemid = "##" + std::to_string(current_i);
						if (ImGui::ItemImage(itemid, D3DTexture, ImVec2(desc.Width, desc.Width * 0.85f), ImVec2(desc.Width, desc.Height * 0.85f), current_i == selctedSlot))
						{
							selctedSlot = current_i;
						}
						if (ImGui::IsItemHovered()) {
							ImGui::BeginTooltip();
							std::string name = GameFunctions::ItemDataGetName(pItemData);
							ImGui::SetTooltip(StringExtension::ASCIIToUTF8(name.c_str()).c_str());
							ImGui::EndTooltip();
						}
					}
					i++;
				}
			}
			ImGui::EndTable();
		}
		ImGui::TableSetColumnIndex(1);
		ImGui::PushItemWidth(30); ImGui::SliderInt("##EQPage", &Page, 1, 4); ImGui::SameLine();
		int selectedVnum = GameFunctions::PlayerGetItemIndex(TItemPos(INVENTORY, selctedSlot));
		if (selectedVnum > 0)
		{
			DWORD* pItemData;
			GameFunctions::ItemManagerGetItemDataPointer(selectedVnum, &pItemData);
			std::string name = GameFunctions::ItemDataGetName(pItemData);
			ImGui::Text("[%d] Selected Item: %s", selctedSlot + 1, StringExtension::ASCIIToUTF8(name.c_str()).c_str());
			ImGui::BeginTabBar("#Inventory Manager");
			if (ImGui::BeginTabItem("Refine")) 
			{
				ImGui::PushItemWidth(100); ImGui::SliderInt("Count", &Settings::REFINE_UPGRADE_COUNT, 1, 9); ImGui::SameLine();
				if (ImGui::Button("Upgrade"))
				{
					for (int i = 0; i < Settings::REFINE_UPGRADE_COUNT; i++)
					{
						GameFunctions::NetworkStreamSendRefinePacket(selctedSlot, Settings::REFINE_UPGRADE_TYPE);
					}
				}
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Actions"))
			{
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Bonus Switcher"))
			{
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
		ImGui::EndTable();
		ImGui::EndChild();
		ImGui::PopStyleVar();
	}

	void OnTabs()
	{
		MainForm::AddTab(32, "Inventory");
	}

	void OnMenu()
	{
		switch (MainForm::CurTabOpen)
		{
		case 32:
			OnTab1();
			break;
		}
	}
};