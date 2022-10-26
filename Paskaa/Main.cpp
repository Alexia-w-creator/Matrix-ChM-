#include "Matrix.h"
#include <Windows.h>
double norma(My_vector a, My_vector b);
//float norma(My_vector a, My_vector b);
My_vector resultvec(Matrix& M, My_vector& f, My_vector& x)
{
	My_vector res;
	//float R = 0;
	double R = 0;
	int n1 = M.size();
	int n2 = f.size();
	if (n1 != n2)
	{
		cout << "\n Матрица и вектор не соглазованы по размеру. Возвращён пустой вектор";
		return res;
	}
	int n = n1;
	bool t = true;
	int i = 1;

	//шаг 1
	for (i; i < M.k; i++) ///n-3 //до К
	{
		if (M.b[i] == 0)
		{
			t = false;
			break;
		}
		R = 1 / M.b[i]; M.b[i] = 1;
		M.c[i] *= R; f[i] = f[i] * R;

		R = M.a[i + 1]; M.a[i + 1] = 0;
		M.b[i + 1] -= R * M.c[i]; f[i + 1] = f[i + 1] - f[i] * R;

		R = M.p[n - i + 1]; M.p[n - i + 1] = 0;
		M.p[n - i] = M.p[n - i] - R * M.c[i]; f[n - 1] = f[n - 1] - f[i] * R;

		R = M.q[n - i + 1]; M.q[n - i + 1] = 0;
		M.q[n - i] = M.q[n - i] - R * M.c[i]; f[n] = f[n] - f[i] * R;
		i++;
		//cout « "(((( " « f « "))))\n";
	}
	M.a[M.k] = M.p[n - M.k + 2];//согласование


	cout << M << "\n";
	My_vector NF;
	NF = M * x;
	cout << "\n-------вектор f, выч по изм А и начальному Х после первого шага-------\n";
	cout << NF;
	cout << "\n-------вектор f после первого шага-------\n";
	cout << f;
	cout << "\n-------норма " << norma(f, NF) << "\n";

	//шаг 2
	for (i = n; i > (M.k + 1); i--) {
		if (M.b[i] == 0)
		{
			t = false;
			break;
		}
		R = 1 / M.b[i]; M.b[i] = 1;
		M.a[i] *= R; f[i] = f[i] * R;

		R = M.c[i - 1]; M.c[i - 1] = 0;
		M.b[i - 1] -= R * M.a[i]; f[i - 1] = f[i - 1] - f[i] * R;

		R = M.q[n - i + 1]; M.q[n - i + 1] = 0;
		M.q[n - i + 2] = M.q[n - i + 2] - R * M.a[i]; f[M.k + 1] = f[M.k + 1] - f[i] * R;

		R = M.p[n - i + 1]; M.p[n - i + 1] = 0;
		M.p[n - i + 2] = M.p[n - i + 2] - R * M.q[n - i + 1]; f[M.k] = f[M.k] - f[i] * R;
	}

	//i == n - 2
	//if (!t || M.b[i] == 0)
	//{
	//	cout << "\n выполнение алгоритма прервано. Возвращён пустой вектор";
	//	return res;
	//}
	//R = 1 / M.b[i]; M.b[i] = 1;
	//M.c[i] *= R; f[i] = f[i] * R;

	//R = M.a[i + 1]; M.a[i + 1] = 0;
	//M.p[3] = M.a[i + 1];/*согласование*/

	//M.b[i + 1] -= R * M.c[i]; M.p[2] = M.b[i + 1];/*согласование*/
	//f[i + 1] = f[i + 1] - f[i] * R;

	//R = M.q[n - i + 1]; M.q[n - i + 1] = 0;
	//M.q[n - i] = M.q[n - i] - R * M.c[i]; f[n] = f[n] - f[i] * R;
	//M.a[n] = M.q[2];//согласование
	//i++;
	//cout « "(((( " « f « "))))\n";

	cout << M << "\n";
	NF = M * x;
	cout << "\n-------вектор f, выч по изм А и начальному Х после второго шага-------\n";
	cout << NF;
	cout << "\n-------вектор f после второго шага-------\n";
	cout << f;
	cout << "\n-------норма " << norma(f, NF) << "\n";


	//i == n - 1
	if (!t || M.b[i] == 0)
	{
		cout << "\n выполнение алгоритма прервано. Возвращён пустой вектор";
		return res;
	}
	R = 1 / M.b[i]; M.b[i] = 1;
	M.p[2] = M.b[i];/*согласование*/
	M.c[i] *= R; f[i] = f[i] * R;
	M.p[1] = M.c[i];/*согласование*/

	R = M.a[i + 1]; M.a[i + 1] = 0;
	M.q[2] = M.a[i + 1];/*согласование*/

	M.b[i + 1] -= R * M.c[i]; M.q[1] = M.b[i + 1];/*согласование*/
	f[i + 1] = f[i + 1] - f[i] * R;

	cout << M << "\n";
	NF = M * x;
	cout << "\n-------вектор f, выч по изм А и начальному Х после третьего шага-------\n";
	cout << NF;
	cout << "\n-------вектор f после третьего шага-------\n";
	cout << f;
	cout << "\n-------норма " << norma(f, NF) << "\n";


	i++;
	//i == n
	if (!t || M.b[i] == 0)
	{
		cout << "\n выполнение алгоритма прервано. Возвращён пустой вектор";
		return res;
	}
	R = 1 / M.b[i]; M.b[i] = 1;
	M.q[1] = M.b[i];/*согласование*/

	f[i] = f[i] * R;

	cout << M << "\n";
	NF = M * x;
	cout << "\n-------вектор f, выч по изм А и начальному Х после четвертого шага-------\n";
	cout << NF;
	cout << "\n-------вектор f после четвертого шага-------\n";
	cout << f;
	cout << "\n-------норма " << norma(f, NF) << "\n";

	//обратный ход
	vector<double> resv;
	//vector<float> resv;
	resv.push_back(f[n]);
	for (int i = 1; i < n; i++)
	{
		resv.push_back(f[n - i] - M.c[n - i] * resv[i - 1]);
	}
	res = resv;
	return res;
}
//bool check obus()
//{
//
//}
//float norma(My_vector a, My_vector b)
double norma(My_vector a, My_vector b)
{
	if (a.size() != b.size())
	{
		cout << "\nОшибка! Размерности сравниваемых векторов не совпадают. Возвращено -1 ";
		return -1;
	}
	My_vector d = a - b;
	double res;
	//float res;

	int s = d.size();
	res = abs(d[1]);
	for (int i = 2; i <= s; i++)
		if (abs(d[i]) > res)
			res = abs(d[i]);
	return res;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<double> a = { 0, 8, 8, 9, 4, 9 };
	vector<double> b = { 8, 1, 2, 3, 4, 7 };
	vector<double> c = { 8, 3, 2, 4, 6, 0 };
	vector<double> p = { 6, 4, 7, 1, 5, 8 };
	vector<double> q = { 7, 9, 8, 2, 4, 8 };
	My_vector aa(a);
	My_vector bb(b);
	My_vector cc(c);
	My_vector pp(p);
	My_vector qq(q);
	int k = rand() % 1 + (qq.size()-2);
	Matrix A(aa, bb, cc, pp, qq, k);
	cout << A << "\n";
	vector<double> x = { 23, 17,32, 7, 11, 7 };
	My_vector xx(x);
	My_vector f;
	f = A * xx;

	cout << f << "\n";
	cout << "----------------------\n";
	My_vector Result;
	Result = resultvec(A, f, xx);
	cout << A << "\n";
	cout << f << "\n";
	cout << Result << "\n";
	cout << "\n-------норма " << norma(Result, xx) << "\n";
 
 
	
	//Matrix A;
	//A.setmat();
	////cout << A << "\n";
	////vector<double> x = { 23, 17,32, 7, 11, 7 ,5,9};
	////My_vector xx(x);
	//My_vector xx;
	//xx.setvecrand(4048, -10, 10);
	//My_vector f;
	//f = A * xx;

	///*cout << "-------Начальный Х-------\n";
	//cout << xx << "\n";
	//cout << "----------------------\n";
	//cout << f << "\n";
	//cout << "----------------------\n";*/

	//My_vector Result;
	//Result = resultvec(A, f,xx);
	////cout << A << "\n";

	///*cout << f << "\n";
	//cout << "-------Вычесленный X-------\n";
	//cout << Result << "\n";
	//cout << "-------Начальный Х-------\n";
	//cout << xx << "\n";
	//cout << "-------Погрешность-------\n";*/
	////float erval = norma(xx, Result);
	//double erval = norma(xx, Result);
	//cout << erval << "\n";


	/*My_vector c(a);
	My_vector d(b);
	cout << c << "\n";
	cout << d << "\n";
	My_vector e;
	e = c + d;
	cout << e << "\n";
	cout << c << "\n";
	cout << d << "\n";
	e = e + e;
	cout << e << "\n";
	e = e + c;
	cout << e << "\n";
	cout << c << "\n";*/
}
