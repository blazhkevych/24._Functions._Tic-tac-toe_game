#include <iostream>
#include "resources/library/games.h"
#include <windows.h>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	srand(time(NULL));
	const int size{ 3 };
	char arr[size][size]{ 0 };

	char answer{ -1 };
	do
	{
		FillArrWithSpaces(arr, size);
		cout << "\tGame \"Tic-tac-toe.\"\"\n\n"
			<< "Choose the difficulty of the game, from 0 to 10"
			"\n(where 0 is the minimum difficulty, 10 is the maximum difficulty):\n";
		int gameDifficulty{ 0 };
		cin >> gameDifficulty;
		cout << "\tDo you want to play \"X\" or \"O\"?\n"
			<< "Press 1 to select \"X\".\n"
			<< "Press 2 to select \"O\".\n";
		int userChoice{ -1 };
		char userLetter{ 3 };
		char pcLetter{ 3 };
		cout << ">>> ";
		cin >> userChoice;
		if (userChoice == 1)
		{
			userLetter = 'X';
			pcLetter = 'O';
			cout << "\n\tYou chose to play \"X\".\n"
				<< "The computer will play \"O\".\n";
		}
		else if (userChoice == 2)
		{
			userLetter = 'O';
			pcLetter = 'X';
			cout << "\n\tYou chose to play \"O\".\n"
				<< "The computer will play \"X\".\n";
		}

		cout << "\n\tWho will go first?\n"
			<< "Press enter to roll the dice.";
		bool firstMove = FirstMove();
		PrintFirstMove(firstMove);
		Sleep(1000); // Чтобы успеть увидеть результаты броска кубика, для понимания кто будет ходить первым.

		int userRow{ -1 };
		int userCol{ -1 };
		int pcRow{ -1 };
		int pcCol{ -1 };

		int totalMovesInGame = 9;
		int winCheck{ -1 };

		do
		{
			if (firstMove == 1) // Пользователь.
			{
				system("cls");
				PrintPlayingField(arr, size);
				int userRow{ -1 };
				int userCol{ -1 };
				bool moveCheckResult{ };
				do
				{
					cout << "\nEnter row number: ";
					cin >> userRow;
					cout << "\nEnter the column number : ";
					cin >> userCol;
					moveCheckResult = UserMoveCheck(userRow, userCol, arr, size);
					if (moveCheckResult == false)
						cout << "\nThese coordinates are not suitable. Enter other coordinates.";

				} while (moveCheckResult == false);
				UserMove(userRow, userCol, arr, size, userLetter);
				system("cls");
				PrintPlayingField(arr, size);
				firstMove -= 1;
				totalMovesInGame--;
				winCheck = WinCheck(arr, userLetter, pcLetter);
				if (winCheck == 1)
				{
					cout << "\nPlayer wins!\n";
					break;
				}
			}
			else if (firstMove == 0) // Компьютер.
			{
				system("cls");
				Sleep(1000);
				PcMove(arr, pcLetter, userLetter, gameDifficulty);
				PrintPlayingField(arr, size);
				firstMove += 1;
				totalMovesInGame--;
				winCheck = WinCheck(arr, userLetter, pcLetter);
				if (winCheck == 0)
				{
					cout << "\nThe computer won!\n";
					break;
				}
			}
		} while ((totalMovesInGame) > 0 || winCheck != 2);

		if (winCheck == 2)
			cout << "\nDraw !" << endl;

		cout << endl;
		cout << "Do you want to continue? ( y (yes) / n (no) )\n";
		cin >> answer;
		cout << endl;

	} while (answer == 'y');

	return 0;
}