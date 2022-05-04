#pragma once

#include "PhysicalObject.h"

class Chest : public PhysicalObject
{
private:
    unsigned int _coinAmount;

public:
    Chest() = default;

    ~Chest() override = default;

    Chest(const Position& position, unsigned int _Width, unsigned int _Height, unsigned int _CoinAmount) : PhysicalObject(position, _Width, _Height)
    {
        _coinAmount = _CoinAmount;
    }

    void Print(std::ostream& os) const override
    {
        os << "Chest: " << std::endl;
        PhysicalObject::Print(os);
        os << "Amount of coins: " << _coinAmount << std::endl;
    }

    void Add() override
    {
        PhysicalObject::Add();
        std::cout << "Enter amount of coins\n";
        std::cin >> _coinAmount;
    }

    unsigned int GetAmountOfCoins() const { return _coinAmount; }
};