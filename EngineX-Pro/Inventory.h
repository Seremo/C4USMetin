#pragma once
class Inventory :public IAbstractModuleBase, public Singleton<Inventory>
{
private:
public:
	void OnStart()
	{

	}

	void OnStop()
	{
	}

	int Page = 1;
	map<string, DirectTexture> itemIcons;
	vector<int> selectedSlots = { };
	bool PlayerIsInstance = false;
	int PackCount = 1;
	int SplitCount = 1;
	void OnUpdate()
	{
		PlayerIsInstance = GameFunctionsCustom::PlayerIsInstance();
		if (!PlayerIsInstance)
		{
			return;
		}
	}

	void OnRender()
	{
	}

	void SplitItems()
	{
		for (auto slot : selectedSlots)
		{
			DelayActions::AppendBlock(false, 300, &GameFunctionsCustom::ItemSplitter, slot, PackCount, SplitCount);
		}
	}

	void UpgradeItems()
	{
		for (int i = 0; i < Settings::REFINE_UPGRADE_COUNT; i++)
		{
			for (auto slot : selectedSlots)
			{
				GameFunctions::NetworkStreamSendRefinePacket(slot, Settings::REFINE_UPGRADE_TYPE);
			}
		}
	}

	void OnTab1()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("RefineBorder", ImVec2(ImGui::GetWindowWidth() - 20, ImGui::GetWindowHeight() - 10), true);
		ImGui::BeginTable("##table1", 2);
		ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, 205.0f);
		ImGui::TableNextRow();
		ImGui::TableSetColumnIndex(0);
		if (PlayerIsInstance)
		{
			int Multipler = (Page - 1) * 45;
			int i = 0;
			static ImGuiTableFlags flags = ImGuiTableFlags_Borders;//ImGuiTableFlags_RowBg
			ImGui::BeginTable("##tableinventory", 5, flags, ImVec2(0.0f, 0.0f));
			float width = 32.0f;
			float height = 32.0f;
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
					int currentSlot = i + Multipler;
					int currentVnum = GameFunctions::PlayerGetItemIndex(TItemPos(INVENTORY, currentSlot));
					if (currentVnum > 0)
					{
						DWORD* pItemData;
						GameFunctions::ItemManagerGetItemDataPointer(currentVnum, &pItemData);
						std::string iconPath = ""; // tymczasowo w taki sposob
						switch (Globals::Server)
						{
						case ServerName::METINPL:
							iconPath = GetStr((DWORD)pItemData + 92);
							break;
						default:
							iconPath = GetStr((DWORD)pItemData + 76);
							break;
						}
						DirectTexture D3DTexture = NULL;
						if (!itemIcons.count(iconPath))
						{
							itemIcons.insert(make_pair(iconPath, GameFunctionsCustom::LoadD3DTexture(iconPath.c_str())));
						}
						D3DTexture = itemIcons[iconPath];
						D3DSURFACE_DESC desc;
						desc.Width = 32;
						desc.Height = 32;
						if (D3DTexture)
						{
							D3DTexture->GetLevelDesc(0, &desc);
						}
						std::string itemid = "##" + std::to_string(currentSlot);
						bool isSelected = std::find(selectedSlots.begin(), selectedSlots.end(), currentSlot) != selectedSlots.end();
						if (ImGui::ItemImage(itemid, D3DTexture, ImVec2(desc.Width, desc.Width * 0.90f), ImVec2(desc.Width, desc.Height * 0.90f), isSelected))
						{
							if (isSelected)
							{
								selectedSlots.erase(std::find(selectedSlots.begin(), selectedSlots.end(), currentSlot));
							}
							else
							{
								selectedSlots.push_back(currentSlot);
							}
						}
						if (ImGui::IsItemHovered()) {
							ImGui::BeginTooltip();
							std::string name = GameFunctions::ItemDataGetName(pItemData);
							ImGui::SetTooltip(StringExtension::ASCIIToUTF8(name.c_str()).c_str());
							ImGui::EndTooltip();
						}
					}
					else
					{
						bool isSelected = std::find(selectedSlots.begin(), selectedSlots.end(), currentSlot) != selectedSlots.end();
						if (isSelected)
						{
							selectedSlots.erase(std::find(selectedSlots.begin(), selectedSlots.end(), currentSlot));
						}
					}
					i++;
				}
			}
			ImGui::EndTable();
		}
		ImGui::TableSetColumnIndex(1);
		ImGui::PushItemWidth(70); ImGui::SliderInt("EQ Page", &Page, 1, 4);
		string slots_str = "";
		for (auto slot : selectedSlots) 
		{
			slots_str += " " + to_string(slot) + " ";
		}
		ImGui::Text("Selected Slots: [%s]", slots_str.c_str());
		ImGui::BeginTabBar("#Inventory Manager");
		if (ImGui::BeginTabItem("Refine"))
		{
			ImGui::PushItemWidth(100); ImGui::SliderInt("Count", &Settings::REFINE_UPGRADE_COUNT, 1, 9); ImGui::SameLine();
			if (ImGui::Button("Upgrade"))
			{
				UpgradeItems();
			}
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Actions"))
		{
			if (ImGui::Button("Split")) 
			{
				SplitItems();
			}  ImGui::SameLine();
			ImGui::InputInt("Pack##split", &PackCount, 0, 0);  ImGui::SameLine();
			ImGui::InputInt("Count##split", &SplitCount, 0, 0); 
			if (ImGui::Button("Sell"))
			{

			}
			if (ImGui::Button("Stack"))
			{

			}
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Bonus Switcher"))
		{
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
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