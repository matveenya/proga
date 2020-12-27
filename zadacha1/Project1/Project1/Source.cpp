#include <iostream>
#include <clocale>
#include <windows.h>
#include "Matrix.h"

using namespace std;

//Дружественная классу Matrix функция, меняющая местами строки в матрицах
void funct(Matrix* arr, const int& m, const int* col_index, int** row_indexes)
{
	//Идем по массиву матриц
	for (int i(0); i < m; ++i)
	{
		//Изначально будем считать что максимальный и минимальный элемент находится в строке с индексом 0
		int index_max(0), index_min(0);
		//Запоминаем элементы col_index[i]-ого столбца в строке с индексом 0
		int min_el(arr[i].matrix[0][col_index[i]]), max_el(arr[i].matrix[0][col_index[i]]);
		//Идем по матрице и находим в каких строках находится минимальный и макимальный элемент col_index[i]-ого столбца
		for (int j(1); j < arr[i].n; ++j)
		{
			if (arr[i].matrix[j][col_index[i]] < min_el)
			{
				min_el = arr[i].matrix[j][col_index[i]];
				index_min = j;
			}
			if (arr[i].matrix[j][col_index[i]] > max_el)
			{
				max_el = arr[i].matrix[j][col_index[i]];
				index_max = j;
			}
		}
		//Меняем эти строки местами
		int* tmp = arr[i].matrix[index_min];
		arr[i].matrix[index_min] = arr[i].matrix[index_max];
		arr[i].matrix[index_max] = tmp;
		//Запоминаем индексы строк, которые мы поменяли
		row_indexes[i][0] = index_min;
		row_indexes[i][1] = index_max;
	}
}

int main()
{
	//Русификатор
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int m; //Переменная для хранения размера массива
	cout << "Введите размер массива: ";
	cin >> m;
	Matrix* arr = nullptr; //Переменная для хранения массива матриц
	int* col_index = nullptr; //Переменная для хранения индексов столбцов, по элемнтам которых надо поменять местами строки
	int** row_indexes = nullptr; //Переменная для хранения индексов строк, которые мы поменяли местами
	//Выделяем память
	try {
		if (m <= 0)
			throw Exception("Ошибка! Некорректное значение для выделения памяти");
		arr = new (nothrow) Matrix[m];
		col_index = new (nothrow) int[m];
		row_indexes = new (nothrow) int* [m];
		if (!arr || !col_index || !row_indexes)
			throw Exception("Ошибка выделения памяти!");
		for (int i(0); i < m; ++i)
		{
			row_indexes[i] = new (nothrow) int[2];
			if (!row_indexes[i])
				throw Exception("Ошибка выделения памяти!");
		}
	}
	catch (const Exception& e)
	{
		std::cout << e.what() << '\n';
		system("pause");
		exit(1);
	}
	cout << endl << "Введите массив матриц:" << endl << endl;
	for (int i(0); i < m; ++i)
	{
		cout << "Введите сначала размер, а затем элементы " << (i + 1) << "-ой матрицы:" << endl;
		cin >> arr[i];
		//Бесконечный цикл, для ввода индекса столбца
		do {
			cout << "Введите индекс столбца, элементы которого необходимо сравнивать: ";
			cin >> col_index[i];
			if ((col_index[i] < 0) || (col_index[i] >= arr[i].get_n()))
			{
				cout << "Ошибка! Некорректный индекс\n";
				//Если ввели некорректный индекс, то начинаем выполение цикла с начала
				continue;
			}
			//Выход из бесконечного цикла
			break;
		} while (true);
		cout << endl;
	}
	cout << endl << "Работа функции..." << endl << endl << endl;
	funct(arr, m, col_index, row_indexes);
	cout << "Массив матриц после работы функции:" << endl << endl;
	for (int i(0); i < m; ++i)
	{
		cout << (i + 1) << "-ая матрица:" << endl;
		cout << arr[i];
		cout << "Поменяли местами строки с индексами " << row_indexes[i][0] << " и " << row_indexes[i][1] << endl << endl;
	}
	//Очищаем память
	delete[] arr;
	delete[] col_index;
	for (int i(0); i < m; ++i)
		delete[] row_indexes[i];
	delete[] row_indexes;
	system("pause");
	return 0;
}