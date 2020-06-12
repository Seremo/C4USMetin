#pragma once
class PacketSniffer :public IAbstractModuleBase, public Singleton<PacketSniffer>
{
private:
	bool PacketSendIgnoreHeaders = false;
	bool PacketSendOnlyHeaders = false;
	bool PacketSendEnable = false;

	bool PacketRecvIgnoreHeaders = false;
	bool PacketRecvOnlyHeaders = false;
	bool PacketRecvEnable = false;

	bool PacketSendRecvIgnoreHeaders = false;
	bool PacketSendRecvOnlyHeaders = false;
	bool PacketSendRecvEnable = false;

public:
	bool  IsEnablePacketSend()
	{
		return PacketSendEnable;
	}
	bool  IsEnablePacketRecv()
	{
		return PacketRecvEnable;
	}


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
		ImGui::BeginChild("SniffernBorder", ImVec2(645, 445), true);
		ImGui::Checkbox("Send Enable", &PacketSendEnable);
		ImGui::Checkbox("Receive Enable", &PacketRecvEnable);
		ImGui::EndChild();
		ImGui::PopStyleVar();
	}


	void ProcessSendPacket(int len, void* pDestBuf)
	{
		BYTE header;
		memcpy(&header, pDestBuf, sizeof(header));
		BYTE* recvBuff = new BYTE[len];
		memcpy(recvBuff, pDestBuf, len);

		if (PacketSendEnable)
		{
			string headerName = sClientToServer[header];
			string packetHex = StringExtension::MakeHexString((BYTE*)pDestBuf, len, true, true);
			string ascii = StringExtension::BYTEToAsciiString(pDestBuf, len);
			ascii += "\n";
			string line = "[SEND][L:" + std::to_string(len) + "][" + headerName + "][" + packetHex + "]\n";
			MainForm::LogSniffer(0, line.c_str());
		
			MainForm::LogSniffer(0, ascii.c_str());
		}
	}
	void ProcessRecvPacket(int len, void* pDestBuf)
	{
		BYTE header;
		memcpy(&header, pDestBuf, sizeof(header));
		BYTE* recvBuff = new BYTE[len];
		memcpy(recvBuff, pDestBuf, len);

		if (header == 0x00)
		{
			return;
		}

		if (PacketRecvEnable)
		{
			string headerName = sServerToClient[header];
			string packetHex = StringExtension::MakeHexString((BYTE*)pDestBuf, len, true, true);
			string line = "[RECV][L:" + std::to_string(len) + "][" + headerName + "][" + packetHex + "]\n";
			string ascii = StringExtension::BYTEToAsciiString(pDestBuf, len);
			ascii += "\n";
			MainForm::LogSniffer(0, line.c_str());
			MainForm::LogSniffer(0, ascii.c_str());
		}
	}

};




