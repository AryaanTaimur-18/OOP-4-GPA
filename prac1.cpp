#include <iostream>
using namespace std;

int glo = 9;

void sum(int a, int b) {
    int x = a;
    int y = b;
    cout << "Sum of a and b is: " << x+y << endl;
    cout <<"glo = " << glo << endl;
}

int main() {
    int glo = 78;
    int a=5;
    int b=7;
    sum(a, b);
    cout << "glo = " << glo << endl;
    cout << "Sum of a and b is: " << a+b << endl;
    cout << "Hello, World!" << endl;
    return 0;
}