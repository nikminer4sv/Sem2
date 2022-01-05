#include <iostream>

using namespace std;

struct Element {

    int Value;
    Element* Prev;
    Element* Next;

    Element() { Prev = nullptr; Next = nullptr; }

    Element(int Value) { Prev = nullptr; Next = nullptr; this->Value = Value; }

};

class Vector {
private:
    Element* First;
    int Size;

public:

private:
    int GetRandomInt(int min, int max) {
        return min + (rand() % (max - min + 1));
    }

public:
    Vector() {

        First = nullptr;
        Size = 0;

    }

    void SetSize(int Size) { 

        this->Size = Size; 


    }

    int GetSize() { return Size; }

    void RandomFill(int LeftBorder, int RightBorder) {

        for (int i = 0; i < Size; i++) {
            
        }

    }

};

int main() {

    Vector v;

}