#include <iostream>
#include <string>
using namespace std;

struct DataOfBirthDay{
    int Day;
    int Mounth;
    int Year;
};

struct Student{
    string Name;
    string Surname;
    string Patronymic;

    int Course;
    float Progress;

    DataOfBirthDay Data;
};

struct Node {

    Student student;
    Node* next;

    Node(string surname, string name, string patronymic, int day, int mounth, int year, int course, float progress){
        next = nullptr;
        student.Name = name;
        student.Surname = surname;
        student.Patronymic = patronymic;

        student.Data.Day = day;
        student.Data.Mounth = mounth;
        student.Data.Year = year;

        student.Course = course;
        student.Progress = progress;
    }
};

struct list {
    Node* first;
    Node* last;

    int size = 0;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }    

    void createNewList(list& newL, char firstSurnameSymbol, char firstNameSymbol, char firstPatronymicSymbol){
        
        while (true)
        {
            if (is_empty()) return;
            if (first->student.Surname[0] == firstSurnameSymbol && first->student.Name[0] == firstNameSymbol &&
                first->student.Patronymic[0] == firstPatronymicSymbol) 
            {
                newL.push_back(first->student.Surname, first->student.Name, first->student.Patronymic, first->student.Data.Day, 
                            first->student.Data.Mounth, first->student.Data.Year, first->student.Course, first->student.Progress);
                remove_first();
                continue;
            }
            else if (last->student.Surname[0] == firstSurnameSymbol && last->student.Name[0] == firstNameSymbol && 
                    last->student.Patronymic[0] == firstPatronymicSymbol) 
            {
                newL.push_back(last->student.Surname, last->student.Name, last->student.Patronymic, last->student.Data.Day,
                    last->student.Data.Mounth, last->student.Data.Year, last->student.Course, last->student.Progress);
                remove_last();
                continue;
            }

            Node* slow = first;
            Node* fast = first->next;

            while (fast && (fast->student.Name[0] != firstNameSymbol || fast->student.Surname[0] != firstSurnameSymbol
                || fast->student.Patronymic[0] != firstPatronymicSymbol)) {
                fast = fast->next;
                slow = slow->next;
            }
            if (!fast) {
                //cout << "This element does not exist" << endl;
                return;
            }
            
            newL.push_back(fast->student.Surname, fast->student.Name, fast->student.Patronymic, fast->student.Data.Day,
                    fast->student.Data.Mounth, fast->student.Data.Year, fast->student.Course, fast->student.Progress);
            slow->next = fast->next;
            delete fast;
        }
         
    }

    void push_back(string surname, string name, string patronymic, int day, int mounth, int year, int course, float progress) {
        Node* p = new Node(surname, name, patronymic, day, mounth, year, course, progress);
        if (is_empty()) {
            first = p;
            last = p;
            size++;
            return;
        }

        Node* temp = first;
        while (temp->next != nullptr)
        {
            if (p->student.Surname > temp->student.Surname && temp->next->student.Surname > p->student.Surname)
            {
                p->next = temp->next;
                temp->next = p;
                break;
            }
            else temp = temp->next;
        }

        if (temp->next == nullptr)
        last->next = p; // присваиваем в текущем последнем узле указателю next следующий узел 
        last = p; // last присваем новый последний узел
        size++;

    }

    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->student.Surname << " " << p->student.Name << " " << p->student.Patronymic << endl;
            cout << p->student.Data.Day << '.' << p->student.Data.Mounth << '.' << p->student.Data.Year << endl;
            cout << "Course - " << p->student.Course << endl;
            cout << "Progress - " << p->student.Progress << endl << endl;
            p = p->next;
        }
        cout << endl;
    }


    // Node* find(string _val) {
    //     Node* p = first;
    //     while (p && p->val != _val) p = p->next;
    //         return (p && p->val == _val) ? p : nullptr;
    // }

    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(char firstSurnameSymbol, char firstNameSymbol, char firstPatronymicSymbol) {
        if (is_empty()) return;
        if (first->student.Name[0] == firstNameSymbol && first->student.Surname[0] == firstSurnameSymbol
            && first->student.Patronymic[0] == firstPatronymicSymbol) 
        {
            remove_first();
            return;
        }
        else if (last->student.Name[0] == firstNameSymbol && last->student.Surname[0] == firstSurnameSymbol
                && last->student.Patronymic[0] == firstPatronymicSymbol) 
        {
            remove_last();
            return;
        }

        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->student.Name[0] != firstNameSymbol && fast->student.Surname[0] != firstSurnameSymbol
            && fast->student.Patronymic[0] != firstPatronymicSymbol) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {

            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

};

int main(){

    list l;
    list newL;
    //cout << l.is_empty() << endl;

    l.push_back("Kazlou", "Dzmitry", "Andreevich", 4, 5, 2004, 1, 7.0);
    l.push_back("Keglik", "Mikhail", "Andreevich", 15, 9, 2011, 1, 5.4);
    l.push_back("Masherov", "Maks", "Andreevich", 11, 12, 2000, 1, 5.4);
    l.push_back("Mazurov", "Malkin", "Andreevich", 9, 2, 1941, 1, 5.4);

    //cout << l.is_empty() << endl;
    cout << "=====================" << endl;
    l.print();
    cout << "=====================" << endl;
    l.createNewList(newL, 'M', 'M', 'A');
    //l.remove('M', 'K', 'A');
    l.print();
    cout << "=====================" << endl;
    newL.print();

    return 0;
}