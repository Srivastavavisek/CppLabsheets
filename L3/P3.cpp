// Program to convert Polar Coordinate to Cartesian.

#include <iostream>
#include <cmath>

#define PI 3.141592

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
    polar2.inputPolar();
    rect2 = polar2;
    rect2.displayRect();
                
    return 0;
}
