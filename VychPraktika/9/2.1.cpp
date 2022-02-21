#include <iostream>
#include <fstream>
#include <tuple>

using namespace std;

tuple<int*, int> ReadFile(char* fileName) {

    ifstream in;
    in.open(fileName);

    int* numbers = new int[256];
    int size = 0;

    if (in.is_open()) {

        int index = 0;

        while (!in.eof()) {
            in >> numbers[index++];
            size += 1;
        }

        in.close();

    } else {

        cout << "Invalid file name!" << endl;

    }

    return make_tuple(numbers, size);

}

bool IsNumberInArrayTwice(int* numbers, int size, int number) {

    int counter = 0;

    for (int i = 0; i < size; i++)
        if (numbers[i] == number)
            counter += 1;

    if (counter > 1)
        return true;
    else 
        return false;


}

void ShiftArray(int* numbers, int& size, int startIndex, int shiftSize) {

    for (int i = size + shiftSize; i > startIndex; i--) {
        numbers[i] = numbers[i - shiftSize]; 

    }

    for (int i = startIndex; i < startIndex + shiftSize; i++) {

        numbers[i] = 0;

    }

    size += shiftSize;

}

void AppendNumber(int* numbers, int& size, int number) {

    if (number > numbers[0]) {
        ShiftArray(numbers, size, 0, 1);
        numbers[0] = number;
        return;
    }

    for (int i = 0; i < size - 1; i++) {

        if (number <= numbers[i] && number >= numbers[i + 1]) {

            ShiftArray(numbers, size, i + 1, 1);
            numbers[i + 1] = number;
            break;

        }

    }
    
}

tuple<int*, int> ResultingArray() {

    int* result = new int[1];
    int resultSize = 1;

    ifstream in;
    in.open("test.txt");

    if (in.is_open()) {

        while (!in.eof()) {
            int number;
            in >> number;
            AppendNumber(result, resultSize, number);
        }
        
    } else {
        cout << "ERROR! File not found.";
        exit(999);
    }

    resultSize -= 1;

    int* finalResult = new int[resultSize];
    int finalResultSize = 0;

    for (int i = 0; i < resultSize - 1; i++) {

        if (result[i] == result[i + 1]) {

            if (result[i + 2] != result[i]) {
                finalResult[finalResultSize++] = result[i];
            } else {
                int temp = result[i];
                while (result[i + 1] == temp)
                    i += 1;
            }

        }

    }

    return make_tuple(finalResult, finalResultSize);

}


int main() {

    /*int* numbers;
    int size;*/

    //tie(numbers, size) = ReadFile("test.txt");

    //for (int i = 0; i < size; i++) 
    //    cout << numbers[i] << " ";

    cout << endl;

    int* result;
    int resultSize;

    tie(result, resultSize) = ResultingArray();

    for (int i = 0; i < resultSize; i++) 
        cout << result[i] << " ";


}