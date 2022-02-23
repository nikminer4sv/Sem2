#include <iostream>

using namespace std;

#define LEN_MAX (255)

struct Date
{
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Student
{
    string LastName;
    string FirstName;
    string Patronymic;
    Date DateOfBirth;
    int Course;
    int Progress;
};

struct Node
{
    Student Data;
    Node* Next;

    Node()
    {
        Next = nullptr;
    }
};


class StudentsList
{
private:
    Node* Head;

public:
    int Size;

private:
    bool Comparator(Student Head, Student Second)
    {
        return (Head.LastName < Second.LastName);
    }

    void PrintInfo(Student StudentData, int Number)
    {
        cout << Number << ". "
            << StudentData.LastName << " "
            << StudentData.FirstName << " "
            << StudentData.Patronymic << "\n";
    }

public:
    StudentsList()
    {
        Head = nullptr;
        Size = 0;
    }

    Student& Get(int Index)
    {
        if (Index > Size - 1 || Index < 0)
            throw invalid_argument("Invalid");

        Node* Temp = Head;

        for (int i = 0; i < Index; i++)
            Temp = Temp->Next;

        return Temp->Data;
    }

    void Add(const Student& AddStudent) {

        Size++;

        Node* NewNode = new Node;
        NewNode->Data = AddStudent;

        if (Head == nullptr) {
            Head = NewNode;
        }
        else if (!Comparator(Head->Data, NewNode->Data))
        {
            NewNode->Next = Head;
            Head = NewNode;
        }
        else if (Head->Next == nullptr)
        {
            Head->Next = NewNode;
        }
        else
        {
            Node* First = Head;
            Node* Second = Head->Next;
            bool IsPutted = false;

            while (Second->Next != nullptr) {

                if (Comparator(First->Data, NewNode->Data) && !Comparator(Second->Data, NewNode->Data))
                {
                    NewNode->Next = First->Next;
                    First->Next = NewNode;
                    IsPutted = true;
                    break;
                }

                First = First->Next;
                Second = Second->Next;
            }

            if (!IsPutted)
            {
                Second->Next = NewNode;
            }
        }
    }

    bool Remove(int Index)
    {
        if (Index > Size - 1 || Index < 0)
            return false;

        if (Index == 0)
        {
            Head = Head->Next;
        }
        else
        {
            Node* Temp = Head;

            for (int i = 0; i < Index - 1; i++)
                Temp = Temp->Next;

            Temp->Next = Temp->Next->Next;
        }

        Size--;

        return true;
    }

    void PrintStudents()
    {
        Node* Temp = Head;
        cout << "Size is: " << Size << endl;

        for (int i = 0; i < Size; i++)
        {
            PrintInfo(Temp->Data, i + 1);
            Temp = Temp->Next;
        }
    }

    ~StudentsList()
    {
        Node* Current = Head;

        while (Current != nullptr)
        {
            Node* next = Current->Next;
            delete Current;
            Current = next;
        }

        Head = nullptr;
    }

};

class Menu
{
private:
    StudentsList* Students;
    StudentsList* TaskStudents;
public:

private:
    void PrintMenu()
    {
        system("cls");
        cout << "1. Add\n"
            << "2. Delete\n"
            << "3. Print list\n"
            << "4. Task\n"
            << "5. Exit\n";
    }

    void ValidateInput(int& Choice)
    {
        while (true)
        {
            cin >> Choice;

            if (cin.fail())
            {
                system("cls");
                cout << "Please, enter the number.\n";
                cin.clear();
                fflush(stdin);
                getchar();
                PrintMenu();
                continue;
            }
            else if (Choice < 1 || Choice > 5)
            {
                system("cls");
                cout << "Please, enter the right number.\n";
                cin.clear();
                fflush(stdin);
                getchar();
                PrintMenu();
                continue;
            }

            PrintMenu();
            break;
        }
    }

    Student MakeNewStudent()
    {
        Student NewStudent;

        cout << "Name: ";
        cin >> NewStudent.FirstName;

        cout << "LastName: ";
        cin >> NewStudent.LastName;

        cout << "Patronymic: ";
        cin >> NewStudent.Patronymic;

        cout << "Birthdate (DD MM YYYY): ";
        cin >> NewStudent.DateOfBirth.day >> NewStudent.DateOfBirth.month >> NewStudent.DateOfBirth.year;

        cout << "Course: ";
        cin >> NewStudent.Course;

        cout << "Progress: ";
        cin >> NewStudent.Progress;

        return NewStudent;
    }

    void AddElement()
    {
        system("cls");
        Students->Add(MakeNewStudent());
    }

    void DeleteElement()
    {
        system("cls");
        int Index;
        cout << "Enter index of the element: ";
        cin >> Index;

        Students->Remove(Index);
    }

    void Print(StudentsList* Needs)
    {
        system("cls");
        Needs->PrintStudents();

        cin.clear();
        fflush(stdin);
        getchar();
    }

    bool Comporator(double First, double Second)
    {
        return First > Second;
    }

    double AverageProgress(StudentsList* Students)
    {
        double EverybodyProgress = 0.0, Average = 0.0;

        for (int i = 0; i < Students->Size; i++)
        {
            Student Temp = Students->Get(i);
            EverybodyProgress += Temp.Progress;
        }

        Average = EverybodyProgress / Students->Size;

        return Average;
    }

    void Task(StudentsList* Students, StudentsList* TaskStudents)
    {
        double Average = AverageProgress(Students);

        StudentsList NewList;

        for (int i = 0; i < Students->Size; i++)
        {
            Student Temp = Students->Get(i);
            if (Comporator(Temp.Progress, Average))
            {
                cout << Temp.Progress << " > " << Average << endl;
                NewList.Add(Temp);
                Students->Remove(i);
            }
        }
        *TaskStudents = NewList;
        Print(TaskStudents);
    }

    void TaskResult()
    {
        system("cls");
        Task(Students, TaskStudents);
        Task(Students, TaskStudents);
    }

public:

    void Beginning(StudentsList* Students, StudentsList* TaskStudents)
    {
        this->Students = Students;
        this->TaskStudents = TaskStudents;
        StartMainMenu();
    }

    void StartMainMenu()
    {
        bool IsWorking = true;
        while (IsWorking)
        {
            PrintMenu();
            int Choice = 0;
            ValidateInput(Choice);
            switch (Choice)
            {
            case 1:
                AddElement();
                break;

            case 2:
                DeleteElement();
                break;

            case 3:
                Print(Students);
                break;

            case 4:
                TaskResult();
                break;

            case 5:
                IsWorking = false;
                break;
            }
        }
    }

};

int main()
{
    Menu StudentsMenu;
    StudentsList Students, TaskStudents;

    StudentsMenu.Beginning(&Students, &TaskStudents);

    return 0;
}