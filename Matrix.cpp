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
        Matrix() {
            m = n = 2;
        }

        Matrix(double rows, double columns) {
            m = rows;
            n = columns;
        }
        
        void out(ostream &Out) {
            for (int row = 0; row < m; row++) {  
                Out << "[";
                
                for (int col = 0; col < n; col++) {
                    Out << matrix[row][col];
                    if (col != n-1)
                        Out << ", ";
                }
                
                Out << "]";
                if (row != m-1)
                   Out << endl;
            }
        }

        bool fin_matrix(ifstream &In) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n && (In >> matrix[i][j]); j++) {}
            }
            return 0;
        }

        bool cin_matrix() {
            bool success = true;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n && (cin >> matrix[i][j]); j++) {}
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
        void set_row(double row[], int rowNum) {
            for (int col = 0; col < n; col++) {
                matrix[rowNum][col] = row[col];
            }
        }

        // Changes column given an array
        void set_col(double column[], int colNum) {
            for (int row = 0; row < m; row++) {
                matrix[row][colNum] = column[row];
            }
        }

        // Changes a single entry within the matrix
        void set_entry(double entry, int row, int col) {
            matrix[row][col] = entry;
        }

        Matrix operator+(Matrix const& other) {
            if (other.get_num_rows() != m || other.get_num_cols() != n) {
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
};