#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 10;

class Matrix {
    private:
        int m, n;
        double matrix[MAX_SIZE][MAX_SIZE] = {0};
    
    public:
        /* Constructors */
        Matrix() {
            m = n = 2;
        }

        Matrix(double rows, double columns) {
            m = rows;
            n = columns;
        }

        /* Input/Output */
        friend ostream& operator<<(ostream &Out, Matrix const &matrix1) {
            for (int row = 0; row < matrix1.m; row++) {
                Out << "[";

                for (int col = 0; col < matrix1.n; col++) {
                    Out << matrix1.matrix[row][col];
                    if (col != matrix1.n - 1)
                        Out << ", ";
                }

                Out << "]";
                if (row != matrix1.m - 1)
                    Out << endl;
            }
            Out << endl;
            return Out;
        }

        bool fin_matrix(ifstream &In) {
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

        bool cin_matrix() {
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

        double get_num_rows() const {
            return m;
        }

        double get_num_cols() const {
            return n;
        }

        double get_entry(int row, int col) const {
            return matrix[row][col];
        }

        // Changes row given an array
        void set_row(double const row[], int rowNum) {
            for (int col = 0; col < n; col++) {
                matrix[rowNum-1][col] = row[col];
            }
        }

        // Changes column given an array
        void set_col(double const column[], int colNum) {
            for (int row = 0; row < m; row++) {
                matrix[row][colNum+1] = column[row];
            }
        }

        // Changes a single entry within the matrix
        void set_entry(double entry, int row, int col) {
            matrix[row][col] = entry;
        }

        /* Operators */
        Matrix operator+(Matrix const& other) {
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

        Matrix operator-(Matrix const& other) {
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

        Matrix operator*(Matrix const& other) {
            if (n != other.get_num_rows()) {
                cout << "Unable to multiply matrices" << endl;
                return (*this);
            }

            Matrix newMatrix(m, other.n);
            double sum = 0;
            for (int col = 0; col < other.n; col++) {
                for (int row = 0; row < m; row++) {
                    for (int i = 0; i < n; i++) {
                        newMatrix.matrix[row][col] += matrix[row][i] * other.matrix[i][col];
                    }
                }
            }

            return newMatrix;
        }

        Matrix transpose() const {
            Matrix newMatrix(n, m);

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    newMatrix.matrix[j][i] = matrix[i][j];
                }
            }

            return newMatrix;
        }


};