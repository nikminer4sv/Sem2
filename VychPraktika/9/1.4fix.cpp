#include <iostream>
#include <math.h>
#include <iomanip>
#include <functional>

using namespace std;

double Func1(double x, double s) {
    return pow((x - 1), 2.0) - 5;
}

double Func2(double x, double s) {
    return (pow((x - 0.5), 2.0)) - (exp(-x));
}

double Radical(std::function<double(double,double)> f, double s, double a, double b, double eps, long int& k_iter_1) {

    double c = (a + b) / 2;

    while (abs(a - b) >= eps) {
        k_iter_1++;
        if (f(a, s) * f(c, s) < 0) 
            b = c;
        else 
            a = c;
        
        c = (a + b) / 2;

    }

    return c;

}


int main() {

    cout << "a)" << endl;

    double a = 2;
    double b = 4;
    double eps = 0.000001;

    long int k_iter_1 = 0;
    double s = 0;
    double x = Radical(Func1, s, a, b, eps, k_iter_1);
    double y = Func1(x, s);

    cout << "|" << setw(15) << "S" << "|" << setw(15) << "x" << "|" << setw(15) << "y" << "|" << setw(15) << "k_iter" << "|" << endl;
    cout << "|" << setw(15) << s << "|" << setw(15) << x << "|" << setw(15) << y << "|" << setw(15) << k_iter_1 << "|" << endl;

    cout << endl;
    cout << "b)" << endl;

    a = -1.5;
    b = 2;
    cout << "|" << setw(15) << "S" << "|" << setw(15) << "x" << "|" << setw(15) << "y" << "|" << setw(15) << "k_iter" << "|" << endl;
    for (double s = 0.7; s <= 1.6; s += 0.3) {
        k_iter_1 = 0;
        double x = Radical(Func2, s, a, b, eps, k_iter_1);
        double y = Func2(x, s);
        cout << "|" << setw(15) << s << "|" << setw(15) << x << "|" << setw(15) << y << "|" << setw(15) << k_iter_1 << "|" << endl;
    }
    return 0;
}