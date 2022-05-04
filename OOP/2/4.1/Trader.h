#pragma once

#include "Person.h"

class Trader : public Person
{
private:
    unsigned int _itemId;

public:
    Trader() = default;

    ~Trader() = default;

    Trader(const Position& position, char* Name)
    {
        _Position = new Position(position);
        this->_Name = Name;
        _itemId = rand() % 100 + 1;
    }

    void Print(std::ostream& os) const override
    {
        os << "Person: " << std::endl;
        Person::Print(os);
        os << "Item id: " << _itemId << std::endl;
    }

    void Write(std::ofstream& of) const override
    {
        of << "Person: " << std::endl;
        Person::Write(of);
        of << _itemId << std::endl;
    }

    void Add() override
    {
        Person::Add();
        _itemId = rand() % 100 + 1;
    }

    unsigned int GetItemId() { return _itemId; }
};