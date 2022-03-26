#include <iostream>
#include <conio.h>
#include <ctime>
#include "Tree.h"

using namespace std;

int main()
{
    srand(time(NULL));

    TreeFunction Head;

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
                Head.add(Number);
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
                    Head.add(rand() % 50 + 1);
                }
                break;
            }
            

            case 3:
            {
                //system("cls");
                Head.print_tree_level(0);
                _getch();
                break;
            }

            case 4:
            {
                //system("cls");
                Head.task();
                _getch();
                break;
            }

            case 5:
            {
                Head.del_tree();
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

