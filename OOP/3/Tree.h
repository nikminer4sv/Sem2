#pragma once


//
// ТОЧНО вспомнить что тут происходит и в чем 
// И не путать лево и
//

// add copy constructor, find_for_element(getter), delete_element(delete list),
template <typename T>
struct Tree
{
    T Data{};
    Tree *right = nullptr;
    Tree *left = nullptr;

    Tree() = default;
};

template <typename T>
class TreeFunction
{
private:
    Tree<T> *Head = nullptr; //root

    //one level upper than target data
    Tree<T>* search(Tree<T> *Head, const T& Data)
    {
        Tree<T> *pv = Head, *ppv = Head;

        while (pv)
        {
            ppv = pv;

            if (Data < pv->Data)
                pv = pv->right;
            else
                pv = pv->left;
        }

        return ppv;
    }

    void deleteMinTree(Tree<T> *&Head, const int count, int &x)
    {
        if (Head)
        {
            x++;
            // std::cout << Head->Data << std::endl;
            deleteMinTree(Head->right, count, x);
            if (x == count)
            {
                del_tree(Head);
                x = 0;
            }
        }
    }

    void print_tree_level(Tree<T> *Head, const int level)
    {
        if (Head)
        {
            print_tree_level(Head->right, level + 1);
            for (int i = 0; i < level; i++)
                std::cout << "\t";

            std::cout << Head->Data << std::endl;
            print_tree_level(Head->left, level + 1);
        }
    }

    void del_tree(Tree<T> *&Head)
    {
        if (Head)
        {
            del_tree(Head->right);
            del_tree(Head->left);
            delete Head;
            Head = nullptr;
        }
    }

    void findR(T &minValueR, int &count)
    {
        count = 0;
        if (Head->right)
        {
            Tree<T> *Help = Head->right;
            while (true)
            {
                if (Help)
                {
                    minValueR = Help->Data;
                    count++;
                    Help = Help->right;
                    continue;
                }
                break;
            }
        }
        else
        {
            minValueR = Head->Data;
            count++;
        }

        int x = 0;
        deleteMinTree(Head->right, count, x);
    }

    void del_data(Tree<T> *&Head, const T data, bool &deleted)
    {
        if (Head)
        {
            del_data(Head->right, data, deleted);
            del_data(Head->left, data, deleted);

            if (Head->Data != data && !deleted)
            {
                delete Head;
                Head = nullptr;
            }
            else if(!deleted)
            {
                deleted = true;
                delete Head;
                Head = nullptr;
            } 
        }
    }

    void copy(Tree<T> *Head, Tree<T> *obj)
    {
        if (Head)
            del_tree();

        if (obj)
        {
            Head = new Tree<T>;
            add(obj->Data);
            copy(Head->left, obj->left);
            copy(Head->right, obj->right);
        }
        
    }
public:
    TreeFunction() { this->Head = NULL; }

    TreeFunction(const T data) : TreeFunction() { this->add(data); }

    TreeFunction(const TreeFunction& obj) { copy(this->Head, obj->Head); }
    
    ~TreeFunction()
    {
        if (this->Head)
            std::cout << this << std::endl;
        del_tree();
    }

    TreeFunction &operator=(const TreeFunction& obj)
    {
        std::cout << this->Head << std::endl;
        std::cout << obj.Head << std::endl;
        copy(this->Head, obj.Head);
       
        return *this;
    }

    T getData(const T Data)
    {
        Tree<T> *Temp = search(this->Head, Data);
        return Temp->Data;
    }

    void add(const T Data)
    {
        Tree<T> *pnew = new Tree<T>;
        pnew->Data = Data;
        pnew->right = NULL;
        pnew->left = NULL;

        if (!Head)
            Head = pnew;
        else
        {
            Tree<T> *ppv;
            ppv = search(Head, Data);

            if (Data < ppv->Data)
                ppv->right = pnew;
            else
                ppv->left = pnew;
        }
    }

    void print_tree_level(const int level)
    {
        if (Head)
        {
            print_tree_level(Head->right, level + 1);
            for (int i = 0; i < level; i++)
                std::cout << "\t";

            std::cout << Head->Data << std::endl;
            print_tree_level(Head->left, level + 1);
        }
    }

    void del_tree()
    {
        if (Head)
        {
            del_tree(Head->right);
            del_tree(Head->left);
            delete Head;
            Head = nullptr;
        }
    }

    void task()
    {
        T minValueR;
        int count = 0;
        if (Head)
            findR(minValueR, count);

        std::cout << "MinValue " << minValueR << std::endl;
    }

    void del_data(const T data)
    {
        bool deleted = false;
        if (Head)
        {
            del_data(Head->right, data, deleted);
            del_data(Head->left, data, deleted);
            if (!deleted)
            {
                delete Head;
                Head = nullptr;
            }
            
        }
    }
};
