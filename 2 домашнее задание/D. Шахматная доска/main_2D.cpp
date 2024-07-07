#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

void output(int& ans);

int main()
{
	int p = 0;
	ifstream ifs;
	ifs.open("input.txt");
	int n;
	ifs >> n;
	p = (n * 4);
	vector<int> v_x(n);
	vector<int> v_y(n);
	for (int i = 0; i < n; i++)
	{
		ifs >> v_y[i];
		ifs >> v_x[i];
	}
	ifs.close();
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v_x[i] == v_x[j] && (abs(v_y[i] - v_y[j]) == 1))
			{
				p -= 1;

			}
			else if (v_y[i] == v_y[j] && (abs(v_x[i] - v_x[j]) == 1))
			{
				p -= 1;
			}
		}
		for (int l = i - 1; l >=0; l--)
		{
			if (v_x[i] == v_x[l] && (abs(v_y[i] - v_y[l]) == 1))
			{
				p -= 1;

			}
			else if (v_y[i] == v_y[l] && (abs(v_x[i] - v_x[l]) == 1))
			{
				p -= 1;
			}
		}
	}
	output(p);
	return 0;
}



void output(int& ans)
{
	ofstream ofs;
	ofs.open("output.txt");
	ofs << ans;
	ofs.close();
}