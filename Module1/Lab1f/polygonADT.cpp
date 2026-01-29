#include <iostream>
#include <string>
using namespace std;

//Abstract base class shape
class Shape {
    private:
        string color;

    public:
        Shape(string argColor = "transparent");

        void setColor(string);
        string getColor(void);

        virtual void displayInfo(void);

};

class Polygon : public Shape {
    private:
        int numSides;
        double sideLengths;
    public:
        Polygon(string argColor = "red", int argNumSides = 3, double argSideLength = 10);

        void setNumSides(int argNumSides);
        double getNumSides();

        void setSideLengths(double argSideLength);
        double getSideLengths();

        double calculatePerimeter();

        virtual void displayInfo();
};

const double PI = 3.14159;


int main() {
    
    Polygon myTri("Green", 3, 5.0);
    myTri.displayInfo();
    cout << '\n';
    
    Polygon myPent("Blue", 5, 4.5);
    myPent.displayInfo();
    cout << '\n';

    Polygon myOcto("Grey", 8, 3.2);
    myOcto.displayInfo();
    cout << '\n';


    return(0);
}

// Source Shape *************
Shape::Shape(string argColor) {
    setColor(argColor);
}
void Shape::setColor(string arg) {
    color = arg;
}
string Shape::getColor(void) {
    return(color);
}
void Shape::displayInfo(void) {
    cout << "Color: " << getColor() << endl;
}

// Polygon ************************************
Polygon::Polygon(string argColor, int argNumSides, double argSideLength):Shape(argColor) {
    setNumSides(argNumSides);
    setSideLengths(argSideLength);
}

void Polygon::setNumSides(int argNumSides) {
    if (argNumSides >= 3) numSides = argNumSides;
    
}

double Polygon::getNumSides() {
    return numSides;
}

void Polygon::setSideLengths(double argSideLength) {
    if (argSideLength > 0) sideLengths = argSideLength;
}

double Polygon::getSideLengths() {
    return sideLengths;
}  

double Polygon::calculatePerimeter() {
    return getSideLengths() * getNumSides();
}


void Polygon::displayInfo() {
    Shape::displayInfo();
    cout << "Polygon Properties: \n";
    cout << "  Number of sides: " << getNumSides() << endl;
    cout << "  Side length: " << getSideLengths() << " units" << endl;
    cout << "  Perimeter: " << calculatePerimeter() << " units" << endl;
}

