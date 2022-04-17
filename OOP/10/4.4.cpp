#include <iostream>
#include <conio.h>
#include "For_4.4.h"
#include "4.1.cpp"

using namespace std;

class ObjectCollection : List<Object>
{
private:
    List<Object*> Array;

public:
    ObjectCollection() = default;

    ObjectCollection(ObjectCollection& obj)
    {
        Array = obj.Array;
    }

    ObjectCollection(ObjectCollection&& obj)
    {
        Array = std::move(obj.Array);
    }

    ObjectCollection& operator=(ObjectCollection& obj)
    {
        Array = obj.Array;
        return *this;
    }

    ObjectCollection& operator=(ObjectCollection&& obj)
    {
        Array = std::move(obj.Array);
        return *this;
    }

    ~ObjectCollection() = default;

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

        Object* obj = nullptr;
        switch (Choice)
        {
        case 1:
        {
            obj = new Rectangle();
            (*obj).Add();
            Array.Add(obj);
            break;
        }

        case 2:
        {
            obj = new Ellipse();
            (*obj).Add();
            Array.Add(obj);
            break;
        }

        case 3:
        {
            obj = new Star();
            (*obj).Add();
            Array.Add(obj);
            break;
        }

        case 4:
        {
            obj = new Polygon();
            (*obj).Add();
            Array.Add(obj);
            break;
        }

        case 5:
        {
            obj = new Text();
            (*obj).Add();
            Array.Add(obj);
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
        {
            IsWorking = false;
            break;
        }

        default:
            cout << "TbI prosto kek\n";
            break;
        }
    }
}