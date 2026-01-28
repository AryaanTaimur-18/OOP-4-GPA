#include <iostream>
using namespace std;

int main()
{
    int num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    cout << "\nEven numbers between " << num1 << " and " << num2 << ":\n";
    for (int i = num1; i <= num2; i++)
    {
        if (i % 2 == 0)
            cout << i << endl ;
    }

    cout << "\n\nOdd numbers between " << num1 << " and " << num2 << ":\n";
    for (int i = num1; i <= num2; i++)
    {
        if (i % 2 != 0)
            cout << i << endl ;
    }

    return 0;
}
