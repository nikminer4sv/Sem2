#include <iostream>
#include <fstream>
using namespace std;

struct student
{
    int age = 0;
    int progress = 0;
    int course = 0;
    char name[20]{};
    char surname[20]{};
    char patronymic[20]{};
    bool gender = false;
    bool isempty = true;

    student() = default;
    student(std::ifstream &str)
    {
        str.read(reinterpret_cast<char *>(this), sizeof(student));
    }
};
static_assert(std::is_trivially_copyable<student>());

std::ifstream &operator>>(std::ifstream &str, student &stud)
{
    str.read(reinterpret_cast<char *>(&stud), sizeof(student));
    return str;
}
int main()
{
    bool is_working = true;
    bool is_paused = false;
    ofstream outfilestream;
    ofstream outresstream;
    ifstream infilestream;
    outfilestream.open("database1.bin", ios::binary | ios::app);
    outresstream.open("result2.bin", ios::trunc);
    infilestream.open("database1.bin");
    while (is_working)
    {
        cout << "1.add\n" 
<< "2.print\n" 
<< "3.task\n" 
<< "4.exit\n";
        int choice = 0;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            student student;
            cout << "name" << endl;
            cin >> student.name;
            cout << "surname" << endl;
            cin >> student.surname;
            cout << "ptron" << endl;
            cin >> student.patronymic;
            cout << "age" << endl;
            cin >> student.age;
            cout << "prgresss" << endl;
            cin >> student.progress;
            cout << "course" << endl;
            cin >> student.course;
            cout << "gener" << endl;
            cin >> student.gender;
            student.isempty = false;
            outfilestream.write(reinterpret_cast<char *>(&student), sizeof(student));
            outfilestream.flush();
            break;
        }
        case 2:
        {

            cout << "all student:" << endl;
            int counter = 0;
            while (!infilestream.eof())
            {
                counter += 1;
                student student;
                infilestream >> student;
                if (!infilestream.good())
                {
                    break;
                }
                cout << "--" << endl;
                cout << student.name << endl;
                cout << student.surname << endl;
                cout << student.patronymic << endl;
                cout << student.age << endl;
                cout << student.progress << endl;
                cout << student.gender << endl;
            }
            cout << "------" << endl;
            infilestream.clear();
            infilestream.seekg(0, ios::beg);
            is_paused = true;
            break;
        }
        case 3:
        {
            int n;
            cin >> n;
            // system("clear");
            while (!infilestream.eof())
            {
                student student;
                infilestream >> student;
                if (student.isempty)
                    break;
                if (student.course == n && student.progress < 4)
                    outresstream << student.name << " " << student.surname << " " << student.patronymic << endl;
            }
            infilestream.clear();
            infilestream.seekg(0, ios::beg);
            break;
        }
        case 4:
        {
            infilestream.close();
            outfilestream.close();
            outresstream.close();
            exit(0);
            break;
        }
        }
        if (is_paused)
        {
            cin.clear();
            fflush(stdin);
            cin.get();
            is_paused = false;
        }
        system("clear");
    }
}