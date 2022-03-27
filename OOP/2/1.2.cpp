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

void CheckAndWrite(ifstream &inputFileStream, ofstream &outputFileStream, function<bool(const int &)> CheckFunction, const int size)
{

	if (inputFileStream.is_open() && outputFileStream.is_open())
	{
		int value;
		for (int k = 0; k < size; k++)
		{
			inputFileStream.read((char *)&value, sizeof(int));
			if (CheckFunction(value))
				outputFileStream.write(reinterpret_cast<char *>(&value), sizeof(value));
		}
	}
	else
	{
		throw runtime_error("Could not open file");
	}
}

void writeRandom(int size)
{
	FILE *pFile;
	if ((pFile = fopen("input.bin", "w+")) == NULL)
	{
		perror("Error while opening the file.");
	}
	for (int i = 0; i < size; ++i)
	{
		int value = rand() % 100 - 50;
		value *= value;
		fwrite(&value, sizeof(int), 1, pFile);
	}
	fclose(pFile);
}

int main()
{
	srand(time(NULL));

	cout << "Enter the size of the file: " << endl;
	int size;
	cin >> size;

	writeRandom(size);

	ifstream inputFileStream;
	inputFileStream.open("input.bin", ios::binary);

	ofstream outputFileStream;
	outputFileStream.open("output.bin", ios::binary);

	CheckAndWrite(inputFileStream, outputFileStream, PositiveComporator, size);
	inputFileStream.seekg(0, ios::beg);
	CheckAndWrite(inputFileStream, outputFileStream, NegativeComporator, size);

	inputFileStream.close();
	outputFileStream.close();

	return 0;
}