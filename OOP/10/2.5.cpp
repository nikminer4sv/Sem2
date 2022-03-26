#include <iostream>
#include <conio.h>
#include <ctime>
#include "Tree.h"

using namespace std;

template <typename T>
void task(Tree<T>& Test, int Number)
{
    int Counter = 0;
    Node<T>* Task = Test.Find(Test.getHead(), Number, Counter);
    cout << "Amount of branches to goal: " << Counter << endl << endl;
    Test.Print(Task, Counter);
    _getch();
}

int main()
{
    srand(time(NULL));

    Tree<int> Test;
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
            Test.Add(Number);
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
                Test.Add(rand() % 50 + 1);
            }
        }
        break;

        case 3:
            system("cls");
            Test.Print(Test.getHead(),0);
            _getch();
            break;

        case 4:
        {
            system("cls");
            cout << "Enter the number: ";
            int Number;
            cin >> Number;
            task(Test, Number);
        }
        break;

        case 5:
            IsWorking = false;
            break;

        default:
            cout << "TbI prosto kek\n";
            _getch();
            break;
        }
    }
}