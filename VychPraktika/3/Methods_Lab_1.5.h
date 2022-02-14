#pragma once
#include <iostream>
#define EXP 2.718
using namespace std;

double f(double x, double t, double s) {
    return pow(1 + x * x, 1 / t) / pow(EXP, sin(x) + s);
}

double arrayRectangle(double (*f)(double x, double t, double s), double a, double b, int n, double t, double s) {
    double x, h;
    double sum = 0.0;
    double fx;
    h = (b - a) / n;  //шаг

    for (int i = 0; i < n; i++) {
        x = a + i * h;

        fx = f(x, t, s);
        sum += fx;
    }

    return (sum * h); //приближенное значение интеграла равно 
                      //сумме площадей прямоугольников
}

double Integral(int a, int b, double s, double t, int& k_iter) {

    int n = 1;
    double area1, area;
    const double eps = 1e-6;
    area1 = arrayRectangle(f, a, b, n, t, s); //первое приближение для интеграла
    do {
        area = area1;     //второе приближение
        n = 2 * n;  //увеличение числа шагов в два раза, 
                    //т.е. уменьшение значения шага в два раза
        area1 = arrayRectangle(f, a, b, n, t, s);
        k_iter++;
    } while (fabs(area1 - area) > eps);  //сравнение приближений с заданной точностью

    return area1;
}