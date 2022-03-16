#include <iomanip>
#include <iostream>
#include <math.h>

using namespace std;

const double e = 1.0e-6;
int s, s1 = 1, s2 = 4, k_iter = 0, a = 0;
double t, t1 = 0.2, t2 = 1.2, Int, b = 1.075; 

double integralFunction(int s, double t, double x) {
	return t * (3 * pow(x, s)) / sqrt(1 + pow(x, 3.0));
}

double Sum(double a, double b, double h, double s, double t) {
	double x, sum;
	x = a;
	sum = 0;
	while (x < b) {
		sum = sum + integralFunction(s, t, x);
		x = x + h;
	}
	return sum;
}

double calculateIntegral(int s, double t, int& k) {
	int n = 4;
	double h = (b - a) / n;
	double S1 = 0, S2 = 0;
	S1 = h * ((integralFunction(s, t, a) + integralFunction(s, t, b)) / 2 + Sum(a, b, h, s, t));
	k = 0;
	do {      
		S2 = S1;
		n *= 2;
		h = (b - a) / n;
		S1 = h * ((integralFunction(s, t, a) + integralFunction(s, t, b)) / 2 + Sum(a, b, h, s, t));
		k++;
	} while (fabs(S1 - S2) > e);
	return S1;
}

int main() {
	setlocale(LC_ALL, "");
	s = s1;
	cout << setw(10) << "S" << setw(15) << "t" << setw(15) << "Int" << setw(13) << "k_iter " << endl;
	cout << "______________________________________________________" << endl;
	for (double t = t1, s = s1; t <= t2, s <= s2; t += 0.2, s += 1) {
			Int = calculateIntegral(s, t, k_iter);
			cout << setw(10) << s << setw(15) << t << setw(15) << Int << setw(13) << k_iter << endl;
			cout << endl;
	}
	cout << "______________________________________________________" << endl;
}



