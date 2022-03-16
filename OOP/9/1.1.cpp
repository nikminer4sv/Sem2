#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

bool EvenComporator(const int& number) {
    return number % 2 == 0;
}

bool OddComporator(const int& number) {
    return !EvenComporator(number);
}

void CheckAndWrite(ifstream& inputFileStream, ofstream& outputFileStream, function<bool(const int&)> chechFunction) {

    if (inputFileStream.is_open() && outputFileStream.is_open()) {
        int value;
        while (!inputFileStream.eof()) {
            inputFileStream >> value;
            if (chechFunction(value))
                outputFileStream << value << " ";
        }

        outputFileStream << "\n";
    } else {
        throw runtime_error("Could not open file");
    }

}

int main() {

    ifstream inputFileStream;
    inputFileStream.open("data.txt");

    ofstream outputFileStream;
    outputFileStream.open("output.txt");

    CheckAndWrite(inputFileStream, outputFileStream, EvenComporator);
    inputFileStream.seekg(0, ios::beg);
    CheckAndWrite(inputFileStream, outputFileStream, OddComporator);

    inputFileStream.close();
    outputFileStream.close();
}