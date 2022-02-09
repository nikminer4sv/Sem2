#include <iostream>
using namespace std;

class SameWords
{
public:
	SameWords();
	SameWords(char* Text);
	~SameWords();

	void printSameWords()
	{
		for (int i = 0; i < strlen(newText); i++) cout << newText[i];
		cout << endl;
	}

private:
	char* Text;
	char* firstWord;
	char* nextWord;
	char** DB;
	bool unicalID = true;
	bool firstQueue = true;

	int sizeDB = 0;

	char newText[255];
	int iteratorNewText = 0;

	void addSameWord(char* Word)
	{
		for (int i = 0; iteratorNewText < 255 && i < strlen(Word); iteratorNewText++, i++)
		{
			newText[iteratorNewText] = Word[i];
		}
		newText[iteratorNewText++] = ' ';
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
		bool isIdentical = false;
		for (int symbolPositionFirstWord = 0; symbolPositionFirstWord < strlen(firstWord); )
		{
			for (int symbolPositionSecondWord = 0; symbolPositionSecondWord < strlen(secondWord); symbolPositionSecondWord++)
			{
				if (firstWord[symbolPositionFirstWord] == secondWord[symbolPositionSecondWord])
				{
					if (findNumberIdenticalSymbol(firstWord, symbolPositionFirstWord) == findNumberIdenticalSymbol(secondWord, symbolPositionSecondWord))
					{
						isIdentical = true;
						symbolPositionFirstWord++;
						break;
					}
					else return false;
				}
				else isIdentical = false;
			}
			if (!isIdentical) return false;
		}
		if (isIdentical) return true;
	}

	bool checkRepetitions()
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


	void findSameWords(char* Text)
	{
		char* ptr;
		char* pch = NULL;
		const char* delimiter = " .,?():-";
		sizeDB = 0;

		ptr = strtok_s(Text, delimiter, &pch);

		for (int i = 0; ptr != NULL; i++) //fill DB
		{
			DB[i] = new char[strlen(ptr)];
			DB[i][strlen(ptr)] = '\0';
			for (int j = 0; j < strlen(DB[i]); j++)
			{
				DB[i][j] = ptr[j];
			}
			sizeDB++;
			ptr = strtok_s(NULL, delimiter, &pch);
		}

		for (int i = 0; i < sizeDB; i++) // i+++ add last
		{
			firstWord = DB[i];

			for (int j = i + 1; j < sizeDB; j++)
			{
				nextWord = DB[j];

				if (checkRepetitions() && strlen(firstWord) == strlen(nextWord) && checkSameSymbols(firstWord, nextWord)) {

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
};

SameWords::SameWords(char* Text)
{
	if (Text == NULL) cout << "Text is empty" << endl;

	DB = new char* [255];
	this->Text = Text;

	findSameWords(this->Text);
}

SameWords::SameWords()
{
	cout << "SameWords <name> (<string> Text)" << endl;
}

SameWords::~SameWords()
{
	for (int i = 0; i < sizeDB; i++)
	{
		DB[i] = NULL;
	}
	for (int i = 0; i < sizeDB; i++)
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

int main()
{
	cout << "Enter the text: ";
	char Text[255];
	gets_s(Text);

	SameWords sameword(Text);
	sameword.printSameWords();

	return 0;
}
