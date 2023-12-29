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
    ComplexNumber() {
        real = 0;
        imaginary = 0;
    }

    ComplexNumber(double Re, double Im) {
        real = Re;
        imaginary = Im;
    }

    ComplexNumber(ComplexNumber const &other) {
        real = other.real;
        imaginary = other.imaginary;
    }

    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    double argument() const {
        return atan2(imaginary, real);
    }

    double modulus() const {
        return sqrt(pow(real, 2) + pow(imaginary, 2));
    }

    ComplexNumber conjugate() const {
        ComplexNumber conVal(real, -imaginary);
        return conVal;
    }

    bool operator==(ComplexNumber const &other) const {
        return (real == other.real && imaginary == other.imaginary);
    }

    ComplexNumber power(double n) const {
        ComplexNumber powNum(pow(modulus(), n)*cos(n * argument()),
                             pow(modulus(), n)*sin(n * argument()));
        return powNum;
    }

    void root(double n, ComplexNumber roots[MAX_ROOTS]) const {
        for (int i = 0; i < MAX_ROOTS; i++)
            roots[i] = ComplexNumber();

        for (int k = 0; k < n; k++) {
            roots[k] = ComplexNumber(pow(modulus(), 1/n) * cos((argument() + 2*k*M_PI) / n),
                                     pow(modulus(), 1/n) * sin((argument() + 2*k*M_PI) / n));
        }
    }

    ComplexNumber operator+(ComplexNumber const &other) const {
        ComplexNumber sum(real + other.real, imaginary + other.imaginary);
        return sum;
    }

    ComplexNumber operator-(ComplexNumber const &other) const {
        ComplexNumber difference(real - other.real, imaginary - other.imaginary);
        return difference;
    }

    ComplexNumber operator*(double const &num) const {
        ComplexNumber product(real * num, imaginary * num);
        return product;
    }

    ComplexNumber operator*(ComplexNumber const &other) const {
        ComplexNumber product(real * other.real - imaginary * other.imaginary,
                              real * other.imaginary + other.real * imaginary);
        return product;
    }

    ComplexNumber operator/(double const &num) const {
        ComplexNumber quotient(real / num, imaginary / num);
        return quotient;
    }

    ComplexNumber operator/(ComplexNumber const &other) const {
        ComplexNumber quotient = (*this) * other.conjugate() /
                                 (pow(other.real,2) + pow(other.imaginary, 2));
        cout << quotient.real << " " << quotient.imaginary << endl;
        return quotient;
    }

    friend ostream& operator<<(ostream &Out, ComplexNumber const &num) {
        if (num.real == 0 && num.imaginary != 0)
            Out << "(" << num.imaginary << ") j";
        else if (num.imaginary == 0 && num.real != 0)
            Out << "(" << num.real << ")";
        else
            Out << "(" << num.real << ") + (" << num.imaginary << ") j";
        return Out;
    }

    friend istream& operator>>(istream &In, ComplexNumber &num) {
        In >> num.real >> num.imaginary;
        return In;
    }

};

ComplexNumber roots[MAX_ROOTS];

ComplexNumber pow(ComplexNumber const &c, double n) {
    if (n == 0)
        return ComplexNumber(1, 0);
    else if (n > 0 && n < 1)
         c.root(n, roots);
    else return c.power(n);
}

double abs(ComplexNumber const &c) {
    return c.modulus();
}

double Re(ComplexNumber const &c) {
    return c.getReal();
}

double Im(ComplexNumber const &c) {
    return c.getImaginary();
}