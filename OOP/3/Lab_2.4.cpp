#include <iostream>
#include "RationalFraction.h"
using namespace std;

int main()
{
    RationalFraction fract1(1, 4);
    RationalFraction fract2(2, 4);

    RationalFraction fract3;
    cin >> fract3;
    cout << "Fract3 = " << fract3 << endl;

    cout << "Fract3 = Fract1 + Fract2" << endl;
    fract3 = fract1 + fract2;

    cout <<"Fract1 =" << fract1 << endl;
    cout <<"Fract2 =" << fract2 << endl;
    cout <<"Fract3 =" << fract3 << endl << endl;

    fract3.reduction();
    cout << "Fract3 = " << fract3 << endl << endl;

    cout << "Fract3 = Fract1 * Fract2" << endl;
    fract3 = fract1 * fract2;
    cout << "Fract3 = " << fract3 << endl;
    fract3.reduction();
    cout << "Fract3 = " << fract3 << endl << endl;

    cout << "Fract3 = Fract1 - Fract2" << endl;
    fract3 = fract1 - fract2;
    cout << "Fract3 = " << fract3 << endl;
    fract3.reduction();
    cout << "Fract3 = " << fract3 << endl << endl;

    cout << "Fract3 = Fract1 / Fract2" << endl;
    fract3 = fract1 / fract2;
    cout << "Fract3 = " << fract3 << endl;
    fract3.reduction();
    cout << "Fract3 = " << fract3 << endl << endl;;

    cout << "Fract1 == Fract3" << endl;
    cout << (fract1 == fract3) << endl << endl;

    cout << "Fract1 = " << fract1 << endl;
    fract1.reduction();
    cout << "Fract1 = " << fract1 << endl << endl;

    cout << "Fract2 = " << fract2 << endl;
    fract2.reduction();
    cout << "Fract2 = " << fract2 << endl << endl;

    cout << "Fract3 = " << fract3 << endl;
    fract3.reduction();
    cout << "Fract3 = " << fract3 << endl << endl;
    
    return 0;
}

