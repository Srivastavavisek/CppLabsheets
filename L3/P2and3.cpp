// Program to convert Polar Coordinate to Cartesian.
// Program to convert Cartesian coordinate to Polar.

#include <iostream>
#include <cmath>
#include <cstdio>
#include <stdlib.h>

#ifdef _WIN32
    #define CLS_CMD "cls"
#else
    #define CLS_CMD "clear"
#endif

#define PI 3.141592

class Polar;

class Cartesian {
private:
    float x, y;
public:
    Cartesian(): x(0.0f), y(0.0f) {}
    Cartesian(float x, float y) {
        this->x = x;
        this->y = y;
    }
    
    void displayRect() {
        printf("Cartesian Coords: (x, y) =  (%.2f, %.2f)\n", x, y);
    }

    void inputRect() {
        std::cout << "Enter x, y: " << std::endl;
        std::cin >> x >> y;
    }

    operator Polar();
};

class Polar {
private:
    float radius, theta;
public:
    Polar(): radius(0.0f), theta(0.0f) {}
    Polar(float r, float t): radius(r), theta(t) {}

    void inputPolar() {
        std::cout << "Enter radius, theta(in degrees): " << std::endl;
        std::cin >> radius >> theta;
    }

    void displayPolar() {
        printf("Polar Coords: (r, theta) =  (%.2f, %.2f)\n", radius, theta);
    }

    operator Cartesian();
};

Cartesian::operator Polar() {
    float r = static_cast<float>(sqrt(x*x + y*y));
    float t = static_cast<float>(atan(y/x)) * (180 / PI);
    return Polar(r, t);
}

Polar::operator Cartesian() {
    float rad = theta * (PI / 180);
    float x1 = radius * cos(rad);
    float y1 = radius * sin(rad);
    return Cartesian(x1, y1);
}

int main() {
    int ch;
    // rect(13, 45) = polar(46.84,73.74).

    Polar polar2;
    Cartesian rect2;

    do {
        system(CLS_CMD);
        std::cout << std::endl << "1.Polar to Cartesian\n2.Cartesian to Polar\n3.Exit\nEnter Choice: ";
        std::cin >> ch;

        switch(ch) {
            case 1:
                polar2.inputPolar();
                rect2 = polar2;
                rect2.displayRect();
                std::cin.ignore();
                std::cin.get();
                break;

            case 2:
                rect2.inputRect();
                polar2 = rect2;
                polar2.displayPolar();
                std::cin.ignore();
                std::cin.get();
                break;

            default:
                break;
        }
    } while(ch != 3);

    return 0;
}
