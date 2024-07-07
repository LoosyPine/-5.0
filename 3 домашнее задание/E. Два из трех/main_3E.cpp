#include <iostream>
#include <unordered_map>
#include <map>
#include <cmath>
#include <vector>
#include <fstream>
#include <iterator>
#include <unordered_set>
#include <set>

using namespace std;

int main()
{
	set<int> us_ans;
	int n;
	map<int, int> m_numbers;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		ifs >> temp;
		m_numbers.try_emplace(temp, 1);
	}
	ifs >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		ifs >> temp;
		auto iterFind = m_numbers.find(temp);
		if (iterFind != m_numbers.end() && iterFind->second != 2)
		{
			us_ans.insert(temp);
			continue;
		}
		m_numbers.try_emplace(temp, 2);
	}
	ifs >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		ifs >> temp;
		auto iterFind = m_numbers.find(temp);
		if (iterFind != m_numbers.end() && iterFind->second != 3)
		{
			us_ans.insert(temp);
			continue;
		}
		m_numbers.try_emplace(temp, 3);
	}
	ifs.close();
	ofstream ofs;
	ofs.open("output.txt");
	for (int i : us_ans)
	{
		ofs << i << ' ';
	}
	ofs.close();
	return 0;
}