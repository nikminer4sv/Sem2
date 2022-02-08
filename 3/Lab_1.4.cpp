#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define PI 3.14159265
#define EXP 2.718

void findRootDiscriminant() 
{
    cout << "The first function!" << endl;
    int min = 1, max = 3;
    double a = 1, b = -2, c = -2, d, x1, x2;

    d = b * b - 4 * a * c;
    if (d > 0)
    {
        x1 = ((-b) + sqrt(d)) / (2 * a);
        x2 = ((-b) - sqrt(d)) / (2 * a);
        if ((min < x1) && (x1 < max))
        {
            cout << "x1 = " << x1 << "\n";
        }
        if ((min < x2) && (x2 < max))
        {
            cout << "x2 = " << x2 << "\n";
        }
    }
    else if (d == 0) // Условие для дискриминанта равного нулю
    {
        x1 = -(b / (2 * a));
        if ((min < x1) && (x1 < max))
        {
            cout << "x1 = x2 = " << x1 << "\n";
        }
    }
    else // Условие при дискриминанте меньше нуля
        cout << "D < 0";
    cout << endl;
}

double F(double x, double s) {
    return pow(EXP, x - s) - sqrt(x + 1);
}

void PrintTable(double sMin, double sMax, double root, double function, int k_iter)
{
    cout << "\tS\t\tX\t\tF(x)\t\tk_iter\n";

    cout << setw(11) << sMin << setw(21) << root << setw(19) << function << setw(11) << k_iter << endl << endl;;
}

void findRootHalfDivision(double (*f)(double x, double s)) {

    cout << "The second function!" << endl << endl;

    const double eps = 1e-6;
    int k_iter = 0;
    double sMin = 0.3, sMax = 0.7;
    for (double s = sMin; s <= 0.7; s += 0.1)
    {
        double a = 0;
        double b = 2;
        double root;
        while (abs((b - a)) > eps) {

            root = (a + b) / 2;
            if (F(a, s) * F(root, s) < 0)
            {
                b = root;
            }
            else
                a = root;
            k_iter++;
           
        }
        
        PrintTable(s, sMax, root, F(root, s), k_iter);
    }
}


int main()
{   
    findRootDiscriminant();
    findRootHalfDivision(F);

    return 0;
}