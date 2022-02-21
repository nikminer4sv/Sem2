#include <iostream>
#include <fstream>
 
using namespace std;
 
int main() {

    ifstream in;
    in.open("test.txt");
    int k = 0;
    int array[10001]{};
 
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