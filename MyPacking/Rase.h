using namespace std;

struct SRase
{
	string NameSudna;
	string PortOtpr;
	string PortPribit;
};

void Rase()
{																	//Редактирование файла Рейсов.
	char ch = 0;
	int i = 0;
	int x = 0;
	bool flag = false;

	string RaseName = "Rase.txt";

	SRase FRase;

	system("cls");
	cout << "\n-----------------------------------------\n";
	cout << " Режим редактирования базы данных Рейсов\n";
	cout << "\n-----------------------------------------\n";
	cout << " Проверка существующей базы данных Рейсов:\n";

	Loading();														//Анимация загрузки.

	if (isfile(RaseName))											//Если файл Рейсов уже существует.
	{
		cout << "\n\n База данных Рейсов уже существует.\n\n";
		while (x < 10)
		{
			cout << " Удалить файл и создать новый.      (BackSpace)\n";
			cout << " Редактировать файл.                (Enter)\n";
			cout << " Выйти в меню программы.            (Esc)\n";
			ch = _getch();
			if (ch == 8)
			{														//Создаём чистый файл Рейсов
				cout << "\n База данных обновленна.\n" << ch;
				ofstream Rase(RaseName);
				flag = true;
				break;
			}
			if (ch == 13)											//Если выбрана клавиша Enter
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
		ofstream Rase(RaseName, ofstream::app);

		x = 0;

		string s1 = " [Судно] ";
		string s2 = " [Порт отправления] ";
		string s3 = " [Порт прибытия] ";

		while (x < 10)
		{
			cout << "\n Введите Название Судна: \n";
			getline(cin, FRase.NameSudna);							//Считывание название судна.

			while (flag == true)
			{
				if (FRase.NameSudna.length() == 0)					//Если название не было введено.
				{
					cout << "\n Название Судна должно быть обязательно заполнено\n";
					cout << "\n Введите название Судно заново\n";

					getline(cin, FRase.NameSudna);
				}
				else
					flag = false;
			}
			flag = true;

			FRase.NameSudna = Cheking(FRase.NameSudna, s1);			//Проверка введеного названия.	  //Корректность.
			FRase.NameSudna = Tire(FRase.NameSudna);												  //Замена пробела на Тире.
			FRase.NameSudna[0] = toupper(FRase.NameSudna[0]);										  //Заглавная первая буква.

			if (FRase.NameSudna.length() >= strlen("        "))		//Коррекция 
				Rase << FRase.NameSudna << "\t\t";					//вида
			else													//в
				Rase << FRase.NameSudna << "\t\t\t";				//таблице.

			cout << "\n Введите название Порта отправления: \n";
			getline(cin, FRase.PortOtpr);							//Считывание название Порта Отправления.

			FRase.PortOtpr = Cheking(FRase.PortOtpr, s2);			//Проверка введеного названия.	  //Корректность.
			FRase.PortOtpr = Tire(FRase.PortOtpr);													  //Замена пробела на Тире.
			FRase.PortOtpr = None(FRase.PortOtpr);													  //Замена пустого ввода на черточки.
			FRase.PortOtpr[0] = toupper(FRase.PortOtpr[0]);											  //Заглавная первая буква.

			if (FRase.PortOtpr.length() >= strlen("        "))		//Коррекция 
				Rase << FRase.PortOtpr << "\t\t";					//вида
			else													//в
				Rase << FRase.PortOtpr << "\t\t\t";					//таблице.

			cout << " Введите название Порты прибытия: \n";
			getline(cin, FRase.PortPribit);							//Считывание название Порта Прибытия.

			FRase.PortPribit = Cheking(FRase.PortPribit, s3);		//Проверка введеного названия.	  //Корректность.
			FRase.PortPribit = Tire(FRase.PortPribit);												  //Замена пробела на Тире.
			FRase.PortPribit = None(FRase.PortPribit);												  //Замена пустого ввода на черточки.
			FRase.PortPribit[0] = toupper(FRase.PortPribit[0]);										  //Заглавная первая буква.

			Rase << FRase.PortPribit << "\n";


			cout << "\n Сохранение";

			Loading();												//Анимация загрузки.

			cout << "\n Запись сохранена\n\n Ввести новые данные.            (1)\n Завершить редактирование.       (2)\n";
			ch = _getch();
			if (ch == 50)											//Завершение режима редактирования и переход в меню.
			{
				system("cls");
				break;
			}
		}
		Rase.close();
		flag = false;
	}
}