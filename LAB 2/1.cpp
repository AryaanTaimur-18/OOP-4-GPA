#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle() : length(0), width(0) {}
    Rectangle(double l, double w) : length(l), width(w) {}

    void setLength(double l) { 
        length = l; 
    }
    void setWidth(double w) { 
        width = w; 
    }
    void setDimensions(double l, double w) {
         length = l; width = w; 
        }

    double getLength() {
        return length; 
    }
    double getWidth() { 
        return width; 
    }
    pair<double,double> getDimensions() { 
        return {length, width};
    }

    double calculateArea() { 
        return length * width;
    }
    double calculatePerimeter() {
        return 2 * (length + width); 
    }

    bool isSquare() { 
        if (length == width) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    double l, w;
    Rectangle r;

    cout << "Enter length and width of the rectangle: ";
    cin >> l >> w;
    r.setLength(l);
    r.setWidth(w);
    r.setDimensions(l, w);

    cout << "Length: " << r.getLength() << "\n";
    cout << "Width: " << r.getWidth() << "\n";
    cout << "Area: " << r.calculateArea() << "\n";
    cout << "Perimeter: " << r.calculatePerimeter() << "\n";
    cout << "Is square? " << (r.isSquare() ? "Yes" : "No") << "\n";

    
    return 0;
}