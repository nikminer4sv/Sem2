#include <iostream>
#include "RationalFraction.h"
using namespace std;

int main()
{
    RationalFraction fract1(2, 4);
    RationalFraction fract2(1, 3);
    RationalFraction fract3 = fract1 * fract2;
    fract3.printFraction();
    
    return 0;
}

