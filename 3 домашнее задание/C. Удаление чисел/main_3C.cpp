#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>


using namespace std;

int main()
{
	int n;
	map<int, int> m_number;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		ifs >> temp;
		++m_number[temp];
	}
	int max = 0;
	auto iterStart = next(m_number.begin(), 1);
	for (auto i = iterStart; i != m_number.end(); i++)
	{
		auto x = prev(i, 1);
		if (abs(i->first - x->first) <= 1)
		{
			if (i->second + x->second > max)
			{
				max = i->second + x->second;
			}
		}
	}
	int ans = n - max;
	if (ans == n)
	{
		if (m_number.size() == 1)
			ans = 0;
		else
			ans = n - 1;
	}
	ifs.close();
	ofstream ofs;
	ofs.open("output.txt");
	ofs << ans << endl;
	ofs.close();
	return 0;
}