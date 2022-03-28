#include <iostream>
using namespace std;

class RationalFraction
{
private:
    int a = NULL;
    int b = NULL;

public:
    RationalFraction() = default;

    RationalFraction(const int a, const int b)
    {
        this->a = a;
        this->b = b;
    }

    void printFraction()
    {
        cout << this->a << '/' << this->b << endl;
    }

    RationalFraction &operator= (const RationalFraction &obj)
    {
        this->a = obj.a;
        this->b = obj.b;

        return *this;
    }

    RationalFraction &operator* (const RationalFraction &obj)
    {
        this->a *= obj.a;
        this->b *= obj.b;
        return *this;
    }

    RationalFraction &operator+ (const RationalFraction &obj)
    {
        if (this->b = obj.b)
        {
            this->a += obj.a;
        }
        else
        {
            this->b *= obj.b;
            this->a = this->a * obj.b + obj.a * obj.b;
        }
        
        return *this;
    }

};

int main()
{
    RationalFraction fract1(2, 4);
    RationalFraction fract2(1, 3);
    RationalFraction fract3;
    fract3 = fract1 * fract2;
    fract3.printFraction();
    fract3 = fract1 + fract2;
    fract3.printFraction();

    return 0;
}