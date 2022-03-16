    #include <iostream>
    
    using namespace std;
    
    struct Node
    {
        int Value;
        Node* Left;
        Node* Right;
    
        Node()
        {
            Value = 0;
            Left = nullptr;
            Right = nullptr;
        }
    
        Node(int Value)
        {
            this->Value = Value;
            Left = nullptr;
            Right = nullptr;
        }
    
    };
    
    
    class BinarySearchTree
    {
    private:
        Node* Root;
    
    private:
    
        void PrintImpl(Node* TempNode)
        {
            cout << TempNode->Value << " ";
    
            if (TempNode->Left != nullptr)
                PrintImpl(TempNode->Left);
    
            if (TempNode->Right != nullptr)
                PrintImpl(TempNode->Right);
        }
    
        void Delete_Tree(Node* node)
        {
            if (node)
            {
                Delete_Tree(node->Right);
                Delete_Tree(node->Left);
                delete node;
            }
        }
    
    
        void TaskImpl(Node* root)
        {
            if ((root->Right != nullptr) || (root->Left != nullptr))
            {
                if (root->Left != nullptr)
                    TaskImpl(root->Left);
                if (root->Right != nullptr)
                    TaskImpl(root->Right);
            }
            else
                cout << root->Value << " ";
        }
        Node* Find_Parents(Node* root, int Value, bool& Check)
        {
            if (root->Value == Value)
            {
                Check = false;
                return root;
            }
    
            Node* TempNode = root;
    
            if (TempNode->Right->Value == Value || TempNode->Left->Value == Value)
                return TempNode;
            else if (Value > TempNode->Value)
                return Find_Parents(TempNode->Right, Value, Check);
            else if (Value < TempNode->Value)
                return Find_Parents(TempNode->Left, Value, Check);
            else
                return nullptr;
            
    
        }
    
        Node* Search_left_element(Node* root)
        {
            Node* temp = new Node;
            while (temp->Left != nullptr)
            {
                temp = temp->Left;
            }
    
            return temp;
        }
    
    
    public:
        BinarySearchTree()
        {
            Root = nullptr;
        }
    
        ~BinarySearchTree()
        {
            Delete_Tree(Root);
        }
    
        void Add(int Value)
        {
            Add(new Node(Value));
        }
    
        void Add(Node* NewNode)
        {
            if (Root == nullptr)
            {
                Root = NewNode;
                return;
            }
    
            Node* TempNode = Root;
            while (true)
            {
                if (TempNode->Value < NewNode->Value)
                {
                    if (TempNode->Right == nullptr)
                    {
                        TempNode->Right = NewNode;
                        return;
                    }
                    else
                    {
                        TempNode = TempNode->Right;
                    }
    
                }
                else
                {
                    if (TempNode->Left == nullptr)
                    {
                        TempNode->Left = NewNode;
                        return;
                    }
                    else
                    {
                        TempNode = TempNode->Left;
                    }
                }
            }
        }
    
        void Print()
        {
            if (Root != nullptr)
                PrintImpl(Root);
        }
    
        Node* GetRoot() { return Root; }
    
    
    
    
        void Task()
        {
            TaskImpl(Root);
        }
    
    
    
        void print_tree_level(Node* top, int level)
        {
            if (top)
            {
                print_tree_level(top->Left, level + 1);
                //обход левого поддерева
                for (int i = 0; i < level; i++)
                    cout << "    ";
                cout << top->Value << endl;
                print_tree_level(top->Right, level + 1);
                //обход правого поддерева
            }
        }
    
        void Delete_element(int Value)
        {
            bool flag = true;
        Node* TempNode = Find_Parents(Root, Value, flag);
            
        if (!flag && TempNode->Right != nullptr)
        {
            Node* Temp = Search_left_element(TempNode->Right);
            Node* Parent_Temp = Find_Parents(TempNode, Temp->Value, flag);
            if(TempNode == Parent_Temp)
            {
                TempNode->Value = TempNode->Right->Value;
                Node* X = TempNode->Right;
                TempNode->Right = TempNode->Right->Right;
                delete X;
            }
            else
            {
                TempNode->Value = Temp->Value;
                if (Temp->Right == nullptr)
                {
                    Node* X = Parent_Temp->Left;
                    Parent_Temp->Left = nullptr;
                    delete X;
                }
                else
                    {
                        Node* X = Parent_Temp->Left;
                        Parent_Temp->Left = Temp->Right;
                        delete X;
                    }
            }
        }
        else if (!flag && TempNode->Right == nullptr)
        {
            Node* X = TempNode;
            TempNode = TempNode->Left;
            delete X;
        } 


        if (TempNode->Left->Value == Value)
        {
            if (TempNode->Left->Left == nullptr && TempNode->Left->Right == nullptr)
            {
                Node* X = TempNode->Left;
                TempNode->Left = nullptr;
                delete X;
            }
            else if (TempNode->Left->Left != nullptr && TempNode->Left->Right != nullptr)
            {
                Node* Temp = Search_left_element(TempNode->Left->Right);
                Node* Parent_Temp = Find_Parents(TempNode, Temp->Value, flag);
                if(TempNode->Left == Parent_Temp)
                    {
                    Node* X = TempNode->Left;
                    TempNode->Left = TempNode->Left->Right;
                    delete X;
                    }
                else
                    {
                    TempNode->Left->Value = Temp->Value;
                    if (Temp->Right == nullptr)
                    {
                        Node* X = Temp;
                        Parent_Temp->Left = nullptr;
                        delete X;
                    }
                    else
                    {
                        Node* X = Temp;
                        Parent_Temp->Left = Temp->Right;
                        delete X;
                    }
                    }
                }
                else if (TempNode->Left->Left != nullptr)
                {
                    Node* X = TempNode->Left;
                    TempNode->Left = TempNode->Left->Left;
                    delete X;
                }
                else if (TempNode->Left->Right != nullptr)
                {
                    Node* X = TempNode->Left;
                    TempNode->Left = TempNode->Left->Right;
                    delete X;
                }
            }
            else if (TempNode->Right->Value == Value)
        {
            if (TempNode->Right->Left == nullptr && TempNode->Right->Right == nullptr)
            {
                Node* X = TempNode->Right;
                TempNode->Right = nullptr;
                delete X;
            }
            else if (TempNode->Right->Left != nullptr && TempNode->Right->Right != nullptr)
            {
                Node* Temp = Search_left_element(TempNode->Right->Right);
                Node* Parent_Temp = Find_Parents(TempNode, Temp->Value, flag);
                if(TempNode == Parent_Temp)
                    {
                    Node* X = TempNode->Right;
                    TempNode->Right = TempNode->Right->Right;
                    delete X;
                    }
                else
                    {
                    TempNode->Right->Value = Temp->Value;
                    if (Temp->Right == nullptr)
                    {
                        Node* X = Temp;
                        Parent_Temp->Left = nullptr;
                        delete X;
                    }
                    else
                    {
                        Node* X = Temp;
                        Parent_Temp->Left = Temp->Right;
                        delete X;
                    }
                    }
                }
                else if (TempNode->Right->Left != nullptr)
                {
                    Node* X = TempNode->Right;
                    TempNode->Right = TempNode->Right->Left;
                    delete X;
                }
                else if (TempNode->Right->Right != nullptr)
                {
                    Node* X = TempNode->Right;
                    TempNode->Right = TempNode->Right->Right;
                    delete X;
                }
            }
        
    
            
    
        }
    
    };
    
    
    
    
    int main()
    {
        BinarySearchTree N;
    
        N.Add(12);
        N.Add(8);
        N.Add(6);
        N.Add(20);
        N.Add(7);
        N.Add(13);
        N.Add(16);
        N.Add(21);
    
        N.print_tree_level(N.GetRoot(), 0);
    
        N.Delete_element(7);
    
        cout << endl << endl;
        cout << "-----------------------------------------";
        cout << endl << endl;
    
        N.print_tree_level(N.GetRoot(), 0);
    
        cout << endl << endl;
    
        N.Task();
    }