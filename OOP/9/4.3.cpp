#include <iostream>
#include "4.1.cpp"
#include <vector>
#include <fstream>
#include <map>

using namespace std;

class MovingObjectFactory {
public: 

    virtual MovingObject* CreateObject(ifstream& stream) = 0;

    /*

    virtual MovingObject* CreateObject(string type) {

        MovingObject* object = nullptr;

        if (type == "Bus")
            object = new Bus(Route(Position(1,1), Position(2,2), Time(1,1,1)), 10);

        return object;

    }

    */
};

class BusFactory : public MovingObjectFactory {
public:
    virtual MovingObject* CreateObject(ifstream& stream) {
        int fare;
        stream >> fare;
        Position startPoint(stream);
        Position endPoint(stream);
        Time time(stream);
        Route route(startPoint, endPoint, time);
        Bus* object = new Bus(route, fare);
        return object;
    }
};

class TrolleybusFactory : public MovingObjectFactory {
public:
    virtual MovingObject* CreateObject(ifstream& stream) {
        int fare;
        stream >> fare;
        Position startPoint(stream);
        Position endPoint(stream);
        Time time(stream);
        Route route(startPoint, endPoint, time);
        Trolleybus* object = new Trolleybus(route, fare);
        return object;
    }
};

class RouteTaxiFactory : public MovingObjectFactory {
public:
    virtual MovingObject* CreateObject(ifstream& stream) {
        int fare;
        stream >> fare;
        Position startPoint(stream);
        Position endPoint(stream);
        Time time(stream);
        Route route(startPoint, endPoint, time);
        RouteTaxi* object = new RouteTaxi(route, fare);
        return object;
    }
};
class MetroFactory : public MovingObjectFactory {
public:
    virtual MovingObject* CreateObject(ifstream& stream) {
        int fare;
        stream >> fare;
        Position startPoint(stream);
        Position endPoint(stream);
        Time time(stream);
        Route route(startPoint, endPoint, time);
        Metro* object = new Metro(route, fare);
        return object;
    }
};
class CarFactory : public MovingObjectFactory {
public:
    virtual MovingObject* CreateObject(ifstream& stream) {
        double rentCost;
        char* rentUrl = new char[255];
        stream >> rentCost;
        stream >> rentUrl;
        Position startPoint(stream);
        Position endPoint(stream);
        Time time(stream);
        Route route(startPoint, endPoint, time);
        Car* object = new Car(route, rentCost, rentUrl);
        return object;
    }
};

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

    Collection(string name, map<string, MovingObjectFactory*> factories) {

        ifstream stream;
        stream.open(name);

        if (stream.is_open()) {

            string type;
            stream >> type;
            while (!stream.eof()) {

                MovingObject* object = factories[type]->CreateObject(stream);
                _collection.push_back(object);
                stream >> type;

            }

        }

    }

    void Save(ofstream& stream) {

        for (MovingObject* object : _collection) {
            stream << *object;
        }

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

};

int main() {

    map<string, MovingObjectFactory*> factories;
    factories["bus"] = new BusFactory;
    factories["car"] = new CarFactory;
    factories["trolleybus"] = new TrolleybusFactory;
    factories["metro"] = new MetroFactory;
    factories["routetaxi"] = new RouteTaxiFactory;

    Bus bus(Route(Position(1,1), Position(2,2), Time(1,1,1)), 10);
    RouteTaxi taxi(Route(Position(1,1), Position(2,2), Time(1,1,1)), 10);
    //Car car(Route(Position(1,1), Position(2,2), Time(1,1,1)), 10, text);

    Collection col("collection.txt", factories);

    //cout << col;

    ofstream stream;
    stream.open("collection.txt");
    //col.Save(stream);
    cout << col;
    col.Save(stream);

    //cout << col;

    /*col.Append(&bus);
    col.Append(&taxi);
    col.Append(&car);*/

    //Save(col);

    /*ifstream stream;
    stream.open("collection.txt");

    string type;
    stream >> type;
    
    MovingObject* object = factories[type]->CreateObject(stream);

    cout << *object;

    stream >> type;
    
    object = factories[type]->CreateObject(stream);

    cout << *object;*/

}
