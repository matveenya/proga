/**
Создать класс BitString для работы с 64-битовыми строками. Битовая строка должна быть представлена двумя полями типа unsigned.
Должны быть реализованы в виде перегруженных операций все традиционные операции для работы с битами: and, or, xor, not.
Реализовать сдвиг влево и сдвиг вправо на заданное количество бит.
**/

#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// Класс для работы с битовыми строками
class  BitString
{
private:
	//Переменная для хранения первых 32 символов
	unsigned bit1;
	//Переменная для хранения вторых 32 символов
	unsigned bit2;
public:
	//Деструктор
	~BitString()
	{}

	//Конструктор по умолчанию
	BitString()
	{
		this->bit1 = 0;
		this->bit2 = 0;
	}

	//Конструктор с параметрами
	BitString(const unsigned bit1, const unsigned bit2)
	{
		this->bit1 = bit1;
		this->bit2 = bit2;
	}

	//Конструктор копирования
	BitString(const BitString& bitstr)
	{
		this->bit1 = bitstr.bit1;
		this->bit2 = bitstr.bit2;
	}

	//Функция, возвращающая значение переменной bit1
	unsigned getBit1() const
	{
		return this->bit1;
	}

	//Функция, возвращающая значение переменной bit2
	unsigned getBit2() const
	{
		return this->bit2;
	}

	//Функция, задающая новое значение переменной bit1
	void setBit1(const unsigned bit1)
	{
		this->bit1 = bit1;
	}

	//Функция, задающая новое значение переменной bit2
	void setBit2(const unsigned bit2)
	{
		this->bit2 = bit2;
	}

	//Перегрузка оператора ">>" для ввода
	friend istream& operator >>(istream& sstream, BitString& bitstr)
	{
		string s;
		//Читаем символы в строку
		sstream >> s;
		//Перводим первую половину строки в десятичное число и записываем в переменную bit1
		bitstr.bit1 = 0;
		unsigned pow2 = 1;
		for (int i = 0; i < 32; i++)
		{
			bitstr.bit1 += pow2 * (s[i] - '0');
			pow2 *= 2;
		}
		//Перводим вторую половину строки в десятичное число и записываем в переменную bit2
		bitstr.bit2 = 0;
		pow2 = 1;
		for (int i = 32; i < 64; i++)
		{
			bitstr.bit2 += pow2 * (s[i] - '0');
			pow2 *= 2;
		}
		return sstream;
	}

	//Перегрузка оператора "<<" для вывода
	friend ostream& operator <<(ostream& sstream, const BitString& bitstr)
	{
		//Выводим двоичное представление первого числа
		for (unsigned i = 0; i < 32; i++)
			sstream << ((bitstr.bit1 >> i) & 1);
		//Выводим двоичное представление второго числа
		for (unsigned i = 0; i < 32; i++)
			sstream << ((bitstr.bit2 >> i) & 1);
		return sstream;
	}

	//Перегрузка оператора "="
	BitString& operator =(const BitString& bitstr)
	{
		if (this == &bitstr)
			return *this;
		this->bit1 = bitstr.bit1;
		this->bit2 = bitstr.bit2;
		return *this;
	}

	//Перегрузка бинарного оператора "&"
	BitString operator &(const BitString& bitstr) const
	{
		return BitString((this->bit1 & bitstr.bit1), (this->bit2 & bitstr.bit2));
	}

	//Перегрузка бинарного оператора "&="
	BitString& operator &=(const BitString& bitstr)
	{
		this->bit1 &= bitstr.bit1;
		this->bit2 &= bitstr.bit2;
		return *this;
	}

	//Перегрузка бинарного оператора "|"
	BitString operator |(const BitString& bitstr) const
	{
		return BitString((this->bit1 | bitstr.bit1), (this->bit2 | bitstr.bit2));
	}

	//Перегрузка бинарного оператора "|="
	BitString& operator |=(const BitString& bitstr)
	{
		this->bit1 |= bitstr.bit1;
		this->bit2 |= bitstr.bit2;
		return *this;
	}

	//Перегрузка бинарного оператора "^"
	BitString operator ^(const BitString& bitstr) const
	{
		return BitString((this->bit1 ^ bitstr.bit1), (this->bit2 ^ bitstr.bit2));
	}

	//Перегрузка бинарного оператора "^="
	BitString& operator ^=(const BitString& bitstr)
	{
		this->bit1 ^= bitstr.bit1;
		this->bit2 ^= bitstr.bit2;
		return *this;
	}

	//Перегрузка бинарного оператора "~"
	BitString operator ~() const
	{
		return BitString(~this->bit1, ~this->bit2);
	}

