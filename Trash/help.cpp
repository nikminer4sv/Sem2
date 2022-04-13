#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Date {
private:
    unsigned short _day = 0;
    unsigned short _month = 0;
    unsigned short _year = 0;
 
 public:

    // CONSTRUCTORS
    Date() = default;

    Date(const Date& date) {
        _day = date.GetDay();
        _month = date.GetMonth();
        _year = date.GetYear();
    }
 
    Date(unsigned short day, unsigned short month, unsigned short year) {
        _day = day;
        _month = month;
        _year = year;
    }
 
    // METHOD FOR DATE CONVERSION
    string ToString() const {
        string dateStr = "";

        if (_day < 10)
            dateStr += "0" + to_string(_day) + ".";
        else 
            dateStr += to_string(_day) + ".";
 
        if (_month < 10)
            dateStr += "0" + to_string(_month) + ".";
        else 
            dateStr += to_string(_month) + ".";
 
        dateStr += to_string(_year);
 
        return dateStr;
    }

    // GETTERS & SETTERS
    [[nodiscard]] unsigned short GetDay() const { return _day; }
    [[nodiscard]] unsigned short GetMonth() const { return _month; }
    [[nodiscard]] unsigned short GetYear() const { return _year; }

    void SetDay(unsigned short day) { _day = day; }
    void SetMonth(unsigned short month) { _month = month; }
    void SetYear(unsigned short year) { _year = year; }

    // << OVERLOADING
    friend ostream& operator<< (ostream& os, const Date& date) {
        os << date.ToString() << endl;
        return os;
    }
 
};

class Edition {
private:
    string _title = "";
    size_t _circulation = 0;
    Date _yearOfIssue;

public:

    Edition() = default;

    Edition(const Edition& edition) {
        _title = edition.GetTitle();
        _circulation = edition.GetCirculation();
        _yearOfIssue = Date(edition.GetYearOfIssue());
    }

    Edition(string title, size_t circulation, const Date& yearOfIssue) {
        _title = title;
        _circulation = circulation;
        _yearOfIssue = Date(yearOfIssue);
    }

    [[nodiscard]] string GetTitle() const { return _title; }
    [[nodiscard]] size_t GetCirculation() const { return _circulation; }
    [[nodiscard]] Date GetYearOfIssue() const { return _yearOfIssue; }

    void SetTitle(string title) { _title = title; }
    void SetCirculation(size_t circulation) { _circulation = circulation; }
    void SetYearOfIssue(const Date& yearOfIssue) { _yearOfIssue = Date(yearOfIssue); }

    friend ostream& operator<< (ostream& os, const Edition& date) {
        os << "Title: " << date.GetTitle() << endl;
        os << "Circulation: " << date.GetCirculation() << endl;
        os << "Year of issue: " << date.GetYearOfIssue() << endl;
        return os;
    }

};

class EditionsCollection {
private:
    vector<Edition> _collection;
    
    void IndexValidation(size_t index) const {
        if (index >= _collection.size())
            throw invalid_argument("Invalid index!");
    }

    static bool DateComporator(const Edition& edition1, const Edition& edition2) {

        if (edition1.GetYearOfIssue().GetYear() == edition2.GetYearOfIssue().GetYear()) {
            if (edition1.GetYearOfIssue().GetMonth() == edition2.GetYearOfIssue().GetMonth()) 
                return edition1.GetYearOfIssue().GetDay() < edition2.GetYearOfIssue().GetDay();
            else
                return edition1.GetYearOfIssue().GetMonth() < edition2.GetYearOfIssue().GetMonth();
        } else {
            return edition1.GetYearOfIssue().GetYear() < edition2.GetYearOfIssue().GetYear();
        }

    }

    static bool CirculationComporator(const Edition& edition1, const Edition& edition2) {
        return edition1.GetCirculation() < edition2.GetCirculation();
    }

public:
    EditionsCollection() = default;

    void Add(const Edition& edition) { _collection.push_back(edition); }  

    Edition Get(size_t index) const { 
        IndexValidation(index);
        return _collection[index]; 
    }

    void Set(size_t index, const Edition& edition) { 
        IndexValidation(index);
        _collection[index] = edition; 
    }

    void Print() const {
        for (auto edition : _collection)
            cout << edition << endl;
    }

    void Save(string fileName) const {
        ofstream stream;
        stream.open(fileName);

        if (stream.is_open()) {
            for (auto edition : _collection) {
                stream << edition.GetTitle() << endl;
                stream << edition.GetCirculation() << endl;
                stream << edition.GetYearOfIssue() << endl;
            }
        }

    }

    void SortByDate() {
        sort(begin(_collection), end(_collection), DateComporator);
    }

    void SortByCirculation() {
        sort(begin(_collection), end(_collection), CirculationComporator);
    }

    size_t GetAverageCirculation() const {
        size_t value = 0;
        for (auto edition : _collection)
            value += edition.GetCirculation();

        return value / _collection.size();
    }

    size_t GetMinCirculation() const {
        size_t min = SIZE_T_MAX;
        for (auto edition : _collection)
            if (edition.GetCirculation() < min)
                min = edition.GetCirculation();

        return min;
    }

    size_t GetMaxCirculation() const {
        size_t max = 0;
        for (auto edition : _collection)
            if (edition.GetCirculation() > max)
                max = edition.GetCirculation();

        return max;
    }

};

int main() {

    Edition ed1("GGWP", 123123, Date(4,11,2003));
    Edition ed2("GGWP", 1324, Date(4,9,2001));
    Edition ed3("GGWP", 533, Date(4,11,2004));
    Edition ed4("GGWP", 6463, Date(4,11,1999));

    EditionsCollection collection;
    collection.Add(ed1);
    collection.Add(ed2);
    collection.Add(ed3);
    collection.Add(ed4);

    collection.SortByCirculation();

    collection.Save("hello.txt");

    cout << collection.GetMaxCirculation();


}