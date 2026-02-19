#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Circle {
    string color;
    float radius;

    Circle(float argRad, string argColor) : radius(argRad), color(argColor) {}
};

bool compareRadius(Circle* arg1, Circle* arg2);
bool compareColor(Circle* arg1, Circle* arg2);
void display(list<Circle*> argList);

int main() {

    srand(time(0));

    list<Circle*> myCircs;
    vector<string> colors = {"red", "green", "blue", "yellow", "orange"};

    for (int i = 0; i < 5; ++i) {
        myCircs.push_back(new Circle(1.0 * rand()/RAND_MAX, colors[rand() % colors.size()]));
    }

    cout << "----------------- Normal Random Generated List -----------------\n";
    display(myCircs);

    cout << "----------------- Compared by Radius List -----------------\n";
    myCircs.sort(compareRadius);
    display(myCircs);

    cout << "----------------- Compared by Color List -----------------\n";
    myCircs.sort(compareColor);
    display(myCircs);
    

    return 0;
}

bool compareRadius(Circle* arg1, Circle* arg2) {
    return arg1->radius < arg2->radius;
}

bool compareColor(Circle* arg1, Circle* arg2) {
    return arg1->color < arg2->color;
}

void display(list<Circle*> argList) {
    list<Circle*>::iterator it = argList.begin();

    while (it != argList.end()) {
        cout << "Color: " << (*it)->color << endl;
        cout << "Radius: " << (*it)->radius << endl;
        it++;
    }
}
