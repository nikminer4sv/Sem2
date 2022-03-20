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


class BINFile
{
private:
    int n;
    char* text;

    template<typename T> 
    T getRand(T min, T max)
    {
        return rand() % (max - min + 1) + min;
    }

    char* fillRandomText(char text[])
    {
        int m = rand() % n + 1;

        for (int i = 0; i < m; i++)
            text[i] = 0;
        
        for (int j = 0; j < m; j++)
            text[j] += getRand('a', 'z');

        text[m] = '\0';

        return text;
    }

    unsigned short fillRandomNumber()
    {
        unsigned short kek = getRand(1, 10);

        return kek;
    }

    Date fillRandomDate()
    {
        Date NoDate;
        NoDate.day = getRand(1, 31);
        NoDate.month = getRand(1, 12);
        NoDate.year = getRand(1, 99);

        return NoDate;
    }

public:
    BINFile();
    ~BINFile();

    void createBinFile(ofstream& out, Student& NoName)
    {
        strncpy(NoName.LastName, fillRandomText(text), n);
        strncpy(NoName.FirstName, fillRandomText(text), n);
        strncpy(NoName.Patronymic, fillRandomText(text), n);
        NoName.DateOfBirth = fillRandomDate();
        NoName.Progress = fillRandomNumber();
        NoName.Course = fillRandomNumber();

        out.write(reinterpret_cast<char*>(&NoName), sizeof(Student));
    }

    void readBinFile(ifstream& infile, Student& NoName)
    {
        if (!infile.is_open()) 
            cout << "You loh" << endl;

        infile.read(reinterpret_cast<char*>(&NoName), sizeof(Student));
    }

    void printStudent(Student& NoName)
    {
        cout << endl;
        cout << "Last name: " << NoName.LastName << endl;
        cout << "First name: "  << NoName.FirstName << endl;
        cout << "Patronymic: " << NoName.Patronymic << endl;
        cout << "Day of birth: " << NoName.DateOfBirth.day << endl;
        cout << "Month of birth: " << NoName.DateOfBirth.month << endl;
        cout << "Year of birth: "<< NoName.DateOfBirth.year << endl;
        cout << "Progress: " << NoName.Progress << endl;
        cout << "Course: " << NoName.Course << endl;
    }
};
BINFile::BINFile()
{
    n = 10;
    text = new char[n];
}
BINFile::~BINFile(){delete[] text;}


int main() 
{
    srand(time(NULL));

    Student NoName;
    Student BINNoName;
    BINFile task;
    
    int size = 0;
    while (true)
    {
        cout << "Menu:\n";
        int choose;
        cout << "1. Add student.\n" <<
                "2. Read and print student.\n" <<
                "0. Exit\n";

        cout << "Enter the choose: ";
        cin >> choose;

        switch (choose)
        {
            int quantity;

            case 1:
            {
                cout << "Enter the value of students: ";
                cin >> quantity;

                size += quantity;

                ofstream out("1.3.bin", ios::binary | ios::app);

                for (int i = 0; i < quantity; i++)
                    task.createBinFile(out, NoName);

                cout << endl;
                out.close();
                break;
            }

            case 2:
            {
                ifstream intfile("1.3.bin", ios::binary);

                for (int i = 0; i < size; i++)
                {
                    task.readBinFile(intfile, BINNoName);
                    task.printStudent(BINNoName);
                }
                
                intfile.close();
                break;
            }

            case 0:
                cout << "Good bye!" << endl;
                break;
                
            default:
                cout << "You loh! Try again!" << endl;
                break;
        }

        if(choose == 0) return 0;
    }
}


