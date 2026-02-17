#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    int finalX ;
    int finalY ;
    void setPoint(int x1, int y1) {
        x = x1;
        y = y1;
    }

   void moveInX(int x_units) {
       int finalX = x + x_units;
    }

    void moveInY(int y_units) {
        int finalY = y + y_units;
    }

    void move(int x_units, int y_units) {
        int finalX = x + x_units;
        int finalY = y + y_units;
    }

    float distancefromOrigin() {
        int disX = finalX - x;
        int disY = finalY - y;
        float distance = sqrt(disX*disX + disY*disY);
        return distance;
    }

    void isEqual(Point p1 ,Point p2) {
        if (p1.finalX == p2.finalX && p1.finalY == p2.finalY) {
            cout << "Points are equal." << endl;
        } else {
            cout << "Points are not equal." << endl;
        }
    }
};    

int main() {
    Point p1,p2;

    int x,y;

    cout << "Enter coordinates of point 1: ";
    cin >> x >> y;

    p1.setPoint(x, y);

    cout << "Enter coordinates of point 2: ";
    cin >> x >> y;

    p2.setPoint(x, y);

    cout << "Enter coordinates to move point 1: ";
    cin >> x >> y;
    
    p1.move(x, y);

    cout << "Enter coordinates to move point 2: ";
    cin >> x >> y;
    
    p2.move(x, y);

    float d1 = p1.distancefromOrigin();
    cout << "Distance of point 1 from origin: " << d1 << endl;


    float d2 = p2.distancefromOrigin();
    cout << "Distance of point 2 from origin: " << d2 << endl;

    p1.isEqual(p1, p2);

    return 0;
}