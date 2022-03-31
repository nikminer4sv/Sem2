#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    ifstream stream;
    stream.open("test.cpp");

    if (stream.is_open()) {

        while (stream) {

            string line;
            getline(stream, line);
            cout << line << endl;

        }

    }

}