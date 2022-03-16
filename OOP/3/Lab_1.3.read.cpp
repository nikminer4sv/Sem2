#include <iostream>
#include <fstream>

using namespace std;

struct Date
{
    Date(){}
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Student
{
    Student(){}
    char LastName[10];
    char FirstName[10];
    char Patronymic[10];
    Date DateOfBirth;
    unsigned short Course;
    unsigned short Progress;
};

int main()
{
    ifstream infile ("1.3.bin", ios::binary); 

    if (!infile) 
    { 
        cout << "You loh" << endl; 
        return 1;
    }

    Student NoName;
    infile.read((char*)&NoName, sizeof(Student));

    cout << NoName.LastName << endl;
    cout << NoName.FirstName << endl;
    cout << NoName.Patronymic << endl;
    cout << NoName.DateOfBirth.day << endl;
    cout << NoName.DateOfBirth.month << endl;
    cout << NoName.DateOfBirth.year << endl;
    cout << NoName.Progress << endl;
    cout << NoName.Course << endl;

    infile.read((char*)&NoName, sizeof(Student));
    cout << NoName.LastName << endl;
    cout << NoName.FirstName << endl;
    cout << NoName.Patronymic << endl;
    cout << NoName.DateOfBirth.day << endl;
    cout << NoName.DateOfBirth.month << endl;
    cout << NoName.DateOfBirth.year << endl;
    cout << NoName.Progress << endl;
    cout << NoName.Course << endl;
    return 0;
}