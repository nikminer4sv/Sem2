#pragma once

#include <fstream>
#include "Position.h"

class Object
{
public:
    Object() = default;
    virtual ~Object() = default;

    Object(const Position& pos)
    {
        _Position = pos;
    }

    virtual void Print(std::ostream& stream) const
    {
        stream << "X & Y: " << (_Position).GetX() << " " << (_Position).GetY() << std::endl;
    }

    virtual void Add()
    {
        int _X, _Y;
        std::cout << "Enter position of your object\n"
             << "X:\t";
        std::cin >> _X;
        std::cout << "Y:\t";
        std::cin >> _Y;
        _Position = Position(_X, _Y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Object& obj)
    {
        obj.Print(os);
        return os;
    }

protected:
    Position _Position;
};
