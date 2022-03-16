// Функция, проверяющая является ли год високосным.
bool IsItALeapYear(int year)
{
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return true;
	else
		return false;
}

enum Months
{
	January = 1, // Январь, 31 день
	February = 2, // Февраль, 28 дней (В високосные годы вводится дополнительный день — 29 февраля.)
	March = 3, // Март, 31 день 
	April = 4, // Апрель, 30 дней 
	May = 5, // Май, 31 день 
	June = 6, // Июнь, 30 дней 
	July = 7, // Июль, 31 день 
	August = 8, // Август, 31 день 
	September = 9, // Сентябрь, 30 дней 
	October = 10, // Октябрь, 31 день 
	November = 11, // Ноябрь, 30 дней 
	December = 12 // Декабрь, 31 день 
};

// Функция, проверяющая корректность введенных значений даты.
bool DateValidationCheck(int day, int month, int year)
{
	if (year > 0)
	{
		if (month > 0 && month < 13)
		{
			if (
				((IsItALeapYear(year))
					&& (month == February) && (day == 29)) // Если 29 февраля в високосном году.
				|| ((IsItALeapYear(year))
					&& (month == February) && (day > 0 && day < 29)) // Если 1-28 февраля, високосный год.
				|| (!(IsItALeapYear(year))
					&& (month == February) && (day > 0 && day < 29)) // Если 1-28 февраля, обычный год.
				|| ((month == January
					|| month == March
					|| month == May
					|| month == July
					|| month == August
					|| month == October
					|| month == December) && (day > 0 && day < 32)) // Все месяца, в которых 31 день.
				|| ((month == April
					|| month == June
					|| month == September
					|| month == November) && (day > 0 && day < 31)) // Все месяца, в которых 30 дней.
				)
			{
				return true; // Все введённые значения корректны.
			}
			else
				return false; // Введен не корректный день.
		}
		else
			return false; // Введен не корректный месяц. 
	}
	else
		return false; // Введен не корректный год. 
}

// Функция, вычисляет разность в днях между этими датами.
int DiffInDaysBetwDates(
	int day1, int month1, int year1,
	int day2, int month2, int year2)
{
	int differenceIs{ 0 }; // Счетчик разности в днях между этими датами.

	if (year1 == year2 && month1 == month2 && day1 == day2) // Если даты равны.
	{
		return differenceIs = 0;
	}
	else
	{
		while (!(year1 == year2 && month1 == month2 && day1 == day2)) // Пока даты не равны, вычисляем следующую дату.
		{
			switch (month1)
			{
			case April: // Расчет следующей даты за введенной, для месяцев c 30 днями.
			case June:
			case September:
			case November:
				day1++;
				if (day1 > 30)
				{
					day1 = 1;
					month1++;
					if (month1 > 12)
					{
						month1 = 1;
						year1++;
					}
				}
				break;

			case January: // Расчет следующей даты за введенной, для месяцев c 31 днем.
			case March:
			case May:
			case July:
			case August:
			case October:
			case December:
				day1++;
				if (day1 > 31)
				{
					day1 = 1;
					month1++;
					if (month1 > 12)
					{
						month1 = 1;
						year1++;
					}
				}
				break;

			case February: // Расчет следующей даты за введенной, для февраля (как высокосного так и не високосного).
				day1++;
				if (!(year1 % 400 == 0 || (year1 % 100 != 0 && year1 % 4 == 0)) && (day1 > 28)) // Не високосный.
				{
					day1 = 1;
					month1++;
					if (month1 > 12)
					{
						month1 = 1;
						year1++;
					}
				}
				else if ((year1 % 400 == 0 || (year1 % 100 != 0 && year1 % 4 == 0)) && (day1 > 29)) // Високосный.
				{
					day1 = 1;
					month1++;
					if (month1 > 12)
					{
						month1 = 1;
						year1++;
					}
				}
				break;
			}
			//cout << "Следующая дата: " << day1 << '.' << month1 << '.' << year1 << endl;
			differenceIs++;
		}
	}
	return differenceIs;
}

// Функция определяет день недели.
int Get_DOW(int year, int month, int day)
{
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	int d = (7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;

	return d ? d : 7;
}