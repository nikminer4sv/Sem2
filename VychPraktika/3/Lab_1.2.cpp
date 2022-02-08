#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SameWords
{
public:
	SameWords();
	SameWords(string Text);
	~SameWords();

	void getSameWords() 
	{
		for (int i = 0; i < newText.size(); i++) cout << newText[i] << " ";
		cout << endl;
	}

private:
	string Text;
	vector<char> firstWord;
	vector<char> nextWord;
	bool unicalID = true;
	bool firstQueue = true;

	vector<string> newText;
	
	void addSameWord(vector<char>& Word)
	{
		string txt;
		for (int i = 0; i < Word.size(); i++) txt += Word[i];
		newText.push_back(txt);	
	}

	int findNumberIdenticalSymbol(vector<char> word, int startPosition)
	{
		int numberIdenticalSymbol = 0;
		for (int i = 0; i < word.size(); i++)
			if (word[startPosition] == word[i]) numberIdenticalSymbol++;

		return numberIdenticalSymbol;
	}

	bool checkSameSymbols(vector<char> firstWord, vector<char> secondWord)
	{
		bool isIdentical = false;
		for (int symbolPositionFirstWord = 0; symbolPositionFirstWord < firstWord.size(); )
		{
			for (int symbolPositionSecondWord = 0; symbolPositionSecondWord < secondWord.size(); symbolPositionSecondWord++)
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
		if (!newText.empty() && !firstQueue) // checking for repetition of symbols
		{
			string charToString;
			for (int HELPME = 0; HELPME < firstWord.size(); HELPME++) charToString += firstWord[HELPME];
		
			for (int HELPME = 0; HELPME < newText.size(); HELPME++)
			{
				if (charToString.size() == newText[HELPME].size() /* need to check for identical symbols */)
				{
					return false;
				}

			}
			unicalID = true;
		}
		return true;
	}


	void findSameWords(string& Text)
	{
		for (int i = 0; i < Text.size(); i++)
		{
			if (Text[i] != ' ' && Text[i] != '\0' && Text[i] != '.' && Text[i] != ',' 
				&& Text[i] != ':' && Text[i] != ';' && Text[i] != '!' && Text[i] != '?' 
				&& Text[i] != '-' && Text[i] != '(' && Text[i] != ')')
			{
				firstWord.push_back(Text[i]);			// first word for compare 	
				continue;
			}
			else
			{
				int j = i;
				j++;
				while (true) //viewing the all text
				{
					for ( ; Text[j] != ' ' && Text[j] != '\0' && Text[j] != '.' && Text[j] != ',' 
						 && Text[j] != ':' && Text[j] != ';' && Text[j] != '!' && Text[j] != '?' 
						 && Text[j] != '-' && Text[j] != '(' && Text[j] != ')'; j++) //getting the next word
					{
						nextWord.push_back(Text[j]);
					}
					
					if (checkRepetitions())
					{
						if (firstWord.size() == nextWord.size()) 
						{
							if (checkSameSymbols(firstWord, nextWord) /*checking for identical symbols*/) //move this if to the top if
							{
								if (unicalID)
								{
									addSameWord(firstWord);
									unicalID = false;
								}

								addSameWord(nextWord);
							}	
						}
					}
					if (!nextWord.empty()) nextWord.clear();
					if (Text[j] == '\0') break;
					j++;
				}	
			}
			if (!firstWord.empty()) firstWord.clear();

			firstQueue = false;
		}

	}
};

SameWords::SameWords(string Text)
{
	if (Text.size() == 0)
	{
		cout << "Text is empty" << endl;
	}
	else
	{
		this->Text = Text;
		findSameWords(this->Text);
	}
	
}

SameWords::SameWords()
{
	cout << "SameWords <name> (<string> Text)" << endl;
}

SameWords::~SameWords()
{
}


int main() 
{	
	cout << "Enter the text: ";
	string Text;
	getline(cin, Text);

	SameWords samewordcheck;
	SameWords sameword(Text);
	sameword.getSameWords();
	
	return 0;
}