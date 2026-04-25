#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Employee {
    private:
        string
        name,
        department;
        int id;

    public:
        Employee(string name, string depo, int id);
        void setName(string name);
        string getName() const;
        void setDepo(string depo);
        string getDepo() const;
        void setID(int id);
        int getID() const;
        void print() const;
};

int hashFunc(const Employee& emp);
bool empComparator(const Employee& emp1, const Employee& emp2);

int main() {

    srand(time(0));

    const int bucketSize = 5;
    list<Employee> employeeTable[bucketSize];

    int numOfEmploys = 50;
    vector<Employee> employees;
    vector<string> names = {"Jesus", "Maria", "Jose", "Gustavo", "Fatima", "Joel", "Candi", "Jay"};
    vector<string> depos = {"retail", "online", "shipping", "warehouse", "delivery"};

    for (int i = 0; i < numOfEmploys; i++) {
        Employee emp(names[rand() % names.size()], depos[rand() % depos.size()], i);
        int index = hashFunc(emp);
        if (index != -1)
            employeeTable[index].push_back(emp);
    }

    for (int i = 0; i < bucketSize; i++) {
        employeeTable[i].sort(empComparator);
    }

    for (int i = 0; i < bucketSize; i++) {
        cout << "\n\n==========================\n";
        cout << "\t\tBucket " << i << endl;
        cout << "==========================\n\n";
        
        for (list<Employee>::iterator itr = employeeTable[i].begin(); itr != employeeTable[i].end(); itr++) {
            cout << '\n';
            itr->print();
        }
    }
    
    return 0;
}


Employee::Employee(string name, string depo, int id) {
    setName(name);
    setDepo(depo);
    setID(id);
}

void Employee::setName(string name) {
    this->name = name;
}

string Employee::getName() const {
    return this->name;
}

void Employee::setDepo(string depo) {
    this->department = depo;
}

string Employee::getDepo() const {
    return this->department;
}

void Employee::setID(int id) {
    this->id = id;
}

int Employee::getID() const {
    return this->id;
}

void Employee::print() const {
    cout << "Name: " << getName() << endl;
    cout << "ID: " << getID() << endl;
    cout << "Department: " << getDepo() << endl;
}

int hashFunc(const Employee& emp) {
    const int size = 5;
    static const string depo[size] =  {"retail", "online", "shipping", "warehouse", "delivery"};

    for (int i = 0; i < size; i++) {
        if (depo[i] == emp.getDepo())
            return i;
    }

    return -1;
}

bool empComparator(const Employee& emp1, const Employee& emp2) {
    return emp1.getID() < emp2.getID();
}