#include <iostream>
using namespace std;

class Engine
{

public:
    string engName;

    Engine(string n) : engName(n) {
        cout <<"EntEngine ("<< engName << ") constructed."<<endl;
        }
    string getName() {
        return engName;
        }
    void start() {
        cout<<"---> "<<engName<<" engine starting up..."<<endl;
        }
    ~Engine(){}
};
class Car
{
    string carName;
    Engine e;

public:
    Car(string n, string engName) : carName(n), e(engName) {
         cout << "Car (" << carName << ") assembled."<<endl;
    }
    string getCarName()
    {
        return carName;
    }
    void drive()
    {
        cout<<"Starting "<<carName<<" drive"<<endl;
        e.start();
       
    }
    ~Car(){
        cout<<"Car ("<<carName<<") destroyed"<<endl;
    }
};
int main()
{
   
    {
        Car car("SedanX","V6");
        car.drive();

        cout<<"End of main scope."<<endl;
    }
}