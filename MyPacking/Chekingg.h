#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Cheking(std::string field, std::string s)				//Функция для проверки корректности ввода.
{
	bool checks = true;
	string Symbols = "[]{}+=&^:;|/><$#@.,!?№%()1234567890";
	
	while (checks == true)
	{
		unsigned int k = 0;
		for (unsigned int i = 0; i < field.length(); i++)
		{
			for (unsigned int i1 = 0; i1 < Symbols.length(); i1++)
			{
				if (field[i] == Symbols[i1])
				{
					k = k + 1;
				}
			}
		}
		if (k >= 1 || k == field.length() && field.length() != 0)
		{
			cout << s << " Возможно, Вы ввели цифры или некорректные символы: (" << Symbols << ")\n Попробуйте ещё раз: \n";
			getline(cin, field);
		}
		else  checks = false;
	}
	checks = true;
	return field;
}