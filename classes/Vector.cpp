#include "Vector.h"

/* --------------------------- VECTOR METHODS ------------------------------- */
std::ostream& operator<<(std::ostream &Out, Vector const &vector1) {
    Out << "[";
    for (int row = 0; row < vector1.m; row++) {
        Out << vector1.matrix[row][0];
        if (row != vector1.m - 1)
            Out << "; ";

    }
    Out << "]";
    return Out;
}

double Vector::get_norm() const {
    double sum = 0;
    for (int i = 0; i < m; i++)
        sum += pow(matrix[i][0], 2);
    return sqrt(sum);
}

bool Vector::operator==(const Vector &other) const {
    bool success = true;
    for (int i = 0; i < m && success; i++)
        success = (get_entry(i) == other.get_entry(i));
    return success;
}

Vector& Vector::operator=(Vector const& other) {
    for (int i = 0; i < m; i++)
        matrix[i][0] = other.matrix[i][0];
    return *this;
}

double Vector::dot_product(const Vector &other) const {
    if (m != other.get_dimension()) {
        std::cout << "Cannot compute dot product" << std::endl;
        return pow(10, 6);
    }

    double result = 0;
    for (int i = 0; i < m; i++)
        result += get_entry(i) * other.get_entry(i);
    return result;
}

Vector Vector::cross_product(const Vector &other) const {
    if (m != 3 || other.get_dimension() != 3) {
        std::cout << "Cannot compute dot product" << std::endl;
        return (*this);
    }

    Vector cp(3);
    cp.set_entry(get_entry(2)*other.get_entry(3) - get_entry(3)*other.get_entry(2), 1);
    cp.set_entry(-(get_entry(1)*other.get_entry(3) - get_entry(3)*other.get_entry(1)), 2);
    cp.set_entry(get_entry(1)*other.get_entry(2) - get_entry(2)*other.get_entry(1), 3);
    return cp;
}

bool Vector::fin_vector(std::ifstream &In) {
    bool success = true;
    for (int i = 0; i < m && success; i++)
        success = (bool) (In >> matrix[i][0]);
    return success;
}

bool Vector::cin_vector() {
    bool success = true;
    for (int i = 0; i < m && success; i++)
        success = (bool) (std::cin >> matrix[i][0]);
    return success;
}

Vector Vector::operator+(Vector const& other) const {
    if (m != other.m) {
        std::cout << "Unable to add matrices" << std::endl;
        return (*this);
    }

    Vector newVector(m);

    for (int i = 0; i < m; i++)
        newVector.set_entry(other.get_entry(i) + (*this).get_entry(i), i);
    return newVector;
}

Vector Vector::operator-(Vector const& other) const {
    if (m != other.m) {
        std::cout << "Unable to add matrices" << std::endl;
        return (*this);
    }

    Vector newVector(m);

    for (int i = 0; i < m; i++)
        newVector.set_entry(other.get_entry(i) - (*this).get_entry(i), i);
    return newVector;
}

Vector Vector::operator*(double constant) const{
    Vector newVector(m);
    for (int row = 0; row < m; row++)
        newVector.set_entry(constant * matrix[row][0], row);
    return newVector;
}

Vector Vector::operator/(double constant) const{
    Vector newVector(m);
    for (int row = 0; row < m; row++)
        newVector.set_entry( matrix[row][0] / constant, row);
    return newVector;
}

// Projection of other onto (*this)
Vector Vector::projection(Vector const& other) const {
    return (*this) * (dot_product(other)/pow(get_norm(), 2));
}

// Perpendicular of other onto (*this)
Vector Vector::perpendicular(Vector const& other) const {
    return other - projection(other);
}