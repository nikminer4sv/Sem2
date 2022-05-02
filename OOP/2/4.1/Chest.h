#pragma once

#include "Object.h"

class Chest : public Object
{
private:
    unsigned int _coinAmount;

public:
    Chest() = default;

    ~Chest() = default;

    Chest(const Position& position, unsigned int _Width, unsigned int _Height, unsigned int _CoinAmount)
    {
        _Position = new Position(position);
        this->_Width = _Width;
        this->_Height = _Height;
        _coinAmount = _CoinAmount;
    }

    void Print(std::ostream& os) const override
    {
        os << "Chest: " << std::endl;
        Object::Print(os);
        os << "Amount of coins: " << _coinAmount << std::endl;
    }

    void Write(std::ofstream& of) const override
    {
        of << "Chest: " << std::endl;
        Object::Write(of);
        of << _coinAmount << std::endl;
    }

    void Add() override
    {
        Object::Add();
        std::cout << "Enter amount of coins\n";
        std::cin >> _coinAmount;
    }

    unsigned int GetAmountOfCoins() { return _coinAmount; }
};