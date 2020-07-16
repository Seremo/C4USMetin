#pragma once
class PythonScript :public IAbstractModuleBase, public Singleton<PythonScript>
{
private:
	string pythonBuffer =string(4000, '\0');;
	
public:
	virtual void OnStart()
	{

	}

	virtual void OnStop()
	{
	}

	virtual void OnUpdate()
	{

	}

	virtual void OnRender()
	{
	}

	virtual void OnMenu()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("PythonBorder", ImVec2(645, 430), true);
		ImGui::InputTextMultiline("##Code", &pythonBuffer[0], pythonBuffer.size(), ImVec2(615, 290));
		if (ImGui::Button("Execute"))
		{
			Globals::PyRun_SimpleStringFlags(pythonBuffer.c_str(),0);
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
	}
};