#include <iostream>
#include <cmath>

using namespace std;

struct EasyFunctionResult {

    double x1 = __DBL_MAX__;
    double x2 = __DBL_MAX__;

};

EasyFunctionResult EasyFunction();
void HardFunction();
double HardFunctionCore(double x, double s);
double Find(double min, double max, double p, int& k_iter);
void PrintTable(double* results, double* functionResult, int* iterations, int arraySize, double sMin, double ds);

int main() {

    EasyFunctionResult easyFunctionResult = EasyFunction();
    
    if (easyFunctionResult.x1 != __DBL_MAX__)
        cout << "x1 = " << easyFunctionResult.x1 << endl;

    if (easyFunctionResult.x2 != __DBL_MAX__)
        cout << "x2 = " << easyFunctionResult.x2 << endl;

    HardFunction();
    
}

EasyFunctionResult EasyFunction() {

    // f(x) = (x+1)^2 - 5
    // f(x) = x^2 + 2x -3

    int minValue = 2, maxValue = 4;
    double a = 1, b = -2, c = -4;
    double D, x1, x2; 
    
    D = pow(b, 2) - 4 * a * c;

    EasyFunctionResult result;

    if (D > 0) {

        x1 = ((-b) + sqrt(D)) / (2 * a);
        x2 = ((-b) - sqrt(D)) / (2 * a);

        if ((minValue < x1) && (x1 < maxValue)) 
            result.x1 = x1;
        
        if ((minValue < x2) && (x2 < maxValue)) 
            result.x1 = x2;
        
    } else if (D == 0) {

        x1 = -b / (2 * a);
        if ((minValue < x1) && (x1 < maxValue))
            result.x1 = x1;
        
    }

    return result;

}

double HardFunctionCore(double x, double s) {
    return pow(x - s, 2) - exp(-x);
}

double Find(double min, double max, double p, double s, int& k_iter) {

    while (abs(max - min) > p) {
        min = max - (max - min) * HardFunctionCore(max, s) / (HardFunctionCore(max, s) - HardFunctionCore(min, s));
        max = min - (min - max) * HardFunctionCore(min, s) / (HardFunctionCore(min, s) - HardFunctionCore(max, s));
        k_iter++;
    }

    return max;

}

void HardFunction() {

    double const p = 1e-6;
    double minValue = -1.5, maxValue = 2, sMin = 0.7, sMax = 1.6, ds = 0.3;

    int arraySize = int((sMax - sMin)/ds + 1);
    int count = 0;
    double results[arraySize];
    double functionResult[arraySize]; 
    int iterations[arraySize];

    for (double sMinCopy = sMin; sMinCopy <= sMax + ds/2; sMinCopy += ds) {
        int k_iter = 0;
        double s = sMinCopy;
        double result = Find(minValue, maxValue, p, s, k_iter);
        results[count] = result;
        iterations[count] = k_iter;
        functionResult[count++] = HardFunctionCore(result, s);
    }

    PrintTable(results, functionResult, iterations, arraySize, sMin, ds);

}

void PrintSeparator(char symbol, int length) {

    for (int i = 0; i < length; i++) 
        cout << symbol;

    cout << endl;

}

void PrintTable(double* results, double* functionResult, int* iterations, int arraySize, double sMin, double ds) {

    cout << "\tS\t|\tX\t|\tF(x)\t\t|\tk_iter\n";
    PrintSeparator('-', 75);

    for (int i = 0; i < arraySize; sMin += ds, i++)
        cout << "\t" << sMin << "\t|\t" << results[i] << "\t|\t" << functionResult[i] << "\t|\t" << iterations[i] << "\n";
    
}