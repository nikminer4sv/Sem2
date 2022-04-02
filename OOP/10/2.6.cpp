#include <iostream>
#include "Vector1.h"

using namespace std;

template <typename T>
void writelong(Vector<T> vec)
{
    printf("%d", vec.getSize() == 0 ? 0 : vec.back());

    for (int i = (int)vec.getSize() - 2; i >= 0; --i)
        printf("%09d", vec[i]);
}

template <typename T>
void Print(Vector<T> array)
{
    int i = 0;
    while (i < array.getSize())
    {
        cout << array[i] << endl;;
        i++;
    }
}

template <typename T>
Vector<T> smult(Vector<T> a, int b)
{
    int carry = 0;

    for (size_t i = 0; i < a.getSize() || carry; ++i)
    {

        if (i == a.getSize())
            a.push_back(0);
        long long cur = carry + a[i] * 1ll * b;
        a[i] = int(cur % base);
        carry = int(cur / base);
    }

    while (a.getSize() > 1 && a.back() == 0)
        a.pop_back();

    return a;
}

int main()
{
    int b;
    cin >> b;

    Vector<int> array(1), array1(1), array2(1);
    array.push_back(1);

    for (int i = 1; i <= b; i++)
        array = smult(array, i);

    array1 = array;
    array2 = array + array1;

    //writelong(array);
    Print(array2);
}