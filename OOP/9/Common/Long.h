#pragma once

#include <algorithm>
#include <ctime>
#include <cstring>
#include <iostream>

#define base 100

template <typename T>
class Long
{
public:
    Long() {}

    Long(const size_t& capacity)
    {
        this->_Capacity = capacity;
        this->_Long = new T[this->_Capacity];
    }

    Long(const Long<T>& obj)
    {
        copy(obj);
    }

    Long<T>& operator=(const Long<T>& obj)
    {
        if(this != &obj){
            copy(obj);
        }
        return *this;
    }

    Long<T> operator+(const Long<T>& obj)
    {
        Long<T> temp(std::max(this->_Capacity, obj._Capacity));
       
        size_t i = 0, sum = 0, carry = 0;
        while (i < std::max(this->_Size, obj._Size))
        {
            sum = carry;
            if (i < this->_Size)
                sum += this->_Long[i];
            if (i < obj._Size)
                sum += obj._Long[i];

            temp.push_back(sum % base);
            carry = sum / base;
            i++;
        }

        return temp;
    }

    Long<T> operator*(const Long<T>& obj)
    {
        Long<T> result(this->_Capacity * obj._Capacity);
        size_t i = 0;
        T sum = 0;
        while (i < this->_Size)
        {
            Long<T> temp;
            sum = this->_Long[i];
            if (sum == 0)
            {
                sum = base;
            }
            temp = smult(obj, sum);
            for (size_t j = 0; j < i; j++)
            {
                temp.push_forward(0);
            }
            result = result + temp;
            i++;
        }

        return result;
    }

    ~Long()
    {
       // std::cout << "Long::~Long() <-" << this << std::endl;
       this->_Capacity = 0;
       this->_Size = 0;
       delete[] this->_Long;
    }

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
        //return this->_Long[idx];
    }

    T& operator[](const size_t idx) const
    {
        return at(idx);
        //return this->_Long[idx];
    }

    void push_back(const T& value)
    {
        if (this->_Size >= this->_Capacity)
        {
            // std::cout << "Capacity -> " << this->_Capacity << " Size -> " << this->_Size << std::endl;
            resize(std::max(this->_Capacity * 2, this->_Size + 1));
        }

        this->_Long[this->_Size++] = value;
    }

    void push_forward(const T& value)
    {
        if (this->_Size >= this->_Capacity)
        {
            // std::cout << "Capacity -> " << this->_Capacity << " Size -> " << this->_Size << std::endl;
            resize(std::max(this->_Capacity * 2, this->_Size + 1));
        }

        T* tempVector = new T[this->_Capacity];

        if (this->_Long)
        {
            for (int i = 0; i < this->_Capacity - 1; i++)
            {
                tempVector[i + 1] = this->_Long[i];
            }
            std::memcpy(this->_Long, tempVector, this->_Capacity * sizeof(T));
            delete[] tempVector;
        }

        this->_Size++;
        this->_Long[0] = value;
    }

    void pop_back()
    {
        for (int i = 0; i < this->_Capacity - this->_Size; i++)
        {
            this->_Long[this->_Size + i - 1] = this->_Long[this->_Size + i];
        }

        this->_Size--;
    }

    T& back()
    {
        return this->_Long[this->_Size - 1];
    }

private:
    T& at(const size_t idx) const
    {
        if (idx >= this->_Capacity)
            throw std::invalid_argument("index is out of bounds");

        return this->_Long[idx];
    }

    T& at(const size_t idx)
    {
        if (idx >= this->_Capacity)
            throw std::invalid_argument("index is out of bounds");

        return this->_Long[idx];
    }


    void copy(const Long& obj)
    {
        if (this->_Long)
        {
            delete[] this->_Long;
        }

        this->_Size = obj._Size;
        this->_Capacity = obj._Capacity;
        this->_Long = new T[this->_Capacity];

        std::memcpy(this->_Long, obj._Long, this->_Size * sizeof(T));
    }

    void resize(const size_t& capacity_new)
    {
        // std::cout << "Long::resize() -> " << capacity_new << std::endl;

        T* tempVector = new T[capacity_new]{};

        if (this->_Long)
        {
            std::memcpy(tempVector, this->_Long, std::min(capacity_new, this->_Capacity) * sizeof(T));
            delete[] this->_Long;
        }

        this->_Long = tempVector;
        this->_Capacity = capacity_new;
    }

private:
    size_t _Capacity = 0;
    size_t _Size = 0;
    T* _Long = nullptr;
};

template<typename T>
std::ostream& operator << (std::ostream& os, const Long<T>& vector)
{
    for (size_t i = 0; i < vector.getSize(); i++) {
        os << vector[i] << " ";
    }

    return os;
}

template <typename T>
Long<T> smult(Long<T> a, T b)
{
    size_t carry = 0;

    for (size_t i = 0; i < a.getSize() || carry; ++i)
    {

        if (i == a.getSize())
            a.push_back(0);
        size_t cur = carry + a[i] * 1ll * b;
        a[i] = cur % base;
        carry = cur / base;
    }

    while (a.getSize() > 1 && a.back() == 0)
        a.pop_back();

    return a;
}

template <typename T>
void Print(Long<T> array)
{
    int i = 0;
    while (i < array.getSize())
    {
        std::cout << array[i] << std::endl;
        i++;
    }
}