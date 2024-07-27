// To write a C++ program to overload all relational operators to compare US currency with Nepalese currency.
// Use conversion rate $1=NRs 101.36 (Note: make two classes to represent each currency)

#include<iostream>
#define CONVERSION_RATE 101.36F
using namespace std;

class NepaleseCurrency;

class USCurrency
{
public:
    USCurrency(): d(0.0f) {}
    USCurrency(float d) { this->d = d; }
    void setDollars() {
        cout << "Enter Dollar Amount: ";
        cin >> d;
    }

    float getDollars() const { return d; }

    bool operator == (const NepaleseCurrency& nc) const ;
    bool operator != (const NepaleseCurrency& nc) const ;
    bool operator > (const NepaleseCurrency& nc) const ;
    bool operator < (const NepaleseCurrency& nc) const ;
    bool operator >= (const NepaleseCurrency& nc) const ;
    bool operator <= (const NepaleseCurrency& nc) const ;

private:
    float d;
};

class NepaleseCurrency
{
public:
    NepaleseCurrency(): nrs(0.0f) {}
    NepaleseCurrency(float nrs) { this->nrs = nrs; }
    void setNRS() {
        cout << "Enter rupee Amount: ";
        cin >> nrs;
    }

    float getNrs() const { return nrs; }

    friend class USCurrency;

private: 
    float nrs;
};

bool USCurrency::operator==(const NepaleseCurrency& nc) const {
    return (d * CONVERSION_RATE == nc.nrs);
}

bool USCurrency::operator!=(const NepaleseCurrency& nc) const {
    return (d * CONVERSION_RATE == nc.nrs);
}

bool USCurrency::operator > (const NepaleseCurrency& nc) const {
    return (d * CONVERSION_RATE > nc.nrs);
}

bool USCurrency::operator < (const NepaleseCurrency& nc) const {
    return (d * CONVERSION_RATE < nc.nrs);
}

bool USCurrency::operator>=(const NepaleseCurrency& nc) const {
    return (d * CONVERSION_RATE >= nc.nrs);
}

bool USCurrency::operator<=(const NepaleseCurrency& nc) const {
    return (d * CONVERSION_RATE <= nc.nrs);
}

void compare(const USCurrency& usd, const NepaleseCurrency& nrs) {
    if (usd == nrs) {
        cout << "USCurrency is equal to NepaleseCurrency" << endl;
    }
    
    else if (usd > nrs) {
        cout << "USCurrency is greater than NepaleseCurrency" << endl;
    }
    
    else if (usd < nrs) {
        cout << "USCurrency is less than NepaleseCurrency" << endl;
    }
    
    else if (usd >= nrs) {
        cout << "USCurrency is greater than or equal to NepaleseCurrency" << endl;
    }
    
    else if (usd <= nrs) {
        cout << "USCurrency is less than or equal to NepaleseCurrency" << endl;
    }
}

int main()
{
    USCurrency usd(1);
    NepaleseCurrency nrs(101.36);
    compare(usd, nrs);

    USCurrency u;
    NepaleseCurrency n;
    usd.setDollars();
    nrs.setNRS();
    compare(usd, nrs);

    return 0;
}
