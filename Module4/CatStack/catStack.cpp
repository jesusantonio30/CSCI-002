#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    stack<string*> catNames;
    string catName = "";
    char anotherCat = 'n';

    do {
        cout << "\nEnter cat name: ";
        getline(cin, catName);
        catNames.emplace(new string(catName));

        cout << "\nEnter another cat? (y/n): ";
        cin >> anotherCat;

        cin.ignore();

    } while (tolower(anotherCat) == 'y');

    cout << '\n';

    while (!catNames.empty()) {
        string* toDelete = catNames.top();
        cout << *(catNames.top()) << endl;
        catNames.pop();

        delete toDelete;
        toDelete = nullptr;
    }

    cout << '\n';

    if (catNames.size() == 0) cout << "Stack is empty!\n";
    else cout << "Stack isn't empty.\n";

    return 0;
}
