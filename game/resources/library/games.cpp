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

// Функция определяет кто будет ходить первым, человек или компьютер. Игра "Крестики-нолики".
bool FirstMove()
{
	int userRoll{ 0 }, computerRoll{ 0 };

	int min = 0;
	int max = 1;
	while (userRoll == computerRoll) // Если результаты бросков совпадают, бросаем еще по 1 разу.
	{
		userRoll = DiceRoll();
		cout << endl;
		cout << "User : " << endl;
		DiceRollToScreen(userRoll);
		computerRoll = DiceRoll();
		cout << "Computer : " << endl;
		DiceRollToScreen(computerRoll);
	}

	if (userRoll > computerRoll)
		return true; // Право первого хода пренадлежит игроку.
	else if (userRoll < computerRoll)
		return false; // Право первого хода пренадлежит компьютеру.
}

// Функция выводит кто будет ходить первым, человек или компьютер. Игра "Крестики-нолики".
void PrintFirstMove(bool firstMove)
{
	if (firstMove == true)
	{
		cout << "\nUser goes first." << endl;
	}
	else if (firstMove == false)
	{
		cout << "\nComputer goes first." << endl;
	}
}

// Функция заполнения матрицы пробелами. Игра "Крестики-нолики".
void FillArrWithSpaces(char arr[][3], int size = 3)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

// Функция печати игрового поля. Игра "Крестики-нолики".
void PrintPlayingField(char arr[][3], int size)
{
	//system("cls");
	cout << "      0       1       2"
		<< "\n"
		<< "  " << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)
		<< "\n  " << char(186) << "       " << char(186) << "       " << char(186) << "       " << char(186)
		<< "\n0 " << char(186) << "   " << arr[0][0] << "   " << char(186) << "   " << arr[0][1] << "   " << char(186) << "   " << arr[0][2] << "   " << char(186)
		<< "\n  " << char(186) << "       " << char(186) << "       " << char(186) << "       " << char(186)
		<< "\n  " << char(204) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185)
		<< "\n  " << char(186) << "       " << char(186) << "       " << char(186) << "       " << char(186)
		<< "\n1 " << char(186) << "   " << arr[1][0] << "   " << char(186) << "   " << arr[1][1] << "   " << char(186) << "   " << arr[1][2] << "   " << char(186)
		<< "\n  " << char(186) << "       " << char(186) << "       " << char(186) << "       " << char(186)
		<< "\n  " << char(204) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185)
		<< "\n  " << char(186) << "       " << char(186) << "       " << char(186) << "       " << char(186)
		<< "\n2 " << char(186) << "   " << arr[2][0] << "   " << char(186) << "   " << arr[2][1] << "   " << char(186) << "   " << arr[2][2] << "   " << char(186)
		<< "\n  " << char(186) << "       " << char(186) << "       " << char(186) << "       " << char(186)
		<< "\n  " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
}

// Функция проверки свободной ячейки в матрице под ход игрока. Игра "Крестики-нолики".
bool UserMoveCheck(int userRow, int userCol, char arr[][3], int size)
{
	if (arr[userRow][userCol] == ' ')
		return true;
	else
		return false;
}

// Функция обрабатывающая ход игрока. Игра "Крестики-нолики".
void UserMove(int userRow, int userCol, char arr[][3], int size, char userLetter)
{
	arr[userRow][userCol] = userLetter;
}

// Функция определяющая сложность игры. Игра "Крестики-нолики".
int GameDifficulty()
{
	int min = 41;
	int max = 100;

	int result = rand() % (max - min + 1) + min;

	return result;
}

// Функция делает рандомный ход компьютера в свободную ячейку. Игра "Крестики-нолики".
void PcRandMove(char arr[][3], char pcLetter)
{
	int min = 0; // для броска от 0 до 2
	int max = 2; // для броска от 0 до 2
	int pcRow{ -1 }, pcCol{ -1 };

	do
	{
		pcRow = rand() % (max - min + 1) + min;
		pcCol = rand() % (max - min + 1) + min;
	} while (arr[pcRow][pcCol] != ' ');
	arr[pcRow][pcCol] = pcLetter;
}

