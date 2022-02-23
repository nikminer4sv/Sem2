#include <iostream>
#include <conio.h>

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

    static bool Compare(const Student& First, const Student& Second)
    {
        return First.LastName < Second.LastName;
    }

    void Print(int Number)
    {
        cout << Number << ". "
            << LastName << " "
            << FirstName << " "
            << Patronymic << "\n";
    }
};

struct Node
{
    Student Data;
    Node* Next;

    Node()
    {
        Next = nullptr;
    }

    explicit Node(const Student& data, Node* next = nullptr)
    {
        Data = data;
        Next = next;
    }
};


class StudentsList
{
private:
    Node* Head;

public:
    int Size;

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

    void Add(const Student& AddStudent) 
    {
        Size++;

        if (!Head || Student::Compare(AddStudent, Head->Data)) 
        {
            Head = new Node(AddStudent, Head);
            return;
        }
        
        Node *Temp = Head;
        Node *BeforeTemp = Head;

        while (Temp && Student::Compare(Temp->Data, AddStudent)) 
        {
            BeforeTemp = Temp;
            Temp = Temp->Next;
        }

        BeforeTemp->Next = new Node(AddStudent, Temp);
    }

    bool Remove(int Index)
    {
        if (Size == 0 || Index > Size - 1 || Index < 0)
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
            Temp->Data.Print(i + 1);
            Temp = Temp->Next;
        }
    }

    void Clear()
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

    ~StudentsList()
    {
        Clear();
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
                _getch();
                PrintMenu();
                continue;
            }
            else if (Choice < 1 || Choice > 5)
            {
                system("cls");
                cout << "Please, enter the right number.\n";
                cin.clear();
                fflush(stdin);
                _getch();
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
        _getch();
    }

    double AverageProgress(StudentsList* Students)
    {
        double EverybodyProgress = 0.0;

        for (int i = 0; i < Students->Size; i++)
        {
            Student Temp = Students->Get(i);
            EverybodyProgress += Temp.Progress;
        }

        return EverybodyProgress / Students->Size;
    }

    void Task(StudentsList* Students, StudentsList* TaskStudents)
    {
        double Average = AverageProgress(Students);
        int Count = 0;

        for (int i = 0; i < Students->Size; i++)
        {
            Student Temp = Students->Get(i);
            if (Temp.Progress > Average)
            {
                (*TaskStudents).Add(Temp);
                Count++;
            }
        }
        while(Count--)
        {
            Students->Remove(Students->Size - 1);
        }
        Print(TaskStudents);
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
                system("cls");
                Task(Students, TaskStudents);
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