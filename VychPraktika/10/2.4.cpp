#include <iostream>
#include <cstring>

using namespace std;

struct Node 
{
    char Data;
    Node* Next;

    Node() { Next = nullptr; }
};

class CharList 
{
private:
    Node* Head;

public:
    int Size;

public:
    CharList() 
    { 
        Head = nullptr; 
        Size = 0;
    }

    char& Get(int Index) 
    {
        if (Index > Size - 1 || Index < 0)
        {
            throw invalid_argument("Invalid index");
        }

        Node* Temp = Head;

        for (int i = 0; i < Index; i++)
        {
            Temp = Temp->Next;
        }

        return Temp->Data;
    }

    void Add(const char& Symbol) 
    {
        Size++;

        Node* NewNode = new Node;
        NewNode->Data = Symbol;

        if (Head == nullptr) 
        {
            Head = NewNode;
        } 
        else 
        {
            Node* temp = Head;

            while (temp->Next != nullptr)
            {
                temp = temp->Next;
            }
            
            temp->Next = NewNode;
        }
    }

    void Add(char* text) 
    {
        for (int i = 0; i < strlen(text); i++)
        {
            Add(text[i]);
        }
    }

    bool Remove(int Index)
    {
        if (Index > Size - 1 || Index < 0)
            return false;

        if (Index == 0) 
        {
            Head = Head->Next;
        } 
        else 
        {
            Node* Temp = Head;

            for (int i = 0; i < Index - 1; i++) 
            {
                Temp = Temp->Next;
            }

            Temp->Next = Temp->Next->Next;
        }

        Size --;

        return true;
    }

    bool Insert(int Index, const char& Symbol)
    {
        if (Index > Size - 1 || Index < 0)
            return false;

        Node* Temp = new Node;
        Temp->Data = Symbol;

        if (Index == 0) 
        {
            Temp->Next = Head;
            Head = Temp;
        } 
        else 
        {
            Node* Temp1 = Head;

            for (int i = 0; i < Index - 1; i++) 
            {
                Temp1 = Temp1->Next;
            }

            Temp->Next = Temp1->Next;
            Temp1->Next = Temp;
        }

        Size++;

        return true;
    }

    ~CharList() 
    {
        Node* current = Head;

        while(current != nullptr) 
        {
            Node* next = current->Next;
            delete current;
            current = next;
        }

        Head = nullptr;
    }

};

void PrintList(CharList& list) 
{
    for (int i = 0; i < list.Size; i++) 
    {
        cout << list.Get(i);
    }

    cout << endl;
}

void Task(CharList& listmain, CharList& list1, CharList& list2) 
{
    if (list1.Size == 0 || listmain.Size - list1.Size < 0) 
        return;

    int forSize = listmain.Size - list1.Size;

    for (int i = 0; i < forSize + 1; i++) 
    {
        bool Flag = true;

        for (int j = 0; j < list1.Size; j++) 
        {
            if (listmain.Get(i + j) != list1.Get(j)) 
            {
                Flag = false;
                break;
            }
        }
        if (Flag) 
        {
            for (int j = 0; j < list1.Size; j++) 
            {
                listmain.Remove(i);
            }

            int k = i;

            for (int j = 0; j < list2.Size; j++) 
            {
                listmain.Insert(k++, list2.Get(j));
            }

            forSize = listmain.Size + list2.Size - list1.Size;
        }
    }
}

int main() {

    CharList listmain, list1, list2;
    listmain.Add("Modern problems require modern solutions");
    list1.Add("problems");
    list2.Add("people");

    Task(listmain, list1, list2);

    PrintList(listmain);

}   