//
// Created by danan on 06/01/2024.
//

#ifndef LINALGCPP_VECTOR_H
#define LINALGCPP_VECTOR_H

#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

const int MAX_SIZE = 10;

class Vector {
protected:
    int m;
    double matrix[MAX_SIZE][1] = {0};
public:
    Vector() { m = 2; }
    Vector(int rows) { m = rows; }

    /* Input/Output */
    friend std::ostream& operator<<(std::ostream &Out, Vector const &vector1);
    bool fin_vector(std::ifstream &In);
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
    Vector& operator=(Vector const& other);

    Vector operator+(Vector const& other) const;
    Vector operator-(Vector const& other) const;
    Vector operator*(double constant) const;
    Vector operator/(double constant) const;

    double dot_product(Vector const& other) const;
    Vector cross_product(Vector const& other) const;
    Vector projection(Vector const& other) const;
    Vector perpendicular(Vector const& other) const;
};

#endif //LINALGCPP_VECTOR_H
