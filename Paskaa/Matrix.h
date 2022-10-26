#pragma once
#include "Vector.h"
class Matrix
{
private:
	void agreement()
	{
		int n = a.size();
		a[1] = 0;
		c[n] = 0;
		if (n > 1)
		{
			p[n-k] = c[k];     //p[1] = c[n - 1]
			q[n-k] = b[k+1];   //q[1] = b[n]
			p[n-k+1] = b[k];   //;p[2] = b[n - 1]
			q[n-k+1] = a[k+1]; //;q[2] = a[n]
		}
		if (n > 2)
			p[n-k+2] = a[k];   //;p[3] = a[n - 1]
	}
public:
	My_vector a, b, c, p, q;
	int k;
public:
	Matrix() {}
	/*Matrix(vector<double> _a, vector<double> _b, vector<double> _c, vector<double> _p, vector<double> _q)
	{
		a = _a;
		b = _b;
		c = _c;
		p = _p;
		q = _q;
	}*/
	Matrix(My_vector _a, My_vector _b, My_vector _c, My_vector _p, My_vector _q, int _k)
	{
		a = _a;
		b = _b;
		c = _c;
		p = _p;
		q = _q;
		k = _k; // rand
	}
	Matrix(const Matrix& _A)
	{
		a = _A.a;
		b = _A.b;
		c = _A.c;
		p = _A.p;
		q = _A.q;
		k = _A.k;
	}

	//обращение по индексу
	double& operator[] (int l)
	{
		double res = 0;
		int n = a.size();
		if (l <= n * n)
		{
			int s = l - 1;
			int i = s / n, j = s % n;
			//return a[i];
			if (i < n - 2)
			{
				int t = i + j;
				if (t == n - 1) res = b[i + 1];
				if (t == n - 2) res = c[i + 1];
				if (t == n) res = a[i + 1];
			}
			if (i == n - 2) res = p[j + 1];
			if (i == n - 1) res = q[j + 1];
		}
		else cout << "\nОшибка! Индекс вне границ матрицы. Возвращён 0";
		return res;
	}

	//размер матрицы
	int size()
	{
		return a.size();
	}


	//задать матрицу
	void setmat()
	{
		int n = 0;
		cout << "\nВведите размерность матрицы ";
		cin >> n;
		cout << "\nВыберите тип заполнения";
		int s;
		cout << "\n1) Заполнить вручную";
		cout << "\n2) Зполнить рандомными(дробными) числами из интервала\n";
		cin >> s;
		switch (s)
		{
		case 1:
		{
			cout << "\nЗаполните каждый из составляющих векторов(согласование по векторам a,b,c)";
			cout << "\n Вектор а";
			a.setvec(n);
			cout << "\n Вектор b";
			b.setvec(n);
			cout << "\n Вектор c";
			c.setvec(n);
			cout << "\n Вектор p";
			p.setvec(n);
			cout << "\n Вектор q";
			q.setvec(n);
			break;
		}
		case 2:
		{
			double min, max;
			cout << "\nВведите нижнюю и верхнюю границу интервала для a, c -> ";
			cin >> min >> max;
			a.setvecrand(n, min, max);
			c.setvecrand(n, min, max);
			//cout << "\nВведите верхнюю границу интервала -> ";

			cout << "\nВведите нижнюю и верхнюю границу интервала для p, q -> ";
			cin >> min >> max;
			p.setvecrand(n, min, max);
			q.setvecrand(n, min, max);

			cout << "\nВведите нижнюю и верхнюю границу интервала для b -> ";
			cin >> min >> max;
			b.setvecrand(n, min, max);


			//agreement();
			break;
		}
		default:
			break;
		}
		agreement();

		/*cout << "\nЗаполните каждый из составляющих векторов ";
		cout << "\n Вектор а";
		a.setvec(n);
		cout << "\n Вектор b";
		b.setvec(n);
		cout << "\n Вектор c";
		c.setvec(n);
		cout << "\n Вектор p";
		p.setvec(n);
		cout << "\n Вектор q";
		q.setvec(n);*/
		//проверка согласованности

	}

