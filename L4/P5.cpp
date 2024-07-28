// a)
// Write a main () function that creates an instance object of Auto called Car, which has the
// following initial data: there is a quantity of five(5) on inventory, and two(2) on reorder;
// the price per unit is $15,545.91, and the description is that of the car obtained from the
// Toyota. Initialize the object Car, and print out all its vital facts.

// b) 
// A Transmission is purchased from Aztec Inc., and must be inventoried. There are 25 of
// them, with 10 more on reorder. Their price is $1789.98. Instantiate and initialize an
// object for Transmission, and provide the same information


#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Inventory {
private:
    int quant;     // number on hand
    int reorder;   // reorder quantity
    double price;  // price per unit
    char *descrip; // description of item

public:
    Inventory(): quant(0), reorder(0), price(0.0), descrip(nullptr) {}

    Inventory(int q, int r, double p, char *d) : quant(q), reorder(r), price(p){
        descrip = new char[strlen(d) + 1];
        strcpy(descrip, d);
    }

    virtual ~Inventory(){
        delete[] descrip;
    };

    void print(){
        cout<< "Quantity: " << quant << endl;
        cout << "Reorder: " << reorder << endl;
        cout << "Price: " << price << endl;
        cout << "Description: " << descrip << endl;
    }
};

class Auto : public Inventory {
private:
    char* manufacturer;
public:
    Auto (int q, int r, double p, char* d, char* m) : Inventory(q, r ,p, d){
        manufacturer = new char[strlen(m) + 1];
        strcpy(manufacturer, m);
    }

    ~Auto(){
        delete[] manufacturer;
    }

    void print(){
        Inventory::print();
        cout << "Manufacturer: " << manufacturer << endl;
    }
};

class Transmission : public Inventory {
private:
    char* vendor;
public:
    Transmission (int q, int r, double p, char* d, char* v) : Inventory(q, r, p, d){
        vendor = new char[strlen(v) + 1];
        strcpy(vendor, v);
    }

    ~ Transmission(){
        delete[] vendor;
    }

    void print(){
        Inventory :: print();
        cout << endl << "Vendor: " << vendor << endl;
    };
};

int main(){
    char description[] = "Obtained from toyota";
    char manufacturer[] = "Toyota";
    Auto car(5, 2, 15545.91, description, manufacturer);
    car.print();

    char description2[] = "Purchased from Aztec Inc.";
    char ven[] = "Aztec Inc.";
    Transmission trans(25, 10, 1789.98 , description2, ven);
    trans.print();

    return 0;
}