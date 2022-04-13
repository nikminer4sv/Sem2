#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int ComputeSum(int* array, int left, int right) {

    if (left == right)
        return abs(array[left - 1]) + array[left - 1];

    int sum = abs(array[left - 1]);
    int par_sum = array[left - 1];

    for (int i = left; i < right; i++) {

        sum &= abs(array[i]);
        par_sum += array[i];

    }

    return sum + par_sum;

}

int main() {

    
    ifstream stream;
    stream.open("input.txt");
    ofstream result;
    result.open("output.txt");

    int elements, records;
    stream >> elements >> records;
    int* elArray = new int[elements];
    int* rArray = new int[records * 2];

    for (int i = 0; i < elements; i++) 
        stream >> elArray[i];

    for (int i = 0; i < records * 2; i++)
        stream >> rArray[i];

    for (int f = 0; f < records * 2; f += 2) {

        int left = rArray[f];
        int right = rArray[f + 1];

        int* array = new int[7]{ 3, -3, 3, -3 , 6, 5, -3};
        
        int max = INT8_MIN;

        int width = 1;
        int position = left;
        while (true) {

            cout << "Left: " << position << endl;
            cout << "Right: " << position + width - 1 << endl;

            int sum = ComputeSum(array, position, position + width - 1);
            cout << "Sum: " << sum << endl;
            cout << "----------------------------" << endl;
            if (sum > max)
                max = sum;

            position += 1;

            if (position + width > right + 1) {
                width += 1;
                position = left;
            }

            if (width > right - left + 1)
                break;

        }

        result << max << endl;

    }


    /*
    int left = 3;
    int right = 7;

    int* array = new int[7]{ 3, -3, 3, -3 , 6, 5, -3};
    
    int max = INT_MIN;

    int width = 1;
    int position = left;
    while (true) {

        cout << "Left: " << position << endl;
        cout << "Right: " << position + width - 1 << endl;

        int sum = ComputeSum(array, position, position + width - 1);
        cout << "Sum: " << sum << endl;
        cout << "----------------------------" << endl;
        if (sum > max)
            max = sum;

        position += 1;

        if (position + width > right + 1) {
            width += 1;
            position = left;
        }

        if (width > right - left + 1)
            break;

    }

    //cout << max << endl;

    */

    //cout << ComputeSum(array, 5, 6);

    // 1 2 3
    

}