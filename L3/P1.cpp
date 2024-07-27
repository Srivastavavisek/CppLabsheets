// Program to convert Nepalese Currency (Rupees and Paisa) to US
// Currency (Dollar and Cents). (Rs. 98.51=1$)
#include <iostream>
#include <cstdio>
#define EXCHANGERATE 98.51F
using namespace std;

class USCurrency;

class NepaleseCurrency
{
protected:
    int rupees, paisa;
    float nrs;

public:
    NepaleseCurrency(): rupees(0), paisa(0), nrs(0.0f) {}
    NepaleseCurrency(int r, int p): rupees(r), paisa(p) {
        nrs = r + (p)/100.0;
    }
    NepaleseCurrency(float n): nrs(n) {
        convert();
    }

    void convert() {
        rupees = static_cast<int>(nrs);
        paisa = static_cast<int>((nrs - rupees) * 100);
    }

    void getNRS() {
        cout << "Enter NRS: ";
        cin >> nrs;

        convert();        
    }

    void displayNRS() {
        cout << "Rupees: " << rupees << endl << "Paisa: " << paisa << endl;
    }

    operator USCurrency();

};

class USCurrency
{
private:
    int dollar, cents;
    float usd;

public:
    USCurrency(): dollar(0), cents(0), usd(0.0f) {}
    USCurrency(int d, int c): dollar(d), cents(c) {
        usd = d + c / 100.0;
    }
    USCurrency(float dlr): usd(dlr) {
        convert();
    }

    void convert() {
        dollar = static_cast<int>(usd);
        cents = static_cast<int>((usd - dollar) * 100);
    }
    
    void getDollar() {
        cout << "Enter USD: ";
        cin >> usd;
        
        convert();
    }

    void displayDollar() {
        cout << "Dollars: " << dollar << endl << "Cents: " << cents << endl;
    }

    operator NepaleseCurrency();
    
};

USCurrency::operator NepaleseCurrency() {
    float nrs = usd * EXCHANGERATE;
    int r = static_cast<int>(nrs);
    int p = static_cast<int>((nrs - r) * 100);
    return NepaleseCurrency(r, p);
}

NepaleseCurrency::operator USCurrency() {
    float usd = nrs / EXCHANGERATE;
    int d = static_cast<int>(usd);
    int c = static_cast<int>((usd - d) * 100);
    return USCurrency(d, c);
}

int main()
{
    USCurrency us;
    NepaleseCurrency np(98.51f);

    np.getNRS();
    us = np;
    us.displayDollar();

    us.getDollar();
    np = us;
    np.displayNRS();

    return 0;
}