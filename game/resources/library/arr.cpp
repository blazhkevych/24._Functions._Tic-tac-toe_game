#include <iostream>
#include <iomanip> // Содержит setw.
using namespace std;

// Функция инициализирует одномерный массив псевдослучайными числами с заданным диапазоном.
void InitArrayRandom(int arr[], int size, int min, int max)
{
	for (int i = 0; i < size; i++) // Заполняем одномерный массив псевдослучайными числами.
		arr[i] = rand() % (max - min + 1) + min;
}

// Функция инициализирует двумерный массив псевдослучайными числами с заданным диапазоном.
void InitArrayRandom(int arr[][4], int row, int min, int max)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 4; j++)
			arr[i][j] = rand() % (max - min + 1) + min;
	}
}

// Функция выводит двумерный массив на экран.
void PrintArray(int arr[][4], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << setw(4) << arr[i][j];
		cout << endl;
	}
}

// Функция выводит одномерный массив на экран.
void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << arr[i]; // setw(4) - Задает ширину поля отображения для следующего элемента в потоке.
}

// Функция реализует линейный поиск заданного ключа в двумерном массиве.
int LinearSearch(int arr[][4], int row, int key)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 4; j++)
			if (arr[i][j] == key)
				return i * 4 + j;
	}
	return -1;
}

// Функция реализует бинарный поиск заданного ключа в двумерном массиве.
int BinarySearch(int arr[][4], int row, int key)
{
	int left = 0, right = row * 4 - 1, index;
	while (left <= right)
	{
		index = (left + right) / 2;
		if (arr[index / 4][index % 4] == key)
			return index;
		else if (arr[index / 4][index % 4] > key)
			right = index - 1;
		else
			left = index + 1;
	}
	return -1;
}

// Функция сортировки двумерного массива.
void Sort(int arr[][4], int row)
{
	for (int i = 1; i < row * 4; i++)
	{
		int temp = arr[i / 4][i % 4];
		int j = i - 1;
		while (j >= 0 && arr[j / 4][j % 4] > temp)
		{
			arr[(j + 1) / 4][(j + 1) % 4] = arr[j / 4][j % 4];
			j--;
		}
		arr[(j + 1) / 4][(j + 1) % 4] = temp;
	}
}

// Функция сортировки одномерного массива (по возрастанию или убыванию).
void Sort(int arr[], int size, bool flag)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (!flag && arr[j - 1] > arr[j] || flag && arr[j - 1] < arr[j])
			{
				int x = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = x;
			}
		}
	}
}

// Функция сортирует первую половину одномерного массива по убыванию, а вторую - по возрастанию.
void SortHalfDescHalfAscend(int arr[], int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = (size - 1) / 2; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				int x = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = x;
			}
		}
	}
	for (int i = size / 2; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j - 1] < arr[j])
			{
				int x = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = x;
			}
		}
	}
}

// Функция сортирует элементы, в одномерном массиве, между двумя индексами, по возрастанию.
void SortBetweenTwoIndices(int arr[], int size, int firstInd, int lastInd)
{
	for (int i = firstInd + 1; i < lastInd; i++)
	{
		for (int j = lastInd - 1; j > i; j--)
		{
			if (arr[j - 1] < arr[j])
			{
				int x = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = x;
			}
		}
	}
}

// Функция меняющая порядок следования элементов передаваемого ей одномерного массива на противоположный.
void ReversesElemArray(int arr[], int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int temp{ arr[i] };
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}

// Функция находит позицию крайнего отрицательного элемента (самого левого отрицательного элемента).
int LeftmostNegElem(int arr[], int size)
{
	int position{ -1 };
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			position = i;
			return position;
		}
	}
}

// Функция находит позицию крайнего отрицательного элемента (самого правого отрицательного элемента).
int RightmostNegElem(int arr[], int size)
{
	int position{ -1 };
	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i] < 0)
		{
			position = i;
			return position;
		}
	}
}