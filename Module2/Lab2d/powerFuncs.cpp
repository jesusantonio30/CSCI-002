#include <iostream>

using namespace std;

double powIterative(double x, int n);
double powRecursive(double x, int n);

int main() {

    cout << powIterative(2, 10) << endl;
    cout << powRecursive(2, 10) << endl;

    cout << '\n';

    cout << powIterative(3, 5) << endl;
    cout << powRecursive(3, 5) << endl;

    cout << '\n';

    cout << powIterative(4, 8) << endl;
    cout << powRecursive(4, 8) << endl;

    return 0;
}

double powIterative(double x, int n) {

    double ans = 1;

    for (int i = 0; i < n; ++i) {
        ans *= x;
    }

    return ans;

}

double powRecursive(double x, int n) {

    if (n == 0) return 1;

    return x * powRecursive(x, n - 1);
}
