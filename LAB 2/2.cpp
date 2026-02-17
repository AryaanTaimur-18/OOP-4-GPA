#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:

    void setTime(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
}
    
    void addTime(Time t);

    void checkTime();
};


void Time::addTime(Time t) {
    seconds += t.seconds;
    minutes += seconds / 60;
    seconds = seconds % 60;

    minutes += t.minutes;
    hours += minutes / 60;
    minutes = minutes % 60;

    hours += t.hours;
}


void Time::checkTime() {
    cout << (hours < 10 ? "0" : "") << hours << ":"
         << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds << endl;
}

// Main function
int main() {
    Time t1, t2;
    

    t1.setTime(2, 45, 50);
    t2.setTime(1, 20, 30);

    t1.addTime(t2);
    t1.checkTime();

    return 0;
}
