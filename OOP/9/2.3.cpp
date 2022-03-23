#include <iostream>
#include "Common/nikminer4sv.h"

using namespace std;
using namespace nikminer4sv;

double Task(DoublyLinkedList<double>& list) {

    if (list.GetSize() < 2 || list.GetSize() % 2)
        throw invalid_argument("invalid arguments");
        
    double min = list[0] + list[list.GetSize() - 1];
    
    for (int i = 1; i < list.GetSize() - 1; i++) {

        double temp = list[i] + list[list.GetSize() - i - 1];

        if (temp < min)
            min = temp;

    }

    return min;

}

int main() {

    DoublyLinkedList<double> list;
    
    list.Append(1.3);
    list.Append(2.123);
    list.Append(3.5678);
    list.Append(4.123);
    list.Append(0.5678);
    list.Append(8.123);
    
    cout << Task(list);

}