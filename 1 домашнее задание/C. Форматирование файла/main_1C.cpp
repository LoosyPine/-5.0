#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void output(long long int& ans);

int main()
{
	long long int ans = 0;
	int n;
	vector<int> v_num;
	enum e_Keys { Tab = 4 };
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n;
	v_num.resize(n);
	for (int i = 0; i < n; i++)
		ifs >> v_num[i];
	ifs.close();

	for (int i = 0; i < n; i++)
	{
		ans += v_num[i] / Tab;
		if (v_num[i] % Tab == 1)
			ans += 1;
		else if ((v_num[i] % Tab == 2) || (v_num[i] % Tab == 3))
			ans += 2;
	}
	output(ans);
	return 0;
}

void output(long long int& ans)
{
	ofstream ofs;
	ofs.open("output.txt");
	ofs << ans;
	ofs.close();
}