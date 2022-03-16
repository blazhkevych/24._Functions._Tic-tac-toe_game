#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

// Функция выводящая на экран переданную ей игральную карту.
void PrintPlayingCard(int number)
{
	switch (number % 9)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		cout << number % 9 + 6;
		break;
	case 5:
		cout << 'J';
		break;
	case 6:
		cout << 'Q';
		break;
	case 7:
		cout << 'K';
		break;
	case 8:
		cout << 'A';
		break;
	}
	cout << char(6 - number / 9);
}

// Функция делает бросок кубика. Игра "Кубики".
int DiceRoll()
{
	int symbol = _getch();
	int min = 1;
	int max = 6;
	int roll{ 0 };
	if (symbol == VK_RETURN) // Enter
	{
		roll = rand() % (max - min + 1) + min;
	}
	return roll;
}

// Функция определяет кто будет ходить первым, человек или компьютер. Игра "Кубики".
int FirstMove(int userRoll, int computerRoll) // Есть проблема с одинаковым результатом броска.
{
	if (computerRoll > userRoll)
	{
		return 1; // Первый ход принадлежит компьютеру.
	}
	else
	{
		return 2; // Первый ход принадлежит игроку.
	}
}

// Функция выводит кто будет ходить первым, человек или компьютер. Игра "Кубики".
void PrintFirstMove(int firstMove)
{
	if (firstMove == 1)
	{
		cout << "Computer goes first." << endl;
	}
	else
	{
		cout << "User goes first." << endl;
	}
}

// Функция вывода кубика на экран. Игра "Кубики".
void DiceRollToScreen(int roll)
{
	switch (roll)
	{
	case 1:
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)
			<< "\n" << char(186) << "  \t" << char(186)
			<< "\n" << char(186) << "   O\t" << char(186)
			<< "\n" << char(186) << "      \t" << char(186)
			<< "\n" << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
		break;
	case 2:
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)
			<< "\n" << char(186) << " O\t" << char(186)
			<< "\n" << char(186) << "    \t" << char(186)
			<< "\n" << char(186) << "     O\t" << char(186)
			<< "\n" << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
		break;
	case 3:
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)
			<< "\n" << char(186) << " O\t" << char(186)
			<< "\n" << char(186) << "   O\t" << char(186)
			<< "\n" << char(186) << "     O\t" << char(186)
			<< "\n" << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
		break;
	case 4:
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)
			<< "\n" << char(186) << " O   O	" << char(186)
			<< "\n" << char(186) << "    \t" << char(186)
			<< "\n" << char(186) << " O   O\t" << char(186)
			<< "\n" << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
		break;
	case 5:
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)
			<< "\n" << char(186) << " O   O " << char(186)
			<< "\n" << char(186) << "   O\t" << char(186)
			<< "\n" << char(186) << " O   O\t" << char(186)
			<< "\n" << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
		break;
	case 6:
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)
			<< "\n" << char(186) << " O O O " << char(186)
			<< "\n" << char(186) << "    \t" << char(186)
			<< "\n" << char(186) << " O O O\t" << char(186)
			<< "\n" << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
		break;
	}
}