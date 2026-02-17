#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

void add(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void sub(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = A[i][j] - B[i][j];
}

void mul(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
    }
}

int determinant(int A[2][2]) {
    return (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
}

#endif
