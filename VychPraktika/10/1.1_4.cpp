#include<iostream>

using namespace std;

void Print(int **arr, int size) 
{
	cout << endl;
	if (size != 0)
	{
		for (int i = 0; i < size; i++) 
		{
			for (int j = 0; j < size; j++) 
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl << endl;
		}
	}
}

void MakeSpiral(int **arr, int size)
{
	if (size != 0) {
		int MaxTurn = size + (size - 1);
		int Turn = 0;
		int Number = 1;
		int NextSize = 0;
		int EachFourth = 0;

		while (true) {
			int i = size - NextSize - 1, j = size - EachFourth - 1;

			while (i > NextSize - 1) {
				arr[i][j] = Number++;
				i--;
			}

			Turn++;

			if (Turn == MaxTurn) break;

			i++;
			j--;

			while (j > NextSize - 1) {
				arr[i][j] = Number++;
				j--;
			}

			Turn++;

			if (Turn == MaxTurn) break;

			i++;
			j++;

			while (i <= size - EachFourth - 1) {
				arr[i][j] = Number++;
				i++;
			}
			Turn++;

			if (Turn == MaxTurn) break;

			i--;
			j++;
			EachFourth++;

			while (j <= size - EachFourth - 1) {
				arr[i][j] = Number++;
				j++;
			}
			Turn++;

			if (Turn == MaxTurn) break;

			NextSize++;
		}
	}
}

int main() {
	int size;
	cout << "Enter the size of the matrix: ";
	cin >> size;

	int **arr = new int* [size];
	for (int i = 0; i < size; i++) 
	{
		arr[i] = new int [size];
	}

	MakeSpiral(arr, size);
	Print(arr, size);
	
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete arr;

	return 0;
}
