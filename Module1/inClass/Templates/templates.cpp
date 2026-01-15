#include <iostream>

using namespace std;

template<class T> void printArr(T arr[], T size);

int main() {

    constexpr int size = 5;

    int arr[size];
    char charArr[size];
    float floatArr[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = rand();
        charArr[i] = char(97 + rand() % 26);
        floatArr[i] = 1.0 * rand() / RAND_MAX;
    }

    printArr<int>(arr, size);
    printArr<char>(charArr, size);
    printArr<float>(floatArr, size);

    return 0;
}

template <typename T> void printArr(T arr[], T size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << endl;
    }
}
