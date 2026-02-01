#include <iostream>
#include <vector>

using namespace std;

template <class T>
void deleteElement(T* arr, int index, int size);

template <class T>
void printArray(const T* a, int size);

int main() {

    const int size = 9;

    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    deleteElement<int>(array, 2, size);

    printArray(array, size);

    return 0;
}

template <class T>
void deleteElement(T* arr, int index, int size) {

    for (int i = index; i < size; ++i) {
        arr[i] = arr[i+1];
    }
}

template <class T>
void printArray(const T* a, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "]\n";
}