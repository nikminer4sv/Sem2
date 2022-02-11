#include <iostream>
#include <cmath>

using namespace std;

void FuncA(double (*xz)(double min, double max, double p, double s, int& k_iter, char ch));
void FuncB(double (*xz)(double min, double max, double p, double s, int& k_iter, char ch));
double Func(double x, double s, char ch);
double Find(double min, double max, double p, double s, int& k_iter, char ch);
void PrintTable(double* Results, double* ROF, int* Iters, int ArraySize, double smin);

int main()
{
    FuncA(Find);
    FuncB(Find);
}

void FuncA(double (*xz)(double min, double max, double p, double s, int& k_iter, char ch))
{
    double const p = 1e-6;
    double min = 0, max = 2;
    int k_iter = 0;
    double Result = xz(min, max, p, 0, k_iter, 'a');
    cout << "Result of A: " << Result << "\tAmount of iterations: " << k_iter << endl << endl;
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

void FuncB(double (*xz)(double min, double max, double p, double s, int& k_iter, char ch)) 
{
    double const p = 1e-6;
    double min = -1.5, max = 1, smin = 0.9, smax = 1.1, ds = 0.05;
    int ArraySize = int((smax - smin)/ds + 1), Count = 0;
    double Results[ArraySize], ROF[ArraySize]; 
    int Iters[ArraySize];

    for (; smin <= smax + ds/2; smin += ds)
    {
        int k_iter = 0;
        double s = smin, Result = xz(min, max, p, s, k_iter, 'b');
        Results[Count] = Result;
        Iters[Count] = k_iter;
        ROF[Count++] = Func(Result, s, 'b');
    }

    PrintTable(Results, ROF, Iters, ArraySize, smin);
}

void PrintTable(double* Results, double* ROF, int* Iters, int ArraySize, double smin)
{
    cout << "\tS\t\tX\t\tF(x)\t\tk_iter\n\n";
    smin = 0.9;
    for (int i = 0; i < ArraySize; smin += 0.05, i++)
    {
        cout << "\t" << smin << "\t\t" << Results[i] << "\t" << ROF[i] << "\t\t" << Iters[i] << "\n";
    }
}