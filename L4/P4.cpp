// a. Define an instance object of class DateTime called Watch.
// b. Write a main () function that would initialize the values through the constructor
// functions, and then allows them to be reset through the set () functions. Be sure and
// display the results following the constructor before you use the set functions.
// c. Through the use of the display () function, the time and date are to be displayed. Note
// that the display () functions in all three classes need to be defined, as well as the
// constructor and all the access functions.

#include <iostream>
#include <cstdio>

using namespace std;

class Date {
    int day, month, year;

public:
    Date() : day(0), month(0), year(0) {}

    Date(int d, int m, int y) : day(d), month(m), year(y){}
    
    ~Date() {};

    // displays the date
    void display(){
        printf("Date: %02d/%02d/%02d\n", day, month, year);
    };

    // accesses the date members
    Date get(){
        return *this;
    };

    // sets the date members
    void set(int d, int m, int y){ 
        day = d;
        month = m;
        year = y;
    }     
};

class Time {
    int hour;
    int minute;
    int second;

    public:
        Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

        ~Time() {};

        void display(){
            printf("Time: %02d:%02d:%02d\n", hour, minute, second);
        } 
        Time get(){
            return *this;
        };

        void set(int h, int m, int s){
            hour = h;
            minute = m;
            second = s;
        };
};

class DateAndTime : public Date, public Time {
    public:
        DateAndTime(int d, int m, int y, int h, int min, int s) : Date(d, m, y) , Time(h, min, s){}

        void display(){
            Date::display();
            Time::display();
        };
};

int main(){
    DateAndTime Watch(28, 7, 2024, 21, 37, 58);

    cout << "Before resetting:" << endl;
    Watch.display();
    
    Watch.Date::set(29, 7, 2024);
    Watch.Time::set(10, 0, 50);
    cout << endl <<"After resetting:" << endl;
    Watch.display();

    return 0;
}