#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SameWords
{
public:
	SameWords(char* Text)
	{
		if (Text == NULL) 
			cout << "Text is empty" << endl;
		else
			this->Text = Text;
		
	}

	~SameWords()
	{
		for (int i = 0; i < sizeDBContainingWords; i++)
		{
			DB[i] = NULL;
		}
		for (int i = 0; i < sizeDBContainingWords; i++)
		{
			delete[] DB[i];
		}
		DB = NULL;
		Text = NULL;
		firstWord = NULL;
		nextWord = NULL;
		delete[] DB;
		delete Text;
		delete firstWord;
		delete nextWord;

	}

	void printSameWords()
	{
		for (int i = 0; i < strlen(newText); i++) 
			cout << newText[i];
		cout << endl;
	}

	void findSameWords()
	{
		char* ptr;
		char* pch = NULL;
		const char* delimiter = " .,?():-";
		sizeDBContainingWords = 0;

		ptr = strtok_s(Text, delimiter, &pch);
		for (int i = 0; ptr != NULL; i++) //fill DB
		{
			DB[i] = ptr;
			sizeDBContainingWords++;
			ptr = strtok_s(NULL, delimiter, &pch);
		}

		bool unicalID = true;
		bool firstQueue = true;

		for (int i = 0; i < sizeDBContainingWords; i++) // i+++ add last
		{
			firstWord = DB[i];

			for (int j = i + 1; j < sizeDBContainingWords; j++)
			{
				nextWord = DB[j];

				if (checkRepetitions(unicalID, firstQueue, DB, firstWord) && strlen(firstWord) == strlen(nextWord) && checkSameSymbols(firstWord, nextWord)) {

					if (unicalID)
					{
						addSameWord(firstWord);
						unicalID = false;
					}

					addSameWord(nextWord);
				}
			}
			firstQueue = false;
		}
	}

private:
	char* Text;
	char* firstWord;
	char* nextWord;
	char** DB = new char* [255];

	int sizeDBContainingWords = 0;
	char newText[255]{};

	void addSameWord(char* Word)
	{
		strcat(newText, Word);
		strcat(newText, " ");
	}

	int findNumberIdenticalSymbol(char* word, int startPosition)
	{
		int numberIdenticalSymbol = 0;
		for (int i = 0; i < strlen(word); i++)
			if (word[startPosition] == word[i]) numberIdenticalSymbol++;

		return numberIdenticalSymbol;
	}

	bool checkSameSymbols(char* firstWord, char* secondWord)
	{
		bool result = true;

		int len = strlen(firstWord);
		for (int i = 0; i < len; i++) {
			if (!strchr(secondWord, firstWord[i])) {
				result = false;
				break;
			}
		}

		return result;
	}

	bool checkRepetitions(bool &unicalID, bool &firstQueue, char** DB, char *firstWord)
	{
		if (!firstQueue) // checking for repetition of symbols
		{
			for (int HELPME = 0; HELPME < strlen(DB[HELPME]); HELPME++)
			{
				if (strlen(firstWord) == strlen(DB[HELPME]) && checkSameSymbols(firstWord, DB[HELPME])) /* need to check for identical symbols */
				{
					return false;
				}
			}
			unicalID = true;
		}
		return true;
	}
};


int main()
{
	cout << "Enter the text: ";
	char Text[255];
	gets_s(Text);

	SameWords sameword(Text);
	sameword.findSameWords();
	sameword.printSameWords();

	return 0;
}
