#include <iostream>
#include <fstream>

using namespace std;

int main() {

    fstream stream;
    stream.open("database.txt", ios::in | ios::out | ios::app);

    stream << "Hello\n";
    stream.close();

}