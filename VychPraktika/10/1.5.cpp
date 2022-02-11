#include <iostream>
#include <cmath>

using namespace std;

void Print(double* Results, int* Iters);
double Function(double x, int t);
void Func(double (*xz)(double x, int t));

int main()
{
    Func(Function);
}

void Func(double (*xz)(double x, int t))
{
    double a, b = 1.234;
    double const p = 1e-6;
    double I = p + 1, I1 = 0; 
    double Results[24];
    int Iters[24];
    int Counter = 0;
    for (double s = 0, ds = 0.2; s < 1 + ds/2; s += ds)
    {
        a = s;
        for (int t = 1, dt = 1; t <= 4; t += dt)
        {
            int k_iters = 0;
            for (int N = 2; (N <= 4) || (abs(I1 - I) > p); N *= 2)
            {
                double h, sum2 = 0, sum4 = 0, sum = 0;
                h = (b - a) / (2 * N); 
                for (int i = 1; i <= 2 * N - 1; i += 2)
                {
                    sum4 += xz(a + h * i, t);       
                    sum2 += xz(a + h * (i + 1), t); 
                    k_iters++;
                }
                sum = xz(a, t) + 4 * sum4 + 2 * sum2 - xz(b, t); 
                I = I1;
                I1 = (h / 3) * sum;
            }
            Results[Counter] = I1;
            Iters[Counter++] = k_iters;
        }
    }
    Print(Results, Iters);
}

double Function(double x, int t)
{
    double x1 = x, x2 = x;
    for (int i = 0; i < t - 1; i++)
    {
        x1 *= x;
    }
    for (int i = 0; i < 2; i++)
    {
        x2 *= x;
    }

    return (sin(x1) * sin(x1)) / (1 + x2);
}

void Print(double* Results, int* Iters)
{
    cout << "\tS\t\tt\t\tInt\t\tk_iter\n\n";
    int Counter = 0;

    for (double s = 0, ds = 0.2; s < 1 + ds/2; s += ds)
    {
        for (int t = 1, dt = 1; t <= 4; t += dt)
        {
            cout << "\t" << s << "\t\t" << t << "\t\t" << Results[Counter] << "\t\t" << Iters[Counter++] << "\n";
        }
    }
}