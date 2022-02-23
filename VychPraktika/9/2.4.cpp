#include <iostream>

using namespace std;

struct Node {

    char Data;
    Node* Next;

    Node() { Next = nullptr; }

};

class CharList {
private:
    Node* Head;

public:
    int Size;

public:
    CharList() { 

        Head = nullptr; 
        Size = 0;

    }

    char& Get(int Index) {

        if (Index > Size - 1 || Index < 0)
            throw invalid_argument("Invalid index");

        Node* Temp = Head;

        for (int i = 0; i < Index; i++)
            Temp = Temp->Next;

        return Temp->Data;
    }

    void Add(const char& Symbol) {

        Size += 1;

        Node* NewNode = new Node;
        NewNode->Data = Symbol;

        if (Head == nullptr) {

            Head = NewNode;

        } else {

            Node* temp = Head;

            while (temp->Next != nullptr)
                temp = temp->Next;
            
            temp->Next = NewNode;

        }

    }

    void Add(char* text) {

        for (int i = 0; i < strlen(text); i++)
            Add(text[i]);

    }

    bool Remove(int Index) {

        if (Index > Size - 1 || Index < 0)
            return false;

        if (Index == 0) {

            Head = Head->Next;

        } else {

            Node* Temp = Head;

            for (int i = 0; i < Index - 1; i++) 
                Temp = Temp->Next;

            Temp->Next = Temp->Next->Next;
        }

        Size -= 1;

        return true;

    }

    ~CharList() {

        Node* current = Head;

        while(current != nullptr) {
            Node* next = current->Next;
            delete current;
            current = next;
        }

        Head = nullptr;

    }

};

void PrintList(CharList& list) {

    for (int i = 0; i < list.Size; i++) 
        cout << list.Get(i);

    cout << endl;

}

void Task(CharList& list1, CharList& list2) {

    if (list2.Size == 0 || list1.Size - list2.Size < 0) 
        return;

    int forSize = list1.Size - list2.Size;

    for (int i = 0; i < forSize + 1; i++) {

        bool exist = true;

        for (int j = 0; j < list2.Size; j++) {

            if (list1.Get(i + j) != list2.Get(j)) {

                exist = false;
                break;

            }

        }

        if (exist) {

            for (int j = 0; j < list2.Size; j++) 
                list1.Remove(i);

            forSize = list1.Size - list2.Size;

        }

    }

}

int main() {

    CharList list1;
    CharList list2;
    list1.Add("Hello dear friend, you are awesome");
    list2.Add("are");

    Task(list1, list2);

    PrintList(list1);

}   