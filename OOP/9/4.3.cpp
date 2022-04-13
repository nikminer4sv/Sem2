#include <iostream>
#include "4.1.cpp"
#include <vector>
#include <fstream>

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

    size_t GetSize() const { return _collection.size(); }

    //std::move
};

void Save(Collection& collection) {

    ofstream stream;
    stream.open("collection.txt");

    for (size_t i = 0; i < collection.GetSize(); i++) {
        Route route = collection[i]->GetRoute();
        cout << route.GetStartPoint().GetLatitude() << " " << route.GetStartPoint().GetLatitude() << endl;
    }

}

int main() {

    char* text = new char[256] {'H'};

    Bus bus(Route(Position(1,1), Position(2,2), Time(1,1,1)), 10);
    RouteTaxi taxi(Route(Position(1,1), Position(2,2), Time(1,1,1)), 10);
    Car car(Route(Position(1,1), Position(2,2), Time(1,1,1)), 10, text);

    Collection col;

    col.Append(&bus);
    col.Append(&taxi);
    col.Append(&car);

    Save(col);

}

class MovingObjectFactory{
    MovingObject* CreateObject(std::string&) = 0;
}

class CarObjectFactory : MovingObjectFactory{
    MovingObject* CreateObject(std::string&) override{
        return new CarObject(...);
    }
}

std::map<string, MovingObjectFactory*> factories;
factories["car"] = new CarFactory();
factories["bus"] = new BusFactory();


void load(Collection c, const char* filename){
    std::ifstream str(filename);

    std::string type;
    stream >> type;

    c.Append(factories[type].CreateObject(type));
}
stream >> type;

collection.Add(factories[type.CreateObject(stream));

if(type == ...){
    new Car
}
else if(type == ...){
    new ....
}
