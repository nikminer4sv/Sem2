#include <iostream>
#include <cstring>

using namespace std;

template<typename T>
void Fill(T* Array, int ArraySize);
void Fill(double* Array, int ArraySize);
void Fill(char* Array, int ArraySize);
void Fill(char** Array, int ArraySize);
template<typename T>
void DirectMergeSort(T* Array, int ArraySize);
void DirectMergeSort(char** Array, int ArraySize);
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
        char** PChar = new char*[n];
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

template<typename T>
void Fill(T* Array, int ArraySize)
{
    for (int i = 0; i < ArraySize; i++)
    {
        Array[i] = rand() % 100 + 1;
    }
}
void Fill(double* Array, int ArraySize)
{
    for (int i = 0; i < ArraySize; i++)
    {
        Array[i] = (rand() % 1000 + 1) / 10.0;
    }
}

void Fill(char* Array, int ArraySize)
{
    char Symbols[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < ArraySize; i++)
    {
        Array[i] = Symbols[rand() % int(sizeof(Symbols) - 2) + 1];
    }
}

void Fill(char** Array, int ArraySize)
{
    char Symbols[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < ArraySize; i++)
    {
        for (int j = 0; j < rand() % 10 + 1; j++)
        {
            Array[i][j] = Symbols[rand() % int(sizeof(Symbols) - 2) + 1];
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

    T* buf = new T[ArraySize];
    int idbuf = 0, idl = 0, idr = ArraySize / 2 ;

    while ((idl < ArraySize / 2) && (idr < ArraySize))
        if (Array[idl] < Array[idr]) 
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

void DirectMergeSort(char** Array, int ArraySize)
{
    if (ArraySize < 2)
        return;

    DirectMergeSort(Array, ArraySize / 2);
    DirectMergeSort(&Array[ArraySize / 2], ArraySize - (ArraySize / 2));

    char** buf = new char*[ArraySize];
    for (int i = 0; i < ArraySize; i++)
    {
        buf[i] = new char[255];
    }  
    int idbuf = 0, idl = 0, idr = ArraySize / 2 ;
    // ArraySize = 10, idr = 5

    while ((idl < ArraySize / 2) && (idr < ArraySize))
    // (0 < 5) && (5 < 10)
        if (strcmp(Array[idl], Array[idr]) <= 0) 
        // Array[0] > Array[5]
            buf[idbuf++] = Array[idl++];
            //buf[0] = Array[0], idbuf = 1, idl = 1
        else
            buf[idbuf++] = Array[idr++];
            //buf[0] = Array[0], idbuf = 1, idr = 6

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
    for (int i = 1; i <= ArraySize; i++)
    {
        cout << Array[i - 1] << "\t";
        if ((i % 20) == 0)
        {
            cout << endl;
        }
    }
}