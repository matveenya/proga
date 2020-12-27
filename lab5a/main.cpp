#include <iostream>
#include <clocale>
#include "Ring.h"
#include "Field.h"
#include "Polynomial.h"
#include "ModularArithmetic.h"

using namespace std;

int main()
{
	//�����������
	setlocale(LC_ALL, "Russian");
	cout << "������ ����� �����" << endl << endl;
	Ring<int> r1, r2;
	cout << "������� ������ �����: ";
	cin >> r1;
	cout << "������� ������ �����: ";
	cin >> r2;
	cout << r1 << " + " << r2 << " = " << (r1 + r2) << endl;
	cout << r1 << " - " << r2 << " = " << (r1 - r2) << endl;
	cout << r1 << " * " << r2 << " = " << (r1 * r2) << endl;
	cout << endl;
	cout << "������ �����������" << endl << endl;
	Ring<Polynomial> r11, r22;
	cout << "������� ����� n, ������ ������������ ������� ������� ���������� + 1" << endl;
	cout << "� ����� ������� ����������� ������� ���������� � ������� ����������� ��������" << endl;
	cin >> r11;
	cout << "������� ����� n, ������ ������������ ������� ������� ���������� + 1" << endl;
	cout << "� ����� ������� ����������� ������� ���������� � ������� ����������� ��������" << endl;
	cin >> r22;
	cout << r11 << " + " << r22 << " = " << (r11 + r22) << endl;
	cout << r11 << " - " << r22 << " = " << (r11 - r22) << endl;
	cout << r22 << " * " << r22 << " = " << (r11 * r22) << endl;
	cout << endl;
	cout << "������ ������� ������� ����� �����, ��������� �� ������" << endl << endl;
	int mod;
	cout << "������� ������: ";
	cin >> mod;
	if (mod < 1)
		mod = 1;
	Ring<ModularArithmetic> r111, r222;
	r111.data.setModule(mod);
	r222.data.setModule(mod);
	cout << "������� ������ �������: ";
	cin >> r111;
	cout << "������� ������ �������: ";
	cin >> r222;
	cout << r111 << " + " << r222 << " = " << (r111 + r222) << endl;
	cout << r111 << " - " << r222 << " = " << (r111 - r222) << endl;
	cout << r111 << " * " << r222 << " = " << (r111 * r222) << endl;
	cout << endl;
	cout << "���� ����������� �����" << endl << endl;
	Field <double> f1, f2;
	cout << "������� ������ �����: ";
	cin >> f1;
	cout << "������� ������ �����: ";
	cin >> f2;
	cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
	cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;
	cout << f1 << " * " << f2 << " = " << (f1 * f2) << endl;
	cout << f1 << " / " << f2 << " = " << (f1 / f2) << endl;
	cout << endl;
	system("pause");
	return 0;
}