#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double F1(double x, double s = 0)
{
	return x * x * x - 3;
}

double F2(double x, double s)
{
	return pow(x, 1.0 / s) - 2 * pow(cos(M_PI * x / 2), 2);
}

bool CheckForValidBounds(int y1, int y2)
{
	if (y1 * y2 > 0)
		return false;
	else
		return true;
}

double FindRoot(double (*f)(double, double), double a, double b, double eps, double s = 0)
{
	double c;
	int count = 0;
	while ((b - a) / 2.0 > eps)
	{
		c = (a + b) / 2.0;
		count++;
		if ((f(a, s) * f(c, s)) > 0)
			a = c;
		else
			b = c;
		cout << setw(8) << "Root: " << c << " "
			 << "Function value in c: " << f(c, s) << " "
			 << "Number of iteration: " << count << endl;
	}
	cout << endl;
	return c;
}

int main()
{
	const double eps = 10e-6;

	cout << "Enter the bounds for the first function: " << endl;
	double a, b;
	cin >> a;
	cin >> b;

	if (CheckForValidBounds(F1(a), F1(b)))
	{
		double x = FindRoot(F1, a, b, eps);
		cout << "The root of first function is " << x << endl;
	}
	else
	{
		cout << "Enter the valid bounds: " << endl;
		cin >> a;
		cin >> b;
	}

	cout << "Enter the bounds for the second function: " << endl;
	cin >> a;
	cin >> b;

	double deltaS = 0.5, sMin = 0.5, sMax = 2;

	while (sMin <= sMax)
	{
		cout << sMin << endl;
		if (CheckForValidBounds(F2(a, sMin), F2(b, sMin)))
		{
			double x = FindRoot(F2, a, b, eps, sMin);
			cout << "The root of second function is " << x << endl;
		}
		else
		{
			cout << "Enter the valid bounds: " << endl;
			cin >> a;
			cin >> b;
		}
		sMin += deltaS;
	}
	return 0;
}