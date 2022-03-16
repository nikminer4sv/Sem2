#include <iostream>

using namespace std;

void fillNumbers(int* numbers, const int n)
{
    for (int i = 0; i < n; i++)
        numbers[i] = rand() % (4 * n) - (2 * n);
}

void printNumbers(const int* numbers, const int n)
{
    int quantity = 0;
    for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << '\t';
        quantity++;
        if (quantity == 10)
            cout << endl;
    }
    cout << endl;
}

void findMaxMinFirstMethod(const int* numbers, const int n)
{
    int max = numbers[0];
    int min = numbers[0];
    
    int maxComparison = 0;
    int minComparison = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        maxComparison++;
        if (numbers[i + 1 ] > max)
        {
            max = numbers[i + 1];
            continue;
        }
        else if (numbers[i + 1] < min)
            min = numbers[i + 1];
        minComparison++;
     
    }
    cout << "First method\n" << "Max: " << max << ", comparison: " << maxComparison << "; Min: " 
    << min << ", comparison: " << minComparison << endl;
}

void findMaxMinSecondMethod(const int* numbers, const int n)
{
    int max = numbers[0];
    int min = numbers[0];

    int Comparison = 0;

    int tempMaxFirst = 0;
    int tempMaxSecond = 0;
    int tempMinFirst = 0;
    int tempMinSecond = 0;

    int k = n / 2;
    for (int i = 1; i < k; i++)
    {
        if (numbers[2 * i] > numbers[2 * i + 1])
        {
            tempMaxFirst = numbers[2 * i];
            tempMinFirst = numbers[2 * i + 1];
            if (numbers[0] > numbers[2 * i - 1])
            {
                tempMaxSecond = numbers[0];
                tempMinSecond = numbers[2 * i - 1];
            }
            else
            {
                tempMaxSecond = numbers[2 * i - 1];
                tempMinSecond = numbers[0];
            }
            
            Comparison++;
            if (tempMaxSecond > tempMaxFirst && tempMaxSecond > max)
                max = tempMaxSecond;
            else if (tempMaxFirst > tempMaxSecond && tempMaxFirst > max)
                max = tempMaxFirst;

            if (tempMinFirst < tempMinSecond && tempMinFirst < min)
                min = tempMinFirst;
            else if (tempMinSecond < tempMinFirst && tempMinSecond < min)
                min = tempMinSecond;       
        }
        else
        {
            tempMaxFirst = numbers[2 * i + 1];
            tempMinFirst = numbers[2 * i];
            if (numbers[0] > numbers[2 * i - 1])
            {
                tempMaxSecond = numbers[0];
                tempMinSecond = numbers[2 * i - 1];
            }
            else
            {
                tempMaxSecond = numbers[2 * i - 1];
                tempMinSecond = numbers[0];
            }
            
            Comparison++;
            if (tempMaxSecond > tempMaxFirst && tempMaxSecond > max)
                max = tempMaxSecond;
            else if (tempMaxFirst > tempMaxSecond && tempMaxFirst > max)
                max = tempMaxFirst;

            if (tempMinFirst < tempMinSecond && tempMinFirst < min)
                min = tempMinFirst;
            else if (tempMinSecond < tempMinFirst && tempMinSecond < min)
                min = tempMinSecond;   
        } 
    }

    if (n % 2 != 0)
    {
        Comparison++;
        if (numbers[n - 1] > max)
            max = numbers[n - 1];
        else if (numbers[n - 1] < min)
            min = numbers[n - 1];
    }

    cout << "Second method\n" << "Max: " << max << ", comparison: " << Comparison << "; Min: " 
    << min << ", comparison: " << Comparison << endl;
}

int main()
{
    unsigned int n;
    cout << "Enter the n (n > 0): ";
    cin >> n;

    int* numbers = new int[n];
    fillNumbers(numbers, n);
    printNumbers(numbers, n);
    findMaxMinFirstMethod(numbers, n);
    findMaxMinSecondMethod(numbers, n);

    delete[] numbers;
    return 0;
}