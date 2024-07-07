#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	int n;
	int ansCount = 0;
	map<string, int> m_songs;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n;
	for (int i = 0; i < n; i++)
	{
		int count;
		ifs >> count;
		for (int j = 0; j < count; j++)
		{
			string temp;
			ifs >> temp;
			++m_songs[temp];
		}
	}
	ifs.close();
	ofstream ofs;
	ofs.open("output.txt");
	for (const auto& i : m_songs)
	{
		if (i.second == n)
		{
			++ansCount;
		}
	}
	ofs << ansCount << endl;
	for (const auto& i : m_songs)
	{
		//cout << i.first << ' ' << i.second << endl;
		if (i.second == n)
		{
			ofs << i.first << ' ';
		}
	}
	ofs.close();
	return 0;
}