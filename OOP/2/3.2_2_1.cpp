#include <iostream>
#include <vector>

enum Matrices
{
	A = 0,
	B = 1,
	C = 2,
	D = 3
};

void SumTheMatrices(std::vector<double> &matrix, std::vector<double> &newMatrix, const int order)
{
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			newMatrix[i * order + j] += matrix[i * order + j];
		}
	}
}

void MultiplyTheMatrices(std::vector<double> &matrix, std::vector<double> &matrix2, std::vector<double> &matrix3, const int order)
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

void FillTheMatrix(std::vector<double> &matrix, const int order)
{
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			matrix[i * order + j] = rand() % 11 + rand() % 10 * 0.1;
		}
	}
}

void TheMatrixWrapper(std::vector<double> &matrixTemplate, const int order, const int indexOfMatrix)
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
			std::cout << matrixTemplate[i * order + j] << "	";
			if (j + 1 == order)
			{
				std::cout << std::endl;
			}
		}
	}
}

void PrintTheMatrix(std::vector<double> &matrix, const int order)
{
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			std::cout << matrix[i * order + j] << "	";
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

	std::cout << "Enter the order of the matrix: " << std::endl;
	int order;
	std::cin >> order;

	std::vector<double> matrixA(order * order);
	TheMatrixWrapper(matrixA, order, 0);
	std::cout << std::endl;

	std::vector<double> matrixB(order * order);
	TheMatrixWrapper(matrixB, order, 1);
	std::cout << std::endl;

	std::vector<double> matrixC(order * order);
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
	std::vector<double> matrixD(order * order);
	MultiplyTheMatrices(matrixA, matrixC, matrixD, order);
	PrintTheMatrix(matrixD, order);

	return 0;
}