#include "Matrix.h"

Matrix::Matrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    elements = new double*[rows];
    for(int i = 0; i < rows; ++i) {
        elements[i] = new double[columns];
    }
    fillMatrix(0);
}

Matrix::Matrix(const Matrix &matrix) {
    this->rows = matrix.rows;
    this->columns = matrix.columns;
    elements = new double*[rows];
    for(int i = 0; i < rows; ++i) {
        elements[i] = new double[columns];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            this->elements[i][j] = matrix[i][j];
        }
    }
}

Matrix::Matrix(Matrix&& matrix) {
    this->rows = matrix.rows;
    this->columns = matrix.columns;
    this->elements = matrix.elements;
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete [] elements[i];
    }
    delete [] elements;
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < rows; ++i) {
        fill(elements[i], elements[i] + columns, value);
    }
}

void Matrix::randomMatrix(int a, int b) {
    srand(time(nullptr));
    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            elements[i][j] = rand() % (b + 1) + a;
        }
    }
}

void Matrix::printMatrix(ostream& os) const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            os << right << setw(5) << elements[i][j];
        }
        os << endl;
    }
}

Matrix operator+(const Matrix& x, const Matrix& y) {
    if(x.getRows() != y.getRows() || x.getColumns() != y.getColumns()) {
        throw out_of_range("Matrix sizes don't match!");
    }
    Matrix matrix(x);
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getColumns(); ++j) {
            matrix[i][j] += y[i][j];
        }
    }
    return matrix;
}
Matrix operator*(const Matrix& x, const Matrix& y) {
    if(x.columns != y.rows) {
        throw out_of_range("Can't multiply those matrices!");
    }
    Matrix matrix(x.rows, y.columns);
    for (int i = 0; i < x.rows; ++i) {
        for (int j = 0; j < y.columns; ++j) {
            double sum = 0;
            for (int k = 0; k < y.rows; ++k) {
                sum += (x[i][k] * y[k][j]);
            }
            matrix[i][j] = sum;
        }
    }
    return matrix;
}
istream& operator>>(istream& is, Matrix& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            is >> matrix[i][j];
        }
    }
}
ostream& operator<<(ostream& os, const Matrix& matrix) {
    matrix.printMatrix(os);
    return os;
}

double *Matrix::operator[](int index) {
    return elements[index];
}

double *Matrix::operator[](int index) const {
    return elements[index];
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    if(this->rows != matrix.rows || this->columns != matrix.columns) {
        throw out_of_range("Matrix sizes don't match!");
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            this->elements[i][j] = matrix[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&matrix) {
    if(this->rows != matrix.rows || this->columns != matrix.columns) {
        throw out_of_range("Matrix sizes don't match!");
    }
    return;
}
