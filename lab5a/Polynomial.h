#include "List.h"

//Класс Многочлен
class Polynomial
{
private:
	//Список для хранения коэффицентов многочлена
	List coeffs;
public:
	~Polynomial();
	Polynomial();
	Polynomial(const Polynomial&);
	Polynomial getDerivative() const;
	double getValueInPoint(const double) const;
	Polynomial& operator=(const Polynomial&);
	Polynomial operator*(const Polynomial&) const;
	Polynomial& operator*=(const Polynomial&);
	Polynomial operator+(const Polynomial&) const;
	Polynomial& operator+=(const Polynomial&);
	Polynomial operator-(const Polynomial&) const;
	Polynomial& operator-=(const Polynomial&);
	friend std::istream& operator >>(std::istream&, Polynomial&);
	friend std::ostream& operator <<(std::ostream&, const Polynomial&);
};
