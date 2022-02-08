#include <iostream>
#include <cmath>

using namespace std;

void FuncA();
void FuncB();
double Func(double x, double s);
double Find(double min, double max, double p, int& k_iter);
void PrintTable(double* Results, double* ROF, int* Iters, int ArraySize, double smin);

int main()
{
    FuncA();
    FuncB();
}

void FuncA()
{
    int min = 0, max = 2;
    double a = 1, b = 2, c = -3, d, x1, x2; 
    
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
    if (d == 0) // Условие для дискриминанта равного нулю
    {
        x1 = -(b / (2 * a));
        if ((min < x1) && (x1 < max))
        {
            cout << "x1 = x2 = " << x1 << "\n";
        }
    }
    if (d < 0) // Условие при дискриминанте меньше нуля
        cout << "D < 0, Действительных корней уравнения не существует";
}

double Func(double x, double s)
{
    return x * x - exp(x) - 1.5 * s;
}

double Find(double min, double max, double p, double s, int& k_iter)
{
    while (abs(max - min) > p)
    {
        min = max - (max - min) * Func(max, s) / (Func(max, s) - Func(min, s));
        max = min - (min - max) * Func(min, s) / (Func(min, s) - Func(max, s));
        k_iter++;
    }

    return max;
}

void FuncB() 
{
    double const p = 1e-6;
    double min = -1.5, max = 1, smin = 0.9, smax = 1.1, ds = 0.05;
    int ArraySize = int((smax - smin)/ds + 1), Count = 0;
    double Results[ArraySize], ROF[ArraySize]; 
    int Iters[ArraySize];

    for (; smin <= smax + ds/2; smin += ds)
    {
        int k_iter = 0;
        double s = smin, Result = Find(min, max, p, s, k_iter);
        Results[Count] = Result;
        Iters[Count] = k_iter;
        ROF[Count++] = Func(Result, s);
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