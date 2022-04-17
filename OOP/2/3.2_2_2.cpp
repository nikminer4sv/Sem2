#include <iostream>
#include <vector>

enum Matrices
{
	A = 0,
	B = 1,
	C = 2,
	D = 3
};

void SumTheMatrices(std::vector<std::vector<double>> &matrix, std::vector<std::vector<double>> &newMatrix, const int order)
{
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			newMatrix[i][j] += matrix[i][j];
		}
	}
}

void MultiplyTheMatrices(std::vector<std::vector<double>> &matrix, std::vector<std::vector<double>> &matrix2, std::vector<std::vector<double>> &matrix3, const int order)
{
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			matrix3[i][j] = 0;
		}
	}

	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			double sum = 0;
			for (int k = 0; k < order; k++)
			{
				sum += matrix[i][k] * matrix2[k][j];
			}
			matrix3[i][j] = sum;
		}
	}
}

void FillTheMatrix(std::vector<std::vector<double>> &matrixTemplate, const int order)
{
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			matrixTemplate[i][j] = rand() % 10 + rand() % 10 * 0.1;
		}
	}
}

void TheMatrixWrapper(std::vector<std::vector<double>> &matrixTemplate, const int order, const int indexOfMatrix)
{
	FillTheMatrix(matrixTemplate, order);

	switch (indexOfMatrix)
	{
	case A:
		std::cout << "A matrix:" << std::endl;
		break;
	case B:
		std::cout << "B matrix:" << std::endl;
		break;
	case C:
		std::cout << "C matrix:" << std::endl;
		break;
	case D:
		std::cout << "D matrix:" << std::endl;
		break;
	default:
		std::cout << "Error";
		break;
	}

	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			std::cout << matrixTemplate[i][j] << "	";
			if (j + 1 == order)
			{
				std::cout << std::endl;
			}
		}
	}
}

void PrintTheMatrix(std::vector<std::vector<double>> &matrix, const int order)
{
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			std::cout << matrix[i][j] << "	";
			if (j + 1 == order)
			{
				std::cout << std::endl;
			}
		}
	}
}

int main()
{
	srand(time(NULL));

	std::cout << "Enter the matrix order: " << std::endl;
	int order;
	std::cin >> order;
	std::cout << std::endl;

	std::vector<std::vector<double>> matrixA(order, std::vector<double>(order, 0));
	TheMatrixWrapper(matrixA, order, 0);
	std::cout << std::endl;

	std::vector<std::vector<double>> matrixB(order, std::vector<double>(order, 0));
	TheMatrixWrapper(matrixB, order, 1);
	std::cout << std::endl;

	std::vector<std::vector<double>> matrixC(order, std::vector<double>(order, 0));
	TheMatrixWrapper(matrixC, order, 2);
	std::cout << std::endl;

	std::cout << std::endl
			  << "Sum of B and C matrices: "
			  << std::endl;
	SumTheMatrices(matrixB, matrixC, order);
	PrintTheMatrix(matrixC, order);

	std::cout << std::endl
			  << "Result of А * ( В + С )."
			  << std::endl;
	std::vector<std::vector<double>> matrixD(order, std::vector<double>(order, 0));
	MultiplyTheMatrices(matrixA, matrixC, matrixD, order);
	PrintTheMatrix(matrixD, order);

	return 0;
}