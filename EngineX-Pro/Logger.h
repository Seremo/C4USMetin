#pragma once
class Logger
{
public:
	enum
	{
		MAIN,
		FISH,
		SNIFFER,
		
	};

	enum
	{
		RED,
		BLACK,
		BLUE,
		GREEN,
		WHITE,
		PINK,
		YELLOW
	};

	class LogWindow
	{
		enum
		{
			RED,
			BLACK,
			BLUE,
			GREEN,
			WHITE,
			PINK,
			YELLOW
		};
		class LogLine
		{
		public:
			vector<ImVec4> colors;
			vector<string> text;
		};
	public:	
		LogWindow()
		{
			logLines.push_back(std::make_shared < LogLine>());
		}
		vector< std::shared_ptr<LogLine>> logLines;
		bool                ScrollToBottom;
	
		ImVec4	GetColor(int color)
		{
			switch (color)
			{
			case RED:
				return ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
				break;
			case BLACK:
				return ImVec4(0.3f, 1.0f, 0.0f, 1.0f);
				break;
			case GREEN:
				return ImVec4(0.3f, 1.0f, 1.0f, 1.0f);
				break;
			case WHITE:
				return ImVec4(1.0f, 0.0f, 1.0f, 1.0f);
				break;

			case YELLOW:
				return ImVec4(1.0f, 1.0f, 0.0f, 1.0f);
				break;
			case PINK:
				return ImVec4(1.0f, 0.0f, 1.0f, 1.0f);
				break;
			
				break;
			}
		}
		void Clear()
		{
			logLines.clear();
			logLines.push_back(std::make_shared < LogLine>());
		}

		void Log(bool isNewLine, int color, const char* fmt, ...)
		{
			va_list args;

			va_start(args, fmt);
			string  log = StringExtension::StringFormat(fmt, args);
			va_end(args);

			logLines[logLines.size()-1]->colors.push_back(GetColor(color));
			logLines[logLines.size() - 1]->text.push_back(log);
			if (isNewLine)
			{
				logLines.push_back(std::make_shared < LogLine>());
			}
			else
			{
				
			}

			/*va_list args;
			va_start(args, fmt);
			Buf.appendfv(fmt, args);
			va_end(args);*/



			
			ScrollToBottom = true;
		}
		void Draw(const char* title, bool* isOpen = NULL)
		{
			ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_FirstUseEver);
			if (!ImGui::Begin(title, isOpen))
			{
				ImGui::End();
				return;
			}
			if (ImGui::Button("Clear")) Clear();
			ImGui::SameLine();
			bool copy = ImGui::Button("Copy");
			ImGui::SameLine();
			/*Filter.Draw("Filter", -100.0f);*/
			ImGui::Separator();
			ImGui::BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
			if (copy)
			{
				ImGui::LogToClipboard();
			}

			for (std::vector< std::shared_ptr< LogLine>>::iterator it = logLines.begin(); it != logLines.end(); ++it)
			{
				for (int i = 0; i < it->get()->text.size(); i++)
				{
					if(i)
					{
						ImGui::SameLine();
					}
					
					ImGui::TextColored(it->get()->colors[i], it->get()->text[i].c_str());
				}
				/*ImGui::TextColored(ImVec4(0.0f, 0.0f, 0.0f, 1.0f),"\n");*/
			}
			

			if (ScrollToBottom)
			{
				ImGui::SetScrollHere(1.0f);
			}
				
			ScrollToBottom = false;
			ImGui::EndChild();
			ImGui::End();
		}
	};
private:
	static LogWindow snifferLogWindow;

	static LogWindow mainLogWindow;

	static LogWindow fishLogWindow;

	static const char* snifferLogWindowTitle;
	static const char* mainLogWindowTitle;
	static const char* fishLogWindowTitle;

	static bool isSnifferLogWindowOpen;
	static bool  isMainLogWindowOpen;
	static bool  isFishLogWindowOpen;
	public:
	
	static void AddString(int window, bool isNewLine, int color, string format, ...)
	{
		va_list args;
		
		va_start(args, format);
		Add(window, isNewLine, color, format.c_str(), args);
		va_end(args);
	}
	static void Add(int window, bool isNewLine, int color, const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		string frm = StringExtension::StringFormat(format, args);
		format = frm.c_str();
		switch (window)
		{
		case MAIN:
			mainLogWindow.Log(isNewLine, color, format/*, args*/);
			
			break;
		case FISH:
			fishLogWindow.Log(isNewLine, color, format/*, args*/);
			
			break;
		case SNIFFER:
			snifferLogWindow.Log(isNewLine, color, format/*, args*/);
			
			break;
		}
		

		va_end(args);
	}
	
	static void Draw(int window)
	{
		
		switch (window)
		{
		case MAIN:
			mainLogWindow.Draw(mainLogWindowTitle, &isMainLogWindowOpen);
			break;
		case FISH:
			fishLogWindow.Draw(fishLogWindowTitle, &isSnifferLogWindowOpen);
			break;
		case SNIFFER:
			snifferLogWindow.Draw(snifferLogWindowTitle, &isFishLogWindowOpen);
			break;
		}
	}

	

};

const char* Logger::snifferLogWindowTitle = "Sniffer";
const char* Logger::mainLogWindowTitle = "Main";
const char* Logger::fishLogWindowTitle = "Fish";

bool Logger::isSnifferLogWindowOpen = true;
bool  Logger::isMainLogWindowOpen = true;
bool  Logger::isFishLogWindowOpen = true;

Logger::LogWindow Logger::snifferLogWindow;
Logger::LogWindow Logger::mainLogWindow;
Logger::LogWindow Logger::fishLogWindow;