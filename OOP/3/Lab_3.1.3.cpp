#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool Compare(const string& word)
{
    int size = word.size();
    for (int i = 0; i < word.size() / 2; i++)
    {
        if (word[i] != word[--size])
            return false;       
    }
    return true;
}

void Write(string& currentWord, string& newWord)
{   
    if (currentWord.size() % 2 != 0)
        return;
    
    if (Compare(currentWord))
        return;

    newWord += currentWord;
    newWord += ' ';
}

void charToString(const char* pch, string& temp)
{
    int size = 0;
    for (size_t i = 0; pch[i] != '\0'; i++)
        size++;
    
    for (int i = 0; i < size; i++)
        temp += pch[i];
}

void Task(string& currentText, string& newText)
{
    char* hz = new char [currentText.size()];

    for (int i = 0; i < currentText.size(); i++)
        hz[i] = currentText[i];    
    hz[currentText.size()] = '\0';

    const char seps[] = " ;,.:!?-()";

    char* pch = strtok (hz, seps);
    while (pch != NULL)                        
    {
        string temp;
        charToString(pch, temp);
        Write(temp, newText);
        pch = strtok(NULL, seps);
    }

    delete[] hz;
    delete[] pch;
}


int main()
{
    string text;
    getline(cin, text);
    string taskText;
    Task(text, taskText);
    cout << taskText << endl;

    return 0;
}