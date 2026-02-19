#include <iostream>
#include <vector>

using namespace std;

class Person {
    protected:
        string name;
        int age;

    public:
        Person(string argName, int argAge) : name(argName), age(argAge) {}
        virtual ~Person() {}
        virtual void display() = 0;
};

class Student : public Person {
    protected:
        string major;
        float GPA;
    public:
        Student(string argName, int argAge, string argMajor, float argGPA) : Person(argName, argAge), major(argMajor), GPA(argGPA) {}
        void display() override;
};

class Athlete : public Person {
    protected:
        string sport;
        string sportTeam;
    public:
        Athlete(string argName, int argAge, string argSport, string argTeam) : Person(argName, argAge), sport(argSport), sportTeam(argTeam) {}
        void display() override;
};

class Employee : public Person {
    protected:
        float salary;
        string company;
    public:
        Employee(string argName, int argAge, float argSalary, string argCompany) : Person(argName, argAge), salary(argSalary), company(argCompany) {}
        void display() override;
};


int main() {

    vector<Person*> myPeople;

    myPeople.push_back(new Student("Jesus", 23, "Computer Science", 4.0));
    myPeople.push_back(new Athlete("Maria", 21, "Track", "Los Waches"));
    myPeople.push_back(new Employee("Jesus", 23, 80000, "BlueScope"));

    for (int i = 0; i < myPeople.size(); i++) {
        cout << endl;
        (myPeople[i])->display();
    }

    for (int i = 0; i < myPeople.size(); i++) {
        delete myPeople[i];
        myPeople[i] = nullptr;
    }

    return 0;
}

void Student::display() {
    cout << "This is a Student!\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Major: " << major << endl;
    cout << "GPA: " << GPA << endl;
}

void Athlete::display() {
    cout << "This is an Athlete!\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Sport: " << sport << endl;
    cout << "Team: " << sportTeam << endl;
}

void Employee::display() {
    cout << "This is an Employee!\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Company: " << company << endl;
    cout << "Salary: " << salary << endl;
    
}
