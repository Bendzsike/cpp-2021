#ifndef LAB5_MATRIX_H
#define LAB5_MATRIX_H

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

class Matrix {
    double **elements;
    int rows;
    int columns;
public:
    Matrix(int rows = 10, int columns = 10);
    Matrix(const Matrix& matrix);
    Matrix(Matrix&& matrix);
    ~Matrix();
    void fillMatrix(double value);
    void randomMatrix(int a, int b);
    void printMatrix(ostream& os = cout) const;
    bool isSquare() const {return this->rows == this->columns;};
    int getRows() const {return this->rows;}
    int getColumns() const {return this->columns;}
    friend Matrix operator+(const Matrix& x, const Matrix& y);
    friend Matrix operator*(const Matrix& x, const Matrix& y);
    friend istream& operator>>(istream& is, Matrix& matrix);
    friend ostream& operator<<(ostream& os, const Matrix& matrix);
    double* operator[](int index);
    double* operator[](int index) const;
    Matrix& operator=(const Matrix& matrix);
    Matrix& operator=(Matrix&& matrix);
};


#endif //LAB5_MATRIX_H
