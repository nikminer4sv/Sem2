#include <iostream>  // for cin cout
#include <conio.h>
#include <ctime>

using namespace std;

struct Tree
{
    int Data;  // число
    Tree* left;    //указатель на левое поддерево
    Tree* right;   //указатель на правое поддерево

    Tree()
    {
        left = nullptr;
        right = nullptr;
    }
};

Tree* search(Tree*, int);
void add(Tree*&, int);
void add_rand(Tree*&, int);
void print_tree(Tree*);
void print_tree_level(Tree*, int);
void del_tree(Tree*& Head);
void task(Tree*, int);

int main()
{
    srand(time(NULL));

    Tree* Head = NULL;
    Tree* Task = NULL;
    bool IsWorking = true;

    while (IsWorking)
    {
        system("cls");
        cout << "1. Add\n"
            << "2. Add random\n"
            << "3. Print tree\n"
            << "4. Task\n"
            << "5. Exit\n";

        int Choice = 0;
        cin >> Choice;

        switch (Choice)
        {
        case 1:
        {
            system("cls");
            cout << "Enter the number: ";
            int Number;
            cin >> Number;
            add(Head, Number);
        }
        break;

        case 2:
        {
            system("cls");
            cout << "Enter the amount: ";
            int Number;
            cin >> Number;
            for (int i = 0; i < Number; i++)
            {
                add(Head, rand() % 50 + 1);
            }
        }
        break;

        case 3:
            system("cls");
            print_tree_level(Head, 0);
            _getch();
            break;

        case 4:
        {
            system("cls");
            cout << "Enter the number: ";
            int Number;
            cin >> Number;
            Task = Head;
            task(Task, Number);
        }
        break;

        case 5:
            IsWorking = false;
            del_tree(Head);
            del_tree(Task);
            break;

        default:
            cout << "Dolboeb\n";
            _getch();
            break;
        }
    }
}

Tree* search(Tree* Head, int Data)
{
    Tree* pv = Head, * ppv = Head;

    while (pv)
    {
        ppv = pv;

        if (Data < pv->Data)
            pv = pv->left;
        else
            pv = pv->right;
    }

    return ppv;
}

Tree* find(Tree* Head, int Data, int& Counter)
{
    if (!Head)
        return NULL;

    Tree* p = new Tree;

    if (Data < Head->Data)
    {
        Counter++;
        p = find(Head->left, Data, Counter);
    }
    else if (Data > Head->Data)
    {
        Counter++;
        p = find(Head->right, Data, Counter);
    }
    else
    {
        p = Head;
    }

    return p ? p : Head;
}

void add(Tree*& Head, int Data)
{
    Tree* pnew = new Tree;
    pnew->Data = Data;
    pnew->left = NULL;
    pnew->right = NULL;

    if (!Head)
        Head = pnew;
    else
    {
        Tree* ppv;
        ppv = search(Head, Data);

        if (Data < ppv->Data)
            ppv->left = pnew;
        else
            ppv->right = pnew;
    }
}

void print_tree(Tree* Head)
{
    if (Head)
    {
        print_tree(Head->left);
        cout << Head->Data << " ";
        print_tree(Head->right);
    }
}

void print_tree_level(Tree* Head, int level)
{
    if (Head)
    {
        print_tree_level(Head->left, level + 1);
        for (int i = 0; i < level; i++)
            cout << "\t";

        cout << Head->Data << endl;
        print_tree_level(Head->right, level + 1);
    }
}

void del_tree(Tree*& Head)
{
    if (Head)
    {
        del_tree(Head->left);
        del_tree(Head->right);
        delete Head;
        Head = NULL;
    }
}

void task(Tree* Task, int Number)
{
    int Counter = 0;
    Task = find(Task, Number, Counter);
    cout << "Amount of branches to goal: " << Counter << endl << endl;
    print_tree_level(Task, Counter);
    _getch();
}