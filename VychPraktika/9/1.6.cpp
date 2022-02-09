#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
void Print(T element) {

    cout << typeid(element).name();

}

int main() {

    Print(array);

}