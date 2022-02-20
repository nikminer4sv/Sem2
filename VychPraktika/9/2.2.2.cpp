#include <iostream>

using namespace std;

double* ToSum(double* matrix1, double* matrix2, int size) {

    double* result = new double[size * size];

    for (int i = 0; i < size; i++) 
        for (int j = 0; j < size; j++) 
            result[i * size + j] = matrix1[i * size + j] + matrix2[i * size + j];

    return result;    

}

double* ToSquare(double* matrix, int size) {

    double* result = new double[size * size];

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {
        
            double sum = 0;

            for (int k = 0; k < size; k++) {

                double firstElement = matrix[i * size + k];
                double secondElement = matrix[k * size + j];

                sum += firstElement * secondElement;

            }

            result[i * size + j] = sum;

        }   
        
    }

    return result;

}

void Print(double* matrix, int size) {

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++)
            cout << matrix[i * size + j] << " ";

        cout << endl;

    }

}

double* Task(double* matrix, int size) {

    double* result = new double[size * size];

    result = ToSum(matrix, ToSum(ToSquare(matrix, size), ToSum(ToSquare(ToSquare(matrix, size), size), ToSquare(ToSquare(ToSquare(matrix, size), size), size), size), size), size);
    return result;

}

int main() {

    int size;
    cin >> size;

    double* matrix = new double[size * size];

    for (int i = 0; i < size * size; i++)
            cin >> matrix[i];

    //double* result = ToSquare(matrix, size); 
    double* result = Task(matrix, size);

    Print(result, size);

}