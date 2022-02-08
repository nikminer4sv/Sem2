#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
void Fill(T* Array, int ArraySize);
template<typename T>
void DirectMergeSort(T* Array, int ArraySize);
template<typename T>
void Print(T* Array, int ArraySize);

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
        int* Array = new int[n];
        Fill(Array, n);
        DirectMergeSort(Array, n);
        Print(Array, n);
        break;
    }
        
    case 2:
    {    
        double* Array = new double[n];
        Fill(Array, n);
        DirectMergeSort(Array, n);
        Print(Array, n);
        break;
    }
    
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

template<typename T>
void Fill(T* Array, int ArraySize)
{
    int* Int;
    double* Double;
    char *Char;
    char** PChar;
    if (typeid(Array) == typeid(Int))
    {
        for (int i = 0; i < ArraySize; i++)
        {
            Array[i] = rand() % 100 + 1;
        }
    }
    else if (typeid(Array) == typeid(Double))
    {
        for (int i = 0; i < ArraySize; i++)
        {
            Array[i] = (rand() % 1000 + 1) / 10;
        }
    }
    else if (typeid(Array) == typeid(Char))
    {
        for (int i = 0; i < ArraySize; i++)
        {
            Array[i] = rand() % 39 + 41;
        }
    }
    else if (typeid(Array) == typeid(PChar))
    {
        for (int i = 0; i < ArraySize; i++)
        {
            for (int j = 0; j < rand() % 10 + 1; j++)
            {
                Array[i][j] = rand() % 39 + 41;
            }
        }
    }
}

template<typename T>
void DirectMergeSort(T* Array, int ArraySize)
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

template<typename T>
void Print(T* Array, int ArraySize)
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