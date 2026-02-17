#include <iostream>
using namespace std;

class Person{
    private:
        string firstName , lastName , midName;
    
    public:

        Person(){
            firstName = "";
            lastName = "";
            midName = "";

            cout << "Default constructor called." << endl;
        }

        void setFirstName(string fName){
            firstName = fName;
        }

        void setMidName(string mName){
            midName = mName;
        }

        void setLastName(string lName){
            lastName = lName;
        }

        void printFullName(){
            cout << firstName << " " << lastName << endl;
        }

        void checkFirstName(string name){
            if(name == firstName){
                cout << "First name is correct." << endl;
            } else {
                cout << "First name is incorrect." << endl;
            }
        }

        void checkFullName(string fName, string mName, string lName){
            if(fName == firstName && mName == midName && lName == lastName){
                cout << "Full name is correct." << endl;
            } else {
                cout << "Full name is incorrect." << endl;
            }
        }
};

int main() {
    string name , name2 , name3;

    Person p1;
    Person();

    p1.setFirstName("Aryaan");
    p1.setMidName("Taimur");
    p1.setLastName("Saeed");

    cout << "Enter the first name: " << endl;
    cin >> name;

    p1.checkFirstName(name);

    cout << "Enter middle name: " << endl;
    cin >> name2;

    cout << "Enter last name: " << endl;
    cin >> name3;

    p1.checkFullName(name , name2 , name3);

    return 0;

}
