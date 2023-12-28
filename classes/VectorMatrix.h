/* Contains definition for Matrix class. To declare a vector,
 * it is recommended to declare a column vector with 1 column
 * and multiple rows.*/

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 10;
const int VEC_EQ_PARAMS = 3;

#ifndef LINALGCPP_VECTORMATRICES_H
#define LINALGCPP_VECTORMATRICES_H

class Vector {
protected:
    int m;
    double matrix[MAX_SIZE][1] = {0};
public:
    Vector() { m = 2; }
    Vector(int rows) { m = rows; }

    /* Input/Output */
    friend ostream& operator<<(ostream &Out, Vector const &vector1);
    bool fin_vector(ifstream &In);
    bool cin_vector();

    /* Properties */
    int get_dimension() const { return m; }
    double get_entry(int row) const { return matrix[row-1][0]; }
    double get_norm() const;
    bool is_unit_vector() const { return (get_norm() == 1); }

    /* Setting Rows/Columns */
    void set_entry(double entry, int row) { matrix[row-1][0] = entry; }

    /* Operators */
    bool operator==(const Vector &other) const;
    void operator=(Vector const& other);

    Vector operator+(Vector const& other) const;
    Vector operator-(Vector const& other) const;
    Vector operator*(double constant);

    double dot_product(Vector const& other) const;
    Vector cross_product(Vector const& other) const;
};

class VectorEquation {
private:
    int dimension;
    static Vector parameters[VEC_EQ_PARAMS];
public:
    VectorEquation();
    VectorEquation(Vector const &point, Vector const &direction);
    VectorEquation(Vector const &point, Vector const &direction1, Vector const &direction2);

    friend ostream& operator<<(ostream &Out, VectorEquation const &eq);

    /* Calculate vector equation given two points */
    void calculate_line(Vector const &point1, Vector const &point2);
    void calculate_plane(Vector const &point1, Vector const &point2, Vector const &point3);
};

class Matrix {
protected:
    int m, n;
    double matrix[MAX_SIZE][MAX_SIZE] = {0};

public:
    /* Constructors */
    Matrix() { m = n = 2; }
    Matrix(int rows, int columns) { m = rows; n = columns; }

    /* Input/Output */
    friend ostream& operator<<(ostream &Out, Matrix const &matrix1);
    bool fin_matrix(ifstream &In);
    bool cin_matrix();

    double get_num_rows() const { return m; }
    double get_num_cols() const { return n; }
    double get_entry(int row, int col) const { return matrix[row-1][col-1]; }

    /* Setting Rows/Columns */

    void set_row(double const row[], int rowNum);
    void set_col(double const column[], int colNum);
    void set_entry(double entry, int row, int col) { matrix[row-1][col-1] = entry; }

    /* Operators */
    void operator=(Matrix const& other);

    Matrix operator+(Matrix const& other) const;
    Matrix operator-(Matrix const& other) const;

    Matrix operator*(Matrix const& other) const;
    Matrix operator*(double constant);
    Vector operator*(Vector const& vector) const;

    Matrix transpose() const;
};

#endif //LINALGCPP_VECTORMATRICES_H