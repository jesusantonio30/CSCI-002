#include <iostream>
#include <vector>

using namespace std;

void printArray(const int* a, int size);

int main() {

    int oldCap = 5;
    int* a = new int[oldCap];

    // Fill with sample values: 10, 20, 30, 40, 50
    for (int i = 0; i < oldCap; i++) {
        a[i] = (i + 1) * 10;
    }


    cout << "Original array: ";
    printArray(a, oldCap);

    // Part A =================================

    int endVal = 123;

    int newSize = oldCap + 1;
    int* newA = new int[newSize];

    for (int i = 0; i < oldCap; ++i) {
        newA[i] = a[i];
    }

    newA[oldCap] = endVal;

    cout << "\nNew array: ";
    printArray(newA, newSize);

    delete[] a;
    a = nullptr;

    // Part B =================================

    int valueFront = 999;

    int newBsize = newSize + 1;
    int* newB = new int[newBsize];

    newB[0] = valueFront;

    for (int i = 1; i < newBsize; ++i) {
        newB[i] = newA[i - 1];
    }

    cout << "\nNew B array: ";
    printArray(newB, newBsize);

    delete[] newA;
    newA = nullptr;

    // Part C =================================

    int valueAt3 = 777;
    int insertIndex = 3;

    int newCsize = newBsize + 1;
    int* newC = new int[newCsize];

    for (int i = 0; i < insertIndex; ++i) {
        newC[i] = newB[i];
    }

    newC[insertIndex] = valueAt3;

    for (int i = insertIndex + 1; i < newCsize; ++i) {
        newC[i] = newB[i - 1];
    }

    cout << "\nNew C array: ";
    printArray(newC, newCsize);

    delete[] newB;
    newB = nullptr;

    // ENTER VECTORS =================================

    vector<int> vec;

    for (int i = 0; i < 8; ++i) {
        vec[i] = (i + 1) * 10;
    }

    return 0;
}

void printArray(const int* a, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "]\n";
}
