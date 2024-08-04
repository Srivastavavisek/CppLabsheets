
    // Assume class person stores the Name, Age and ID, class employee
    // stores the designation, basic salary, total overtime(hr) in a month
    // and hourly rate and class computedSalary stores the total salary of
    // the employee. Implement above concept using appropriate inheritance


#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    int id;

public:
    // Person(string n, int a, int i) : name(n), age(a), id(i) {}

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter id: ";
        cin >> id;
    }

    void displayInfo() {
        cout << "Name: " << name << endl
        << "Age: " << age << endl
        << "ID: " << id << endl;
    }
};

class Employee : public Person
{
private:
    string designation;

protected:
    double basicSal;
    int totalOvertime;
    double hourlyRate;
public:
    void input() {
        Person::input();
        cout << "Enter employee designation: ";
        cin >> designation;
        cout << "Enter the basic salary: ";
        cin >> basicSal;
        cout << "Enter the total overtime in a month in hours: ";
        cin >> totalOvertime;
        cout << "Enter the hourly rate: ";
        cin >> hourlyRate;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Designation: " << designation << endl;
        cout << "Basic Salary: " << basicSal << endl;
    }
};

class ComputedSalary : public Employee
{
private:
    unsigned int totalSal;

public:
    void compute() {
        totalSal = basicSal + totalOvertime * hourlyRate;
    }

    void displayInfo() {
        cout << endl;
        Employee::displayInfo();
        compute();
        cout << "Total Salary: " << totalSal << endl;
    }
};

int main()
{
    ComputedSalary totalSalary;
    totalSalary.input();
    totalSalary.displayInfo();

    return 0;
}
