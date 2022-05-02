#pragma once

#include <iostream>

class Position
{
private:
    int _X = 0;
    int _Y = 0;

public:
    Position() = default;

    Position(size_t x, size_t y)
    {
        _X = x;
        _Y = y;
    }

    Position(const Position& temp)
    {
        _X = temp.GetX();
        _Y = temp.GetY();
    }

    ~Position() = default;

    Position& operator= (const Position& temp)
    {
        _X = temp.GetX();
        _Y = temp.GetY();

        return *this;
    }

    void SetX(size_t x) { _X = x; }
    void SetY(size_t y) { _Y = y; }

    [[nodiscard]] size_t GetX() const { return _X; }
    [[nodiscard]] size_t GetY() const { return _Y; }
};
