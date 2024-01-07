#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Matrix.h"

Matrix::Matrix(Matrix const &mat) {
    m = mat.m;
    n = mat.n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; n++)
            matrix[i][j] = mat.matrix[i][j];
}

std::ostream& operator<<(std::ostream &Out, Matrix const &matrix1) {
    Out << "[";
    for (int row = 0; row < matrix1.m; row++) {
        for (int col = 0; col < matrix1.n; col++) {
            Out << matrix1.matrix[row][col];
            if (col != matrix1.n - 1)
                Out << " ";
        }

        if (row != matrix1.m - 1)
            Out << "; ";

    }
    Out << "]";
    return Out;
}

bool Matrix::fin_matrix(std::ifstream &In) {
    bool success = true;
    int i = 0;
    while (success && i < m) {
        for (int j = 0; j < n; j++) {
            success = (bool) (In >> matrix[i][j]);
        }
        i++;
    }
    return success;
}

bool Matrix::cin_matrix() {
    bool success = true;
    int i = 0;
    while (success && i < m) {
        for (int j = 0; j < n; j++) {
            success = (bool) (std::cin >> matrix[i][j]);
        }
        i++;
    }
    return success;
}

void Matrix::set_row(double const row[], int rowNum) {
    for (int col = 0; col < n; col++) {
        matrix[rowNum-1][col] = row[col];
    }
}

void Matrix::set_col(double const column[], int colNum) {
    for (int row = 0; row < m; row++) {
        matrix[row][colNum+1] = column[row];
    }
}

void Matrix::swap_row(int num_1, int num_2) {
    double temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = matrix[num_1][i];
        matrix[num_1][i] = matrix[num_2][i];
        matrix[num_2][i] = temp[i];
    }
}

Matrix& Matrix::operator=(Matrix const& other) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            matrix[i][j] = other.matrix[i][j];
    }
    return *this;
}

Matrix Matrix::operator+(Matrix const& other) const {
    if (other.m != m || other.m != n) {
        std::cout << "Unable to add matrices" << std::endl;
        return (*this);
    }

    Matrix newMatrix(m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            newMatrix.set_entry(other.get_entry(i, j) + matrix[i][j], i, j);
        }
    }
    return newMatrix;
}

Matrix Matrix::operator-(Matrix const& other) const {
    if (other.m != m || other.n != n) {
        std::cout << "Unable to subtract matrices" << std::endl;
        return (*this);
    }

    Matrix newMatrix(m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            newMatrix.set_entry(matrix[i][j] - other.get_entry(i, j), i, j);
        }
    }
    return newMatrix;
}

Matrix Matrix::operator*(Matrix const& other) const {
    if (n != other.get_num_rows()) {
        std::cout << "Unable to multiply matrices" << std::endl;
        return (*this);
    }
    Matrix newMatrix(m, other.n);
    for (int col = 0; col < other.n; col++) {
        for (int row = 0; row < m; row++) {
            for (int i = 0; i < n; i++) {
                newMatrix.matrix[row][col] += matrix[row][i] * other.matrix[i][col];
            }
        }
    }
    return newMatrix;
}

Matrix Matrix::operator*(double constant) {
    Matrix newMatrix(m, n);
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; m++)
            newMatrix.matrix[row][col] = constant * matrix[row][col];
    }
    return newMatrix;
}

Matrix Matrix::transpose() const {
    Matrix newMatrix(n, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            newMatrix.matrix[j][i] = matrix[i][j];
        }
    }
    return newMatrix;
}

Vector Matrix::operator*(Vector const& vector1) const {
    if (vector1.get_dimension() != n) {
        std::cout << "Cannot multiply";
        return vector1;
    }

    Vector newVector(m);
    for (int row = 0; row < m; row++) {
        double entry = 0;
        for (int i = 0; i < n; i++)
            entry += matrix[row][i] * vector1.get_entry(i);
        newVector.set_entry(entry, row);
    }
    return newVector;
}