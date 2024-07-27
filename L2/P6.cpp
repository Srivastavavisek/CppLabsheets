// Modify above class to work with compile time memory allocation i.e. with char [].

#include<iostream>
#include<string.h>

#define sz 100

using namespace std;

class STRING
{
private:
	char str[sz];

public:
	STRING() {
        str[0] = '\0';
    }
	STRING(const char str[])
	{
		strncpy(this->str, str, sz-1);
        this->str[sz-1] = '\0';
	}
	void out() const {
            cout << str << endl;
    }
	STRING operator + (const STRING obj) const {
		STRING temp;
		strncpy(temp.str, str, sz-1);
        temp.str[sz-1] = '\0';
        strncat(temp.str, " ", sz - strlen(temp.str) - 1);
		strncat(temp.str, obj.str, sz - strlen(temp.str) - 1);
		return temp;
	}
    STRING& operator = (const STRING& obj) {
        strncpy(str, obj.str, sz-1);
        str[sz-1] = '\0';
        return *this;
    }
    bool operator == (const STRING& obj) const {
        return (strcmp(str, obj.str) == 0);
    }
};

int main() {
    STRING s1("Abhishek"), s2("Kayastha"), s3, s4, s5;

    s3 = s1 + s2;
    s3.out();

    s4 = s5 = s3;
    // s4 = s3;

    s4.out();
    s5.out();

    cout << ((s3 == s4)? "Equal" : "Not Equal") << endl;
    cout << ((s5 == s4)? "Equal" : "Not Equal") << endl;

    return 0;
}