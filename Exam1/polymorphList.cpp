#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>

using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int a, int b) {
        x = a;
        y = b;
    }
    virtual void print() {
        cout << "\nPoint: ";
        cout << "(" << x << "," << y << ")";
    }
    ~Point() {
        cout << "Point Destroyed!" << endl;
    }
};

class Circle : public Point {
private:
    int r;
public:
    Circle(int a, int b, int c) : Point(a, b) {
        r = c;
    }
    virtual void print() {
        cout << "\nCircle: ";
        cout << "center: ";
        Point::print();
        cout << " radius r = " << r;
    }
};

class Cylinder : public Circle {
private:
    int h;
public:
    Cylinder(int a, int b, int c, int d) : Circle(a, b, c) {
        h = d;
    }
    virtual void print() {
        cout << "\nCylinder:";
        Circle::print();
        cout << " height h = " << h;
    }
};

int main() {

    srand(time(0));

    list<Point*> myList;
    int randNum1 = 0,
        randNum2 = 0,
        randNum3 = 0,
        randNum4 = 0,
        randObj = 0;

    for (int i = 0; i < 30; ++i) {
        randObj = rand() % 3;

        switch (randObj) {
            case 0:
                randNum1 = 1 + rand() % 10;
                randNum2 = 1 + rand() % 10;

                myList.push_back(new Point(randNum1, randNum2));
                
                break;

            case 1:
                randNum1 = 1 + rand() % 10;
                randNum2 = 1 + rand() % 10;
                randNum3 = 1 + rand() % 10;

                myList.push_back(new Circle(randNum1, randNum2, randNum3));
                
                break;

            case 2:
                randNum1 = 1 + rand() % 10;
                randNum2 = 1 + rand() % 10;
                randNum3 = 1 + rand() % 10;
                randNum4 = 1 + rand() % 10;

                myList.push_back(new Cylinder(randNum1, randNum2, randNum3, randNum4));
                
                break;
        }
    }



    for (list<Point*>::iterator it = myList.begin(); it != myList.end(); ++it) {

        (*it)->print();
        cout << "\n-----------------------\n";
    }

    for (Point* obj : myList) {
        delete obj;
    }




    return 0;
}