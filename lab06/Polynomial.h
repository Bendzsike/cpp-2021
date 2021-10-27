#ifndef LAB6_POLYNOMIAL_H
#define LAB6_POLYNOMIAL_H

using namespace std;

#include <iostream>

class Polynomial {
    double* coefficients;
    int capacity;
public:
    Polynomial(int degree, const double coefficients[]);
    Polynomial(const Polynomial &that);
    Polynomial(Polynomial &&that);
    ~Polynomial();
// Polinom fokszáma
    int degree() const {return capacity - 1;};
// Polinom értéke a megadott pontban
    double evaluate(double x) const;
// Polinom deriváltja
    Polynomial derivative() const;
    double operator[](int index) const;
    friend Polynomial operator -(const Polynomial &a);
    friend Polynomial operator +(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator -(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator *(const Polynomial &a, const Polynomial &b);
    friend ostream & operator <<(ostream& out, const Polynomial& what);
/* copy assignment - mély másolat letiltása értékadásra nézve */
    Polynomial& operator=(const Polynomial&) = delete;
/* move assignment - sekély másolat letiltása értékadásra nézve */
    Polynomial& operator=(Polynomial&&) = delete;
};

#endif //LAB6_POLYNOMIAL_H
