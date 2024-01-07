#include <cmath>
#include <iostream>
#include "ComplexNumber.h"
using namespace std;

ComplexNumber ComplexNumber::power(double n) const {
    ComplexNumber powNum(pow(modulus(), n)*cos(n * argument()),
                         pow(modulus(), n)*sin(n * argument()));
    return powNum;
}

void ComplexNumber::root(double n, ComplexNumber roots[MAX_ROOTS]) const {
    for (int i = 0; i < MAX_ROOTS; i++)
        roots[i] = ComplexNumber();

    for (int k = 0; k < n; k++) {
        roots[k] = ComplexNumber(pow(modulus(), 1/n) * cos((argument() + 2*k*M_PI) / n),
                                 pow(modulus(), 1/n) * sin((argument() + 2*k*M_PI) / n));
    }
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

ComplexNumber roots[MAX_ROOTS];

ComplexNumber pow(ComplexNumber const &c, double n) {
    if (n == 0)
        return {1, 0};
    else if (n > 0 && n < 1)
         c.root(n, roots);
    else return c.power(n);
}

double abs(ComplexNumber const &c) { return c.modulus(); }
double Re(ComplexNumber const &c) { return c.getReal(); }
double Im(ComplexNumber const &c) { return c.getImaginary(); }