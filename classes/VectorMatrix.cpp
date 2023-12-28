#include "VectorMatrix.h"

ostream& operator<<(ostream &Out, Matrix const &matrix1) {
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

bool Matrix::fin_matrix(ifstream &In) {
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
            success = (bool) (cin >> matrix[i][j]);
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

void Matrix::operator=(Matrix const& other) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            matrix[i][j] = other.matrix[i][j];
    }
}

Matrix Matrix::operator+(Matrix const& other) const {
    if (other.m != m || other.m != n) {
        cout << "Unable to add matrices" << endl;
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
        cout << "Unable to subtract matrices" << endl;
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
        cout << "Unable to multiply matrices" << endl;
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

Vector Matrix::operator*(Vector const& v) const {
    if (v.get_dimension() != n) {
        cout << "Cannot multiply";
        return v;
    }

    Vector newVector(m);
    for (int row = 0; row < m; row++) {
        double entry = 0;
        for (int i = 0; i < n; i++)
            entry += matrix[row][i] * v.get_entry(i);
        newVector.set_entry(entry, row);
    }
    return newVector;
}

/* --------------------------------------------------------------------------
 * -------------------------------- VECTOR ----------------------------------
 * --------------------------------------------------------------------------*/
ostream& operator<<(ostream &Out, Vector const &vector1) {
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

void Vector::operator=(Vector const& other) {
    for (int i = 0; i < m; i++)
        matrix[i][0] = other.matrix[i][0];
}

double Vector::dot_product(const Vector &other) const {
    if (m != other.get_dimension()) {
        cout << "Cannot compute dot product" << endl;
        return pow(10, 6);
    }

    double result = 0;
    for (int i = 0; i < m; i++)
        result += get_entry(i) * other.get_entry(i);
    return result;
}

// First-year linear algebra only covers cross products for vectors in R^3
Vector Vector::cross_product(const Vector &other) const {
    if (m != 3 || other.get_dimension() != 3) {
        cout << "Cannot compute dot product" << endl;
        return (*this);
    }

    Vector cp(3);
    cp.set_entry(get_entry(2)*other.get_entry(3) - get_entry(3)*other.get_entry(2), 1);
    cp.set_entry(-(get_entry(1)*other.get_entry(3) - get_entry(3)*other.get_entry(1)), 2);
    cp.set_entry(get_entry(1)*other.get_entry(2) - get_entry(2)*other.get_entry(1), 3);
    return cp;
}

bool Vector::fin_vector(ifstream &In) {
    bool success = true;
    for (int i = 0; i < m && success; i++)
        success = (bool) (In >> matrix[i][0]);
    return success;
}

bool Vector::cin_vector() {
    bool success = true;
    for (int i = 0; i < m && success; i++)
        success = (bool) (cin >> matrix[i][0]);
    return success;
}

Vector Vector::operator+(Vector const& other) const {
    if (m != other.m) {
        cout << "Unable to add matrices" << endl;
        return (*this);
    }

    Vector newVector(m);

    for (int i = 0; i < m; i++)
        newVector.set_entry(other.get_entry(i) + (*this).get_entry(i), i);
    return newVector;
}

Vector Vector::operator-(Vector const& other) const {
    if (m != other.m) {
        cout << "Unable to add matrices" << endl;
        return (*this);
    }

    Vector newVector(m);

    for (int i = 0; i < m; i++)
        newVector.set_entry(other.get_entry(i) - (*this).get_entry(i), i);
    return newVector;
}

Vector Vector::operator*(double constant) {
    Vector newVector(m);
    for (int row = 0; row < m; row++)
        newVector.set_entry(constant * matrix[row][0], row);
    return newVector;
}

/* --------------------------------------------------------------------------
 * --------------------------- VECTOR EQUATION ------------------------------
 * --------------------------------------------------------------------------*/
VectorEquation::VectorEquation() {
    dimension = 2;
    for (int i = 0; i < VEC_EQ_PARAMS; i++)
        parameters[i] = Vector(2);
};

VectorEquation::VectorEquation(Vector const &point, Vector const &direction) {
    if (point.get_dimension() != direction.get_dimension()) {
        cout << "Cannot form vector equation; vectors have different dimensions";
        (*this) = VectorEquation();
    }

    parameters[0] = point;
    parameters[1] = direction;
    parameters[2] = Vector(point.get_dimension());
    dimension = point.get_dimension();
}

VectorEquation::VectorEquation(Vector const &point, Vector const &direction1, Vector const &direction2) {
    if (! (point.get_dimension() == direction1.get_dimension() &&
           point.get_dimension() == direction2.get_dimension()) )
    {
        cout << "Cannot form vector equation; vectors have different dimensions";
        (*this) = VectorEquation();
    }

    parameters[0] = point;
    parameters[1] = direction1;
    parameters[2] = direction2;
    dimension = point.get_dimension();
}

ostream& operator<<(ostream &Out, VectorEquation const &eq) {
    Out << eq.parameters[0] << " + s*" << eq.parameters[1];
    if (eq.parameters[2].get_norm() != 0)
        Out << " + t*" << eq.parameters[2];
    return Out;
}