#include <iostream>
#include <string>

std::string IntegerToRoman(int numberInArabic)
{

	std::string strRomans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

	std::string resultString = "";

	for (int i = 0; i < std::size(values); i++)
	{
		while (numberInArabic - values[i] >= 0)
		{
			resultString += strRomans[i];
			numberInArabic -= values[i];
		}
	}

	return resultString;
}

int main()
{
	std::cout << "Enter the desired number in arabic to convert it in roman: " << std::endl;
	int numberInArabic;
	std::cin >> numberInArabic;

	std::string numberInRoman = IntegerToRoman(numberInArabic);
	std::cout << "Your number in roman: " << numberInRoman << std::endl;

	return 0;
}