#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Position
{
private:
    float _X = 0, _Y = 0, _Z = 0;

public:
    Position() = default;

    Position(const float& X, const float& Y, const float& Z)
    {
        _X = X;
        _Y = Y;
        _Z = Z;
    }

    [[nodiscard]] float getX() const {return _X;}
    [[nodiscard]] float getY() const {return _Y;}
    [[nodiscard]] float getZ() const {return _Z;}

    friend ostream& operator<< (ostream& os, const Position& position) {
        os << "Position: " << position._X << " " << position._Y << " " << position._Z << " ";
        return os;
    }
};

class Speed 
{
private:
    float _Vx = 0, _Vy = 0, _Vz = 0;
public:
    Speed() = default;

    Speed(const float& Vx, const float& Vy, const float& Vz)
    {
        _Vx = Vx;
        _Vy = Vy;
        _Vz = Vz;
    }

    [[nodiscard]] float getVx() const {return _Vx;}
    [[nodiscard]] float getVy() const {return _Vy;}
    [[nodiscard]] float getVz() const {return _Vz;}

    friend ostream& operator<< (ostream& os, const Speed& speed) {
        os << "Speed: " << speed._Vx << " " << speed._Vy << " " << speed._Vz << " ";
        return os;
    }
};

class Object
{
public:
    virtual void Write(ofstream& of) 
    {
        if (_name)
            of << _name << endl;

        of << _position.getX() << " " << _position.getY() << " " << _position.getZ() << endl;
    }

    virtual void Print (ostream& os) const
    {
        os << _position << endl << endl;
    }

protected:
    Position _position;  
    char* _name = nullptr;

    Object() = default; 

    virtual ~Object() = default;

    Object(const Position& pos, const char* name = nullptr) {
        _position = pos;
        _name = _strdup(name);
    }

    friend ostream& operator<< (ostream& os, const Object& object) {
        object.Print(os);
        return os;
    }  

};

class MovableObject : public Object
{
public:
    void Write(ofstream& of) override
    {
        Object::Write(of);
        of << _speed.getVx() << " " << _speed.getVy() << " " << _speed.getVz() << endl;
    }
protected:
    Speed _speed; 

    MovableObject() = default; 

    MovableObject(const Position& position,const Speed& speed, const char* name = nullptr)
    : Object(position, name)
    {
        _speed = speed;
    }

    void Print (ostream& os) const override
    {
        os << _speed << endl;
        Object::Print(os);
        os << endl;
    }

    virtual ~MovableObject() = default;

    friend ostream& operator<< (ostream& os, const MovableObject& object) {
        object.Print(os);

        return os;
    }


};

class Star : public Object
{
private:
    float _temperature = 0;
    bool _isSolidSurface = false;

public:
    Star() = default;

    Star(const char* name, const float temperature, const bool isSolidSurface) : Object(Position(), name)
    {
        _temperature = temperature;
        _isSolidSurface = isSolidSurface;
    }

    void Write(ofstream& of) override
    {
        of << "Star" << endl;
        of << _name << endl
        << _temperature << endl
        << _isSolidSurface << endl;
    }

    void Print (ostream& os) const override
    {
        os << "Star: " << "name = " << _name << ", temperature = " <<
        _temperature << ", solid surface = " << _isSolidSurface << " " << endl << endl;
    }

    ~Star() override { if (_name != nullptr) delete[] _name; }
};


class Asteroid : public MovableObject
{
private:
    float _maxSize = 0;

public:
    Asteroid() = default;

    Asteroid(const Position& position, const Speed& speed, const float& maxSizeObject) : MovableObject(position ,speed)
    {
        _maxSize = maxSizeObject;
    }

    void Write(ofstream& of) override
    {
        of << "Asteroid" << endl;
        of << _maxSize << endl;
        MovableObject::Write(of);
    }

    void Print (ostream& os) const override
    {
        os << "Asteroid: " << "max size = " << _maxSize << endl;
        MovableObject::Print(os);
        os << endl;
    }
};

class Spaceship : public MovableObject
{
private:
    size_t _ammunition = 0;
    float _maxSpeed = 0;

public:
    Spaceship(const Position& position, const Speed& speed, const float& maxSpeed, const char* name, const size_t& ammunition)
    : MovableObject(position, speed, name)
    {
        _maxSpeed = maxSpeed;
        _ammunition = ammunition;
    }

    void Write(ofstream& of) override
    {
        of << "Spaceship" << endl;
        of << _ammunition << endl << _maxSpeed << endl;
        MovableObject::Write(of);    
    }

    void Print (ostream& os) const override
    {
        os << "Spaceship: " << _name << endl 
        << "Ammunition: " << _ammunition << endl
        << "Max speed: " << _maxSpeed << endl;
        MovableObject::Print(os);
        os << endl;
    }

    Spaceship() = default;
    ~Spaceship() override { if (_name != nullptr) delete[] _name; }   
};

class Rocket : public MovableObject
{
private:
    size_t _explosivePower = 0, _timeFuelReserve = 0;
public:
    Rocket() = default;

    Rocket(const Position& position, const Speed& speed, const size_t& explosivePower, const size_t& timeFuelReserve)
    : MovableObject(position, speed)
    {
        _explosivePower = explosivePower;
        _timeFuelReserve = timeFuelReserve;
    }

    void Write(ofstream& of) override
    {
        of << "Rocket" << endl;
        of << _explosivePower << endl << _timeFuelReserve << endl;
        MovableObject::Write(of);
    }

    void Print (ostream& os) const override
    {
        os << "Explosive power: "<< _explosivePower 
        << " , time fuel reserve: " << _timeFuelReserve << endl;
        MovableObject::Print(os);
        os << endl;
    }
};

// int main()
// {
//     const size_t SIZE = 255;
//     char* name = new char[SIZE];
//     cout << "Enter the name of Star: " << endl;
//     cin.getline(name, SIZE);

//     Star obj(name, 90, true);
//     cout << obj << endl;

//     Asteroid obj2(Position(1, 1, 1), Speed(2, 2, 2), 5);
//     cout << obj2 << endl << endl;

//     Spaceship obj3(Position(11, 14, 23), Speed(10, 10, 10), 180, "ORBITA-8", 250);
//     cout << obj3 << endl << endl;

//     Rocket obj4(Position(23, 56, 21), Speed(9, 2 ,4), 1100, 12405);
//     cout << obj4 << endl;
    
//     return 0;
// }