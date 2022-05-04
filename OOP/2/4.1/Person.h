#pragma once

#include <fstream>
#include "Position.h"
#include "Object.h"

class Person : public Object
{
public:
    Person() = default;

    Person(const Position& pos, char* name) : Object(pos)
    {
        strcpy(_Name, name);
    }

    virtual ~Person()
    {
        delete[] _Name;
    }

    virtual void Print(std::ostream &stream) const override
    {
        Object::Print(stream);
        stream << "Name: " << _Name << std::endl;
    }

    virtual void Add() override
    {
        Object::Add();
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
    char *_Name = new char[255]{};
};
