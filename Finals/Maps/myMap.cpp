#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Employee {
    string name;
    int ID;

    Employee(string arg1, int arg2) {
        name = arg1;
        ID = arg2;
    }
};

void print(const vector<Employee*>& vec);

int main() {

    map<string, vector<Employee*>> categoryMap;

    // Add the keys to the empty map
    categoryMap["project manager"];
    categoryMap["programmer"];
    categoryMap["support staff"];


    // Construct the Employee object in-place of it's vector
        // Hard Code 3 elements per vector
        categoryMap["project manager"].emplace_back(new Employee("Jesus Morales", 00001));
        categoryMap["project manager"].emplace_back(new Employee("Gustavo Garcia", 00002));
        categoryMap["project manager"].emplace_back(new Employee("Maria Gamez", 00003));

        categoryMap["programmer"].emplace_back(new Employee("Joel Barajas", 12345));
        categoryMap["programmer"].emplace_back(new Employee("Candi Plascencia", 23456));
        categoryMap["programmer"].emplace_back(new Employee("Chente Pena", 34567));

        categoryMap["support staff"].emplace_back(new Employee("Frijol", 45678));
        categoryMap["support staff"].emplace_back(new Employee("Oso", 56789));
        categoryMap["support staff"].emplace_back(new Employee("Verizon", 67890));


        // UI
        int userChoice = 0;

        cout << "\t--- Employee Selection ---\n";
        cout << "\n1.) Project Manager\n";
        cout << "2.) Programmer\n";
        cout << "3.) Support Staff\n";

        cout << "\nSelect Employee (e.g. 1): ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                print(categoryMap["project manager"]);
                break;
            case 2:
                print(categoryMap["programmer"]);
                break;
            case 3:
                print(categoryMap["support staff"]);
                break;
            default:
                cout << "Not a valid choice.\n";
                break;
        }

        // Clean Up
        for (map<string, vector<Employee*>>::iterator itr = categoryMap.begin() ; itr != categoryMap.end(); itr++) {
            for (Employee* emp : itr->second) {
                delete emp;
            }
        }



    return 0;
}

void print(const vector<Employee*>& vec) {
    for (Employee* emp : vec) {
        cout << "\nName: " << emp->name << endl;
        cout << "ID: " << emp->ID << endl;
    }
}