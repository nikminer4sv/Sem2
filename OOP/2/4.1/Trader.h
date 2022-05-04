#pragma once

#include "Person.h"

class Trader : public Person
{
private:
    unsigned int _itemId;

public:
    Trader() = default;

    Trader(const Position& position, char* Name) : Person(position, Name)
    {
        _itemId = rand() % 100 + 1;
    }

    ~Trader() = default;

    void Print(std::ostream& os) const override
    {
        os << "Trader: " << std::endl;
        Person::Print(os);
        os << "Item id: " << _itemId << std::endl;
    }

    void Add() override
    {
        Person::Add();
        _itemId = rand() % 100 + 1;
    }

    unsigned int GetItemId() { return _itemId; }
};