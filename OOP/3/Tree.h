#pragma once


//add copy constructor, find_for_element(getter), delete_element(delete list),
struct Tree
{
    int Data;
    Tree *right;
    Tree *left;

    Tree()
    {
        right = nullptr;
        left = nullptr;
    }
};

class TreeFunction
{
private:
    Tree* Head;

    Tree *search(Tree *Head, int Data)
    {
        Tree *pv = Head, *ppv = Head;

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

    void deleteMinTree(Tree *&Head, const int count, int &x)
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

    void print_tree_level(Tree *Head, const int level)
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

    void del_tree(Tree *&Head)
    {
        if (Head)
        {
            del_tree(Head->right);
            del_tree(Head->left);
            delete Head;
            Head = nullptr;
        }
    }

public:
    TreeFunction()
    {
        this->Head = NULL;
    }


    ~TreeFunction()
    {
        if (this->Head)
            std::cout << this << std::endl;
        del_tree();
    }

    void add(const int Data)
    {
        Tree *pnew = new Tree;
        pnew->Data = Data;
        pnew->right = NULL;
        pnew->left = NULL;

        if (!Head)
            Head = pnew;
        else
        {
            Tree *ppv;
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

    void findR(int &minValueR, int &count)
    {
        count = 0;
        if (Head->right)
        {
            Tree *Help = Head->right;
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

    void task()
    {
        int minValueR = 0;
        int count = 0;
        int x = 0;
        if (Head)
            findR(minValueR, count);

        std::cout << "MinValue " << minValueR << std::endl;
    }
};
