#include <iostream>

using namespace std;
#define COUNT 10

template <typename T>
class BinarySearchTree
{
private:
	struct Node
	{

		T Value = 0;
		Node *Left = nullptr;
		Node *Right = nullptr;

		Node() = default;

		Node(T Value)
		{
			this->Value = Value;
		}
	};

	Node *Root = nullptr;

private:
	void PrintImpl(Node *TempNode)
	{

		cout << TempNode->Value << " ";

		if (TempNode->Left != nullptr)
			PrintImpl(TempNode->Left);

		if (TempNode->Right != nullptr)
			PrintImpl(TempNode->Right);
	}

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

	BinarySearchTree(const BinarySearchTree &tree)
	{
		Node *head = new Node(tree.Root->Value);
		Copy(head);
	}

	void Clear()
	{
		Destroy(Root);
		Root = nullptr;
	}

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

	void Copy(Node *element)
	{

		if (element == nullptr)
			return;

		this->Add(element->Value);

		Copy(element->Left);
		Copy(element->Right);
	}

	void Add(const T &Value)
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

	void Print()
	{
		if (Root != nullptr)
			PrintImpl(Root);
	}

	Node *GetRoot() { return Root; }

	Node *TaskImpl(Node *root)
	{

		if (root == nullptr)
			return nullptr;

		if (root->Left == nullptr && root->Right == nullptr)
		{
			delete root;
			return nullptr;
		}

		root->Left = TaskImpl(root->Left);
		root->Right = TaskImpl(root->Right);
		return root;
	}

	void Task()
	{
		TaskImpl(Root);
	}

	~BinarySearchTree()
	{
		Destroy(Root);
	}

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
};

int main()
{
	BinarySearchTree<int> tree;

	cout << "Enter the numbers of elements: " << endl;
	int size;
	cin >> size;

	cout << endl
		 << endl;

	cout << "Enter the values: " << endl;
	for (int k = 0; k < size; k++)
	{
		int temp;
		cin >> temp;
		tree.Add(temp);
	}

	cout << endl
		 << endl;
	cout << "Created binary tree: " << endl
		 << endl;
	tree.print2DUtil(tree.GetRoot(), 0);
	int leaves = tree.getLeafCount(tree.GetRoot());

	cout << endl
		 << endl;
	cout << "Number of leaves: " << leaves << endl
		 << endl;
}