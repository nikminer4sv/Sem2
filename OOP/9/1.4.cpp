#include <iostream>
#include <string>
#include "Libs/nlohmann-json/json.hpp"
#include <fstream>

using namespace std;

struct Student {

    string name;
    string surname;
    string patronymic;
    int age;
    int course;
    int progress;
    bool gender;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Student, name, surname, patronymic, age, course, progress, gender)
};

string ToJSON(const Student& student) {
    return nlohmann::json(student).dump(4);
}

Student FromJSON(const string& json) {
    return nlohmann::json::parse(json).get<Student>();
}

int main() {
    ofstream outputFileStream;
    ofstream outputResultStream;
    ifstream inputFileStream;
    outputFileStream.open("db.json", ios::app);
    outputResultStream.open("result.txt");
    inputFileStream.open("db.json");
    bool isWorking = true;
    bool isPaused = false;

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

                outputFileStream << ToJSON(student) << endl;
                break;

            }

            case 2: {

                system("clear");
                cout << "----------ALL STUDENTS----------" << endl;
                while (!inputFileStream.eof()) {
                    string json;
                    inputFileStream >> json;
                    if (json == "")
                        break;
                    Student student = FromJSON(json);
                    cout << "-----------------------------" << endl;
                    cout << student.name << endl;
                    cout << student.surname << endl;
                    cout << student.patronymic << endl;
                    cout << student.age << endl;
                    cout << student.course << endl;
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
                    string json;
                    inputFileStream >> json;
                    if (json == "")
                        break;
                    Student student = FromJSON(json);

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
                isWorking = false;
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

}