# include <iostream>
using namespace std;

int main() {
    
    // Reference Variable
    int a = 4;
    int & b = a;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // Typecasting

    float x = 5.67;

    cout << "x = " << x << endl;
    cout << "x = " << int(x) << endl;
    cout << "x = " << (int)x << endl;
}