#include <iostream>
#include "MergeSort.h"

using namespace std;

int main()
{
    cout << "Enter the amount of elements: ";
    int n, k;
    cin >> n;
    cout << "Choose type of elemets:\n1. Integer\n2. Double\n3. Char\n4. C-string\n";
    cin >> k;

    switch (k)
    {
    case 1:
    {
        int* Int = new int[n];
        Fill(Int, n);
        DirectMergeSort(Int, n);
        Print(Int, n);
        break;
    }

    case 2:
    {
        double* Double = new double[n];
        Fill(Double, n);
        DirectMergeSort(Double, n);
        Print(Double, n);
        break;
    }

    case 3:
    {
        char* Char = new char[n];
        Fill(Char, n);
        DirectMergeSort(Char, n);
        Print(Char, n);
        break;
    }

    case 4:
    {
        char** PChar = new char* [n];
        for (int i = 0; i < n; i++)
        {
            PChar[i] = new char[255];
        }
        Fill(PChar, n);
        DirectMergeSort(PChar, n);
        Print(PChar, n);
        break;
    }

    default:
        cout << "You fuckin fuckin you";
        break;
    }
}

