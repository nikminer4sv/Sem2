#pragma once

#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T Data;
    Node* Next = nullptr;

    Node() = default;
};

template <typename T>
class List
{
private:
    Node<T>* Head = nullptr;
    int Size = 0;

public:
    List() = default;

    List(const List<T>& obj)
    {
        Copy(obj);
    }

    List(List<T>&& obj)
    {
        Size = obj.getSize();
        Head = obj.Head();
        obj.Head = nullptr;
        obj.Size = 0;
    }

    List<T>& operator= (const List<T>& obj)
    {
        Copy(obj);

        return *this;
    }

    List<T>& operator= (List<T>&& obj)
    {
        Size = obj.getSize();
        Head = obj.Head;
        obj.Head = nullptr;
        obj.Size = 0;

        return *this;
    }

    char Get(int Index) const
    {
        if (Index > Size - 1 || Index < 0)
        {
            throw std::invalid_argument("Invalid index");
        }

        Node<T>* Temp = Head;

        for (int i = 0; i < Index; i++)
        {
            Temp = Temp->Next;
        }

        return Temp->Data;
    }

    void Add(const T& value)
    {
        Size++;

        Node<T>* NewNode = new Node<T>;
        NewNode->Data = value;

        if (Head == nullptr)
        {
            Head = NewNode;
        }
        else
        {
            Node<T>* temp = Head;

            while (temp->Next != nullptr)
            {
                temp = temp->Next;
            }

            temp->Next = NewNode;
        }
    }

    bool Remove(int Index)
    {
        if (Size == 0 || Index > Size - 1 || Index < 0)
            return false;

        if (Index == 0)
        {
            auto* next = Head->Next;
            delete Head;
            Head = next;
        }
        else
        {
            Node<T>* Temp = Head;

            for (int i = 0; i < Index - 1; i++)
            {
                Temp = Temp->Next;
            }

            auto* to_delete = Temp->Next;
            Temp->Next = Temp->Next->Next;
            delete to_delete;
        }

        Size--;

        return true;
    }

    bool Insert(int Index, const T& value)
    {
        if (Index > Size - 1 || Index < 0)
            return false;

        Node<T>* Temp = new Node<T>;
        Temp->Data = value;

        if (Index == 0)
        {
            Temp->Next = Head;
            Head = Temp;
        }
        else
        {
            Node<T>* Temp1 = Head;

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

    ~List()
    {
        Clear();
    }

    void Clear()
    {
        Node<T>* current = Head;

        while (current != nullptr)
        {
            Node<T>* next = current->Next;
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

    void Print(ostream& os)
    {
        Node<T>* Temp = Head;
        for (int i = 0; i < getSize(); i++)
        {
            (*(Temp->Data)).Print(os);
            Temp = Temp->Next;
        }

        os << std::endl;
    }

    void Copy(const List<T>& obj)
    {
        if (Head)
        {
            delete Head;
        }
        this->Size = obj.Size;

        Node<T>* NewNode = new Node<T>();
        this->Head = NewNode;
        Node<T>* Temp = obj.Head;

        for (size_t i = 0; i < this->Size; i++)
        {
            NewNode->Data = Temp->Data;
            NewNode->Next = new Node<T>();
            Temp = Temp->Next;
            NewNode = NewNode->Next;
        }
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, List<T>& list)
{
    list.Print(os);

    return os;
}