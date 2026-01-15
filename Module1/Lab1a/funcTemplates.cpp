#include <iostream>
#include <string>

using namespace std;

template <typename T> 
T minElement(T arg1, T arg2);

template <typename T> 
T maxElement(T arg1, T arg2);

int main() {

    cout << "Min: " << minElement("helloo", "world") << endl;
    cout << "Max: " << maxElement("helloo", "world") << endl;

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
