#include <iostream>
#include <string>

using namespace std;

template <typename T> 
T minElement(T arg1, T arg2);

template <typename T> 
T maxElement(T arg1, T arg2);

int main() {

    string str1 = "hello", 
           str2 = "world";

    int num1 = 10,
        num2 = 15;

    double dec1 = 15.3,
           dec2 = 18.67;

    char char1 = 'g',
         char2 = 'Y';

    cout << "\nMin of " << "( " << str1 << ", " << str2 << " )" << " => " << minElement(str1, str2) << endl;
    cout << "Max of " << "( " << str1 << ", " << str2 << " )" << " => " << maxElement(str1, str2) << endl;

    cout << "\nMin of " << "( " << num1 << ", " << num2 << " )" << " => " << minElement(num1, num2) << endl;
    cout << "Max of " << "( " << num1 << ", " << num2 << " )" << " => " << maxElement(num1, num2) << endl;
    
    cout << "\nMin of " << "( " << dec1 << ", " << dec2 << " )" << " => " << minElement(dec1, dec2) << endl;
    cout << "Max of " << "( " << dec1 << ", " << dec2 << " )" << " => " << maxElement(dec1, dec2) << endl;
    
    cout << "\nMin of " << "( " << char1 << ", " << char2 << " )" << " => " << minElement(char1, char2) << endl;
    cout << "Max of " << "( " << char1 << ", " << char2 << " )" << " => " << maxElement(char1, char2) << endl;
    
    return 0;
}

template <typename T> 
T minElement(T arg1, T arg2) {
    return arg1 < arg2 ? arg1 : arg2;
}

template <typename T> 
T maxElement(T arg1, T arg2) {
    return arg1 > arg2 ? arg1 : arg2;
}
