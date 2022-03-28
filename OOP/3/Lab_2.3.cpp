#include <iostream>
#include "DList.h"
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int n;
    cout << "Enter amount of numbers: ";
    cin >> n;

    DList<int> list(2);
    list.PrintList();

    DList<int> l2(4);
    l2.PrintList();
    l2 = list;
    l2.PrintList();

    list.Fill(n);
    list.PrintList();
    cout << "Sum: " << Task(list, n) << endl;
    cout << "Size -> " << list.getSize() << endl;

    int idx;
    cout << "Enter the index of element for delete." << endl;
    cin >> idx;
    list.Remove(idx);
    list.PrintList();

    int choose;
    cout << "Enter the data, that you want to get." << endl;
    cin >> choose;
    cout << list.contains(choose) << endl;

    cout << "Enter the index of data, that you want to get." << endl;
    cin >> choose;
    cout << list.getDataForIndex(choose) << endl;

    list.Clear();
    list.PrintList();
    cout << "Zakoncheno!" << endl;

    return 0;
}
