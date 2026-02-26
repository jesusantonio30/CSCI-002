#include <iostream>
#include <stack>

using namespace std;

int main() {

    /*
    Create a stack. 
    A stack works like a vector, without access of elements in between.
    The front of the stack is like the end of a vector.
    So the last appended element is the first to be popped off.

    Using this knowledge, iterate through a string
    Append each char into the stack.

    Then using another loop, compare the beginning of the string to check against the top of the stack.
    If both chars are equal, set bool flag to true and false if otherwise.
    Pop char after each iteration.
    If the stack is empty and bool flag is true, then the string is a valid Palindrome
    Otherwise, it is not.
    */

    stack<char> palindromeCheck;

    string myStr;
    char checkAgain = 'n';

    do {
        cout << "Enter a string: ";
        getline(cin, myStr);

        bool isPalindrome = false;

        for (char let : myStr) {
            palindromeCheck.push(let);
        }

        while (!palindromeCheck.empty()) {
            for (char itr : myStr) {
                if (palindromeCheck.top() == itr) {
                    isPalindrome = true;
                }
                else {
                    isPalindrome = false;
                }

                palindromeCheck.pop();
            }
        }

        isPalindrome ? cout << "Is Palindrome!\n" : cout << "Is not Palindrome.\n";

        cout << "Check another string? (y/n): ";
        cin >> checkAgain;

        cin.ignore();

    } while (tolower(checkAgain) == 'y');

    return 0;
}