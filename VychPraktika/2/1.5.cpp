#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

double f(double x, double s, double t)
{
	return pow(t + pow(x, 3), 1.0 / s);
}

double rectangle_integral(double (*f)(double, double, double), double a, double b, double s, double t, int n)
{
	double x, h;
	double sum = 0.0;
	double fx;
	h = (b - a) / n;

	for (int i = 0; i < n; i++)
	{
		x = a + i * h;
		fx = f(x, s, t);
		sum += fx;
	}
	return (sum * h);
}

int main()
{
	double a, b, sMin = 1.5, sMax = 2.5, tMin = 0.6, tMax = 1.8, deltaS = 0.5, deltaT = 1;
	double integral1, integral;
	int n = 1, i = 0;
	const double eps = 10e-6;

	cout << "Enter a left bound: ";
	cin >> a;
	cout << "Enter the right bound: ";
	cin >> b;

	while (sMin <= sMax && tMin <= tMax)
	{
		integral1 = rectangle_integral(f, a, b, sMin, tMin, n);
		do
		{
			integral = integral1;
			n = 2 * n;
			integral1 = rectangle_integral(	f, a, b, sMin, tMin, n);
		} while (fabs(integral1 - integral) > eps);
		cout << "Integral = " << integral1 << endl;
		sMin = sMin + i * deltaS;
		tMin = tMin + i * deltaT;
		i++;
	}

	return 0;
}