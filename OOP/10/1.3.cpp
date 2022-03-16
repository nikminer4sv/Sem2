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

Student ReadStudent(ifstream &in);
double Average(ifstream &in);
void Task(ifstream &in);

int main()
{
    ifstream in("1.3.students.bin", ios::binary); 

    if (!in) 
    { 
        cout << "error2" << endl; 
        return 1;
    }

    Task(in);

    return 0;
}

Student ReadStudent(ifstream &in)
{
    Student NoName;
    in.read((char*)&NoName, sizeof(Student));

    return NoName;
}

double Average(ifstream &in)
{
    double EverybodyProgress = 0.0;
    int Count = 0;
    while(in)
    {
        Student Temp = ReadStudent(in);
        EverybodyProgress += Temp.Progress;
        Count++;
    }

    return EverybodyProgress / Count;
}

void Task(ifstream &in)
{
    double AverageProgress = Average(in);
    in.close();
    in.open("1.3.bin", ios::binary);
    ofstream out("1.3.1.bin", ios::binary);
    while(in)
    {
        Student Temp = ReadStudent(in);
        if (double(Temp.Progress) > AverageProgress)
        {
            out.write((char*)&Temp, sizeof(Student));
        }
    }
    in.close();
    out.close();
}