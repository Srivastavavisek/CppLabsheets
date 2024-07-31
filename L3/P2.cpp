// Program to convert time (hour, minute and second) in 24-hr format to
// 12-hr format.

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

    void input24(){
        cout << "Enter 24-hr format (hh: mm: ss):" << endl;
        scanf("%d:%d:%d", &hh, &mm, &ss);

        if (hh < 0 || hh > 23 || mm < 0 || mm >= 60 || ss < 0 || ss >= 60)
            throw incorrectFormat();
    }

    operator Format12();
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
};

Format24::operator Format12() {
    string meridien = "AM";
    int h = hh;
    if (h >= 12) {
        meridien = "PM";
        if (h > 12)
            h -= 12;
    }

    if (h == 0)
        h = 12;
    
    return Format12(h, mm, ss, meridien);
}

int main()
{
    int ch;
    Format12 t1;
    Format24 t2;

    try {
        t2.input24();
        t1 = t2;
        t1.display12(); 
    }
    catch(incorrectFormat) {cout << "Format Error\n"; }
    return 0;
}
