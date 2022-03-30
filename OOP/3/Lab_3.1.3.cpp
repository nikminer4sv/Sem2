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

void Write(const string& currentWord, string& newWord)
{
    if (currentWord.size() % 2 != 0)
        return;

    if (Compare(currentWord))
        return;

    if (newWord.length())
        newWord += " ";
    newWord += currentWord;
}

void lexem(const string &str, string &res, string delim = " ;,.:!?-()")
{
    unsigned int wordBegin = 0, wordEnd = 0;

    wordBegin = str.find_first_not_of(delim, wordEnd);
   
    wordEnd = str.find_first_of(delim, wordBegin);

    if (wordEnd >= str.length())
        wordEnd = str.length();

    while (wordBegin < str.length())
    {
        string word = str.substr(wordBegin, wordEnd - wordBegin);
        
        Write(word, res);

        wordBegin = str.find_first_not_of(delim, wordEnd);

        wordEnd = str.find_first_of(delim, wordBegin);
        if (wordEnd >= str.length())
            wordEnd = str.length();
    }
}

int main()
{
    string text;
    getline(cin, text);
    string taskText;
    lexem(text, taskText);
    cout << taskText << endl;

    return 0;
}