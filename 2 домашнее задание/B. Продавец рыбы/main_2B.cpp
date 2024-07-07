#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template<typename T>
void output(T& ans);

int main()
{
	int n;
	int k;
	vector<int> v_price;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n;
	ifs >> k;
	v_price.resize(n);
	for (int i = 0; i < n; i++)
	{
		ifs >> v_price[i];
	}
	ifs.close();
	int max = 0;
	if (n == k)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (v_price[j] - v_price[i] > max)
				{
					max = v_price[j] - v_price[i];
				}
			}
		}
	}
	else
	{
		for (int i = 0; i <= (n - k - 1); i++)
		{
			for (int j = i + 1; j <= (i + k); j++)
			{
				if (v_price[j] - v_price[i] > max)
				{
					max = v_price[j] - v_price[i];
				}
			}
		}
		for (int i = (n - k); i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (v_price[j] - v_price[i] > max)
				{
					max = v_price[j] - v_price[i];
				}
			}
		}
	}
	if (max < 0)
		max = 0;
	output(max);
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
 