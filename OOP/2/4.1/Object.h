#pragma once

#include <fstream>
#include "Position.h"

class Object
{
public:
    Object() = default;

    virtual ~Object() = default;

    virtual void Print(std::ostream& stream) const
    {
        stream << "X & Y: " << (*_Position).GetX() << " " << (*_Position).GetY() << std::endl;
        stream << "Size: " << _Width << std::endl
        << _Height << std::endl;
    }

    virtual void Write(std::ofstream& of) const
    {
        of << (*_Position).GetX() << std::endl
           << (*_Position).GetY() << std::endl
           << _Width << _Height
           << std::endl;
    }

    virtual void Add()
    {
        int _X, _Y;
        std::cout << "Enter position of your object\n"
             << "X:\t";
        std::cin >> _X;
        std::cout << "Y:\t";
        std::cin >> _Y;
        _Position = new Position(_X, _Y);
        std::cout << "Enter the width of your object\n";
        std::cin >> _Width;
        std::cout << "Enter the height of your object\n";
        std::cin >> _Height;
    }

    friend std::ostream& operator<<(std::ostream& os, const Object& obj)
    {
        obj.Print(os);

        return os;
    }

protected:
    Position* _Position;
    unsigned int _Height;
    unsigned int _Width;
};
