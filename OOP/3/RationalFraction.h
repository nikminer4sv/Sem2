#pragma once
#include <iostream>
class RationalFraction
{
private:
    int a = 0;
    int b = 0;

public:
    RationalFraction() = default;

    RationalFraction(const int a, const int b);

    void reduction();

    void printFraction();

    int getA();
    int getB();

    RationalFraction &operator=(const RationalFraction &obj);

    RationalFraction &operator*(const RationalFraction &obj);

    RationalFraction &operator+(const RationalFraction &obj);
    
    RationalFraction &operator-(const RationalFraction &obj);

    RationalFraction &operator/(const RationalFraction &obj);

    bool operator< (const RationalFraction& obj);

    bool operator> (const RationalFraction& obj);

    bool operator<= (const RationalFraction& obj);

    bool operator>= (const RationalFraction& obj);

    bool operator== (const RationalFraction& obj);
};

std::ostream& operator<< (std::ostream &os, RationalFraction &obj);
