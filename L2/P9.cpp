// Create a 'MATRIX' class of size m X n. Overload the ‘+’ operator to
// Add Two MATRIX objects. Write a main function to implement it.

#include <iostream>
#include <cstdio>
#define SIZE 10

using namespace std;

class MATRIX
{
    static int m, n;
    float matrix[SIZE][SIZE];

public:
    MATRIX() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                matrix[i][j] = 0.0f;
        }
    }

    static void getRowsCols()
    {
        cout << "Enter the number of rows and columns: " << std::endl;
        cin >> m >> n;
    }

    void input() {
        cout << "Enter the elements of Matrix: " << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("Index [%d, %d] = ", i+1, j+1);
                cin >> matrix[i][j];
            }
        }
    }

    MATRIX operator+(const MATRIX& mat2) const {
        MATRIX sum;
        for (auto i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum.matrix[i][j] = this->matrix[i][j] + mat2.matrix[i][j];
            }
        }
        return sum;
    }

    void output() const {
        for (auto i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int MATRIX::m = 0;
int MATRIX::n = 0;

int main() {
    MATRIX::getRowsCols();

    MATRIX m1, m2, m3, m4;
    m4.output();

    cout << "Matrix-1\n";
    m1.input();
    cout << "Matrix-2\n";
    m2.input();

    m3 = m1 + m2;

    cout << "Matrix-1:\n";
    m1.output();
    cout << "Matrix-2:\n";
    m2.output();
    cout << "Sum:\n";
    m3.output();

    return 0;
}