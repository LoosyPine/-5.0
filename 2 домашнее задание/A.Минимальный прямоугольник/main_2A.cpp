#include <iostream>
#include <vector>
#include <fstream>


using namespace std;


int main()
{
	int n;
	int minX = 10000000;
	int maxX = 0;
	int minY = 10000000;
	int maxY = 0;
	vector<int> v_x;
	vector<int> v_y;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> n;
	v_x.resize(n);
	v_y.resize(n);
	for (int i = 0; i < n; i++)
	{
		ifs >> v_x[i];
		ifs >> v_y[i];
		if (minX > v_x[i])
		{
			minX = v_x[i];
		}
		if (maxX < v_x[i])
		{
			maxX = v_x[i];
		}
		if (minY > v_y[i])
		{
			minY = v_y[i];
		}
		if (maxY < v_y[i])
		{
			maxY = v_y[i];
		}
	}
	ifs.close();
	ofstream ofs;
	ofs.open("output.txt");
	ofs << minX;
	ofs << ' ';
	ofs << minY;
	ofs << ' ';
	ofs << maxX;
	ofs << ' ';
	ofs << maxY;
	ofs.close();
	return 0;
}