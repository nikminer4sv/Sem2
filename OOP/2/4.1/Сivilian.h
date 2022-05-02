#pragma once

#include "Person.h"

class Civilian : public Person
{
public:
    Civilian() = default;

    ~Civilian() = default;

    Civilian(const Position& position, char* Name)
    {
        _Position = new Position(position);
        this->_Name = Name;
    }

    void Print(std::ostream& os) const override
    {
        os << "Civilian: " << std::endl;
        Person::Print(os);
        os << std::endl;
    }

    void Write(std::ofstream& of) const override
    {
        of << "Civilian: " << std::endl;
        Person::Write(of);
    }

    void Add() override
    {
        Person::Add();
    }
};