#include <iostream>
#include <string>

using namespace std;

struct YearGap {

    int Begin;
    int End;

};

struct Human {

    string Name;
    string Surname;
    string Patronymic;

};

struct Learner : Human {

    YearGap YearOfEducation; 
    int StudentCardNumber;
    double AverageGrade;

};

struct Student : Learner {};

struct Undergraduate : Learner {};

struct Postgraduate : Learner {};

struct Employer : Human {

    string Function;

};

struct Teacher : Employer {

    string AcademicDegree;

};

struct Assistant : Employer {

    unsigned char LaboratoryNumber;

};

template<typename T>
class Array {
private:

public:
    T Test;

private:

public:
    Array(T Object) {
        Test = Object;
    }

};

int main() {

    cout << "It works";
    Student student;
    student.Name = "GG";
    Array ar(student);

    cout << ar.Test.Name;

}