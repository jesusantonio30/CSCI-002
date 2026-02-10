#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Person {
    private:
        string firstName, lastName;
        int age;

    public:
        Person(string argFN = "John", string argLN = "Doe", int argAge = 20);

        void setFName(string argFname);
        void setLName(string argLname);
        void setAge(int argAge);

        string getFName();
        string getLName();
        int getAge();

        virtual void display();
};

class UScitizen : public Person {
    private:
        int SSN;

    public:
        UScitizen(string argFN = "Jane", string argLN = "Doe", int argAge = 21, int argSSN = 123456789);

        void setSSN(int argSSN);
        int getSSN();

        virtual void display();
};

class Employee : public UScitizen {
    private:
        int employeeID;
        float salary;

    public:
        Employee(string argFN = "Jane", string argLN = "Doe", int argAge = 21, int argSSN = 123456789, int argEmployeeID = 99999, float argComp = 100000.00);

        void setEmployeeID(int argID);
        int getEmployeeID();

        void setSalary(float argComp);
        float getSalary();

        virtual void display();
};

int main() {

    srand(time(0));

    vector<string> fNames = {"Jesus", "Maria", "Fatima", "Gustavo", "Candi", "Joel", "Dylan"};
    vector<string> lName = {"Morales", "Gamez", "Rodriguez", "Barajas", "Plasencia", "Garcia"};

    list<Employee*> employeeNames;
    list<Employee*>::iterator it;


    for (int i = 0; i < 300; ++i) {

        string randFName = fNames[rand() % fNames.size()];
        string randLName = lName[rand() % lName.size()];
        int randAge = 18 + rand() % 30;
        int randSS = 600000000 + rand() % 100000000;
        int randID = 10000 + rand() % 9999;
        float randSalary = 50000 + rand() % 950000;


        Employee* employee = new Employee(randFName, randLName, randAge, randSS, randID, randSalary);
        employeeNames.push_back(employee);
    }

    int i = 1;
    for (list<Employee*>::iterator it = employeeNames.begin(); it != employeeNames.end(); it++ ) {

        cout << "-----------------------\n";
        cout << "Employee " << i++ << endl;
        (*it)->display();
        cout << "-----------------------\n";
    }

    for (Employee* emp : employeeNames) {
        delete emp;
    }

    while (!employeeNames.empty()) {
        employeeNames.pop_front();
    }

    return 0;
}

// PERSON ----------------------------------------------------------------------------------------
Person::Person(string argFN, string argLN, int argAge) {
    firstName = argFN;
    lastName = argLN;
    age = argAge;
}

void Person::setFName(string argFname) {
    firstName = argFname;
}

void Person::setLName(string argLname) {
    lastName = argLname;
}

void Person::setAge(int argAge) {
    age = argAge;
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


void Person::display() {
    cout << "First Name: " << getFName() << endl;
    cout << "Last Name: " << getLName() << endl;
    cout << "Age: " << getAge() << endl;
}

// USCITIZEN ----------------------------------------------------------------------------------------
UScitizen::UScitizen(string argFN, string argLN, int argAge, int argSSN):Person(argFN, argLN, argAge) {
    setSSN(argSSN);
}

void UScitizen::setSSN(int argSSN) {
    SSN = argSSN;
}

int UScitizen::getSSN() {
    return SSN;
}

void UScitizen::display() {
    Person::display();
    cout << "SSN: " << getSSN() << endl;
}

// EMPLOYEE ----------------------------------------------------------------------------------------
Employee::Employee(string argFN, string argLN, int argAge, int argSSN, int argEmployeeID, float argComp):UScitizen(argFN, argLN, argAge, argSSN) {
    setEmployeeID(argEmployeeID);
    setSalary(argComp);
}

void Employee::setEmployeeID(int argID) {
    employeeID = argID;
}

int Employee::getEmployeeID() {
    return employeeID;
}

void Employee::setSalary(float argComp) {
    salary = argComp;
}

float Employee::getSalary() {
    return salary;
}

void Employee::display() {
    UScitizen::display();
    cout << "Employee ID: " << getEmployeeID() << endl;
    cout << "Salary: " << getSalary() << endl;
}
