#pragma once

#include <fstream>
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

    Time(const Time& time) {
        _seconds = time.GetSeconds();
        _minutes = time.GetMinutes();
        _hours = time.GetHours();
    }

    Time(const size_t seconds, const size_t minutes, const size_t hours) {

        if (seconds >= 60 || minutes >= 60)
            throw invalid_argument("invalid time");

        _hours = hours;
        _minutes = minutes;
        _seconds = seconds;

    }

    Time(ifstream& stream) {
        stream >> _seconds;
        stream >> _minutes;
        stream >> _hours;
    }

    [[nodiscard]] size_t GetSeconds() const { return _seconds; }
    [[nodiscard]] size_t GetMinutes() const { return _minutes; }
    [[nodiscard]] size_t GetHours() const { return _hours; }

    void SetSeconds(size_t seconds) { _seconds = seconds; }
    void SetMinutes(size_t minutes) { _minutes = minutes; }
    void SetHours(size_t hours) { _hours = hours; }

    friend ostream& operator<< (ostream& os, const Time& time) {
        os << time._seconds << " " << time._minutes << " " << time._hours;
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

    Position(ifstream& stream) {
        stream >> _latitude;
        stream >> _longitude;
    }

    friend ostream& operator<< (ostream& os, const Position& position) {
        os << position._latitude << " " << position._longitude;
        return os;
    }

    [[nodiscard]] float GetLatitude() { return _latitude; }
    [[nodiscard]] float GetLongitude() { return _longitude; }

    void SetLatitude(float latitude) { _latitude = latitude; }
    void SetLongitude(float longitude) { _longitude = longitude; }

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

    [[nodiscard]] Position GetStartPoint() const { return _startPoint; }
    [[nodiscard]] Position GetEndPoint() const { return _endPoint; }
    [[nodiscard]] Time GetTime() const { return _time; }

    void SetStartPoint(const Position& position) { _startPoint = position; }
    void SetEndPoint(const Position& position) { _endPoint = position; }
    void SetTime(const Time& time) { _time = time; }

};

class MovingObject {
public:

    virtual ~MovingObject() = default;
    
    virtual string GetType() const = 0;

    virtual void Print(ostream& os) const {
        os << route << endl;
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
    double _rentCost;
    char* _rentUrl;

public:
    void Print(ostream& os) const {
        os << "car" << endl;
        os << _rentCost << endl;
        os << _rentUrl << endl;
        MovingObject::Print(os);
    }

public: 
    Car() = default;

    Car(const Route& route, const double rentCost, char* rentUrl) {
        this->_rentCost = rentCost;
        this->_rentUrl = rentUrl;
        this->route = route;
    }

    double GetRentCost() const { return _rentCost; }

    void SetRentCost(double rentCost) { _rentCost = rentCost; }

    string GetType() const { return "Car"; }

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
        os << "bus" << endl;
        PublicTransport::Print(os);
    }

public: 
    Bus() = default;

    Bus(const Route& route, const size_t& fare) {
        this->fare = fare;
        this->route = route;
    }

    string GetType() const { return "Bus"; }
};

class Trolleybus : public PublicTransport {
    void Print(ostream& os) const {
        os << "trolleybus" << endl;
        PublicTransport::Print(os);
    }

public: 
    Trolleybus() = default;

    Trolleybus(const Route& route, const size_t& fare) {
        this->fare = fare;
        this->route = route;
    }

    string GetType() const { return "Trolleybus"; }
};

class Metro : public PublicTransport {
    void Print(ostream& os) const {
        os << "metro" << endl;
        PublicTransport::Print(os);
    }

public: 
    Metro() = default;

    Metro(const Route& route, const size_t& fare) {
        this->fare = fare;
        this->route = route;
    }
    string GetType() const { return "Metro"; }
};

class RouteTaxi : public PublicTransport {
    void Print(ostream& os) const {
        os << "routetaxi" << endl;
        PublicTransport::Print(os);
    }

public:
    RouteTaxi() = default;

    RouteTaxi(const Route& route, const size_t& fare) {
        this->fare = fare;
        this->route = route;
    }
    string GetType() const { return "RouteTaxi"; }
};



/*int main() {
    vector<PublicTransport> objects;
    Bus a(Route(Position(1,1), Position(2,2), Time(3,3,3)), 10);
    Metro b(Route(Position(10,10), Position(20,20), Time(30,30,30)), 20);

    objects.push_back(a);
    objects.push_back(b);

    for (auto b : objects) 
        cout << b;

}  */ 