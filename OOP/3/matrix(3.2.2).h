#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(const vector<T>& vectorB)
{
    for (int i = 0; i < vectorB.size(); i++)
        std::cout << vectorB[i] << '\t';

    std::cout << std::endl << std::endl;
}

template <typename T>
void multiplyingVectorMatrix(const vector<T> &oldMatrix, const vector<T>& vectorB, vector<T> &newVector, const int n)
{
    //newVector.clear();

    int sum = 0;
    for (int i = 0, m = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++, m++)
            sum += oldMatrix[m] * vectorB[j];

        newVector.push_back(sum);
    }        
}

template <typename T>
void multiplyingVectorMatrix(const vector<vector<T>> &oldMatrix, const vector<T>& vectorB, vector<T> &newVector)
{
    newVector.clear();
    int n =  oldMatrix.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += oldMatrix[i][j] * vectorB[j];

        newVector.push_back(sum);
    }
        
}

template <typename T>
vector<vector<T>> quadraticMatrix(const vector<vector<T>> &matrix)
{
    int n =  matrix.size();

    int i = 0;
    vector<vector<T>> quadratMatrix(n);
    for (const auto& el : quadratMatrix)
        quadratMatrix[i++].resize(n);
    
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
    return quadratMatrix;

}

template <typename T>
vector<T> quadraticMatrix(const vector<T> &matrix, const int& n)
{
    vector<T> quadratMatrix(n);
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
    return quadratMatrix;
}

template <typename T>
void printMatrix(const vector<vector<T>> &matrix)
{
    int n = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << matrix[i][j] << '\t';

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template <typename T>
void printMatrix(const vector<T> &matrix, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << matrix[i * n + j] << '\t';

        std::cout << std::endl;
    }
    std::cout << std::endl;
}