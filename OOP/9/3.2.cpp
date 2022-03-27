#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

vector<int> Split(int n) {

    vector<int> numbers;

    while (true) {

        if (n == 0)
            break;

        double temp = (double)n / 10;
        n /= 10;
        numbers.push_back(round((temp-n)*10));
    }

    reverse(numbers.begin(), numbers.end());

    return numbers;

}

void t2_1_1() {

    int n, k;
    cin >> n >> k;

    vector<int> numbers = Split(n);

    int left = 0, right = 0;
    for (size_t i = 0; i < k; i++) {
        left += numbers[i];
        right += numbers[numbers.size() - 1 - i];
    }

    if (left == right)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

}

double Function(int x) {

    return 1 / pow(1 + x, 3) - 1;

}

void t2_1_2() {

    string n;
    cin >> n;
    string frac = n.substr(n.find('.') + 1);

    bool flag = true;
    for (size_t i = 0; i < frac.size(); i++) {
        for (size_t j = i + 1; j < frac.size(); j++) {
            if (frac[i] == frac[j]) {
                flag = false;
                break;
            }
        }
    }

    if (flag)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

}

void t2_2() {

    double x0 = -0.6, xn = 0.8, dx = 0.1;
    for (double x = x0; x < xn; x += dx) {

        double sum = 1;
        double operand = 1;
        int counter = 2;
        int sign = -1;
        while (operand > 0.000001) {

            double tempOperand = (double)counter*(counter+1)/2*pow(x, counter) * sign;
            sum += tempOperand;
            operand = tempOperand;
            sign *= -1;

        }

        cout << x << " " << sum << endl;

    }

}

int main() {

    t2_1_2();

}