#include "ComplexNumber.h"

void ComplexNumber::root(double n, ComplexNumber roots[MAX_ROOTS]) const {
    for (int i = 0; i < MAX_ROOTS; i++)
        roots[i] = ComplexNumber();

    for (int k = 0; k < n; k++) {
        roots[k] = ComplexNumber(pow(modulus(), 1/n) * cos((argument() + 2*k*M_PI) / n),
                                 pow(modulus(), 1/n) * sin((argument() + 2*k*M_PI) / n));
    }
}

ComplexNumber ComplexNumber::operator+(ComplexNumber const &other) const {
    ComplexNumber sum(real + other.real, imaginary + other.imaginary);
    return sum;
}

ComplexNumber ComplexNumber::operator-(ComplexNumber const &other) const {
    ComplexNumber difference(real - other.real, imaginary - other.imaginary);
    return difference;
}

ComplexNumber ComplexNumber::operator*(double const &num) const {
    ComplexNumber product(real * num, imaginary * num);
    return product;
}

ComplexNumber ComplexNumber::operator*(ComplexNumber const &other) const {
    ComplexNumber product(real * other.real - imaginary * other.imaginary,
                          real * other.imaginary + other.real * imaginary);
    return product;
}

ComplexNumber ComplexNumber::operator/(double const &num) const {
    ComplexNumber quotient(real / num, imaginary / num);
    return quotient;
}

ComplexNumber ComplexNumber::operator/(ComplexNumber const &other) const {
    ComplexNumber quotient = (*this) * other.conjugate() /
                             (pow(other.real,2) + pow(other.imaginary, 2));
    cout << quotient.real << " " << quotient.imaginary << endl;
    return quotient;
}

ostream& operator<<(ostream &Out, ComplexNumber const &num) {
    if (num.real == 0 && num.imaginary != 0)
        Out << "(" << num.imaginary << ") j";
    else if (num.imaginary == 0 && num.real != 0)
        Out << "(" << num.real << ")";
    else
        Out << "(" << num.real << ") + (" << num.imaginary << ") j";
    return Out;
}

istream& operator>>(istream &In, ComplexNumber &num) {
    In >> num.real >> num.imaginary;
    return In;
}

ComplexNumber pow(ComplexNumber const &c, double n) {
    if (n == 0)
        return ComplexNumber(1, 0);
    else if (n > 0 && n < 1)
        c.root(n, roots);
    else return c.power(n);
}