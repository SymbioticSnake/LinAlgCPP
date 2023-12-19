#include "Matrix.cpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout("output.txt");

    Matrix I2;
    I2.cin_matrix();
    
    Matrix M;
    M = I2 + I2;
}