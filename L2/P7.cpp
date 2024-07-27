// Overload >> and << operators to input and display time.
#include<iostream>

using namespace std;

class TIME
{
    private:
    int hr, min, sec;

    public:
    friend istream& operator>> (istream& sin, TIME& t);
    friend ostream& operator<< (ostream& sout, const TIME& t);
};

istream& operator>> (istream& sin, TIME& t) {

    cout << "Enter hour: ";
    sin >> t.hr;
    cout << "Enter minutes: ";
    sin >> t.min;
    cout << "Enter seconds: ";
    sin >> t.sec;
    return sin;
}

ostream& operator<< (ostream& sout, const TIME& t){
    sout << endl << t.hr << ": " << t.min << ": " << t.sec << endl;
	return sout;
}

int main()
{
    TIME t;
    cin>>t;
    cout << "Output";
    cout<<t;

    return 0;
}