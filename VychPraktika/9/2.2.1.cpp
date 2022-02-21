#include <iomanip>
#include <iostream>

using namespace std;

double **matrix_create(int n)
{
    double **result = new double *[n];
    for (int i = 0; i < n; i++)
        result[i] = new double[n]{};

    return result;
}

double **matrix_sum(const double **matrix1, const double **matrix2, int size)
{

    double **result = new double *[size];
    for (int i = 0; i < size; i++)
        result[i] = new double[size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = matrix1[i][j] + matrix2[i][j];

    return result;
}

double **matrix_pow(const double **matrix, int size, int power)
{

    double **result = new double *[size];
    for (int i = 0; i < size; i++)
    {
        result[i] = new double[size];
        memcpy(result[i], matrix[i], size);
    }

    for (int p = 0; p < power; p++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                double sum = 0;
                for (int k = 0; k < size; k++)
                {
                    sum += result[i][k] * matrix[k][j];
                }

                result[i][j] = sum;
            }
        }
    }

    return result;
}

void matrix_print(const double **matrix, int size)
{

    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size; j++)
            cout << setw(4) << matrix[i][j];

        cout << endl;
    }
}

double **Task(double **matrix, int size)
{
    auto *matrix = matrix_create(size);

    auto *result = matrix_sum(matrix, matrix_sum(matrix_pow(matrix, size, 2), matrix_sum(matrix_pow(matrix_pow(matrix, size, 2), size, 2), matrix_pow(matrix_pow(matrix_pow(matrix, size, 2), size, 2), size, 2), size, 2), size), size);
    return result;
}

int main()
{

    int size;
    cin >> size;

    double **matrix = new double *[size];
    for (int i = 0; i < size; i++)
        matrix[i] = new double[size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> matrix[i][j];

    double **result = Task(matrix, size);

    Print(result, size);
}