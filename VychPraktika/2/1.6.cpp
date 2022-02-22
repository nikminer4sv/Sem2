#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

template <typename T>
void FillTheArray(T *Array, int ArraySize);
template <typename T>
void MergeSort(T *Array, int leftElement, int rightElement);
template <typename T>
void PrintTheArray(T *Array, int ArraySize);
template <typename T>
void Merge(T *Array, int leftElement, int middleElement, int rightElement);

template <typename T>
void FillTheArray(T *Array, int ArraySize)
{
	srand(time(NULL));
	int *Int;
	double *Double;
	char *Char;
	char **PChar;
	if (typeid(Array) == typeid(Int))
	{
		for (int i = 0; i < ArraySize; i++)
		{
			Array[i] = rand() % 101;
		}
	}
	else if (typeid(Array) == typeid(Double))
	{
		for (int i = 0; i < ArraySize; i++)
		{
			Array[i] = (rand() % 1000 + 1) / 10.0;
		}
	}
	else if (typeid(Array) == typeid(Char))
	{
		for (int i = 0; i < ArraySize; i++)
		{
			Array[i] = rand() % 39 + 41;
		}
	}
}

void FillTheArray(char **Array, int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		for (int j = 0; j < ArraySize; j++)
		{
			Array[i][j] = rand() % 39 + 41;
		}
	}
}

template <typename T>
void PrintTheArray(T *Array, int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		cout << Array[i] << " ";
	}
	cout << endl;

	delete[] Array;
}

void PrintTheArray(char **Array, int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		for (int j = 0; j < ArraySize; j++)
		{
			cout << Array[i][j];
		}
		cout << " ";
	}
	cout << endl;

	for (int i = 0; i < ArraySize; i++)
		delete Array[i];
	delete[] Array;
}

template <typename T>
void Merge(T *array, int leftElement, int middleElement, int rightElement)
{
	int i, j, k, leftTempArraySize, rightTempArraySize;

	leftTempArraySize = middleElement - leftElement + 1;
	rightTempArraySize = rightElement - middleElement;
	T *leftTempArray = new T[leftTempArraySize];
	T *rightTempArray = new T[rightTempArraySize];

	for (i = 0; i < leftTempArraySize; i++)
		leftTempArray[i] = array[leftElement + i];
	for (j = 0; j < rightTempArraySize; j++)
		rightTempArray[j] = array[middleElement + 1 + j];
	i = 0;
	j = 0;
	k = leftElement;

	while (i < leftTempArraySize && j < rightTempArraySize)
	{
		if (leftTempArray[i] <= rightTempArray[j])
		{
			array[k] = leftTempArray[i];
			i++;
		}
		else
		{
			array[k] = rightTempArray[j];
			j++;
		}
		k++;
	}
	while (i < leftTempArraySize)
	{
		array[k] = leftTempArray[i];
		i++;
		k++;
	}
	while (j < rightTempArraySize)
	{
		array[k] = rightTempArray[j];
		j++;
		k++;
	}
}

void Merge(char **array, int leftElement, int middleElement, int rightElement)
{
	int i, j, k, leftTempArraySize, rightTempArraySize;

	leftTempArraySize = middleElement - leftElement + 1;
	rightTempArraySize = rightElement - middleElement;
	char **leftTempArray = new char *[leftTempArraySize];
	for (int i = 0; i < leftTempArraySize; i++)
		leftTempArray[i] = new char[leftTempArraySize];
	char **rightTempArray = new char *[rightTempArraySize];
	for (int i = 0; i < rightTempArraySize; i++)
		rightTempArray[i] = new char[rightTempArraySize];

	for (i = 0; i < leftTempArraySize; i++)
		strcpy(leftTempArray[i], array[leftElement + i]);
	for (j = 0; j < rightTempArraySize; j++)
		strcpy(rightTempArray[j], array[middleElement + 1 + j]);
	i = 0;
	j = 0;
	k = leftElement;

	while (i < leftTempArraySize && j < rightTempArraySize)
	{
		if (strcmp(leftTempArray[i], rightTempArray[j]) <= 0)
		{
			strcpy(array[k], leftTempArray[i]);
			i++;
		}
		else
		{
			strcpy(array[k], rightTempArray[j]);
			j++;
		}
		k++;
	}

	while (i < leftTempArraySize)
	{
		strcpy(array[k], leftTempArray[i]);
		i++;
		k++;
	}

	while (j < rightTempArraySize)
	{
		strcpy(array[k], rightTempArray[j]);
		j++;
		k++;
	}
}

template <typename T>
void MergeSort(T *array, int leftElement, int rightElement)
{
	T middleElement;
	if (leftElement < rightElement)
	{
		T middleElement = leftElement + (rightElement - leftElement) / 2;
		MergeSort(array, leftElement, middleElement);
		MergeSort(array, middleElement + 1, rightElement);
		Merge(array, leftElement, middleElement, rightElement);
	}
}

void MergeSort(char **array, int leftElement, int rightElement)
{
	int middleElement;
	if (leftElement < rightElement)
	{
		middleElement = leftElement + (rightElement - leftElement) / 2;
		MergeSort(array, leftElement, middleElement);
		MergeSort(array, middleElement + 1, rightElement);
		Merge(array, leftElement, middleElement, rightElement);
	}
}

void CreateTheArray(const int choice, const int size)
{
	switch (choice)
	{
	case 1:
	{
		int *array = new int[size];
		FillTheArray(array, size);
		cout << "Unsorted array: " << endl;
		PrintTheArray(array, size);
		MergeSort(array, 0, size - 1);
		cout << "Sorted array: " << endl;
		PrintTheArray(array, size);
		break;
	}

	case 2:
	{
		double *array = new double[size];
		FillTheArray(array, size);
		cout << "Unsorted array: " << endl;
		PrintTheArray(array, size);
		MergeSort(array, 0, size - 1);
		cout << "Sorted array: " << endl;
		PrintTheArray(array, size);
		break;
	}

	case 3:
	{
		char *array = new char[size];
		FillTheArray(array, size);
		cout << "Unsorted array: " << endl;
		PrintTheArray(array, size);
		MergeSort(array, 0, size - 1);
		cout << "Sorted array: " << endl;
		PrintTheArray(array, size);
		break;
	}

	case 4:
	{
		char **array = new char *[size];
		for (int i = 0; i < size; i++)
			array[i] = new char[size];
		FillTheArray(array, size);
		cout << "Unsorted array: " << endl;
		PrintTheArray(array, size);
		MergeSort(array, 0, size - 1);
		cout << "Sorted array: " << endl;
		PrintTheArray(array, size);
		break;
	}

	default:
		cout << "Invalid enter!";
		break;
	}
}

int main()
{

	cout << "Enter the number of elements: ";
	int size;
	cin >> size;

	int choice;
	cout << "Choose type of elemets:\n1. Integer\n2. Double\n3. Char\n4. C-string\n";
	cin >> choice;

	CreateTheArray(choice, size);

	return 0;
}