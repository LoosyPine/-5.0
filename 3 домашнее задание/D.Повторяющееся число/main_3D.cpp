#include <iostream>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <fstream>
#include <iterator>
#include <unordered_set>

using namespace std;

template<typename T>
void output(T& ans);

int main()
{
	string str_yes = "YES";
	string str_no = "NO";
	bool ans = false;
	int n, k;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n >> k;
	unordered_map<int, unordered_set<int>> m_numbers;
	for (int i=0; i<n; i++)
	{
		int temp;
		ifs >> temp;
		m_numbers[temp].insert(i);
		//cout << i << endl;
		if (m_numbers[temp].size() > 1)
		{
			for (int j : m_numbers[temp])
			{
				//cout << j << endl;
				for (int z : m_numbers[temp])
				{
					
					//cout << z << ' ';
					if (abs(z - j) <= k && abs(z - j) != 0)
					{
						output(str_yes);
						return 0;
					}
				}
				//cout << endl;
			}
		}
	}
	ifs.close();
	output(str_no);
	return 0;
}

template<typename T>
void output(T& ans)
{
	ofstream ofs;
	ofs.open("output.txt");
	ofs << ans;
	ofs.close();
}