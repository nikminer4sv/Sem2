#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Print(vector<vector<int>> Matrix, int n);
void Fill(vector<vector<int>> &Matrix, int n);
int Track(vector<vector<int>> Matrix, int n);
void Task(vector<vector<int>> Matrix, int power, int n);
vector<vector<int>> Pow(vector<vector<int>> Matrix, int power, int n);

int main()
{
    system("cls");
    int n, power;
    cout << "Enter the size of the matrix\n";
    cin >> n;
    cout << "Enter the power\n";
    cin >> power;
    system("cls");

    vector<vector<int>> Matrix(n);
	for (int i = 0; i < n; i++)
	{
        vector<int> temp(n);
		Matrix[i] = temp;
	}

    Fill(Matrix, n);
    Print(Matrix, n);
    Task(Matrix, power, n);
}

void Print(vector<vector<int>> Matrix, int n)
{
    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			cout << Matrix[i][j] << "\t";
            _sleep(100);
		}
		cout << endl << endl;
    }
}

void Fill(vector<vector<int>> &Matrix, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			Matrix[i][j] = count++;
		}
    }
}

int Track(vector<vector<int>> Matrix, int n)
{
    size_t i = 0, sum = 0;;
    while (i < n)
    {
        sum += Matrix[i][i];
        i++;
    }

    return sum;
}

void Task(vector<vector<int>> Matrix, int power, int n) 
{
    vector<vector<int>> temp = Matrix;
    size_t i = 1, sum = 0;
    while (i <= power)
    {
        sum += Track(temp, n);
        temp = Pow(Matrix, ++i, n);
    }
    cout << "sum -> " << sum << endl;
}

vector<vector<int>> Pow(vector<vector<int>> Matrix, int power, int n) 
{
    vector<vector<int>> copy = Matrix;
    vector<vector<int>> result(n);

	for (int i = 0; i < n; i++)
	{
        vector<int> temp(n);
		result[i] = temp;
	}

    for (int f = 0; f < power - 1; f++) 
    {
        for (int i = 0; i < n; i++) 
        {
            vector<int> temp(n);
            for (int j = 0; j < n; j++) 
            {
                int ElementValue = 0;
                for (int t = 0; t < n; t++)
                {
                    ElementValue += Matrix[i][t] * copy[t][j];
                }
                result[i][j] = ElementValue;
            }
        }
        copy = result;
    }

    return result;
}
