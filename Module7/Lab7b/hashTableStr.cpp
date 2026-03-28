#include <iostream>
#include <string>
#include <list>

using namespace std;

int stringToIndexHash(string userName, int buckets);
void printTable(list<string> arg[], const int size);

int main() {

    string userStr = "jesus";

    const int size = 3;
    list<string> a[size]; // hash table with nun in it
    int index = 0;

    while (true) {
        cout << "\nEnter a string: ";
        getline(cin, userStr);

        if (userStr == "")
            break;

        index = stringToIndexHash(userStr, size);
        a[index].push_back(userStr);
        a[index].sort();

        printTable(a, size);
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

void printTable(list<string> arg[], const int size) {
    list<string>::iterator itr;
    cout << '\n';
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": ";
        for (itr = arg[i].begin(); itr != arg[i].end(); itr++) {
            cout << *itr << ", ";
        }
        cout << endl;
    }
}

