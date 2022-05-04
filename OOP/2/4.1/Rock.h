#pragma once

#include "PhysicalObject.h"

class Rock : public PhysicalObject
{
private:
    unsigned int _imageId;

public:
    Rock() = default;

    ~Rock() = default;

    Rock(const Position& position, unsigned int _Width, unsigned int _Height, unsigned int _ImageId)
    {
        _Position = new Position(position);
        this->_Width = _Width;
        this->_Height = _Height;
        _imageId = _ImageId;
    }

    void Print(std::ostream& os) const override
    {
        os << "Rock: " << std::endl;
        Object::Print(os);
        os << "Image Id: " << _imageId << std::endl;
    }

    void Write(std::ofstream& of) const override
    {
        of << "Rock: " << std::endl;
        Object::Write(of);
        of << _imageId << std::endl;
    }

    void Add() override
    {
        Object::Add();
        std::cout << "Enter Image Id\n";
        std::cin >> _imageId;
    }

    unsigned int GetImageid() { return _imageId; }
};