#include <iostream>
#include <cmath>

using namespace std;

void FuncA(double (*xz)(double min, double max, double p, double s, int& k_iter, char ch), double min, double max);
void FuncB(double (*xz)(double min, double max, double p, double s, int& k_iter, char ch), double min, double max, double s);
double Func(double x, double s, char ch);
double Find(double min, double max, double p, double s, int& k_iter, char ch);
void PrintTable(double* Results, double* ROF, int* Iters, int ArraySize, double smin);

int main()
{
    double minA = 0, maxA = 2;
    FuncA(Find, minA, maxA);
    double minB = -1.5, maxB = 1, smin = 0.9, smax = 1.1, ds = 0.05;
    cout << "\tS\t\tX\t\tF(x)\t\tk_iter\n\n";
    for (double s = smin; s <= smax + ds/2; s += ds)
    {
        FuncB(Find, minB, maxB, s);
    }
}

void FuncA(double (*xz)(double min, double max, double p, double s, int& k_iter, char ch), double min, double max)
{
    double const p = 1e-6;
    int k_iter = 0;
    double Result = xz(min, max, p, 0, k_iter, 'a');
    cout << "\tResult of A: " << Result << "\tAmount of iterations: " << k_iter << endl << endl;
}

double Func(double x, double s, char ch)
{
    if (ch == 'a')
        return (x + 1) * (x + 1) - 5;
    else if (ch == 'b')
        return x * x - exp(x) - 1.5 * s;
}

double Find(double min, double max, double p, double s, int& k_iter, char ch)
{
    while (abs(max - min) > p)
    {
        min = max - (max - min) * Func(max, s, ch) / (Func(max, s, ch) - Func(min, s, ch));
        max = min - (min - max) * Func(min, s, ch) / (Func(min, s, ch) - Func(max, s, ch));
        k_iter++;
    }

    return max;
}

void FuncB(double (*xz)(double min, double max, double p, double s, int& k_iter, char ch), double min, double max, double s)
{
    double const p = 1e-6;
    int k_iter = 0;
    double Result = xz(min, max, p, s, k_iter, 'b');

    cout << "\t" << s << "\t\t" << Result << "\t" << Func(Result, s, 'b') << "\t\t" << k_iter << "\n";
}
