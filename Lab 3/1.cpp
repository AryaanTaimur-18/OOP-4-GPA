#include <iostream>
#include <string>
using namespace std;

class DayType {
private:
    int dayIndex;
    string days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

public:
    DayType() {
        dayIndex = 0;
    }

    DayType(string day) {
        setDay(day);
    }

    void setDay(string day) {
        for (int i = 0; i < 7; i++) {
            if (days[i] == day) {
                dayIndex = i;
                return;
            }
        }
        dayIndex = 0;
    }

    void printDay() {
        cout << days[dayIndex] << endl;
    }

    string getDay() {
        return days[dayIndex];
    }

    string nextDay() {
        return days[(dayIndex + 1) % 7];
    }

    string previousDay() {
        return days[(dayIndex + 6) % 7];
    }

    string addDays(int n) {
        int newIndex = (dayIndex + n) % 7;
        return days[newIndex];
    }
};

int main() {
    DayType today("Mon");

    cout << "Today: ";
    today.printDay();

    cout << "Next Day: " << today.nextDay() << endl;
    cout << "Previous Day: " << today.previousDay() << endl;

    cout << "After adding 4 days: " << today.addDays(4) << endl;
    cout << "After adding 13 days: " << today.addDays(13) << endl;

    return 0;
}
