#include <iostream>


//TODO: у листа хранить также и поинтер на хвост

//TODO: при подсчете таски юзать не гет, а итерировать через ->Next и ->Prev


using namespace std;

struct Node {

    double Data;
    Node* Next;
    Node* Prev;

    Node() { Next = nullptr; Prev = nullptr; }
};

class DoubleLink
{
private:
    Node* Head;
    Node* Tail;
    int Size;

public:

    DoubleLink()
    {
        Head = nullptr;
        Tail = nullptr;
        Size = 0;
    }

    int getSize() const
    {
        return Size;
    }

    Node* getHead()
    {
        return Head;
    }

    Node* getTail()
    {
        return Tail;
    }

    void Add(const double Value)
    {
        if (Head == nullptr)
        {
            Head = new Node;
            Head->Data = Value;
            Head->Next = Tail;
            Head->Prev = Tail;
        }
        else
        {
            if (Size == 1)
            {
                Tail = new Node;
                Tail->Data = Value;
                Head->Next = Tail;
                Head->Prev = Tail;
                Tail->Prev = Head;
                Tail->Next = Head;
            }
            else
            {
                Tail->Next = new Node;
                Tail->Next->Prev = Tail;
                Tail = Tail->Next;
                Tail->Next = Head;
                Tail->Data = Value;
            }
        }

        Size++;
    }

    bool Remove(int Index)
    {
        if (Size == 0 || Index > Size - 1 || Index < 0)
            return false;

        if (Index == 0)
        {
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
        Node* Temp = Head;
        for (int i = 0; i < Size; i++)
        {
            if (i % 10 == 0 && i != 0)
                cout << endl;
            cout << Temp->Data << " ";
            Temp = Temp->Next;
        }
        cout << endl;
    }

    void Clear()
    {
        Node* current = Head;

        while (current->Next != Head)
        {
            Node* Next = current->Next;
            delete current;
            current = Next;
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

    double max = list.getHead()->Data + list.getTail()->Data;
    int Index1 = 0, Index2 = list.getSize() - 1;

    Node* Temp1 = list.getHead();
    Node* Temp2 = list.getTail();
    for (int i = 1; i < list.getSize() / 2; i++)
    {
        Temp1 = Temp1->Next;
        Temp2 = Temp2->Prev;
        double temp = Temp1->Data + Temp2->Data;

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