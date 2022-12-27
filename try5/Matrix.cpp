#include "Matrix.h"


void Matrix::ABCtoPQ()
{
	p[size - k] = a[k];
	p[size - (k - 1)] = b[k];
	p[size - (k - 2)] = c[k];
	q[size - (k + 1)] = a[k + 1];
	q[size - (k)] = b[k + 1];
	q[size - (k - 1)] = c[k + 1];
	c[1] = 0;
	a[size] = 0;
}

void Matrix::PQtoABC()
{
	a[k] = p[size - k];
	b[k] = p[size - (k - 1)];
	c[k] = p[size - (k - 2)];
	a[k + 1] = q[size - (k + 1)];
	b[k + 1] = q[size - (k)];
	c[k + 1] = q[size - (k - 1)];
	c[1] = 0;
	a[size] = 0;
}

Matrix::Matrix()
{
	size = 5;
	a = MyVector(size);
	b = MyVector(size);
	c = MyVector(size);
	p = MyVector(size);
	q = MyVector(size);
	k = 1;
}

Matrix::Matrix(int size_, int k_) {
	size = size_;
	a = MyVector(size);
	b = MyVector(size);
	c = MyVector(size);
	p = MyVector(size);
	q = MyVector(size);
	k = k_;
}

void Matrix::randomFilling(double x, double y)
{
	double xx = x + 5;
	double yy = y + 10;

	a.randomFilling(xx, yy);
	xx = xx + 50;
	yy = yy + 100;
	b.randomFilling(xx, yy);
	xx = xx - 40;
	yy = yy - 90;
	c.randomFilling(xx, yy);
	p.randomFilling(x, y);
	q.randomFilling(x, y);

	ABCtoPQ();
}

Matrix Matrix::operator+(Matrix matr)
{
	Matrix temp(size, k);
	temp.a = a + matr.a;
	temp.b = b + matr.b;
	temp.c = c + matr.c;
	temp.p = p + matr.p;
	temp.q = q + matr.q;
	temp.size = size;
	temp.k = k;
	return temp;
}

Matrix Matrix::operator-(Matrix matr)
{
	Matrix temp(size, k);
	temp.a = a - matr.a;
	temp.b = b - matr.b;
	temp.c = c - matr.c;
	temp.p = p - matr.p;
	temp.q = q - matr.q;
	temp.size = size;
	temp.k = k;
	return temp;
}

MyVector Matrix::operator*(MyVector vec)
{
	MyVector temp(size);
	if (k != 1) {
		temp[1] = a[1] * vec[size - 1] + b[1] * vec[size];

		for (int i = 2; i < k; i++)
			temp[i] = a[i] * vec[size - i] + b[i] * vec[size - i + 1] + c[i] * vec[size - i + 2];
	}
	for (int i = 1; i <= size; i++)
		temp[k] += p[i] * vec[i];

	//temp[k + 1] = a[k + 1] * vec[size-(k + 1)] + b[k + 1] * vec[size - (k + 1)+1] + c[k + 1] * vec[size - (k + 1)+2];

	for (int i = 1; i <= size; i++)
		temp[k + 1] += q[i] * vec[i];

	for (int i = k + 2; i <= size; i++)
		temp[i] = a[i] * vec[size - i] + b[i] * vec[size - i + 1] + c[i] * vec[size - i + 2];

	return temp;
}

