/*
Create a class publication that stores the title and price of a
publication. From this class derive two classes:book, which adds a
page count and tape, which adds a playing time in minutes. Each of
these three classes should have getdata() function to get its data
from the user at the keyboard and putdata() function to display its
data.
*/

#include<iostream>

using namespace std;

class Publication{
protected:
    string title;
    float price;

public:
    virtual void getData(){
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }
    virtual void putData(){
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

    void displayPublication() {
        getData();
        cout << endl << "Publication details:" << endl;
        putData();
        cout << endl;
    }

    // virtual ~Publication() {}
};

class Book : public Publication {
private:
    int pageCount;

public:
    void getData() {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void putData(){
        Publication::putData();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    int playingTime;

public:
    void getData(){
        Publication::getData();
        cout << "Enter the playing time (in minutes): ";
        cin >> playingTime;
    }
    void putData(){
        Publication :: putData();
        cout << "Playing time (in minutes): " << playingTime << endl;
    }
};

int main(){
    Book book;
    Tape tape;

    cout << "Enter book details:" << endl;
    book.displayPublication();

    cout << "Enter tape details:" << endl;
    tape.displayPublication();

    return 0; 
}