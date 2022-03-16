// Функция, проверяющая является ли год високосным.
bool IsItALeapYear(int year);

// Функция, проверяющая корректность введенных значений даты.
bool DateValidationCheck(int day, int month, int year);

// Функция, вычисляет разность в днях между этими датами.
int DiffInDaysBetwDates(
	int day1, int month1, int year1,
	int day2, int month2, int year2);

// Функция определяет день недели.
int Get_DOW(int year, int month, int day);