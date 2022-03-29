#include <iostream>
#include <vector>
#include <string>

using namespace std;

void DeleteSeparators(string& Array, int& ArraySize);
void Task(string& Array, int ArraySize);
bool CheckWord(string& Array, int prev_position, int position);
void CopyWord(string& Array, string& Array1, int prev_position, int position);

int main()
{
    string Array;
    getline(cin, Array);
    int ArraySize = Array.length();

    DeleteSeparators(Array, ArraySize);
    Task(Array, ArraySize);
}

void DeleteSeparators(string& Array, int& ArraySize)
{
    for (int i = 0; i < ArraySize; i++)
    {
        if (Array[i] == ' ' || Array[i] == '?' ||
            Array[i] == ',' || Array[i] == '.' ||
            Array[i] == ':' || Array[i] == ';' ||
            Array[i] == '!' || Array[i] == '-' ||
            Array[i] == '(' || Array[i] == ')')
        {
            Array[i] = ' ';
        }
    }
    while (Array[ArraySize - 1] == ' ')
    {
        ArraySize--;
    }
    while (Array[0] == ' ')
    {
        for (size_t i = 0; i < ArraySize; i++)
        {
            Array[i] = Array[i + 1];
        }
    }
}

void Task(string& Array, int ArraySize)
{
    int position = 0, prev_position = ArraySize;
    string Array1;
    for (int i = 0; i < ArraySize + 1; i++)
    {
        if ((Array[i] == ' ' || Array[i] == '\0') && abs(position - prev_position) > 1)
        {
            prev_position = position;
            position = i;
            if (CheckWord(Array, prev_position, position))
            {
                CopyWord(Array, Array1, prev_position, position);
            }
        }
    }

    cout << Array1;
}

bool CheckWord(string& Array, int prev_position, int position)
{
    for (size_t i = prev_position; i < position - 1; i++)
    {
        for (size_t j = i + 1; j < position; j++)
        {
            if (Array[i] == Array[j])
            {
                return true;
            }
        }
    }

    return false;
}

void CopyWord(string& Array, string& Array1, int prev_position, int position)
{
    int j = Array1.length();
    for (size_t i = prev_position; i < position; i++)
    {
        Array1.push_back(Array[i]);
        j++;
    }
    Array1[j] = ' ';
}