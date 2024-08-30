// Design a class Employee with id, name, and salary as data members. Implement
// functions to input employee data and display employees who have a salary greater
// than a user-specified amount.

#include <iostream>
#include <iomanip>
using namespace std;

class ThresholdSalary
{
private:
    unsigned int threshold;
public:
    void inputThreshold() {
        cout << "Enter threshold salary: ";
        cin >> threshold;
    }

    unsigned int getThreshold() const {
        return threshold;
    }
};

class Employee
{
private:
    int id;
    string name;
    unsigned int salary;

public:
    unsigned int getSalary() const {
        return salary;
    }
    void inputData() {
        // cout << "Enter Data:" << endl;
        cout << "Id: ";
        cin >> id;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name); 
        cout << "Salary: ";
        cin >> salary;
    }

    void showData() const {
        cout << setw(15) << left << id 
            << setw(15) << left << name 
            << setw(15) << left << salary << endl;
    }

    bool operator > (const ThresholdSalary& sal) const {
        return (salary > sal.getThreshold());
    }
};


int main() {
    int n;
    cout << "Enter number of employee: ";
    cin >> n;
    Employee *emp = new Employee[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter data of employee_" << i+1 << endl;
        emp[i].inputData();
    }

    ThresholdSalary T_sal;
    T_sal.inputThreshold();

    cout << "\nEmployees whose salary is greater than " << T_sal.getThreshold() << endl;
    cout << setw(15) << left << "Id" 
            << setw(15) << left << "Name" 
            << setw(15) << left << "Salary" << endl;
    
    for (int i = 0; i < n; i++) 
    {
        if (emp[i] > T_sal)
            emp[i].showData();
    }

    delete[] emp;

    return 0;
}