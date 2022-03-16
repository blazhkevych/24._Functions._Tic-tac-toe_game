#include <conio.h>
#include <windows.h>
#include "asciilib.h"

// Функция проверяющая является ли переданный ей параметр алфавитно - цифровым.
bool alphanumeric(char x)
{
	if (x >= '0' && x <= '9' || x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z')
		return true;
	return false;
}

// Реверс регистра при вводе с клавиатуры текста (заменяет строчные буквы на прописные, а прописные – на строчные)
void reverse_register()
{
	char symbol;
	do
	{
		symbol = _getch();
		if (symbol == VK_RETURN) // Enter
			symbol = '\n';
		if (symbol == VK_ESCAPE) // Escape
			break;
		if (symbol >= 'A' && symbol <= 'Z')
			symbol = (int)symbol + 32;
		else if (symbol >= 'a' && symbol <= 'z')
			symbol = (int)symbol - 32;
		_putch(symbol);

	} while (true);
}

// Функция при вводе с клавиатуры текста заменяет цифры пробелами.
void ReplaceDigit()
{
	int symbol;
	do {
		symbol = _getch();
		if (symbol == VK_RETURN) // Enter
			symbol = '\n';
		if (symbol == VK_ESCAPE) // Escape
			break;
		symbol >= '0' && symbol <= '9' ? _putch(' ') : _putch(symbol);
	} while (true);
}

// Функция выполняет фильтрацию букв (игнорирует вывод введенных символов).
void Filter()
{
	int symbol;
	do {
		symbol = _getch();
		if (symbol == VK_RETURN) // Enter
			symbol = '\n';
		if (symbol == VK_ESCAPE) // Escape
			break;
		if (symbol >= 'A' && symbol <= 'Z' || symbol >= 'a' && symbol <= 'z')
			continue;
		_putch(symbol);
	} while (true);
}