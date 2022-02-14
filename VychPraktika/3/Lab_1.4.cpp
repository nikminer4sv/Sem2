#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double aFunction(double x) {
    return pow(x - 1, 2) - 3;
}

double bFunction(double x, double s) {
    return exp(x - s) - sqrt(x + 1);
}

void PrintTable(double sMin, double root, double function, int k_iter)
{
    cout << "\tS\t\tX\t\tF(x)\t\tk_iter\n";

    cout << setw(11) << sMin << setw(21) << root << setw(19) << function << setw(11) << k_iter << endl;
}


void findRootHalfDivision(double (*bFunction)(double x, double s), double a, double b, double sMin, const double sMax, const double eps) {

    int k_iter = 0;
   
    double root;
    while (abs((b - a)) > eps) {

        root = (a + b) / 2;
        if (bFunction(a, sMin) * bFunction(root, sMin) < 0)
        {
            b = root;
        }
        else
            a = root;
        k_iter++;
    }
        
    PrintTable(sMin, root, bFunction(root, sMin), k_iter);
   
}

void findRootHalfDivision(double (*aFunction)(double x), const double eps, double a, double b) 
{

    int k_iter = 0;

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

    PrintTable(0, root, aFunction(root), k_iter);
}


int main()
{   
    double sMin = 0.3, sMax = 0.7;
    const double eps = 1e-6;
    double a = 0;
    double b = 2;

    cout << "\tThis 'b' function!" << endl;

    for (; sMin <= sMax; sMin += 0.1)
    {
        findRootHalfDivision(bFunction, a, b, sMin, sMax, eps);
    }
    
    cout << endl;
    a = 1;
    b = 4;

    cout << "\tThis 'a' function!" << endl;
    findRootHalfDivision(aFunction, eps, a, b);

    return 0;
}