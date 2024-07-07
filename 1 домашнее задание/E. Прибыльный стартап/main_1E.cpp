#include <iostream>
#include <fstream>

using namespace std;

void output(int& ans);

int main()
{
	int n;
	int k;
	int d;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n;
	ifs >> k;
	ifs >> d;
	ifs.close();

	ofstream ofs;
	ofs.open("output.txt");
	int temp;
	for (int i = 0; i <= 9; i++)
	{
		temp = n * 10;
		temp += i;
		if (temp % k == 0)
		{
			ofs << temp;
			--d;
			break;
		}
		else if (i == 9)
		{
			temp = -1;
			ofs << temp;
			return 0;
		}
	}
	if (d > 0)
	{
		for (int i = 0; i < d; i++)
		{
			int zero = 0;
			ofs << zero;
		}
	}
	ofs.close();
	return 0;
}
