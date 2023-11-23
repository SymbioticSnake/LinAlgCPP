#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 10;

class Matrix {
    public:
        Matrix() {
            m = n = 2;
        }

        Matrix(double rows, double columns) {
            m = rows;
            n = columns;
        }
        
        void out() {
            for (int row = 0; row < m; row++) {  
                cout << "[";
                
                for (int col = 0; col < n; col++) {
                    cout << matrix[row][col];
                    if (col != n-1)
                        cout << ", ";
                }
                
                cout << "]";
                if (row != m-1)
                   cout << endl;
            }
        }

        // Assume row array is n elements long 
        void set_row(double row[], int rowNum) {
            for (int col = 0; col < n; col++) {
                matrix[rowNum][col] = row[col];
            }
        }

        // Assume col array is m elements long
        void set_col(double column[], int colNum) {
            for (int row = 0; row < m; row++) {
                matrix[row][colNum] = column[row];
            }
        }

    private:
        int m, n;
        double matrix[MAX_SIZE][MAX_SIZE] = {0};
};