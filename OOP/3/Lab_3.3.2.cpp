#include <iostream>
#include <list>
#include <ctime>
using namespace std;

template<typename T>
void Fill(list<T>& listok, const size_t& n)
{
    for (int i = 0; i < n; i++)
        listok.push_back((rand() % 1000 + 1) / 100.0);
}

double Task(list<int> &listok, int n)
{
    list<int>::iterator itEnd = listok.begin(), itBeginNext = listok.begin(), itBegin = listok.begin();

    for (int i = 0; i < listok.size() - 1; i++)
        ++itEnd;

    int Temp1 = *itBegin;
    int Temp2 = *++itBeginNext;
    int Temp3 = *itEnd;
    int Temp4 = n;
    cout << Temp1 << " -> " << Temp2 << " -> " << Temp3 << endl;
    double sum = 0;

    for (int i = 0; i <= n - 2; i++)
    {
        cout << '(' << Temp1 << " + " << Temp2 << " + " << Temp4 << " * " << Temp3 << ")  +  ";
        sum += Temp1 + Temp2 + Temp4 * Temp3;
        Temp1 = *++itBegin;
        Temp2 = *++itBeginNext;
        Temp3 = *--itEnd;
        Temp4--;
    }
    cout << endl;
    return sum;
}
void printList(list<int>& listok)
{
    list<int>::iterator it = listok.begin();
    for (int i = 0; i < listok.size(); i++)
        cout << *it++ << ' ';

    cout << endl;
}

int main()
{
    srand(time(NULL));
    int n;
    cout << "Enter amount of numbers: ";
    cin >> n;

    list<int> listok;

    Fill(listok, n);

    printList(listok);
    cout << "Sum: " << Task(listok, n) << endl;
    cout << "Size -> " << listok.size() << endl;

    return 0;
}
