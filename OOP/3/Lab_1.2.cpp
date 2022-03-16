#include <iostream>
#include <fstream>

using namespace std;

void writeNewFile(ifstream& in, ofstream& out)
{
    int k = 0;
    if (in.is_open())
    {
        while (!in.eof())
        {
            in >> k;
            cout << k <<endl;
            out.write(reinterpret_cast <char*>(&k), sizeof (k));
        } 
    }
}

int main() 
{
    
    ifstream in;
    in.open("lab_1.1_numbers2.txt");
    ofstream out;
    out.open("lab_1.2.bin", ios::binary);
    writeNewFile(in, out);

    out.close();
    in.close();
}


