#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>
#include <list>
#include <vector>
#include <cstdlib>

using namespace std;

class Shape {
    private:
        string color;
    public:
        Shape(string argCol) { this->setColor(argCol); }
        virtual ~Shape() = default;

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
            //cout << "Constructor called!\n";
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

int hashFunc(Polygon* poly);
bool listComparator(Polygon* polyA, Polygon* polyB);
void printTable(list<Polygon*> tableArg[], const int size);

int main() {
    srand(time(0));

    const int size  = 11;
    list<Polygon*> table[size];
    vector<string> colors = {"red", "green", "blue", "yellow", "black", "orange", "purple"};

    for (int i = 0; i < 100; i++) {

        string polyColor = colors[rand() % colors.size()];
        int sides = 3 + rand() % 8;
        float sideLen = 0.5 + 49.5 * (1.0 * rand() / RAND_MAX);


        Polygon * y = nullptr;
        try {
            y = new Polygon(polyColor, sides, sideLen);
            int index = hashFunc(y);
            table[index].push_back(y);
            table[index].sort(listComparator);
        } catch (const runtime_error& err) {
            cout << "Error: " << err.what() << endl;
        }

    }

    printTable(table, size);

    for (list<Polygon*> bucket : table) {
        for (Polygon* node : bucket) {
            delete node;
        }
    }

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

int hashFunc(Polygon* poly) {
    return poly->getNumSides();
}

bool listComparator(Polygon* polyA, Polygon* polyB) {
    return polyA->getSideLen() < polyB->getSideLen();
}

void printTable(list<Polygon*> tableArg[], const int size) {
    list<Polygon*>::iterator itr;

    for (int i = 0; i < size; i++) {
        cout << "Bucket " << i << ": ";
        for (itr = tableArg[i].begin(); itr != tableArg[i].end(); itr++) {
            cout << "Polygon: " << (*itr)->getSideLen() << " ";
        }
        cout << endl;
    }
}