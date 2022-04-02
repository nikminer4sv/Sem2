#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(const vector<T> vectorB, const int n)
{
    for (int i = 0; i < n; i++)
        cout << vectorB[i] << '\t';

    cout << endl << endl;
}

template <typename T>
void multiplyingVectorMatrix(const vector<T> &oldMatrix, const vector<T> vectorB, const int n, vector<T> &newVector)
{
    int sum = 0;
    for (int i = 0, m = 0; i < n * n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++, m++)
            sum += oldMatrix[m] * vectorB[j];

        newVector.push_back(sum);
    }
        
        
}

template <typename T>
void multiplyingVectorMatrix(const vector<vector<T>> &oldMatrix, const vector<T> vectorB, const int n, vector<T> &newVector)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += oldMatrix[i][j] * vectorB[j];

        newVector.push_back(sum);
    }
        
}

template <typename T>
void quadraticMatrix(const vector<vector<T>> &matrix, const int n, vector<vector<T>> &quadratMatrix)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int j1 = 0; j1 < n; j1++)
                sum += matrix[i][j1] * matrix[j1][j];

            quadratMatrix[i][j] = sum;
            sum = 0;
        }
    }
}

template <typename T>
void quadraticMatrix(const vector<T> &matrix, const int n, vector<T> &quadratMatrix)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int j1 = 0; j1 < n; j1++)
                sum += matrix[i * n + j1] * matrix[j1 * n + j];

            quadratMatrix[i * n + j] = sum;
        }
    }
}

template <typename T>
void printMatrix(const vector<vector<T>> &matrix, const int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << '\t';

        cout << endl;
    }
    cout << endl;
}

template <typename T>
void printMatrix(const vector<T> &matrix, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i * n + j] << '\t';

        cout << endl;
    }
    cout << endl;
}