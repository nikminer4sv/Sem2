#include <iostream>
#include "Lab_4.1.cpp"
#include "For_4.4.h"

using namespace std;

class VectorTask : List<Object *>
{
private:
    List<Object *> helpPLS;

public:
    void Add(Object *trash)
    {
        helpPLS.Add(trash);
    }

    friend ostream &operator<<(ostream &os, VectorTask &vector)
    {
        vector.helpPLS.Print(os);
        return os;
    }

public:

    VectorTask() = default;

    VectorTask(VectorTask &&obj)
    {
        helpPLS = std::move(obj.helpPLS);
    }

    VectorTask &operator=(VectorTask &&obj)
    {
        helpPLS = std::move(obj.helpPLS);
        return *this;
    }
};


void Menu(VectorTask &mum)
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

            mum.Add(new Star(name, temperature, solidSurface));

           
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

            mum.Add(new Asteroid(Position(x, y, z),Speed(vx, vy, vz), maxSize));

            break;
        }
        case 3:
        {
            cout << "Fill a Spaceship" << endl;

            const size_t SIZE = 255;
            char *name = new char[SIZE];
            cin.get();
            cout << "Enter the name of Star: " << endl;
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

            mum.Add(new Spaceship(Position(x, y, z), Speed(vx, vy, vz), maxSpeed, name, ammunition));

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

            mum.Add(new Rocket(Position(x, y, z), Speed(vx, vy ,vz), explosivePower, timeFuelReserve));
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
            break;
    }
}

int main()
{
    VectorTask task;
    Menu(task);
    return 0;
}