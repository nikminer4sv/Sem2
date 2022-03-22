#include <iostream>
#include "Common/nikminer4sv.h"

using namespace std;
using namespace nikminer4sv;

void Task(List<char>& list1, List<char>& list2) {

    if (list2.GetSize() == 0 || list1.GetSize() - list2.GetSize() < 0) 
        return;

    int forSize = list1.GetSize() - list2.GetSize();

    for (int i = 0; i < forSize + 1; i++) {

        bool exist = true;

        for (int j = 0; j < list2.GetSize(); j++) {

            if (list1[i + j] != list2[j]) {

                exist = false;
                break;

            }

        }

        if (exist) {

            for (int j = 0; j < list2.GetSize(); j++) 
                list1.Remove(i);

            forSize = list1.GetSize() - list2.GetSize();

        }

    }

}

int main() {

    List<char> list1;
    List<char> list2;

    list1.Append('H');
    list1.Append('e');
    list1.Append('l');
    list1.Append('l');
    list1.Append('o');

    list2.Append('e');
    list2.Append('l');

    Task(list1, list2);


    cout << list1 << endl;

}