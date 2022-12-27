#pragma once
#include "MyVector.h"

class Matrix {
	MyVector a;
	MyVector b;
	MyVector c;
	MyVector p;
	MyVector q;
	int k;
	int size;
	void ABCtoPQ();
	void PQtoABC();
public:
	Matrix();
	Matrix(int size_, int k_);
	void randomFilling(double x, double y);
	Matrix operator+(Matrix matr);
	Matrix operator-(Matrix matr);
	MyVector operator*(MyVector vec);
	MyVector result(MyVector f, Matrix M, MyVector xx);
	void operator=(Matrix matr);
	friend std::ostream& operator<<(std::ostream& output, Matrix matr);
	friend std::istream& operator>>(std::istream& input, Matrix& matr);
};
