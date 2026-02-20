#include <iostream>
#include <string>

using namespace std;

class RentCalculator {
private:
    const double RentPerDay = 1000.85;
    
    const string CustomerName;
    int NumberOfDays;
    double CustomerRent;

public:
    RentCalculator(string name, int days) : CustomerName(name), NumberOfDays(days) {
        if (NumberOfDays > 7) {
            RentWithDiscount();
        } else {
            RentWithoutDiscount();
        }
    }

    void RentWithDiscount() {
        CustomerRent = (NumberOfDays - 1) * RentPerDay;
    }

    void RentWithoutDiscount() {
        CustomerRent = NumberOfDays * RentPerDay;
    }

    void DisplayRent() const {
        cout << "--- Sindhri Hotel Receipt ---" << endl;
        cout << "Customer Name: " << CustomerName << endl;
        cout << "Days Stayed:   " << NumberOfDays << endl;
        cout << "Total Rent:    " << CustomerRent << endl;
        cout << "-----------------------------" << endl << endl;
    }
};

int main() {
    
    RentCalculator customer1("Aryaan Taimur", 5);
    customer1.DisplayRent();

    RentCalculator customer2("Mehmood Sahab", 10);
    customer2.DisplayRent();

    return 0;
}