#include "Polynomial.h"
#include <algorithm>
#include <cmath>

//Деструктор
Polynomial::~Polynomial()
{
}

//Конструктор по умолчанию
Polynomial::Polynomial()
{
	//Задаем многочлен равным "0"
	this->coeffs.insert(0, 0);
}

//Конструктор копирования
Polynomial::Polynomial(const Polynomial& pol)
{
	this->coeffs = pol.coeffs;
}

//Функция, возвращающая новый многочлен, равный производной от исходного многочлена
Polynomial Polynomial::getDerivative() const
{
	Polynomial ans;
	for (int i = 1; i < this->coeffs.getSize(); i++)
	{
		if (i == 1)
			ans.coeffs[0] = this->coeffs[1];
		else
			ans.coeffs.insert(this->coeffs[i] * i, i - 1);
	}
	return ans;
}

//Функция, возвращающая значение многочлена в точке x, посчитаное схемой Горнера
double Polynomial::getValueInPoint(const double x) const
{
	double ans = this->coeffs[this->coeffs.getSize() - 1];
	for (int i = this->coeffs.getSize() - 2; i >= 0; i--)
	{
		ans *= x;
		ans += this->coeffs[i];
	}
	return ans;
}

//Перегрузка оператора присвоения "="
Polynomial& Polynomial::operator=(const Polynomial& pol)
{
	if (this == &pol)
		return *this;
	this->coeffs = pol.coeffs;
	return *this;
}

//Перегрузка оператора умножения "*"
Polynomial Polynomial::operator*(const Polynomial& pol) const
{
	Polynomial ans;
	for (int i = 0; i < ((this->coeffs.getSize() - 1) + (pol.coeffs.getSize() - 1)); i++)
		ans.coeffs.insert(0, i + 1);
	for (int i = 0; i < this->coeffs.getSize(); i++)
		for (int j = 0; j < pol.coeffs.getSize(); j++)
			ans.coeffs[i + j] += this->coeffs[i] * pol.coeffs[j];
	return ans;
}

//Перегрузка оператора умножения "*="
Polynomial& Polynomial::operator*=(const Polynomial& pol)
{
	*this = *this * pol;
	return *this;
}

//Перегрузка оператора сложения "+"
Polynomial Polynomial::operator+(const Polynomial& pol) const
{
	Polynomial ans;
	if (this->coeffs.getSize() > pol.coeffs.getSize())
	{
		ans = *this;
		for (int i = 0; i < pol.coeffs.getSize(); i++)
			ans.coeffs[i] += pol.coeffs[i];
	}
	else
	{
		ans = pol;
		for (int i = 0; i < this->coeffs.getSize(); i++)
			ans.coeffs[i] += this->coeffs[i];
	}
	return ans;
}

//Перегрузка оператора сложения "+="
Polynomial& Polynomial::operator+=(const Polynomial& pol)
{
	*this = *this + pol;
	return *this;
}

//Перегрузка вычитания "-"
Polynomial Polynomial::operator-(const Polynomial& pol) const
{
	Polynomial ans;
	if (this->coeffs.getSize() > pol.coeffs.getSize())
	{
		ans = *this;
		for (int i = 0; i < pol.coeffs.getSize(); i++)
			ans.coeffs[i] -= pol.coeffs[i];
	}
	else
	{
		ans = pol;
		for (int i = 0; i < ans.coeffs.getSize(); i++)
			ans.coeffs[i] *= -1;
		for (int i = 0; i < this->coeffs.getSize(); i++)
			ans.coeffs[i] += this->coeffs[i];
	}
	return ans;
}

//Перегрузка оператора вычитания "-="
Polynomial& Polynomial::operator-=(const Polynomial& pol)
{
	*this = *this - pol;
	return *this;
}

//Перегрузка оператора ввода ">>"
std::istream& operator>>(std::istream& sstream, Polynomial& pol)
{
	sstream >> pol.coeffs;
	if (pol.coeffs.getSize() == 0)
		pol.coeffs.insert(0, 0);
	return sstream;
}

//Перегрузка оператора вывода "<<"
std::ostream& operator<<(std::ostream& sstream, const Polynomial& pol)
{
	int cnt = 0;
	for(int i=0;i<pol.coeffs.getSize();i++)
		if (std::fabs(pol.coeffs[i]) > 0.000001)
		{
			if (i == 0)
				sstream << pol.coeffs[i];
			else
			{
				if (pol.coeffs[i] < 0)
					sstream << " - ";
				else
					if (cnt > 0)
						sstream << " + ";
				sstream << std::fabs(pol.coeffs[i]) << "x^" << i;
			}
			cnt++;
		}
	if (cnt == 0)
		sstream << "0";
	return sstream;
}
