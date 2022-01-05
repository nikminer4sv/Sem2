#include <iostream>

using namespace std;

struct Node {

    int Value;
    Node* Left;
    Node* Right;

    Node() { Left = nullptr; Right = nullptr; }

    Node(int Value) { Left = nullptr; Right = nullptr; this->Value = Value; }

};

class BinarySearchTree {
private:
    Node* Root;

public:

private:
    void PrintImplementation(Node* TempNode) {

        cout << TempNode->Value << " ";

        if (TempNode->Left != nullptr) 
            PrintImplementation(TempNode->Left);

        if (TempNode->Right != nullptr) 
            PrintImplementation(TempNode->Right);

    }

public:
    BinarySearchTree() { Root = nullptr; }

    void Add(int Value) {

        Node* NewNode = new Node(Value);        

        if (Root == nullptr) {

            Root = NewNode;

        } else {

            Node* TempNode = Root;

            while (true) {

                if (TempNode->Value < NewNode->Value) {

                    if (TempNode->Right != nullptr) {

                        TempNode = TempNode->Right;

                    } else {

                        TempNode->Right = NewNode;
                        break;

                    }


                } else {

                    if (TempNode->Left != nullptr) {

                        TempNode = TempNode->Left;

                    } else {

                        TempNode->Left = NewNode;
                        break;

                    }

                }

            }

        }

    }

    

    void Print() {

        PrintImplementation(Root);

    }

    Node* GetRoot() { return Root; }
};

int main() {

    BinarySearchTree T;

    T.Add(2);
    T.Add(1);
    T.Add(4);
    T.Add(3);
    T.Add(5);

    T.Print();


}