#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

long long BinFind(const vector<long long>& vec, const long long& delta, const long long& need_num);

int main()
{
	vector<long long>v_num;
	vector<long long> v_pre;
	vector<long long> v_ans;
	long long n, k;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n >> k;
	v_num.resize(n + 2, 0);
	v_pre.resize(n + 2, 0);
	v_ans.resize(k);
	for (long long i = 1; i < v_num.size() - 1; i++)
	{
		ifs >> v_num[i];
		v_pre[i] = v_pre[i - 1] + v_num[i];
	}
	for (long long j = 0; j < k; j++)
	{
		long long groups;
		long long units;
		ifs >> groups >> units;
		v_ans[j] = BinFind(v_pre, groups, units);
	}
	ifs.close();
	ofstream ofs;
	ofs.open("output.txt");
	for (long long i = 0; i < v_ans.size(); i++)
		ofs << v_ans[i] << endl;
	ofs.close();
	return 0;
}

long long BinFind(const vector<long long>& vec, const long long& delta, const long long& need_num)
{
	long long l = 0;
	long long r = vec.size() - delta - 1;
	long long mid = 0;
	long long temp_num = 0;
	while (l < r)
	{
		mid = l + ((r - l) / 2);
		temp_num = vec[mid + delta] - vec[mid];
		if (temp_num == need_num)
			return mid + 1;
		if (temp_num > need_num)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return -1;
}