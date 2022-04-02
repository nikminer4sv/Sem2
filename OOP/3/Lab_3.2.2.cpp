#include <iostream>
#include "matrix(3.2.2).h"
#include <vector>
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

            vector<int> matrix;
            for (int i = 0; i < n * n; i++)
                matrix.push_back(rand() % 20);
            

            vector<int> quadratMatrix;
            for (int i = 0; i < n * n; i++)
                quadratMatrix.push_back(0);

            vector<int> vectorB;
            for (int i = 0; i < n; i++)
                vectorB.push_back(rand() % 20);
            
            cout << "Matrix:" << endl;
            printMatrix(matrix, n);

            quadraticMatrix(matrix, n, quadratMatrix);

            cout << "QuadratMatrix:" << endl;
            printMatrix(quadratMatrix, n);

            vector<int> newVector;

            cout << "VectorB:" << endl;
            printVector(vectorB, n);

            multiplyingVectorMatrix(quadratMatrix, vectorB, n, newVector);

            cout << "NewVector:" << endl;
            printVector(newVector, n);

            break;
        }
    case 2:
        {   
            cout << "Enter the number of matrix and vector: " << endl;
            int n;
            cin >> n;
            cout << endl;

            vector<vector<int>> matrix;
            for (int i = 0; i < n; i++)
            {
                matrix.push_back(vector<int>());
                for (int j = 0; j < n; j++)
                    matrix[i].push_back(rand() % 20);      
            }
            
            vector<vector<int>> quadratMatrix;
            for (int i = 0; i < n; i++)
            {
                quadratMatrix.push_back(vector<int>());
                for (int j = 0; j < n; j++)
                    quadratMatrix[i].push_back(0);       
            }

            vector<int> vectorB;
            for (int i = 0; i < n; i++)
                vectorB.push_back(rand() % 20);
            
            quadraticMatrix(matrix, n, quadratMatrix);

            cout << "Matrix:" << endl;
            printMatrix(matrix, n);

            cout << "QuadratMatrix:" << endl;
            printMatrix(quadratMatrix, n);

            vector<int> newVector;

            cout << "VectorB:" << endl;
            printVector(vectorB, n);

            multiplyingVectorMatrix(quadratMatrix, vectorB, n, newVector);

            cout << "NewVector:" << endl;
            printVector(newVector, n);
            
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
