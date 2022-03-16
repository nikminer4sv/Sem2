#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

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

template<typename T> 
T getRand(T min, T max);

char* PrintText(char[]);
void Print(ofstream& out);
unsigned short PrintNumber();
Date PrintDate();

int main() 
{
    srand(time(NULL));
    ofstream out("1.3.bin", ios::binary);
    for (int i = 0; i < 10; i++)
    {
        Print(out);
    }
    
    cout << "End of program" << endl;
    return 0;
}

template<typename T> 
T getRand(T min, T max)
{
    return rand() % (max - min + 1) + min;
}

char* PrintText(char text[])
{
    int n = rand() % 10 + 1;

    for (int i = 0; i < n; i++)
        text[i] = NULL;    

    for (int j = 0; j < n; j++)
    {
        text[j] += getRand('a', 'z');
    }

    text[n] = '\0';

    for (int i = 0; i < n; i++)
    {
        cout << text[i];
    }
    cout << endl;

    return text;
}

unsigned short PrintNumber()
{
    unsigned short kek = getRand(1, 10);

    return kek;
}

Date PrintDate()
{
    Date NoDate;
    NoDate.day = getRand(1, 31);
    NoDate.month = getRand(1, 12);
    NoDate.year = getRand(1, 99);

    return NoDate;
}

void Print(ofstream& out)
{
    const int n = 10;
    char text[n]{};
    Student NoName;
    strncpy(NoName.LastName, PrintText(text), n);
    strncpy(NoName.FirstName, PrintText(text), n);
    strncpy(NoName.Patronymic, PrintText(text), n);
    cout << endl;
    NoName.DateOfBirth = PrintDate();
    NoName.Progress = PrintNumber();
    NoName.Course = PrintNumber();

    out.write((char*)&NoName, sizeof(Student));
}