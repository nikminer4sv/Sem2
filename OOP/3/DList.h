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
class DList
{
private:
    Node<T> *Head;
    Node<T> *Tail;
    int Size;

public:
    DList()
    {
        Head = nullptr;
        Tail = nullptr;
        Size = 0;
    }

    DList(const T value) : DList() { Add(value); }

    ~DList()
    {
        if (Head)
            Clear();
    }

    int getSize() const { return Size; }

    Node<T> *getHead() const { return Head; }

    Node<T> *getTail() const { return Tail; }

    DList &operator=(DList &obj)
    {
        copy(obj);
        return *this;
    }

    void copy(DList &obj)
    {
        if (this->Head)
            this->Clear();

        T value;
        for (int i = 0; i < obj.getSize(); i++)
        {
            value = obj.getDataForIndex(i);
            this->Add(value);
        }
    }

    void Add(const T Value)
    {
        if (Head == nullptr)
        {
            Head = new Node<T>(Value);
            Head->Next = Tail;
            Head->Prev = Tail;
        }
        else
        {
            if (Size == 1)
            {
                Tail = new Node<T>(Value);
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
                Head->Prev = Tail;
            }
        }

        Size++;
    }

    T getDataForData(const T value)
    {
        Node<T> *Temp = Head;

        while (value != Temp->Data)
        {
            Temp = Temp->Next;
        }

        return Temp->Data;
    }

    T getDataForIndex(const int idx)
    {
        Node<T> *Temp = Head;
        int i = 0;
        while (i != idx)
        {
            Temp = Temp->Next;
            i++;
        }

        return Temp->Data;
    }

    bool Remove(const int Index)
    {
        if (Size == 0 || Index > Size - 1 || Index < 0)
            return false;

        if (Index == 0)
        {
            Node<T> *delete_el = Head;
            Head->Prev->Next = Head->Next;
            Head->Next->Prev = Head->Prev;
            Head = Head->Next;
            delete delete_el;
        }
        else
        {
            Node<T> *Temp = Head;

            for (int i = 0; i < Index; i++)
                Temp = Temp->Next;

            Node<T> *delete_el = Temp;

            Temp->Next->Prev = Temp->Prev;
            Temp->Prev->Next = Temp->Next;

            delete delete_el;
        }

        Size--;
        std::cout << "Size -> " << Size << std::endl;
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
        while (--Size)
        {
            Head = Head->Next;
            delete Head->Prev;
        }
        Head = nullptr;
    }

    void Fill(DList &list, int n)
    {
        for (int i = 0; i < n; i++)
            list.Add((rand() % 1000 + 1) / 100.0);
    }

    double Task(DList &list, int n)
    {
        Node<T> *Temp1 = list.getHead();
        Node<T> *Temp2 = Temp1->Next;
        Node<T> *Temp3 = list.getTail();
        int Temp4 = n;

        double sum = 0;

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
};