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

void Merge(char** A, int first, int last) {
    int middle, start, final, j, size = last + 1;
    auto *mas = new char*[size];
    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    for (j = first; j <= last; j++)
        if ((start <= middle) && ((final > last) || (strcmp(A[start],A[final])<0))) {
            mas[j] = A[start];
            start++;
        } else {
            mas[j] = A[final];
            final++;
        }
    for (j = first; j <= last; j++)
        A[j] = mas[j];
    delete[] mas;
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

void MergeSort(char **A, int first, int last) {
    if (first < last) {
        MergeSort(A, first, (first + last) / 2);
        MergeSort(A, (first + last) / 2 + 1, last);
        Merge(A, first, last);
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

            delete[] array;
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

            delete[] array;
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

            delete[] array;
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

            for (int i = 0; i < size; i++)
                delete array[i];
            delete[] array;
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