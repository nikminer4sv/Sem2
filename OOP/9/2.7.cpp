#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Matrix {
private:
    string _name;
public:
    vector<vector<int>> _matrix;
    size_t _rows;
    size_t _cols;

public:
    static size_t counter;

private:
    void SetName() { 
        _name = "Matrix_" + to_string(counter); 
        counter += 1;
    }

    void IndexValidation(size_t index) const {
        if (index >= _rows)
            throw invalid_argument("Invalid index!");
    }

public:
    Matrix() { SetName(); }

    Matrix(const size_t& rows, const size_t& cols) {

        SetName();

        _matrix = vector<vector<int>>(rows, vector<int>(cols, 0));

        _rows = rows;
        _cols = cols;

    }

    size_t GetRows() const { return _rows; }

    size_t GetCols() const { return _cols; }

    string GetName() const { return _name; }

    void SetRows(const size_t& rows) {
        _matrix.resize(rows);
        if (rows > _rows)
            for (size_t i = _rows; i < rows; i++)
                _matrix[i] = vector<int>(_cols, 0);
        _rows = rows;
    }

    void SetCols(const size_t& cols) {
        for (auto col : _matrix)
            col.resize(cols);

        _cols = cols;
    }

    vector<int>& operator[](const size_t& row) {
        IndexValidation(row);
        return _matrix[row];
    }

    const vector<int>& operator[] (const size_t& row) const {
        IndexValidation(row);
        return _matrix[row];
    }

    Matrix operator+ (const Matrix& matrix) {
        Matrix newMatrix(_rows, _cols);
        for (size_t i = 0; i < _rows; i++) 
            for (size_t j = 0; j < _cols; j++)
                newMatrix[i][j] = (*this)[i][j] + matrix[i][j];

        return newMatrix;
    }

    Matrix& operator= (const Matrix& matrix) {
        for (size_t i = 0; i < _rows; i++) 
            for (size_t j = 0; j < _cols; j++)
                (*this)[i][j] = matrix[i][j];

        return *this;
    }

    friend ostream& operator<< (ostream &os, const Matrix& matrix){
        os << matrix.GetName() << endl;
        for (size_t i = 0; i < matrix.GetRows(); i++) {
            for (size_t j = 0; j < matrix.GetCols(); j++)
                os << matrix[i][j] << " ";

            os << endl;
        }

        return os;
    }
    
    void AscendingFill() {
        size_t counter = 0;
        for (size_t i = 0; i < _rows; i++) {
            for (size_t j = 0; j < _cols; j++) {
                _matrix[i][j] = counter;
                ++counter;
            }
        }
    }

    Matrix Pow(const int& power) {
        if (_cols != _rows)
            throw runtime_error("Rows and cols must be equals!");

        Matrix copy = *this;
        Matrix result(_rows, _cols);
        for (int f = 0; f < power - 1; f++) {
            for (int i = 0; i < _rows; i++) {
                for (int j = 0; j < _cols; j++) {
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

    void Task() {
        *this = *this + this->Pow(2) + this->Pow(4) + this->Pow(8);
    }

};
size_t Matrix::counter = 1;

int main() {
    Matrix m(3, 3);
    m.AscendingFill();
    cout << m;
    m.Task();
    cout << m;
}
