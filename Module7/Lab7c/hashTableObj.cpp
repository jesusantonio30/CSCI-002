#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Person {
    public:
        string name;
        string gender;
        int age;

        Person(string argName, string argGender, int argAge) : name(argName), gender(argGender), age(argAge) {}
};

class Student : public Person {
    public:
        int id;

        Student(string argName, string argGender, int argAge, int argID) : Person(argName, argGender, argAge), id(argID) {}
        
        void printDetails();
};

int stringToIndexHash(string userName, int buckets);
bool nameComparator(Student* studA, Student* studB);
Student* searchName(string argName, list<Student*> table[], int tableSize);

int main() {

    srand(time(0));

    constexpr int buckets = 5;
    list<Student*> myTable[buckets];
    vector<string> names = {"Jesus", "Maria", "Jose", "Gustavo", "Candi", "Joel", "Fatima", "Goylan", "Chente", "Jay"};

    for (int i = 0; i < 20; i++) {

        string name = names[rand() % names.size()];
        int gender = rand() % 2;
        int age = 18 + (rand() % 48);
        int id = 10000 + (rand() % 90000);
        int index = stringToIndexHash(name, buckets);

        Student* stud = new Student(name, gender ? "Female" : "Male", age, id);

        myTable[index].push_back(stud);
        myTable[index].sort(nameComparator);
    }

    cout << "\n---------------- Student Database ----------------\n";
    
    for (list<Student*> list : myTable) {
        for (Student* stud : list) {
            cout << endl;
            stud->printDetails();
        }
    }

    // This name doesn't exist
    string johnDoe = "Carlos";

    // This name does exist
    string student = myTable[0].front()->name;

    cout << "\n---------------- Search Method Usage ----------------\n";

    cout << "\n\t******* This Name Doesn't Exist *******\n";
    cout << "Name: " << johnDoe << endl;
    (searchName(johnDoe, myTable, buckets) == nullptr) ? (cout << "--Not In Database--\n") : (cout << "--In Database--\n");

    cout << "\n\t******* This Name Does Exist *******\n";
    cout << "Name: " << student << endl;

    Student* found = searchName(student, myTable, buckets);
    if (found != nullptr) {
        cout << "--In Database--\n";
        found->printDetails();
    } else 
        cout << "--Not In Database--\n";


    for (list<Student*> list : myTable) {
        for (Student* stud : list) {
            delete stud;
        }
    }

    return 0;
}

int stringToIndexHash(string userName, int buckets) {
    int sum = 0;

    for (int i = 0; i < userName.size(); i++) {
        sum += int(userName[i]);
    }

    return sum % buckets;
}

bool nameComparator(Student* studA, Student* studB) {
    return studA->name < studB->name;
}

void Student::printDetails() {
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "Age: " << age << endl;
    cout << "ID: " << id << endl;
}

Student* searchName(string argName, list<Student*> table[], int tableSize) {
    int index = stringToIndexHash(argName, tableSize);

    for (Student* stud : table[index]) {
        if (stud->name == argName)
            return stud;
    }


    return nullptr;
}