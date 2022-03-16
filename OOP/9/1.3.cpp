#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)
struct Student {

    int age;
    int progress;
    char name[20]{};
    char surname[20]{};
    char patronymic[20]{};
    bool gender;

    Student() = default;

    Student(std::fstream& str){
        str.read(reinterpret_cast<char*>(this), sizeof(Student));
    }

    friend std::fstream& operator >> (std::fstream& str, Student& stud);
};

std::fstream& operator >> (std::fstream& str, Student& stud){
    str.read(reinterpret_cast<char*>(&stud), sizeof(stud));
    return str;
}

#pragma pack(pop)

int main() {

    bool isWorking = true;
    bool isPaused = false;
    fstream database;
    database.open("database", ios::binary);

    while (isWorking) {

        cout << "1. Add\n"
             << "2. Print\n"
             << "3. Exit\n";

        int choice;
        cin >> choice;

        switch (choice) {

            case 1: {

                Student student;
                cin >> student.name;
                cin >> student.surname;
                cin >> student.patronymic;
                cin >> student.age;
                cin >> student.progress;
                cin >> student.gender;

                database.write(reinterpret_cast<char*>(&student), sizeof(student));
                database.flush();
                break;

            }

            case 2: {

                Student student;

                database >> student;

                system("clear");
                cout << student.age << endl;
                isPaused = true;
                break;

            }

            case 3: {
                database.close();
                exit(0);
                break;
            }

        }

        if (isPaused) {
            cin.clear();
            cin.get();
            isPaused = false;
        }

        system("clear");
        
    }

    /*ofstream database;
    database.open("database", ios::binary);

    Student student{};
    student.name[0] = 'N';
    student.surname[0] = 'K';
    student.patronymic[0] = 'D';
    student.age = 18;
    student.gender = true;
    student.progress = 9;

    database.write(reinterpret_cast<char*>(&student), sizeof(student));
    database.flush();

    ifstream database_r("database",ios::binary);

    Student student2{};
    database_r >> student2;

    database.close();

    cout << student2.age;*/

    

}