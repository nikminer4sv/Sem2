#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

struct Tree
{
    int Data; 
    Tree* right;    
    Tree* left;   

    Tree()
    {
        right = nullptr;
        left = nullptr;
    }
};

Tree* search(Tree*, int);
void add(Tree*&, int);
void print_tree_level(Tree*, int);
void del_tree(Tree*& );
void task(Tree*& );
void deleteMinTree(Tree*&, const int , int&);

int main()
{
    srand(time(NULL));

    Tree* Head = NULL;

    bool IsWorking = true;

    while (IsWorking)
    {
        //system("cls");
        cout << "1. Add\n"
            << "2. Add random\n"
            << "3. Print tree\n"
            << "4. Task\n"
            << "5. Delete\n"
            << "0. Exit\n";

        int Choice;
        cin >> Choice;

        switch (Choice)
        {
            case 1:
            {
                //system("cls");
                cout << "Enter the number: ";
                int Number;
                cin >> Number;
                add(Head, Number);
                break;
            }
            

            case 2:
            {
                //system("cls");
                cout << "Enter the amount: ";
                int Number;
                cin >> Number;
                for (int i = 0; i < Number; i++)
                {
                    add(Head, rand() % 50 + 1);
                }
                break;
            }
            

            case 3:
            {
                //system("cls");
                print_tree_level(Head, 0);
                _getch();
                break;
            }

            case 4:
            {
                //system("cls");
                task(Head);
                _getch();
                break;
            }

            case 5:
            {
                del_tree(Head);
                break;
            }

            case 0:
            {
                IsWorking = false;
                break;
            }
            default:
            {
                cout << "Dolboeb\n";
                _getch();
                break;
            }
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
        Head = nullptr;
    }

}

void findR(Tree*& Task, int& minValueR, int& count)
{   
    count = 0;
    if (Task->right)
    {   
        Tree* Help = Task->right;
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
        minValueR = Task->Data;
        count++;
    }
    
    int x = 0;
    deleteMinTree(Task->right, count, x);
}

void deleteMinTree(Tree*& Task, const int count, int& x)
{
    if (Task)
    {
        x++;
        //cout << Task->Data << endl;
        deleteMinTree(Task->right, count, x);
        if(x == count){
            del_tree(Task);
            x = 0;
        }
    }
}

void task(Tree*& Task)
{
    int minValueR = 0;
    int count = 0;
    int x = 0;
    if (Task) 
        findR(Task, minValueR, count);
   
    cout << "MinvALUE" << minValueR << endl;

}