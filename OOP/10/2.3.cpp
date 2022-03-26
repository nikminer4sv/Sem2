#include <iostream>
#include "DList.h"

using namespace std;

template<typename T>
void Task(DoubleLink<T>& list)
{
    if (list.getSize() < 2 || list.getSize() % 2)
        throw invalid_argument("Invalid list size");

    double max = list.getHead()->Data + list.getTail()->Data;
    int Index1 = 0, Index2 = list.getSize() - 1;

    Node<T>* Temp1 = list.getHead();
    Node<T>* Temp2 = list.getTail();
    for (int i = 1; i < list.getSize() / 2; i++)
    {
        Temp1 = Temp1->Next;
        Temp2 = Temp2->Prev;
        double temp = Temp1->Data + Temp2->Data;

        if (temp > max)
        {
            max = temp;
            Index1 = i;
            Index2 = list.getSize() - i - 1;
        }
    }

    list.TaskResult(max, Index1, Index2);
}

int main()
{
    int n;
    cout << "Enter amount of numbers: ";
    cin >> n;

    DoubleLink<double> list;

    list.Fill(n);
    list.PrintList();
    Task(list);
}