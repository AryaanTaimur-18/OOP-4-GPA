
#include <iostream>
#include <vector>
using namespace std;

class Employee{

    public:
    string employeeName;

    Employee(string n) : employeeName(n)
    {
        cout << "Employee " << employeeName << " Hired"<<endl;
    }
    string getEmpName()
    {
        return employeeName;
    }
    void display()
    {
        cout << employeeName << " is" << " Performing tasks" << endl;
    }
    ~Employee(){
        cout<<"Employee "<<employeeName<<" Retired\\left"<<endl; 
    }
};

class Department{

public:
    string deptName;
    vector<Employee *> e;

    Department(string name) : deptName(name)
    {
    }

    void addEmp(Employee *emp)
    {
        e.push_back(emp);
        cout<<"[Dept] Employee added to "<< deptName << endl;
    }

    void display()
    {
        cout<<"---" << deptName << " Staff----" << endl;
        for (int i = 0; i < e.size(); i++)
        {
            e[i]->display();
        }
    }
    ~Department(){
        cout << "Department " << deptName << " Shut down" << endl;
    }
};
int main()
{
    Department d1("HR");
    Employee emp2("Aryaan Taimur");
    Employee emp1("Abdullah");
    d1.addEmp(&emp1);
    d1.addEmp(&emp2);
    d1.display();

    return 0;
}