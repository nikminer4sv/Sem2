#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

int From2DTo1D(int x, int y, int n);
int* CreateMatrix(int n);
int** CreateMatrix2(int n);
void Fill(int* Matrix, int n);
void Fill(int** Matrix, int n);
void PrintMatrix(int * Matrix, int n);
void PrintMatrix(int ** Matrix, int n);
vector<int> Maximums(int * Matrix, int n);
vector<int> Maximums(int ** Matrix, int n);
void PrintMaximum(vector<int> maximums, int n);

int main() 
{
    system("cls");
    int n, Choice;
    cout << "Matrix size: ";
    cin >> n;
    cout << "Choose type of matrix:\n1. 1D\n2. 2D\n";
    cin >> Choice;
    switch (Choice)
    {
        case 1:
        {
            int *Matrix1D = CreateMatrix(n);
            Fill(Matrix1D, n);
            PrintMatrix(Matrix1D, n);
            vector<int> Maximum;
            Maximum = Maximums(Matrix1D, n);
            PrintMatrix(Matrix1D, n);
            PrintMaximum(Maximum, n);
            break;
        }

        case 2:
        {
            int **Matrix2D = CreateMatrix2(n);
            Fill(Matrix2D, n);
            vector<int> Maximum;
            Maximum = Maximums(Matrix2D, n);
            PrintMatrix(Matrix2D, n);
            PrintMaximum(Maximum, n);
            break;
        }
        
        default:
            cout << "It's not your day";
            break;
    }
}

int From2DTo1D(int x, int y, int n)
{
    return x * n + y;
}

int* CreateMatrix(int n)
{
    int* Matrix = new int[n * n];
    system("cls");
    _sleep(500);
    cout << "Matrix created\nPress any key to continue.." << endl;
    getch();

    return Matrix;
}
int** CreateMatrix2(int n)
{
    int** Matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		Matrix[i] = new int[n];
	}
    system("cls");
    _sleep(500);
    cout << "Matrix created\nPress any key to continue.." << endl;
    getch();

    return Matrix;
}

void Fill(int* Matrix, int n)
{
    for (int i = 0; i < n * n; i++)
	{
        Matrix[i] = rand() % 100 + 1;
    }
    system("cls");
    _sleep(500);
    cout << "Matrix filled\nPress any key to continue.." << endl;
    getch();
}

void Fill(int** Matrix, int n)
{
    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			Matrix[i][j] = rand() % 100 + 1;
		}
    }
    system("cls");
    _sleep(500);
    cout << "Matrix filled\nPress any key to continue.." << endl;
    getch();
}

void PrintMatrix(int *Matrix , int n)
{
    system("cls");
    cout << "Elements of matrix are:\n\n";

    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			cout << Matrix[From2DTo1D(i, j, n)] << "\t";
            _sleep(100);
		}
		cout << endl << endl;
    }
    cout << "Matrix printed" << endl;
}

void PrintMatrix(int **matrix , int n)
{
    system("cls");
    cout << "Elements of matrix are:\n\n";

    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			cout << matrix[i][j] << "\t";
            _sleep(100);
		}
		cout << endl << endl;
    }
    cout << "Matrix printed" << endl;
}

vector<int> Maximums(int *Matrix , int n)
{
    vector<int> maximums;
    int number = 0;

    for (int i = 1; i <= n; i++) // до главной диагонали
	{
        int max = 0;
		for (int k = 1 , m = i + 1 - k; k < i + 1; k++ , m--) 
		{
            if (max < Matrix[From2DTo1D(k - 1, n - m, n)])
            {
                max = Matrix[From2DTo1D(k - 1, n - m, n)];
            }
		}
        maximums.push_back(max);
    }

    for (int i = 1; i < n; i++) // после главной диагонали
	{
        int max = 0;
		for (int k = 0; k < n - i; k++) 
		{
            if (max < Matrix[From2DTo1D(i + k, k, n)])
            {
                max = Matrix[From2DTo1D(i + k, k, n)];
            }
		}
        maximums.push_back(max);
    }

    return maximums;
}

vector<int> Maximums(int **matrix , int n)
{
    vector<int> maximums;

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
        maximums.push_back(max);
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
        maximums.push_back(max);
    }

    system("cls");
    _sleep(500);
    cout << "Maximums Founded\nPress any key to continue.." << endl;
    getch();

    return maximums;
}

void PrintMaximum(vector<int> maximums, int n) 
{
    cout << "Maximums in diagonalies are : ";

    for (int i = 0; i < 2 * n - 1; i++) // вывод максимумов
    {
        cout << maximums[i] << " ";
        _sleep(100);
    }
}