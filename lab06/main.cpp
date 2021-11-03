#include "Polynomial.h"
#include <iostream>

using namespace std;

int main() {
    double c1[] {1, 2, 1};

    Polynomial p1(2, c1);

    cout << "P1: " << p1 << endl;

    cout << "P1(0) = " << p1.evaluate(0) << endl;

    cout << "P1(1) = " << p1.evaluate(1) << endl;

    cout << "Index: ";
    for (int i = 0; i < p1.degree() + 1; ++i) {
        cout << p1[i] << " ";
    }
    cout << endl;

    cout << "Negating P1: " << -p1 << endl;

    Polynomial dp1 = p1.derivative();

    cout << "P1 derivative: " << dp1 << endl;

    cout << "P1 derivative + P1 = " << dp1 + p1 << endl;

    cout << "P1 - P1 derivative = " << p1 - dp1 << endl;

    cout << "P1 * P1 derivative = " << p1 * dp1 << endl;

    return 0;
}
