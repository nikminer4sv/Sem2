#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define PI 3.14159265
#define EXP 2.718
//
void findRootDiscriminant() 
{
    cout << "Discriminant of 'a' function!" << endl;
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

double bFunction(double x, double s) {
    return pow(EXP, x - s) - sqrt(x + 1);
}
double aFunction(double x) {
    return pow(x - 1, 2) - 3;
}

void PrintTable(double sMin, double root, double function, int k_iter)
{
    cout << "\tS\t\tX\t\tF(x)\t\tk_iter\n";

    cout << setw(11) << sMin << setw(21) << root << setw(19) << function << setw(11) << k_iter << endl << endl;
}

void PrintTable( double root, double function, int k_iter)
{
    cout << "\tS\t\tX\t\tF(x)\t\tk_iter\n";

    cout << setw(9) << '-' << setw(16) << root << setw(17) << function << setw(16) << k_iter << endl << endl;
}

void findRootHalfDivision(double (*bFunction)(double x, double s)) {

    const double eps = 1e-6;
    int k_iter = 0;
    double sMin = 0.3, sMax = 0.7;
    
    cout << "The 'b' function!" << endl << endl;

    for (double s = sMin; s <= 0.7; s += 0.1)
    {
        double a = 0;
        double b = 2;
        double root;
        while (abs((b - a)) > eps) {

            root = (a + b) / 2;
            if (bFunction(a, s) * bFunction(root, s) < 0)
            {
                b = root;
            }
            else
                a = root;
            k_iter++;
        }
        
        PrintTable(s, root, bFunction(root, s), k_iter);
    }
}
void findRootHalfDivision(double (*aFunction)(double x)) 
{
    const double eps = 1e-6;
    int k_iter = 0;

    cout << "The 'a' function!" << endl << endl;

    double a = 1;
    double b = 4;
    double root;
    while (abs((b - a)) > eps) {

        root = (a + b) / 2;
        if (aFunction(a) * aFunction(root) < 0)
        {
            b = root;
        }
        else
            a = root;
        k_iter++;
    }

    PrintTable(root, aFunction(root), k_iter);
}


int main()
{   
 
    findRootHalfDivision(bFunction);
    findRootDiscriminant();
    findRootHalfDivision(aFunction);

    return 0;
}