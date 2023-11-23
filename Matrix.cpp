class Matrix {
    public:
        Matrix() {
            m = n = 2;
        }

        Matrix(double rows, double columns) {
            m = rows;
            n = columns;
        }

        Matrix 
    private:
        const int MAX_SIZE = 10;
        int m, n;
        double matrix[MAX_SIZE][MAX_SIZE];
};

int main () {
    Matrix(1, 2);
}