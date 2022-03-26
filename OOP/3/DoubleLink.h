#pragma once

template <typename T>
struct Node
{
    T Data;
    Node *Next;
    Node *Prev;

    Node(T Data)
    {
        this->Data = Data;
        Next = nullptr;
        Prev = nullptr;
    }
};

template <typename T>
class DoubleLink
{
private:
    Node<T> *Head;
    Node<T> *Tail;
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

    Node<T> *getHead()
    {
        return Head;
    }

    Node<T> *getTail()
    {
        return Tail;
    }

    void Add(const T Value)
    {
        if (Head == nullptr)
        {
            Head = new Node<T>(Value);
            Head->Data = Value;
            Head->Next = Tail;
            Head->Prev = Tail;
        }
        else
        {
            if (Size == 1)
            {
                Tail = new Node<T>(Value);
                Tail->Data = Value;
                Head->Next = Tail;
                Head->Prev = Tail;
                Tail->Prev = Head;
                Tail->Next = Head;
            }
            else
            {
                Tail->Next = new Node<T>(Value);
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
            auto *delete_el = Head;
            delete_el->Prev->Next = Head->Next;
            delete_el->Next->Prev = Head->Prev;
            Head = delete_el->Next;
            delete delete_el;
        }
        else
        {
            Node<T> *Temp = Head;

            for (int i = 0; i < Index - 1; i++)
            {
                Temp = Temp->Next;
            }

            auto *delete_el = Temp;
            Temp->Next->Next->Prev = delete_el;
            Temp->Next = delete_el->Next->Next;
            delete delete_el;
        }

        Size--;

        return true;
    }

    void PrintList()
    {
        Node<T> *Temp = Head;
        for (int i = 0; i < Size; i++)
        {
            if (i % 10 == 0 && i != 0)
                std::cout << std::endl;
            std::cout << Temp->Data << " ";
            Temp = Temp->Next;
        }
        std::cout << std::endl;
    }

    void Clear()
    {
        Node<T> *current = Head;

        while (current->Next != Head)
        {
            Node<T> *Next = current->Next;
            delete current;
            current = Next;
        }

        Head = nullptr;
    }

    void Fill(DoubleLink &list, int n)
    {
        for (int i = 0; i < n; i++)
            list.Add((rand() % 1000 + 1) / 100.0);
    }

    double Task(DoubleLink &list, int n)
    {
        Node<T> *Temp1 = list.getHead();
        Node<T> *Temp2 = Temp1->Next;
        Node<T> *Temp3 = list.getTail();
        int Temp4 = n;

        double sum = 0;
        int Index1 = 0, Index2 = list.getSize() - 1;

        for (int i = 0; i < n - 2; i++)
        {
            std::cout << '(' << Temp1->Data << " + " << Temp2->Data << " + " << Temp4 << " * " << Temp3->Data << ")  +  ";
            sum += Temp1->Data + Temp2->Data + Temp4 * Temp3->Data;
            Temp1 = Temp1->Next;
            Temp2 = Temp2->Next;
            Temp3 = Temp3->Prev;
            Temp4--;
        }
        std::cout << std::endl;
        return sum;
    }

    ~DoubleLink()
    {
        Clear();
    }
};