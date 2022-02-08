#include <iostream>
#include <ctime>

using namespace std;

int& Max(int Array[], int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        Array[i - 1] = rand() % 10 + 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << Array[i] << '\t';
    }
    cout << endl;

    int MaxIndex = NULL, MaxCount = 0;

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
        
        if (CurrentCount == 2 && MaxIndex == NULL)
        {
            MaxIndex = Index;
            MaxCount = CurrentCount;
        }
        else if (CurrentCount == 2 && Array[MaxIndex] < Array[Index])
        {
            MaxIndex = Index;
            MaxCount = CurrentCount;
        }
        
    }

    if (MaxCount != 2)
    {
        MaxIndex = 0, MaxCount = 0;
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

            if (Array[MaxIndex] < Array[Index])
            {
                MaxIndex = Index;
                MaxCount = CurrentCount;
            }
        }
    }

    cout << "MaxCount: " << MaxCount << "\tMaxIndex: " << MaxIndex << endl;

    return Array[MaxIndex];
}

int main()
{
    srand(time(NULL));
    cout << "Enter the number of numbers: ";
    int n, k;
    cin >> n;
    int* Array = new int[n];
   

    cout << "Enter the value of k: ";
    cin >> k;

    int& p = Max(Array, n, k);
    cout << p << endl;
    p = k;
    cout << p << endl;

    delete[] Array;
}

