#include "Port.h"
#include "Rase.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);                                         //Русский язык в консоли.
	SetConsoleOutputCP(1251);                                   //Русский язык в файле.

	char ch = 0;
	int i = 0;
	int x = 0;
	bool flag = false;

	cout << " Запустить программу(Enter)\n";
	getchar();
	cout << " Запуск программы:\n\n";

	Loading();													//Анимация загрузки.

	while (!flag)                                               //Чекпоинт.
	{
		cout << " Редактировать файл Портов.         (1)\n";
		cout << " Редактировать файл Рейсов.         (2)\n";
		cout << " Выйти из программы.                (Esc)\n";

		x = 0;
		ch = _getch();

		if (ch == 49)
		{                                                       //Редактирование файла Портов.
			Port();
		}
		else
			if (ch == 50)										//Редактирование файла Рейсов.
			{
				Rase();
			}
			else
				if (ch == 27)
				{
					cout << "\n Завершение программы";

					Loading();									//Анимация загрузки.
				}
				else cout << "\n Введена неправильная клавиша\n";
	}
}