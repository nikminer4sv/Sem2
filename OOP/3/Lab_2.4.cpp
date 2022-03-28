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

    RationalFraction& operator= (const RationalFraction& obj)
    {
        this->a = obj.a;
        this->b = obj.b;

        return *this;
    }

    RationalFraction& operator* (const RationalFraction& obj)
    {
        RationalFraction* fract = new RationalFraction(this->a * obj.a, this->b * obj.b);
       
        return *fract;
    }

    RationalFraction& operator+ (const RationalFraction& obj)
    {
        RationalFraction* fract;
        if (this->b == obj.b)
        {
            fract = new RationalFraction(this->a + obj.a, this->b);
        }
        else
        {
            fract = new RationalFraction(this->a * obj.b + obj.a * this->b, this->b * obj.b);
            fract->printFraction();
        }

        return *fract;
    }

};

int main()
{
    RationalFraction fract1(2, 4);
    RationalFraction fract2(1, 3);
    RationalFraction fract3;
    fract3 = fract1 * fract2;
    fract3.printFraction();
    fract1.printFraction();
    fract2.printFraction();
    fract3 = fract1 + fract2 + fract1;
    fract3.printFraction();

    return 0;
}