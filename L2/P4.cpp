// Create a class called 'TIME' that has
// - thhee integer data members for hours, mmutes and ssonds
// - constructor to initialize the object to zero
// - constructor to initialize the object to some constant value
// - overload +,- to add and subtract two TIME objects
// - overload > function to compare two time
// - member function to display time in HH:MM:SS format

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class TIME {
protected:
    int hh, mm, ss;
    string time;

    void format24() {
        if (ss >= 60) {
            mm += ss / 60;
            ss %= 60;
        }
        if (mm >= 60) {
            hh += mm / 60;
            mm %= 60;
        }
        if (hh >= 24) {
            hh %= 24;
        }
    }

public:
    class negTimeDifference
    {};

    TIME(): hh(0), mm(0), ss(0) {}

    TIME(int h, int m, int s): hh(h), mm(m), ss(s) { format24(); }

    void input() {
        cout << "Enter Time (hh:mm:ss): ";
        getline(cin, time);
        sscanf(time.c_str(), "%d:%d:%d", &hh, &mm, &ss);
        format24();
    }

    void show() const {
        printf("Time:\t%02d:%02d:%02d\n", hh, mm, ss);
    }

    TIME operator+ (const TIME& t) const;
    TIME operator- (const TIME& t) const;
    bool operator> (const TIME& t) const;
};

TIME TIME::operator+ (const TIME& t) const {
    int h = hh + t.hh;
    int m = mm + t.mm;
    int s = ss + t.ss;
    return TIME(h, m, s);
}

TIME TIME::operator- (const TIME& t) const {
    int result = (hh * 3600 + mm * 60 + ss) - (t.hh * 3600 + t.mm * 60 + t.ss);

    if (result < 0)
        throw negTimeDifference();

    int h = result / 3600;
    result %= 3600;
    int m = result / 60;
    result %= 60;
    int s = result;
    return TIME(h, m, s);
}

bool TIME::operator> (const TIME& t) const {
    if (hh > t.hh)
        return true;
    else if (hh == t.hh && mm > t.mm)
        return true;
    else if (hh == t.hh && mm == t.mm && ss > t.ss)
        return true;

    return false;
}

int main() {
    TIME t1(3, 45, 50);
    TIME t2;
    t2.input();
    t1.show();
    t2.show();

    (t1 > t2) ? cout << "True" << endl : cout << "False" << endl;

    TIME t3 = t2 + t1;
    t3.show();

    try {
        TIME t4 = t2 - t1;
        t4.show();
    }
    catch(TIME::negTimeDifference) {
        cout << "Negative time Difference" << endl;
    }

    try {
        TIME t5 = t1 - t2;
        t5.show();
    }
    catch(TIME::negTimeDifference) {
        cout << "Negative time Difference" << endl;
    }
    
    return 0;
}