	//Перегрузка бинарного оператора "<<"
	BitString operator <<(const int n)
	{
		//Если количество бит, на которое надо ощуществить сдвиг, больше 64, то берем по модулю 64
		int normal_n = n % 64;
		unsigned b1 = 0, b2 = 0;
		//Записываем бинарную строку в строку
		string s = "";
		for (unsigned i = 0; i < 32; i++)
			s += ((this->bit1 >> i) & 1) ? "1" : "0";
		for (unsigned i = 0; i < 32; i++)
			s += ((this->bit2 >> i) & 1) ? "1" : "0";
		//Переносим normal_n символов из начала в конец строки, т.е. сдвигаем строку на normal_n символов влево
		s = s.substr(normal_n) + s.substr(0, normal_n);
		//Пересчитываем значения переменных для хранения бинарной строки
		unsigned pow2 = 1;
		for (int i = 0; i < 32; i++)
		{
			b1 += pow2 * (s[i] - '0');
			pow2 *= 2;
		}
		pow2 = 1;
		for (int i = 32; i < 64; i++)
		{
			b2 += pow2 * (s[i] - '0');
			pow2 *= 2;
		}
		return BitString(b1, b2);
	}

	//Перегрузка бинарного оператора "<<="
	BitString operator <<=(const int n)
	{
		int normal_n = n % 64;
		string s = "";
		for (unsigned i = 0; i < 32; i++)
			s += ((this->bit1 >> i) & 1) ? "1" : "0";
		for (unsigned i = 0; i < 32; i++)
			s += ((this->bit2 >> i) & 1) ? "1" : "0";
		s = s.substr(normal_n) + s.substr(0, normal_n);
		for (int i = 0; i < normal_n; i++)
			s += "0";
		unsigned pow2 = 1;
		this->bit1 = 0;
		this->bit2 = 0;
		for (int i = 0; i < 32; i++)
		{
			this->bit1 += pow2 * (s[i] - '0');
			pow2 *= 2;
		}
		pow2 = 1;
		for (int i = 32; i < 64; i++)
		{
			this->bit2 += pow2 * (s[i] - '0');
			pow2 *= 2;
		}
		return *this;
	}

	//Перегрузка бинарного оператора ">>"
	BitString operator >>(const int n)
	{
		int normal_n = n % 64;
		unsigned b1 = 0, b2 = 0;
		string s = "";
		for (unsigned i = 0; i < 32; i++)
			s += ((this->bit1 >> i) & 1) ? "1" : "0";
		for (unsigned i = 0; i < 32; i++)
			s += ((this->bit2 >> i) & 1) ? "1" : "0";
		//Переносим normal_n символов из конца в начало строки, т.е. сдвигаем строку на normal_n символов вправо
		s = s.substr(64 - normal_n, normal_n) + s.substr(0, 64 - normal_n);
		unsigned pow2 = 1;
		for (int i = 0; i < 32; i++)
		{
			b1 += pow2 * (s[i] - '0');
			pow2 *= 2;
		}
		pow2 = 1;
		for (int i = 32; i < 64; i++)
		{
			b2 += pow2 * (s[i] - '0');
			pow2 *= 2;
		}
		return BitString(b1, b2);
	}

	//Перегрузка бинарного оператора ">>="
	BitString operator >>=(const int n)
	{
		int normal_n = n % 64;
		string s = "";
		for (unsigned i = 0; i < 32; i++)
			s += ((this->bit1 >> i) & 1) ? "1" : "0";
		for (unsigned i = 0; i < 32; i++)
			s += ((this->bit2 >> i) & 1) ? "1" : "0";
		s = s.substr(64 - normal_n, normal_n) + s.substr(0, 64 - normal_n);
		unsigned pow2 = 1;
		this->bit1 = 0;
		this->bit2 = 0;
		for (int i = 0; i < 32; i++)
		{
			this->bit1 += pow2 * (s[i] - '0');
			pow2 *= 2;
		}
		pow2 = 1;
		for (int i = 32; i < 64; i++)
		{
			this->bit2 += pow2 * (s[i] - '0');
			pow2 *= 2;
		}
		return *this;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin("input.txt");
	BitString bitstr1, bitstr2;
	fin >> bitstr1 >> bitstr2;
	cout << "Первая битовая строка:" << endl;
	cout << bitstr1 << endl;
	cout << "Вторая битовая строка:" << endl;
	cout << bitstr2 << endl;
	cout << endl;
	cout << "Оперция and:" << endl;
	cout << (bitstr1 & bitstr2) << endl;
	cout << endl;
	cout << "Оперция or:" << endl;
	cout << (bitstr1 | bitstr2) << endl;
	cout << endl;
	cout << "Оперция xor:" << endl;
	cout << (bitstr1 ^ bitstr2) << endl;
	cout << endl;
	cout << "Оперция not для первой битовой строки:" << endl;
	cout << (~bitstr1) << endl;
	cout << endl;
	int k;
	do {
		cout << "Введите на какое количество бит сдвигать битовую строку: ";
		cin >> k;
		if (k < 0)
		{
			cout << "Ошибка! Введите неотрицательное число" << endl;
			continue;
		}
		break;
	} while (true);
	cout << endl;
	cout << "Сдвиг влево для первой битовой строки:" << endl;
	cout << (bitstr1 << k) << endl;
	cout << endl;
	cout << "Сдвиг вправо для первой битовой строки:" << endl;
	cout << (bitstr1 >> k) << endl;
	fin.close();
	system("pause");
	return 0;
}