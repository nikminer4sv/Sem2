#include <iostream>

using namespace std;

template<typename T>
class BinarySearchTree {
private:
    struct Node {

        T Value=0;
        Node* Left = nullptr;
        Node* Right=nullptr;

        Node() = default;

        Node(T Value) { 
            this->Value = Value; 
        }

    };

    Node* Root = nullptr;

private:
    void PrintImpl(Node* TempNode) {

        cout << TempNode->Value << " ";

        if (TempNode->Left != nullptr) 
            PrintImpl(TempNode->Left);

        if (TempNode->Right != nullptr) 
            PrintImpl(TempNode->Right);

    }

    void Destroy(Node* node)
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

    BinarySearchTree(const BinarySearchTree& tree){
        Node* head = new Node(tree.Root->Value);
        Copy(head);
    }

    void Clear() {
        Destroy(Root);
        Root = nullptr;
    }

    void Copy(Node* element) {

        if (element == nullptr)
            return;
        
        this->Add(element->Value);
        
        Copy(element->Left);
        Copy(element->Right);

    }

    void Add(const T& Value){
        Add(new Node(Value));
    }

    void Add(Node* NewNode) {
        if (Root == nullptr) {
            Root = NewNode;
            return;
        } 

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

    void Print() {
        if (Root != nullptr)
            PrintImpl(Root);
    }

    Node* GetRoot() { return Root; }

    Node* TaskImpl(Node* root) {

        if (root == nullptr)
            return nullptr;
     
        if (root->Left == nullptr && root->Right == nullptr) {
            delete root;
            return nullptr;
        }
    
        root->Left = TaskImpl(root->Left);
        root->Right = TaskImpl(root->Right);
        return root;
    }

    void Task() {
        TaskImpl(Root);
    }

    ~BinarySearchTree()
    {
        Destroy(Root);
    }

    void print_tree_level(Node * top, int level)
    {
        if (top)
        {   print_tree_level (top->Left, level + 1);
                                //обход левого поддерева
            for (int i = 0; i < level; i++)
                cout << "    ";
            cout << top->Value << endl;
            print_tree_level(top->Right, level + 1);
                                //обход правого поддерева
        }
    }

};

int main() {

    BinarySearchTree<int> T;

    T.Add(20);
    T.Add(10);
    T.Add(5);
    T.Add(15);
    T.Add(9);
    //print_tree_level(T.GetRoot(), 0);


    BinarySearchTree<int> T2(T);
    T2.Add(1);
    T2.Add(1);
    T2.Add(1);
    T2.Add(1);


    T2.print_tree_level(T2.GetRoot(), 0);

          /*          20
                    /
                  10
                 /  \
                5    15  
                 \
                  9


                */

}