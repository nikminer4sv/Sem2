#pragma once
#include <iostream>
using namespace std;

void quadraticMatrix(int* matrix, const int n, int* quadratMatrix){
   
  
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
             int sum = 0;
            for (int j1 = 0; j1 < n; j1++)
            {
                sum += matrix[i*n+j1] * matrix[j1*n+j];
            }
            quadratMatrix[i*n+j] = sum;
        }
    }  
}

void printMatrix(int* matrix, const int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i*n+j] << '\t';
        }
        cout << endl;
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
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            newMatrix[i*n+j] = oldMatrix[i*n+j] * vectorB[j];
        }
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