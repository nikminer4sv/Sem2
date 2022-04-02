#pragma once

#include <algorithm>
#include <ctime>
#include <cstring>
#include <iostream>

#define base 1000000000

template <typename T>
class Vector
{
public:
    Vector() {}

    Vector(const size_t& capacity)
    {
        this->_Capacity = capacity;
        this->_Vector = new T[this->_Capacity];
    }

    Vector(const Vector<T>& obj)
    {
        copy(obj);
    }

    Vector<T>& operator=(const Vector<T>& obj)
    {
        copy(obj);
        return *this;
    }

    Vector<T>& operator+(const Vector<T>& obj)
    {
        Vector<T> temp(std::max(this->_Capacity, obj._Capacity));
        size_t i = 0, sum = 0, carry = 0;
        while (i < std::max(this->_Size, obj._Size))
        {
            sum = carry;
            if (i < this->_Size)
                sum += this->_Vector[i];
            if (i < obj._Size)
                sum += obj._Vector[i];
            
            temp.push_back(sum % base);
            carry = sum / base;
            i++;
        }  

        return temp;
    }

    // ~Vector()
    // {
    //    std::cout << "Vector::~Vector() <-" << this << std::endl;
    //    this->_Capacity = 0;
    //    this->_Size = 0;
    //    delete[] this->_Vector;
    // }

public:
    size_t getCapacity() const
    {
        return this->_Capacity;
    }

    size_t getSize() const
    {
        return this->_Size;
    }

    void setSize(const size_t& size_new)
    {
        if (size_new > this->_Capacity)
        {
            resize(size_new);
        }
    }

    T& operator[](const size_t idx)
    {
        return at(idx);
        //return this->_Vector[idx];
    }

    T& operator[](const size_t idx) const
    {
        return at(idx);
        //return this->_Vector[idx];
    }

    void push_back(const T& value)
    {
        if (this->_Size >= this->_Capacity)
        {
            // std::cout << "Capacity -> " << this->_Capacity << " Size -> " << this->_Size << std::endl;
            resize(std::max(this->_Capacity * 2, this->_Size + 1));
        }

        this->_Vector[this->_Size++] = value;
    }

    void push_forward(const T& value)
    {
        if (this->_Size >= this->_Capacity)
        {
            // std::cout << "Capacity -> " << this->_Capacity << " Size -> " << this->_Size << std::endl;
            resize(std::max(this->_Capacity * 2, this->_Size + 1));
        }

        T* tempVector = new T[this->_Capacity];

        if (this->_Vector)
        {
            for (int i = 0; i < this->_Capacity - 1; i++)
            {
                tempVector[i + 1] = this->_Vector[i];
            }
            std::memcpy(this->_Vector, tempVector, this->_Capacity * sizeof(T));
            delete[] tempVector;
        }

        this->_Size++;
        this->_Vector[0] = value;
    }

    void pop_back()
    {
        for (int i = 0; i < this->_Capacity - this->_Size; i++)
        {
            this->_Vector[this->_Size + i - 1] = this->_Vector[this->_Size + i];
        }

        this->_Size--;
    }

    T& back()
    {
        return this->_Vector[this->_Size - 1];
    }

private:
    T& at(const size_t idx) const
    {
        // if (idx >= this->_Size)
        //     throw std::invalid_argument("index is out of bounds");

        return this->_Vector[idx];
    }

    T& at(const size_t idx)
    {
        // if (idx >= this->_Size)
        //     throw std::invalid_argument("index is out of bounds");

        return this->_Vector[idx];
    }

    
    void copy(const Vector& obj)
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

    void resize(const size_t& capacity_new)
    {
        // std::cout << "Vector::resize() -> " << capacity_new << std::endl;

        T* tempVector = new T[capacity_new]{};

        if (this->_Vector)
        {
            std::memcpy(tempVector, this->_Vector, std::min(capacity_new, this->_Capacity) * sizeof(T));
            delete[] this->_Vector;
        }

        this->_Vector = tempVector;
        this->_Capacity = capacity_new;
    }

private:
    size_t _Capacity = 0;
    size_t _Size = 0;
    T* _Vector = nullptr;
};

template <typename T>
void randomFill(Vector<T>& obj)
{
    srand(time(NULL));
    int size = obj.getCapacity() - obj.getSize();
    for (int i = 0; i < size; i++)
    {
        obj.push_back(rand() % 100);
    }
}

template <typename T>
void randomFill(Vector<T>& obj, const int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        obj.push_back(rand() % 100);
}

template<typename T>
std::ostream& operator << (std::ostream& os, const Vector<T>& vector)
{
    for (size_t i = 0; i < vector.getSize(); i++) {
        os << vector[i] << " ";
    }

    return os;
}