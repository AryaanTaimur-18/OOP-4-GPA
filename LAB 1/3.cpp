#include <iostream>
using namespace std;

void inputMatrix(int m[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> m[i][j];
        }
    }
}

void displayMatrix(int m[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrix(int a[2][2], int b[2][2])
{
    int sum[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    cout << "\nAddition Result:\n";
    displayMatrix(sum);
}

void subtractMatrix(int a[2][2], int b[2][2])
{
    int sub[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sub[i][j] = a[i][j] - b[i][j];
        }
    }
    cout << "\nSubtraction Result:\n";
    displayMatrix(sub);
}

void multiplyMatrix(int a[2][2], int b[2][2])
{
    int mul[2][2] = {0};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "\nMultiplication Result:\n";
    displayMatrix(mul);
}

int main()
{
    int A[2][2], B[2][2];

    cout << "Enter elements of first matrix:\n";
    inputMatrix(A);

    cout << "Enter elements of second matrix:\n";
    inputMatrix(B);

    addMatrix(A, B);
    subtractMatrix(A, B);
    multiplyMatrix(A, B);

    return 0;
}
