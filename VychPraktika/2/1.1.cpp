#include <iostream>
#include <iomanip>

using namespace std;

void FillArray(int **array, const int size)
{

	if (size != 0)
	{
		int numberOfTurns = size + (size - 1);
		int temp = 1;
		int nextSize = 0;
		int eachFourthTurn = 0;

		while (numberOfTurns > 0)
		{
			int i = size - nextSize - 1, j = size - eachFourthTurn - 1;

			//ход влево
			while (j > nextSize - 1)
			{
				array[i][j] = temp++;
				j--;
			}

			numberOfTurns--;
			i--;
			j++;

			//ход вверх
			while (i > nextSize - 1)
			{
				array[i][j] = temp++;
				i--;
			}

			i++;
			j++;
			numberOfTurns--;

			//ход вправо
			while (j <= size - eachFourthTurn - 1)
			{
				array[i][j] = temp++;
				j++;
			}

			numberOfTurns--;
			eachFourthTurn++;
			i++;
			j--;

			//ход вниз
			while (i <= size - eachFourthTurn - 1)
			{
				array[i][j] = temp++;
				i++;
			}

			numberOfTurns--;
			nextSize++;
		}
	}
}

void PrintArray(int **array, const int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			cout << setw(size) << array[i][j];
		cout << endl;
	}
}

int main()
{
	cout << "Enter the order of the matrix: ";
	int size;
	cin >> size;

	int **array = new int *[size];
	for (int i = 0; i < size; i++)
		array[i] = new int[size];

	FillArray(array, size);
	PrintArray(array, size);

	for (int i = 0; i < size; i++)
		delete array[i];
	delete[] array;

	return 0;
}
