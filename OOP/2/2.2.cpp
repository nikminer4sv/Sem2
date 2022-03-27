#include <iostream>
#include "Header-files/List.h"

using namespace std;

const int SIZE = 800;

void Task(List<char> &list1, List<char> &list2)
{
	if (list1.GetSize() == 0)
		return;

	const int n = 255;
	int g[n]{};

	for (int i = 0; i < list1.GetSize(); i++)
	{
		g[list1[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (g[i] > 1)
		{
			list2.Append(i);
		}
	}
}

int main()
{

	List<char> list1;
	List<char> list2;

	char line[SIZE];

	cout << "Enter the string: " << endl;
	cin.getline(line, SIZE);

	int i = 0;
	while (line[i] != '\0')
	{
		list1.Append(line[i]);
		i++;
	}

	Task(list1, list2);

	cout << list2 << endl;
}