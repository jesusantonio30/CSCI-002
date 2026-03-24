#include <iostream>
#include <string>

using namespace std;

int stringToIndexHash(string userName, int buckets);

int main() {

    char runAgain = 'n';

    do {
        string userStr = "";
        int tableSize = 0;

        cout << "Enter a string: ";
        cin >> userStr;

        cout << "Enter a table size: ";
        cin >> tableSize;

        cout << userStr << " placed at index " << stringToIndexHash(userStr, tableSize) << endl;

        cout << "\nTry again? (y/n): ";
        cin >> runAgain;

    } while (tolower(runAgain) == 'y');

    return 0;
}

int stringToIndexHash(string userName, int buckets) {
    int sum = 0;
    for (int i = 0; i < userName.size(); i++) {
        sum += int(userName[i]);
    }

    return sum % buckets;
}