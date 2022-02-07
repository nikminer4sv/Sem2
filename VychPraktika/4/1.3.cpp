#include <iostream>

using namespace std;

int& Max(int Array[], int n, int k);

int main()
{
    cout << "Enter the number of numbers: ";
    int n, k;
    cin >> n;
    int *Array = new int[n];

    cout << "Enter the value of k: ";
    cin >> k;

    int& p = Max(Array, n, k);
    p = k;
}

int& Max(int Array[], int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        Array[i - 1] = rand() % 10 + 1;
    }

    int MaxIndex = 0, MaxCount = 0;

    for (int Index = 0; Index < n; Index++)
    {
        int CurrentCount = 1;

        for (int Index_2 = Index + 1; Index_2 < n; Index_2++)
        {
            if (Array[Index_2] == Array[Index])
            {
                CurrentCount++;
            }
        }
        if (CurrentCount > MaxCount)
        {
            MaxIndex = Index;
            MaxCount = CurrentCount;
        }
        else if ((CurrentCount == MaxCount) && (Array[MaxIndex] > Array[Index]))
        {
            MaxIndex = Index;
            MaxCount = CurrentCount;
        }
    }

    cout << "MaxCount: " << MaxCount << "\tMaxIndex: " << MaxIndex << endl;

    return Array[MaxIndex];
}