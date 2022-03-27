#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

bool PositiveComporator(const int &number)
{
	return number >= 0;
}

bool NegativeComporator(const int &number)
{
	return !PositiveComporator(number);
}

void CheckAndWrite(ifstream &inputFileStream, ofstream &outputFileStream, function<bool(const int &)> CheckFunction, int size)
{

	if (inputFileStream.is_open() && outputFileStream.is_open())
	{
		int value;
		for (int k = 0; k < size; k++)
		{
			inputFileStream >> value;
			if (CheckFunction(value))
				outputFileStream << value << " ";
		}

		outputFileStream << "\n";
	}
	else
	{
		throw runtime_error("Could not open file");
	}
}

void FillTheInputFile(int size)
{
	ofstream fout("input.txt", ios::out);

	for (int i = 0; i < size; i++)
	{
		int element = rand() % 2000 - 1000;
		fout << element << " ";
	}

	fout.close();
}

int main()
{
	srand(time(NULL));

	cout << "Enter the size of the file: " << endl;
	int size;
	cin >> size;

	FillTheInputFile(size);

	ifstream inputFileStream;
	inputFileStream.open("input.txt");

	ofstream outputFileStream;
	outputFileStream.open("output.txt");

	CheckAndWrite(inputFileStream, outputFileStream, PositiveComporator, size);
	inputFileStream.seekg(0, ios::beg);
	CheckAndWrite(inputFileStream, outputFileStream, NegativeComporator, size);

	inputFileStream.close();
	outputFileStream.close();

	return 0;
}