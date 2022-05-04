#pragma once

#include "PhysicalObject.h"

class Rock : public PhysicalObject
{
private:
    unsigned int _imageId;

public:
    Rock() = default;

    ~Rock() override = default;

    Rock(const Position& position, unsigned int _Width, unsigned int _Height, unsigned int _ImageId) : PhysicalObject(position, _Width, _Height)
    {
        _imageId = _ImageId;
    }

    void Print(std::ostream& os) const override
    {
        os << "Rock: " << std::endl;
        PhysicalObject::Print(os);
        os << "Image Id: " << _imageId << std::endl;
    }

    void Add() override
    {
        PhysicalObject::Add();
        std::cout << "Enter Image Id\n";
        std::cin >> _imageId;
    }

    unsigned int GetImageid() const { return _imageId; }
};