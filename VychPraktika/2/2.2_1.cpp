#include <iostream>
#include <ctime>

using namespace std;

enum Matrices
{
	A = 0,
	B = 1,
	C = 2,
	D = 3
};

void TheMatrixWrapper(double *&matrix, const int order)
{
	matrix = new double[order * order];
}

void FillTheMatrix(double *matrix, const int order)
{
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			matrix[i * order + j] = rand() % 11 + rand() % 10 * 0.1;
		}
	}
}

void PrintTheMatrix(const double *matrix, const int order, const int indexOfMatrix)
{
	switch (indexOfMatrix)
	{
	case A:
		cout << "A matrix:" << endl;
		break;
	case B:
		cout << "B matrix:" << endl;
		break;
	case C:
		cout << "C matrix:" << endl;
		break;
	case D:
		cout << "D matrix:" << endl;
		break;
	default:
		cout << "Error";
		break;
	}
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			cout << matrix[i * order + j] << "	";
			if (j + 1 == order)
			{
				cout << endl;
			}
		}
	}
}

void PrintTheMatrix(const double *matrix, const int order)
{
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			cout << matrix[i * order + j] << "	";
			if (j + 1 == order)
			{
				cout << endl;
			}
		}
	}
}

void SumTheMatrices(double *&matrix, double *&newMatrix, const int order)
{
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			newMatrix[i * order + j] += matrix[i * order + j];
		}
	}
}

void MultiplyTheMatrices(double *matrix, double *matrix2, double *matrix3, const int order)
{
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			matrix3[i * order + j] = 0;
		}
	}

	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			double sum = 0;
			for (int k = 0; k < order; k++)
			{
				sum += matrix[i * order + k] * matrix2[k * order + j];
			}
			matrix3[i * order + j] = sum;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	cout << "Enter the order of the matrix: ";
	int order;
	cin >> order;
	cout << endl
		 << endl;

	double *matrices[4];

	cout << "Matrices: " << endl
		 << endl;
	for (int k = 0; k < 3; k++)
	{
		TheMatrixWrapper(matrices[k], order);
		FillTheMatrix(matrices[k], order);
		PrintTheMatrix(matrices[k], order, k);
		cout << endl;
	}

	cout << endl
		 << "Sum of B and C matrices: "
		 << endl;
	SumTheMatrices(matrices[1], matrices[2], order);
	PrintTheMatrix(matrices[2], order);

	cout << endl
		 << "Result of А * ( В + С )."
		 << endl;
	TheMatrixWrapper(matrices[3], order);
	MultiplyTheMatrices(matrices[0], matrices[2], matrices[3], order);
	PrintTheMatrix(matrices[3], order, 3);

	for (int k = 0; k < 4; k++)
		delete[] matrices[k];

	return 0;
}