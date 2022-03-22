#ifndef VICTOR
#define VICTOR

#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
class Vector
{
private:
    int _Size; 
    int _Count; 
    T* _Vector;

public:
    Vector()
    {
        this->_Size = 0;
        this->_Count = 0;
        this->_Vector = new T [this->_Size];
    }

    Vector(const int Size)
    {
        this->_Size = Size;
        this->_Count = 0;
        this->_Vector = new T [this->_Size];
    }

    Vector(const Vector& obj)
    {
        this->_Size = obj._Size;
        this->_Count = obj._Count;
        this->_Vector = new T [this->_Size];

        for (int i = 0; i < this->_Size; i++)
            this->_Vector[i] = obj._Vector[i];
    }

    ~Vector()
    {
        cout << "!!!!!!!!!!!GARBAGE!!!!!!!!!!!!!" << endl;
        garbageCollector();
    }

public:
    Vector& operator = (const Vector& obj)
    {
        delete[] this->_Vector;

        this->_Count = obj._Count;
        this->_Size = obj._Size;
        this->_Vector = new T [this->_Size];

        for (int i = 0; i < this->_Size; i++)
            this->_Vector[i] = obj._Vector[i];

        return *this;
    }

    int getAmount() const
    {
        return this->_Count;
    }

    int getSize() const
    {
        return this->_Size;
    }

    void push_back(const T value)
    {

        if (this->_Count >= this->_Size)
        {
            this->_Count++;
            this->_Size = _Count;

            T *_tempVector = new T [this->_Size];

            for (int i = 0; i < this->_Size - 1; i++)
                _tempVector[i] = _Vector[i];
            _tempVector[this->_Size - 1] = value;

            delete[] this->_Vector;
            
            this->_Vector = new T [this->_Size];

            for (int i = 0; i < this->_Size; i++)
                this->_Vector[i] = _tempVector[i];
            
            delete[] _tempVector;  
            return;
        }
        
        this->_Vector[this->_Count++] = value;
    }

    T& operator[] (const int idx)
    {
        try
        {
            if (idx >= this->_Size || idx < 0)
                throw 0;

            return this->_Vector[idx];
        }
        catch(const int e)
        {
            if (e == 0)
                cout << "Error! Going aboard 2!" << endl;
        }  
    }

private:
    void garbageCollector()
    {
        this->_Size = 0;
        delete[] this->_Vector;
    }
};

template<typename T>
void randomFill(Vector<T>& obj)
{
    srand(time(NULL));
    int size = obj.getSize() - obj.getAmount();
    for (int i = 0; i < size; i++)
    {
        obj.push_back(rand() % 100);
    }    
}

template<typename T>
void randomFill(Vector<T>& obj, const int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        obj.push_back(rand() % 100); 
}


#endif