#include <iostream>

using namespace std;

struct Node {

    double Data;
    Node* Next;
    Node* Prev;

    Node() { Next = nullptr; Prev = nullptr;}


};

class DoubleLink
{
private:
    Node* Head;
    int Size;

public:

    DoubleLink()
    {
        Head = nullptr;
        Size = 0;
    }

    int getSize() const
    {
        return Size;
    }

    double Get(int Index)
    {
        if (Index > Size - 1 || Index < 0)
            throw invalid_argument("Invalid index");

        Node* Temp = Head;

        if (Index >= Size / 2 + 1)
        {
            for (int j = Size - 1; j > Index - 1; j--)
            {
                Temp = Temp->Prev;
            }

        }
        else
        {
            for (int i = 0; i < Index; i++)
            {
                Temp = Temp->Next;
            }
        }

        return Temp->Data;
    }

    void Add(const double Value)
    {
        Node* NewNode = new Node;
        NewNode->Data = Value;

        if (Head == nullptr)
        {
            Head = NewNode;
        }
        else
        {
            if (Size == 1)
            {
                Head->Next = NewNode;
                Head->Prev = NewNode;
                NewNode->Prev = Head;
                NewNode->Next = Head;
            }
            else
            {
                Node* temp = Head->Prev;
                temp->Next = NewNode;
                NewNode->Prev = temp;
                NewNode->Next = Head;
                Head->Prev = NewNode;
            }
        }

        Size += 1;
    }

    bool Remove(int Index)
    {
        if (Size == 0 || Index > Size - 1 || Index < 0)
            return false;

        if (Index == 0)
        {
            // Head->Prev->Next = Head->Next;
            // Head->Next->Prev = Head->Prev;
            // Head = Head->Next;
            auto* delete_el = Head;
            delete_el->Prev->Next = Head->Next;
            delete_el->Next->Prev = Head->Prev;
            Head = delete_el->Next;
            delete[] delete_el;
        }
        else
        {
            Node* Temp = Head;

            for (int i = 0; i < Index - 1; i++)
            {
                Temp = Temp->Next;
            }

            // Temp->Next->Next->Prev = Temp;
            // Temp->Next = Temp->Next->Next;
            auto* delete_el = Temp;
            Temp->Next->Next->Prev = delete_el;
            Temp->Next = delete_el->Next->Next;
            delete[] delete_el;
        }

        Size--;

        return true;
    }

    void PrintList()
    {
        for (int i = 0; i < Size; i++)
        {
            if (i % 10 == 0 && i != 0)
                cout << endl;
            cout << Get(i) << " ";
        }
        cout << endl;
    }

    void Clear()
    {
        Node* current = Head;

        while(current->Next != Head)
        {
            Node* next = current->Next;
            delete current;
            current = next;
        }

        Head = nullptr;
    }

    ~DoubleLink()
    {
        Clear();
    }
};

void Fill(DoubleLink& list, int n)
{
    for (int i = 0; i < 2 * n; i++)
    {
        list.Add((rand() % 1000 + 1) / 100.0);
    }
}

void TaskResult(double max, int Index1, int Index2)
{
    cout << "Max sum: " << max << endl <<
            "Indexes: " << Index1 << " and " << Index2 << " (Begins from 0)" << endl;
}

void Task(DoubleLink& list)
{
    if (list.getSize() < 2 || list.getSize() % 2)
        throw invalid_argument("Invalid list size");

    double max = list.Get(0) + list.Get(list.getSize() - 1);
    int Index1 = 0, Index2 = list.getSize() - 1;

    for (int i = 1; i < list.getSize() - 1; i++)
    {
        double temp = list.Get(i) + list.Get(list.getSize() - i - 1);

        if (temp > max)
        {
            max = temp;
            Index1 = i;
            Index2 = list.getSize() - i - 1;
        }
    }

    TaskResult(max, Index1, Index2);
}

int main()
{
    int n;
    cout << "Enter amount of numbers: ";
    cin >> n;

    DoubleLink list;

    Fill(list, n);
    list.PrintList();
    Task(list);
}