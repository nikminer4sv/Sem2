#include <iostream>
#include <conio.h>
#include <ctime>
#include "Tree.h"

using namespace std;

int main()
{
    srand(time(NULL));

    TreeFunction<int> Tree1;
    TreeFunction<int> Tree2(2);

    bool IsWorking = true;

    while (IsWorking)
    {
        // system("cls");
        cout << "1. Add\n"
             << "2. Add random\n"
             << "3. Print tree\n"
             << "4. Task\n"
             << "5. Delete tree\n"
             << "6. Delete element of tree\n"
             << "7. Create a new tree based on another\n"
             << "0. Exit\n";

        int Choice;
        cin >> Choice;

        switch (Choice)
        {
        case 1:
        {
            // system("cls");
            cout << "Enter the number: ";
            int Number;
            cin >> Number;
            Tree1.add(Number);
            break;
        }

        case 2:
        {
            // system("cls");
            cout << "Enter the amount: ";
            int Number;
            cin >> Number;
            for (int i = 0; i < Number; i++)
            {
                Tree1.add(rand() % 50 + 1);
            }
            break;
        }

        case 3:
        {
            // system("cls");
            Tree1.print_tree_level(0);
            cout << "========================TREE2===============================" << endl;
            Tree2.print_tree_level(0);
            _getch();
            break;
        }

        case 4:
        {
            // system("cls");
            Tree1.task();
            _getch();
            break;
        }

        case 5:
        {
            Tree1.del_tree();
            break;
        }

        case 6:
        {
            int element;
            cout << "Enter the element for delete." << endl;
            cin >> element;
            Tree1.del_data(element);
            break;
        }

        case 7:
        {
            cout << "Enter the object from and to copy: " << endl;
            cout << "1. Tree1 -> Tree2." << endl;
            cout << "2. Tree2 -> Tree1." << endl;
            int choose2;
            cin >> choose2;

            switch (choose2)
            {
            case 1:
            {
                Tree2 = Tree1;
                break;
            }

            case 2:
            {
                Tree1 = Tree2;
                break;
            }

            default:
                break;
            }

            break;
        }

        case 0:
        {
            IsWorking = false;
            break;
        }
        default:
        {
            cout << "Noob\n";
            _getch();
            break;
        }
        }
    }
}
