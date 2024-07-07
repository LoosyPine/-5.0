#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
using namespace std;

int main()
{
	vector<int> v_output;
	int n;
	int k;
	vector<int> v_nums;
	vector<int> v_Left;
	vector<int> v_Right;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n;
	v_nums.resize(n);
	for (int i = 0; i < n; i++)
	{
		ifs >> v_nums[i];
	}
	sort(v_nums.begin(), v_nums.end());
	ifs >> k;
	v_output.resize(k);
	v_Left.resize(k);
	v_Right.resize(k);
	for (int j = 0; j < k; j++)
	{
		ifs >> v_Left[j];
		ifs >> v_Right[j];
		auto iterLeft = lower_bound(v_nums.begin(), v_nums.end(), v_Left[j]);
		auto iterRight = upper_bound(v_nums.begin(), v_nums.end(), v_Right[j]);
		int summCounts = 0;
		for (auto iter = iterLeft; iter != iterRight; ++iter)
		{
			++summCounts;
		}
		v_output[j] = summCounts;
	}
	ifs.close();
	ofstream ofs;
	ofs.open("output.txt");
	for (int i = 0; i < v_output.size(); i++)
	{
		ofs << v_output[i] << ' ';
	}
	ofs.close();
	return 0;
}