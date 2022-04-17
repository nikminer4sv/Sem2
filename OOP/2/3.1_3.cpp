#include <iostream>
#include <string>
#include <sstream>

const char separators[] = " ,?!:;-.()";

std::string SearchTheLastWord(std::string &line)
{
	for (auto c : separators)
		if (line[line.length() - 1] == c)
		{
			line.erase(line.length() - 1);
			break;
		}

	std::string lastWord = line.substr(line.find_last_of(separators) + 1);

	return lastWord;
}

void PrintAllAnagrams(const std::string &line, const std::string &lastWord)
{
	std::stringstream strm(line);

	std::string word;
	while (strm >> word)
		if (word.find_last_not_of(lastWord) == std::string::npos)
			std::cout << word << std::endl;
}

int main()
{
	std::cout << "Enter the string: " << std::endl;
	std::string line;
	std::getline(std::cin, line);

	std::string lastWord = SearchTheLastWord(line);

	PrintAllAnagrams(line, lastWord);

	return 0;
}