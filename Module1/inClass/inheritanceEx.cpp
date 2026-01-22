#include <iostream>
#include <string>
using namespace std;
const double PI = 3.14159;

//Abstract base class shape
class Shape {
private:
 string color;

public:
 Shape(string argColor = "transparent");

 void setColor(string);
 string getColor(void);

 // virtual methods required to be implemented
 virtual double calculatePerimeter() = 0;

 // virtual method has implementation but can be overridden
 virtual void displayInfo(void);

};

class Circle : public Shape { // A circle "is-a" Shape
private:
 double radius;

public:
 Circle(string argColor, double argRadius = 0.0);

 void setRadius(double r);
 double getRadius();

 double calculatePerimeter();
 double calculateDiameter();
 void displayInfo();

};


int main(void) {
 // Task: try to instatiate a Shape object
 // Implement pure virtual area method

 Circle myCircle("blue", 2.5);
 myCircle.displayInfo();

 cout << endl;
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

//Source Circle *********************************
Circle::Circle(string argColor, double argRadius):Shape(argColor){
 //Shape::setColor(argColor); 
 setRadius(argRadius);
}

void Circle::setRadius(double r) {
 //some data validation
 radius = (r <= 0 ? 0 : r);
}

double Circle::getRadius() {
 return radius;
}

double Circle::calculatePerimeter() {
 return 2 * PI * getRadius();
}
double Circle::calculateDiameter() {
 return getRadius() * 2;
}

void Circle::displayInfo() {
 Shape::displayInfo();

 cout << "Circle Properties";
 cout << "Radius = " << getRadius() << " units " << endl;
 cout << "Diameter = " << calculateDiameter() << " units " << endl;
 cout << "Circumference = " << calculatePerimeter() << " units " << endl;

}
