// Create a 'STRING' class which char* and length as data member and
// overloads ‘+’ ,’=’ and ‘ = = ‘ to perform respective operations.
// Use constructor and destructor whenever suitable.

#include<iostream>
#include<string.h>

using namespace std;

class STRING {
private:
    char* str;
    int len;

public:
    STRING() : str(nullptr), len(0) {}
    // STRING() : str(new char[1]) { str[0] = '\0'; }

    STRING(const char* s) {
        len = strlen(s);
        str = new char[len+1];
        strcpy(str, s);
    }

    // STRING(const STRING& obj) {
    //     len = obj.len;
    //     str = new char[len];
    //     strcpy(str, obj.str);
    // }

    ~STRING() {
        delete[] str;
    }

    void out() const {
        if (str != nullptr)
            cout << str << endl;
        else
            cout << "(no memory was allocated...)";
    }

    STRING& operator = (const STRING& obj);
    bool operator == (const STRING& obj) const;
    STRING operator + (const STRING& obj) const;    
};

bool STRING::operator == (const STRING& obj) const {
    return (strcmp(str, obj.str) == 0);
}

STRING& STRING::operator = (const STRING& obj) {
    if (this == &obj) {
        return *this;
    }
    delete[] str;
    len = obj.len;
    str = new char[len + 1];
    strcpy(str, obj.str);
    return *this;
}

STRING STRING::operator + (const STRING& obj) const {
    STRING temp;
    temp.len = len + obj.len;
    temp.str = new char[temp.len+1];
    strcpy(temp.str, str);
    strcat(temp.str, " ");
    strcat(temp.str, obj.str);
    return temp;
}

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