MyVector Matrix::result(MyVector f, Matrix M, MyVector xx)
{
	//std::cout << M << std::endl;
	for (int i = 1; i < k; i++) {
		double R = 1 / b[i];
		a[i] *= R;
		f[i] *= R;
		b[i] = 1;
		b[i + 1] -= a[i] * c[i + 1];
		f[i + 1] -= f[i] * c[i + 1];
		c[i + 1] = 0;
		ABCtoPQ();
		p[size - i] -= a[i] * p[size - (i - 1)];
		f[k] -= f[i] * p[size - (i - 1)];
		p[size - (i - 1)] = 0;
		q[size - i] -= a[i] * q[size - (i - 1)];
		f[k + 1] -= f[i] * q[size - (i - 1)];
		q[size - (i - 1)] = 0;
		PQtoABC();
	}
	std::cout << "After first step:" << std::endl;
	//std::cout << M << std::endl;
	MyVector ff = M * xx;
	//std::cout << "f_correct: " << ff;
	//std::cout << "f_culculated: " << f << std::endl;
	std::cout << "norm(f1) = " << (f-ff).norm() << "\n\n";

	for (int i = size; i > k + 1; i--) {
		double R = 1 / b[i];
		c[i] *= R;
		f[i] *= R;
		b[i] = 1;
		b[i - 1] -= c[i] * a[i - 1];
		f[i - 1] -= f[i] * a[i - 1];
		a[i - 1] = 0;
		ABCtoPQ();
		p[size - (i - 2)] -= c[i] * p[size - (i - 1)];
		f[k] -= f[i] * p[size - (i - 1)];
		p[size - (i - 1)] = 0;
		q[size - (i - 2)] -= c[i] * q[size - (i - 1)];
		f[k + 1] -= f[i] * q[size - (i - 1)];
		q[size - (i - 1)] = 0;
		PQtoABC();
	}
	std::cout << "After second step:" << std::endl;
	//std::cout << M << std::endl;
	ff = M * xx;
	//std::cout << "f_correct: " << ff;
	//std::cout << "f_culculated: " << f << std::endl;
	std::cout << "norm(f2) = " << (f - ff).norm() << "\n\n";


	/*double temp = 1 / b[k + 1];
	a[k + 1] *= temp;
	b[k + 1] = 1;
	c[k + 1] *= temp;
	f[k + 1] *= temp;

	b[k] -= a[k] * c[k + 1];
	b[k + 2] -= a[k + 1] * c[k + 2];
	f[k] -= f[k + 1] * a[k];
	f[k + 2] -= f[k + 1] * c[k + 2];
	normalizeABCtoPQ();
	p[size - k - 1] -= a[k] * a[k + 1];
	q[size - k + 1] -= c[k + 1] * c[k + 2];
	p[size - k] = 0;
	q[size - k] = 0;
	normalizePQtoABC();

	temp = 1 / q[size - k - 1];
	q[size - k - 1] = 1;
	q[size - k + 1] *= temp;
	f[k + 2] *= temp;
	normalizePQtoABC();
	c[k + 1] -= a[k + 1] * q[size - k + 1];
	f[k + 1] -= a[k + 1] * f[k + 2];
	a[k + 1] = 0;
	p[size - k + 1] -= p[size - k - 1] * q[size - k + 1];
	f[k] -= p[size - k - 1] * f[k + 2];
	p[size - k - 1] = 0;
	normalizePQtoABC();


	temp = 1 / b[k];
	f[k] *= temp;
	b[k] = 1;
	f[k + 1] -= f[k] * c[k + 1];
	c[k + 1] = 0;
	normalizeABCtoPQ();
	f[k + 2] -= f[k] * q[size - k + 1];
	q[size - k + 1] = 0;
*/
	double R = 1.0 / p[size - (k - 1)];
	p[size - (k - 1)] = 1;//6
	p[size - (k)] *= R;//5
	f[k] *= R;
	q[size - (k)] -= p[size - (k)] * q[size - (k - 1)];//5
	f[k + 1] -= f[k] * q[size - (k - 1)];
	q[size - (k - 1)] = 0;//6
	PQtoABC();

	R = 1.0 / q[size - (k)];
	q[size - (k)] = 1;
	f[k + 1] *= R;
	f[k] -= f[k + 1] * p[size - (k)];
	p[size - (k)] = 0;
	PQtoABC();

	std::cout << "After third step:" << std::endl;
	//std::cout << M << std::endl;
	ff = M * xx;
	//std::cout << "f_correct: " << ff;
	//std::cout << "f_culculated: " << f << std::endl;
	std::cout << "norm(f3) = " << (f - ff).norm() << "\n";

	std::cout << std::endl;

	MyVector x(size);
	x[size - k + 1] = f[k];
	x[size - k] = f[k + 1];
	int i, j;
	for (i = size - k + 2, j = k - 1; i <= size; i++, j--)
		x[i] = f[j] - x[i - 1] * a[j];
	for (i = size - k - 1, j = k + 2; i >= 1; i--, j++)
		x[i] = f[j] - x[i + 1] * c[j];
	
	return x;
}

void Matrix::operator=(Matrix matr)
{
	a = matr.a;
	b = matr.b;
	c = matr.c;
	p = matr.p;
	q = matr.q;
	k = matr.k;
	size = matr.size;
}

std::ostream& operator<<(std::ostream& output, Matrix matr)
{
	if (matr.k != 1) {
		for (int i = 1; i <= matr.size - 2; i++)
			output << "0 ";
		output << matr.a[1] << ' ' << matr.b[1] << '\n';
		for (int i = 2; i < matr.k; i++) {
			for (int j = 1; j <= matr.size - (i + 1); j++)
				output << "0 ";
			output << matr.a[i] << ' ' << matr.b[i] << ' ' << matr.c[i];
			for (int j = 1; j <= i - 2; j++)
				output << " 0";
			output << '\n';
		}
	}

	for (int i = 1; i <= matr.size; i++)
		output << matr.p[i] << ' ';
	output << '\n';

	/*for (int i = 1; i <= matr.size - (matr.k + 2); i++)
		output << "0 ";
	output << matr.a[matr.k + 1] << ' ' << matr.b[matr.k + 1] << ' ' << matr.c[matr.k + 1];
	for (int i = 1; i <= (matr.k + 1) - 2; i++)
		output << " 0";
	output << '\n';*/

	for (int i = 1; i <= matr.size; i++)
		output << matr.q[i] << ' ';
	output << '\n';

	if (matr.k != matr.size - 1) {
		for (int i = matr.k + 2; i < matr.size; i++) {
			for (int j = 1; j <= matr.size - (i + 1); j++)
				output << "0 ";
			output << matr.a[i] << ' ' << matr.b[i] << ' ' << matr.c[i];
			for (int j = 1; j <= i - 2; j++)
				output << " 0";
			output << '\n';
		}
		output << matr.b[matr.size] << ' ' << matr.c[matr.size];
		for (int i = 1; i <= matr.size - 2; i++)
			output << " 0";
		output << '\n';
	}
	return output;
}

std::istream& operator>>(std::istream& input, Matrix& matr)
{
	input >> matr.a >> matr.b >> matr.c >> matr.p >> matr.q;
	matr.ABCtoPQ();
	return input;
}
