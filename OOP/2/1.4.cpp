#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

using namespace std;

struct Date
{
	Date() {}
	unsigned short day;
	unsigned short month;
	unsigned short year;
};
static_assert(std::is_trivially_copyable<Date>());

struct Student
{
	Student() {}
	char LastName[10];
	char FirstName[10];
	char Patronymic[10];
	Date BirthDate;
	unsigned short Course;
	unsigned short Progress;
};
static_assert(std::is_trivially_copyable<Student>());

class BINFile
{
private:
	int n = 10;
	char *text = new char[n]{};

	template <typename T>
	T getRand(T min, T max)
	{
		return rand() % (max - min + 1) + min;
	}

	char *fillRandomText(char text[])
	{
		int m = rand() % n + 1;

		for (int i = 0; i < m; i++)
			text[i] = 0;

		for (int j = 0; j < m; j++)
			text[j] += getRand('a', 'z');

		text[m] = '\0';

		return text;
	}

	unsigned short fillRandomNumber()
	{
		unsigned short kek = getRand(1, 10);

		return kek;
	}

	Date fillRandomDate()
	{
		Date NoDate;
		NoDate.day = getRand(1, 31);
		NoDate.month = getRand(1, 12);
		NoDate.year = getRand(1, 99);

		return NoDate;
	}

	bool DateComparator(Date First, Date Last)
	{
		if (First.year == Last.year)
		{
			if (First.month == Last.month)
			{
				return (First.day < Last.day);
			}
			else
			{
				return (First.month < Last.month);
			}
		}
		else
		{
			return (First.year < Last.year);
		}
	}

public:
	BINFile() = default;

	~BINFile()
	{
		delete[] text;
	}

	void createBinFile(ofstream &out, Student &NoName)
	{
		strncpy(NoName.LastName, fillRandomText(text), n);
		strncpy(NoName.FirstName, fillRandomText(text), n);
		strncpy(NoName.Patronymic, fillRandomText(text), n);
		NoName.BirthDate = fillRandomDate();
		NoName.Progress = fillRandomNumber();
		NoName.Course = fillRandomNumber();

		out.write(reinterpret_cast<char *>(&NoName), sizeof(Student));
	}

	void readBinFile(ifstream &infile, Student &NoName)
	{
		if (!infile.is_open())
			cout << "Error! File could not been open!" << endl;

		infile.read(reinterpret_cast<char *>(&NoName), sizeof(Student));
	}

	void readTextFile(ifstream &infile, Student &tempStudent)
	{
		if (!infile.is_open())
		{
			cout << "You loh" << endl;
			return;
		}

		infile >> tempStudent.LastName >> tempStudent.FirstName >> tempStudent.Patronymic >> tempStudent.BirthDate.day >> tempStudent.BirthDate.month >> tempStudent.BirthDate.year >> tempStudent.Course >> tempStudent.Progress;
	}

	void printStudent(const Student &NoName) const
	{
		cout << endl;
		cout << "Last name: " << NoName.LastName << endl;
		cout << "First name: " << NoName.FirstName << endl;
		cout << "Patronymic: " << NoName.Patronymic << endl;
		cout << "Day of birth: " << NoName.BirthDate.day << endl;
		cout << "Month of birth: " << NoName.BirthDate.month << endl;
		cout << "Year of birth: " << NoName.BirthDate.year << endl;
		cout << "Progress: " << NoName.Progress << endl;
		cout << "Course: " << NoName.Course << endl
			 << endl
			 << endl;
	}

	void FillTheArray(const int size, ifstream &infile, ofstream &outfile, int &sizeTask)
	{
		Student tempStudent;

		Student *array = new Student[size];
		for (int i = 0; i < size; i++)
		{
			infile.read(reinterpret_cast<char *>(&tempStudent), sizeof(Student));
			array[i] = tempStudent;
		}

		FillTheOldestStudentList(array, size, outfile, sizeTask);
	};

	int SearchTheoldestStudent(Student *studentList, int firstStudent, int Course, const int size, int &sizeTask)
	{
		Date minDate = studentList[firstStudent].BirthDate;
		Student tempStudent = studentList[firstStudent];
		int minIndex = firstStudent;
		for (int k = 0; k < size; k++)
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

	void FillTheOldestStudentList(Student *studentList, const int size, ofstream &outfile, int &sizeTask)
	{
		for (int course = 1; course <= 10; course++)
			for (int k = 0; k < size; k++)
				if (course == studentList[k].Course)
				{
					int index = SearchTheoldestStudent(studentList, k, course, size, sizeTask);
					cout << index << " ";
					WriteInBinFile(studentList[index], outfile, sizeTask);
					break;
				}
	}

	void WriteInBinFile(Student tempStudent, ofstream &outfile, int &sizeTask)
	{

		outfile << tempStudent.LastName << endl
				<< tempStudent.FirstName << endl
				<< tempStudent.Patronymic << endl
				<< tempStudent.BirthDate.day << ' '
				<< tempStudent.BirthDate.month << ' '
				<< tempStudent.BirthDate.year << endl
				<< tempStudent.Course << endl
				<< tempStudent.Progress << endl;
		sizeTask++;
	}
};

int main()
{
	srand(time(NULL));

	Student NoName;
	Student BINNoName;
	BINFile task;

	int size = 0;
	int sizeTask = 0;
	while (true)
	{
		cout << "Menu:\n";
		int choose;
		cout << "1. Add student.\n"
			 << "2. Read and print student.\n"
			 << "3. Task.\n"
			 << "4. Read and print task.\n"
			 << "0. Exit.\n";

		cout << "Enter the choose: ";
		cin >> choose;

		switch (choose)
		{
			int quantity;

		case 1:
		{
			cout << "Enter the value of students: ";
			cin >> quantity;

			size += quantity;

			ofstream out("AllStudents(1.4).bin", ios::binary | ios::app);

			for (int i = 0; i < quantity; i++)
				task.createBinFile(out, NoName);

			cout << endl;
			out.close();
			break;
		}

		case 2:
		{
			ifstream infile("AllStudents(1.4).bin", ios::binary);

			for (int i = 0; i < size; i++)
			{
				task.readBinFile(infile, BINNoName);
				task.printStudent(BINNoName);
			}

			infile.close();
			break;
		}

		case 3:
		{

			ifstream infile("AllStudents(1.4).bin", ios::binary);
			ofstream out("OldestStudents.txt", ios::binary | ios::app);

			task.FillTheArray(size, infile, out, sizeTask);

			infile.close();
			out.close();
			break;
		}

		case 4:
		{
			ifstream infile("OldestStudents.txt", ios::binary);
			for (int i = 0; i < sizeTask; i++)
			{
				task.readTextFile(infile, BINNoName);
				task.printStudent(BINNoName);
			}

			infile.close();
			break;
		}

		case 0:
			cout << "Good bye!" << endl;
			break;

		default:
			cout << "You lox! Try again!" << endl;
			break;
		}

		if (choose == 0)
			return 0;
	}
}
