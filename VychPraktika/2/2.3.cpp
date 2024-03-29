#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int Day;
    int Month;
    int Year;
};

struct Student
{
    string Name;
    string Surname;
    string Patronymic;

    int Course;
    float Progress;

    Date BirthDate;

    void PrintStudentInfo()
    {
        cout << Surname << " " << Name << " " << Patronymic << endl;
        cout << BirthDate.Day << '.' << BirthDate.Month << '.' << BirthDate.Year << endl;
        cout << "Course - " << Course << endl;
        cout << "Progress - " << Progress << endl
             << endl;
    }
};

struct Node
{
    Student newStudent;
    Node *pNext;

    Node(const Student &student)
    {
        newStudent = student;
        this->pNext = nullptr;
    }
};

class StudentList
{
private:
    Node *first = nullptr;
    Node *last = nullptr;
    int size = 0;

    bool StudentsComparator(const Student &a, const Student &b)
    {
        return a.Surname >= b.Surname;
    }

    bool Compare(const Student &a, const Student &b)
    {
        return a.Surname == b.Surname && a.Name == b.Name && a.Patronymic == b.Patronymic;
    }

public:
    int GetSize() { return size; }
    Student &operator[](const int index);

    bool is_empty() const
    {
        return first == nullptr;
    }

    void PrintStudentsInfo()
    {

        Node *p = first;
        while (p)
        {
            p->newStudent.PrintStudentInfo();
            p = p->pNext;
        }
        cout << endl;
    }

    void CreateNewList(StudentList &newStudentList, Student &stud)
    {
        while (true)
        {
            if (is_empty())
                return;

            Node *slow = first;
            Node *fast = first->pNext;

            while (fast)
            {
                fast = fast->pNext;
                slow = slow->pNext;
            }
            if (!fast)
            {
                return;
            }

            newStudentList.push_back(fast->newStudent);
            slow->pNext = fast->pNext;
            delete fast;
        }
    }

    void removeAt(const Student &stud)
    {
        size--;
        if (is_empty())
            return;

        if (Compare(first->newStudent, stud))
        {

            Node *p = first;
            first = p->pNext;
            delete p;
            return;
        }

        if (Compare(last->newStudent, stud))
        {

            if (first == last)
            {
                Node *p = first;
                first = p->pNext;
                delete p;
            }

            Node *p = first;
            while (p->pNext != last)
                p = p->pNext;

            p->pNext = nullptr;

            delete last;
            last = p;
            return;
        }

        Node *itPrev = first;
        Node *itCurrent = first->pNext;
        while (itCurrent && !Compare(itCurrent->newStudent, stud))
        {
            itCurrent = itCurrent->pNext;
            itPrev = itPrev->pNext;
        }

        if (!itCurrent)
        {
            cout << "This element does not exist" << endl;
            return;
        }

        itPrev->pNext = itCurrent->pNext;
        delete itCurrent;
    }

    StudentList() : first(nullptr), last(nullptr) {}

    void push_back(Student &stud)
    {

        Node *p = new Node(stud);

        if (is_empty())
        {
            first = p;
            last = p;
            size++;
            return;
        }

        Node *temp = first;
        size++;

        while (temp->pNext != nullptr)
        {
            if (StudentsComparator(p->newStudent, temp->newStudent) && StudentsComparator(temp->pNext->newStudent, p->newStudent))
            {
                p->pNext = temp->pNext;
                temp->pNext = p;
                return;
            }
            else if (StudentsComparator(temp->newStudent, p->newStudent))
            {
                p->pNext = first;
                first = p;
                return;
            }
            else
                temp = temp->pNext;
        }

        if (size == 2 && p->newStudent.Surname < temp->newStudent.Surname) // провервка в начале когда только два узла
        {
            p->pNext = last;
            first = p;
            // last = p->pNext;
            return;
        }
        last->pNext = p; // присваиваем в текущем последнем узле указателю pNext следующий узел
        last = p;        // last присваем новый последний узел
    }
};

bool DateComparator(Date First, Date Last)
{
    if (First.Year == Last.Year)
    {
        if (First.Month == Last.Month)
        {
            return (First.Day < Last.Day);
        }
        else
        {
            return (First.Month < Last.Month);
        }
    }
    else
    {
        return (First.Year < Last.Year);
    }
}

Student &StudentList::operator[](const int index)
{
    if (index > size - 1)
        throw invalid_argument("Accessing element out of bounds.");
    int counter = 0;

    Node *current = this->first;

    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->newStudent;
        }
        current = current->pNext;
        counter++;
    }
}

int SearchTheoldestStudent(StudentList &studentList, int firstStudent, int Course)
{
    Date minDate = studentList[firstStudent].BirthDate;
    Student tempStudent = studentList[firstStudent];
    int minIndex = firstStudent;
    for (int k = 0; k < studentList.GetSize(); k++)
    {
        if (!DateComparator(minDate, studentList[k].BirthDate) && studentList[k].Course == Course)
        {
            minIndex = k;
            tempStudent = studentList[k];
            minDate = studentList[k].BirthDate;
        }
    }
    return minIndex;
}

void FillTheOldestStudentList(StudentList &studentList, StudentList *theOldestStudentList)
{
    for (int course = 1; course <= 4; course++)
        for (int k = 0; k < studentList.GetSize(); k++)
            if (course == studentList[k].Course)
            {
                int index = SearchTheoldestStudent(studentList, k, course);
                theOldestStudentList->push_back(studentList[index]);
                studentList.removeAt(studentList[index]);
                break;
            }
}

void Menu(StudentList &studentList, Student &stud, StudentList &theOlderStudentList)
{
    while (true)
    {
        cout << "Enter the choose:  " << endl;

        cout << "1. Add new student." << endl;
        cout << "2. Find the oldest students on the course." << endl;
        cout << "3. PrintStudentInfo the StudentList's of newStudent." << endl;
        cout << "4. Exit." << endl;

        int choose;
        cin >> choose;

        if (choose == 4)
            break;

        switch (choose)
        {
        case 1:
        {
            cout << "Surname: ";
            cin >> stud.Surname;

            cout << "Name: ";
            cin >> stud.Name;

            cout << "Patronymic: ";
            cin >> stud.Patronymic;

            cout << "BirthDate of birth: ";
            cin >> stud.BirthDate.Day;
            cin >> stud.BirthDate.Month;
            cin >> stud.BirthDate.Year;

            cout << "Course of student: ";
            cin >> stud.Course;

            cout << "Average mark of student: ";
            cin >> stud.Progress;

            studentList.push_back(stud);

            break;
        }
        case 2:
        {

            FillTheOldestStudentList(studentList, &theOlderStudentList);

            break;
        }
        case 3:
        {
            cout << "\n========================LIST=OF=STUDENTS===========================" << endl;
            studentList.PrintStudentsInfo();
            cout << "====================SECOND=LIST=OF=STUDENTS========================" << endl;
            theOlderStudentList.PrintStudentsInfo();

            break;
        }

        default:
            break;
        }

        cout << endl;
    }
}

int main()
{

    StudentList studentList, theOlderStudentList;
    Student newStudent;

    Menu(studentList, newStudent, theOlderStudentList);

    return 0;
}
