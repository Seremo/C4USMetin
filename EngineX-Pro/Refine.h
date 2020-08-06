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

	void OnMenu()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("RefineBorder", ImVec2(645, 150), true);
		ImGui::RadioButton("Blacksmith", &Settings::REFINE_UPGRADE_TYPE, 0); 
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
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
	}
};