#include <iostream>
#include <clocale>
#include <windows.h>
#include "Matrix.h"

using namespace std;

//������������� ������ Matrix �������, �������� ������� ������ � ��������
void funct(Matrix* arr, const int& m, const int* col_index, int** row_indexes)
{
	//���� �� ������� ������
	for (int i(0); i < m; ++i)
	{
		//���������� ����� ������� ��� ������������ � ����������� ������� ��������� � ������ � �������� 0
		int index_max(0), index_min(0);
		//���������� �������� col_index[i]-��� ������� � ������ � �������� 0
		int min_el(arr[i].matrix[0][col_index[i]]), max_el(arr[i].matrix[0][col_index[i]]);
		//���� �� ������� � ������� � ����� ������� ��������� ����������� � ����������� ������� col_index[i]-��� �������
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
		//������ ��� ������ �������
		int* tmp = arr[i].matrix[index_min];
		arr[i].matrix[index_min] = arr[i].matrix[index_max];
		arr[i].matrix[index_max] = tmp;
		//���������� ������� �����, ������� �� ��������
		row_indexes[i][0] = index_min;
		row_indexes[i][1] = index_max;
	}
}

int main()
{
	//�����������
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int m; //���������� ��� �������� ������� �������
	cout << "������� ������ �������: ";
	cin >> m;
	Matrix* arr = nullptr; //���������� ��� �������� ������� ������
	int* col_index = nullptr; //���������� ��� �������� �������� ��������, �� �������� ������� ���� �������� ������� ������
	int** row_indexes = nullptr; //���������� ��� �������� �������� �����, ������� �� �������� �������
	//�������� ������
	try {
		if (m <= 0)
			throw Exception("������! ������������ �������� ��� ��������� ������");
		arr = new (nothrow) Matrix[m];
		col_index = new (nothrow) int[m];
		row_indexes = new (nothrow) int* [m];
		if (!arr || !col_index || !row_indexes)
			throw Exception("������ ��������� ������!");
		for (int i(0); i < m; ++i)
		{
			row_indexes[i] = new (nothrow) int[2];
			if (!row_indexes[i])
				throw Exception("������ ��������� ������!");
		}
	}
	catch (const Exception& e)
	{
		std::cout << e.what() << '\n';
		system("pause");
		exit(1);
	}
	cout << endl << "������� ������ ������:" << endl << endl;
	for (int i(0); i < m; ++i)
	{
		cout << "������� ������� ������, � ����� �������� " << (i + 1) << "-�� �������:" << endl;
		cin >> arr[i];
		//����������� ����, ��� ����� ������� �������
		do {
			cout << "������� ������ �������, �������� �������� ���������� ����������: ";
			cin >> col_index[i];
			if ((col_index[i] < 0) || (col_index[i] >= arr[i].get_n()))
			{
				cout << "������! ������������ ������\n";
				//���� ����� ������������ ������, �� �������� ��������� ����� � ������
				continue;
			}
			//����� �� ������������ �����
			break;
		} while (true);
		cout << endl;
	}
	cout << endl << "������ �������..." << endl << endl << endl;
	funct(arr, m, col_index, row_indexes);
	cout << "������ ������ ����� ������ �������:" << endl << endl;
	for (int i(0); i < m; ++i)
	{
		cout << (i + 1) << "-�� �������:" << endl;
		cout << arr[i];
		cout << "�������� ������� ������ � ��������� " << row_indexes[i][0] << " � " << row_indexes[i][1] << endl << endl;
	}
	//������� ������
	delete[] arr;
	delete[] col_index;
	for (int i(0); i < m; ++i)
		delete[] row_indexes[i];
	delete[] row_indexes;
	system("pause");
	return 0;
}