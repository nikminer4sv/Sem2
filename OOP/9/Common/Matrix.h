#pragma once

#include "Vector.h"

namespace nikminer4sv {

using namespace std;

template< typename T>
    class Matrix {

private:
    string _name;
    Vector<Vector<T>> _matrix;
    size_t _rows;
    size_t _cols;

public:
    static size_t counter;

private:
    void SetName() { 
        _name = "Matrix_" + to_string(counter++);
    }

    void IndexValidation(size_t index) const {
        if (index >= _rows)
            throw invalid_argument("Invalid index!");
    }

public:
    Matrix() { SetName(); }

    Matrix(const size_t rows, const size_t cols) {
        SetName();

        //_matrix = Vector<Vector<T>>(rows, Vector<T>(cols));
        _matrix = Vector<Vector<T>>(rows);
        for (size_t i = 0; i < rows; i++)
            _matrix[i] = Vector<T>(cols);

        _rows = rows;
        _cols = cols;
    }

    [[nodiscard]] size_t GetRows() const { return _rows; }

    [[nodiscard]] size_t GetCols() const { return _cols; }

    [[nodiscard]] string GetName() const { return _name; }

    void SetRows(const size_t rows) {
        _matrix.SetSize(rows);
        if (rows > _rows)
            for (size_t i = _rows; i < rows; i++)
                _matrix[i] = vector<T>(_cols);
        _rows = rows;
    }

    void SetCols(const size_t& cols) {
        for (auto col : _matrix)
            col.SetSize(cols);

        _cols = cols;
    }

    Vector<T>& operator[](const size_t row) {
        IndexValidation(row);
        return _matrix[row];
    }

    const Vector<T> operator[] (const size_t row) const {
        IndexValidation(row);
        return _matrix[row];
    }

    [[nodiscard]] Matrix operator+ (const Matrix& matrix) const {
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

    void Debug() {
        cout << (*this)[0][1];
    }

};

template<typename T>
size_t Matrix<T>::counter = 1;
}