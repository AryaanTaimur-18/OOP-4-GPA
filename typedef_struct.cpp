#include <iostream>
using namespace std;

int main() {
    typedef struct {
        int id;
        float gpa;
        int maths, phy, PF, AP;
    } Student;

    Student s1;

    s1.id = 101;
    s1.maths = 78;
    s1.phy = 89;
    s1.PF = 90;
    s1.AP = 78;

    s1.gpa = (s1.maths + s1.phy + s1.PF + s1.AP) / 80.0;

    cout << "ID: " << s1.id << endl;
    cout << "GPA: " << s1.gpa << endl;

    return 0;
} 