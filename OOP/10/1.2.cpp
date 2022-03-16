#include <stdlib.h>
#include <ctime>  
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    double k = 0;
    ifstream infile("numbersi.txt");
    ofstream outfile("1.bin", ios::binary);

    while (!infile.eof())
    {
        infile >> k;
        if (k > 1.0)
            outfile.write(reinterpret_cast <char*>(&k), sizeof (double));
    }

    infile.close();
    infile.open("numbersi.txt");

    while (!infile.eof())
    {
        infile >> k;
        if (k <= 1.0)
            outfile.write(reinterpret_cast <char*>(&k), sizeof (double));
    }

    infile.close();
    outfile.close();

    return 0;
}
