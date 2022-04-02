#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{

    ifstream in;
    in.open("2.1.txt");
 
    const int size = 10001;
    int garbage;
    vector<bool> array(size);

    if (in.is_open())
    {
        while (in.eof())
        {
            in >> garbage;
            if (garbage < size)
            {
                array.push_back(garbage);
            }
        }
    }

    in.close();

    for (int i = 0; i < size; i++)
    {
        if (!array.at(i))
        {
            cout << i << "\t";
            if (i % 20 == 0 && i > 0)
            {
                cout << endl;
            }  
        } 
    }

    return 0;
}