using namespace std;

struct SRase
{
	string NameSudna;
	string PortOtpr;
	string PortPribit;
};

void Rase()
{																	//�������������� ����� ������.
	char ch = 0;
	int i = 0;
	int x = 0;
	bool flag = false;

	string RaseName = "Rase.txt";

	SRase FRase;

	system("cls");
	cout << "\n-----------------------------------------\n";
	cout << " ����� �������������� ���� ������ ������\n";
	cout << "\n-----------------------------------------\n";
	cout << " �������� ������������ ���� ������ ������:\n";

	Loading();														//�������� ��������.

	if (isfile(RaseName))											//���� ���� ������ ��� ����������.
	{
		cout << "\n\n ���� ������ ������ ��� ����������.\n\n";
		while (x < 10)
		{
			cout << " ������� ���� � ������� �����.      (BackSpace)\n";
			cout << " ������������� ����.                (Enter)\n";
			cout << " ����� � ���� ���������.            (Esc)\n";
			ch = _getch();
			if (ch == 8)
			{														//������ ������ ���� ������
				cout << "\n ���� ������ ����������.\n" << ch;
				ofstream Rase(RaseName);
				flag = true;
				break;
			}
			if (ch == 13)											//���� ������� ������� Enter
			{
				flag = true;
				break;
			}
			if (ch == 27)											//������� � ����.
			{
				cout << " �������� ����";

				Loading();											//�������� ��������.

				system("cls");
			}
			else cout << "\n ������� ������������ �������\n";
		}
	}
	else
	{
		cout << "\n ���� ������ ������ �� ���������� � ����� �������\n";
		flag = true;
	}

	while (flag == true)											//��������.
	{
		ofstream Rase(RaseName, ofstream::app);

		x = 0;

		string s1 = " [�����] ";
		string s2 = " [���� �����������] ";
		string s3 = " [���� ��������] ";

		while (x < 10)
		{
			cout << "\n ������� �������� �����: \n";
			getline(cin, FRase.NameSudna);							//���������� �������� �����.

			while (flag == true)
			{
				if (FRase.NameSudna.length() == 0)					//���� �������� �� ���� �������.
				{
					cout << "\n �������� ����� ������ ���� ����������� ���������\n";
					cout << "\n ������� �������� ����� ������\n";

					getline(cin, FRase.NameSudna);
				}
				else
					flag = false;
			}
			flag = true;

			FRase.NameSudna = Cheking(FRase.NameSudna, s1);			//�������� ��������� ��������.	  //������������.
			FRase.NameSudna = Tire(FRase.NameSudna);												  //������ ������� �� ����.
			FRase.NameSudna[0] = toupper(FRase.NameSudna[0]);										  //��������� ������ �����.

			if (FRase.NameSudna.length() >= strlen("        "))		//��������� 
				Rase << FRase.NameSudna << "\t\t";					//����
			else													//�
				Rase << FRase.NameSudna << "\t\t\t";				//�������.

			cout << "\n ������� �������� ����� �����������: \n";
			getline(cin, FRase.PortOtpr);							//���������� �������� ����� �����������.

			FRase.PortOtpr = Cheking(FRase.PortOtpr, s2);			//�������� ��������� ��������.	  //������������.
			FRase.PortOtpr = Tire(FRase.PortOtpr);													  //������ ������� �� ����.
			FRase.PortOtpr = None(FRase.PortOtpr);													  //������ ������� ����� �� ��������.
			FRase.PortOtpr[0] = toupper(FRase.PortOtpr[0]);											  //��������� ������ �����.

			if (FRase.PortOtpr.length() >= strlen("        "))		//��������� 
				Rase << FRase.PortOtpr << "\t\t";					//����
			else													//�
				Rase << FRase.PortOtpr << "\t\t\t";					//�������.

			cout << " ������� �������� ����� ��������: \n";
			getline(cin, FRase.PortPribit);							//���������� �������� ����� ��������.

			FRase.PortPribit = Cheking(FRase.PortPribit, s3);		//�������� ��������� ��������.	  //������������.
			FRase.PortPribit = Tire(FRase.PortPribit);												  //������ ������� �� ����.
			FRase.PortPribit = None(FRase.PortPribit);												  //������ ������� ����� �� ��������.
			FRase.PortPribit[0] = toupper(FRase.PortPribit[0]);										  //��������� ������ �����.

			Rase << FRase.PortPribit << "\n";


			cout << "\n ����������";

			Loading();												//�������� ��������.

			cout << "\n ������ ���������\n\n ������ ����� ������.            (1)\n ��������� ��������������.       (2)\n";
			ch = _getch();
			if (ch == 50)											//���������� ������ �������������� � ������� � ����.
			{
				system("cls");
				break;
			}
		}
		Rase.close();
		flag = false;
	}
}