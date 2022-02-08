#include <iostream>

using namespace std;

void Fill(int* Array, int n);
void DirectMergeSort(int* Array, int n);
void Print(int* Array, int n);

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
    {    int* Array = new int[n];
        Fill(Array, n);
        DirectMergeSort(Array, n);
        Print(Array, n);
        break;
    }
        
    case 2:
        cout << "Nothing.";
        break;
    
    case 3:
        cout << "Nothing.";
        break;
        
    case 4:
        cout << "Nothing.";
        break;
    
    default:
        cout << "You fuckin fuckin you";
        break;
    }
}

void Fill(int Array[], int ArraySize)
{
    for (int i = 0; i < ArraySize; i++)
    {
        Array[i] = rand() % 100 + 1;
    }
}

void DirectMergeSort(int Array[], int ArraySize)
{
    if (ArraySize < 2)
        return;

    DirectMergeSort(Array, ArraySize / 2);
    DirectMergeSort(&Array[ArraySize / 2], ArraySize - (ArraySize / 2));

    int* buf = new int[ArraySize];
    int idbuf = 0, idl = 0, idr = ArraySize / 2 ;

    while ((idl < ArraySize / 2) && (idr < ArraySize))
        if (Array[idl] > Array[idr]) 
            buf[idbuf++] = Array[idl++];
        else
            buf[idbuf++] = Array[idr++];

    while (idl < ArraySize / 2) 
        buf[idbuf++] = Array[idl++];

    while (idr < ArraySize) 
        buf[idbuf++] = Array[idr++];

    for (idl = 0; idl < ArraySize; idl++)
        Array[idl] = buf[idl];
        
    delete[]buf;
}

void Print(int Array[], int ArraySize)
{
    for (int i = 0; i < ArraySize; i++)
    {
        cout << Array[i] << "\t";
        if ((i % 20) == 0)
        {
            cout << endl;
        }
    }
}