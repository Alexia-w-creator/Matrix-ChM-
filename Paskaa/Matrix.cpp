//#pragma once
//#include <iostream>
//class Vector {
//	int v_N;
//	int* v_arr;
//public:
//	Vector();
//	Vector(int* arr);
//	Vector(int N);
//	Vector v_add(Vector second);
//	Vector v_sub(Vector second);
//	Vector v_scal(int num);
//	int norma();
//	void set_vector(int* arr);
//	void get_vector();
//};
//
//class Matrix : Vector {
//protected:  Vector m_a, m_b, m_c, m_p, m_q;
//public:
//	Matrix();
//	Matrix(Vector a, Vector b, Vector c, Vector k);
//	Matrix m_add(Matrix second);
//	Matrix m_sub(Matrix second);
//	Matrix m_multpl(Vector x);
//};


//#include "Matrix.h"
//#include <algorithm>
//
//Vector::Vector()
//{
//}
//
//Vector::Vector(int* arr)
//{
//	for (int i = 0; i < v_N; i++) {
//		v_arr[i] = arr[i];
//	}
//}
//
//Vector::Vector(int N)
//{
//	v_N = N;
//	int a;
//	std::cout << "Enter the matrix:";
//
//	for (int i = 0; i < v_N; i++) {
//		std::cin >> a;
//		v_arr[i] = a;
//	}
//}
//
//Vector Vector::v_add(Vector second)
//{
//	int* arr;
//	for (int i = 0; i < v_N; i++) {
//		arr[i] = v_arr[i] + second.v_arr[i];
//	}
//	return arr;
//}
//
//Vector Vector::v_sub(Vector second)
//{
//	int* arr;
//	for (int i = 0; i < v_N; i++) {
//		arr[i] = v_arr[i] - second.v_arr[i];
//	}
//	return arr;
//	
//}
//
//Vector Vector::v_scal(int num)
//{
//	int* arr;
//	for (int i = 0; i < v_N; i++) {
//		arr[i] = v_arr[i] * num;
//	}
//	return arr;
//}
//
//int Vector::norma()
//{
//	int max = 0;
//	for (int i = 0; i < v_N; i++) {
//		if (v_arr[i] > max) {
//			max = v_arr[i];
//		}
//	}
//	return abs(max);
//}
//
//void Vector::set_vector(int* arr)
//{
//	int a;
//	std::cout << "Enter the vector:";
//
//	for (int i = 0; i < v_N; i++) {
//		std::cin >> a;
//		v_arr[i] = a;
//	}
//}
//
//void Vector::get_vector()
//{
//	for (int i = 0; i < v_N; i++) {
//		std::cout << v_arr[i] << "/t";
//	}
//	std::cout << std::endl;
//}
//
//
//
//
//
//Matrix::Matrix()
//{
//}
//
//Matrix::Matrix(Vector a, Vector b, Vector c, Vector k)
//{
//	m_a = a;
//	m_b = b;
//	m_c = c;
//	m_k = k;
//}
//
//Matrix Matrix::m_add(Matrix second)
//{
//	Matrix res;
//	res.m_a = m_a.v_add(second.m_a);
//	res.m_b = m_b.v_add(second.m_b);
//	res.m_c = m_c.v_add(second.m_c);
//	res.m_k = m_k.v_add(second.m_k);
//	return res;
//}
//
//Matrix Matrix::m_sub(Matrix second)
//{
//	Matrix res;
//	res.m_a = m_a.v_sub(second.m_a);
//	res.m_b = m_b.v_sub(second.m_b);
//	res.m_c = m_c.v_sub(second.m_c);
//	res.m_k = m_k.v_sub(second.m_k);
//	return res;
//}
//
//Matrix Matrix::m_multpl(Vector x)
//{
//	for ()
//	return ;
//}