#include <iostream>
#include <cmath>
#include "For_1.5.cpp"

using namespace std;

int main()
{
    double b = 1.234, s = 0, ds = 0.2, t = 1, dt = 1;
    cout << "\tS\t\tt\t\tInt\t\tk_iter\n\n";
    for (double a = s; a < 1 + ds/2; a += ds)
    {
        for (int temp = t; temp <= 4; temp += dt)
        {
            Func(Function, a, b, temp);
        }
    }
}
