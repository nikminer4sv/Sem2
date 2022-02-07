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

        if (Root != nullptr)
            PrintImplementation(Root);

    }

    Node* GetRoot() { return Root; }

    /*void Task() {

        if (Root != nullptr) {

            if (Root->Right == nullptr) {

                Root = nullptr;

            } else {

                Node* Main = Root;
                Node* First = Root->Right;

                while (First->Right != nullptr) {
                    Main = Main->Right;
                    First = First->Right;
                }

                Main->Right = nullptr;

            }

        }

    }*/

    Node* TaskImpl(Node* root) {

        if (root == NULL)
            return NULL;
        if (root->Left == NULL && root->Right == NULL) {
            free(root);
            return NULL;
        }
    
        root->Left = TaskImpl(root->Left);
        root->Right = TaskImpl(root->Right);
    
        return root;

    }

    void Task() {

        TaskImpl(Root);

    }

};

void print_tree(Node* top)
{
    if (top)
    {   print_tree (top->Left); //обход левого поддерева
         cout << top->Value<< "  ";
         print_tree(top->Right);//обход правого поддерева
    }
}

int main() {

    BinarySearchTree T;

    T.Add(20);
    T.Add(10);
    T.Add(5);
    T.Add(15);
    T.Add(9);
    T.Task();

    //print_tree(T.GetRoot());
    T.Print();

          /*          20
                10
            5       15
                9*/

}