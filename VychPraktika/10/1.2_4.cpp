#include <iostream>
#include <cstring>

using namespace std;

#define LEN_MAX (255)

// не использовать std::string и std::vector
// вместо велосипедов использовать strtok, strdup, strcpy, strlen

int Trim(char Array[], int ArraySize);
char** Split(char* str, int& Count);
bool WordsComparison(char* str1, char* str2);
int DifferentWordsNumber(char** Words, int Count);
char** Rate(char** Words, int Count);
void Print(char** WordRate, int Number);

int main() 
{   
    cout << "Enter the text you want to print: \n";
    char *Array = new char[LEN_MAX];
    cin.getline(Array, LEN_MAX); 

///
    
    int ArraySize = strlen(Array);
    ArraySize = Trim(Array, ArraySize);

    int Count = 0;
    char** Words = Split(Array, Count);
    
    int Number = DifferentWordsNumber(Words, Count);
    
    char** WordRate = Rate(Words, Count);
    Print(WordRate, Number);
}

int Trim(char Array[], int ArraySize) 
{
    while (Array[ArraySize - 1] == ' ')
    {
        ArraySize--;
    }
    Array[ArraySize] = '\0';

    int First = 0;
    while (Array[First] == ' ') 
    {
        First++;
        for (int i = 0; i < ArraySize; i++)
        {
            Array[i] = Array[i + 1];
        }
        ArraySize--;
    }
    return ArraySize;
}

char** Split(char* str, int& Count)
{
    char Separartors[] = " ,.!?;:()-";

    char* Word = strtok(strdup(str), Separartors);
    while (Word)
    {
        Count++;
        Word = strtok(nullptr, Separartors);
    }

    char** Result = new char*[Count];
    int i = 0;

    Word = strtok(strdup(str), Separartors);
    while (Word)
    {
        Result[i] = strdup(Word);
        Word = strtok(nullptr, Separartors);
        i++;
    }
    
    return Result;
}

bool WordsComparison(char* str1, char* str2)
{
    bool Flag = true;

    if (strlen(str1) == strlen(str2))
    {
        unsigned int Counter1 = 0;
        for (unsigned int j = 0; j < strlen(str1); j++)
        {
            if (str1[j] == str2[j])
            {
                Counter1++;
            }
        }
        if (Counter1 != strlen(str1))
        {
            Flag = false;
        }
    }

    return Flag;
}

int DifferentWordsNumber(char** Words, int Count)
{
    int Counter = 0;

    for (int i = 0; i < Count; i++)
    {
        bool Flag = true;

        for (int Before = 0; Before < i; Before++)
        {
            if (WordsComparison(Words[i],Words[Before]))
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

char** Rate(char** Words, int Count)
{
    int Number = 0;
    char** Result = new char*[Count];

    for (int i = 0; i < Count; i++)
    {
        int Counter = 1;
        bool Flag = true;
        
        for (int After = i + 1; After < Count; After++)
        {
            if (WordsComparison(Words[i],Words[After]))
            {
                Counter++;
            }
        }
        for (int Before = 0; Before < i; Before++)
        {
            if (WordsComparison(Words[i],Words[Before]))
            {
                Flag = false;
            }
        }
        if (Flag)
        {
            char num[] = "", str[LEN_MAX] = "", str1[] = " - ";
            sprintf(num, "%d",Counter);
            strcat_s(str, Words[Number]);
            strcat_s(str, str1);
            strcat_s(str, num);
            Result[Number] = str;
            //cout << Result[Number] << endl;
            Number++; //????
        }
    }


    //cout << Number << endl << Result[0] << endl << Result[1];
    return Result;
}

void Print(char** WordRate, int Number)
{
    cout << "\n\nRate of words:\n\n";

    for (int i = 0; i < Number; i++)
    {
        cout << "  " << WordRate[i] << endl;
    }

    cout << "\n\n";
}