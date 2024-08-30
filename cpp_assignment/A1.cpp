// Create a class person with name and date of birth as data members. Ask the user to
// enter a date of birth and print all persons name with a matched date of birth.

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Person;

class Date
{
private:
    int yy, mm, dd;
public:
    Date() : yy(0), mm(0), dd(0) {}

    void getInput() {
        scanf("%d-%d-%d", &yy, &mm, &dd);
    }

    bool operator == (Date d) const {
        return(yy == d.yy && mm == d.mm && dd == d.dd);
    }

    // friend bool compare(const Person& person, const Date& date);

};

class Person
{
    string name;
    Date dob;
public:
    // Person() : name(""), dob(Date()) {}

    void getInput() {
        cout << "Enter name: " << endl;
        cin.ignore();
        getline(cin, name);
        cout << "Enter date of birth (YYYY-MM-DD): ";
        dob.getInput();
    }

    void show() {
        cout << name << endl;
    }

    friend bool compare(const Person& person, const Date& date);
};

bool compare(const Person& person, const Date& date) {
    return (date == person.dob);
}


int main()
{
    int n;
    cout << "Enter number of people: ";
    cin >> n;
    Person *person = new Person[n];
    Date dob;

    cout << "Enter data: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Person" << i+1 << endl;
        person[i].getInput();
    }

    cout << "Enter date of birth to match with other datas: ";
    dob.getInput();

    cout << "\nPeople with Matching DOB:" << endl;
    for (int i = 0; i < n; i++) {
        if (compare(person[i], dob))
            person[i].show();
    }

    delete[] person;

    return 0;
}