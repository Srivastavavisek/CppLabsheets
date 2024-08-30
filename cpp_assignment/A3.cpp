// Define a class Library with bookTitle, author, and numberOfCopies as data
// members. Implement methods to add new books, issue books, and return books.
// Ensure that the number of copies is appropriately updated for each operation.

#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

class Library
{
private:
    string bookTitle;
    string author;
    int numberOfCopies;

public:
    void setData()
    {
        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, bookTitle);
        cout << "Enter author name: ";
        cin.ignore();
        getline(cin, author);
        cout << "Enter number of copies: ";
        cin >> numberOfCopies;
    }

    void showData() {
        cout << "Book Title: " << bookTitle << endl;
        cout << "Author: " << author << endl;
        cout << "Number of Copies: " << numberOfCopies << endl;
    }

    void addBook(int n)
    {
        numberOfCopies++;
        cout << "Book added successfully";
    }

    void issueBook() 
    {
        if (numberOfCopies > 0) 
        {
            numberOfCopies--;
            cout << "Book issued successfully!" << endl;
        } 
        
        else
            cout << "Sorry, no copies available." << endl;
    }

    void returnBook() 
    {
        numberOfCopies++;
        cout << "Book returned successfully!" << endl;
    }
};

int main()
{
    Library lib;
    lib.setData();
    int n;
    int ch;
    do
    {
        system(CLEAR);
        cout << "Library Management System: \n" << "1. Add a book\n" << "2. Issue a Book\n" << "3. Return a book\n" << "4. Exit\n\n";
        cin >> ch;
        system(CLEAR);

        switch (ch)
        {
            case 1:
                cout << "ADD BOOK...\n";
                cout << "Enter number of copies: ";
                cin >> n;
                lib.addBook(n);
                break;

            case 2:
                cout << "ISSUE BOOK...\n";
                lib.issueBook();
                break;

            case 3:
                std::cout << "RETURN BOOK...\n";
                lib.returnBook();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
        
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();

    } while (ch != 4);
    return 0;
}