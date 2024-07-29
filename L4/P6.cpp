#include <iostream>
#include <cstring>

#define sz 50

using namespace std;

class Student {
private:
    char name[sz];
    int rn;

public:
    void getData() {
        cout << "Enter student roll no.: ";
        cin >> rn;
        cout << "Enter student name: ";
        cin >> name;
    }

    void display() const {
        cout << "\nName:\t" << name << "\nRoll number:\t" << rn << endl;
    }
};

class InternalExam : virtual public Student {
protected:
    float m[7];

public:
    void getExamData() {
        cout << "Enter the marks student got in 7 subjects in internal exam: " << endl;
        for (int i = 0; i < 7; i++) {
            cin >> m[i];
        }
    }

    void displayExamData() const {
        cout << "Internal Exam Marks: " << endl << "\t";
        for (int i = 0; i < 7; i++) {
            cout << m[i] << "\t";
        }
        cout << endl;
    }
};

class FinalExam : virtual public Student {
protected:
    float m[7];

public:
    void getExamData() {
        cout << "Enter the marks student got in 7 subjects in final exam: " << endl;
        for (int i = 0; i < 7; i++) {
            cin >> m[i];
        }
    }

    void displayExamData() const {
        cout << "Final Exam Marks: " << endl << "\t";
        for (int i = 0; i < 7; i++) {
            cout << m[i] << "\t";
        }
        cout << endl;
    }
};

class AverageMarks : public InternalExam, public FinalExam {
    float avgmarks;

public:
    void calculateAverage() {
        float sum = 0.0f;
        for (int i = 0; i < 7; ++i) {
            sum += (InternalExam::m[i] + FinalExam::m[i]);
        }
        avgmarks = sum / 14.0;
    }

    void getAllData() {
        Student::getData();
        InternalExam::getExamData();
        FinalExam::getExamData();
    }

    void displayAllData() {
        Student::display();
        InternalExam::displayExamData();
        FinalExam::displayExamData();
        cout << "Average Marks: " << avgmarks << endl;
    }
};

int main() {
    AverageMarks avg;

    avg.getAllData();
    avg.calculateAverage();
    avg.displayAllData();

    return 0;
}