// Функция обрабатывающая ход компьютера. Игра "Крестики-нолики".
int PcMove(char arr[][3], char pcLetter, char userLetter, int gameDifficulty)
{
	if ((arr[0][0] == ' ') && (arr[0][1] == userLetter) && (arr[0][2] == userLetter)) // 1 горизонтальная [_**]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[0][0] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][0] == userLetter) && (arr[0][1] == ' ') && (arr[0][2] == userLetter)) // 1 горизонтальная [*_*]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[0][1] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][0] == userLetter) && (arr[0][1] == userLetter) && (arr[0][2] == ' ')) // 1 горизонтальная [**_]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[0][2] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[1][0] == ' ') && (arr[1][1] == userLetter) && (arr[1][2] == userLetter)) // 2 горизонтальная [_**]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[1][0] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[1][0] == userLetter) && (arr[1][1] == ' ') && (arr[1][2] == userLetter)) // 2 горизонтальная [*_*]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[1][1] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[1][0] == userLetter) && (arr[1][1] == userLetter) && (arr[1][2] == ' ')) // 2 горизонтальная [**_]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[1][2] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[2][0] == ' ') && (arr[2][1] == userLetter) && (arr[2][2] == userLetter)) // 3 горизонтальная [_**]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[2][0] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[2][0] == userLetter) && (arr[2][1] == ' ') && (arr[2][2] == userLetter)) // 3 горизонтальная [*_*]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[2][1] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[2][0] == userLetter) && (arr[2][1] == userLetter) && (arr[2][2] == ' ')) // 3 горизонтальная [**_]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[2][2] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][0] == ' ') && (arr[1][0] == userLetter) && (arr[2][0] == userLetter)) // 1 вертикальная [_**]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[0][0] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][0] == userLetter) && (arr[1][0] == ' ') && (arr[2][0] == userLetter)) // 1 вертикальная [*_*]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[1][0] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][0] == userLetter) && (arr[1][0] == userLetter) && (arr[2][0] == ' ')) // 1 вертикальная [**_]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[2][0] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][1] == ' ') && (arr[1][1] == userLetter) && (arr[2][1] == userLetter)) // 2 вертикальная[_**]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[0][1] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][1] == userLetter) && (arr[1][1] == ' ') && (arr[2][1] == userLetter)) // 2 вертикальная[*_*]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[1][1] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][1] == userLetter) && (arr[1][1] == userLetter) && (arr[2][1] == ' ')) // 2 вертикальная[**_]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[2][1] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][2] == ' ') && (arr[1][2] == userLetter) && (arr[2][2] == userLetter)) // 3 вертикальная [_**] 
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[0][2] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][2] == userLetter) && (arr[1][2] == ' ') && (arr[2][2] == userLetter)) // 3 вертикальная [*_*] 
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[1][2] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][2] == userLetter) && (arr[1][2] == userLetter) && (arr[2][2] == ' ')) // 3 вертикальная [**_] 
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[2][2] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][0] == ' ') && (arr[1][1] == userLetter) && (arr[2][2] == userLetter)) // главная диагональ [_**]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[0][0] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][0] == userLetter) && (arr[1][1] == ' ') && (arr[2][2] == userLetter)) // главная диагональ [*_*]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[1][1] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[0][0] == userLetter) && (arr[1][1] == userLetter) && (arr[2][2] == ' ')) // главная диагональ [**_]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[2][2] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[2][0] == ' ') && (arr[1][1] == userLetter) && (arr[0][2] == userLetter)) // вторая диагональ [_**]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[2][0] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[2][0] == userLetter) && (arr[1][1] == ' ') && (arr[0][2] == userLetter)) // вторая диагональ [*_*]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[1][1] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else if ((arr[2][0] == userLetter) && (arr[1][1] == userLetter) && (arr[0][2] == ' ')) // вторая диагональ [**_]
	{
		if (GameDifficulty() + gameDifficulty > 50)
			arr[0][2] = pcLetter;
		else
			PcRandMove(arr, pcLetter);
		return 0;
	}
	else
	{
		PcRandMove(arr, pcLetter);
	}
}

// Функция проверки победы. Игра "Крестики-нолики".
int WinCheck(char arr[][3], char userLetter, char pcLetter)
{
	if (((arr[0][0] == userLetter) && (arr[0][1] == userLetter) && (arr[0][2] == userLetter)) || // 1 горизонтальная
		((arr[1][0] == userLetter) && (arr[1][1] == userLetter) && (arr[1][2] == userLetter)) || // 2 горизонтальная
		((arr[2][0] == userLetter) && (arr[2][1] == userLetter) && (arr[2][2] == userLetter)) || // 3 горизонтальная
		((arr[0][0] == userLetter) && (arr[1][0] == userLetter) && (arr[2][0] == userLetter)) || // 1 вертикальная
		((arr[0][1] == userLetter) && (arr[1][1] == userLetter) && (arr[2][1] == userLetter)) || // 2 вертикальная 
		((arr[0][2] == userLetter) && (arr[1][2] == userLetter) && (arr[2][2] == userLetter)) || // 3 вертикальная 
		((arr[0][0] == userLetter) && (arr[1][1] == userLetter) && (arr[2][2] == userLetter)) || // главная диагональ
		((arr[2][0] == userLetter) && (arr[1][1] == userLetter) && (arr[0][2] == userLetter))) // второстепенная диагональ
	{
		return 1; // Возвращает при победе игрока.
	}
	else if (((arr[0][0] == pcLetter) && (arr[0][1] == pcLetter) && (arr[0][2] == pcLetter)) || // 1 горизонтальная
		((arr[1][0] == pcLetter) && (arr[1][1] == pcLetter) && (arr[1][2] == pcLetter)) || // 2 горизонтальная
		((arr[2][0] == pcLetter) && (arr[2][1] == pcLetter) && (arr[2][2] == pcLetter)) || // 3 горизонтальная
		((arr[0][0] == pcLetter) && (arr[1][0] == pcLetter) && (arr[2][0] == pcLetter)) || // 1 вертикальная
		((arr[0][1] == pcLetter) && (arr[1][1] == pcLetter) && (arr[2][1] == pcLetter)) || // 2 вертикальная 
		((arr[0][2] == pcLetter) && (arr[1][2] == pcLetter) && (arr[2][2] == pcLetter)) || // 3 вертикальная 
		((arr[0][0] == pcLetter) && (arr[1][1] == pcLetter) && (arr[2][2] == pcLetter)) || // главная диагональ
		((arr[2][0] == pcLetter) && (arr[1][1] == pcLetter) && (arr[0][2] == pcLetter))) // второстепенная диагональ
	{
		return 0; // Возвращает при победе компьютера.
	}
	else
	{
		return 2; // Возвращает при ничьей.
	}
}