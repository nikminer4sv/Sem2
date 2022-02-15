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

    // void Initialization() 
    // {
    //     cout << "Name: ";
    //     cin >> this->FirstName;

    //     cout << "Surname: ";
    //     cin >> this->LastName;

    //     cout << "Patronomyc: ";
    //     cin >> this->Patronymic;

    //     cout << "Date of birth (DD.MM.YYYY): ";
    //     cin >> this->DateOfBirth.day;
    //     cin >> this->DateOfBirth.month;
    //     cin >> this->DateOfBirth.year;

    //     cout << "Course: ";
    //     cin >> this->Course;

    //     cout << "Progress: ";
    //     cin >> this->Progress; 
    // }

    // Human()
    // {
    //    Initialization();
    // }

    // Human(string FirstName, string LastName, string Patronymic, 
    //         Date DateOfBirth, int Course, int Progress) 
    // {
    //     this->FirstName = FirstName;
    //     this->LastName = LastName;
    //     this->Patronymic = Patronymic;
    //     this->DateOfBirth = DateOfBirth;
    //     this->Course = Course;
    //     this->Progress = Progress;

    // }
};

struct Node
{
    Student NeStudent;
    Node* Next;

    Node() 
    {
        Next = nullptr;
    }
};

class StudentsList 
{
private:
    Node* First;

public:
    int Size;

private:
    bool Comparator(Student First, Student Second) 
    {
        return (First.LastName < Second.LastName);
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
        First = nullptr; 
        Size = 0;
    }

    Student& Get(int Index) 
    {
        if (Index > Size - 1 || Index < 0)
            throw invalid_argument("Invalid");

        Node* Temp = First;

        for (int i = 0; i < Index; i++)
            Temp = Temp->Next;

        return Temp->NeStudent;
    }

    void Add(const Student& AddStudent) 
    {
        Size++;

        Node* NewNode = new Node;
        NewNode->NeStudent = AddStudent;

        if (First == nullptr) 
        {
            First = NewNode;
        } 
        else if (!Comparator(First->NeStudent, NewNode->NeStudent)) 
        {
            NewNode->Next = First;
            First = NewNode;
        } 
        else if (First->Next == nullptr) 
        {
            First->Next = NewNode;
        } 
        else 
        {
            Node* FirstTemp = First;
            Node* SecondTemp = First->Next;
            bool IsPutIn = false;

            while (SecondTemp != nullptr) 
            {
                if (Comparator(FirstTemp->NeStudent, NewNode->NeStudent) && !Comparator(SecondTemp->NeStudent, NewNode->NeStudent)) 
                {
                    NewNode->Next = FirstTemp->Next;
                    FirstTemp->Next = NewNode;
                    IsPutIn = true;
                    break;
                }

                FirstTemp = FirstTemp->Next;
                SecondTemp = SecondTemp->Next;
            }

            if (!IsPutIn) 
            {
                SecondTemp->Next = NewNode;
            }
        }
    }

    bool Remove(int Index) 
    {
        if (Index > Size - 1 || Index < 0)
            return false;

        if (Index == 0) 
        {
            First = First->Next;
        } 
        else 
        {
            Node* Temp = First;

            for (int i = 0; i < Index - 1; i++) 
                Temp = Temp->Next;

            Temp->Next = Temp->Next->Next;
        }

        Size--;

        return true;
    }

    void PrintStudents() 
    {
        Node* Temp = First;
        cout << "Size is: " << Size << endl;

        for (int i = 0; i < Size; i++)
        {
            PrintInfo(Temp->NeStudent, i + 1);
            Temp = Temp->Next;
        }
    }

    ~StudentsList() 
    {
        Node* Current = First;

        while(Current != nullptr) 
        {
            Node* next = Current->Next;
            delete Current;
            Current = next;
        }

        First = nullptr;
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

    void ValidateInput(int &Choice) 
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

        cout << "Birthdate (DD.MM.YYYY): ";
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

    bool Comporator(Date First, Date Second)
    {
        if (First.year <= Second.year && First.month <= Second.month && First.day < Second.day)
            return true;
    }

    void Task(StudentsList* Students, StudentsList* TaskStudents) 
    {
        Date GivenDate;
        cout << "Enter required age (DD.MM.YYYY): ";
        cin >> GivenDate.day >> GivenDate.month >> GivenDate.year;

        StudentsList NewList;

        for (int i = 0; i < Students->Size; i++) 
        {
            Student Temp = Students->Get(i);
            if (Comporator(Temp.DateOfBirth, GivenDate)) 
            {
                NewList.Add(Temp);
                Students->Remove(i);
            }  
        }
        *TaskStudents = NewList;
    }

    void TaskResult() 
    {
        system("cls");
        Task(Students, TaskStudents);
        Print(TaskStudents);
    }
    
public:

    void Quit(bool& IsWorking) {

        IsWorking = false;

    }

    void Begining(StudentsList* Students)
    {
        this->Students = Students;
        MainMenu();
    }

    void MainMenu()
    {
        bool IsWorking = true;
        while (IsWorking) 
        {
            PrintMenu();
            int Choice = 0;
            ValidateInput(Choice);
            switch(Choice) 
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
                    Task(Students, TaskStudents);
                    break;

                case 5:
                    Quit(IsWorking);
                    break;
            }
        }
    }

};

int main() 
{
    StudentsList Students();

	return 0;
}