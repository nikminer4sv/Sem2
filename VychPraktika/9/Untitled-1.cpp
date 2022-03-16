#include <iostream>
#include <string>

using namespace std;

struct Date
{
	 int Day;
	 int Month;
	 int Year;

	Date() {}

};

struct Student
{
	string Name;
	string Surname; 
	string Patronymic;

	Date BirthDay;

	unsigned char Course;
	float Progress;

	Student() {}
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

	bool Comparator(Student First, Student Second)
	{
		if (First.Surname != Second.Surname)
			return (First.Surname < Second.Surname);
		else if (First.Name != Second.Name)
			return (First.Name < Second.Name);
		else
			return (First.Patronymic < Second.Patronymic);
	}

	Student* Make_New_Student()
	{
		Student* NewStudent = new Student;

		cout << "Name: ";
		cin >> NewStudent->Name;

		cout << "Surname: ";
		cin >> NewStudent->Surname;

		cout << "Patronymic: ";
		cin >> NewStudent->Patronymic;

		cout << "Birthdate (DD.MM.YYYY): ";
		cin >> NewStudent->BirthDay.Day >> NewStudent->BirthDay.Month >> NewStudent->BirthDay.Year;

		cout << "Course: ";
		cin >> NewStudent->Course;

		cout << "Progress: ";
		cin >> NewStudent->Progress;

		return NewStudent;
	}

public:

	StudentsList() {

		Head = nullptr;
		Size = 0;

	}


	

	void Print_List(StudentsList& Student)
	{
		Node* temp = Head;
		int count = 1;
		while (temp != nullptr)
		{
			cout << count++ << ". " << temp->Data.Surname << " " << temp->Data.Name << " " << temp->Data.Patronymic << "  " << temp->Data.BirthDay.Day << "." << temp->Data.BirthDay.Month << "." << temp->Data.BirthDay.Year << endl;
			cout << temp->Data.Course << " course  " << temp->Data.Progress << endl;
			temp = temp->Next;
		}
	}

	void Add_Student()
	{
		Student* NewStudent = Make_New_Student();

		Node* NewNode = new Node;

		NewNode->Data = *NewStudent;
		if (Head == nullptr)
		{
			Head = NewNode;
			
		}
		else if(!Comparator(Head->Data, *NewStudent))
		{
			NewNode->Next = Head;
			Head = NewNode;

		}
		else
		{
			Node* temp_first = new Node;
			temp_first = Head;
			Node* temp_second = new Node;
			temp_second = Head->Next;

			while ((temp_second != nullptr) && Comparator(temp_second->Data, *NewStudent))
			{
				temp_first = temp_second;
				temp_second = temp_second->Next;
			}
			if (temp_second == nullptr)
			{
				temp_first->Next = NewNode;
				NewNode->Next = nullptr;
			}
			else
			{
				temp_first->Next = NewNode;
				NewNode->Next = temp_second;
			}
		}

		


			Size++;
	}

	bool Delete_Student(int index)
	{
		if (index > Size || index <= 0)
			return false;

		if (index == 1)
		{
			Node* temp = Head;
			Head = Head->Next;

			delete temp;
		}
		else
		{
			Node* temp = Head;
			for (int i = 0; i < index - 2; i++)
				temp = temp->Next;
			
			Node* temp_2 = temp->Next;
			temp->Next = temp->Next->Next;

			delete temp_2;

		}

		Size--;

		return true;
	}

	void Print_Student(int index)
	{
		if (index > Size || index <= 0)
		throw invalid_argument("Invalid index");

		Node* temp = Head;

		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->Next;
		}

		cout << index << ". " << temp->Data.Surname << " " << temp->Data.Name << " " << temp->Data.Patronymic << "  " << temp->Data.BirthDay.Day << "." << temp->Data.BirthDay.Month << "." << temp->Data.BirthDay.Year << endl;
		cout << temp->Data.Course << " course  " << temp->Data.Progress << endl;
		
	}



	~StudentsList() {

		Node* current = Head;

		while (current != nullptr) {
			Node* next = current->Next;
			delete current;
			current = next;
		}

		Head = nullptr;

	}

};


void Task(StudentsList List_1, StudentsList Excellent_Students)
{

}

int main()
{
	StudentsList List_1;
	StudentsList Excellent_Student;

	int choise;

	do
	{
		cout << "Select operation:\n";
		cout << "1. Add student\n";
		cout << "2. Delete student\n";
		cout << "3. Print student \n";
		cout << "4. Print list\n";
		cout << "5. Task\n";
		cout << "6. Exit\n";

		do
		{
			cin >> choise;
		} while ((choise > 6) || (choise < 1));


		switch (choise)
		{
		case 1:
			List_1.Add_Student();
			break;

		case 2:
			int index;
			cin >> index;
			List_1.Delete_Student(index);

			break;
		case 3:
			int index_2;
			cin >> index_2;
			List_1.Print_Student(index_2);
			break;
		case 4:
			List_1.Print_List(List_1);
			break;
		case 5:
			Task(List_1, Excellent_Student);
			break;
		case 6:
			break;
		}

	} while (choise != 6);
	
}