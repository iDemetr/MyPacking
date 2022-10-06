#include <string>

using namespace std;

string None(std::string field)                                 //Функция если ввод отсутсвует.
{
	if (field.length() == 0 || field == " ")
		field = " ---- ";
	return field;
}