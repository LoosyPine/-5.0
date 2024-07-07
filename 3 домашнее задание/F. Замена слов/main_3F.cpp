#include <iostream>
#include <map>
#include <fstream>
#include <set>
#include <string>

using namespace std;

template<typename T>
void Output(T& ans);

int main()
{
	string ans = "";
	map<char, set<string>> m_dictionary;
	ifstream ifs;
	ifs.open("input.txt");
	string current_str;
	getline(ifs, current_str);
	string word = "";
	for (int i = 0; i < current_str.size(); i++)
	{
		if (current_str[i] == ' ')
		{
			m_dictionary.try_emplace(word[0]);
			m_dictionary[word[0]].insert(word);
			word.erase();
		}
		else if (i == current_str.size() - 1)
		{
			word += current_str[i];
			m_dictionary.try_emplace(word[0]);
			m_dictionary[word[0]].insert(word);
			word.erase();
		}
		else
		{
			word += current_str[i];
		}
	}
	//cout dictionary
	for (auto& i : m_dictionary)
	{
		cout << i.first << '\t';
		for (auto& j : i.second)
		{
			cout << j << ' ';
		}
		cout << endl;
	}
	// Обработка основных слов
	current_str.erase();
	word.erase();
	getline(ifs, current_str);
	for (int i = 0; i < current_str.size(); i++)
	{
		// Запись слова в переменную
		word += current_str[i];
		if (current_str[i] == ' ' || i == current_str.size() - 1) // Если слово закончилось начинается его обработка
		{
			auto i_firstLetter = m_dictionary.find(word[0]);
			if (i_firstLetter == m_dictionary.end())
			{
				ans += word; // добавления слова в ответ если нет сокращения в словаре
				word.erase();
			}
			else // Если перва буква слова нашлась в словаре
			{
				for (auto j : i_firstLetter->second) // перебор всех сокращений в словаре
				{
					if (j.size() >= word.size()) // Если слово из словоря длиньше чем само слово из текста, то цикл останавливается
					{
						continue;
					}
					for (int f = 0; f < j.size(); f++) // сравниваем буквы сокращённого слова и слова из текста
					{
						if (j[f] != word[f]) // если хотя бы одна буква не равна, то цикл прерывается и на проверку идёт следующее скоращённое слово
						{
							break;
						}
						else if (f == j.size() - 1)
						{
							word = j;
						}
					}
					if (word == j)
					{
						word += " ";
						break;
					}
						
				}
				ans += word; // добовляем слово в ответ(неважно сократилось оно или нет)
				word.erase(); // очищаем переменную word для следующего слова
			}
		}
	}
	ifs.close();
	Output(ans);
	return 0;
}

template<typename T>
void Output(T& ans)
{
	ofstream ofs;
	ofs.open("output.txt");
	ofs << ans;
	ofs.close();
}