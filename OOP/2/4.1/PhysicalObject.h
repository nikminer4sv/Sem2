#pragma once

#pragma once

#include <fstream>
#include "Object.h"

class PhysicalObject : public Object
{
public:
    PhysicalObject() = default;

    PhysicalObject(const Position& pos, int w, int h): Object(pos)
    {
        height = h;
        width = w;
    }

    ~PhysicalObject() override = default;

    void Print(std::ostream& stream) const override
    {
        Object::Print(stream);
        stream << width << std::endl
               << height << std::endl;
    }

    void Add() override
    {
        Object::Add();
        std::cout << "Enter the width of your object\n";
        std::cin >> width;
        std::cout << "Enter the height of your object\n";
        std::cin >> height;
    }

    friend std::ostream& operator<<(std::ostream& os, const PhysicalObject& obj)
    {
        obj.Print(os);

        return os;
    }

protected:
    unsigned int height;
    unsigned int width;
};
