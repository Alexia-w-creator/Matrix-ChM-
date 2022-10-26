#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <iomanip>
class My_vector
{
private:
	vector<double> a;
	//vector<float> a;
public:
	My_vector(vector<double> _a)
	{
		a = _a;
	}

	My_vector()
	{
	}
	My_vector(const My_vector& _a)
	{
		a = _a.a;
	}

	double& operator[] (int i)
	{
		return a[i - 1];
	}
	int size()
	{
		return a.size();
	}
	vector<double> getvec()
	{
		return a;
	}

	void setvec(int n = 0)
	{
		a.clear();
		if (n == 0)
		{
			cout << "\n¬ведите размерность вектора -> ";
			cin >> n;
		}
		cout << "\n¬ведите вектор\n";
		for (int i = 0; i < n; i++)
		{
			double _a;
			cin >> _a;
			a.push_back(_a);
		}
	}
	void setvecrand(int n, double min, double max)
	{
		a.clear();
		for (int i = 0; i < n; i++)
		{
			double _a = (double)(rand()) / RAND_MAX * (max - min) + min;;
			a.push_back(_a);
		}
	}

	friend ostream& operator << (ostream& wos, My_vector& _a)
	{
		int size = _a.size();
		for (int i = 0; i < size; i++)
			wos << setw(12) << _a.a[i];
		return wos;
	}

	My_vector operator - (const My_vector& _a)
	{
		vector<double> resv;
		int size = _a.a.size();
		for (int i = 0; i < size; i++)
			resv.push_back(a[i] - _a.a[i]);
		My_vector Res(resv);
		return Res;
	}
	My_vector operator + (const My_vector& _a)
	{
		vector<double> resv;
		int size = _a.a.size();
		for (int i = 0; i < size; i++)
			resv.push_back(a[i] + _a.a[i]);
		My_vector Res(resv);
		return Res;
	}
	My_vector operator = (const My_vector _a)
	{
		if (this != &_a)
		{
			a.clear();
			a = _a.a;
		}
		return *this;
	}
	My_vector operator = (const vector<double> _a)
	{
		a.clear();
		a = _a;
		return *this;
	}
	My_vector operator * (double k)
	{
		vector<double> resv;
		int size = a.size();
		for (int i = 0; i < size; i++)
			resv.push_back(a[i] * k);
		My_vector Res(resv);
		return Res;
	}


	//float ---------------------------------------------------------------------------
	//My_vector(vector<float> _a)
	//{
	//	a = _a;
	//}

	//float& operator[] (int i)
	//{
	//	return a[i - 1];
	//}

	//vector<float> getvec()
	//{
	//	return a;
	//}

	//void setvec(int n = 0)
	//{
	//	a.clear();
	//	if (n == 0)
	//	{
	//		cout << "\n¬ведите размерность вектора -> ";
	//		cin >> n;
	//	}
	//	cout << "\n¬ведите вектор\n";
	//	for (int i = 0; i < n; i++)
	//	{
	//		float _a;
	//		cin >> _a;
	//		a.push_back(_a);
	//	}
	//}
	//void setvecrand(int n, float min, float max)
	//{
	//	a.clear();
	//	for (int i = 0; i < n; i++)
	//	{
	//		float _a = (float)(rand()) / RAND_MAX * (max - min) + min;;
	//		a.push_back(_a);
	//	}
	//}


	//My_vector operator - (const My_vector& _a)
	//{
	//	vector<float> resv;
	//	int size = _a.a.size();
	//	for (int i = 0; i < size; i++)
	//		resv.push_back(a[i] - _a.a[i]);
	//	My_vector Res(resv);
	//	return Res;
	//}
	//My_vector operator + (const My_vector& _a)
	//{
	//	vector<float> resv;
	//	int size = _a.a.size();
	//	for (int i = 0; i < size; i++)
	//		resv.push_back(a[i] + _a.a[i]);
	//	My_vector Res(resv);
	//	return Res;
	//}
	//My_vector operator = (const My_vector _a)
	//{
	//	if (this != &_a)
	//	{
	//		a.clear();
	//		a = _a.a;
	//	}
	//	return *this;
	//}
	//My_vector operator = (const vector<float> _a)
	//{
	//	a.clear();
	//	a = _a;
	//	return *this;
	//}
	//My_vector operator * (float k)
	//{
	//	vector<float> resv;
	//	int size = a.size();
	//	for (int i = 0; i < size; i++)
	//		resv.push_back(a[i] * k);
	//	My_vector Res(resv);
	//	return Res;
	//}





};
