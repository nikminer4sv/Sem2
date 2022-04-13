#include <iostream>
#include <fstream>
#include <conio.h>
#include "4.1.cpp"
#include "Vector.h"

using namespace std;

class ObjectCollection : Vector<Object>
{
private:
    Vector<Object *> Array;

public:
    ObjectCollection() = default;

    ObjectCollection(ObjectCollection &&obj)
    {
        Array = obj.Array;
        obj.Array.Clear();
    }

    ObjectCollection &operator=(ObjectCollection &&obj)
    {
        Array.Clear();
        Array = obj.Array;
        obj.Array.Clear();

        return *this;
    }

    // void Write(ofstream &of)
    // {
    //     int size = Array.getSize();
    //     for (int i = 0; i < size; ++i)
    //     {
    //         Object *Temp;
    //         *Temp.Write(of);
    //     }
    // }

    void Add()
    {
        system("cls");
        int Choice = 0;
        cout << "Choose object:\n"
             << "1. Rectangle\n"
             << "2. Ellipse\n"
             << "3. Star\n"
             << "4. Polygon\n"
             << "5. Text\n";
        cin >> Choice;

        Object *obj = nullptr;
        switch (Choice)
        {
        case 1:
        {
            obj = new Rectangle();
            Array.push_back(obj);
            break;
        }

        case 2:
        {
            obj = new Ellipse();
            Array.push_back(obj);
            break;
        }

        case 3:
        {
            obj = new Star();
            Array.push_back(obj);
            break;
        }

        case 4:
        {
            obj = new Polygon();
            Array.push_back(obj);
            break;
        }

        case 5:
        {
            obj = new Text();
            Array.push_back(obj);
            break;
        }

        default:
        {
            cout << "TbI prosto kek\n";
            break;
        }
        }
    }

    void Print()
    {
        cout << Array;
    }


};

int main()
{
    ObjectCollection Temp;

    bool IsWorking = true;
    int i = 0;
    while (IsWorking)
    {
        system("cls");
        cout << "1. Add\n"
             << "2. Print\n"
             << "3. Exit\n";

        int Choice = 0;
        cin >> Choice;

        switch (Choice)
        {
        case 1:
        {
            system("cls");
            Temp.Add();
            break;
        }

        case 2:
        {
            system("cls");
            Temp.Print();
            _getch();
            break;
        }

        case 3:
            IsWorking = false;
            break;

        default:
            cout << "TbI prosto kek\n";
            break;
        }
    }
}
