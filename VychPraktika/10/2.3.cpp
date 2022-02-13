#include <iostream>

using namespace std;

#define LEN_MAX (255)

class Date
{
public:
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Human
{
	char* LastName = new char[LEN_MAX];
    char* FirstName = new char[LEN_MAX];
    char* Patronymic = new char[LEN_MAX];
	Date DateOfBirth;
	int Course;
    int Progress;

    void Initialization() 
    {
        cout << "First name: ";
        cin >> this->FirstName;

        cout << "Last name: ";
        cin >> this->LastName;

        cout << "Patronomyc: ";
        cin >> this->Patronymic;

        cout << "Date of birth (DD.MM.YYYY): ";
        cin >> this->DateOfBirth.day;
        cin >> this->DateOfBirth.month;
        cin >> this->DateOfBirth.year;

        cout << "Course: ";
        cin >> this->Course;

        cout << "Progress: ";
        cin >> this->Progress; 
    }

    Human()
    {
       Initialization();
    }

    Human(char* FirstName, char* LastName, char* Patronymic, 
            Date DateOfBirth, int Course, int Progress) 
    {
        this->FirstName = FirstName;
        this->LastName = LastName;
        this->Patronymic = Patronymic;
        this->DateOfBirth = DateOfBirth;
        this->Course = Course;
        this->Progress = Progress;

    }
};

struct Node
{
    Human Student;
    Node* Next;
};


// class Students 
// {
// private:
//     Human* StudentsData;
//     Human* SortedStudents;
//     int NOS = 0;

// public: 

//     Students(int NumberOfStudents)
//     {
//         NOS = NumberOfStudents;
//         StudentsData = new Human[NOS];
//         for (int i = 0; i < NOS; i++) 
//         {
//             Human TempStudent;
//             StudentsData[i] = TempStudent;
//         }
//     }

//     void Condition(Date age)
//     {
//         for (int i = 0; i < NOS; i++) {
//             if (((StudentsData[i].DateOfBirth.year <= age.year) & (StudentsData[i].DateOfBirth.month <= age.month) & (StudentsData[i].DateOfBirth.day < age.day))) 
//             {
//                 Human TempStudent = StudentsData[i];
//                 SortedStudents.push_back(TempStudent);
//                 for (int j = i; j < StudentsData.size(); j++)
//                 {
//                     StudentsData[j] = StudentsData[j + 1];
//                 }
//             }
//         }
//     }

//     void Print()
//     {
//         for (int i = 0; i < SortedStudents.size(); i++)
//         {
//             /* code */
//         }
        
//     }
// };

int main() 
{
	cout << "Enter the amount of students: ";
	int n;
	cin >> n; 
    cout << "Enter required age (DD.MM.YYYY): ";
    Date age;
    cin >> age.day;
    cin >> age.month;
    cin >> age.year;



    //Students StudentsArray(n);
    //StudentsArray.Condition(age);

	return 0;
}