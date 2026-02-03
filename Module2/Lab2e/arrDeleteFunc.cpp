#include <iostream>

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

    int array2[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deleteElement<int>(array2, 0, size);
    printArray(array2, size);

    double array4[size] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    deleteElement<double>(array4, 3, size);
    printArray(array4, size);

    char array5[size] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    deleteElement<char>(array5, 0, size);
    printArray(array5, size);

    return 0;
}

template <class T>
void deleteElement(T* arr, int index, int size) {

    for (int i = index; i < size; ++i) {
        arr[i] = arr[i+1];
    }

    arr[size-1] = 0;
}

template <class T>
void printArray(const T* a, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "]\n";
}
