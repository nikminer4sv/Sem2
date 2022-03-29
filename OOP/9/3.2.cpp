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

vector<double> ToSum(const vector<double>& matrix1, const vector<double>& matrix2) {
    if(matrix1.size() != matrix2.size())
        throw std::invalid_argument("SHLYAPA");
        
    auto size = matrix1.size();

    vector<double> result(matrix1.size()*matrix1.size());

    for (int i = 0; i < size; i++) 
        for (int j = 0; j < size; j++) 
            result[i * size + j] = matrix1[i * size + j] + matrix2[i * size + j];

    return result;    

}

vector<double> ToSquare(const vector<double>& matrix) {
     
    auto size = matrix.size();

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

void Print(const vector<double> &matrix) {

    auto size = matrix.size();

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++)
            cout << matrix[i * size + j] << " ";

        cout << endl;

    }

}

vector<double> Task(const vector<double> & matrix) {



    auto size = matrix.size();

    vector<double> result(size*size);

    auto a_2 = ToSquare(matrix);
    auto a_4 = ToSquare(a_2);
    auto a_8 = ToSquare(a_4);

    return ToSum(ToSum(ToSum(matrix, a_2),a_4), a_8);
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