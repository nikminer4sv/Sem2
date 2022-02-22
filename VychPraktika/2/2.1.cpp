#include <iostream>
#include <fstream>
#include <tuple>

using namespace std;

tuple<int *, int> ReadFile(char *fileName)
{

    ifstream in;
    in.open(fileName);

    int *numbers = new int[256];
    int size = 0;

    if (in.is_open())
    {

        int index = 0;

        while (!in.eof())
        {
            in >> numbers[index++];
            size += 1;
        }

        in.close();
    }

    return make_tuple(numbers, size);
}

void FillTheFile()
{
    const unsigned long int SIZE = 100000;
    const int N = 10000;

    srand(time(NULL));
    ofstream fout("numbers.txt", ios::out);

    for (int i = 0; i < SIZE; i++)
    {
        int element = rand() % N;
        fout << element << endl;
    }
}

void ShiftArray(int *numbers, int &size, int startIndex, int shiftSize)
{

    for (int i = size + shiftSize; i > startIndex; i--)
    {
        numbers[i] = numbers[i - shiftSize];
    }

    for (int i = startIndex; i < startIndex + shiftSize; i++)
    {

        numbers[i] = 0;
    }

    size += shiftSize;
}

void AppendNumber(int *numbers, int &size, int number)
{

    if (number > numbers[0])
    {
        ShiftArray(numbers, size, 0, 1);
        numbers[0] = number;
        return;
    }

    for (int i = 0; i < size - 1; i++)
    {

        if (number <= numbers[i] && number >= numbers[i + 1])
        {

            ShiftArray(numbers, size, i + 1, 1);
            numbers[i + 1] = number;
            break;
        }
    }
}

tuple<int *, int> ResultingArray()
{
    int temp;
    int *result = new int[1];
    int resultSize = 1;

    ifstream fin("numbers.txt", ios::in);

    if (fin.is_open())
    {
        while (fin >> temp && temp)
        {
            AppendNumber(result, resultSize, temp);
        }
    }

    resultSize -= 1;

    cout << "Primal data: " << endl
         << endl;

    for (int i = 0; i < resultSize; i++)
        cout << result[i] << " ";

    cout << endl
         << endl;

    int *finalResult = new int[resultSize];
    int finalResultSize = 0;

    for (int i = 0; i < resultSize - 1; i++)
    {

        if (result[i] != result[i + 1])
        {
            finalResult[finalResultSize++] = result[i];
        }
        else
        {
            int temp = result[i];
            while (result[i + 1] == temp)
                i += 1;
            finalResult[finalResultSize++] = temp;
        }
    }

    return make_tuple(finalResult, finalResultSize);
}

void PrintTheArray(int *result, int resultSize)
{
    cout << "Analyzed data: " << endl
         << endl;

    for (int i = 0; i < resultSize; i++)
        cout << result[i] << " ";
}

int main()
{
    srand((unsigned)time(NULL));

    int *result;
    int resultSize;

    FillTheFile();
    tie(result, resultSize) = ResultingArray();

    PrintTheArray(result, resultSize);
}
