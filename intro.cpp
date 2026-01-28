#include <iostream>
using namespace std;

class Student {
private:
    int id=5;
    float gpa;
    int maths , phy , PF , AP;

public:
    void setData(int i, int subj1 , int subj2 , int subj3 , int subj4) {
        id = i;
        maths = subj1;
        phy = subj2;
        PF = subj3;
        AP = subj4;
    }

    void print() {
        cout << "ID: " << id << endl;
        cout <<  "GPA: " << (maths+phy+AP+PF)/80 << endl;
    }
};

int main() {
    Student s;
    s.setData(101, 78 , 89 , 90 , 78);
    s.print();
}
