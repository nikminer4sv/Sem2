#include <iostream>

using namespace std;
#define COUNT 10

struct Node
{

	int Value = 0;
	Node *Left = nullptr;
	Node *Right = nullptr;

	Node() = default;

	Node(int Value)
	{
		this->Value = Value;
	}
};

class BinarySearchTree
{
private:
	Node *Root = nullptr;

private:
	void Destroy(Node *node)
	{
		if (node)
		{
			Destroy(node->Left);
			Destroy(node->Right);
			delete node;
		}
	}

public:
	BinarySearchTree() { Root = nullptr; }

	void Add(int Value)
	{
		Add(new Node(Value));
	}

	void Add(Node *NewNode)
	{
		if (Root == nullptr)
		{
			Root = NewNode;
			return;
		}

		Node *TempNode = Root;
		while (true)
		{
			if (TempNode->Value < NewNode->Value)
			{
				if (TempNode->Right != nullptr)
				{
					TempNode = TempNode->Right;
				}
				else
				{
					TempNode->Right = NewNode;
					break;
				}
			}
			else
			{
				if (TempNode->Left != nullptr)
				{
					TempNode = TempNode->Left;
				}
				else
				{
					TempNode->Left = NewNode;
					break;
				}
			}
		}
	}

	Node *GetRoot() { return Root; }

	int getLeafCount(Node *Root)
	{
		if (Root == NULL)
			return 0;
		if (Root->Left == NULL && Root->Right == NULL)
			return 1;
		else
			return getLeafCount(Root->Left) +
				   getLeafCount(Root->Right);
	}

	~BinarySearchTree()
	{
		Destroy(Root);
	}
};

void print2DUtil(Node *root, int space)
{
	if (root == NULL)
		return;

	space += COUNT;

	print2DUtil(root->Right, space);

	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->Value << "\n";

	print2DUtil(root->Left, space);
}

int main()
{

	BinarySearchTree tree;

	cout << "Enter the numbers of elements: " << endl;
	int size;
	cin >> size;

	cout << endl
		 << endl;

	for (int k = 0; k < size; k++)
	{
		int temp;
		cin >> temp;
		tree.Add(temp);
	}

	cout << endl
		 << endl;

	print2DUtil(tree.GetRoot(), 0);
	int leaves = tree.getLeafCount(tree.GetRoot());
	cout << "Number of leaves: " << leaves << endl;
}