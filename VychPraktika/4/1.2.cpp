#include <iostream>
#include <vector>
#include <string>

using namespace std;

int GetArraySize(char Array[]);
void ChangeSeparatorToVoid(char Array[], int ArraySize);
int DeleteFirstAndLastVoids(char Array[], int ArraySize);
void LineToWords(char Array[], int ArraySize, vector<string>& Words, int Index);
int DifferentWordsNumber(vector<string>& Words);
void Rate(vector<string>& Words, string **WordRate);
void Print(string **WordRate, int Number);

int main() 
{   
    cout << "Enter the text you want to print: \n";
    char *Array = new char[255];
    cin.getline(Array, 255); 

    int ArraySize = GetArraySize(Array);
    ChangeSeparatorToVoid(Array, ArraySize);
    ArraySize = DeleteFirstAndLastVoids(Array, ArraySize);

    int Index = 0;
    vector<string> Words;
    LineToWords(Array, ArraySize, Words, Index);

    int Number = DifferentWordsNumber(Words);
    string **WordRate = new string*[Number];
    for (int i = 0; i < Number; i++)
	{
		WordRate[i] = new string[2];
	}

    Rate(Words, WordRate);
    Print(WordRate, Number);
}

int GetArraySize(char Array[]) 
{
    int Size = 0;

    while (Array[Size] != '\0')
        Size += 1;

    return Size;
}

void ChangeSeparatorToVoid(char Array[], int ArraySize) 
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
}

int DeleteFirstAndLastVoids(char Array[], int ArraySize) 
{
    int First = 0;

    while (Array[First] == ' ') 
    {
        for (int i = 0; i < ArraySize; i++)
        {
            Array[i] = Array[i + 1];
        }
        ArraySize--;
    }

    while (Array[ArraySize - 1] == ' ')
    {
        ArraySize--;
    }
    Array[ArraySize] = '\0';

    return ArraySize;
}

void LineToWords(char Array[], int ArraySize, vector<string>& Words, int Index)
{
    string Word = "";

    if (Index < ArraySize)
    {
        while ((Array[Index] != ' ') && (Index < ArraySize))
        {
            Word += Array[Index];
            Index++;
        }
        Words.push_back(Word);

        if (Array[Index + 1] == ' ')
        {
            while (Array[Index + 1] == ' ')
            {
                Index++;
            }
        }
        Index++;
        LineToWords(Array, ArraySize, Words, Index);
    }
}

int DifferentWordsNumber(vector<string>& Words)
{
    int Counter = 0;

    for (int i = 0; i < Words.size(); i++)
    {
        bool Flag = true;

        for (int Before = 0; Before < i; Before++)
        {
            if (Words[Before] == Words[i])
            {
                Flag = false;
            }
        }
        if (Flag)
        {
            Counter++;
        }
    }
    
    return Counter;
}

void Rate(vector<string>& Words, string **WordRate)
{
    int Number = 0;

    for (int i = 0; i < Words.size(); i++)
    {
        int Counter = 1;
        bool Flag = true;
        
        for (int After = i + 1; After < Words.size(); After++)
        {
            if (Words[i] == Words[After])
            {
                Counter++;
            }
        }
        for (int Before = 0; Before < i; Before++)
        {
            if (Words[Before] == Words[i])
            {
                Flag = false;
            }
        }
        if (Flag)
        {
            WordRate[Number][0] = Words[i];
            WordRate[Number++][1] = to_string(Counter);
        }
    }
}

void Print(string **WordRate, int Number)
{
    cout << "\n\nRate of words:\n\n";

    for (int i = 0; i < Number; i++)
    {
        cout << "  " << WordRate[i][0] << " - " << WordRate[i][1] << endl;
    }

    cout << "\n\n";
}