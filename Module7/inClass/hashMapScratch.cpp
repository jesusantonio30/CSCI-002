#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Hash table itself is a C Array
// Buckets can be any sequential data structure

int hashFunc(string target) {
    return target[0] - 97;
}

void printBucket(vector<string> argv, int index) {
    cout << "Bucket " << index << ": " << endl;
    for (int i = 0; i < argv.size(); i++) {
        cout << argv.at(i) << " ";
    }
    cout << endl;
}

int main() {

    const int size = 26;
    vector<string> data[size];
    string target = "barry";

    data[0].push_back("aaron");
    data[1].push_back("barry");
    data[1].push_back("barrio");
    data[1].push_back("barto");
    data[3].push_back("daniel");

    string userStr = "carlos";
    data[hashFunc(userStr)].push_back(userStr);

    for (int i = 0; i < size; i++) {
        printBucket(data[i], i);
        cout << endl;
    }



    return 0;
}

