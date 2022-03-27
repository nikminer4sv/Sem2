#include <iostream>
#include "Header-files/List.h"
#include "Header-files/DoublyLinkedList.h"

using namespace std;

double Task(DoublyLinkedList<double> &list)
{

	if (list.GetSize() < 2 || list.GetSize() % 2)
		throw invalid_argument("invalid arguments");

	double result = list[0] + list[list.GetSize() - 1];

	for (int i = 1; i < list.GetSize(); i++)
	{

		double temp = list[i] + list[list.GetSize() - i - 1];

		result *= temp;
	}

	return result;
}

int main()
{
	DoublyLinkedList<double> list;

	cout << "Enter the size of the doubly linked list: " << endl;
	int size;
	cin >> size;
	while (size % 2 != 0)
	{
		cout << "Invalid enter!" << endl;
		cin >> size;
	}

	for (int k = 0; k < size; k++)
	{
		double temp;
		cin >> temp;
		list.Append(temp);
	}

	cout << endl
		 << "Result is: " << endl
		 << Task(list) << endl;

	return 0;
}