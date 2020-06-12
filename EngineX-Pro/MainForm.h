#pragma once

class MainForm
{
public:
	MainForm();
	~MainForm();

	static size_t CurTabOpen ;
	static size_t CurMenuOpen;
	static bool IsInitialized;
	static bool SideBarIsOpen;
	static bool ShowFishLog;

	static bool IsRadarHovered;
	static void AddTab(size_t Index, const char* Text, size_t Index2 = 0);
	static void AddMenu(size_t Index, const char* Text, size_t Index2 = 0);




	static void Initialize();
	static void ShowRadar();
	static void Menu();

	static void SetImages();

	static DirectTexture LogoHref;
	static DirectTexture Background;
	static DirectTexture WindowOn;
	static DirectTexture WindowOff;
	static DirectTexture RadarOn;
	static DirectTexture RadarOff;
	static DirectTexture MHOn;
	static DirectTexture MHOff;
	static DirectTexture AutologinOn;
	static DirectTexture AutologinOff;
	static DirectTexture FishbotOn;
	static DirectTexture FishbotOff;
	static DirectTexture ExitGameIcon;
	static DirectTexture ChannelChangerIcon;

	static DirectTexture ninja_a_0;
	static DirectTexture ninja_a_1;
	static DirectTexture ninja_a_2;
	static DirectTexture ninja_a_3;
	static DirectTexture ninja_a_4;
	static DirectTexture ninja_a_5;

	static DirectTexture ninja_d_0;
	static DirectTexture ninja_d_1;
	static DirectTexture ninja_d_2;
	static DirectTexture ninja_d_3;
	static DirectTexture ninja_d_4;
	static DirectTexture ninja_d_5;

	static DirectTexture shaman_d_0;
	static DirectTexture shaman_d_1;
	static DirectTexture shaman_d_2;
	static DirectTexture shaman_d_3;
	static DirectTexture shaman_d_4;
	static DirectTexture shaman_d_5;

	static DirectTexture shaman_h_0;
	static DirectTexture shaman_h_1;
	static DirectTexture shaman_h_2;
	static DirectTexture shaman_h_3;
	static DirectTexture shaman_h_4;
	static DirectTexture shaman_h_5;

	static DirectTexture sura_b_0;
	static DirectTexture sura_b_1;
	static DirectTexture sura_b_2;
	static DirectTexture sura_b_3;
	static DirectTexture sura_b_4;
	static DirectTexture sura_b_6;

	static DirectTexture sura_w_0;
	static DirectTexture sura_w_1;
	static DirectTexture sura_w_2;
	static DirectTexture sura_w_3;
	static DirectTexture sura_w_4;
	static DirectTexture sura_w_5;

	static DirectTexture warrior_b_0;
	static DirectTexture warrior_b_1;
	static DirectTexture warrior_b_2;
	static DirectTexture warrior_b_3;
	static DirectTexture warrior_b_4;
	static DirectTexture warrior_b_5;

	static DirectTexture warrior_m_0;
	static DirectTexture warrior_m_1;
	static DirectTexture warrior_m_2;
	static DirectTexture warrior_m_3;
	static DirectTexture warrior_m_4;
	static DirectTexture warrior_m_5;

	static DirectTexture skill_none;
	static DirectTexture skill_on;
	static DirectTexture skill_off;
	
	//
	//
	
	//
	struct orbital_logs_t
	{
		ImGuiTextBuffer     Buf;
		ImGuiTextFilter     Filter;
		ImVector<int>       LineOffsets;
		bool                ScrollToBottom;

		void Clear()
		{
			Buf.clear();
			LineOffsets.clear();
		}

		void Log(const char* fmt, ...) IM_FMTARGS(2)
		{
			int old_size = Buf.size();
			va_list args;
			va_start(args, fmt);
			Buf.appendfv(fmt, args);
			va_end(args);
			for (int new_size = Buf.size(); old_size < new_size; old_size++)
				if (Buf[old_size] == '\n')
					LineOffsets.push_back(old_size);
			ScrollToBottom = true;
		}

		void Log(char c)
		{
			ImVector<char>& chars = Buf.Buf;
			if (c == '\n')
				LineOffsets.push_back(Buf.size());
			chars.push_back(c);
			ScrollToBottom = true;
		}

		void Draw(const char* title, bool* p_open = NULL)
		{
			ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_FirstUseEver);
			if (!ImGui::Begin(title, p_open)) {
				ImGui::End();
				return;
			}
			if (ImGui::Button("Clear")) Clear();
			ImGui::SameLine();
			bool copy = ImGui::Button("Copy");
			ImGui::SameLine();
			Filter.Draw("Filter", -100.0f);
			ImGui::Separator();
			ImGui::BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
			if (copy) ImGui::LogToClipboard();

			if (Filter.IsActive()) {
				const char* buf_begin = Buf.begin();
				const char* line = buf_begin;
				for (int line_no = 0; line != NULL; line_no++) {
					const char* line_end = (line_no < LineOffsets.Size) ? buf_begin + LineOffsets[line_no] : NULL;
					if (Filter.PassFilter(line, line_end))
						ImGui::TextUnformatted(line, line_end);
					line = line_end && line_end[1] ? line_end + 1 : NULL;
				}
			}
			else {
				ImGui::TextUnformatted(Buf.begin());
			}

			if (ScrollToBottom)
				ImGui::SetScrollHere(1.0f);
			ScrollToBottom = false;
			ImGui::EndChild();
			ImGui::End();
		}
	};

	typedef struct OrbitalUI {
		struct orbital_logs_t* logs_sniffer;
		struct orbital_logs_t* logs_chat;
		struct orbital_logs_t* logs_fishing;
		struct orbital_logs_t* logs_char;
		struct orbital_logs_t* logs_main;
	} OrbitalUI;

	static OrbitalUI ui;

	static struct orbital_logs_t* orbital_logs_create(void)
	{
		struct orbital_logs_t* logs;

		logs = new orbital_logs_t();
		return logs;
	}

	static void orbital_logs_destroy(struct orbital_logs_t* logs)
	{
		delete logs;
	}

	static void orbital_logs_clear(struct orbital_logs_t* logs)
	{
		logs->Clear();
	}

	static void orbital_logs_draw(struct orbital_logs_t* logs, const char* title, bool* p_open)
	{
		logs->Draw(title, p_open);
	}

	static void orbital_logs_logchr(struct orbital_logs_t* logs, const char* chr)
	{
		logs->Log(chr);
	}

	static void LogSniffer(int index, const char* ch)
	{
		(void)index; // Unused
		orbital_logs_logchr(ui.logs_sniffer, ch);
	}
	static void LogMain(int index, const char* ch)
	{
		(void)index; // Unused
		orbital_logs_logchr(ui.logs_main, ch);
	}
	static void orbital_log_chat(int index, const char* ch)
	{
		(void)index; // Unused
		orbital_logs_logchr(ui.logs_chat, ch);
	}

	static void LogFish(int index, const char* ch)
	{
		(void)index; // Unused
		orbital_logs_logchr(ui.logs_fishing, ch);
	}

	static void orbital_log_char(int index, const char* ch)
	{
		(void)index; // Unused
		orbital_logs_logchr(ui.logs_char, ch);
	}
	static void OrbitalLogs(OrbitalUI* ui);
};
