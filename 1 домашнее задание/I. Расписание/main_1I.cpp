#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string transOutDay(int& day);
int transMonth(string& month);
int transDay(string& day);

int main()
{
	bool febHelp = 0;
	int n;
	int year;
	vector<int> v_day;
	vector<int> v_month;
	vector<int> v_monthSpec(13);
	vector<int> v_monthStartDay(13);
	vector<int> v_daysCounts(8);
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n;
	v_day.resize(n);
	v_month.resize(n);
	ifs >> year;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		febHelp = 1;
	}
	v_monthSpec = { -1, 31, 28 + febHelp, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	v_daysCounts = {-1, 52, 52, 52, 52, 52, 52, 52};
	string temp;
	for (int i = 0; i < n; i++)
	{
		ifs >> v_day[i];
		ifs >> temp;
		v_month[i] = transMonth(temp);
	}
	ifs >> temp;
	v_monthStartDay[1] = transDay(temp);
	v_daysCounts[v_monthStartDay[1]] += 1;
	int tempNextDayID = v_monthStartDay[1] + 1;
	if (tempNextDayID > 7)
	{
		tempNextDayID %= 7;
	}
	v_daysCounts[tempNextDayID] += febHelp;
	for (int i = 2; i <= 12; i++)
	{
		int tempDay;
		if (v_monthSpec[i - 1] == 31)
		{
			tempDay = v_monthStartDay[i - 1] + 3;
		}
		else if (v_monthSpec[i - 1] == 30)
		{
			tempDay = v_monthStartDay[i - 1] + 2;
		}
		else if (v_monthSpec[i - 1] == 29)
		{
			tempDay = v_monthStartDay[i - 1] + 1;
		}
		else
		{
			tempDay = v_monthStartDay[i - 1];
		}
		if (tempDay > 7)
		{
			tempDay = tempDay % 7;
		}
		v_monthStartDay[i] = tempDay;
	}
	ifs.close();
	for (int i = 0; i < n; i++)
	{
		int needDay = (v_day[i] + (v_monthStartDay[v_month[i]] - 1)) % 7;
		if (needDay == 0)
		{
			needDay = 7;
		}
		--v_daysCounts[needDay];
	}
	int max = 0;
	int maxTemp = -1;
	for (int i = 1; i <= 7; i++)
	{
		if (v_daysCounts[i] > maxTemp)
		{
			maxTemp = v_daysCounts[i];
			max = i;
		}
	}
	int min = 0;
	int minTemp = 100;
	for (int i = 1; i <= 7; i++)
	{
		if (v_daysCounts[i] < minTemp)
		{
			minTemp = v_daysCounts[i];
			min = i;
		}
	}
	/*if (n == 0)
	{
		min += 2;
		if (min > 7)
		{
			min -= 7;
		}
	}*/
	/*for (int i = 1; i <= 7;  i++)
	{
		cout << v_daysCounts[i] << endl;
	}*/
	string strMax = transOutDay(max);
	string strMin = transOutDay(min);
	char space = ' ';
	ofstream ofs;
	ofs.open("output.txt");
	ofs << strMax;
	ofs << space;
	ofs << strMin;
	ofs.close();
	return 0;
}

string transOutDay(int& day)
{
	if (day == 1)
	{
		return "Monday";
	}
	else if (day == 2)
	{
		return "Tuesday";
	}
	else if (day == 3)
	{
		return "Wednesday";
	}
	else if (day == 4)
	{
		return "Thursday";
	}
	else if (day == 5)
	{
		return "Friday";
	}
	else if (day == 6)
	{
		return "Saturday";
	}
	else if (day == 7)
	{
		return "Sunday";
	}
	return string();
}

int transMonth(string& month)
{
	if (month == "January")
	{
		return 1;
	}
	else if (month == "February")
	{
		return 2;
	}
	else if (month == "March")
	{
		return 3;
	}
	else if (month == "April")
	{
		return 4;
	}
	else if (month == "May")
	{
		return 5;
	}
	else if (month == "June")
	{
		return 6;
	}
	else if (month == "July")
	{
		return 7;
	}
	else if (month == "August")
	{
		return 8;
	}
	else if (month == "September")
	{
		return 9;
	}
	else if (month == "October")
	{
		return 10;
	}
	else if (month == "November")
	{
		return 11;
	}
	else if (month == "December")
	{
		return 12;
	}
	return 0;
}

int transDay(string& day)
{
	if (day == "Monday")
	{
		return 1;
	}
	else if (day == "Tuesday")
	{
		return 2;
	}
	else if (day == "Wednesday")
	{
		return 3;
	}
	else if (day == "Thursday")
	{
		return 4;
	}
	else if (day == "Friday")
	{
		return 5;
	}
	else if (day == "Saturday")
	{
		return 6;
	}
	else if (day == "Sunday")
	{
		return 7;
	}

	return 0;
}
