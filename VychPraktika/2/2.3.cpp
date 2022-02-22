#include <iostream>

using namespace std;

struct Date
{

    unsigned short Day;
    unsigned short Month;
    unsigned short Year;

    Date() {}

    Date(unsigned char Day, unsigned char Month, unsigned short Year)
    {

        this->Day = Day;
        this->Month = Month;
        this->Year = Year;
    }
};

struct Student
{

    string Name;
    string Surname;
    string Patronymic;
    Date BirthDate;
    int Course;
    unsigned char AverageMark;
};

Student CreateStudent()
{

    Student NewStudent;

    cout << "Enter name: ";
    cin >> NewStudent.Name;

    cout << "Enter surname: ";
    cin >> NewStudent.Surname;

    cout << "Enter patronymic: ";
    cin >> NewStudent.Patronymic;

    cout << "Enter birthdate(using spaces between numbers): ";
    cin >> NewStudent.BirthDate.Day >> NewStudent.BirthDate.Month >> NewStudent.BirthDate.Year;

    cout << "Enter course: ";
    cin >> NewStudent.Course;

    cout << "Enter progress: ";
    cin >> NewStudent.AverageMark;

    cout << endl
         << endl;

    return NewStudent;
}

void PrintStudentInfo(Student student)
{
    cout << "Name: " << student.Name << endl
         << "Surname: " << student.Surname << endl
         << "Patronymic: " << student.Patronymic << endl;
    cout << "Birth date: " << student.BirthDate.Day << "/" << student.BirthDate.Month << "/" << student.BirthDate.Year << endl;
    cout << "Course: " << student.Course << endl;
    cout << "Average mark: " << student.AverageMark << endl;
}

bool DateComporator(Date First, Date Last)
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

class StudentList
{
public:
    StudentList();
    ~StudentList();

    void insert(Student newStudent, int index);
    void removeAt(int index);
    void pop_front();
    void pop_back();
    void push_front(Student newStudent);
    void push_back(Student newStudent);
    int GetSize() { return Size; }
    Student &operator[](const int index);
    void clear();

private:
    class Node
    {
    public:
        Node *pNext;
        Student newStudent;

        Node(Student newStudent, Node *pNext = nullptr)
        {
            this->newStudent = newStudent;
            this->pNext = pNext;
        }
    };

    bool StudentsComporator(Student First, Student Second)
    {

        return (First.Surname < Second.Surname);
    }

    void FindNeededPointer(Node *previous, int index);
    int Size;
    Node *head;
};

void StudentList::FindNeededPointer(Node *previous, int index)
{
    for (int k = 0; k < index - 1; k++)
    {
        previous = previous->pNext;
    }
}

StudentList::StudentList()
{
    Size = 0;
    head = nullptr;
}

StudentList::~StudentList()
{
    clear();
}

void StudentList::clear()
{
    while (Size)
    {
        pop_front();
    }
}

void StudentList::insert(Student newStudent, int index)
{
    if (index > Size - 1)
    {
        throw invalid_argument("Accessing element out of bounds.");
    }
    else if (index == 0)
    {
        push_front(newStudent);
    }
    else if (index == Size - 1)
    {
        push_back(newStudent);
    }
    else
    {
        Node *previous = this->head;

        FindNeededPointer(previous, index);

        Node *newNode = new Node(newStudent, previous->pNext);
        previous->pNext = newNode;

        Size++;
    }
}

void StudentList::removeAt(int index)
{
    if (index > Size - 1)
    {
        throw invalid_argument("Accessing element out of bounds.");
    }
    else if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node *previous = this->head;

        FindNeededPointer(previous, index);

        Node *toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;
        Size--;
    }
}

void StudentList::push_front(Student newStudent)
{
    head = new Node(newStudent, head);
    Size++;
}

void StudentList::push_back(Student addedStudent)
{
    if (head == nullptr)
    {
        head = new Node(addedStudent);
    }
    else
    {
        Node *current = new Node(addedStudent, this->head);
        if (!StudentsComporator(head->newStudent, current->newStudent))
        {
            current->pNext = head;
            head = current;
        }
        else
        {

            if (head->pNext == nullptr)
            {
                head->pNext = current;
            }
            else
            {
                Node *first = this->head;
                Node *second = head->pNext;
                bool isPutted = false;

                while (second != nullptr)
                {
                    if (StudentsComporator(first->newStudent, current->newStudent) &&
                        !StudentsComporator(second->newStudent, current->newStudent))
                    {
                        current->pNext = first->pNext;
                        first->pNext = current;
                        isPutted = true;
                        break;
                    }
                    first = first->pNext;
                    second = second->pNext;
                }
                if (!isPutted)
                {
                    second->pNext = current;
                }
            }
        }
    }
    Size++;
}

void StudentList::pop_front()
{
    Node *temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

void StudentList::pop_back()
{
    removeAt(Size - 1);
}

Student &StudentList::operator[](const int index)
{
    if (index > Size - 1)
        throw invalid_argument("Accessing element out of bounds.");
    int counter = 0;
    Node *current = this->head;

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

void FindTheOldestStudent(StudentList &studentList, StudentList *theOldestStudents)
{
    for (int i = 1; i <= 4; i++)
    {
        int count = 1;
        int index;
        for (int k = 0; k < studentList.GetSize(); k++)
        {
            if (i == studentList[k].Course)
            {
                Student theOldestStudent = studentList[k];
                if (k + 1 <= studentList.GetSize())
                {
                    for (int j = k + 1; j < studentList.GetSize(); j++)
                    {
                        if (i == studentList[j].Course)
                            if (!DateComporator(theOldestStudent.BirthDate, studentList[j].BirthDate))
                            {
                                count++;
                                index = j;
                            }
                    }
                }
                theOldestStudents->push_back(theOldestStudent);
                if (count == 1)
                {
                    studentList.removeAt(k);
                }
                else
                {
                    studentList.removeAt(index);
                }
            }
        }
    }
}

void PrintStudentsInfo(StudentList &studentList)
{
    for (int k = 0; k < studentList.GetSize(); k++)
    {
        PrintStudentInfo(studentList[k]);
        cout << endl;
    }
    cout << endl;
}

void FillTheStudentList(StudentList *studentList, const int size)
{
    for (int k = 0; k < size; k++)
    {
        studentList->push_back(CreateStudent());
    }
}

int main()
{
    StudentList studentList;

    cout << "Enter the amount of students: " << endl;
    int amountOfStudents;
    cin >> amountOfStudents;

    FillTheStudentList(&studentList, amountOfStudents);
    cout << "All students: " << endl;
    PrintStudentsInfo(studentList);

    cout << "The oldest students: " << endl;
    StudentList theOldestStudents;
    FindTheOldestStudent(studentList, &theOldestStudents);
    PrintStudentsInfo(theOldestStudents);

    studentList.clear();
    theOldestStudents.clear();

    return 0;
}