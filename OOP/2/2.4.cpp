#include <iostream>
#include "Header-files/String.h"

int main()
{
	String testString;
	String testStrin2;

	std::cout << "Enter the first string: " << std::endl;
	std::cin >> testString;
	std::cout << testString << std::endl;

	std::cout << "Enter the second string: " << std::endl;
	std::cin >> testStrin2;
	std::cout << testStrin2 << std::endl;

	testString.Task(testStrin2);
	std::cout << "The first string after erasing: " << std::endl
			  << testString << std::endl;

	return 0;
}