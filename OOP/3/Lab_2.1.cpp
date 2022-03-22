#include <iostream>
#include <fstream>
#include "VECTOR.h"

using namespace std;

int main()
{
    ofstream out("2.1.txt");
    for (int i = 0; i < 10000; i++)
    {
        out << i << endl;
    }
    out.close();

    ifstream in;
    in.open("2.1.txt");
 
    const int size = 10001;
    int garbage;
    Vector<bool> array(size);
    cout << array.getSize() << endl;

    if (in.is_open())
    {
        while (in.eof())
        {
            in >> garbage;
            if (garbage < size)
            {
                array[garbage] = true;
            }
        }
    }

    in.close();

    for (int i = 0; i < size; i++)
    {
        if (!array[i])
        {
            cout << i << "\t";
            if (i % 10 == 0 && i > 0)
            {
                cout << endl;
            }  
        } 
    }
    return 0;
}