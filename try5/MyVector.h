#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <Windows.h>


class MyVector {
	double* vec;
	int size;
public:
	MyVector();
	MyVector(int size_);
	MyVector(int size_, double vec_);
	/*~myVector();*/
	void setOnes();
	void operator=(MyVector vec_);
	MyVector operator+(MyVector vec_);
	MyVector operator-(MyVector vec_);
	double operator*(MyVector vec_);
	MyVector operator*(double number);
	friend MyVector operator*(MyVector vec_, double number);
	double norm();
	friend std::ostream& operator<<(std::ostream& output, MyVector vec_);
	friend std::istream& operator>>(std::istream& input, MyVector& vec_);
	void randomFilling(double min, double max);
	double& operator[](int number);
};