	//вывод матрицы на консоль
	friend ostream& operator << (ostream& wos, Matrix& A)
	{
		int n = A.size();
		//первая строка
		for (int i = 1; i < n - 1; i++)
			wos << setw(12) << 0;
		wos << setw(12) << A.c[1] << setw(12) << A.b[1] << "\n";
		//строки со 2-й по k
   		for (int i = 2; i < A.k; i++)
		{
			for (int j = 1; j < n - i; j++)
				wos << setw(12) << 0;
			wos << setw(12) << A.c[i] << setw(12) << A.b[i] << setw(12) << A.a[i];
			for (int j = n - i + 3; j <= n; j++)
				wos << setw(12) << 0;
			wos << "\n";
		}
		//вектор p, q
		wos << A.p;
		wos << "\n";
		wos << A.q;
		wos << "\n";
		//от (k + 2) до (n - 1)(включительно)
		for (int i = A.k + 2; i < n; i++)
		{
			for (int j = 1; j < n - i; j++)
				wos << setw(12) << 0;
			wos << setw(12) << A.c[i] << setw(12) << A.b[i] << setw(12) << A.a[i];
			for (int j = n - i + 3; j <= n; j++)
				wos << setw(12) << 0;
			wos << "\n";
		}
		//последняя строка
		wos << setw(12) << A.b[n] << setw(12) << A.a[n];
		for (int i = 3; i <= n; i++)
			wos << setw(12) << 0;
		wos << "\n";
		/*for (int i = 1; i <= n; i++)
			wos << A.p[i]<<" ";
		wos << "\n";
		for (int i = 1; i <= n; i++)
			wos << A.q[i] << " ";*/

			/*wos << "------------------------\n";
			wos << A.a;
			wos << "\n";
			wos << A.b;
			wos << "\n";
			wos << A.c;
			wos << "\n";
			wos << A.p;
			wos << "\n";
			wos << A.q;
			wos << "\n";*/

		return wos;
	}

	//вычитание матриц
	Matrix operator - (const Matrix& A)
	{
		My_vector _a, _b, _c, _p, _q;
		_a = a - A.a;
		_b = b - A.b;
		_c = c - A.c;
		_p = p - A.p;
		_q = q - A.q;
		Matrix Res(_a, _b, _c, _p, _q, A.k);
		return Res;
	}

	//сложение матриц
	Matrix operator + (const Matrix& A)
	{
		My_vector _a, _b, _c, _p, _q;
		_a = a + A.a;
		_b = b + A.b;
		_c = c + A.c;
		_p = p + A.p;
		_q = q + A.q;
		Matrix Res(_a, _b, _c, _p, _q, A.k);
		return Res;
	}

	//оператор присвоения
	Matrix operator = (const Matrix A)
	{
		if (this != &A)
		{
			a = A.a;
			b = A.b;
			c = A.c;
			p = A.p;
			q = A.q;
			k = A.k;
		}
		return *this;
	}

	//умножение на число
	Matrix operator * (double s)
	{
		My_vector _a, _b, _c, _p, _q;
		_a = a * s;
		_b = b * s;
		_c = c * s;
		_p = p * s;
		_q = q * s;
		Matrix Res(_a, _b, _c, _p, _q, k);
		return Res;
	}

	//умножение на вектор
	My_vector operator * (My_vector& A)
	{
		int n = size();
		vector<double> resv;
		resv.push_back(c[1] * A[n - 1] + b[1] * A[n]);
		for (int i = 2; i <= n - 2; i++)
			resv.push_back(c[i] * A[n - i] + b[i] * A[n - i + 1] + a[i] * A[n - i + 2]);
		double s1 = 0, s2 = 0;
		for (int i = 1; i <= n; i++)
		{
			s1 += p[i] * A[i];
			s2 += q[i] * A[i];
		}
		resv.push_back(s1);
		resv.push_back(s2);
		My_vector Res(resv);
		return Res;
	}
};
