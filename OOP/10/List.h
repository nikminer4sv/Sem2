#pragma once

#include <iostream>
#include <cstring>

template <typename T>
struct Node
{
    T Data;
    Node *Next;

    Node() { Next = nullptr; }
};

template <typename T>
class CharList
{
private:
    Node<T> *Head;
    int Size;

public:
    CharList()
    {
        Head = nullptr;
        Size = 0;
    }

    CharList(const CharList &obj)
    {
        this->Size = obj.Size;

        Node<T> *NewNode = new Node<T>();
        this->Head = NewNode;
        Node<T> *Temp = obj.Head;

        for (size_t i = 0; i < this->Size; i++)
        {
            NewNode->Data = Temp->Data;
            NewNode->Next = new Node<T>();
            Temp = Temp->Next;
            NewNode = NewNode->Next;
        }
    }

    char Get(int Index) const
    {
        if (Index > Size - 1 || Index < 0)
        {
            throw std::invalid_argument("Invalid index");
        }

        Node<T> *Temp = Head;

        for (int i = 0; i < Index; i++)
        {
            Temp = Temp->Next;
        }

        return Temp->Data;
    }

    void Add(const T &Symbol)
    {
        Size++;

        Node<T> *NewNode = new Node<T>;
        NewNode->Data = Symbol;

        if (Head == nullptr)
        {
            Head = NewNode;
        }
        else
        {
            Node<T> *temp = Head;

            while (temp->Next != nullptr)
            {
                temp = temp->Next;
            }

            temp->Next = NewNode;
        }
    }

    void Add(char *text)
    {
        for (int i = 0; i < strlen(text); i++)
        {
            Add(text[i]);
        }
    }

    bool Remove(int Index)
    {
        if (Size == 0 || Index > Size - 1 || Index < 0)
            return false;

        if (Index == 0)
        {
            auto *next = Head->Next;
            delete Head;
            Head = next;
        }
        else
        {
            Node<T> *Temp = Head;

            for (int i = 0; i < Index - 1; i++)
            {
                Temp = Temp->Next;
            }

            auto *to_delete = Temp->Next;
            Temp->Next = Temp->Next->Next;
            delete to_delete;
        }

        Size--;

        return true;
    }

    bool Insert(int Index, const T &Symbol)
    {
        if (Index > Size - 1 || Index < 0)
            return false;

        Node<T> *Temp = new Node<T>;
        Temp->Data = Symbol;

        if (Index == 0)
        {
            Temp->Next = Head;
            Head = Temp;
        }
        else
        {
            Node<T> *Temp1 = Head;

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
    
    bool Search(const CharList& list1, const size_t& index)
    {
        bool Flag = true;
        size_t size = list1.getSize();
        
        for (int j = 0; j < size; j++) 
        {
            if (this->Get(index + j) != list1.Get(j)) 
            {
                Flag = false;
                break;
            }
        }

        return Flag;
    }

    ~CharList()
    {
        Clear();
    }

    void Clear()
    {
        Node<T> *current = Head;

        while (current != nullptr)
        {
            Node<T> *next = current->Next;
            delete current;
            current = next;
        }

        Head = nullptr;
        Size = 0;
    }

    int getSize() const
    {
        return Size;
    }

    void Print()
    {
        for (int i = 0; i < getSize(); i++)
        {
            std::cout << Get(i);
        }

        std::cout << std::endl;
    }
};