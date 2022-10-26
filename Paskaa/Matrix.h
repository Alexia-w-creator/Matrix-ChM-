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

	//��������� �� �������
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
		else cout << "\n������! ������ ��� ������ �������. ��������� 0";
		return res;
	}

	//������ �������
	int size()
	{
		return a.size();
	}


	//������ �������
	void setmat()
	{
		int n = 0;
		cout << "\n������� ����������� ������� ";
		cin >> n;
		cout << "\n�������� ��� ����������";
		int s;
		cout << "\n1) ��������� �������";
		cout << "\n2) �������� ����������(��������) ������� �� ���������\n";
		cin >> s;
		switch (s)
		{
		case 1:
		{
			cout << "\n��������� ������ �� ������������ ��������(������������ �� �������� a,b,c)";
			cout << "\n ������ �";
			a.setvec(n);
			cout << "\n ������ b";
			b.setvec(n);
			cout << "\n ������ c";
			c.setvec(n);
			cout << "\n ������ p";
			p.setvec(n);
			cout << "\n ������ q";
			q.setvec(n);
			break;
		}
		case 2:
		{
			double min, max;
			cout << "\n������� ������ � ������� ������� ��������� ��� a, c -> ";
			cin >> min >> max;
			a.setvecrand(n, min, max);
			c.setvecrand(n, min, max);
			//cout << "\n������� ������� ������� ��������� -> ";

			cout << "\n������� ������ � ������� ������� ��������� ��� p, q -> ";
			cin >> min >> max;
			p.setvecrand(n, min, max);
			q.setvecrand(n, min, max);

			cout << "\n������� ������ � ������� ������� ��������� ��� b -> ";
			cin >> min >> max;
			b.setvecrand(n, min, max);


			//agreement();
			break;
		}
		default:
			break;
		}
		agreement();

		/*cout << "\n��������� ������ �� ������������ �������� ";
		cout << "\n ������ �";
		a.setvec(n);
		cout << "\n ������ b";
		b.setvec(n);
		cout << "\n ������ c";
		c.setvec(n);
		cout << "\n ������ p";
		p.setvec(n);
		cout << "\n ������ q";
		q.setvec(n);*/
		//�������� ���������������

	}

	//����� ������� �� �������
	friend ostream& operator << (ostream& wos, Matrix& A)
	{
		int n = A.size();
		//������ ������
		for (int i = 1; i < n - 1; i++)
			wos << setw(12) << 0;
		wos << setw(12) << A.c[1] << setw(12) << A.b[1] << "\n";
		//������ �� 2-� �� k
   		for (int i = 2; i < A.k; i++)
		{
			for (int j = 1; j < n - i; j++)
				wos << setw(12) << 0;
			wos << setw(12) << A.c[i] << setw(12) << A.b[i] << setw(12) << A.a[i];
			for (int j = n - i + 3; j <= n; j++)
				wos << setw(12) << 0;
			wos << "\n";
		}
		//������ p, q
		wos << A.p;
		wos << "\n";
		wos << A.q;
		wos << "\n";
		//�� (k + 2) �� (n - 1)(������������)
		for (int i = A.k + 2; i < n; i++)
		{
			for (int j = 1; j < n - i; j++)
				wos << setw(12) << 0;
			wos << setw(12) << A.c[i] << setw(12) << A.b[i] << setw(12) << A.a[i];
			for (int j = n - i + 3; j <= n; j++)
				wos << setw(12) << 0;
			wos << "\n";
		}
		//��������� ������
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

	//��������� ������
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

	//�������� ������
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

	//�������� ����������
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

	//��������� �� �����
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

	//��������� �� ������
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
