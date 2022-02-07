#include <iostream>
#include <vector>

using namespace std;

int* Max(int Array[], int n, int k);
int NumberOfDifferent(int Array[], int n);
void Count(int Array[], int n, int *Numbers, int *Rate);
void RateAndIndex(int Counter, int *Numbers, int *Rate, int &MaxIndex, int &MaxRate);
int FirstInclusion(int Array[], int MaxIndex);
void PrintRate(int Counter, int *Numbers, int *Rate);
void Print(int Array[], int n);

int main()
{
    cout << "Enter the number of numbers: ";
    int n, k;
    cin >> n;
    int *Array = new int[n];

    cout << "Enter the value of k: ";
    cin >> k;

    int* p = Max(Array, n, k);
    *p = k;

    Print(Array, n);
}

int* Max(int Array[], int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        Array[i - 1] = rand() % 10 + 1;
    }

    int Counter = NumberOfDifferent(Array, n);
    int Numbers[Counter];
    int Rate[Counter];

    Count(Array, n, Numbers, Rate);

    int MaxIndex = 0;
    int MaxRate = 0;

    RateAndIndex(Counter, Numbers, Rate, MaxIndex, MaxRate);

    int First = FirstInclusion(Array, MaxIndex);

    PrintRate(Counter, Numbers, Rate);

    return &Array[First];
}

int NumberOfDifferent(int Array[], int n)
{
    int Counter = 0;

    for (int i = 0; i < n; i++)
    {
        bool Flag = true;

        for (int Before = 0; Before < i; Before++)
        {
            if (Array[Before] == Array[i])
            {
                Flag = false;
            }
        }
        if (Flag)
        {
            Counter++;
        }
    }

    return Counter;
}

void Count(int Array[], int n, int *Numbers, int *Rate)
{
    int Chislo = 0;

    for (int i = 0; i < n; i++)
    {
        int RateOfNumber = 1;
        bool Flag = true;
        
        for (int After = i + 1; After < n; After++)
        {
            if (Array[i] == Array[After])
            {
                RateOfNumber++;
            }
        }
        for (int Before = 0; Before < i; Before++)
        {
            if (Array[Before] == Array[i])
            {
                Flag = false;
            }
        }
        if (Flag)
        {
            Numbers[Chislo] = Array[i];
            Rate[Chislo++] = RateOfNumber;
        }
    }
}

void RateAndIndex(int Counter, int *Numbers, int *Rate, int &MaxIndex, int &MaxRate)
{
    for (int i = 0; i < Counter; i++)
    {
        if (Rate[i] > MaxRate)
        {
            MaxRate = Rate[i];
            MaxIndex = i;
        }
        else if (Rate[i] == MaxRate)
        {
            if (Numbers[i] < Numbers[MaxIndex])
            {
                MaxRate = Rate[i];
                MaxIndex = i;
            }
        }
    }
}

int FirstInclusion(int Array[], int MaxIndex)
{
    int First = 0;

    while (Array[First] != Array[MaxIndex])
    {
        First++;
    }

    return First;
}

void PrintRate(int Counter, int *Numbers, int *Rate)
{
    cout << "\n\nRate of numbers:\n\n";

    for (int i = 0; i < Counter; i++)
    {
        cout << "  " << Numbers[i] << " - " << Rate[i] << endl;
    }

    cout << "\n\n";
}

void Print(int Array[], int n)
{
    cout << "Numbers:\n\n";

    for (int i = 1; i <= n; i++)
    {
        cout << Array[i - 1] << " ";

        if ((i % 20) == 0)
        {
            cout << endl;
        }
    }
}