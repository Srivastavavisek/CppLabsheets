
// Modify Q.2 to add base class sales that holds an array of three
// floats so that it can record the dollar sales of a particular
// publication for the last three months. Include getdata() function to
// get three Sales amount from the user and a putdata() function to
// display sales figures. Alter the book and tape classes so they are
// derived from both publication and sales. An object of class book or
// tape should input and output sales data along with its other data.


#include <iostream>
#include <string>

using namespace std;

class Publication{
protected:
    string title;
    float price;

public:
    virtual void getData(){
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }
    virtual void putData(){
        cout << "\tTitle: " << title << endl;
        cout << "\tPrice: " << price << endl;
    }

    void displayPublication() {
        cout << endl << "Publication details:" << endl;
        putData();
        cout << endl;
    }
};

class Sales
{
protected:
    float sales[3];
public:
    Sales() {
        for (int i = 0; i < 3; ++i)
            sales[i] = 0.0f;
    }

    void getData() {
        cout << "Enter the sales of the last three months: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "\tMonths " << i+1 << ": ";
            cin >> sales[i];
        }
        cin.ignore();
    }

    void putData() {
        cout << "\tSales of the last three months: " << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "\t\tMonth " << i+1 << ": $" << sales[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pageCount;

public:
    void getData() {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
        Sales::getData();
    }

    void putData(){
        Publication::putData();
        cout << "\tPage Count: " << pageCount << endl;
        Sales::putData();
    }
};

class Tape : public Publication, public Sales {
private:
    int playingTime;

public:
    void getData(){
        Publication::getData();
        cout << "Enter the playing time (in minutes): ";
        cin >> playingTime;
        Sales::getData();
    }
    void putData(){
        Publication :: putData();
        cout << "\tPlaying time (in minutes): " << playingTime << endl;
        Sales::putData();
    }
};

int main(){
    Book book;
    Tape tape;

    cout << "Enter book details:" << endl;
    book.getData();

    cout << "Enter tape details:" << endl;
    tape.getData();
    
    book.displayPublication();
    tape.displayPublication();

    return 0; 
}
