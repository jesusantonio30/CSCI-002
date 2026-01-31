#include <iostream>
#include <cmath>

using namespace std;

double calcPI(double argN, double sum = 0);

int main() {

    char runAgain = 'n';

    do {
        int n;

        cout << "Enter number of terms: ";
        cin >> n;

        if (n < 0 || cin.fail()) {
            cout << "Invalid input! Enter a positive integer.\n";
            cin.clear();
            cin.ignore('\n');
        } 
        else {
            cout << "You Entered " << n << " terms.\n";
            cout << "PI = " << calcPI(n) << endl;
        }

        cout << "Try again? (y/n): ";
        cin >> runAgain;

    } while (tolower(runAgain) == 'y');

    return 0;
}


double calcPI(double argN, double sum) {

    if (argN >= 0) {

        sum += 4 * (pow(-1, argN) / (2 * argN + 1));
        return calcPI(argN - 1, sum);
    }

    return sum;
}