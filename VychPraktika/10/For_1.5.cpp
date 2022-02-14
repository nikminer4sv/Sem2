#include <iostream>
#include <cmath>

using namespace std;

double Function(double x, int t);
void Func(double (*x3)(double x, int t), double a, double b, double t);

void Func(double (*x3)(double x, int t), double a, double b, double t)
{
    double const p = 1e-6;
    double I = p + 1, I1 = 0; 
    int k_iters = 0;
    for (int N = 2; (N <= 4) || (abs(I1 - I) > p); N *= 2)
    {
        double h, sum2 = 0, sum4 = 0, sum = 0;
        h = (b - a) / (2 * N); 
        for (int i = 1; i <= 2 * N - 1; i += 2)
        {
            sum4 += x3(a + h * i, t);       
            sum2 += x3(a + h * (i + 1), t); 
            k_iters++;
        }
        sum = x3(a, t) + 4 * sum4 + 2 * sum2 - x3(b, t); 
        I = I1;
        I1 = (h / 3) * sum;
    }
    
    cout << "\t" << a << "\t\t" << t << "\t\t" << I1 << "\t\t" << k_iters << "\n";
}

double Function(double x, int t)
{
    double x1 = x;
    for (int i = 0; i < t - 1; i++)
    {
        x1 *= x;
    }

    return (sin(x1) * sin(x1)) / (1 + x * x);
}