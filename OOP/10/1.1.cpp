#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    double k = 0;
    ifstream in;
    in.open("numbersi.txt");
    ofstream out;
    out.open("numbersi1.txt");

    if (in.is_open())
    {
        while (!in.eof())
        {
            in >> k;
            if (k > 1.0)
            out << k << endl;
        }
    }

    in.close();
    in.open("numbersi.txt");

    if (in.is_open())
    {
        while (!in.eof())
        {
            in >> k;
            if (k <= 1.0)
            out << k << endl;
        }
    }

    in.close();
}