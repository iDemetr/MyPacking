#include <iostream>
#include <Windows.h>

using namespace std;

void Loading()
{
	int i = 0;
	do
	{                                                   //�������� ��������.
		i++;
		cout << ". ";
		Sleep(200);
	} while (i != 10);
}