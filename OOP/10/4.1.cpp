#include <iostream>
#include <fstream>

using namespace std;

class Position
{
private:
    int _X = 0;
    int _Y = 0;

public:
    Position()
    {
        system("cls");
        cout << "Enter position of your object\n"
            << "X:\t";
        cin >> _X;
        cout << "Y:\t";
        cin >> _Y;
    }

    Position(size_t x, size_t y)
    {
        this->_X = x;
        this->_Y = y;
    }

    ~Position() = default;

    // void Write(ofstream &of)
    // {
    //     Position Temp(this->_X, this->_Y);
    //     of.write((char*)&Temp, sizeof(Position));
    // }

    void SetX(size_t x) { _X = x; }
    void SetY(size_t y) { _Y = y; }

    [[nodiscard]] size_t GetX() const { return _X; }
    [[nodiscard]] size_t GetY() const { return _Y; }
    
};

class Object
{
public:
    Object()
    {
        _Color = new char[255];
        system("cls");
        cout << "Enter color of your object\n";
        cin >> _Color;
    }

    virtual ~Object() 
    {
        delete[] _Color;
    }

    virtual void Print(ostream& stream) const
    {
        stream << "X & Y: " << _Position.GetX() << " " << _Position.GetY() << endl;
        stream << "Color: " << _Color << endl;
    }

    friend ostream& operator<<(ostream& os, const Object& obj) 
    {
        obj.Print(os);
    }

protected:

    Position _Position;
    char* _Color = nullptr;
};

class Shape : public Object
{
protected:
    float _Width = 0;
    float _Height = 0;

public:
    Shape()
    {
        system("cls");
        cout << "Enter size of your object\n"
            << "Width:\t";
        cin >> _Width;
        cout << "Height:\t";
        cin >> _Height;
    }

    ~Shape()
    {
        _Width = 0;
        _Height = 0;
    }

    // void Print(ostream& os) const override 
    // {
    //     Object::Print(os);
    //     os << "width: " << _Width << endl;
    //     os << "height: " << _Height << endl << endl;
    // }
};

class Rectangle : public Shape
{
public: 
    Rectangle() = default;
    ~Rectangle() = default;

    Rectangle(Position position, float width, float height, char* color) 
    {
        _Position = position;
        _Width = width;
        _Height = height;
        _Color = color;
    }

    void Print(ostream& os) const override 
    {
        os << "Rectangle" << endl;
        Shape::Print(os);
    }

    // void Write(ofstream &of)
    // {
    //     Rectangle Temp(this->_Position, this->_Width, this->_Height, this->_Color);
    //     of.write((char*)&Temp, sizeof(Rectangle));
    // }
};

class Ellipse : public Shape
{
public:
    Ellipse() = default;
    ~Ellipse() = default;

    Ellipse(Position position, float width, float height, char* color) 
    {
        _Position = position;
        _Width = width;
        _Height = height;
        _Color = color;
    }

    void Print(ostream& os) const override 
    {
        cout << "Ellipse" << endl;
        Shape::Print(os);
    }

    // void Write(ofstream &of)
    // {
    //     Ellipse Temp(this->_Position, this->_Width, this->_Height, this->_Color);
    //     of.write((char*)&Temp, sizeof(Ellipse));
    // }
};

class Star : public Shape
{
private:
    int _Peaks = 0;

public:
    Star()
    {
        system("cls");
        cout << "Enter amount of peaks\n";
        cin >> _Peaks;
    }

    ~Star() = default;

    Star(Position position, float width, float height, char* color, size_t peaks) 
    {
        _Position = position;
        _Width = width;
        _Height = height;
        _Color = color;
        _Peaks = peaks;
    }

    void Print(ostream& os) const override 
    {
        cout << "Star" << endl;
        Shape::Print(os);
    }

    // void Write(ofstream &of)
    // {
    //     Star Temp(this->_Position, this->_Width, this->_Height, this->_Color, this->_Peaks);
    //     of.write((char*)&Temp, sizeof(Star));
    // }
};

class Polygon : public Shape
{
private:
    size_t _Peaks = 0;

public:
    Polygon()
    {
        system("cls");
        cout << "Enter amount of peaks\n";
        cin >> _Peaks;
    }

    ~Polygon() = default;

    Polygon(Position position, float width, float height, char* color, size_t peaks) 
    {
        _Position = position;
        _Width = width;
        _Height = height;
        _Color = color;
        _Peaks = peaks;
    }

    void Print(ostream& os) const override 
    {
        cout << "Polygon" << endl;
        Shape::Print(os);
    }

    // void Write(ofstream &of)
    // {
    //     Polygon Temp(this->_Position, this->_Width, this->_Height, this->_Color, this->_Peaks);
    //     of.write((char*)&Temp, sizeof(Polygon));
    // }
};

class Text : public Object
{
private:
    int _TextSize = 0;
    char* _Text = nullptr;

public:
    Text()
    {
        _Text = new char[255];
        system("cls");
        cout << "Enter text\n";
        cin >> _Text;
        cout << "Enter size of text\n";
        cin >> _TextSize;
    }

    Text(Position position, int textSize, char* text, char* color) 
    {
        _Position = position;
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
        cout << "Text" << endl;
        Object::Print(os);
        os << "text size: " << _TextSize << endl;
        os << "text: " << _Text << endl << endl;
    }

    // void Write(ofstream &of)
    // {
    //     Text Temp(this->_Position, this->_TextSize, this->_Text, this->_Color);
    //     of.write((char*)&Temp, sizeof(Text));
    // }
};

// int main() 
// {
//     Rectangle re(Position(112, 113), 66, 88, "Green");
//     Ellipse el(Position(411, 255), 255, 245, "Red");
//     Star st(Position(356, 245), 116, 88, "Blue", 5);
//     Polygon po(Position(653, 542), 611, 88, "Black", 5);
//     Text txt(Position(1, 2), 14, "3,14zdec", "ebat'");
//     cout << re << el << st << po << txt;
// }