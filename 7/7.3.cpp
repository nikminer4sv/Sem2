#include <iostream> 
#include <string>

using namespace std;

struct Date {

    unsigned char Day;
    unsigned char Month;
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

    void PrintStudentInfo(Student StudentData) {

        cout << StudentData.Surname << " " << StudentData.Name << " " << StudentData.Patronymic << endl;

    }

public:
    StudentsList() { 

        Head = nullptr; 
        Size = 0;

    }

    StudentsList(int Size) {

    }

    void Add(Student NewStudent) {

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

    void Remove(int Index) {

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

    }

    void Print() {

        Node* Temp = Head;

        for (int i = 0; i < Size; i++) {

            PrintStudentInfo(Temp->Data);
            Temp = Temp->Next;

        }

    }

};

int main() {

    StudentsList List;

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