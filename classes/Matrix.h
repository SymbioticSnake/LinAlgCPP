//
// Created by danan on 06/01/2024.
//

#ifndef LINALGCPP_MATRIX_H
#define LINALGCPP_MATRIX_H

#include "Vector.h"

class Matrix {
private:
    int m, n;
    double matrix[MAX_SIZE][MAX_SIZE] = {0};

public:
    /* Constructors */
    Matrix() { m = n = 2; }
    Matrix(int rows, int columns) { m = rows; n = columns; }
    Matrix(Matrix const &mat);

    /* Input/Output */
    friend std::ostream& operator<<(std::ostream &Out, Matrix const &matrix1);
    bool fin_matrix(std::ifstream &In);
    bool cin_matrix();
    Matrix& operator=(Matrix const& other);

    [[nodiscard]] double get_num_rows() const { return m; }
    [[nodiscard]] double get_num_cols() const { return n; }
    [[nodiscard]] double get_entry(int row, int col) const { return matrix[row][col]; }


    void set_row(double const row[], int rowNum);
    void set_col(double const column[], int colNum);
    void set_entry(double entry, int row, int col) { matrix[row][col] = entry; }

    void swap_row(int num_1, int num_2);
    void determinant();

    /* Operators */
    Matrix operator+(Matrix const& other) const;
    Matrix operator-(Matrix const& other) const;
    Matrix operator*(Matrix const& other) const;
    Matrix operator*(double constant);
    [[nodiscard]] Matrix transpose() const;
    Vector operator*(Vector const& vector1) const;
};

#endif //LINALGCPP_MATRIX_H
