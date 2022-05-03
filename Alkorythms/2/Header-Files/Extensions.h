#pragma once

#include <iostream>
#include <ctime>
#include <vector>

class CustomFill
{
public:
    void operator()(int &_x)
    {
        _x = rand() % 20 - 10;
    }
};

class CustomPrint
{
public:
    void operator()(int &_x) const
    {
        std::cout << _x << " ";
    }
};

void FillTheArray(std::vector<int> &unsortedArray)
{
    std::for_each(unsortedArray.begin(), unsortedArray.end(), CustomFill());
}

void PrintTheArray(std::vector<int> numbersArray)
{
    std::for_each(numbersArray.begin(), numbersArray.end(), CustomPrint());
}