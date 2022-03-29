#include "RationalFraction.h"
#include <iostream>

RationalFraction::RationalFraction(const int a, const int b)
{
    this->a = a;
    this->b = b;
}

void RationalFraction::reduction()
{
    if (this->a >= this->b)
    {
        for (int i = this->b; i >= 0; i--)
        {
            if (this->b % i == 0 && this->a % i == 0)
            {
                this->a /= i;
                this->b /= i;
                return;
            }  
        }  
    }
    else
    {
        for (int i = this->a; i >= 0; i--)
        {
            if (this->b % i == 0 && this->a % i == 0)
            {
                this->a /= i;
                this->b /= i;
                return;
            }  
        }  
    }
}

void RationalFraction::printFraction()
{
    std::cout << "Fraction - > " << this << ' ' << this->a << '/' << this->b << std::endl;
}

int RationalFraction::getA() { return this->a; }
int RationalFraction::getB() { return this->b; }


RationalFraction& RationalFraction::operator=(const RationalFraction &obj)
{

    this->a = obj.a;
    this->b = obj.b;

    return *this;
}

RationalFraction& RationalFraction::operator*(const RationalFraction &obj)
{
    RationalFraction *fract = new RationalFraction(this->a * obj.a, this->b * obj.b);

    return *fract;
}

RationalFraction& RationalFraction::operator+(const RationalFraction &obj)
{
    RationalFraction *fract;
    if (this->b == obj.b)
    {
        fract = new RationalFraction(this->a + obj.a, this->b);
    }
    else
    {
        fract = new RationalFraction(this->a * obj.b + obj.a * this->b, this->b * obj.b);
    }

    return *fract;
}

RationalFraction& RationalFraction::operator-(const RationalFraction &obj)
{
    RationalFraction *fract;
    if (this->b == obj.b)
    {
        fract = new RationalFraction(this->a - obj.a, this->b);
    }
    else
    {
        fract = new RationalFraction(this->a * obj.b - obj.a * this->b, this->b * obj.b);
    }

    return *fract;
}

RationalFraction& RationalFraction::operator/(const RationalFraction &obj)
{
    RationalFraction *fract = new RationalFraction(this->a * obj.b, this->b * obj.a);

    return *fract;
}

bool RationalFraction::operator< (const RationalFraction& obj)
{
    return (this->a/(double)this->b < obj.a/(double)obj.b);
}

bool RationalFraction::operator> (const RationalFraction& obj)
{
    return (this->a/(double)this->b > obj.a/(double)obj.b);
}

bool RationalFraction::operator<= (const RationalFraction& obj)
{
    return (this->a/(double)this->b <= obj.a/(double)obj.b);
}

bool RationalFraction::operator>= (const RationalFraction& obj)
{
    return (this->a/(double)this->b >= obj.a/(double)obj.b);
}

bool RationalFraction::operator== (const RationalFraction& obj)
{
    return (this->a/(double)this->b == obj.a/(double)obj.b);
}

std::ostream &operator<< (std::ostream &os, RationalFraction &obj)
{
    return os << obj.getA() << '/' << obj.getB();
}