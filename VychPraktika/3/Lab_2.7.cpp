#include <iostream>  // for cin cout
#include <conio.h>
#include <ctime>

using namespace std;

struct Tree
{
    int Data;  // число
    Tree* right;    //указатель на левое поддерево
    Tree* left;   //указатель на правое поддерево

    Tree()
    {
        right = nullptr;
        left = nullptr;
    }
};

Tree* search(Tree*, int);
void add(Tree*&, int);
void add_rand(Tree*&, int);
void print_tree(Tree*);
void print_tree_level(Tree*, int);
void del_tree(Tree*& Head);
void task(Tree* );

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
            Task = Head;
            task(Task);
            _getch();
            break;
        }

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
            pv = pv->right;
        else
            pv = pv->left;
    }

    return ppv;
}

void add(Tree*& Head, int Data)
{
    Tree* pnew = new Tree;
    pnew->Data = Data;
    pnew->right = NULL;
    pnew->left = NULL;

    if (!Head)
        Head = pnew;
    else
    {
        Tree* ppv;
        ppv = search(Head, Data);

        if (Data < ppv->Data)
            ppv->right = pnew;
        else
            ppv->left = pnew;
    }
}

void print_tree(Tree* Head)
{
    if (Head)
    {
        print_tree(Head->right);
        cout << Head->Data << " ";
        print_tree(Head->left);
    }
}

void print_tree_level(Tree* Head, int level)
{
    if (Head)
    {
        print_tree_level(Head->right, level + 1);
        for (int i = 0; i < level; i++)
            cout << "\t";

        cout << Head->Data << endl;
        print_tree_level(Head->left, level + 1);
    }
}

void del_tree(Tree*& Head)
{
    if (Head)
    {
        del_tree(Head->right);
        del_tree(Head->left);
        delete Head;
        Head = NULL;
    }
}

void findR(Tree* Task, int& minValueR)
{
    if (Task && Task->right)
    {
        minValueR = Task->right->Data;
        findR(Task->right, minValueR);
    }
}

void task(Tree* Task)
{
    int minValueR = 0;

    findR(Task, minValueR);
    cout << minValueR << endl;
}