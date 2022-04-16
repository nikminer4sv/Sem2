#include <iostream>
#include <map>
#include "Lab_4.1.cpp"
#include "VECTOR.h"
#include <fstream>

using namespace std;

class ObjectFactory
{
protected:
    const size_t SIZE = 255; 
public:
    virtual Object* Create(ifstream& ifs) = 0;
};

class StarFactory : public ObjectFactory
{
public:
    Object* Create(ifstream& ifs)
    {
        char *name = new char[SIZE];
        float temperature;
        bool solidSurface;
        ifs >> name;
        ifs >> temperature;
        ifs >> solidSurface;

        Object* Temp = new Star(name, temperature, solidSurface);

        return Temp;
    }
};

class AsteroidFactory : public ObjectFactory
{
public:
    Object* Create(ifstream& ifs)
    {
        float x, y, z, vx, vy, vz, maxSize;
        ifs >> maxSize >> x >> y >> z >> vx >> vy >> vz;

        Object* Temp = new Asteroid(Position(x, y, z), Speed(vx, vy, vz), maxSize);

        return Temp;
    }
};

class SpaceshipFactory : public ObjectFactory
{
public:
    Object* Create(ifstream& ifs)
    {
        char *nameSpaceship = new char[SIZE];
        size_t ammunition;
        float x, y, z, vx, vy, vz, maxSpeed;
        ifs >> ammunition >> maxSpeed >> nameSpaceship >> x >> y >> z >> vx >> vy >> vz;

        Object* Temp = new Spaceship(Position(x, y, z), Speed(vx, vy, vz), maxSpeed, nameSpaceship, ammunition);

        return Temp;
    }
};

class RocketFactory : public ObjectFactory
{
public:
    Object* Create(ifstream& ifs)
    {
        size_t explosivePower, timeFuelReserve;
        float x, y, z, vx, vy, vz;
        ifs >> explosivePower >> timeFuelReserve >> x >> y >> z >> vx >> vy >> vz;
       
        Object* Temp = new Rocket(Position(x, y, z), Speed(vx, vy, vz), explosivePower, timeFuelReserve);

        return Temp;
    }
};


class ObjectCollection : Vector<Object *>
{
private:
    Vector<Object *> helpPLS;

public:
    void push_back(Object *trash) { helpPLS.push_back(trash); }
    
    ObjectCollection(string name, map<string, ObjectFactory*>& factories)
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
                helpPLS.push_back(temp);
                stream >> type;
            }
        }
    }

    friend ostream &operator<<(ostream &os, const ObjectCollection &vector)
    {
        for (size_t i = 0; i < vector.helpPLS.getSize(); i++)
        {
            os << *vector.helpPLS[i] << endl << endl;
        }
        return os;
    }

public:

    ObjectCollection() = default;

    ObjectCollection(ObjectCollection &&obj)
    {
        helpPLS = std::move(obj.helpPLS);
    }

    ObjectCollection &operator=(ObjectCollection &&obj)
    {
        helpPLS = std::move(obj.helpPLS);
        return *this;
    }

    void Save()
    {
        ofstream of("C:\\Users\\Lenovo\\Desktop\\Sem2\\OOP\\3\\4.3.txt");
        int size = helpPLS.getSize();

        for (int i = 0; i < size; ++i)
            (*helpPLS[i]).Write(of);
    }
};


void Menu(ObjectCollection &mum)
{
    while (true)
    {
        cout << "Enter the number: " << endl;
        cout << "1. Star.\n"
             << "2. Asteroid.\n"
             << "3. Spaceship.\n"
             << "4. Rocket.\n"
             << "5. Print\n"
             << "0. Exit.\n";

        size_t choose = 0;
        size_t choose2 = 0;
        cin >> choose;

        switch (choose)
        {
        case 1:
        {
            cout << "Fill a Star" << endl;
            const size_t SIZE = 255;
            char *name = new char[SIZE];
            cin.get();
            cout << "Enter the name of Star: " << endl;
            cin.getline(name, SIZE);

            float temperature;
            cout << "Enter the temperature: ";
            cin >> temperature;
            
            bool solidSurface;
            cout << "This planet/star have a solid surface? (1 == YES, 0 = NO): ";
            cin >> solidSurface;

            mum.push_back(new Star(name, temperature, solidSurface));

           
            break;
        }
        case 2:
        {
            cout << "Fill an Asteroid" << endl;
            float x, y, z;
            cout << "Enter the coordinate (X , Y , Z): ";
            cin >> x >> y >> z;

            float vx, vy, vz;
            cout << "Enter the speed (Vx , Vy , Vz): ";
            cin >> vx >> vy >> vz;

            float maxSize;
            cout << "Enter the max size: ";
            cin >> maxSize;

            mum.push_back(new Asteroid(Position(x, y, z),Speed(vx, vy, vz), maxSize));

            break;
        }
        case 3:
        {
            cout << "Fill a Spaceship" << endl;

            const size_t SIZE = 255;
            char *name = new char[SIZE];
            cin.get();
            cout << "Enter the name of Spaceship: " << endl;
            cin.getline(name, SIZE);

            float x, y, z;
            cout << "Enter the coordinate (X , Y , Z): ";
            cin >> x >> y >> z;

            float vx, vy, vz;
            cout << "Enter the speed (Vx , Vy , Vz): ";
            cin >> vx >> vy >> vz;

            float maxSpeed;
            cout << "Enter the max speed: ";
            cin >> maxSpeed;

            size_t ammunition;
            cout << "Enter the ammunition: ";
            cin >> ammunition;

            mum.push_back(new Spaceship(Position(x, y, z), Speed(vx, vy, vz), maxSpeed, name, ammunition));

            break;
        }
        case 4:
        {
            float x, y, z;
            cout << "Enter the coordinate (X , Y , Z): ";
            cin >> x >> y >> z;

            float vx, vy, vz;
            cout << "Enter the speed (Vx , Vy , Vz): ";
            cin >> vx >> vy >> vz;

            size_t explosivePower;
            cout << "Enter the power: ";
            cin >> explosivePower;

            size_t timeFuelReserve;
            cout << "Enter the time of fuel reserve: ";
            cin >> timeFuelReserve;

            mum.push_back(new Rocket(Position(x, y, z), Speed(vx, vy ,vz), explosivePower, timeFuelReserve));
            break;
        }
        case 5:
        {
            cout << mum << endl;
            break;
        }
        default:
            break;
        }

        if (choose == 0)
        {
            mum.Save();
            break;
        }
    }
}

int main()
{
    map<string, ObjectFactory*> Map; 
    Map["Star"] = new StarFactory;
    Map["Asteroid"] = new AsteroidFactory;
    Map["Spaceship"] = new SpaceshipFactory;
    Map["Rocket"] = new RocketFactory;

    ObjectCollection Temp("C:\\Users\\Lenovo\\Desktop\\Sem2\\OOP\\3\\4.3.txt", Map);
    Menu(Temp);
    // task2 = std::move(task);

    // cout << "============" << endl;
    // cout << task << endl;
    // cout << "============" << endl;
    // cout << task2 << endl;
    return 0;
}