#pragma once

#include "Person.h"

class Civilian : public Person
{
public:
    Civilian() = default;

    Civilian(const Position& position, char* Name) : Person(position, Name){}

    ~Civilian() = default;

    void Print(std::ostream& os) const override
    {
        os << "Civilian: " << std::endl;
        Person::Print(os);
    }

    void Add() override
    {
        Person::Add();
    }
};