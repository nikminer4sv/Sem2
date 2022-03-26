#pragma once

#include <iostream>
#include <conio.h>
#include <ctime>

template <typename T>
struct Node
{
    int Data;
    Node* Left;   
    Node* Right; 

    Node()
    {
        Left = nullptr;
        Right = nullptr;
    }
};

template <typename T>
class Tree
{
    private:
    Node<T>* Head = nullptr;

    public:
    Tree() = default;

    Tree(const Tree& obj)
    {
        Node<T>* Temp = obj.Head;
        AddNode(Head, Temp);
    }

    ~Tree()
    {
        Clear(Head);
    }

    Node<T>* getHead()
    {
        return Head;
    }

    void Clear(Node<T>* Temp)
    {
        if (Temp)
        {
            Clear(Temp->Left);
            Clear(Temp->Right);
            delete Temp;
        }
    }

    void AddNode(Node<T>* Temp1, Node<T>* Temp2)
    {
        if (Temp2)
        {
            if (!Temp1)
            {
                Temp1 = new Node<T>;
            }
            Add(Temp2->Data);
            AddNode(Temp1->Left, Temp2->Left);
            AddNode(Temp1->Right, Temp2->Right);
        }
    }

    void Add(const T& value)
    {
        Node<T>* pnew = new Node<T>;
        pnew->Data = value;

        if (!Head)
            Head = pnew;
        else
        {
            Node<T>* ppv;
            ppv = Search(value);

            if (value < ppv->Data)
                ppv->Left = pnew;
            else
                ppv->Right = pnew;
        }
    }

    Node<T>* Search(const T& value)
    {
        Node<T>* pv = Head, *ppv = Head;

        while (pv)
        {
            ppv = pv;

            if (value < pv->Data)
                pv = pv->Left;
            else
                pv = pv->Right;
        }

        return ppv;
    }

    Node<T>* Find(Node<T>* Temp, const T& Data, int& Counter)
    {
        if (!Temp)
            return NULL;

        Node<T>* p = new Node<T>;

        if (Data < Temp->Data)
        {
            Counter++;
            p = Find(Temp->Left, Data, Counter);
        }
        else if (Data > Temp->Data)
        {
            Counter++;
            p = Find(Temp->Right, Data, Counter);
        }
        else
        {
            p = Temp;
        }

        return p;
    }

    void Print(Node<T>* Temp, const int& level)
    {
        if (Temp)
        {
            Print(Temp->Left, level + 1);
            for (int i = 0; i < level; i++)
                std::cout << "\t";

            std::cout << Temp->Data << std::endl;
            Print(Temp->Right, level + 1);
        }
    }
};