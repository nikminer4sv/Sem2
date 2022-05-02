#pragma once

#include <fstream>
#include "Position.h"
#include "Object.h"

class Person : public Object
{
public:
    Person() = default;

    virtual ~Person()
    {
        delete[] _Name;
    }

    virtual void Print(std::ostream &stream) const override
    {
        stream << "X & Y: " << (*_Position).GetX() << " " << (*_Position).GetY() << std::endl;
        stream << "Name: " << _Name << std::endl;
    }

    virtual void Write(std::ofstream &of) const override
    {
        of << (*_Position).GetX() << std::endl
           << (*_Position).GetY() << std::endl
           << _Name << std::endl;
    }

    virtual void Add() override
    {
        int _X, _Y;
        std::cout << "Enter position of your person\n"
                  << "X:\t";
        std::cin >> _X;
        std::cout << "Y:\t";
        std::cin >> _Y;
        _Position = new Position(_X, _Y);
        std::cout << "Enter the name of your person\n";
        std::cin.get();
        _Name = new char[255];
        std::cin.getline(_Name, 255);
    }

    friend std::ostream &operator<<(std::ostream &os, const Person &obj)
    {
        obj.Print(os);

        return os;
    }

protected:
    Position *_Position;
    char *_Name = nullptr;
};
