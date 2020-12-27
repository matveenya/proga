#pragma once
#include <iostream>
#include "Exception.h"

//Класс Матрица
class Matrix
{
private:
	int n; //Размер матрицы n*n
	int** matrix; //Двумерный массив для хранения элементов матрицы
public:
	~Matrix();
	Matrix();
	Matrix(const int* const*, const int&);
	Matrix(const Matrix&);
	int get_n() const;
	const int* const* get_matrix() const;
	int get_elemnt(const int&, const int&) const;
	void set_matrix_and_n(const int* const*, const int&);
	Matrix& operator= (const Matrix&);
	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	friend void funct(Matrix*, const int&, const int*, int**);
};