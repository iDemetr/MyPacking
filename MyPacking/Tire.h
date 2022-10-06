#include <string>

using namespace std;

string Tire(std::string field)                                 //Функция замены пробелов на Тире(-).
{
	for (unsigned int r = 0; r < field.length() + 1; r++)
	{
		if (field[r] == ' ')
			field[r] = '-';
	};
	return field;
};