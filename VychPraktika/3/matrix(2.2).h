#pragma once
#include <iostream>
using namespace std;

void quadraticMatrix(int* matrix, const int n, int* quadratMatrix){

    int idColumnMatrix = 0;
    int idRowMatrix = 0;

    int startPositionColumn = 0;
    int startPositionRow = 0;

    int indexN = n - 1;
    
    for (int iterQuadraticMatrix = 0, i = 0; iterQuadraticMatrix < n * n; i++)
    {

        if (iterQuadraticMatrix == indexN && i == n)
        {
            indexN += n;
            idColumnMatrix = startPositionColumn = -1;
            startPositionRow += n;
            idRowMatrix = startPositionRow; 
        }

        if (i == n)
        {
            iterQuadraticMatrix++;
            idColumnMatrix = ++startPositionColumn;
            idRowMatrix = startPositionRow;
            i = 0;
        }
        
        quadratMatrix[iterQuadraticMatrix] += matrix[idRowMatrix++] * matrix[idColumnMatrix];

        idColumnMatrix += n;   
    }
}

void printMatrix(int* matrix, const int n){
    int indexN = n - 1;
    for (int i = 0; i < n * n; i++)
    {
        cout << matrix[i] << "\t";
        if (i == indexN)
        {
            indexN += n;
            cout << endl;
        }
    }
    cout << endl;
}

void printVector(int* vectorB, const int n){
    for (int i = 0; i < n; i++)
    {
        cout << vectorB[i] << '\t';
    }
    cout << endl << endl;
}

void multiplyingVectorMatrix(int* oldMatrix, int* vectorB, const int n, int* newMatrix){
    for (int i = 0, j = 0; i < n * n; i++)
    {
        if (j == n)
            j = 0;
        
        newMatrix[i] = oldMatrix[i] * vectorB[j++];
    }  
}


void quadraticMatrix(int** matrix, const int n, int** quadratMatrix){
    int sum = 0;
  
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int j1 = 0; j1 < n; j1++)
            {
                sum += matrix[i][j1] * matrix[j1][j];
            }
            quadratMatrix[i][j] = sum;
            sum = 0;
        }
    }  
}

void printMatrix(int** matrix, const int n){
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

void multiplyingVectorMatrix(int** oldMatrix, int* vectorB, const int n, int** newMatrix){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            newMatrix[i][j] = oldMatrix[i][j] * vectorB[j];
        }
    }
}