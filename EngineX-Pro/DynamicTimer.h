#pragma once
class DynamicTimer
{
	static map< string, DWORD> timersList;
public:
	static bool Check(string timerName,DWORD timeMiliseconds)
	{
		if (timersList.count(timerName))
		{
			if (GetTickCount() - timersList[timerName] > timeMiliseconds)
			{
				timersList[timerName] = GetTickCount();
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			timersList.insert(std::make_pair(timerName, GetTickCount()));
			return true;
		}
		
	}
};

 map< string, DWORD> DynamicTimer::timersList;