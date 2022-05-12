#pragma once

#include <algorithm>
#include <ctime>
#include <cstring>
#include <iostream>

#define base 10

template <typename T>
class Long
{
public:
    Long() = default;

    Long(const size_t& capacity) {
        this->_capacity = capacity;
        this->_long = new T[this->_capacity];
    }

    Long(const Long<T>& obj) { copy(obj); }

    Long<T>& operator=(const Long<T>& obj) {
        if(this != &obj)
            copy(obj);
        
        return *this;
    }

    Long<T> operator+(const Long<T>& obj) {
        Long<T> temp(std::max(this->_capacity, obj._capacity));
       
        size_t i = 0, sum = 0, carry = 0;
        while (i < std::max(this->_size, obj._size)) {
            sum = carry;
            if (i < this->_size)
                sum += this->_long[i];
            if (i < obj._size)
                sum += obj._long[i];
            temp.push_back(sum % base);
            carry = sum / base;
            i++;
        }

        return temp;
    }

    Long<T> operator*(const Long<T>& obj) {
        Long<T> result(this->_capacity * obj._capacity);
        size_t i = 0;
        T sum = 0;
        while (i < this->_size) {
            Long<T> temp;
            sum = this->_long[i];
            if (sum == 0)
                sum = base;
            
            temp = smult(obj, sum);
            for (size_t j = 0; j < i; j++)
                temp.push_forward(0);
            
            result = result + temp;
            i++;
        }

        return result;
    }

    ~Long() {
       // std::cout << "Long::~Long() <-" << this << std::endl;
       this->_capacity = 0;
       this->_size = 0;
       delete[] this->_long;
    }

public:
    size_t GetCapacity() const { return this->_capacity; }

    size_t GetSize() const
    {
        return this->_size;
    }

    void setSize(const size_t& size_new)
    {
        if (size_new > this->_capacity)
        {
            resize(size_new);
        }
    }

    T& operator[](const size_t idx)
    {
        return at(idx);
        //return this->_long[idx];
    }

    T& operator[](const size_t idx) const
    {
        return at(idx);
        //return this->_long[idx];
    }

    void push_back(const T& value)
    {
        if (this->_size >= this->_capacity)
        {
            // std::cout << "Capacity -> " << this->_capacity << " Size -> " << this->_size << std::endl;
            resize(std::max(this->_capacity * 2, this->_size + 1));
        }

        this->_long[this->_size++] = value;
    }

    void push_forward(const T& value)
    {
        if (this->_size >= this->_capacity)
        {
            // std::cout << "Capacity -> " << this->_capacity << " Size -> " << this->_size << std::endl;
            resize(std::max(this->_capacity * 2, this->_size + 1));
        }

        T* tempVector = new T[this->_capacity];

        if (this->_long)
        {
            for (int i = 0; i < this->_capacity - 1; i++)
            {
                tempVector[i + 1] = this->_long[i];
            }
            std::memcpy(this->_long, tempVector, this->_capacity * sizeof(T));
            delete[] tempVector;
        }

        this->_size++;
        this->_long[0] = value;
    }

    void pop_back()
    {
        for (int i = 0; i < this->_capacity - this->_size; i++)
        {
            this->_long[this->_size + i - 1] = this->_long[this->_size + i];
        }

        this->_size--;
    }

    T& back()
    {
        return this->_long[this->_size - 1];
    }

private:
    T& at(const size_t idx) const
    {
        if (idx >= this->_capacity)
            throw std::invalid_argument("index is out of bounds");

        return this->_long[idx];
    }

    T& at(const size_t idx)
    {
        if (idx >= this->_capacity)
            throw std::invalid_argument("index is out of bounds");

        return this->_long[idx];
    }


    void copy(const Long& obj) {
        if (this->_long)
            delete[] this->_long;
        

        this->_size = obj._size;
        this->_capacity = obj._capacity;
        this->_long = new T[this->_capacity];

        std::memcpy(this->_long, obj._long, this->_size * sizeof(T));
    }

    void resize(const size_t& capacity_new) {
        // std::cout << "Long::resize() -> " << capacity_new << std::endl;

        T* tempVector = new T[capacity_new]{};

        if (this->_long) {
            std::memcpy(tempVector, this->_long, std::min(capacity_new, this->_capacity) * sizeof(T));
            delete[] this->_long;
        }

        this->_long = tempVector;
        this->_capacity = capacity_new;
    }

private:
    size_t _capacity = 0;
    size_t _size = 0;
    T* _long = nullptr;
};

template<typename T>
std::ostream& operator << (std::ostream& os, const Long<T>& vector)
{
    for (size_t i = 0; i < vector.GetSize(); i++) 
        os << vector[i] << " ";
    
    return os;
}

template <typename T>
Long<T> smult(Long<T> a, T b) {
    size_t carry = 0;

    for (size_t i = 0; i < a.GetSize() || carry; ++i) {

        if (i == a.GetSize())
            a.push_back(0);
        size_t cur = carry + a[i] * 1ll * b;
        a[i] = cur % base;
        carry = cur / base;
    }

    while (a.GetSize() > 1 && a.back() == 0)
        a.pop_back();

    return a;
}

template <typename T>
void Print(Long<T> array) {
    int i = 0;
    while (i < array.GetSize()) {
        std::cout << array[i] << std::endl;
        i++;
    }
}