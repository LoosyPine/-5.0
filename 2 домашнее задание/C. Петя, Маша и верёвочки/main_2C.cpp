#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

void output(int& ans);

int main()
{
	int n;
	int summ = 0;
	int ans;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n;
	vector<int> v_rope(n);
	for (int i = 0; i < n; i++)
	{
		ifs >> v_rope[i];
		summ += v_rope[i];
	}
	ifs.close();
	sort(v_rope.begin(), v_rope.end());
	summ -= v_rope[n - 1];
	if (summ < v_rope[n - 1])
	{
		ans = v_rope[n - 1] - summ;
		output(ans);
		return 0;
	}
	else
	{
		ans = summ + v_rope[n - 1];
		output(ans);
		return 0;
	}
	return 0;
}



void output(int& ans)
{
	ofstream ofs;
	ofs.open("output.txt");
	ofs << ans;
	ofs.close();
}