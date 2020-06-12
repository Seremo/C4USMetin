#pragma once
class StringExtension
{
public:
	static const char* StringExtension::ConstCharJoin(const char* chr1, const char* chr2)
	{

		char result[sizeof(chr1) + sizeof(chr2)];
		strncpy(result, chr1, sizeof(result));
		strncat(result, chr2, sizeof(result));
		return result;
	}
	static string ReplaceString(std::string subject, const std::string& search, const std::string& replace)
	{
		size_t pos = 0;
		while ((pos = subject.find(search, pos)) != std::string::npos) {
			subject.replace(pos, search.length(), replace);
			pos += replace.length();
		}
		return subject;
	}
	static bool Contains(const std::string& sentence, const std::string& word)
	{
		string Original = sentence;
		string ToFind = word;
		std::transform(Original.begin(), Original.end(), Original.begin(), [](unsigned char c) { return tolower(c); });
		std::transform(ToFind.begin(), ToFind.end(), ToFind.begin(), [](unsigned char c) { return tolower(c); });
		return Original.find(ToFind) != std::string::npos;
	}

	static bool ContainsW(const std::wstring& sentence, const std::wstring& word)
	{
		return sentence.find(word)

			!= std::string::npos;
	}
	static bool Equals(const char* word1, const char* word2)
	{
		if (strcmp(word1, word2) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static unsigned char* BinToStrhex(const unsigned char* bin, unsigned int binsz, unsigned char** result)
	{
		unsigned char     hex_str[] = "0123456789ABCDEF";
		unsigned int      i;

		if (!(*result = (unsigned char*)malloc(binsz * 2 + 1)))
			return (NULL);

		(*result)[binsz * 2] = 0;

		if (!binsz)
			return (NULL);

		for (i = 0; i < binsz; i++)
		{
			(*result)[i * 2 + 0] = hex_str[(bin[i] >> 4) & 0x0F];
			(*result)[i * 2 + 1] = hex_str[(bin[i]) & 0x0F];
		}
		return (*result);
	}

	static string MakeHexString(BYTE* data, int len, bool use_uppercase = true, bool insert_spaces = false)
	{
		std::ostringstream ss;
		ss << std::hex << setfill('0');
		if (use_uppercase)
			ss << std::uppercase;
		for (int i = 0; i < len; ++i)
		{
			ss << setw(2) << static_cast<int>(data[i]);
			if (insert_spaces)
				ss << " ";
		}
		return ss.str();
	}
	static string BYTEToHex(BYTE BYTE)
	{
		ostringstream ss;
		ss << std::hex << setfill('0');
		ss << std::uppercase;
		//ss << "0x";
		ss << setw(2) << static_cast<int>(BYTE);
		return ss.str();
	}
	static string StringFormat(const string fmt_str, ...)
	{
		int final_n, n = ((int)fmt_str.size()) * 2;
		unique_ptr<char[]> formatted;
		va_list ap;
		while (1) {
			formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
			strcpy(&formatted[0], fmt_str.c_str());
			va_start(ap, fmt_str);
			final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
			va_end(ap);
			if (final_n < 0 || final_n >= n)
				n += abs(final_n - n + 1);
			else
				break;
		}
		return string(formatted.get());
	}
	static const char* StringFormatChar(const string fmt_str, ...)
	{
		int final_n, n = ((int)fmt_str.size()) * 2;
		unique_ptr<char[]> formatted;
		va_list ap;
		while (1) {
			formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
			strcpy(&formatted[0], fmt_str.c_str());
			va_start(ap, fmt_str);
			final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
			va_end(ap);
			if (final_n < 0 || final_n >= n)
				n += abs(final_n - n + 1);
			else
				break;
		}
		return string(formatted.get()).c_str();
	}
	static string BYTEToAsciiString(void* data, int len)
	{

		string ret = "";
		BYTE* dataBuff = new BYTE[len];
		memcpy(dataBuff, data, len);
		for (int j = 0; j < len; j++)
		{

			if (dataBuff[j] > 32 && dataBuff[j] < 127)
			{
				ret += (char)dataBuff[j];
			}
			else
			{
				ret += ".";
			}

		}


		return ret;

		//return string(reinterpret_cast<char const*>(data), len);
	}

	static const wchar_t* GetWideChar(const char* c)
	{
		const size_t cSize = strlen(c) + 1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs(wc, c, cSize);

		return wc;
	}

	static LPWSTR  GetLPWSTR(const char* c)
	{
		const size_t cSize = strlen(c) + 1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs(wc, c, cSize);

		return wc;
	}
	static const wchar_t* GetWCharFromString(string c)
	{
		std::wstring stemp = std::wstring(c.begin(), c.end());
		return  stemp.c_str();
	}
	static const char* ConstCharFromWChar(TCHAR* tch)
	{
		/*wstring ws = wstring(tch);
		string s(ws.begin(), ws.end());
		return s.c_str();*/
		return "";
	}
	static string StringFromWChar(TCHAR* tch)
	{
		/*wstring ws = wstring(tch);
		string s(ws.begin(), ws.end());
		return s;*/
		return "";;
	}

	static string StringFromWString(wstring ws)
	{
		string s(ws.begin(), ws.end());
		return s;
	}

	static vector<std::string> Split(std::string src, char delim)
	{
		std::vector <std::string> ret;
		std::string tempval;
		for (std::string::iterator i = src.begin(); i < src.end(); i++)
		{
			if (*i == delim)
			{
				ret.push_back(tempval);
				tempval.clear();
			}
			else
				tempval.push_back(*i);
		}
		return ret;
	}

	static string DWORDToHexString(DWORD intValue) {

		string hexStr;


		std::stringstream sstream;
		sstream << "0x"
			<< std::setfill('0') << std::setw(2)
			<< std::hex << (DWORD)intValue;

		hexStr = sstream.str();
		sstream.clear();

		return hexStr;
	}


	static vector<char>HexToBytes(std::string& hex) {
		std::vector<char> bytes;
		hex = StringExtension::ReplaceString(hex, " ", "");

		for (unsigned int i = 0; i < hex.length(); i += 2) {
			std::string byteString = hex.substr(i, 2);
			char byte = (char)strtol(byteString.c_str(), NULL, 16);
			bytes.push_back(byte);
		}

		return bytes;
	}


	static char* UTF8ToANSI(char* szU8)
	{
		int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0);
		wchar_t* wszString = new wchar_t[wcsLen + 1];
		::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen);
		wszString[wcsLen] = '\0';

		int ansiLen = ::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), NULL, 0, NULL, NULL);
		char* szAnsi = new char[ansiLen + 1];
		::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), szAnsi, ansiLen, NULL, NULL);
		szAnsi[ansiLen] = '\0';

		return szAnsi;
	}
};

