#pragma once

#include "Person.h"

class Player : public Person
{
private:
    char* _Color = new char[255];

public:
    Player() = default;

    ~Player() = default;

    Player(const Position& position, char* Name, char* color)
    {
        _Position = new Position(position);
        this->_Name = Name;
        _Color = color;
    }

    void Print(std::ostream& os) const override
    {
        os << "Player: " << std::endl;
        Person::Print(os);
        os << "Color: " << _Color << std::endl;
    }

    void Write(std::ofstream& of) const override
    {
        of << "Player: " << std::endl;
        Person::Write(of);
        of << _Color << std::endl;
    }

    void Add() override
    {
        Person::Add();
        std::cout << "Enter the color:\n";
        std::cin.getline(_Color, 255);
    }

    char* GetTheColor() { return _Color; }
};