#include <iostream>

using namespace std;

void PrintMatrix(int **, int);
void Maximums(int **, int);
void PrintMaximum(int *, int);

int main() 
{
    int n;
    cout << "Matrix size: ";
    cin >> n;

    int **matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
    PrintMatrix(matrix, n);
    Maximums(matrix, n);
}

void PrintMatrix(int **matrix , int n)
{
    cout << "Elements of matrix are:\n\n";

    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			matrix[i][j] = rand() % 100 + 1;
			cout << matrix[i][j] << "\t";
		}
		cout << endl << endl;
    }
}

void Maximums(int **matrix , int n)
{
    int maximums[2 * n - 1]; // массив максимумов
    int number = 0;

    for (int i = 1; i <= n; i++) // до главной диагонали
	{
        int max = 0;
		for (int k = 1 , m = i + 1 - k; k < i + 1; k++ , m--) 
		{
            if (max < matrix[k - 1][n - m])
            {
                max = matrix[k - 1][n - m];
            }
		}
        maximums[number++] = max;
    }

    for (int i = 1; i < n; i++) // после главной диагонали
	{
        int max = 0;
		for (int k = 0; k < n - i; k++) 
		{
            if (max < matrix[i + k][k])
            {
                max = matrix[i + k][k];
            }
		}
        maximums[number++] = max;
    }
    PrintMaximum(maximums , n);
}

void PrintMaximum(int *maximums, int n)
{
    cout << "Maximums in diagonalies are : ";

    for (int i = 0; i < 2 * n - 1; i++) // вывод максимумов
    {
        cout << maximums[i] << " ";
    }
}