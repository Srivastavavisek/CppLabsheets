// To write a C++ program to swap two private data members using friend functions.

#include<iostream>

using namespace std;

class B;

class A{
    int a;
public:
    A(int a) { this->a = a; }
    void display() const {
        cout << "A: " << a << endl;
    }

    friend void swap(A &, B &);
};

class B{
    int b;
public:
    B(int b) { this->b = b; }
    void display() const {
        cout << "B: " << b << endl;
    }

    friend void swap(A &, B &);
};

void swap(A &aobj, B &bobj){
    int temp = aobj.a;
    aobj.a = bobj.b;
    bobj.b = temp;
}

int main(){
    A objA(10);
    B objB(20);

    cout << "Before swap:" << endl;
    objA.display();
    objB.display();

    swap(objA, objB);

    cout << "After swap:" << endl;
    objA.display();
    objB.display();

    return 0;
}