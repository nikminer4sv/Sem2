#pragma once

#include <algorithm>
#include <ctime>
#include <cstring>
#include <iostream>

template <typename T>
class Vector
{
public:
    Vector()
    {
        std::cout << "Vector::Vector() <-" << this << std::endl;
    }

    Vector(const size_t capacity)
    {
        this->_Capacity = capacity;
        this->_Vector = new T[this->_Capacity];
    }

    Vector(const Vector &obj)
    {
        copy(obj);
    }

    Vector &operator=(const Vector &obj)
    {
        copy(obj);
        return *this;
    }

    ~Vector()
    {
        std::cout << "Vector::~Vector() <-" << this << std::endl;
        this->_Capacity = 0;
        this->_Size = 0;
        delete[] this->_Vector;
    }

public:
    int getCapacity() const
    {
        return this->_Capacity;
    }

    size_t getSize() const
    {
        return this->_Size;
    }

    void setSize(const size_t size_new)
    {
        if (size_new > this->_Capacity)
        {
            resize(size_new);
        }

        this->_Size = size_new;
    }

    T &operator[](const size_t idx)
    {
        return at(idx);
    }

    const T &operator[](const size_t idx) const
    {
        return at(idx);
    }

    void push_back(const T &value)
    {
        if (this->_Size >= this->_Capacity)
        {
            resize(std::max(this->_Capacity * 2, this->_Size + 1));
        }

        this->_Vector[this->_Size++] = value;
    }

private:
    T &at(const size_t idx)
    {
        if (idx >= this->_Size)
            throw std::invalid_argument("index is out of bounds");

        return this->_Vector[idx];
    }

    void copy(const Vector &obj)
    {
        if (this->_Vector)
        {
            delete[] this->_Vector;
        }

        this->_Size = obj._Size;
        this->_Capacity = obj._Capacity;
        this->_Vector = new T[this->_Capacity];

        std::memcpy(this->_Vector, obj._Vector, this->_Size * sizeof(T));
    }

    void resize(const size_t capacity_new)
    {
        std::cout << "Vector::resize() -> " << capacity_new << std::endl;

        T *tempVector = new T[capacity_new];

        if (this->_Vector)
        {
            std::memcpy(tempVector, this->_Vector, std::min(capacity_new, this->_Capacity) * sizeof(T));
            delete[] this->_Vector;
        }

        this->_Vector = tempVector;
    }

private:
    size_t _Capacity = 0;
    size_t _Size = 0;
    T *_Vector = nullptr;
};

template <typename T>
void randomFill(Vector<T> &obj)
{
    srand(time(NULL));
    int size = obj.getCapacity() - obj.getSize();
    for (int i = 0; i < size; i++)
    {
        obj.push_back(rand() % 100);
    }
}

template <typename T>
void randomFill(Vector<T> &obj, const int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        obj.push_back(rand() % 100);
}
