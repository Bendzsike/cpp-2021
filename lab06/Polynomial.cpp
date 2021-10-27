#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double coefficients[]) {
    this->capacity = degree + 1;
    this->coefficients = new double[capacity];
    for (int i = 0; i < capacity; ++i) {
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity = that.capacity;
    this->coefficients = new double[this->capacity];
    for (int i = 0; i < this->capacity; ++i) {
        this->coefficients[i] = that.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial &&that) {
    this->capacity = that.capacity;
    this->coefficients = that.coefficients;
    that.capacity = 0;
    that.coefficients = nullptr;
}

Polynomial::~Polynomial() {
    capacity = 0;
    delete [] coefficients;
}

double Polynomial::evaluate(double x) const {
    double P = this->coefficients[0];
    for (int i = 0; i < this->capacity; ++i) {
        P = P * x + this->coefficients[i];
    }

    return P;
}

Polynomial Polynomial::derivative() const {
    double result[this->capacity - 1];
    for (int i = 0; i < this->capacity - 1; ++i) {
        result[i] = this->coefficients[i] * (this->capacity - 1 - i);
    }

    return Polynomial(this->capacity - 2, result);
}

double Polynomial::operator[](int index) const {
    return this->coefficients[index];
}

Polynomial operator -(const Polynomial &a) {
    Polynomial result(a);
    for (int i = 0; i < result.capacity; ++i) {
        result.coefficients[i] *= -1;
    }

    return result;
}

Polynomial operator +(const Polynomial &a, const Polynomial &b) {
    if(a.capacity < b.capacity) {
        return b + a;
    }
    Polynomial result(a);

    int difference = a.capacity - b.capacity;

    for (int i = 0; i < b.capacity; ++i) {
        result.coefficients[i + difference] += b.coefficients[i];
    }

    return result;
}

Polynomial operator -(const Polynomial &a, const Polynomial &b) {
    return a + (-b);
}

Polynomial operator *(const Polynomial &a, const Polynomial &b) {
    double result[a.capacity + b.capacity - 1];

    for (int i = 0; i < a.capacity; ++i) {
        for (int j = 0; j < b.capacity; ++j) {
            result[i + j] = a.coefficients[i] * b.coefficients[j];
        }
    }

    return Polynomial(a.capacity + b.capacity -2, result);
}

ostream & operator <<(ostream& out, const Polynomial& what) {
    for (int i = 0; i < what.capacity; ++i) {
        out << what.coefficients[i] << " ";
    }
    return out;
}