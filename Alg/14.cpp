#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    double* array = new double[n];
    for (int i = 0; i < n; i++) 
        cin >> array[i];

    for (int i = 0; i < n; i++) 
        cout << array[i] << " ";

}