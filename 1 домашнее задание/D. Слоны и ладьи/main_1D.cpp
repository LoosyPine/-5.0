#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

void output(int& ans);

int main()
{
	int ans = 64;
	char** ar2_field = new char*[8];
	for (int i = 0; i < 8; i++)
	{
		ar2_field[i] = new char[8];
	}

	ifstream ifs;
	ifs.open("input.txt");

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ifs >> ar2_field[i][j];
			if ((ar2_field[i][j] == 'R') || (ar2_field[i][j] == 'B'))
				--ans;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (ar2_field[i][j] == 'R')
			{
				for(int k = i - 1; k >= 0; k--)
				{
					if (ar2_field[k][j] == '*')
					{
						--ans;
						ar2_field[k][j] = '+';
					}
					else if (ar2_field[k][j] == '+') ar2_field[k][j] = '+';
					else break;
				}
				for (int k = i + 1; k < 8; k++)
				{
					if (ar2_field[k][j] == '*')
					{
						--ans;
						ar2_field[k][j] = '+';
					}
					else if (ar2_field[k][j] == '+') ar2_field[k][j] = '+';
					else break;
				}
				for (int k = j - 1; k >= 0; k--)
				{
					if (ar2_field[i][k] == '*')
					{
						--ans;
						ar2_field[i][k] = '+';
					}
					else if (ar2_field[i][k] == '+') ar2_field[i][k] = '+';
					else break;
				}
				for (int k = j + 1; k < 8; k++)
				{
					if (ar2_field[i][k] == '*')
					{
						--ans;
						ar2_field[i][k] = '+';
					}
					else if (ar2_field[i][k] == '+') ar2_field[i][k] = '+';
					else break;
				}
			}
			else if (ar2_field[i][j] == 'B')
			{
				int x = j + 1;
				for (int y = i + 1; y <= 7; y++)
				{
					if (ar2_field[y][x] == '*')
					{
						--ans;
						ar2_field[y][x] = '+';
					}
					else if (ar2_field[y][x] == '+') ar2_field[y][x] == '+';
					else break;
					if (x == 7) break;
					++x;
				}
				x = j - 1;
				for (int y = i - 1; y >= 0; y--)
				{
					if (ar2_field[y][x] == '*')
					{
						--ans;
						ar2_field[y][x] = '+';
					}
					else if (ar2_field[y][x] == '+') ar2_field[y][x] == '+';
					else break;
					if (x == 0) break;
					--x;
				}
				x = j - 1;
				for (int y = i + 1; y <= 7; y++)
				{
					if (ar2_field[y][x] == '*')
					{
						--ans;
						ar2_field[y][x] = '+';
					}
					else if (ar2_field[y][x] == '+') ar2_field[y][x] == '+';
					else break;
					if (x == 0) break;
					--x;
				}
				x = j + 1;
				for (int y = i - 1; y >= 0; y--)
				{
					if (ar2_field[y][x] == '*')
					{
						--ans;
						ar2_field[y][x] = '+';
					}
					else if (ar2_field[y][x] == '+') ar2_field[y][x] == '+';
					else break;
					if (x == 7) break;
					++x;
				}
			}
		}
	}
	ifs.close();

	/*cout << endl;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << ar2_field[i][j];
		}
		cout << endl;
	}*/

	output(ans);
	// Деструктор
	for (int i = 0; i < 8; i++)
	{
		delete[] ar2_field[i];
	}
	delete[] ar2_field;
	ar2_field = nullptr;
	return 0;
}

void output(int& ans)
{
	ofstream ofs;
	ofs.open("output.txt");
	ofs << ans;
	ofs.close();
}