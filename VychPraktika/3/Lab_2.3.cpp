#include <iostream>
#include <string>
using namespace std;


struct DataOfBirthDay {
    int Day;
    int Mounth;
    int Year;
};

struct Student {
    string Name;
    string Surname;
    string Patronymic;

    int Course;
    float Progress;

    DataOfBirthDay Data;

    void Print() {
        cout << Surname << " " << Name << " " << Patronymic << endl;
        cout << Data.Day << '.' << Data.Mounth << '.' << Data.Year << endl;
        cout << "Course - " << Course << endl;
        cout << "Progress - " << Progress << endl << endl;
    }

    static bool Separator(const Student& a, const Student& b) {
        return a.Surname >= b.Surname;
    }

    static bool Compare(const Student& a, const Student& b) {
        return a.Surname == b.Surname && a.Name == b.Name && a.Patronymic == b.Patronymic;
    }

    static bool CompareSymbols(const Student& a, const Student& b) {
        return a.Surname[0] == b.Surname[0] && a.Name[0] == b.Name[0] && a.Patronymic[0] == b.Patronymic[0];
    }

    static bool NewCompare(const Student& a, const Student& b) {
        return a.Name[0] != b.Name[0] || a.Surname[0] != b.Surname[0] || a.Patronymic[0] != b.Patronymic[0];
    }
   
};

struct Node {
    Student students;
    Node* next;

    Node(const Student& student) {
        students = student;
        this->next = nullptr;
    }
};

class list {
private:
    Node* first = nullptr;
    Node* last = nullptr;
    int size = 0;

public:
    bool is_empty() const {
        return first == nullptr;
    }

    void print() {

        Node* p = first;
        while (p) {
            p->students.Print();
            p = p->next;
        }
        cout << endl;
    }


    void createNewList(list& newL, Student& stud) {
        while (true)
        {
            if (is_empty()) return;

            if (Student::CompareSymbols(first->students, stud))
            {
                newL.push_back(stud);
                cout << "FIRST" << endl;
                remove(stud);
                continue;
            }
            else if (Student::CompareSymbols(last->students, stud))
            {
                newL.push_back(stud);
                cout << "LAST" << endl;
                remove(stud);
                continue;
            }

            Node* itPrev = first;
            Node* itCurrent = first->next;

            while (itCurrent && Student::NewCompare(itCurrent->students, stud)) {
                itCurrent = itCurrent->next;
                itPrev = itPrev->next;
            }
            if (!itCurrent) {
                return;
            }

            newL.push_back(itCurrent->students);
            itPrev->next = itCurrent->next;
            delete itCurrent;
            size--;
        }
    }


    void remove(const Student& stud) {
        if (is_empty()) return;

        if (Student::Compare(first->students, stud)) {

            Node* p = first;
            first = p->next;

            size--;
            delete p;
            return;
        }

        if (Student::Compare(last->students, stud)) {

            Node* p = first;
            while (p->next != last)
                p = p->next;

            p->next = nullptr;

            size--;
            delete last;
            last = p;
            return;
        }

        Node* itPrev = first;       
        Node* itCurrent = first->next; 

        while (itCurrent && !Student::Compare(itCurrent->students, stud))
        {
            itCurrent = itCurrent->next;
            itPrev = itPrev->next;
        }

        if (!itCurrent) {
            cout << "This element does not exist" << endl;
            return;
        }

        itPrev->next = itCurrent->next;
        size--;
        delete itCurrent;
    }

    list() : first(nullptr), last(nullptr) {}


    void push_back(Student& stud) {

        Node* p = new Node(stud);

        if (is_empty()) {
            first = p;
            last = p;
            size++;
            return;
        }

        Node* temp = first;
        size++;

        if (size == 2 && Student::Separator(temp->students, p->students))
        {
            p->next = last;
            first = p;
            return;
        }

        while (temp->next != nullptr)
        {
            if (Student::Separator(p->students, temp->students) && Student::Separator(temp->next->students, p->students))
            {
                p->next = temp->next;
                temp->next = p;
                return;
            }
            else if (Student::Separator(temp->students, p->students))
            {
                p->next = temp;
                temp = p;
                return;
            }
            else temp = temp->next;
        }

        last->next = p; 
        last = p;
    }

};

void Menu(list& listStudents, Student& stud, list& newList)
{
    while (true)
    {
        cout << "Enter the choose:  " << endl;

        cout << "1. Add new student." << endl;
        cout << "2. Search a student by \"symbols\" and create a new list of them." << endl;
        cout << "3. Delete a student." << endl;
        cout << "4. Print the list's of students." << endl;
        cout << "5. Exit." << endl;

        int choose;
        cin >> choose;

        if (choose == 5) break;

        switch (choose)
        {
        case 1:
        {
            cout << "Surname = ";
            cin >> stud.Surname;

            cout << "Name = ";
            cin >> stud.Name;

            cout << "Patronymic = ";
            cin >> stud.Patronymic;

            cout << "Data of birth (1 4 2002):";
            cin >> stud.Data.Day;
            cin >> stud.Data.Mounth;
            cin >> stud.Data.Year;

            cout << "Course of student: ";
            cin >> stud.Course;

            cout << "Progress of student: ";
            cin >> stud.Progress;


            listStudents.push_back(stud);

            break;
        }
        case 2:
        {
            cout << "Enter the first symbols of surname, name, patronymic (\"K\" \"D\" \"A\"): ";

            cin >> stud.Surname[0];
            cin >> stud.Name[0];
            cin >> stud.Patronymic[0];

            listStudents.createNewList(newList, stud);

            break;
        }
        case 3:
        {
            cout << "Enter the surname, name, patronymic of student (\"Kazlou\" \"Dzmitry\" \"Andreevich\")" << endl;

            cout << "Surname = ";
            cin >> stud.Surname;

            cout << "Name = ";
            cin >> stud.Name;

            cout << "Patronymic = ";
            cin >> stud.Patronymic;

            listStudents.remove(stud);

            break;
        }
        case 4:
        {
            cout << "\n========================LIST=OF=STUDENTS===========================" << endl;
            listStudents.print();
            cout << "====================SECOND=LIST=OF=STUDENTS========================" << endl;
            newList.print();

            break;
        }

        default:
            break;
        }

        cout << endl;
    }
}

int main() {

    list listStudents, newList;
    Student students;

    Menu(listStudents, students, newList);

    return 0;
}