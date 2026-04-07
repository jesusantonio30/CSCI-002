#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;

struct Person {
    string name;
    int age;
    bool gender;

    Person(string argName, int argAge, bool argGender) : name(argName), age(argAge), gender(argGender) {}
};

bool compareAge (Person* personA, Person* personB);

int main() {

    char runAgain = 'n';

    list<Person*> personList;

    do {

        string userName = " ";
        int userAge = 0;
        bool userGender;

        cout << "\nEnter Name (e.g. John Doe):  ";
        getline(cin, userName);

        cout << "\nEnter Age: ";
        cin >> userAge;

        cout << "\nEnter '0' if Male or '1' if Female: ";
        cin >> userGender;

        personList.emplace_back(new Person(userName, userAge, userGender));

        personList.sort(compareAge);

        cout << "\nEnter another person? (y/n): ";
        cin >> runAgain;

        cin.ignore();

    } while (tolower(runAgain) == 'y');

    ofstream myPplFile;

    myPplFile.open("persons.csv");

    for (Person* person : personList) {
        myPplFile << person->name << ", ";
        myPplFile << person->age << ", ";
        myPplFile << (person->gender ? "Female\n" : "Male\n");
    }

    myPplFile.close();


    ifstream readMyPpl;
    vector<string> myVec;

    readMyPpl.open("persons.csv");

    string line;

    cout << "\n---------------------- File Contents ----------------------\n";

    while (!readMyPpl.eof()) {
        getline(readMyPpl, line);

        myVec.push_back(line);
    }

    for (string myLine : myVec) {
        cout << myLine << endl;
    }

    readMyPpl.close();

    for (Person* person : personList) {
        delete person;
    }


    return 0;
}

bool compareAge (Person* personA, Person* personB) {
    return personA->age < personB->age;
}