#include <iostream>
#include "Common/nikminer4sv.h"
#include "4.1.cpp"

using namespace std;
using namespace nikminer4sv;

class Container {
private:
    List<MovingObject*> _objects;

public:
    Container() = default;

    Container(const Container& container) {
        _objects = container._objects;
    }

    Container(Container&& obj) {
        _objects = move(obj._objects);
    }

    void Append(MovingObject* object) { _objects.Append(object); }

    MovingObject* operator[](size_t index) {
        if(index >= _objects.GetSize())
            throw std::invalid_argument("index is out of bounds");

        return _objects.Get(index);
    }

    const MovingObject* operator[](size_t index) const {
        if(index >= _objects.GetSize())
            throw std::invalid_argument("index is out of bounds");

        return _objects.Get(index);
    }

    void Remove(size_t index) {
        if(index >= _objects.GetSize())
            throw std::invalid_argument("index is out of bounds");

        _objects.Remove(index);
    }

    void Clear() {
        _objects.Clear();
    }

    [[nodiscard]] size_t GetSize() const { return _objects.GetSize(); }

    friend ostream& operator<< (ostream& os, const Container& container) {
        for (size_t i = 0; i < container.GetSize(); i++)
            os << *container[i] << endl;

        return os;
    }

    ~Container() = default;

};

int main() {

    Container con;
    
    con.Append(new Bus (Route(Position(1,1), Position(2,2), Time(1,1,1)), 10));
    con.Append(new Bus (Route(Position(2,2), Position(3,3), Time(1,1,1)), 69));

    Container con2(con);

    cout << con2;

    con.Remove(0);

    cout << "-------------" << endl;

}