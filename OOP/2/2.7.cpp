#include <iostream>
#include <vector>
#include <string>
#include "Header-files/Vector.h"
#include "Header-files/Matrix.h"

using namespace std;

Matrix<double> Task(Matrix<double> A, Matrix<double> B, Matrix<double> C)
{
    return A * (B + C);
}

int main()
{
    srand(time(NULL));

    Matrix<double> A(3, 3);
    A.RandomFill();
    cout << "A matrix: " << endl
         << A << endl;

    Matrix<double> B(3, 3);
    B.RandomFill();
    cout << "B matrix: " << endl
         << B << endl;

    Matrix<double> C(3, 3);
    C.RandomFill();
    cout << "C matrix: " << endl
         << C << endl
         << endl;

    cout << "A * ( B + C )" << endl
         << Task(A, B, C);

    return 0;
}