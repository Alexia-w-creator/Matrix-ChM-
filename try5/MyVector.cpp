#pragma once
#include "MyVector.h"



MyVector::MyVector() {
	size = 3;
	vec = new double[3];
	for (int i = 0; i < 3; i++)
		vec[i] = 0;
}

MyVector::MyVector(int size_) {
	size = size_;
	vec = new double[size_];
	for (int i = 0; i < size; i++)
		vec[i] = 0;
}

MyVector::MyVector(int size_, double vec_) {
	size = size_;
	vec = new double[size_];
	for (int i = 0; i < size; i++)
		vec[i] = vec_;
}

//myVector::~myVector() {
//	delete[] mas;
//}

void MyVector::setOnes()
{
	for (int i = 0; i < size; i++)
		vec[i] = 1;
}

void MyVector::operator=(MyVector vec_) {
	delete[] vec;
	vec = new double[vec_.size];
	size = vec_.size;
	for (int i = 0; i < size; i++)
		vec[i] = vec_.vec[i];
}

MyVector MyVector::operator+(MyVector vec_) {
	MyVector temp(size);
	for (int i = 0; i < size; i++)
		temp.vec[i] = vec[i] + vec_.vec[i];
	return temp;
}

MyVector MyVector::operator-(MyVector vec_) {
	MyVector temp(size);
	for (int i = 0; i < size; i++)
		temp.vec[i] = vec[i] - vec_.vec[i];
	return temp;
}

double MyVector::operator*(MyVector vec_) {
	double temp = 0;
	for (int i = 0; i < size; i++)
		temp += vec[i] * vec_.vec[i];
	return temp;
}

MyVector MyVector::operator*(double number) {
	MyVector temp(size);
	for (int i = 0; i < size; i++)
		temp.vec[i] = vec[i] * number;
	return temp;
}

double MyVector::norm() {
	double temp1 = abs(vec[0]);
	for (int i = 1; i < size; i++) {
		double temp2 = abs(vec[i]);
		if (temp2 > temp1)
			temp1 = temp2;
	}
	return temp1;
}

void MyVector::randomFilling(double min, double max) {
	int temp = max / min;
	for (int i = 0; i < size; i++)
		vec[i] = (min + rand() % temp * min)/10;
}

double& MyVector::operator[](int number) {
	return (vec[number - 1]);
}

MyVector operator*(MyVector vec_, double number) {
	MyVector temp(vec_.size);
	for (int i = 0; i < vec_.size; i++)
		temp.vec[i] = vec_.vec[i] * number;
	return temp;
}

std::ostream& operator<<(std::ostream& output, MyVector vec_) {
	for (int i = 0; i < vec_.size; i++)
		output << vec_.vec[i] << ' ';
	output << '\n';
	return output;
}

std::istream& operator>>(std::istream& input, MyVector& vec_) {
	for (int i = 0; i < vec_.size; i++)
		input >> vec_.vec[i];
	return input;
}
