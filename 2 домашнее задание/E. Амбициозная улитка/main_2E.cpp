#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	long long sum = 0;
	long long n;
	long long sizeVecID = 0;
	long long sizeVecLowID = 0;
	vector<long long> v_day;
	vector<long long> v_night;
	vector<long long> v_ID;
	vector<long long> v_low_ID;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n;
	v_day.resize(n);
	v_night.resize(n);
	for (long long i = 0; i < n; i++)
	{
		ifs >> v_day[i];
		ifs >> v_night[i];
		if (v_day[i] - v_night[i] >= 0)
		{
			sum += v_day[i] - v_night[i];
			v_ID.push_back(i);
			++sizeVecID;
		}
		else
		{
			v_low_ID.push_back(i);
			++sizeVecLowID;
		}
	}
	ifs.close();
	v_ID.resize(sizeVecID);
	v_low_ID.resize(sizeVecLowID);
	long long maxSum = sum;
	long long maxID = -1;
	if (sizeVecID > 0)
	{
		for (long long i = 0; i < sizeVecID; i++)
		{
			long long temp = sum;
			temp += v_night[v_ID[i]];
			if (temp > maxSum)
			{
				maxSum = temp;
				maxID = i;
			}
		}
	}
	bool check = false;
	long long maxLowID = 0;
	if (sizeVecLowID > 0)
	{
		for (long long i = 0; i < sizeVecLowID; i++)
		{
			long long temp = sum;
			temp += v_day[v_low_ID[i]];
			if (temp > maxSum)
			{
				maxSum = temp;
				maxLowID = i;
				check = true;
			}
		}
	}
	if (check == true)
	{
		long long tempB = v_low_ID[0];
		v_low_ID[0] = v_low_ID[maxLowID];
		v_low_ID[maxLowID] = tempB;
	}
	else
	{
		long long tempA = v_ID[sizeVecID - 1];
		v_ID[sizeVecID - 1] = v_ID[maxID];
		v_ID[maxID] = tempA;
	}
	ofstream ofs;
	ofs.open("output.txt");
	ofs << maxSum << endl;
	for (long long i = 0; i < v_ID.size(); i++)
	{
		ofs << v_ID[i] + 1 << ' ';
	}
	for (long long i = 0; i < v_low_ID.size(); i++)
	{
		ofs << v_low_ID[i] + 1 << ' ';
	}
	ofs.close();
	return 0;
}