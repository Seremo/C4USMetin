#pragma once
class FileExtension
{
public:

	static string GetDirectoryPathFromFilePatch(string filePath)
	{
		string directory;
		const size_t last_slash_idx = filePath.rfind('\\');
		if (std::string::npos != last_slash_idx)
		{
			directory = filePath.substr(0, last_slash_idx);
		}
		return directory;
	}

	static string GetCurrentExeDirectory()
	{
		const unsigned long maxDir = 260;
		char currentDir[maxDir];
		/*GetCurrentDirectory(maxDir, (LPWSTR)currentDir);*/
		return string(currentDir);
	}

	static int ReadBYTEFileSize(const char* filename, int* read)
	{
		ifstream file(filename, ios::binary | ios::ate);
		return file.tellg();
	}

	static char* ReadAllBYTEs(const char* filename, int* read)
	{
		ifstream ifs(filename, ios::binary | ios::ate);
		ifstream::pos_type pos = ifs.tellg();
		int length = pos;
		char* pChars = new char[length];
		ifs.seekg(0, ios::beg);
		ifs.read(pChars, length);
		ifs.close();
		*read = length;
		return pChars;
	}
	static vector<char> ReadAllBYTEs(char const* filename)
	{
		ifstream ifs(filename, ios::binary | ios::ate);
		ifstream::pos_type pos = ifs.tellg();

		std::vector<char>  result(pos);

		ifs.seekg(0, ios::beg);
		ifs.read(&result[0], pos);

		return result;
	}

	static bool CreateDirectoryPath(const char* path)
	{
		/*if (CreateDirectory(StringExtension::GetWideChar(path), NULL) ||
			ERROR_ALREADY_EXISTS == GetLastError())
		{*/
		return true;
		/*}
		else
		{
			return false;
		}*/
	}

	static void Write(const std::string& file_name, void* data, int size)
	{
		std::ofstream out(file_name.c_str());
		out.write(reinterpret_cast<char*>(data), size);
		out.close();
	}

	static void Read(const std::string& file_name, void* data, int size)
	{
		std::ifstream in(file_name.c_str());
		in.read(reinterpret_cast<char*>(data), size);
		in.close();
	}
	static void ReadDirectory(const std::string& name, vector<string>& v) {
		std::string pattern(name);
		pattern.append("*");
		WIN32_FIND_DATAA data;
		HANDLE hFind;
		if ((hFind = FindFirstFileA(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
			do {
				v.push_back(data.cFileName);
			} while (FindNextFileA(hFind, &data) != 0);
			FindClose(hFind);
		}
	}
};

