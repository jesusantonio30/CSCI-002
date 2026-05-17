#include <cctype>
#include <iostream>
#include <algorithm>

using namespace std;

class Line {
    private:
        int a, b, c;

    public:
        Line(int argA, int argB, int argC) : a(argA), b(argB), c(argC) {}
        bool isPerpendicular(const Line& other) const;
        bool isParallel(const Line& other) const;

};

Line parseUsrStr(const string& input);

int main() {

    char runAgain = 'n';

    do {
        string line1 = "";
        string line2 = "";

        cout << "\n\tEnter two lines:\n";
        cout << "Line 1: ";
        getline(cin, line1);
        cout << "Line 2: ";
        getline(cin, line2);

        line1.erase(remove(line1.begin(), line1.end(), ' '), line1.end());
        line2.erase(remove(line2.begin(), line2.end(), ' '), line2.end());

        Line l1 = parseUsrStr(line1);
        Line l2 = parseUsrStr(line2);

        if (l1.isParallel(l2)) {
            cout << "Lines are parallel.\n";
        } else if (l1.isPerpendicular(l2)) {
            cout << "Lines are perpendicular.\n";
        } else {
            cout << "Lines are neither parallel nor perpendicular.\n";
        }

        cout << "\nRun Again? (y/n): ";
        cin >> runAgain;

        cin.ignore();

    } while (tolower(runAgain) == 'y');

    return 0;
}

bool Line::isPerpendicular(const Line& other) const {
    return (this->a * other.a) == (-1 * this->b * other.b);
}

bool Line::isParallel(const Line& other) const {
    return (this->a * other.b) == (other.a * this->b);
}

Line parseUsrStr(const string& input) {
    int current = 0;
    int a = 0,
        b = 0,
        c = 0; 
    int sign = 1;
    bool sawNums = false;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '-') {
            sign = -1;
        }
        else if (isdigit(input[i])) { 
            current = current * 10 + (input[i] - '0');
            sawNums = true;
        }
        else {
            if (input[i] == 'x') {
                a = sign * (sawNums ? current : 1);
                current = 0;
                sign = 1;
                sawNums = false;
            }
            if (input[i] == 'y') {
                b = sign * (sawNums ? current : 1);
                current = 0;
                sign = 1;
                sawNums = false;
            }
        }
    }

    c = sign * current;

    return Line(a, b, c);
}