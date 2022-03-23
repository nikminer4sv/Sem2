#include <iostream>
#include "LIST.h"

template<typename T>
void Menu(list<T> &l1, T &symbol, list<T> &l2)
{
    while (true)
    {
        std::cout << "Enter the choose:  " << std::endl;

        std::cout << "1. Add new symbol." << std::endl;
        std::cout << "2. Search for identical symbols, that are repeated twice and create a new list of them." << std::endl;
        std::cout << "3. Delete a symbol." << std::endl;
        std::cout << "4. Print the list's of symbols." << std::endl;
        std::cout << "5. Clear." << std::endl;
        std::cout << "6. Create a new list based on another." << std::endl;
        std::cout << "7. Exit." << std::endl;

        int choose;
        std::cin >> choose;

        if (choose == 7)
            break;

        switch (choose)
        {
        case 1:
        {
            std::cout << "How many symbols do you want to enter? " << std::endl;
            int amount;
            std::cin >> amount;
            for (int i = 0; i < amount; i++)
            {
                std::cout << "Symbol = ";
                std::cin >> symbol;

                l1.push_back(symbol);
            }

            break;
        }
        case 2:
        {
            std::cout << "Creating a new list...";

            l1.Task(l2);
            break;
        }
        case 3:
        {
            std::cout << "Enter the symbol (\"x\")" << std::endl;

            std::cout << "Symbol = ";
            std::cin >> symbol;

            l1.remove(symbol);

            break;
        }
        case 4:
        {
            std::cout << "\n========================LIST=OF=STUDENTS===========================" << std::endl;
            l1.print();
            std::cout << "====================SECOND=LIST=OF=STUDENTS========================" << std::endl;
            l2.print();

            break;
        }

        case 5:
        {
            l1.Clear();
            l2.Clear();
            break;
        }

        case 6:
        {
            std::cout << "Enter the object from and to copy: " << std::endl;
            std::cout << "1. L1 -> L2." << std::endl;
            std::cout << "2. L2 -> L1." << std::endl;
            int choose2;
            std::cin >> choose2;

            switch (choose2)
            {
            case 1:
            {
                l2 = l1;
                break;
            }

            case 2:
            {
                l1 = l2;
                break;
            }   
            
            default:
                break;
            }
        }

        default:
            break;
        }

        std::cout << std::endl;
    }
}

int main()
{

    list<int> l1, l2;
    int symbol;

    Menu(l1, symbol, l2);

    return 0;
}