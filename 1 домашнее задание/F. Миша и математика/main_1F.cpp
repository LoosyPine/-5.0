#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	int n;
	bool one_state = false;
	bool zero_state = false;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n;
	vector<int> v_num(n);
	vector<char> v_ans;
	for (int i = 0; i < n; i++)
	{
		ifs >> v_num[i];
	}
	ifs.close();
	
	for (int i = 1; i < n; i++)
	{
		if ((v_num[i - 1] % 2 != 0) && (v_num[i] % 2 != 0))
		{
			v_num[i] *= v_num[i - 1];
			v_ans.push_back(120);
		}
		else if ((v_num[i - 1] % 2 == 0) && (v_num[i] % 2 == 0))
		{
			v_num[i] *= v_num[i - 1];
			v_ans.push_back(120);
		}
		else
		{
			v_num[i] += v_num[i - 1];
			v_ans.push_back(43);
		}
	}

	ofstream ofs;
	ofs.open("output.txt");
	for (int i = 0; i < v_ans.size(); i++)
	{
		ofs << v_ans[i];
	}
	ofs.close();
	return 0;
}