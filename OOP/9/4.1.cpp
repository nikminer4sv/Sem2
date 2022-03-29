#include <iostream>

using namespace std;

class Time {
public:
    size_t seconds;
    size_t minutes;
    size_t hours;

    Time() = default;

    Time(const size_t& seconds, const size_t& minutes, const size_t& hours) : 
        seconds(seconds), minutes(minutes), hours(hours) {}

    friend ostream& operator<< (ostream& os, const Time& time) {
        os << "Time: " << time.seconds << " " << time.minutes << " " << time.hours;
        return os;
    }
};

struct Position {
    float latitude;
    float longitude;

    Position() = default;

    Position(const float& latitude, const float& longitude) : 
        latitude(latitude), longitude(longitude) {}

    friend ostream& operator<< (ostream& os, const Position& position) {
        os << "Position: " << position.latitude << " " << position.longitude;
        return os;
    }
};

class Route {
public:
    Position startPoint;
    Position endPoint;
    Time time;

    Route() = default;

    Route(const Position& startPoint, const Position& endPoint, const Time& time) : 
            startPoint(startPoint), endPoint(endPoint), time(time){}

    friend ostream& operator<< (ostream& os, const Route& route) {
        os << route.startPoint << endl << route.endPoint << endl << route.time;
        return os;
    }

};

class MovingObject {
public:
    Route route;

    virtual void Print(ostream& os) const {
        os << route;
    }

    friend ostream& operator<< (ostream& os, const MovingObject& movingObject) {
        movingObject.Print(os);
        return os;
    }

};

class Car : public MovingObject {
    double rentCost;
    char* rentUrl;

    void Print(ostream& os) const {
        os << "Type: Car" << endl;
        os << rentCost << endl;
        os << rentUrl << endl;
        os << route << endl;
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
    size_t fare;
};

class Bus : public PublicTransport {
    void Print(ostream& os) const {
        os << "Type: Bus" << endl;
        os << fare << endl;
        os << route << endl;
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
        os << fare << endl;
        os << route << endl;
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
        os << fare << endl;
        os << route << endl;
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
        os << fare << endl;
        os << route << endl;
    }

public:
    RouteTaxi() = default;

    RouteTaxi(const Route& route, const size_t& fare) {
        this->fare = fare;
        this->route = route;
    }
};

int main() {

    Car b(Route(Position(1,1), Position(2,2), Time(3,3,3)), 10, "Hello");
    cout << b;

}   