#include <iostream> 
using namespace std;

struct Point {
    double x, y;

    void displayPoints(Point* arg) {
        cout << "(" << this->x << "," << this->y << ")" << endl;
        cout << "(" << arg->x << "," << arg->y << ")" << endl;
    }
};

int main() {

    Point a, b;

    a.x = 3.5;
    a.y = -6.8;
    b.x = -2;
    b.y = -5;

    a.displayPoints(&b);

    return(0);
}