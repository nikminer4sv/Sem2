#include <iostream>
#include <fstream>


using namespace std;

void CombSort(int values[], int lenD) 
{
    const double factor = 1.247; // Фактор уменьшения
    double step = lenD - 1;

    while (step >= 1) 
    {
        for (int i = 0; i + step < lenD; ++i) 
        {
            if (values[i] > values[int(i + step)]) 
            {
                swap(values[i], values[int(i + step)]);
            }
        }

        step /= factor;
    }
}

int main() 
{
    ifstream in;
    in.open("numbers1.txt");
    int n = 1;
    int k = 0;
    int *array = new int[n];
    if (in.is_open())
    {
        while (!in.eof())
        {
            in >> k;
            array[n - 1] = k;
            int* array1 = new int[n];
            for (int i = 0; i < n; i++)
            {
                array1[i] = array[i];
            }
            delete[] array;
            n++;
            array = new int[n];
            for (int i = 0; i < n - 1 ; i++)
            {
                array[i] = array1[i];
            }
            delete[] array1;
        }
    }

    int *array1 = new int[n - 1];
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool Flag = true;
        for (int Before = 0; Before < i; Before++)
        {
            if (array[Before] == array[i])
            {
                Flag = false;
            }
        }
        if (Flag)
        {
            array1[count++] = array[i];
        }
    }

    CombSort(array1, count);

    in.close();
    for (int i = 1; i < count; i++)
    {
        cout << array1[i - 1] << "\t";
        if ((i % 20) == 0)
        {
            cout << endl;
        }
    }
    cout << endl << "End of program";
    return 0;
}
