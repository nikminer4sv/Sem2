#include <iostream>
#include <string>
#include <cstring>
#include "Lab_2.6.h"

using namespace std;

int main()
{
    string binaryNumber;
    getline(cin, binaryNumber);

    bit256BinaryNumber task(binaryNumber);

    getline(cin, binaryNumber);
    bit256BinaryNumber task2(binaryNumber);

    task.convertToDecimalNumber();

    task2.convertToDecimalNumber();

    cout << task << endl << endl;
    cout << task2 << endl << endl;

    bit256BinaryNumber testMinus = task - task2;
    cout << testMinus << endl;

    task2.task();
    cout << task2 << endl << endl;


    return 0;
}