#include <iostream>

using namespace std;

void FillTheArray(int *pointer, const int *size)
{
	cout << "Enter the values to fill the array: " << endl;
	for (int k = 0; k < *size; k++)
		cin >> pointer[k];
}

void PrintTheArray(const int *pointer, const int *size)
{
	for (int k = 0; k < *size; k++)
		cout << pointer[k] << " ";
	cout << endl;
}

int &AnalysisTheArray(int *pointerToMain, int *pointerToDuplicates, const int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (pointerToMain[i] == pointerToDuplicates[j])
			{
				int wasBefore = 0;
				for (int k = 0; k < i; k++)
				{
					if (pointerToMain[k] == pointerToMain[i])
					{
						wasBefore = 1;
						break;
					}
				}
				if (wasBefore == 0)
				{
					pointerToDuplicates[count] = pointerToMain[i];
					count++;
				}
				break;
			}
		}
	}

	int minIndex = 0;
	if (count == 0)
	{
		for (int k = 0; k < size; k++)
		{
			if (pointerToMain[k] < pointerToMain[minIndex])
			{
				minIndex = k;
			}
		}
		return pointerToMain[minIndex];
	}
	else
	{
		for (int k = 0; k < count; k++)
		{
			if (pointerToDuplicates[k] < pointerToDuplicates[minIndex])
			{
				minIndex = k;
			}
		}
		return pointerToDuplicates[minIndex];
	}
}

void ReplaceElement(int &minNum)
{
	cout << "Enter the number you want to replace the minimum number with: ";
	int k;
	cin >> k;
	minNum = k;
}

int main()
{
	cout << "Enter the size of the array: " << endl;
	int size;
	cin >> size;

	int *enteredNumbers = new int[size];
	int *arrayOfDuplicate = new int[size];

	int *pointerToArray = enteredNumbers;
	FillTheArray(pointerToArray, &size);
	PrintTheArray(pointerToArray, &size);

	int *pointerToDuplicates = arrayOfDuplicate;
	int &minNum = AnalysisTheArray(pointerToArray, pointerToDuplicates, size);

	cout << "The smallest number in array: " << minNum << endl;

	ReplaceElement(minNum);
	PrintTheArray(pointerToArray, &size);

	delete[] enteredNumbers;
	delete[] arrayOfDuplicate;

	return 0;
}
