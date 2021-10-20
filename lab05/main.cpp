#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix matrix(10, 5);
//    matrix.printMatrix();
//    matrix.fillMatrix(20);
//    matrix.printMatrix();
//    matrix.randomMatrix(1, 10);
//    matrix.printMatrix();
//    cout << matrix[6][3];

    matrix.fillMatrix(10);
    Matrix matrix2(5, 10);
    matrix2.fillMatrix(20);
//    try {
//        Matrix matrix3 = matrix + matrix2;
//        matrix3.printMatrix();
//    } catch (out_of_range& e) {
//        cout << e.what() << endl;
//    }
    try {
        Matrix matrix3 = matrix * matrix2;
//        matrix3.printMatrix();
    cout << matrix3 << endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }
    return 0;
}

