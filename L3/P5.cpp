// Program to convert time (hour, minute and second) in 12-hr format to
// 24-hr format.

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class incorrectFormat {};
class Format12;

class Format24
{
    protected:
    int hh, mm, ss;

    public:
    Format24(): hh(0), mm(0), ss(0) {}

    Format24(int h, int m, int s): hh(h), mm(m), ss(s) {}

    void display24() {
        printf("24-hr format:\t%02d:%02d:%02d\n", hh, mm, ss);
    }
};

class Format12
{
    protected:
    int hh, mm, ss;
    string meridien;

    public:
    Format12(): hh(0), mm(0), ss(0), meridien("AM") {}

    Format12(int h, int m, int s, string mrdn): hh(h), mm(m), ss(s), meridien(mrdn) {}

    void display12() {
        printf("12-hr format:\t%02d:%02d:%02d %s\n", hh, mm, ss, meridien.c_str());
    }
    
    void input12(){
        char mrdn[2];
        cout << "Enter 12-hr format (hh: mm: ss AM/PM):" << endl;
        scanf("%d:%d:%d %s", &hh, &mm, &ss, mrdn);
        meridien = mrdn;

        if (hh < 1 || hh > 12 || mm < 0 || mm >= 60 || ss < 0 || ss >= 60)
            throw incorrectFormat();
    }

    operator Format24();
};

Format12::operator Format24() {
    if (meridien == "PM") {
        return Format24(hh + 12, mm, ss);
    }
    return Format24(hh, mm, ss);
}

int main()
{
    int ch;
    Format12 t1;
    Format24 t2;

    try { 
        t1.input12();
        t2 = t1;
        t2.display24();
    }
    
    catch(incorrectFormat) {
        cout << "Format Error\n"; 
    }
    
    return 0;
}
