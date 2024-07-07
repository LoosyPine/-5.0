#include <iostream>
#include <fstream>

using namespace std;

//Вывод в поток
void output(int result)
{
	ofstream ofs;
	ofs.open("output.txt");
	ofs << result;
	ofs.close();
}

int main()
{
	//Переменные
	int p, v;
	int q, m;
	int result = 0;

	ifstream ifs;
	ifs.open("input.txt");
	ifs >> p >> v;
	ifs >> q >> m;
	ifs.close();

	//Обработка каревых случаев
	if ((v == 0) && (m == 0))
	{
		result = 0;
		output(result);
		return 0;
	}
	else if ((v == 0) || (m == 0))
	{
		if (v == 0)
		{
			result = m * 2 + 1;
			output(result);
			return 0;
		}
		else
		{
			result = v * 2 + 1;
			output(result);
			return 0;
		}
	}
	
	//Минимумы и максимум Васи и Маши
	int min_V = 0,
		max_V = 0;
	int min_M = 0,
		max_M = 0;

	min_V = p - v;
	max_V = p + v;

	min_M = q - m;
	max_M = q + m;

	//Нахождения абсолютных мин. и макс.
	int absolute_min = 0;
	int absolute_max = 0;

	if (min_V <= min_M)
		absolute_min = min_V;
	else
		absolute_min = min_M;
	
	if (max_V >= max_M)
		absolute_max = max_V;
	else
		absolute_max = max_M;

	//Основной цикл для проверки ОБЩЕЙ зоны покрытия
	bool zone = false;
	for (int i = absolute_min; i <= absolute_max; i++)
	{
		if ((i >= min_V) && (i <= max_V))
			zone = true;
		else if ((i >= min_M) && (i <= max_M))
			zone = true;
		else
			zone = false;
			
		if (zone == true)
			result++;
	}

	output(result);

	return 0;
}