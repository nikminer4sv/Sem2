#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Matrix
{
private:
	string _name;

public:
	vector<vector<double>> _matrix;
	size_t _rows;
	size_t _cols;

public:
	static size_t counter;

private:
	void SetName()
	{
		_name = "Matrix_" + to_string(counter);
		counter += 1;
	}

	void IndexValidation(size_t index) const
	{
		if (index >= _rows)
			throw invalid_argument("Invalid index!");
	}

public:
	Matrix() { SetName(); }

	Matrix(const size_t &rows, const size_t &cols)
	{

		SetName();

		_matrix = vector<vector<double>>(rows, vector<double>(cols, 0));

		_rows = rows;
		_cols = cols;
	}

	size_t GetRows() const { return _rows; }

	size_t GetCols() const { return _cols; }

	string GetName() const { return _name; }

	void SetRows(const size_t &rows)
	{
		_matrix.resize(rows);
		if (rows > _rows)
			for (size_t i = _rows; i < rows; i++)
				_matrix[i] = vector<double>(_cols, 0);
		_rows = rows;
	}

	void SetCols(const size_t &cols)
	{
		for (auto col : _matrix)
			col.resize(cols);

		_cols = cols;
	}

	vector<double> &operator[](const size_t &row)
	{
		IndexValidation(row);
		return _matrix[row];
	}

	const vector<double> &operator[](const size_t &row) const
	{
		IndexValidation(row);
		return _matrix[row];
	}

	Matrix operator+(const Matrix &matrix)
	{
		Matrix newMatrix(_rows, _cols);
		for (size_t i = 0; i < _rows; i++)
			for (size_t j = 0; j < _cols; j++)
				newMatrix[i][j] = (*this)[i][j] + matrix[i][j];

		return newMatrix;
	}

	Matrix operator*(const Matrix &matrix)
	{
		Matrix newMatrix(_rows, _cols);
		for (size_t i = 0; i < _rows; i++)
		{
			for (size_t j = 0; j < _cols; j++)
			{
				newMatrix[i][j] = 0;
				for (int k = 0; k < _cols; k++)
					newMatrix[i][j] += (*this)[i][k] * matrix[k][j];
			}
		}
		return newMatrix;
	}

	Matrix &operator=(const Matrix &matrix)
	{
		for (size_t i = 0; i < _rows; i++)
			for (size_t j = 0; j < _cols; j++)
				(*this)[i][j] = matrix[i][j];

		return *this;
	}

	friend ostream &operator<<(ostream &os, const Matrix &matrix)
	{
		os << matrix.GetName() << endl;
		for (size_t i = 0; i < matrix.GetRows(); i++)
		{
			for (size_t j = 0; j < matrix.GetCols(); j++)
				os << matrix[i][j] << " ";

			os << endl;
		}

		return os;
	}

	void AscendingFill()
	{
		size_t counter = 0;
		for (size_t i = 0; i < _rows; i++)
		{
			for (size_t j = 0; j < _cols; j++)
			{
				_matrix[i][j] = counter;
				++counter;
			}
		}
	}

	void RandomFill()
	{
		for (size_t i = 0; i < _rows; i++)
		{
			for (size_t j = 0; j < _cols; j++)
			{
				_matrix[i][j] = rand() % 10 + rand() % 10 * 0.1;
			}
		}
	}

	Matrix Pow(const int &power)
	{
		if (_cols != _rows)
			throw runtime_error("Rows and cols must be equals!");

		Matrix copy = *this;
		Matrix result(_rows, _cols);
		for (int f = 0; f < power - 1; f++)
		{
			for (int i = 0; i < _rows; i++)
			{
				for (int j = 0; j < _cols; j++)
				{
					int ElementValue = 0;
					for (int t = 0; t < _rows; t++)
						ElementValue += _matrix[i][t] * copy[t][j];
					result[i][j] = ElementValue;
				}
			}
			copy = result;
		}

		return result;
	}
};
size_t Matrix::counter = 1;

Matrix Task(Matrix A, Matrix B, Matrix C)
{
	return A * (B + C);
}

int main()
{
	srand(time(NULL));

	Matrix A(3, 3);
	A.RandomFill();
	cout << "A matrix: " << endl
		 << A << endl;

	Matrix B(3, 3);
	B.RandomFill();
	cout << "B matrix: " << endl
		 << B << endl;

	Matrix C(3, 3);
	C.RandomFill();
	cout << "C matrix: " << endl
		 << C << endl
		 << endl;

	cout << "A * ( B + C )" << endl
		 << Task(A, B, C);

	return 0;
}