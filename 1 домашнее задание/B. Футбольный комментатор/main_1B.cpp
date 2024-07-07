#include <iostream>
#include <fstream>

using namespace std;

void output(int ans);

int main()
{
	int a1, a2;
	int b1, b2;
	int status;
	char* dots = new char;
	ifstream ifs;
	ifs.open("input.txt");
	ifs >> a1;
	ifs >> *dots;
	ifs >> b1;
	ifs >> a2;
	ifs >> *dots;
	ifs >> b2;
	ifs >> status;
	ifs.close();
	delete dots;
	dots = nullptr;

	int ans = b1 + b2 - a1 - a2;
	int outAns = 0;
	switch (status)
	{
	case(1): {
		if ((ans + a2) > b1)
			outAns = ans;
		else if ((ans + a2) == b1)
			outAns = ++ans;
		else
			outAns = ++ans;
		break;
	}
	case(2): {
		if (a1 > b2)
			outAns = ans;
		else if (a1 == b2)
			outAns = ++ans;
		else
			outAns = ++ans;
		break;
	}
	default:
		return -1;
	}
	if (outAns < 0)
		outAns = 0;
	output(outAns);
	return 0;
}

void output(int ans)
{
	ofstream ofs;
	ofs.open("output.txt");
	ofs << ans;
	ofs.close();
}