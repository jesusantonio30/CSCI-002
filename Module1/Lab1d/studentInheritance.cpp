#include <iostream>
#include <string>

class Person {
    private:
        std::string firstName, lastName;
        int age;

    public:
        Person(std::string argFN = "John", std::string argLN = "Doe", int argAge = 20);

        void setFName(std::string argFname);
        void setLName(std::string argLname);
        void setAge(int argAge);

        std::string getFName();
        std::string getLName();
        int getAge();

        virtual void display();
};

class UScitizen : public Person {
    private:
        int SSN;

    public:
        UScitizen(std::string argFN = "Jane", std::string argLN = "Doe", int argAge = 21, int argSSN = 123456789);

        void setSSN(int argSSN);
        int getSSN();

        virtual void display();
};

int main() {

    UScitizen citizen1("Jesus", "Morales", 23, 614738526);
    UScitizen citizen2("Maria", "Gamez", 21, 614768226);
    UScitizen citizen3("Fatima", "Morales", 20, 617338526);

    Person person1("Antonio", "Morales", 65);
    Person person2("Herminia", "Bermudez", 62);

    citizen1.display();
    std::cout << '\n';
    citizen2.display();
    std::cout << '\n';
    citizen3.display();
    std::cout << '\n';
    person1.display();
    std::cout << '\n';
    person2.display();


    return 0;
}

Person::Person(std::string argFN, std::string argLN, int argAge) {
    firstName = argFN;
    lastName = argLN;
    age = argAge;
}

void Person::setFName(std::string argFname) {
    firstName = argFname;
}

void Person::setLName(std::string argLname) {
    lastName = argLname;
}

void Person::setAge(int argAge) {
    age = argAge;
}


std::string Person::getFName() {
    return firstName;
}

std::string Person::getLName() {
    return lastName;
}

int Person::getAge() {
    return age;
}


void Person::display() {
    std::cout << "First Name: " << getFName() << std::endl;
    std::cout << "Last Name: " << getLName() << std::endl;
    std::cout << "Age: " << getAge() << std::endl;
}

UScitizen::UScitizen(std::string argFN, std::string argLN, int argAge, int argSSN):Person(argFN, argLN, argAge) {
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
    std::cout << "SSN: " << getSSN() << std::endl;
}

