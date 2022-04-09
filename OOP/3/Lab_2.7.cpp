#include <iostream>
#include <string>
#include "Matrix.h"
#include "VECTOR.h"

using namespace std;

template<typename T>
Vector<T> Task(Matrix<T> &matrix, const size_t &power, const Vector<T> &vector)
{
    size_t i = 1, sum = 0;
    while (i < power)
        matrix = matrix.Pow(++i);

    cout << matrix << endl;

    Vector<T> newVector(vector.getSize());

    for (int i = 0; i < matrix.GetRows(); i++)
    {
        for (int j = 0; j < matrix.GetCols(); j++)
        {
            sum += matrix[i][j] * vector[j];
        }
        newVector.push_back(sum);
        sum = 0;
    }

    return newVector;
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
    Vector<int> vector(size);

    randomFill(vector);
    cout << vector << endl;

    matrix.AscendingFill();
    
    cout << matrix << endl;

    Vector<int> newVector = Task(matrix, power, vector);
    cout << newVector << endl;
}
