#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Person {
    private:
        string firstName, lastName;
        int age;

    public:
        Person(string argFN, string argLN, int argAge) : firstName(argFN), lastName(argLN), age(argAge) {}

        string getFName();
        string getLName();
        int getAge();
};

class Student : public Person {
    private:
        int ID;

    public:
        Student(string argFN, string argLN, int argAge, int argID) : Person(argFN, argLN, argAge), ID(argID) {}
        int getID();
};

int main() {

    srand(time(0));

    map<int, Student> studentMap;
    char searchAgain = 'n';
    vector<string> fNames = {"Jesus", "Maria", "Fatima", "Gustavo", "Jose"};


    for (int i = 0; i < 5; ++i) {
        string randName = fNames[rand() % fNames.size()];
        int randAge = 18 + (rand() % 18);

        Student stud(randName, "Morales", randAge, i);

        studentMap.emplace(i, stud);
    }


    do {
        
        int ID = 0;

        cout << "\nSearch ID: ";
        cin >> ID;

        map<int, Student>::iterator found = studentMap.find(ID);


        cout << "-------------- STUDENT --------------\n";
        if (found != studentMap.end()) {
            cout << "\nID: " << found->first << endl;
            cout << "Name: " << found->second.getFName() << ' ' << found->second.getLName() << endl;
            cout << "Age: " << found->second.getAge() << endl;
        } 

        else cout << "\nNot in database!\n";

        cout << "\nSearch again? (y/n): ";
        cin >> searchAgain;

        cin.ignore();

    } while (tolower(searchAgain) == 'y');

    return 0;
}

string Person::getFName() {
    return firstName;
}

string Person::getLName() {
    return lastName;
}

int Person::getAge() {
    return age;
}

int Student::getID() {
    return ID;
}
