#include <string>

using namespace std;

string None(std::string field)                                 //������� ���� ���� ����������.
{
	if (field.length() == 0 || field == " ")
		field = " ---- ";
	return field;
}