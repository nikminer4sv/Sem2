#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void t2_1() {
    ifstream in;
    in.open("test.txt");
    int k = 0;
    vector<int> array(10000);
 
    if (in.is_open()) {

        while (!in.eof()) {
            in >> k;
            array[k]++;
        }

    }

    for (int i = 10000; i > 0; i--) 
        if (array[i - 1] == 2) 
            cout << i - 1 << ' ';    
}

vector<double> ToSum(vector<double> matrix1, vector<double> matrix2, int size) {

    vector<double> result(size*size);

    for (int i = 0; i < size; i++) 
        for (int j = 0; j < size; j++) 
            result[i * size + j] = matrix1[i * size + j] + matrix2[i * size + j];

    return result;    

}

vector<double> ToSquare(vector<double> matrix, int size) {

    vector<double> result(size*size);

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

void Print(vector<double> matrix, int size) {

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++)
            cout << matrix[i * size + j] << " ";

        cout << endl;

    }

}

vector<double> Task(vector<double> matrix, int size) {

    vector<double> result(size*size);

    result = ToSum(matrix, ToSum(ToSquare(matrix, size), ToSum(ToSquare(ToSquare(matrix, size), size), ToSquare(ToSquare(ToSquare(matrix, size), size), size), size), size), size);
    return result;

}

int main() {

    /*

    int size;
    cin >> size;

    vector<double> matrix(size*size);

    for (int i = 0; i < size * size; i++)
            cin >> matrix[i];

    //vector<double> result = ToSquare(matrix, size); 
    vector<double> result = Task(matrix, size);

    Print(result, size);

    */

   t2_1();

}