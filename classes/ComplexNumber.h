#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAX_ROOTS = 10;

#ifndef LINALGCPP_COMPLEXNUMBER_H
#define LINALGCPP_COMPLEXNUMBER_H

class ComplexNumber {
private:
    double real, imaginary;

public:
    ComplexNumber() { real = 0; imaginary = 0; }
    ComplexNumber(double Re, double Im) { real = Re; imaginary = Im; }
    ComplexNumber(ComplexNumber const &other) { real = other.real; imaginary = other.imaginary; }

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
    double argument() const { return atan2(imaginary, real); }
    double modulus() const { return sqrt(pow(real, 2) + pow(imaginary, 2)); }

    ComplexNumber conjugate() const { return ComplexNumber(real, -imaginary); }

    bool operator==(ComplexNumber const &other) const {
        return (real == other.real && imaginary == other.imaginary);
    }

    ComplexNumber power(double n) const {
        return ComplexNumber(pow(modulus(), n)*cos(n * argument()),
                             pow(modulus(), n)*sin(n * argument()));
    }

    void root(double n, ComplexNumber roots[MAX_ROOTS]) const;
    ComplexNumber operator+(ComplexNumber const &other) const;
    ComplexNumber operator-(ComplexNumber const &other) const;
    ComplexNumber operator*(double const &num) const;
    ComplexNumber operator*(ComplexNumber const &other) const;
    ComplexNumber operator/(double const &num) const;
    ComplexNumber operator/(ComplexNumber const &other) const;
    friend ostream& operator<<(ostream &Out, ComplexNumber const &num);
    friend istream& operator>>(istream &In, ComplexNumber &num);

};

ComplexNumber roots[MAX_ROOTS];

ComplexNumber pow(ComplexNumber const &c, double n);
double abs(ComplexNumber const &c) { return c.modulus(); }
double Re(ComplexNumber const &c) { return c.getReal(); }
double Im(ComplexNumber const &c) { return c.getImaginary(); }

#endif //LINALGCPP_COMPLEXNUMBER_H
