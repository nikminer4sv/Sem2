#include <iostream>
#include "Common/nikminer4sv.h"
#include <fstream>

using namespace std;

int main() {

    nikminer4sv::Vector<int> vector;
    /*vector.SetSize(10);
    vector.Append(1);
    vector.Append(2);
    vector.Append(3);
    vector.Append(4);
    vector[0] = 123;
    cout << vector;*/


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
            vector.Append(i - 1);

    cout << vector << endl;


}