#include <iostream>
#include "4.1.cpp"
#include <vector>

using namespace std;

class Collection {
private:
    vector<MovingObject*> _collection;
    
    inline void IndexValidation(size_t index) const {
        if (index >= _collection.size())
            throw invalid_argument("Invalid index!");
    }

public:
    Collection() = default;


    Collection(const Collection& collection) { _collection = collection._collection; }

    Collection(Collection&& other) {
        cout << "This is test message!----------------------------" << endl;
        _collection = std::move(other._collection);
    }

    void Append(MovingObject* object) { _collection.push_back(object); }

    void Clear() {
        _collection.clear();
    }

    MovingObject* GetMovingObject(const size_t index) const { return _collection[index]; }

    void Remove(size_t index) { 
        IndexValidation(index);
        vector<MovingObject*>::iterator it = _collection.begin();
        advance(it, index);
        _collection.erase(it); 
    }

    friend std::ostream& operator <<(std::ostream& str, const Collection& c) {
        for (const auto* MovingObject : c._collection)
            str << *MovingObject;

        return str;
    }

    MovingObject*& operator[](size_t index) {
        IndexValidation(index);
        return _collection[index];
    }

    Collection& operator = (const Collection& collection){
        _collection = collection._collection;
        return *this;
    }

    Collection& operator = (Collection&& collection){

        if (!(this == &collection)) 
            _collection = std::move(collection._collection);

        return *this;
    }

    //std::move
};

int main() {

    char* text = new char[256] {'H'};

    Bus bus(Route(Position(1,1), Position(2,2), Time(1,1,1)), 10);
    RouteTaxi taxi(Route(Position(1,1), Position(2,2), Time(1,1,1)), 10);
    Car car(Route(Position(1,1), Position(2,2), Time(1,1,1)), 10, text);

    Collection col;

    col.Append(&bus);
    col.Append(&taxi);
    col.Append(&car);

    Collection col2 = std::move(col);

    cout << col2;

}