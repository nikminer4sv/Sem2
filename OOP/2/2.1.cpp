#include <iostream>
#include "Header-files/Vector.h"
#include <fstream>

using namespace std;

void FillTheFile()
{
    const unsigned long int SIZE = 100000;
    const int N = 10000;

    srand(time(NULL));
    ofstream fout("numbers.txt", ios::out);

    for (int i = 0; i < SIZE; i++)
    {
        int element = rand() % N;
        fout << element << endl;
    }
}

int main()
{
    srand(time(NULL));

    Vector<int> vector;

    FillTheFile();

    ifstream in;
    in.open("numbers.txt");
    int k = 0;
    int array[10001]{};

    if (in.is_open())
    {
        while (!in.eof())
        {
            in >> k;
            array[k]++;
        }
    }

    for (int i = 10000; i > 0; i--)
        if (array[i] != array[i + 1])
            vector.Append(i - 1);

    cout << vector << endl;
}