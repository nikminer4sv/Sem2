#include <iostream>
#include "Vector1.h"

using namespace std;

template <typename T>
void writelong(Vector<T> vec)
{
    printf("%d", vec.getSize() == 0 ? 0 : vec.back());

    for (int i = (int)vec.getSize() - 2; i >= 0; --i)
        printf("%09d", vec[i]);

    cout << endl;
}

int main()
{
    int b;
    cin >> b;

    Vector<int> array(1), array1(1), array2(1), array3(1);
    array.push_back(1);

    for (int i = 1; i <= b; i++)
        array = smult(array, i);

    array1 = array;
    array2 = array + array1;
    array3 = array * array1;

    cout << "number -> ";
    writelong(array);
    cout << "number + number -> ";
    writelong(array2);
    cout << "number * number -> ";
    writelong(array3);

    //Print(array2);
}