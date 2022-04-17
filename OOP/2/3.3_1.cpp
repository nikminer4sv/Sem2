#include <iostream>
#include <list>

const int SIZE = 800;

void Task(std::list<char> &list1, std::list<char> &list2)
{

	if (list1.size() == 0)
		return;

	const int n = 255;
	int g[n]{};

	for (std::list<char>::iterator it = list1.begin(); it != list1.end(); ++it)
	{
		g[*it]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (g[i] > 1)
		{
			list2.push_back(i);
		}
	}
}

int main()
{

	std::list<char> list1;
	std::list<char> list2;

	char line[SIZE];

	std::cout << "Enter the string: " << std::endl;
	std::cin.getline(line, SIZE);

	int i = 0;
	while (line[i] != '\0')
	{
		list1.push_back(line[i]);
		i++;
	}

	Task(list1, list2);

	for (auto c : list2)
		std::cout << c << " ";

	std::cout << std::endl;

	return 0;
}