#pragma once

#include <iostream>

template<typename T>
struct Node {

    T Data;
    Node* Next;
    Node* Prev;

    Node() { Next = nullptr; Prev = nullptr; }
};

template<typename T>
class DoubleLink
{
private:
    Node<T>* Head = nullptr;
    Node<T>* Tail = nullptr;
    int Size = 0;

public:

    DoubleLink() = default;

    DoubleLink(const DoubleLink& obj)
    {
        Node<T> *Temp = obj.Head;

        while (Temp != nullptr)
        {
            Add(Temp->Data);
            Temp = Temp->Next;
        }
    }

    int getSize() const
    {
        return Size;
    }

    Node<T>* getHead()
    {
        return Head;
    }

    Node<T>* getTail()
    {
        return Tail;
    }

    void Add(const T& Value)
    {
        if (Head == nullptr)
        {
            Head = new Node<T>;
            Head->Data = Value;
            Tail = Head;
        }
        else
        {
            Tail->Next = new Node<T>;
            Tail->Next->Prev = Tail;
            Tail = Tail->Next;
            Tail->Data = Value;
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
            Head = delete_el->Next;
            delete delete_el;
        }
        else
        {
            Node<T>* Temp = Head;
            for (int i = 0; i < Index ; i++)
            {
                Temp = Temp->Next;
            }

            auto* delete_el = Temp;
            Temp->Next->Prev = delete_el->Prev;
            Temp->Prev->Next = delete_el->Next;
            delete delete_el;
        }

        Size--;

        return true;
    }

    Node<T> Search(const T& value)
    {
        Node<T>* Temp = Head;
        while(Temp && Temp->Data != value)
        {
            Temp = Temp->Next;
        }

        return *Temp;
    }

    void PrintList()
    {
        Node<T>* Temp = Head;
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
        Node<T>* current = Head;
        while (current)
        {
            Node<T>* Next = current->Next;
            delete current;
            current = Next;
        }

        Head = nullptr;
        Tail = nullptr;
        Size = 0;
    }

    void Fill(int n)
    {
        for (int i = 0; i < 2 * n; i++)
        {
            Add((rand() % 1000 + 1) / 100.0);
        }
    }

    void TaskResult(double max, int Index1, int Index2)
    {
        std::cout << "Max sum: " << max << std::endl <<
            "Indexes: " << Index1 << " and " << Index2 << " (Begins from 0)" << std::endl;
    }

    ~DoubleLink()
    {
        Clear();
    }
};

