#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string StudentName;
    const int StudentID; 

public:
    Student(string name, int id) : StudentName(name), StudentID(id) {}

    void setStudentName(string name) {
        StudentName = name;
    }

    string getStudentName() const { return StudentName; }
    int getStudentID() const { return StudentID; }
};

void displayStudent(const Student& s) {
    cout << "ID: " << s.getStudentID() << " | Name: " << s.getStudentName() << endl;
}

void runStudentTask() {
    Student student1("Aryaan Taimur", 2540);
    Student student2("Ayesha", 2590);
    Student student3("Abdullah", 2439);

    student1.setStudentName("Aryaan");

    displayStudent(student1);
    displayStudent(student2);
    displayStudent(student3);
}

int main() {
    runStudentTask();
    
    return 0;
}