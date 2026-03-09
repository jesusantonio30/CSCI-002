#include <iostream>
#include <numeric>

using namespace std;

class Fraction {
    private:
        int a, b;

    public:
        Fraction(int argA, int argB) : a(argA), b(argB) {}

        Fraction reduce();
        Fraction add(Fraction argY);
        void print();
};

int main () {

    Fraction x(5, 10);

    Fraction ex = x.reduce();

    cout << "-----------------Reduce-----------------\n";
    cout << "Original: "; 
    x.print();
    cout << endl;

    cout << "Reduced: ";
    ex.print();
    cout << endl;

    
    Fraction y(1, 2);
    Fraction z(1, 2);

    Fraction eg = y.add(z);

    cout << "-----------------Add-----------------\n";
    cout << "Original: "; 
    y.print();
    cout << "  +  ";
    z.print();
    cout << endl;

    cout << "Added: ";
    eg.print();
    cout << endl;

    return 0;
}

Fraction Fraction::reduce() {
    int GCD = gcd(a, b);

    return Fraction ((a/GCD), (b/GCD));
}

Fraction Fraction::add(Fraction argY) {
    int numerator = (a * argY.b) + (argY.a * b);
    int denominator = b * argY.b;

    return Fraction(numerator, denominator).reduce();
}

void Fraction::print() {
    cout << a << " / " << b;
}