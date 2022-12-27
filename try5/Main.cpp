#include "myVector.h"
#include "Matrix.h"
#include <math.h>
int main()
{
    std::srand(time(0));

    int i = 10;
    double a = 1, b = i;
    int k;
    k = rand() % (i - 4) + 2;
    Matrix matr(i, k);
    Matrix matr1(i, k);
    MyVector x_correct(i);
    x_correct.randomFilling(a, b);
    matr.randomFilling(a, b);
    matr1 = matr;
    MyVector f_correct(i);
    f_correct = matr1 * x_correct;
    std::cout << "matrix\n" << matr << std::endl;
    MyVector x_calculated(i);
    x_calculated = matr.result(f_correct, matr, x_correct);
    std::cout << "x_correct(" << i << ") = \n" << x_correct /*<< "f_correct(" << i << ") = \n" << f_correct*/;
    std::cout << "x_calculated(" << i << ") = \n" << x_calculated /*<< "f_calculated(" << i << ") = \n" << matr1 * x_calculated*/;
    std::cout << "norm(" << i << ") = " << (x_calculated - x_correct).norm() << "\n\n";

    for (int i = 16; i < 4000; i *= 2) 
    {
        //int i = 10;
        double a = 1, b = 100;
        int k;
        k = rand() % (i - 3) + 2;
        Matrix matr(i, k);
        Matrix matr1(i, k);
        MyVector x_correct(i);
        x_correct.randomFilling(a, b);
        matr.randomFilling(a, b);
        matr1 = matr;
        MyVector f_correct(i);
        f_correct = matr1 * x_correct;
        //std::cout << "matrix\n" << matr << std::endl;
        MyVector x_calculated(i);
        std::cout << i << ": \n";
        x_calculated = matr.result(f_correct, matr, x_correct);
        //std::cout << "x_correct(" << i << ") = \n" << x_correct << "f_correct(" << i << ") = \n" << f_correct;
        //std::cout << "x_calculated(" << i << ") = \n" << x_calculated << "f_calculated(" << i << ") = \n" << matr1 * x_calculated;
        std::cout << "norm(" << i << ") = " << (x_calculated - x_correct).norm() << "\n\n\n\n\n";
    }

}
//Вариант 4
//СЛАУ  с разреженной матрицей специального вида
//Фалалеева А. В.
//Преподаватель: Махинова О.
