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

    RationalFraction(const RationalFraction& obj)
    {
        this->a = obj.a;
        this->b = obj.b;
    }
    RationalFraction &operator=(const RationalFraction &obj);

    //TODO: operator >>(istream)

    void reduction();

    [[nodiscard]] int getA() const; //TODO:make const method, make nodiscard
    [[nodiscard]] int getB() const; //TODO:make const method, make nodiscard

    RationalFraction operator*(const RationalFraction &obj) const; //TODO: make const

    RationalFraction operator+(const RationalFraction &obj) const; //TODO: make const
    
    RationalFraction operator-(const RationalFraction &obj) const; //TODO: make const

    RationalFraction operator/(const RationalFraction &obj) const; //TODO: make const

    [[nodiscard]]bool operator< (const RationalFraction& obj) const;  //TODO: make const, make nodiscard

    [[nodiscard]]bool operator> (const RationalFraction& obj) const; //TODO: make const, make nodiscard

    [[nodiscard]]bool operator<= (const RationalFraction& obj) const; //TODO: make const, make nodiscard

    [[nodiscard]]bool operator>= (const RationalFraction& obj) const; //TODO: make const, make nodiscard

    [[nodiscard]]bool operator== (const RationalFraction& obj) const; //TODO: make const, make nodiscard
    
    friend std::istream &operator>> (std::istream &is, RationalFraction &obj);
    friend std::ostream &operator<< (std::ostream &os, const RationalFraction &obj);
};

RationalFraction::RationalFraction(const int a, const int b)
{
    this->a = a;
    this->b = b;
}

void RationalFraction::reduction()
{
    std::cout << "Reduction!" << std::endl;
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

int RationalFraction::getA() const { return this->a; }
int RationalFraction::getB() const { return this->b; }


RationalFraction& RationalFraction::operator=(const RationalFraction &obj)
{
    this->a = obj.a;
    this->b = obj.b;

    return *this;
}

RationalFraction RationalFraction::operator* (const RationalFraction &obj) const
{
    return RationalFraction(this->a * obj.a, this->b * obj.b);
}

RationalFraction RationalFraction::operator+(const RationalFraction &obj) const
{
    if (this->b == obj.b)
    {
        return RationalFraction(this->a + obj.a, this->b);
    }
    else
    {
        return RationalFraction(this->a * obj.b + obj.a * this->b, this->b * obj.b);
    }

}

RationalFraction RationalFraction::operator-(const RationalFraction &obj) const
{
    if (this->b == obj.b)
    {
        return RationalFraction(this->a - obj.a, this->b);
    }
    else
    {
        return RationalFraction(this->a * obj.b - obj.a * this->b, this->b * obj.b);
    }
}

RationalFraction RationalFraction::operator/(const RationalFraction &obj) const
{
    return RationalFraction(this->a * obj.b, this->b * obj.a);
}

bool RationalFraction::operator< (const RationalFraction& obj) const
{
    return (this->a/(double)this->b < obj.a/(double)obj.b);
}

bool RationalFraction::operator> (const RationalFraction& obj) const
{
    return (this->a/(double)this->b > obj.a/(double)obj.b);
}

bool RationalFraction::operator<= (const RationalFraction& obj) const
{
    return (this->a/(double)this->b <= obj.a/(double)obj.b);
}

bool RationalFraction::operator>= (const RationalFraction& obj) const
{
    return (this->a/(double)this->b >= obj.a/(double)obj.b);
}

bool RationalFraction::operator== (const RationalFraction& obj) const
{
    return (this->a/(double)this->b == obj.a/(double)obj.b);
}

std::ostream &operator<< (std::ostream &os, const RationalFraction &obj)
{
    return os << obj.getA() << '/' << obj.getB();
}

std::istream &operator>> (std::istream &is, RationalFraction &obj)
{
    std::cout << "Enter the A and B (A/B): ";
    is >> obj.a >> obj.b;
    return is;
}