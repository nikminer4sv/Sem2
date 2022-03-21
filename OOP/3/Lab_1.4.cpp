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

    bool comparator(const Student tempStudent, const int course, const char F, const char I, const char O)
    {
        return tempStudent.Course == course && tempStudent.FirstName[0] == I && tempStudent.LastName[0] == F && tempStudent.Patronymic[0] == O;
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
        {
            cout << "You loh" << endl;
            return;
        }
        
        infile.read(reinterpret_cast<char*>(&NoName), sizeof(Student));
    }

    void readTextFile(ifstream& infile, Student& tempStudent)
    {
        if (!infile.is_open())
        {
            cout << "You loh" << endl;
            return;
        }
        
        infile >> tempStudent.LastName
        >> tempStudent.FirstName
        >> tempStudent.Patronymic
        >> tempStudent.DateOfBirth.day
        >> tempStudent.DateOfBirth.month
        >> tempStudent.DateOfBirth.year
        >> tempStudent.Course
        >> tempStudent.Progress;
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

    int task(const int size, const int course, const char F, const char I, const char O, ifstream& infile, ofstream& out)
    {
        Student tempStudent;
        int sizeTemp = 0;
        for (int i = 0; i < size; i++)
        {
            readBinFile(infile, tempStudent);

            if (comparator(tempStudent, course, F, I, O))
            {
                out << tempStudent.LastName << endl
                << tempStudent.FirstName << endl
                << tempStudent.Patronymic << endl
                << tempStudent.DateOfBirth.day << ' '
                << tempStudent.DateOfBirth.month << ' '
                << tempStudent.DateOfBirth.year << endl
                << tempStudent.Course << endl
                << tempStudent.Progress << endl;

                sizeTemp++;
            }    
        }
        return sizeTemp;
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
    Student TextNoName;
    BINFile task;
    
    int size = 0;
    int sizeTask = 0;
    while (true)
    {
        cout << "Menu:\n";
        int choose;
        cout << "1. Add student.\n" <<
                "2. Read and print student.\n" <<
                "3. Task.\n" <<
                "4. Read and print task.\n" <<
                "0. Exit.\n";

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

                ofstream out("1.4.bin", ios::binary | ios::app);

                for (int i = 0; i < quantity; i++)
                    task.createBinFile(out, NoName);

                cout << endl;
                out.close();
                break;
            }

            case 2:
            {
                ifstream infile("1.4.bin", ios::binary);

                for (int i = 0; i < size; i++)
                {
                    task.readBinFile(infile, TextNoName);
                    task.printStudent(TextNoName);
                }
                
                infile.close();
                break;
            }

            case 3:
            {
                int course;
                cout << "Enter the course: ";
                cin >> course;

                char F, I, O;
                cout << "Enter the first symbols of FIO student: ";
                cin >> F;
                cin >> I;
                cin >> O;
                
                ifstream infile("1.4.bin", ios::binary);
                ofstream out("1.4.task.txt");

                sizeTask += task.task(size, course, F, I, O, infile, out);
                infile.close();
                out.close();
                break;
            }

            case 4:
            {
                ifstream infile("1.4.task.txt");
                cout << sizeTask << endl;
                for (int i = 0; i < sizeTask; i++)
                {
                    task.readTextFile(infile, TextNoName);
                    task.printStudent(TextNoName);
                }
                
                infile.close();
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


