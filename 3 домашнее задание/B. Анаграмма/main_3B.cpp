#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

template<typename T>
void output(T& ans);

int main()
{
	string ans = "NO";
	string wordOne;
	string wordTwo;
	map<char, int> m_wordOneBook;
	map<char, int> m_wordTwoBook;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> wordOne;
	ifs >> wordTwo;
	ifs.close();
	if (wordOne.size() == wordTwo.size())
	{
		for (int i = 0; i < wordOne.size(); i++)
		{
			++m_wordOneBook[wordOne[i]];
			++m_wordTwoBook[wordTwo[i]];
		}
		auto iterOne = m_wordOneBook.begin();
		auto iterTwo = m_wordTwoBook.begin();
		if (m_wordOneBook.size() == m_wordTwoBook.size())
		{
			int check = 0;
			for (int i = 0; i < m_wordOneBook.size(); i++)
			{
				if (*iterOne == *iterTwo)
				{
					++check;
				}
				++iterOne;
				++iterTwo;
			}
			if (check == m_wordOneBook.size())
			{
				ans = "YES";
			}
		}
	}
	output(ans);
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