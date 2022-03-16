#include <iostream>
#include <fstream>

using namespace std;

void writeFile(ofstream& out, const int size)
{   
    int kolvo = 0;
    for (int i = 0; i < size;)
    {
        int value = rand() % 10000;

        if (value % 2 == 0 && kolvo % 2 == 0)
        {
            out << value << endl; 
            i++;
        }  
        else if(value % 2 != 0 && kolvo % 2 != 0 )  
        {
            out << value << endl; 
            i++;
        }
        else
            continue;
        if (i % 2 == 0)
            kolvo++;
    }
}

void writeNewFile(ifstream& in1, ifstream& in2, ofstream& out)
{
    int k = 0;
    int k2 = 0;

    if (in1.is_open() && in2.is_open())
    {
        in1 >> k;
        in2 >> k2;
    
        while (!in2.eof())
        {
            if (k % 2 == 0 && k2 % 2 == 0)
            {
                in2 >> k2;
            }
            else if (k % 2 == 0 && k2 % 2 != 0)
            {
                out << k << endl;
                out << k2 << endl;

                in1 >> k;
                in2 >> k2;

                out << k << endl;
                out << k2 << endl;

                in2 >> k2;
                while (k != k2)
                    in1 >> k; 
            }     
        }  
    }
}

int main() 
{
    const int size = 100;

    ofstream out;
    //out.open("lab_1.1_numbers.txt");
    out.open("fgfgf.txt");
    writeFile(out, size);

    out.close();

    ifstream in1;
    ifstream in2;
    in1.open("lab_1.1_numbers.txt");
    in2.open("lab_1.1_numbers.txt");
    out.open("lab_1.1_numbers2.txt");
    writeNewFile(in1, in2, out);

    out.close();
    in1.close();
    in2.close();
}