#include <iostream>
#include <cstring>
#include "List.h"

using namespace std;

template <typename T>
void Task(CharList<T>& listmain, CharList<T>& list1, CharList<T>& list2) 
{
    if (list1.getSize() == 0 || listmain.getSize() < list1.getSize()) 
        return;

    int forSize = listmain.getSize() - list1.getSize();
    bool Flag = true;
    int i = 0;

    for (; i < forSize + 1; i++) 
    {
        Flag = listmain.Search( list1, i);
        if (Flag) 
        {
            for (int j = 0; j < list1.getSize(); j++) 
            {
                listmain.Remove(i);
            }

            int k = i;

            for (int j = 0; j < list2.getSize(); j++) 
            {
                listmain.Insert(k++, list2.Get(j));
            }

            forSize = listmain.getSize() + list2.getSize() - list1.getSize();
        }
    }
}

int main() {

    CharList<char> listmain, list1, list2;
    listmain.Add("Modern problems require modern solutions");
    list1.Add("problems");
    list2.Add("people");

    Task(listmain, list1, list2);

    listmain.Print();
}   