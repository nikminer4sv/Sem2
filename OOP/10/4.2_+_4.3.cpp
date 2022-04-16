#include <iostream>
#include <fstream>
#include <conio.h>
#include <map>
#include "4.1.cpp"
#include "For_4.2.h"

using namespace std;

class ObjectFactory
{
public:
    virtual Object* Create(ifstream& ifs) = 0;
};

class RectangleFactory : public ObjectFactory
{
public:
    Object* Create(ifstream& ifs) override
    {
        int x, y;
        ifs >> x >> y;
        char* color = new char[255];
        ifs >> color;
        float width, height;
        ifs >> width >> height;
        Object* Temp = new Rectangle(Position(x, y), width, height, color);

        return Temp;
    }
};

class EllipseFactory : public ObjectFactory
{
public:
    Object* Create(ifstream& ifs) override
    {
        int x, y;
        ifs >> x >> y;
        char* color = new char[255];
        ifs >> color;
        float width, height;
        ifs >> width >> height;
        Object* Temp = new Ellipse(Position(x, y), width, height, color);

        return Temp;
    }
};

class StarFactory : public ObjectFactory
{
public:
    Object* Create(ifstream& ifs) override
    {
        int x, y;
        ifs >> x >> y;
        char* color = new char[255];
        ifs >> color;
        float width, height;
        ifs >> width >> height;
        int peaks;
        ifs >> peaks;
        Object* Temp = new Star(Position(x, y), width, height, color, peaks);

        return Temp;
    }
};

class PolygonFactory : public ObjectFactory
{
public:
    Object* Create(ifstream& ifs) override
    {
        int x, y;
        ifs >> x >> y;
        char* color = new char[255];
        ifs >> color;
        float width, height;
        ifs >> width >> height;
        int peaks;
        ifs >> peaks;
        Object* Temp = new Polygon(Position(x, y), width, height, color, peaks);

        return Temp;
    }
};

class TextFactory : public ObjectFactory
{
public:
    Object* Create(ifstream& ifs) override
    {
        int x, y;
        ifs >> x >> y;
        char* color = new char[255];
        ifs >> color;
        int textSize;
        ifs >> textSize;
        char* text = new char[255];
        ifs >> text;
        Object* Temp = new Text(Position(x, y), textSize, text, color);

        return Temp;
    }
};

class ObjectCollection : Vector<Object>
{
private:
    Vector<Object*> Array;

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

    ObjectCollection(string name, map<string, ObjectFactory*> factories)
    {
        ifstream stream;
        stream.open(name);

        if (stream.is_open())
        {
            string type;
            stream >> type;
            while (!stream.eof())
            {
                Object* temp = factories[type]->Create(stream);
                Array.push_back(temp);
                stream >> type;
            }
        }
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

    void Write(ofstream& of)
    {
        int size = Array.getSize();
        for (int i = 0; i < size; ++i)
        {
            (*Array[i]).Write(of);
        }
    }

    void Save()
    {
        ofstream of("4.3.txt");
        Write(of);
    }

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
            Array.push_back(obj);
            break;
        }

        case 2:
        {
            obj = new Ellipse();
            (*obj).Add();
            Array.push_back(obj);
            break;
        }

        case 3:
        {
            obj = new Star();
            (*obj).Add();
            Array.push_back(obj);
            break;
        }

        case 4:
        {
            obj = new Polygon();
            (*obj).Add();
            Array.push_back(obj);
            break;
        }

        case 5:
        {
            obj = new Text();
            (*obj).Add();
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
    map<string, ObjectFactory*> factories;
    factories["Rectangle"] = new RectangleFactory;
    factories["Ellipse"] = new EllipseFactory;
    factories["Star"] = new StarFactory;
    factories["Polygon"] = new PolygonFactory;
    factories["Text"] = new TextFactory;

    ObjectCollection Temp("4.3.txt", factories);

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
            Temp.Save();
            break;
        }

        default:
            cout << "TbI prosto kek\n";
            break;
        }
    }
}