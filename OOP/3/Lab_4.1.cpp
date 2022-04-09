#include <iostream>
#include <cstring>

using namespace std;

class Position
{
private:
    float _X = 0, _Y = 0, _Z = 0;

public:
    Position() = default;

    Position(const float X, const float Y, const float Z)
    {
        this->_X = X;
        this->_Y = Y;
        this->_Z = Z;
    }

    [[nodiscard]] float getX() {return _X;}
    [[nodiscard]] float getY() {return _Y;}
    [[nodiscard]] float getZ() {return _Z;}

    friend ostream& operator<< (ostream& os, const Position& position) {
        os << "Position: " << position._X << " " << position._Y << " " << position._Z << " ";
        return os;
    }
};

class Speed
{
private:
    float _Vx = 0, _Vy = 0, _Vz = 0, _maxSpeed = 0;
public:
    Speed() = default;

    Speed(const float Vx, const float Vy, const float Vz)
    {
        this->_Vx = Vx;
        this->_Vy = Vy;
        this->_Vz = Vz;
    }

    Speed(const float Vx, const float Vy, const float Vz, const float maxSpeed) : Speed (Vx, Vy, Vz)
    {
        this->_maxSpeed = maxSpeed;
    }
    
    [[nodiscard]] float getVx() const {return _Vx;}
    [[nodiscard]] float getVy() const {return _Vy;}
    [[nodiscard]] float getVz() const {return _Vz;}
    [[nodiscard]] float getMaxSpeed() const {return _maxSpeed;}

    friend ostream& operator<< (ostream& os, const Speed& speed) {
        os << "Speed: " << speed._Vx << " " << speed._Vy << " " << speed._Vz << " ";
        return os;
    }
};

class MyObject
{
public:
    MyObject() = default; 

    virtual ~MyObject() = default;

    virtual void Print (ostream& os) const
    {
        os << this->_positon << endl << this->_speed;
    }

    friend ostream& operator<< (ostream& os, const MyObject& myObject) {
        myObject.Print(os);
        return os;
    }
protected:
    Speed _speed;

    Position _positon;    

    size_t getSizeName(const char* name)
    {
        size_t _sizeName = 0;
        for (int i = 0; name[i] != '\0'; i++)
            _sizeName++;  
        return _sizeName;
    }

};

class Star : public MyObject
{
private:
    char* _name = nullptr;
    int _temperature = 0;
    bool _isSolidSurface = false;

public:
    Star() = default;

    Star(const char* name, const int& temperature, const bool isSolidSurface)
    {   
        this->_temperature = temperature;
        this->_name = new char[MyObject::getSizeName(name) + 1];
        memcpy(this->_name, name, MyObject::getSizeName(name) + 1);
        this->_isSolidSurface = isSolidSurface;
    }

    virtual void Print (ostream& os) const override
    {
        os << "Star: " << "name = " << this->_name << ", temperature = " <<
        this->_temperature << ", solid surface = " << this->_isSolidSurface << " " << endl;
    }

    ~Star() override { if (this->_name != nullptr) delete[] this->_name; }
    // char* getName() const
    // {
    //     char* _name = new char[this->_size];
    //     memcpy(_name, this->_name, this->_size);
    //     return _name;
    // }

    // size_t getSize() const
    // {
    //     return this->_size;
    // }

    // int getTemperature() const
    // {
    //     return this->_temperature;
    // }

    // bool SolidSurface() const
    // {
    //     return this->_isSolidSurface;
    // } 
};


class Asteroid : public MyObject
{
private:
    size_t _maxSize = 0;

public:
    Asteroid() = default;

    Asteroid(const Position position, const Speed speed, const size_t& maxSizeObject)
    {
        //_ammunition = ammunition;
        MyObject::_positon = position;
        MyObject::_speed = speed;
        this->_maxSize = maxSizeObject;
    }

    virtual void Print (ostream& os) const override
    {
        os << "Asteroid: " << "max size = " << this->_maxSize << endl;
        MyObject::Print(os);
    }
};

class Spaceship : public MyObject
{
private:
    char* _name = nullptr;
    size_t _ammunition = 0;

public:
    Spaceship(const Position& position, const Speed& speed, const char name[], const size_t& ammunition)
    {
        this->_name = new char[MyObject::getSizeName(name) + 1];
        memcpy(this->_name, name, MyObject::getSizeName(name) + 1);
        MyObject::_positon = position;
        MyObject::_speed = speed;

        this->_ammunition = ammunition;
    }

    virtual void Print (ostream& os) const override
    {
        os << "Spaceship: " << this->_name << endl 
        << "Ammunition: " << this->_ammunition << endl
        << "Max speed: " << MyObject::_speed.getMaxSpeed() << endl;
        MyObject::Print(os);
    }

    Spaceship() = default;
    ~Spaceship() override { if (this->_name != nullptr) delete[] this->_name; }   
};

class Rocket : public MyObject
{
private:
    size_t _explosivePower = 0;
    size_t _timeFuelReserve = 0;
public:
    Rocket() = default;

    Rocket(const Position& position, const Speed& speed, const size_t& explosivePower, const size_t& timeFuelReserve)
    {
        MyObject::_positon = position;
        MyObject::_speed = speed;

        this->_explosivePower = explosivePower;
        this->_timeFuelReserve = timeFuelReserve;
    }

    virtual void Print (ostream& os) const override
    {
        os << "Explosive power: "<< this->_explosivePower 
        << " , time fuel reserve: " << this->_timeFuelReserve << endl;
        MyObject::Print(os);
    }
};

int main()
{
    const size_t SIZE = 255;
    char* _name = new char[SIZE];
    cout << "Enter the _name of Star: " << endl;
    cin.getline(_name, SIZE);

    Star obj(_name, 90, true);
    cout << obj << endl;

    Asteroid obj2(Position(1, 1, 1), Speed(2, 2, 2), 5);
    cout << obj2 << endl << endl;

    Spaceship obj3(Position(11, 14, 23), Speed(10, 10, 10, 110), "ORBITA-8", 250);
    cout << obj3 << endl << endl;

    Rocket obj4(Position(23, 56, 21), Speed(9, 2 ,4), 1100, 12405);
    cout << obj4 << endl;
    
    return 0;
}