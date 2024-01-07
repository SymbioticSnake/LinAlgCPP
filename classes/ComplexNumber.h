//
// Created by danan on 06/01/2024.
//

#ifndef LINALGCPP_COMPLEXNUMBER_H
#define LINALGCPP_COMPLEXNUMBER_H

#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAX_ROOTS = 10;

class ComplexNumber {
private:
    double real, imaginary;

public:
    ComplexNumber() { real = 0; imaginary = 0; }

    ComplexNumber(double Re, double Im) { real = Re; imaginary = Im; }

    ComplexNumber(ComplexNumber const &other) { real = other.real; imaginary = other.imaginary; }

    [[nodiscard]] double getReal() const { return real; }
    [[nodiscard]] double getImaginary() const { return imaginary; }
    [[nodiscard]] double argument() const { return atan2(imaginary, real); }
    [[nodiscard]] double modulus() const { return sqrt(pow(real, 2) + pow(imaginary, 2)); }
    [[nodiscard]] ComplexNumber conjugate() const { return {real, -imaginary}; }

    bool operator==(ComplexNumber const &other) const {
        return (real == other.real && imaginary == other.imaginary);
    }

    [[nodiscard]] ComplexNumber power(double n) const;
    void root(double n, ComplexNumber roots[MAX_ROOTS]) const;

    ComplexNumber operator+(ComplexNumber const &other) const {
        return {real + other.real, imaginary + other.imaginary};
    }
    ComplexNumber operator-(ComplexNumber const &other) const {
        return {real - other.real, imaginary - other.imaginary};
    }
    ComplexNumber operator*(double const &num) const {
        return {real * num, imaginary * num};
    }
    ComplexNumber operator*(ComplexNumber const &other) const {
        return {real * other.real - imaginary * other.imaginary,
                real * other.imaginary + other.real * imaginary};
    }
    ComplexNumber operator/(double const &num) const {
        return {real / num, imaginary / num};
    }
    ComplexNumber operator/(ComplexNumber const &other) const {
        return ((*this) * other.conjugate() / (pow(other.real,2) + pow(other.imaginary, 2)));
    }

    friend ostream& operator<<(ostream &Out, ComplexNumber const &num);
    friend istream& operator>>(istream &In, ComplexNumber &num);

};

#endif //LINALGCPP_COMPLEXNUMBER_H
