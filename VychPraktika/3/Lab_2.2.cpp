#include <iostream>
#include "matrix(2.2).h"
using namespace std;

int main(){

    int choose;

    cout << "Enter the choose: " << endl;
    cout << "1. 1D " << endl << "2. 2D " << endl;
    cin >> choose;

    switch (choose)
    {
    case 1:
        {
            cout << "Enter the number of matrix and vector: " << endl;
            int n;
            cin >> n;

            cout << endl;

            int* matrix = new int [n * n];
            for (int i = 0; i < n * n; i++)
            {
                matrix[i] = rand() % 20;
            }

            int* quadratMatrix = new int [n * n];
            for (int i = 0; i < n * n; i++)
            {
                quadratMatrix[i] = 0;
            }

            int* vectorB = new int [n];
            for (int i = 0; i < n; i++)
            {
                vectorB[i] = rand() % 20;
            }
            
            quadraticMatrix(matrix, n, quadratMatrix);

            cout << "Matrix:" << endl;
            printMatrix(matrix, n);

            cout << "QuadratMatrix:" << endl;
            printMatrix(quadratMatrix, n);

            int* newMatrix = new int [n * n];

            cout << "VectorB:" << endl;
            printVector(vectorB, n);

            multiplyingVectorMatrix(quadratMatrix, vectorB, n, newMatrix);

            cout << "NewMatrix:" << endl;
            printMatrix(newMatrix, n);

            delete[] matrix;
            delete[] quadratMatrix;
            delete[] vectorB;
            delete[] newMatrix;

            break;
        }
    case 2:
        {   
            cout << "Enter the number of matrix and vector: " << endl;
            int n;
            cin >> n;

            cout << endl;

            int** matrix = new int* [n];
            for (int i = 0; i < n; i++)
            {
                matrix[i] = new int [n];
                for (int j = 0; j < n; j++)
                    matrix[i][j] = rand() % 20;      
            }
            
            int** quadratMatrix = new int* [n];
            for (int i = 0; i < n; i++)
            {
                quadratMatrix[i] = new int [n];
                for (int j = 0; j < n; j++)
                    quadratMatrix[i][j] = 0;      
            }

            int* vectorB = new int [n];
            for (int i = 0; i < n; i++)
            {
                vectorB[i] = rand() % 20;
            }
            
            quadraticMatrix(matrix, n, quadratMatrix);

            cout << "Matrix:" << endl;
            printMatrix(matrix, n);

            cout << "QuadratMatrix:" << endl;
            printMatrix(quadratMatrix, n);

            int** newMatrix = new int* [n];
            for (int i = 0; i < n; i++)
            {
                newMatrix[i] = new int [n];
                for (int j = 0; j < n; j++)
                    newMatrix[i][j] = 0;      
            }

            cout << "VectorB:" << endl;
            printVector(vectorB, n);

            multiplyingVectorMatrix(quadratMatrix, vectorB, n, newMatrix);

            cout << "NewMatrix:" << endl;
            printMatrix(newMatrix, n);


            for (int i = 0; i < n; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;

            delete[] quadratMatrix;
            for (int i = 0; i < n; i++)
            {
                delete[] quadratMatrix[i];
            }
            
            delete[] vectorB;
            delete[] newMatrix;
            for (int i = 0; i < n; i++)
            {
                delete[] newMatrix[i];
            }
            
            break;
        }
    
    default:
        {
            cout << "Error! Try again!" << endl;
            break;
        } 
    }

    return 0;
}
