#pragma once

#include "Extensions.h"
#include "Sort.h"

struct val_ind
{
    int  val;
    int  pos;
};

std::vector<int> GetSortedArray(std::vector<int> &arrayToSort)
{
    FillTheArray(arrayToSort);

    std::cout << "Unsorted array: " << std::endl;
    PrintTheArray(arrayToSort);
    std::cout << std::endl << std::endl;

    MergeSort(arrayToSort, 0, arrayToSort.size()-1);

    std::cout << "Sorted array: " << std::endl;
    PrintTheArray(arrayToSort);

    return arrayToSort;
}

std::vector<int> GetResultedArray(const std::vector<int> &sortedArray, const int &sum)
{
    std::vector<int> resultArrayVal;

    val_ind arr_ind[sortedArray.size()];
    for (int i = 0; i < sortedArray.size(); ++i)
    {
        arr_ind[i].val  = sortedArray[i];
        arr_ind[i].pos = i + 1;
    }

    val_ind *left  = arr_ind;
    val_ind *right = arr_ind + sortedArray.size() - 1;
    while(left < right)
    {
        int s = (*left).val + (*right).val;
        if (s == sum )
        {
            resultArrayVal.push_back(left->val);
            resultArrayVal.push_back(right->val);

            std::cout << "Valid sum: " << std::endl;
            PrintTheArray(resultArrayVal);

            std::cout << std::endl << "Positions of the values:"
                      << std::endl << left->pos << " " << right->pos << std::endl;

            return resultArrayVal;
        }
        else (s < sum) ? left++ : right--;
    }

    std::cout << "Sum does not exist." << std::endl;
    PrintTheArray(resultArrayVal);

    return resultArrayVal;
}