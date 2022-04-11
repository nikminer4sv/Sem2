#include <iostream>

using namespace std;

class Position
{
private:
    size_t _X = 0;
    size_t _Y = 0;

public:
    Position() = default;

    Position(size_t x, size_t y)
    {
        this->_X = x;
        this->_Y = y;
    }

    ~Position()
    {
        _X = 0;
        _Y = 0;
    }

    void SetX(size_t x) { _X = x; }
    void SetY(size_t y) { _Y = y; }

    [[nodiscard]] size_t GetX() const { return _X; }
    [[nodiscard]] size_t GetY() const { return _Y; }
    
};

class Object
{
protected:
    Position _Position;
    char* _Color = nullptr;

    virtual ~Object() 
    {
        delete[] _Color;
    }

public:
    virtual void Print(ostream& stream) const {

        stream << "X & Y: " << _Position.GetX() << " " << _Position.GetY() << endl;
        stream << "Color: " << _Color << endl;

    }

    friend ostream& operator<<(ostream& os, const Object& obj) {
        obj.Print(os);
    }
};

class Shape : public Object
{
protected:
    float _Width = 0;
    float _Height = 0;

public:
    ~Shape()
    {
        _Width = 0;
        _Height = 0;
    }

    void Print(ostream& os) const {
        Object::Print(os);
        os << "width: " << _Width << endl;
        os << "height: " << _Height << endl << endl;
    }
};

class Rectangle : public Shape
{

public: 
    Rectangle() = default;

    Rectangle(Position position, float width, float height, char* color) {
        _Position = position;
        _Width = width;
        _Height = height;
        _Color = color;
    }

    void Print(ostream& os) const {
        os << "Rectangle" << endl;
        Shape::Print(os);
    }

};

class Ellipse : public Shape
{
public:
    Ellipse() = default;

    Ellipse(Position position, float width, float height, char* color) {
        _Position = position;
        _Width = width;
        _Height = height;
        _Color = color;
    }

    void Print(ostream& os) const {
        cout << "Ellipse" << endl;
        Shape::Print(os);
    }

};

class Star : public Shape
{
private:
    size_t _Peaks = 0;

public:
    Star() = default;

    Star(Position position, float width, float height, char* color, size_t peaks) {
        _Position = position;
        _Width = width;
        _Height = height;
        _Color = color;
        _Peaks = peaks;
    }

    ~Star() 
    {
        _Peaks = 0;
    }

    void Print(ostream& os) const {
        cout << "Star" << endl;
        Shape::Print(os);
    }
};

class Polygon : public Shape
{
private:
    size_t _Peaks = 0;

public:
    Polygon() = default;

    Polygon(Position position, float width, float height, char* color, size_t peaks) {
        _Position = position;
        _Width = width;
        _Height = height;
        _Color = color;
        _Peaks = peaks;
    }

    ~Polygon() 
    {
        _Peaks = 0;
    }

    void Print(ostream& os) const {
        cout << "Polygon" << endl;
        Shape::Print(os);
    }
};

class Text : public Object
{
private:
    float _TextSize = 0;
    char* _Text = nullptr;

public:
    Text() = default;

    Text(Position position, float textSize, char* text, char* color) {
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

    void Print(ostream& os) const 
    {
        cout << "Text" << endl;
        Object::Print(os);
        os << "text size: " << _TextSize << endl;
        os << "text: " << _Text << endl << endl;
    }
};

int main() {

    Rectangle re(Position(112, 113), 66, 88, "Green");
    Ellipse el(Position(411, 255), 255, 245, "Red");
    Star st(Position(356, 245), 116, 88, "Blue", 5);
    Polygon po(Position(653, 542), 611, 88, "Black", 5);
    Text txt(Position(1, 2), 14, "3,14zdec", "ebat'");
    cout << re << el << st << po << txt;

}