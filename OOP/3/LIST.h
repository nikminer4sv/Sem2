#pragma once

#include <iostream>

template<typename T>
struct Node
{
    Node *next;
    T symbolData;

    Node(const T symbol)
    {
        symbolData = symbol;
        this->next = nullptr;
    }
    void Print()
    {
        std::cout << symbolData << " " << sizeof(symbolData) << std::endl;
    }
};

template<typename T>
class list
{
private:
    Node<T> *first = nullptr;
    Node<T> *last = nullptr;

    
    int size = 0;

    bool Separator(const T &a, const T &b)
    {
        return a >= b;
    }

    bool Compare(const T &a, const T &b)
    {
        return a == b;
    }

public:
    bool is_empty() const
    {
        return first == nullptr;
    }

    void Clear()
    {
        if (this->first)
        {
            this->size = 0;
            Node<T> *itCurrent = first;
            first = first->next;
            delete itCurrent;

            while (first)
            {
                Node<T> *itCurrent = first;
                first = first->next;
                delete itCurrent;
            }
        }
    }

    void print()
    {

        Node<T> *p = first;
        while (p)
        {
            p->Print();
            p = p->next;
        }
        std::cout << "Size = " << size << std::endl;
        std::cout << std::endl;
    }

    void remove(const T &symbol)
    {
        if (is_empty())
            return;

        if (Compare(first->symbolData, symbol))
        {

            Node<T> *p = first;
            first = p->next;

            size--;
            delete p;
            return;
        }

        if (Compare(last->symbolData, symbol))
        {

            Node<T> *p = first;
            while (p->next != last)
                p = p->next;

            p->next = nullptr;

            size--;
            delete last;
            last = p;
            return;
        }

        Node<T> *itPrev = first;
        Node<T> *itCurrent = first->next;

        while (itCurrent && !Compare(itCurrent->symbolData, symbol))
        {
            itCurrent = itCurrent->next;
            itPrev = itPrev->next;
        }

        if (!itCurrent)
        {
            std::cout << "This element does not exist" << std::endl;
            return;
        }

        itPrev->next = itCurrent->next;
        size--;
        delete itCurrent;
    }

    list() : first(nullptr), last(nullptr) {}

    ~list()
    {
        Clear();
    }

    list &operator=(const list &obj)
    {
        copy(obj);
        return *this;
    }

    void copy(const list &obj)
    {
        if (this->first)
            this->Clear();

        Node<T> *temp = obj.first;

        Node<T> *p = new Node<T>(temp->symbolData);
        this->first = p;
        Node<T> *thisTemp = this->first;
        p->next = thisTemp->next; //пустота
        temp = temp->next;

        while (temp)
        {
            p = new Node<T>(temp->symbolData);

            p->next = thisTemp->next; //пустота

            thisTemp->next = p;

            thisTemp = thisTemp->next; // переход на некст

            temp = temp->next; //
        }
        last = p;
        this->size = obj.size;
    }

    void push_back(T &symbol)
    {

        Node<T> *p = new Node<T>(symbol);

        if (is_empty())
        {
            first = p;
            last = p;
            size++;
            return;
        }

        Node<T> *temp = first;
        size++;

        if (size == 2 && Separator(temp->symbolData, p->symbolData))
        {
            p->next = last;
            first = p;
            return;
        }

        while (temp->next != nullptr)
        {
            if (Separator(p->symbolData, temp->symbolData) && Separator(temp->next->symbolData, p->symbolData))
            {
                p->next = temp->next;
                temp->next = p;
                return;
            }
            else if (Separator(temp->symbolData, p->symbolData))
            {
                p->next = temp;
                first = p;
                return;
            }
            else
                temp = temp->next;
        }

        last->next = p;
        last = p;
    }

    void Task(list &l2)
    {

        Node<T> *itPrev = first;

        while (itPrev->next)
        {
            int quantity = 1;
            while (itPrev->next && Compare(itPrev->symbolData, itPrev->next->symbolData))
            {
                quantity++;
                itPrev = itPrev->next;
            }

            if (quantity == 2)
                l2.push_back(itPrev->symbolData);

            if (itPrev->next)
                itPrev = itPrev->next;
        }
    }
};
