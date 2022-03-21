#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)
struct Student {

    int age = 0;
    int progress;
    int course;
    char name[20]{};
    char surname[20]{};
    char patronymic[20]{};
    bool gender;
    bool isEmpty;

    Student() {
        isEmpty = true;
    }

    Student(std::ifstream& str){
        str.read(reinterpret_cast<char*>(this), sizeof(Student));
    }

};
std::ifstream& operator >> (std::ifstream& str, Student& stud){
    str.read(reinterpret_cast<char*>(&stud), sizeof(Student));
    return str;
}

int main() {

    bool isWorking = true;
    bool isPaused = false;
    ofstream outputFileStream;
    ofstream outputResultStream;
    ifstream inputFileStream;
    outputFileStream.open("database", ios::app);
    outputResultStream.open("result.txt", ios::app);
    inputFileStream.open("database");

    while (isWorking) {

        cout << "1. Add\n"
             << "2. Print\n"
             << "3. Task\n"
             << "4. Exit\n";

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
                cin >> student.course;
                cin >> student.gender;
                student.isEmpty = false;

                outputFileStream.write(reinterpret_cast<char*>(&student), sizeof(student));
                break;

            }

            case 2: {

                system("clear");
                cout << "----------ALL STUDENTS----------" << endl;
                int counter = 0;
                while (!inputFileStream.eof()) {
                    counter += 1;
                    Student student;
                    inputFileStream >> student;
                    if (student.isEmpty)
                        break;
                    cout << "-----------------------------" << endl;
                    cout << student.name << endl;
                    cout << student.surname << endl;
                    cout << student.patronymic << endl;
                    cout << student.age << endl;
                    cout << student.progress << endl;
                    cout << student.gender << endl;

                }

                cout << "-----------------------------" << endl;

                inputFileStream.clear();
                inputFileStream.seekg(0, ios::beg);
                isPaused = true;
                break;

            }

            case 3: {
                
                int n;
                cin >> n;

                system("clear");

                while (!inputFileStream.eof()) {
                    Student student;
                    inputFileStream >> student;
                    if (student.isEmpty)
                        break;
                    
                    if (student.course == n && student.progress < 4)
                        outputResultStream << student.name << " " << student.surname << " " << student.patronymic << endl;

                }

                inputFileStream.clear();
                inputFileStream.seekg(0, ios::beg);

                break;
            }

            case 4: {
                inputFileStream.close();
                outputFileStream.close();
                outputResultStream.close();
                exit(0);
                break;
            }

        }

        if (isPaused) {
            cin.clear();
            fflush(stdin);
            cin.get();
            isPaused = false;
        }

        system("clear");
        
    }

    /*ofstream stream;
    stream.open("stream", ios::binary);

    Student student{};
    student.name[0] = 'N';
    student.surname[0] = 'K';
    student.patronymic[0] = 'D';
    student.age = 18;
    student.gender = true;
    student.progress = 9;

    stream.write(reinterpret_cast<char*>(&student), sizeof(student));
    stream.flush();

    ifstream database_r("stream",ios::binary);

    Student student2{};
    database_r >> student2;

    stream.close();

    cout << student2.age;*/

    

}

#pragma pack(pop)