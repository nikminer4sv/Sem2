#include <iostream>
#include <cstring>
#include <string>

using namespace std;

bool checkSameSymbols(char *firstWord, char *secondWord)
{
	bool result = true;

	int len = strlen(secondWord);
	for (int i = 0; i < len; i++)
	{
		if (!strchr(firstWord, secondWord[i]))
		{
			result = false;
			break;
		}
	}

	return result;
}

bool checkRepetitions(bool &unicalID, bool &firstQueue, char **separatedWords, char *firstWord)
{
	if (!firstQueue)
	{
		for (int i = 0; i < strlen(separatedWords[i]); i++)
		{
			if (strlen(firstWord) == strlen(separatedWords[i]) && checkSameSymbols(firstWord, separatedWords[i]))
			{
				return false;
			}
		}
		unicalID = true;
	}
	return true;
}

void AddSameWord(char *Word, char **repeatedWords)
{
	strcat(*repeatedWords, Word);
	strcat(*repeatedWords, " ");
}

void FillTheArray(char *line, const int size)
{
	cout << "Enter the string: ";
	cin.getline(line, size);
}

void SeparateTheArray(char *line, char **separatedWords, char **repeatedWords, const char *separators, const int numberOfWords)
{
	char *words = strtok(line, separators);

	for (int i = 0; i < numberOfWords; i++)
	{
		strcpy(separatedWords[i], words);
		words = strtok(NULL, separators);
	}
}

int AnalysisTheSeparetedArray(char **separatedWords, char **repeatedWords, const int numberOfWords)
{
	char *firstWord;
	char *nextWord;
	bool unicalID = true;
	bool firstQueue = true;
	int numberOfRepeatedWords;

	for (int i = 0; i < numberOfWords; i++)
	{
		firstWord = separatedWords[i];

		for (int j = i + 1; j < numberOfWords; j++)
		{
			nextWord = separatedWords[j];

			if (checkRepetitions(unicalID, firstQueue, separatedWords, firstWord) && checkSameSymbols(firstWord, nextWord))
			{

				if (unicalID)
				{
					AddSameWord(firstWord, repeatedWords);
					unicalID = false;
					numberOfRepeatedWords++;
				}

				AddSameWord(nextWord, repeatedWords);
				numberOfRepeatedWords++;
			}
		}
		firstQueue = false;
	}

	return numberOfRepeatedWords;
}

void PrintTheArray(char **repeatedWords, const int numberOfWords)
{
	for (int k = 0; k < numberOfWords; k++)
		cout << repeatedWords[k] << " ";

	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int MAX = 8000;

	char firstLine[MAX];
	const char separators[] = " ,?!:;-.()";

	FillTheArray(firstLine, MAX);

	bool isWord = false;
	int numberOfWords = 0;

	for (int k = 0; k < strlen(firstLine); k++)
	{
		for (int l = 0; l < strlen(separators); l++)
		{
			if (firstLine[k] == separators[l])
			{
				isWord = false;
				numberOfWords++;
			}
			else
			{
				isWord = true;
			}
		}
	}
	isWord = true;
	for (int l = 0; l < strlen(separators); l++)
	{
		if (firstLine[strlen(firstLine) - 1] == separators[l])
			isWord = false;
	}
	if (isWord)
		numberOfWords++;

	char **separatedWords = new char *[numberOfWords];
	for (int i = 0; i < numberOfWords; i++)
		separatedWords[i] = new char[100];

	char **repeatedWords = new char *[numberOfWords];
	for (int i = 0; i < numberOfWords; i++)
		repeatedWords[i] = new char[100];

	SeparateTheArray(firstLine, separatedWords, repeatedWords, separators, numberOfWords);
	int numberOfRepeatedWords = AnalysisTheSeparetedArray(separatedWords, repeatedWords, numberOfWords);
	PrintTheArray(repeatedWords, numberOfRepeatedWords);

	for (int i = 0; i < numberOfWords; i++)
		delete separatedWords[i];
	delete[] separatedWords;

	for (int i = 0; i < numberOfWords; i++)
		delete repeatedWords[i];
	delete[] repeatedWords;

	return 0;
}