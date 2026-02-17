#include <iostream>
#include "matrix.h"
using namespace std;

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int result[2][2];

    cout << "Addition:\n";
    add(A, B, result);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    cout << "\nSubtraction:\n";
    sub(A, B, result);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    cout << "\nMultiplication:\n";
    mul(A, B, result);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    cout << "\nDeterminant of Matrix A: "
         << determinant(A) << endl;

    return 0;
}
