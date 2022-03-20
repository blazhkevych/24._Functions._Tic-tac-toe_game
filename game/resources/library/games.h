// Функция выводящая на экран переданную ей игральную карту.
void PrintPlayingCard(int number);

// Функция делает бросок кубика. Игра "Кубики".
int DiceRoll();

// Функция определяет кто будет ходить первым, человек или компьютер. Игра "Кубики".
int FirstMove(int userRoll, int computerRoll);

// Функция выводит кто будет ходить первым, человек или компьютер. Игра "Кубики".
void PrintFirstMove(int firstMove);

// Функция вывода кубика на экран. Игра "Кубики".
void DiceRollToScreen(int roll);

// Функция определяет кто будет ходить первым, человек или компьютер. Игра "Крестики-нолики".
bool FirstMove();

// Функция выводит кто будет ходить первым, человек или компьютер. Игра "Крестики-нолики".
void PrintFirstMove(bool firstMove);

// Функция заполнения массива пробелами. Игра "Крестики-нолики".
void FillArrWithSpaces(char arr[][3], int size = 3);

// Функция печати игрового поля. Игра "Крестики-нолики".
void PrintPlayingField(char arr[][3], int size);

// Функция проверки свободной ячейки в матрице под ход игрока. Игра "Крестики-нолики".
bool UserMoveCheck(int userRow, int userCol, char arr[][3], int size);

// Функция обрабатывающая ход игрока. Игра "Крестики-нолики".
void UserMove(int userRow, int userCol, char arr[][3], int size, char userLetter);

// Функция определяющая сложность игры. Игра "Крестики-нолики".
int GameDifficulty();

// Функция делает рандомный ход компьютера в свободную ячейку. Игра "Крестики-нолики".
void PcRandMove(char arr[][3], char pcLetter);

// Функция обрабатывающая ход компьютера. Игра "Крестики-нолики".
int PcMove(char arr[][3], char pcLetter, char userLetter, int gameDifficulty);

// Функция проверки победы. Игра "Крестики-нолики".
int WinCheck(char arr[][3], char userLetter, char pcLetter);


