#include <iostream>
#include <vector>

using namespace std;

class Time {
private:
    size_t _seconds;
    size_t _minutes;
    size_t _hours;

public:

    Time() = default;

    Time(const size_t seconds, const size_t minutes, const size_t hours) {

        if (seconds >= 60 || minutes >= 60)
            throw invalid_argument("invalid time");

        _hours = hours;
        _minutes = minutes;
        _seconds = seconds;

    }

    [[nodiscard]] size_t GetSeconds() { return _seconds; }
    [[nodiscard]] size_t GetMinutes() { return _minutes; }
    [[nodiscard]] size_t GetHours() { return _hours; }

    friend ostream& operator<< (ostream& os, const Time& time) {
        os << "Time: " << time._seconds << " " << time._minutes << " " << time._hours;
        return os;
    }
};

class Position {
private:
    float _latitude;
    float _longitude;

public:
    Position() = default;

    Position(const float latitude, const float longitude) {

        if (latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180)
            throw invalid_argument("invalid position");

        _latitude = latitude;
        _longitude = longitude;

    }

    friend ostream& operator<< (ostream& os, const Position& position) {
        os << "Position: " << position._latitude << " " << position._longitude;
        return os;
    }

    [[nodiscard]] float GetLatitude() { return _latitude; }
    [[nodiscard]] float GetLongitude() { return _longitude; }

};

class Route {
private:
    Position _startPoint;
    Position _endPoint;
    Time _time;

public:

    Route() = default;

    Route(const Position& startPoint, const Position& endPoint, const Time& time) : 
            _startPoint(startPoint), _endPoint(endPoint), _time(time){}

    friend ostream& operator<< (ostream& os, const Route& route) {
        os << route._startPoint << endl << route._endPoint << endl << route._time;
        return os;
    }

    [[nodiscard]] Position GetStartPoint() { return _startPoint; }
    [[nodiscard]] Position GetEndPoint() { return _endPoint; }
    [[nodiscard]] Time GetTime() { return _time; }

};

class MovingObject {
public:

    virtual ~MovingObject() = default;

    virtual void Print(ostream& os) const {
        os << route;
    }

    friend ostream& operator<< (ostream& os, const MovingObject& movingObject) {
        movingObject.Print(os);
        return os;
    }

    [[nodiscard]] Route GetRoute() { return route; }

protected:
    MovingObject() = default;
    Route route;

};

class Car : public MovingObject {
protected:
    double rentCost;
    char* rentUrl;

public:
    void Print(ostream& os) const {
        os << "Type: Car" << endl;
        os << rentCost << endl;
        os << rentUrl << endl;
        MovingObject::Print(os);
    }

public: 
    Car() = default;

    Car(const Route& route, const double& rentCost, char* rentUrl) {
        this->rentCost = rentCost;
        this->rentUrl = rentUrl;
        this->route = route;
    }

};

class PublicTransport : public MovingObject {
public:
    virtual ~PublicTransport() = default;

protected:
    PublicTransport() = default;

public:
    
    void Print(ostream& os) const {
        os << fare << endl;
        MovingObject::Print(os);
    }

protected:
    size_t fare;

};

class Bus : public PublicTransport {
    void Print(ostream& os) const {
        os << "Type: Bus" << endl;
        PublicTransport::Print(os);
    }

public: 
    Bus() = default;

    Bus(const Route& route, const size_t& fare) {
        this->fare = fare;
        this->route = route;
    }
};

class Trolleybus : public PublicTransport {
    void Print(ostream& os) const {
        os << "Type: Trolleybus" << endl;
        PublicTransport::Print(os);
    }

public: 
    Trolleybus() = default;

    Trolleybus(const Route& route, const size_t& fare) {
        this->fare = fare;
        this->route = route;
    }
};

class Metro : public PublicTransport {
    void Print(ostream& os) const {
        os << "Type: metro" << endl;
        PublicTransport::Print(os);
    }

public: 
    Metro() = default;

    Metro(const Route& route, const size_t& fare) {
        this->fare = fare;
        this->route = route;
    }
};

class RouteTaxi : public PublicTransport {
    void Print(ostream& os) const {
        os << "Type: RouteTaxi" << endl;
        PublicTransport::Print(os);
    }

public:
    RouteTaxi() = default;

    RouteTaxi(const Route& route, const size_t& fare) {
        this->fare = fare;
        this->route = route;
    }
};



int main() {
    vector<PublicTransport> objects;
    Bus a(Route(Position(1,1), Position(2,2), Time(3,3,3)), 10);
    Metro b(Route(Position(10,10), Position(20,20), Time(30,30,30)), 20);

    objects.push_back(a);
    objects.push_back(b);

    for (auto b : objects) 
        cout << b;

}   

class Gg {
public:
    vector<MovingObject*> a;

    MovingObject get() { a[]}
}