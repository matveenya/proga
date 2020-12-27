/**
������� ����� BitString ��� ������ � 64-�������� ��������. ������� ������ ������ ���� ������������ ����� ������ ���� unsigned.
������ ���� ����������� � ���� ������������� �������� ��� ������������ �������� ��� ������ � ������: and, or, xor, not.
����������� ����� ����� � ����� ������ �� �������� ���������� ���.
**/

#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// ����� ��� ������ � �������� ��������
class  BitString
{
private:
	//���������� ��� �������� ������ 32 ��������
	unsigned bit1;
	//���������� ��� �������� ������ 32 ��������
	unsigned bit2;
public:
	//����������
	~BitString()
	{}

	//����������� �� ���������
	BitString()
	{
		this->bit1 = 0;
		this->bit2 = 0;
	}

	//����������� � �����������
	BitString(const unsigned bit1, const unsigned bit2)
	{
		this->bit1 = bit1;
		this->bit2 = bit2;
	}

	//����������� �����������
	BitString(const BitString& bitstr)
	{
		this->bit1 = bitstr.bit1;
		this->bit2 = bitstr.bit2;
	}

	//�������, ������������ �������� ���������� bit1
	unsigned getBit1() const
	{
		return this->bit1;
	}

	//�������, ������������ �������� ���������� bit2
	unsigned getBit2() const
	{
		return this->bit2;
	}

	//�������, �������� ����� �������� ���������� bit1
	void setBit1(const unsigned bit1)
	{
		this->bit1 = bit1;
	}

	//�������, �������� ����� �������� ���������� bit2
	void setBit2(const unsigned bit2)
	{
		this->bit2 = bit2;
	}

	//���������� ��������� ">>" ��� �����
	friend istream& operator >>(istream& sstream, BitString& bitstr)
	{
		string s;
		//������ ������� � ������
		sstream >> s;
		//�������� ������ �������� ������ � ���������� ����� � ���������� � ���������� bit1
		bitstr.bit1 = 0;
		unsigned pow2 = 1;
		for (int i = 0; i < 32; i++)
		{
			bitstr.bit1 += pow2 * (s[i] - '0');
			pow2 *= 2;
		}
		//�������� ������ �������� ������ � ���������� ����� � ���������� � ���������� bit2
		bitstr.bit2 = 0;
		pow2 = 1;
		for (int i = 32; i < 64; i++)
		{
			bitstr.bit2 += pow2 * (s[i] - '0');
			pow2 *= 2;
		}
		return sstream;
	}

	//���������� ��������� "<<" ��� ������
	friend ostream& operator <<(ostream& sstream, const BitString& bitstr)
	{
		//������� �������� ������������� ������� �����
		for (unsigned i = 0; i < 32; i++)
			sstream << ((bitstr.bit1 >> i) & 1);
		//������� �������� ������������� ������� �����
		for (unsigned i = 0; i < 32; i++)
			sstream << ((bitstr.bit2 >> i) & 1);
		return sstream;
	}

	//���������� ��������� "="
	BitString& operator =(const BitString& bitstr)
	{
		if (this == &bitstr)
			return *this;
		this->bit1 = bitstr.bit1;
		this->bit2 = bitstr.bit2;
		return *this;
	}

	//���������� ��������� ��������� "&"
	BitString operator &(const BitString& bitstr) const
	{
		return BitString((this->bit1 & bitstr.bit1), (this->bit2 & bitstr.bit2));
	}

	//���������� ��������� ��������� "&="
	BitString& operator &=(const BitString& bitstr)
	{
		this->bit1 &= bitstr.bit1;
		this->bit2 &= bitstr.bit2;
		return *this;
	}

	//���������� ��������� ��������� "|"
	BitString operator |(const BitString& bitstr) const
	{
		return BitString((this->bit1 | bitstr.bit1), (this->bit2 | bitstr.bit2));
	}

	//���������� ��������� ��������� "|="
	BitString& operator |=(const BitString& bitstr)
	{
		this->bit1 |= bitstr.bit1;
		this->bit2 |= bitstr.bit2;
		return *this;
	}

	//���������� ��������� ��������� "^"
	BitString operator ^(const BitString& bitstr) const
	{
		return BitString((this->bit1 ^ bitstr.bit1), (this->bit2 ^ bitstr.bit2));
	}

	//���������� ��������� ��������� "^="
	BitString& operator ^=(const BitString& bitstr)
	{
		this->bit1 ^= bitstr.bit1;
		this->bit2 ^= bitstr.bit2;
		return *this;
	}

	//���������� ��������� ��������� "~"
	BitString operator ~() const
	{
		return BitString(~this->bit1, ~this->bit2);
	}

	//���������� ��������� ��������� "<<"
	BitString operator <<(const int n)
	{
		//���� ���������� ���, �� ������� ���� ����������� �����, ������ 64, �� ����� �� ������ 64
		int normal_n = n % 64;
		unsigned b1 = 0, b2 = 0;
		//���������� �������� ������ � ������
		string s = "";
		for (unsigned i = 0; i < 32; i++)
			s += ((this->bit1 >> i) & 1) ? "1" : "0";
		for (unsigned i = 0; i < 32; i++)
			s += ((this->bit2 >> i) & 1) ? "1" : "0";
		//��������� normal_n �������� �� ������ � ����� ������, �.�. �������� ������ �� normal_n �������� �����
		s = s.substr(normal_n) + s.substr(0, normal_n);
		//������������� �������� ���������� ��� �������� �������� ������
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

	//���������� ��������� ��������� "<<="
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

	//���������� ��������� ��������� ">>"
	BitString operator >>(const int n)
	{
		int normal_n = n % 64;
		unsigned b1 = 0, b2 = 0;
		string s = "";
		for (unsigned i = 0; i < 32; i++)
			s += ((this->bit1 >> i) & 1) ? "1" : "0";
		for (unsigned i = 0; i < 32; i++)
			s += ((this->bit2 >> i) & 1) ? "1" : "0";
		//��������� normal_n �������� �� ����� � ������ ������, �.�. �������� ������ �� normal_n �������� ������
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

	//���������� ��������� ��������� ">>="
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
	cout << "������ ������� ������:" << endl;
	cout << bitstr1 << endl;
	cout << "������ ������� ������:" << endl;
	cout << bitstr2 << endl;
	cout << endl;
	cout << "������� and:" << endl;
	cout << (bitstr1 & bitstr2) << endl;
	cout << endl;
	cout << "������� or:" << endl;
	cout << (bitstr1 | bitstr2) << endl;
	cout << endl;
	cout << "������� xor:" << endl;
	cout << (bitstr1 ^ bitstr2) << endl;
	cout << endl;
	cout << "������� not ��� ������ ������� ������:" << endl;
	cout << (~bitstr1) << endl;
	cout << endl;
	int k;
	do {
		cout << "������� �� ����� ���������� ��� �������� ������� ������: ";
		cin >> k;
		if (k < 0)
		{
			cout << "������! ������� ��������������� �����" << endl;
			continue;
		}
		break;
	} while (true);
	cout << endl;
	cout << "����� ����� ��� ������ ������� ������:" << endl;
	cout << (bitstr1 << k) << endl;
	cout << endl;
	cout << "����� ������ ��� ������ ������� ������:" << endl;
	cout << (bitstr1 >> k) << endl;
	fin.close();
	system("pause");
	return 0;
}