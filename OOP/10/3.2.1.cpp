#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in;
    in.open("numbers2.txt");
    int k = 0;
    vector<bool> array(10001);

    if (in.is_open())
    {
        while (!in.eof())
        {
            in >> k;
            array[k] = true;
        }
    }

    int Counter = 0;
    for (int i = 0; i < 10000; i++)
    {
        if (array[i])
        {
            cout << i << "\t";
            Counter++;
            if ((Counter % 10 && Counter != 0) == 0)
            {
                cout << endl;
            }
        }
    }
}