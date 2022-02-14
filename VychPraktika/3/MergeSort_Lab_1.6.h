#pragma once
#include <iostream>
using namespace std;

template<typename T>
void Fill(T* Array, int ArraySize)
{
    for (int i = 0; i < ArraySize; i++)
    {
        Array[i] = rand() % 100 + 1;
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
    int idbuf = 0, idl = 0, idr = ArraySize / 2;

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
            Array[i][j + 1] = '\0';
        }
    }
}

void DirectMergeSort(char** Array, int ArraySize)
{
    if (ArraySize < 2)
        return;

    DirectMergeSort(Array, ArraySize / 2);
    DirectMergeSort(&Array[ArraySize / 2], ArraySize - (ArraySize / 2));

    char** buf = new char* [ArraySize];
    for (int i = 0; i < ArraySize; i++)
    {
        buf[i] = new char[255];
    }
    int idbuf = 0, idl = 0, idr = ArraySize / 2;
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