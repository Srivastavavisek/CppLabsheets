// To write a C++ program to manipulate complex numbers using operator
// overloading. (addition,subtraction,multiplication,division)

#include<iostream>
#include<iomanip>
using namespace std;

class Complex
{
private:
    float real, imag;

public:
    Complex(float r = 0.0, float i = 0.0): real(r), imag(i) {}
    Complex(const Complex& c): real(c.real), imag(c.imag) {}

    void input(){
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    void output() const {
        if (imag < 0)
            cout << "\t" << real << " - " << -imag << "i" << endl;
        else
            cout << "\t" << real << " + " << imag << "i" << endl;

    }

    Complex operator + (const Complex&) const;
    Complex operator - (const Complex&) const;
    Complex operator * (const Complex&) const;
    Complex operator / (const Complex&) const;
};

Complex Complex::operator + (const Complex& c) const {
    return Complex(real + c.real, imag + c.imag);
}
Complex Complex::operator - (const Complex& c) const {
    return Complex(real - c.real, imag - c.imag);
}
Complex Complex::operator * (const Complex& c) const {
    return Complex((real * c.real) - (imag * c.imag), real * c.imag + imag * c.real);
}
Complex Complex::operator / (const Complex& c) const {
    float denominator = c.real * c.real + c.imag * c.imag;
    float t_real = (real * c.real + imag * c.imag) / denominator;
    float t_imag = (imag * c.real - real * c.imag) / denominator;
    return Complex(t_real, t_imag);
}

int main()
{
    Complex c1, c2, c3, c4, c5, c6;
    cout << "Enter first number: " << endl;
    c1.input();
    cout << "Enter second number: " << endl;
    c2.input();

    c3 = c1 + c2;
    c4 = c1 - c2;
    c5 = c1 * c2;
    c6 = c1 / c2;

    cout << "Sum:\t";
    c3.output();

    cout << "Difference:";
    c4.output();

    cout << "Product:";
    c5.output();

    cout << "Quotient:";
    c6.output();

    return 0;
}
