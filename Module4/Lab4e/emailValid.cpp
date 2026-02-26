#include <iostream>
#include <string>
#include <list>
#include <stdexcept>

using namespace std;

bool isEmailValid(string);

int main() {

    string userInput;
    list<string> validEmailExtensions =  { "@gmail.com", "@aol.com", "@cos.edu", "@giant.cos.edu"};

    cout << "Enter an email: ";
    getline(cin, userInput);

    try {
        cout << isEmailValid(userInput) << endl;
    } catch (const exception& err) {
        cout << err.what() << endl;
    }

    return 0;
}

bool isEmailValid(string arg) {

    size_t n = arg.find('@');
    list<string> validEmailExtensions =  { "@gmail.com", "@aol.com", "@cos.edu", "@giant.cos.edu"};

    if (n == string::npos) {
        throw invalid_argument("No @ detected.");
    }

    for (string email : validEmailExtensions) {
        if (arg.substr(n) == email) {
            return true;
        }
    }

    return false;
}