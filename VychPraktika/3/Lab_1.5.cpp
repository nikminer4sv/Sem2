#include <iostream>
#include <iomanip>
#include "Methods.h"
using namespace std;

int main() {

    setlocale(LC_ALL, "RU");
    int a, b;

    int sMax = 2;
    int tMax = 5;

    
    double area1;
    int n = 1; //начальное число шагов

    cout << "¬ведите левую границу интегрировани€ a = ";
    cin >> a;
    cout << "\n¬ведите правую границу интегрировани€ b = ";
    cin >> b;
 
    int k_iter = 0;
    for (double s = 0; s <= sMax; s += 0.5)
    {
        for (double t = 2; t <= tMax; t++)
        {
            k_iter = 0;
            area1 = Integral(a, b, s, t, k_iter);

            cout << "\tS\t\tT\t\tIntegral\t\tk_iter\n";
            cout << setw(9) << s << setw(16) << t << setw(22) << area1 << setw(18) << k_iter << endl << endl;
        }
    }
    
}