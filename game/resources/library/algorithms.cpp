#include <iostream>
using namespace std;

// Функция, циклически сдвигающая целое число на N разрядов вправо или влево, в зависимости от третьего параметра функции.
// сдвигаемое число, на сколько разрядов сдвинуть число, направление сдвига влево или вправо(по умолчанию влево(false)).
void CyclicNumberShift(int number, int shiftBitDepth = 1, bool leftOrRight = false)
{
	int divider{ 1 }; // определяем отрезаемое кол-во цифр от введенного числа
	for (; number / (divider * 10);)
		divider *= 10;

	switch (leftOrRight) // по выбору направления циклического сдвига числа
	{
	case false: // - циклический сдвиг влево		
		for (int i = 0; i < shiftBitDepth; i++) // формируем новое число
		{
			int temp = number % divider; // отделяем левую часть
			number = temp * 10 + number / divider; // формируем новое число(правая часть + левая часть числа)
		}
		cout << number << endl;
		break;
	case true: // - циклический сдвиг вправо
		int temp = 0;
		for (int i = 0; i < shiftBitDepth; i++) // формируем новое число
		{
			temp = number % 10; // отделяем правую часть
			number /= 10; // удаляем крайнее правое число
			number = temp * divider + number; // формируем новое число(правая часть + левая часть числа)
		}
		cout << number << endl;
		break;
	}
}