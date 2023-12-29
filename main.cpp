#include "classes/Matrix.cpp"
#include "classes/ComplexNumber.cpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ComplexNumber c1(-16, 0);
    c1.root(3, roots);

    int power = 0;
    cout << "Enter power to calculate root: ";
    cin >> power;
    c1.root(power, roots);

    for (int i = 0; i < power; i++) {
        cout << roots[i] << endl;
    }
    return EXIT_SUCCESS;
}