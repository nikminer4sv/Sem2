#include <iostream>

using namespace std;

struct Element {

    int Value;
    Element* Next;

    Element() { Next = nullptr; Value = 0; }

    Element(int Value) { Next = nullptr; this->Value = Value; }

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

    Vector(Vector& Other) {

        First = nullptr;
        Size = 0;

        this->SetSize(Other.GetSize());

        for (int i = 0; i < Other.GetSize(); i++)
            *this->GetElement(i) = *Other.GetElement(i);

    }

    void SetSize(int Size) { 

        if (this->Size == 0) {

            Element* Temp = nullptr;

            Element* FirstElement = new Element;
            FirstElement->Value = 0;

            First = FirstElement;
            Temp = First;

            for (int i = 1; i < Size; i++) {

                Element* NewElement = new Element;
                NewElement->Value = 0;
                Temp->Next = NewElement;
                Temp = Temp->Next;

            }

        } else if (Size < this->Size) {

            Element* Temp = First;

            for (int i = 0; i < Size - 1; i++)
                Temp = Temp->Next;

            Temp->Next = nullptr;

        } else {

            Element* Temp = First;

            for (int i = 0; i < this->Size - 1; i++)
                Temp = Temp->Next;

            for (int i = 0; i < Size - this->Size; i++) {

                Element* NewElement = new Element;
                Temp->Next = NewElement;
                Temp = Temp->Next;

            }

        }

        this->Size = Size; 

    }

    int* GetElement(int Index) {

        Index = Index % Size;

        Element* Temp = First;

        for (int i = 0; i < Index; i++)
            Temp = Temp->Next;

        return &Temp->Value;

    }

    int GetSize() { return Size; }

    void RandomFill(int LeftBorder, int RightBorder) {

        Element* Temp = First;

        for (int i = 0; i < Size; i++) {

            Temp->Value = GetRandomInt(LeftBorder, RightBorder);
            Temp = Temp->Next;

        }

        //Temp->Value = GetRandomInt(LeftBorder, RightBorder);

    }

    Element* GetFirst() {
        return First;
    }

    int& operator[] (const int Index) {

        return *this->GetElement(Index);

    }

    friend ostream& operator<< (ostream &out, Vector vector) {
        
        for (int i = 0; i < vector.GetSize() - 1; i++)
            out << vector[i] << " ";

        out << vector[vector.GetSize() - 1];

        return out;

    }

    friend istream& operator>> (istream &in, Vector& vector) {


        for (int i = 0; i < vector.GetSize(); i++) {

            in >> vector[i];

        }

        return in;

    }


};

int main() {

    srand(time(NULL));

    Vector v;
    v.SetSize(3);
    cin >> v;
    cout << v;

}