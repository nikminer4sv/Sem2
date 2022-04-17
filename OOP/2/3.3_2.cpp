#include <iostream>
#include <list>

double Task(std::list<double> &list)
{

	if (list.size() < 2 || list.size() % 2)
		throw std::invalid_argument("invalid arguments");

	std::list<double>::iterator it = list.begin();

	double result = *it + (*it + (list.size() - 1));

	for (int i = 1; i < list.size(); i++)
	{
		result *= (*it + i) + (*it + (list.size() - i - 1));
	}

	return result;
}

int main()
{
	std::list<double> taskList;

	std::cout
		<< "Enter the size of the doubly linked list: " << std::endl;
	int size;
	std::cin >> size;
	while (size % 2 != 0)
	{
		std::cout << "Invalid enter!" << std::endl;
		std::cin >> size;
	}

	for (int k = 0; k < size; k++)
	{
		double temp;
		std::cin >> temp;
		taskList.push_back(temp);
	}

	std::cout << std::endl
			  << "Result is: " << std::endl
			  << Task(taskList) << std::endl;

	return 0;
}