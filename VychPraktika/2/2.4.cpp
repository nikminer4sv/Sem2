#include <iostream>
#include <cstring>

using namespace std;

struct Node
{

	char Data;
	Node *Next;

	Node() { Next = nullptr; }
};

class CharList
{
private:
	Node *Head;

public:
	int Size;

public:
	char &operator[](const int index);

	CharList()
	{

		Head = nullptr;
		Size = 0;
	}

	void Add(const char &Symbol)
	{

		Size += 1;

		Node *NewNode = new Node;
		NewNode->Data = Symbol;

		if (Head == nullptr)
		{

			Head = NewNode;
		}
		else
		{

			Node *temp = Head;

			while (temp->Next != nullptr)
				temp = temp->Next;

			temp->Next = NewNode;
		}
	}

	void Add(char *text)
	{

		for (int i = 0; i < strlen(text); i++)
			Add(text[i]);
	}

	bool Remove(int Index)
	{

		if (Index > Size - 1 || Index < 0)
			return false;

		if (Index == 0)
		{

			Head = Head->Next;
		}
		else
		{

			Node *Temp = Head;

			for (int i = 0; i < Index - 1; i++)
				Temp = Temp->Next;

			Temp->Next = Temp->Next->Next;
		}

		Size -= 1;

		return true;
	}

	~CharList()
	{

		Node *current = Head;

		while (current != nullptr)
		{
			Node *next = current->Next;
			delete current;
			current = next;
		}

		Head = nullptr;
	}
};

char &CharList::operator[](const int index)
{
	if (index > Size - 1)
		throw invalid_argument("Accessing element out of bounds.");
	int counter = 0;

	Node *current = this->Head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->Data;
		}
		current = current->Next;
		counter++;
	}
}

void PrintList(CharList &list)
{

	for (int i = 0; i < list.Size; i++)
		cout << list[i];

	cout << endl;
}

void Task(CharList &list1, CharList &list2)
{
    if (list1.Size == 0)
        return;

    const int n = 255;
	int g[n]{};

	for (int i = 0; i < list1.Size; i++)
	{
		g[list1[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (g[i] > 1)
		{
			list2.Add( i);
		}
	}
}

int main()
{

	CharList list1;
	CharList list2;

	const int SIZE = 80;

	char line[SIZE];

	cout << "Enter the string: " << endl;
	cin.getline(line, SIZE);

	list1.Add(line);

	Task(list1, list2);

	PrintList(list2);
	cout << list2.Size << endl;
}