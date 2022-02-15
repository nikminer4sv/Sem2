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
    h = (b - a) / n;  //���

    for (int i = 0; i < n; i++) {
        x = a + i * h;

        fx = f(x, t, s);
        sum += fx;
    }

    return (sum * h); //������������ �������� ��������� ����� 
                      //����� �������� ���������������
}

double Integral(int a, int b, double s, double t, int& k_iter) {

    int n = 1;
    double area1, area;
    const double eps = 1e-6;
    area1 = arrayRectangle(f, a, b, n, t, s); //������ ����������� ��� ���������
    do {
        area = area1;     //������ �����������
        n = 2 * n;  //���������� ����� ����� � ��� ����, 
                    //�.�. ���������� �������� ���� � ��� ����
        area1 = arrayRectangle(f, a, b, n, t, s);
        k_iter++;
    } while (fabs(area1 - area) > eps);  //��������� ����������� � �������� ���������

    return area1;
}