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
{																	//�������������� ����� ������.
	char ch = 0;
	int i = 0;
	int x = 0;
	bool flag = false;

	string PortsName = "Ports.txt";
	SPort FPort;

	system("cls");
	cout << "\n-----------------------------------------------\n";
	cout << "\n    ����� �������������� ���� ������ ������\n";
	cout << "\n-----------------------------------------------\n";
	cout << " �������� ������������ ���� ������ ������:\n";

	Loading();														//�������� ��������.

	if (isfile(PortsName))											//�������� ������� �����.
	{
		cout << "\n\n ���� ������ ������ ��� ����������.\n\n";
		while (x < 10)
		{
			cout << " ������� ���� � ������� �����.      (BackSpace)\n";
			cout << " ������������� ����.                (Enter)\n";
			cout << " ����� � ���� ���������.            (Esc)\n";
			ch = _getch();
			if (ch == 8)
			{														//������ ������ ����
				cout << "\n ���� ������ ����������.\n" << ch;
				ofstream Port(PortsName);
				flag = true;
				break;
			}
			if (ch == 13)											//���� ������� ������� Enter.
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
		ofstream Port(PortsName, ofstream::app);
		x = 0;

		string s1 = " [����] ";
		string s2 = " [������] ";
		string s3 = " [����] ";

		while (x < 10)
		{
			cout << "\n ������� �������� �����: \n";
			getline(cin, FPort.NamePort);							//���������� �������� �����.

			while (flag == true)
			{
				if (FPort.NamePort.length() == 0)					//���� �������� �� ���� �������.
				{
					cout << "\n �������� ����� ������ ���� ����������� ���������\n";
					cout << "\n ������� �������� ����� ������\n";

					getline(cin, FPort.NamePort);
				}
				else
					flag = false;
			}
			flag = true;

			FPort.NamePort = Cheking(FPort.NamePort, s1);			//�������� ��������� ��������.	  //������������.
			FPort.NamePort = Tire(FPort.NamePort);													  //������ ������� �� ����.
			FPort.NamePort[0] = toupper(FPort.NamePort[0]);											  //��������� ������ �����.

			if (FPort.NamePort.length() >= strlen("        "))		//��������� 
				Port << FPort.NamePort << "\t\t";					//����
			else													//�
				Port << FPort.NamePort << "\t\t\t";					//�������.

			cout << " ������� �������� ������: \n";
			getline(cin, FPort.Contry);									

			FPort.Contry = Cheking(FPort.Contry, s2);				//�������� ��������� ��������.	  //������������.
			FPort.Contry = Tire(FPort.Contry);														  //������ ������� �� ����.
			FPort.Contry = None(FPort.Contry);														  //������ ������� ����� �� ��������.
			FPort.Contry[0] = toupper(FPort.Contry[0]);												  //��������� ������ �����.

			if (FPort.Contry.length() >= strlen("        "))		//��������� 
				Port << FPort.Contry << "\t\t";						//����
			else													//�
				Port << FPort.Contry << "\t\t\t";					//�������.


			cout << " ������� �������� ����: \n";
			getline(cin, FPort.Sea);									

			FPort.Sea = Cheking(FPort.Sea, s3);						//�������� ��������� ��������.	  //������������.
			FPort.Sea = Tire(FPort.Sea);															  //������ ������� �� ����.
			FPort.Sea = None(FPort.Sea);															  //������ ������� ����� �� ��������.
			FPort.Sea[0] = toupper(FPort.Sea[0]);													  //��������� ������ �����.

			Port << FPort.Sea << "\n";

			cout << "\n ����������";

			Loading();												//�������� ��������.

			cout << "\n ������ ���������\n\n ������ ����� ������.            (1)\n ��������� ��������������.       (2)";
			ch = _getch();
			if (ch == 50)											//���������� ������ �������������� � ������� � ����.
			{
				system("cls");
				break;
			}
		}
		Port.close();
		flag = false;
	}
}