#include <iostream>

using namespace std;

struct InvalidListSize : public exception
{

	const char *what() const throw()
	{
		return "List size must be more or equal to 2 and be a multiple of two!";
	}
};

struct Node
{

	double Data;
	Node *Next;
	Node *Prev;

	Node()
	{
		Next = nullptr;
		Prev = nullptr;
	}
};

class DoublyLinkedList
{
private:
	Node *Head;

public:
	int Size;

public:
	DoublyLinkedList()
	{

		Head = nullptr;
		Size = 0;
	}

	double Get(int Index)
	{

		if (Index > Size || Index < 0)
			throw invalid_argument("Invalid index");

		Node *Temp = Head;

		if (Index >= Size / 2 + 1)
		{

			for (int j = Size - 1; j > Index - 1; j--)
				Temp = Temp->Prev;
		}
		else
		{

			for (int i = 0; i < Index; i++)
				Temp = Temp->Next;
		}

		return Temp->Data;
	}

	void Add(const double Value)
	{

		Node *NewNode = new Node;
		NewNode->Data = Value;

		if (Head == nullptr)
		{

			Head = NewNode;
		}
		else
		{

			if (Size == 1)
			{

				Head->Next = NewNode;
				Head->Prev = NewNode;
				NewNode->Prev = Head;
				NewNode->Next = Head;
			}
			else
			{

				Node *temp = Head->Prev;
				temp->Next = NewNode;
				NewNode->Prev = temp;
				NewNode->Next = Head;
				Head->Prev = NewNode;
			}
		}

		Size += 1;
	}

	bool Remove(int Index)
	{

		if (Index > Size - 1 || Index < 0)
			return false;

		if (Index == 0)
		{

			Head->Prev->Next = Head->Next;
			Head->Next->Prev = Head->Prev;
			Head = Head->Next;
		}
		else
		{

			Node *Temp = Head;

			for (int i = 0; i < Index - 1; i++)
				Temp = Temp->Next;

			Temp->Next->Next->Prev = Temp;
			Temp->Next = Temp->Next->Next;
		}

		Size -= 1;

		return true;
	}

	~DoublyLinkedList()
	{

		Node *current = Head;

		while (current->Next != Head)
		{
			Node *next = current->Next;
			delete current;
			current = next;
		}

		Head = nullptr;
	}
};

void PrintList(DoublyLinkedList &list)
{

	for (int i = 0; i < list.Size; i++)
		cout << list.Get(i) << " ";

	cout << endl;
}

double Task(DoublyLinkedList &list)
{

	if (list.Size < 2 || list.Size % 2)
		throw InvalidListSize();

	double result = list.Get(0) + list.Get(list.Size - 1);

	for (int i = 1; i < list.Size; i++)
	{

		double temp = list.Get(i) + list.Get(list.Size - i - 1);

		result *= temp;
	}

	return result;
}

int main()
{
	DoublyLinkedList list;

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
		list.Add(temp);
	}

	cout << endl
		 << "Result is: " << endl
		 << Task(list) << endl;

	cout << endl
		 << "Doubly linked list: " << endl;
	PrintList(list);
	cout << endl;
}