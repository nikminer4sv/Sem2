#include <iostream>
#include <list>

using namespace std;

void TaskResult(double max, int Index1, int Index2)
{
    cout << "Max sum: " << max << endl 
        <<"Indexes: " << Index1 << " and " 
        << Index2 << " (Begins from 0)" << endl;
}

void PrintList(list<double>& listmain)
{
    list<double>::iterator it = listmain.begin();
    for (int i = 0; i < listmain.size(); i++)
    {
        if (i % 10 == 0 && i != 0)
            cout << endl;
        cout << *it++ << " ";
    }
    cout << endl;
}

void Fill(list<double>& listmain, int n)
{
    for (int i = 0; i < 2 * n; i++)
    {
        listmain.push_back((rand() % 1000 + 1) / 100.0);
    }
}

void Task(list<double>& listmain)
{
    if (listmain.size() < 2 || listmain.size() % 2)
        throw invalid_argument("Invalid listmain size");

    list<double>::iterator first = listmain.begin();
    list<double>::iterator second = listmain.end();

    double max = *first + *--second;
    int Index1 = 0, Index2 = listmain.size() - 1;

    for (int i = 1; i < listmain.size() / 2; i++)
    {
        first++;
        second--;
        double temp = *first + *second;

        if (temp > max)
        {
            max = temp;
            Index1 = i;
            Index2 = listmain.size() - i - 1;
        }
    }

    TaskResult(max, Index1, Index2);
}

int main()
{
    int n;
    cout << "Enter amount of numbers: ";
    cin >> n;

    list<double> listmain;

    Fill(listmain, n);
    PrintList(listmain);
    Task(listmain);
}