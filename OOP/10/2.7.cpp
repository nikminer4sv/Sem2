#include <iostream>
#include <string>
#include "Matrix.h"

using namespace std;

size_t Track(Matrix<int>& matrix)
{
    size_t i = 0, sum = 0;;
    while (i < matrix.GetCols())
    {
        sum += matrix[i][i];
        i++;
    }

    return sum;
}

void Task(Matrix<int>& matrix, const size_t& power) {

    Matrix<int> temp = matrix;
    size_t i = 1, sum = 0;
    while (i <= power)
    {
        sum += Track(temp);
        temp = matrix.Pow(++i);
    }
    cout << sum << endl;
}

int main()
{
    system("cls");
    size_t size, power;
    cout << "Enter the size of the matrix\n";
    cin >> size;
    cout << "Enter the power\n";
    cin >> power;
    system("cls");
    Matrix<int> matrix(size);
    matrix.AscendingFill();
    cout << matrix;
    Task(matrix, power);
}
