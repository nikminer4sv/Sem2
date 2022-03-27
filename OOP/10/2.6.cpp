#include <iostream>
#include "Vector.h"

using namespace std;

#define base 1000000000

template<typename T>
void writelong(Vector<T> vec){
    printf ("%d", vec.getSize() == 0 ? 0 : vec[vec.getSize() - 1]);

    for (int i = (int)vec.getSize() - 2; i >= 0; --i)
        printf ("%09d", vec[i]);

}

template<typename T>
void Print(Vector<T> array)
{
    int i = array.getSize() - 1;
    while (i >= 0)
    {
        cout << array[i];
        i--;
    }
}

template<typename T>
Vector<T> smult(Vector<T> a, int b){
    int carry = 0;

    for (size_t i = 0; i < a.getSize() || carry; ++i) {

        if (i == a.getSize())
            a.push_back(0);
        long long cur = carry + a[i] * 1ll * b;
        a[i] = int (cur % base);
        carry = int (cur / base);

    }

    while (a.getSize() > 1 && a[a.getSize() - 1] == 0)
        a.pop_back();

    return a;
}

int main()
{
    int b;
    cin >> b;

    Vector<int> array(1);
    array.push_back(1);

    for (int i = 1; i <= b; i++)
        array = smult(array,i);

    writelong(array);
}