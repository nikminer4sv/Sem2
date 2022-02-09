#include <iostream> 
#include <string>
#include <functional>

using namespace std;

struct Date {

    unsigned short Day;
    unsigned short Month;
    unsigned short Year;

    Date() {}

    Date(unsigned char Day, unsigned char Month, unsigned short Year) {

        this->Day = Day;
        this->Month = Month;
        this->Year = Year;

    }

};

struct Student {

    string Name;
    string Surname;
    string Patronymic;
    Date BirthDate;
    unsigned char Course;
    unsigned char Progress;

};

struct Node {

    Student Data;
    Node* Next;

    Node() { Next = nullptr; }

};

class StudentsList {
private:
    Node* Head;

public:
    int Size;

private:
    bool StudentsComporator(Student First, Student Second) {

        return (First.Surname < Second.Surname);

    }

    void PrintStudentInfo(Student StudentData, int Number) {

        cout << Number << ". " << StudentData.Surname << " " << StudentData.Name << " " << StudentData.Patronymic << endl;

    }

public:
    StudentsList() { 

        Head = nullptr; 
        Size = 0;

    }

    Student& Get(int Index) {
        //TODO: обработать ситуацию когда у нас выход за пределы
        // кидать эксепшн
        // или возвращать указать и кидать нулевой указатель

        if (Index > Size - 1 || Index < 0)
            throw invalid_argument("Invalid index");

        Node* Temp = Head;

        for (int i = 0; i < Index; i++)
            Temp = Temp->Next;

        return Temp->Data;
    }

    void Add(const Student& NewStudent) {

        Size += 1;

        Node* NewNode = new Node;
        NewNode->Data = NewStudent;

        if (Head == nullptr) {
            Head = NewNode;
        } else {

            if (!StudentsComporator(Head->Data, NewNode->Data)) {

                NewNode->Next = Head;
                Head = NewNode;

            } else {

                if (Head->Next == nullptr) {

                    Head->Next = NewNode;

                } else {

                    Node* First = Head;
                    Node* Second = Head->Next;
                    bool IsPutted = false;

                    while (Second != nullptr) {

                        if (StudentsComporator(First->Data, NewNode->Data) && !StudentsComporator(Second->Data, NewNode->Data)) {

                            NewNode->Next = First->Next;
                            First->Next = NewNode;
                            IsPutted = true;
                            break;

                        }

                        First = First->Next;
                        Second = Second->Next;

                    }

                    if (!IsPutted) {

                        Second->Next = NewNode;

                    }

                }

            }

        }

    }

    bool Remove(int Index) {
        //ситуация когда нечего ремувать (лист пустой)
        //ситуация когда индекс слишком большой

        if (Index > Size - 1 || Index < 0)
            return false;

        if (Index == 0) {

            Head = Head->Next;

        } else {

            Node* Temp = Head;

            for (int i = 0; i < Index - 1; i++) 
                Temp = Temp->Next;

            Temp->Next = Temp->Next->Next;

            // 1 2 3 4 5 [3]

        }

        Size -= 1;

        return true;

    }

    void Print() {
        //ситуация когда лист пустой
        //поставить ассерт на размер листа

        //assert(Size > 0);
        
        Node* Temp = Head;

        cout << "Size is: " << Size << endl;

        for (int i = 0; i < Size; i++) {

            PrintStudentInfo(Temp->Data, i + 1);
            Temp = Temp->Next;

        }

    }

    ~StudentsList() {

        Node* current = Head;

        while(current != nullptr) {
            Node* next = current->Next;
            delete current;
            current = next;
        }

        Head = nullptr;

    }

};

class UserInterface {
private:
    const int NUMBER_OF_MENU_ITEMS = 5;
    bool IsWorking;
    StudentsList* List;
    function<void(StudentsList* List)> TaskFunction;

public:

private:
    void ClearConsole() {

        if (system( "cls" )) 
            system( "clear" );

    }

    void WaitForInput() {

        system("read");

    }

