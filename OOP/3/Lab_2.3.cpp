#include <iostream>
#include "DoubleLink.h"
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int n;
    cout << "Enter amount of numbers: ";
    cin >> n;

    DoubleLink<int> list;

    list.Fill(list, n);
    list.PrintList();
     cout << "Sum: " << list.Task(list, n);
}
