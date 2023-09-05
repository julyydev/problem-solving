#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

class Matrix {
    int rows, cols;
    vector<vector<int>> data;

   public:
    Matrix() {}
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, vector<int>(cols, 0));
    }

    void set_element(int i, int j, int value) { data[i][j] = value; }

    int get_rows() { return rows; }

    int get_cols() { return cols; }

    Matrix operator*(const Matrix& m) const {
        Matrix result(rows, m.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * m.data[k][j];
                result.data[i][j] %= 1000;
            }
        }

        return result;
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) cout << data[i][j] << " ";
            cout << "\n";
        }
    }
};

Matrix power_matrix(Matrix matrix, long long n) {
    Matrix result(matrix.get_rows(), matrix.get_cols());
    for (int i = 0; i < result.get_rows(); i++) result.set_element(i, i, 1);

    while (n > 0) {
        if (n % 2 == 1) {
            result = result * matrix;
            n--;
        } else {
            matrix = matrix * matrix;
            n /= 2;
        }
    }

    return result;
}

int main() {
    FASTIO();
    int N, x;
    long long B;
    cin >> N >> B;

    Matrix matrix(N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> x;
            matrix.set_element(i, j, x);
        }
    }

    Matrix result = power_matrix(matrix, B);
    result.print();

    return 0;
}