    void ValidateInput(int &Choice) {

        while (true) {

            cin >> Choice;

            if (cin.fail()) {

                ClearConsole();
                cout << "Please, enter the number.\n";
                cin.clear();
                fflush(stdin);
                getchar();
                PrintMenu();
                continue;
                
            }

            if (Choice < 1 || Choice > NUMBER_OF_MENU_ITEMS) {

                ClearConsole();
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

    void PrintMenu() {

        ClearConsole();

        cout << "[7.3] LinkedList interface\n";
        cout << "1. Add element\n";
        cout << "2. Delete element\n";
        cout << "3. Print list\n";
        cout << "4. Task\n";
        cout << "5. Exit\n";

    }

    Student CreateStudent() {

        Student NewStudent;

        cout << "Enter name: ";
        cin >> NewStudent.Name;

        cout << "Enter surame: ";
        cin >> NewStudent.Surname;

        cout << "Enter patronymic: ";
        cin >> NewStudent.Patronymic;

        cin.clear();
        fflush(stdin);

        cout << "Enter birthdate(using spaces between numbers): ";
        cin >> NewStudent.BirthDate.Day >> NewStudent.BirthDate.Month >> NewStudent.BirthDate.Year;

        cout << "Enter course: ";
        cin >> NewStudent.Course;

        cout << "Enter progress: ";
        cin >> NewStudent.Progress;

        return NewStudent;

    }

    void AddElementOperation() {

        ClearConsole();

        List->Add(CreateStudent());

    }

    void DeleteElementOperation() {

        ClearConsole();

        int Index;

        cout << "Enter index of the element: "; 
        cin >> Index;

        List->Remove(Index);

    } 

    void PrintOperation() {

        ClearConsole();

        List->Print();

        cin.clear();
        fflush(stdin);

        cout << "Press ENTER to continue...";

        getchar();
        //WaitForInput();

    }

    void TaskOperation() {

        ClearConsole();

        TaskFunction(List);

        cout << "Press ENTER to continue...";

        cin.clear();
        fflush(stdin);

        getchar();

    }

    void QuitOperation() {

        IsWorking = false;

    }

public:

    UserInterface() {

        IsWorking = false;

    }

    void StartUserInterface() {

        IsWorking = true;

        while (IsWorking) {

            PrintMenu();

            int Choice = 0;

            ValidateInput(Choice);

            switch(Choice) {

                case 1:
                    AddElementOperation();
                    break;

                case 2:
                    DeleteElementOperation();
                    break;

                case 3:
                    PrintOperation();
                    break;

                case 4: 
                    TaskOperation();
                    break;

                case 5:
                    QuitOperation();
                    break;


            }

        }

    }

    bool GetCondition() {

        return IsWorking;

    }

    void SetList(StudentsList* List) {

        this->List = List;
    }

    void SetTaskFunction(function<void(StudentsList* List)> Function) {

        TaskFunction = Function;

    }

};

void Hello(int a) {
    
}

bool DateComporator(Date First, Date Last) {

    if (First.Year == Last.Year) {
        
        if (First.Month == Last.Month) {
            
            return (First.Day < Last.Day);

        } else {

            return (First.Month < Last.Month);

        }

    } else {

        return (First.Year < Last.Year);

    }

}

void Task(StudentsList* List) {

    Date GivenDate;
    cout << "Enter birth date(using spaces between numbers): ";
    cin >> GivenDate.Day >> GivenDate.Month >> GivenDate.Year;

    StudentsList NewList;

    for (int i = 0; i < List->Size; i++) {

        Student Temp = List->Get(i);

        if (DateComporator(Temp.BirthDate, GivenDate)) {
            NewList.Add(Temp);
            List->Remove(i);
        }
            
    }

    *List = NewList;

}

int main() {

    StudentsList List;
    UserInterface ui;

    ui.SetList(&List);
    ui.SetTaskFunction(Task);
    ui.StartUserInterface();

    List.Get(100);

    /*Student me;
    me.Name = "Nikita";
    me.Surname = "Korotki";
    me.Patronymic = "Denisovich";
    me.BirthDate = Date(4,11,2003);
    me.Progress = 10;
    me.Course = 1;

    Student other;
    other.Name = "Andrey";
    other.Surname = "Demchenko";
    other.Patronymic = "Alexandrovich";
    other.BirthDate = Date(10,10,2003);
    other.Progress = 8;
    other.Course = 1;

    Student third;
    third.Name = "Andrey";
    third.Surname = "Ash";
    third.Patronymic = "Alexandrovich";
    third.BirthDate = Date(10,10,2003);
    third.Progress = 8;
    third.Course = 1;

    Student fourth;
    fourth.Name = "Andrey";
    fourth.Surname = "Eskereeee";
    fourth.Patronymic = "Alexandrovich";
    fourth.BirthDate = Date(10,10,2003);
    fourth.Progress = 8;
    fourth.Course = 1;

    List.Add(me);
    List.Add(other);
    List.Add(third);
    List.Add(fourth);

    List.Print();
    cout << "-----------" << endl;

    List.Remove(1);
    List.Remove(1);
    List.Remove(1);
    List.Remove(0);

    List.Print();

    cout << List.Size;*/

}