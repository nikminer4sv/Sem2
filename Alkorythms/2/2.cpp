#include "Header-Files/Functions.h"

int main()
{
    srand(time(NULL));

    std::cout << "Enter the size of sorted array: " << std::endl;
    int arraySize;
    std::cin >> arraySize;

    std::vector<int> sortedArray(arraySize);
    sortedArray = GetSortedArray(sortedArray);

    std::cout << std::endl << "Enter the number: " << std::endl;
    int number;
    std::cin >> number;

    std::vector<int> resultArray = GetResultedArray(sortedArray, number);

    return 0;
}
