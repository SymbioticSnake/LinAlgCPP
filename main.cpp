#include "Matrix.cpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    Matrix matrix;
    double identity[2][2] = {1, 0, 0, 1};

    matrix.set_row(identity[0], 0);
    matrix.set_row(identity[1], 1);

    matrix.out();
}