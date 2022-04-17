#include <iostream>
#include <fstream>

using namespace std;

class Position
{
private:
    int _X = 0;
    int _Y = 0;

public:
    Position() = default;

    Position(size_t x, size_t y)
    {
        this->_X = x;
        this->_Y = y;
    }

    Position(const Position& temp)
    {
        _X = temp.GetX();
        _Y = temp.GetY();
    }

    ~Position() = default;

    Position& operator= (const Position& temp)
    {
        _X = temp.GetX();
        _Y = temp.GetY();

        return *this;
    }

    void SetX(size_t x) { _X = x; }
    void SetY(size_t y) { _Y = y; }

    [[nodiscard]] size_t GetX() const { return _X; }
    [[nodiscard]] size_t GetY() const { return _Y; }
};

class Object
{
public:
    Object() = default;

    virtual ~Object()
    {
        delete[] _Color;
    }

    virtual void Print(ostream& stream) const
    {
        stream << "X & Y: " << (*_Position).GetX() << " " << (*_Position).GetY() << endl;
        stream << "Color: " << _Color << endl;
    }

    virtual void Write(ofstream& of) const
    {
        of << (*_Position).GetX() << endl
            << (*_Position).GetY() << endl
            << _Color << endl;
    }

    virtual void Add()
    {
        int _X, _Y;
        system("cls");
        cout << "Enter position of your object\n"
            << "X:\t";
        cin >> _X;
        cout << "Y:\t";
        cin >> _Y;
        _Position = new Position(_X, _Y);
        _Color = new char[255];
        cout << "Enter color of your object\n";
        cin >> _Color;
    }

    friend ostream& operator<<(ostream& os, const Object& obj)
    {
        obj.Print(os);

        return os;
    }

protected:
    Position* _Position;
    char* _Color = nullptr;
};

class Shape : public Object
{
protected:
    float _Width = 0;
    float _Height = 0;

public:
    Shape() = default;

    ~Shape()
    {
        _Width = 0;
        _Height = 0;
    }

    void Print(ostream& os) const override
    {
        Object::Print(os);
        os << "width: " << _Width << endl;
        os << "height: " << _Height << endl;
    }

    void Write(ofstream& of) const override
    {
        Object::Write(of);
        of << _Width << endl
            << _Height << endl;
    }

    void Add() override
    {
        Object::Add();
        system("cls");
        cout << "Enter size of your object\n"
            << "Width:\t";
        cin >> _Width;
        cout << "Height:\t";
        cin >> _Height;
    }
};

class Rectangle : public Shape
{
public:
    Rectangle() = default;

    ~Rectangle() = default;

    Rectangle(const Position& position, float width, float height, char* color)
    {
        _Position = new Position(position);
        _Width = width;
        _Height = height;
        _Color = color;
    }

    void Print(ostream& os) const override
    {
        os << "Rectangle" << endl;
        Shape::Print(os);
        os << endl;
    }

    void Write(ofstream& of) const override
    {
        of << "Rectangle" << endl;
        Shape::Write(of);
    }

    void Add() override
    {
        Shape::Add();
    }
};

class Ellipse : public Shape
{
public:
    Ellipse() = default;

    ~Ellipse() = default;

    Ellipse(const Position& position, float width, float height, char* color)
    {
        _Position = new Position(position);
        _Width = width;
        _Height = height;
        _Color = color;
    }

    void Print(ostream& os) const override
    {
        os << "Ellipse" << endl;
        Shape::Print(os);
        os << endl;
    }

    void Write(ofstream& of) const override
    {
        of << "Ellipse" << endl;
        Shape::Write(of);
    }

    void Add() override
    {
        Shape::Add();
    }
};

class Star : public Shape
{
private:
    int _Peaks = 0;

public:
    Star() = default;

    ~Star() = default;

    Star(const Position& position, float width, float height, char* color, size_t peaks)
    {
        _Position = new Position(position);
        _Width = width;
        _Height = height;
        _Color = color;
        _Peaks = peaks;
    }

    void Print(ostream& os) const override
    {
        os << "Star" << endl;
        Shape::Print(os);
        os << "Peaks: " << _Peaks << endl << endl;
    }

    void Write(ofstream& of) const override
    {
        of << "Star" << endl;
        Shape::Write(of);
        of << _Peaks << endl;
    }

    void Add() override
    {
        Shape::Add();
        system("cls");
        cout << "Enter amount of peaks\n";
        cin >> _Peaks;
    }
};

class Polygon : public Shape
{
private:
    size_t _Peaks = 0;

public:
    Polygon() = default;

    ~Polygon() = default;

    Polygon(const Position& position, float width, float height, char* color, size_t peaks)
    {
        _Position = new Position(position);
        _Width = width;
        _Height = height;
        _Color = color;
        _Peaks = peaks;
    }

    void Print(ostream& os) const override
    {
        os << "Polygon" << endl;
        Shape::Print(os);
        os << "Peaks: " << _Peaks << endl << endl;
    }

    void Write(ofstream& of) const override
    {
        of << "Polygon" << endl;
        Shape::Write(of);
        of << _Peaks << endl;
    }

    void Add() override
    {
        Shape::Add();
        system("cls");
        cout << "Enter amount of peaks\n";
        cin >> _Peaks;
    }
};

class Text : public Object
{
private:
    int _TextSize = 0;
    char* _Text = nullptr;

public:
    Text() = default;

    Text(const Position& position, int textSize, char* text, char* color)
    {
        _Position = new Position(position);
        _TextSize = textSize;
        _Text = text;
        _Color = color;
    }

    ~Text()
    {
        _TextSize = 0;
        delete[] _Text;
    }

    void Print(ostream& os) const override
    {
        os << "Text" << endl;
        Object::Print(os);
        os << "text size: " << _TextSize << endl;
        os << "text: " << _Text << endl
            << endl;
    }

    void Write(ofstream& of) const override
    {
        of << "Text" << endl;
        Object::Write(of);
        of << _TextSize << endl
            << _Text << endl;
    }

    void Add() override
    {
        Object::Add();
        _Text = new char[255];
        system("cls");
        cout << "Enter text\n";
        cin >> _Text;
        cout << "Enter size of text\n";
        cin >> _TextSize;
    }
};