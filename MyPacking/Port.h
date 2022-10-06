#include <conio.h>

#include "isFilee.h"
#include "Chekingg.h"
#include "None.h"
#include "Tire.h"
#include "Loadingg.h"

using namespace std;

struct SPort
{
	string NamePort;
	string Contry;
	string Sea;
};

void Port()
{																	//Редактирование файла Портов.
	char ch = 0;
	int i = 0;
	int x = 0;
	bool flag = false;

	string PortsName = "Ports.txt";
	SPort FPort;

	system("cls");
	cout << "\n-----------------------------------------------\n";
	cout << "\n    Режим редактирования базы данных Портов\n";
	cout << "\n-----------------------------------------------\n";
	cout << " Проверка существующей базы данных Портов:\n";

	Loading();														//Анимация загрузки.

	if (isfile(PortsName))											//Проверка наличия файла.
	{
		cout << "\n\n База данных Портов уже существует.\n\n";
		while (x < 10)
		{
			cout << " Удалить файл и создать новый.      (BackSpace)\n";
			cout << " Редактировать файл.                (Enter)\n";
			cout << " Выйти в меню программы.            (Esc)\n";
			ch = _getch();
			if (ch == 8)
			{														//Создаём чистый файл
				cout << "\n База данных обновленна.\n" << ch;
				ofstream Port(PortsName);
				flag = true;
				break;
			}
			if (ch == 13)											//Если выбрана клавиша Enter.
			{
				flag = true;
				break;
			}
			if (ch == 27)											//Переход в меню.
			{
				cout << " Загрузка меню";

				Loading();											//Анимация загрузки.

				system("cls");
			}
			else cout << "\n Введена неправильная клавиша\n";
		}
	}

	else
	{
		cout << "\n Базы данных Портов не существует и будет создана\n";
		flag = true;
	}

	while (flag == true)											//Чекпоинт.
	{
		ofstream Port(PortsName, ofstream::app);
		x = 0;

		string s1 = " [Порт] ";
		string s2 = " [Страна] ";
		string s3 = " [Море] ";

		while (x < 10)
		{
			cout << "\n Введите название Порта: \n";
			getline(cin, FPort.NamePort);							//Считывание название судна.

			while (flag == true)
			{
				if (FPort.NamePort.length() == 0)					//Если название не было введено.
				{
					cout << "\n Название Судна должно быть обязательно заполнено\n";
					cout << "\n Введите название Судно заново\n";

					getline(cin, FPort.NamePort);
				}
				else
					flag = false;
			}
			flag = true;

			FPort.NamePort = Cheking(FPort.NamePort, s1);			//Проверка введеного названия.	  //Корректность.
			FPort.NamePort = Tire(FPort.NamePort);													  //Замена пробела на Тире.
			FPort.NamePort[0] = toupper(FPort.NamePort[0]);											  //Заглавная первая буква.

			if (FPort.NamePort.length() >= strlen("        "))		//Коррекция 
				Port << FPort.NamePort << "\t\t";					//вида
			else													//в
				Port << FPort.NamePort << "\t\t\t";					//таблице.

			cout << " Введите название Страны: \n";
			getline(cin, FPort.Contry);									

			FPort.Contry = Cheking(FPort.Contry, s2);				//Проверка введеного названия.	  //Корректность.
			FPort.Contry = Tire(FPort.Contry);														  //Замена пробела на Тире.
			FPort.Contry = None(FPort.Contry);														  //Замена пустого ввода на черточки.
			FPort.Contry[0] = toupper(FPort.Contry[0]);												  //Заглавная первая буква.

			if (FPort.Contry.length() >= strlen("        "))		//Коррекция 
				Port << FPort.Contry << "\t\t";						//вида
			else													//в
				Port << FPort.Contry << "\t\t\t";					//таблице.


			cout << " Введите название Моря: \n";
			getline(cin, FPort.Sea);									

			FPort.Sea = Cheking(FPort.Sea, s3);						//Проверка введеного названия.	  //Корректность.
			FPort.Sea = Tire(FPort.Sea);															  //Замена пробела на Тире.
			FPort.Sea = None(FPort.Sea);															  //Замена пустого ввода на черточки.
			FPort.Sea[0] = toupper(FPort.Sea[0]);													  //Заглавная первая буква.

			Port << FPort.Sea << "\n";

			cout << "\n Сохранение";

			Loading();												//Анимация загрузки.

			cout << "\n Запись сохранена\n\n Ввести новые данные.            (1)\n Завершить редактирование.       (2)";
			ch = _getch();
			if (ch == 50)											//Завершение режима редактирования и переход в меню.
			{
				system("cls");
				break;
			}
		}
		Port.close();
		flag = false;
	}
}