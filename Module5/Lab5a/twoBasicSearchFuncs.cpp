#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

int searchListLinear(vector<int>& arg, int target);
int searchListBinary(vector<int>& arg, int target);

int main() {
    srand(time(0));

    char runAgain = 'n';
    int userInt = 0;

    vector<int> randNums;
    map<int, int> uniques;

    for (int i = 0; i < 100; ++i) {
        int num = rand() % 1000;

        while (uniques.find(num) != uniques.end()) {
            num = rand() % 1000;
        }

        randNums.push_back(num);
        uniques[num] = num;
    }

    sort(randNums.begin(), randNums.end());

    cout << "----------------- RANDOM NUMS -----------------\n";
    for (int num : randNums) {
        cout << num << ' ';
    }
    cout << endl;
    cout << "-----------------------------------------------\n";

    do {
        cout << "Enter a number to find: ";
        cin >> userInt;

        int found = searchListBinary(randNums, userInt);
        int foundAgain = searchListLinear(randNums, userInt);

        if (found != -1) {
            cout << "Binary Search: Integer found in index " << found << endl;
            cout << "Linear Search: Integer found in index " << foundAgain << endl;
        }
        else
            cout << "Integer not found.\n";

        cout << "Search again? (y/n): ";
        cin >> runAgain;
    } while (tolower(runAgain) == 'y');

    return 0;
}

int searchListLinear(vector<int>& arg, int target) {
    for (int i = 0; i < arg.size(); ++i) {
        if (arg[i] == target) return i;
    }

    return -1;
}

int searchListBinary(vector<int>& arg, int target) {
    int low = 0;
    int high = arg.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arg[mid] == target)
            return mid;

        // If x greater, ignore left half
        if (arg[mid] < target)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}
