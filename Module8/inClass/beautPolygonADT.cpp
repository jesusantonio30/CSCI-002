#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>

using namespace std;

class Shape {
    private:
        string color;
    public:
        Shape(string argCol) { this->setColor(argCol); }

        string getColor() {return this->color; }
        void setColor(string argCol) { this->color = argCol; }

        virtual void displayProp() = 0;
        virtual double perimeter() = 0;
        virtual double area() = 0;
};


class Polygon: public Shape {
    private:
        int numSides;
        double sideLen;
    public:

        Polygon(string argCol = "Transparent", int argNumSides = 3, double argSideLen = 0) : Shape(argCol) {
            cout << "Constructor called!\n";
            this->setNumSides(argNumSides);
            this->setSideLen(argSideLen);
        }
        ~Polygon();

        int getNumSides();
        void setNumSides(int argNumSides);
        double getSideLen();
        void setSideLen(double argSideLen);

        virtual void displayProp();
        virtual double perimeter();
        virtual double area();
};

int main() {
    Polygon* y = nullptr;
    try {
        y = new Polygon("red", 4, 5);
    } catch (const runtime_error& err) {
        cout << "Error: " << err.what() << endl;
    }

    y->displayProp();
    cout << "Perimeter: " << y->perimeter() << endl;
    cout << "Area: " << y->area() << endl;

    return 0;
}

Polygon::~Polygon() {
    cout << "Destructor called!\n";
}

int Polygon::getNumSides() {
    return this->numSides;
}

void Polygon::setNumSides(int argNumSides) {
    if (argNumSides >= 3)
        this->numSides = argNumSides;
    else 
        throw runtime_error("Number of sides too low.");
}

double Polygon::getSideLen() {
    return this->sideLen;
}

void Polygon::setSideLen(double argSideLen) {
    if (argSideLen >= 0)
        this->sideLen = argSideLen;
    else 
        throw runtime_error("Can't be less than 0.");
}


void Polygon::displayProp() {
    cout << "Number of sides: " << this->getNumSides() << endl;
    cout << "Color: " << this->getColor() << endl; 
}

double Polygon::perimeter() {
    return this->getNumSides() * this->getSideLen();
}

double Polygon::area() {
    const double PI = 3.14159;
    double numSides = this->getNumSides();
    double sideLen = this->getSideLen();
    return ( this->numSides * pow(this->sideLen, 2) ) / ( 4 * tan(PI  / this->numSides) );
}