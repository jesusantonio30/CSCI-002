#include <iostream>

using namespace std;

template<class T>
T* mergeArrs(T* argArr1, int argSize1, T* argArr2, int argSize2);

template <class T>
void printArray(const T* a, int size);

int main() {

    int size1 = 5;

    int arr[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};

    int* list = mergeArrs<int>(arr, size1, arr2, size1);

    printArray(list, size1 * 2);

    delete[] list;
    list = nullptr;

    cout << '\n';

    int size2 = 5;
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    char charArr2[] = {'f', 'g', 'h', 'i', 'j'};

    char* charMerged = mergeArrs<char>(charArr, size2, charArr2, size2);

    printArray(charMerged, size2 * 2);

    delete[] charMerged;
    charMerged = nullptr;

    cout << '\n';

    int size3 = 5;

    float floatArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float floatArr2[] = {6.6, 7.7, 8.8, 9.9, 10.10};

    float* mergeFloats = mergeArrs<float>(floatArr, size3, floatArr2, size3);

    printArray(mergeFloats, size3 * 2);

    delete[] mergeFloats;
    mergeFloats = nullptr;

    return 0;
}

template<class T>
T* mergeArrs(T* argArr1, int argSize1, T* argArr2, int argSize2) {
    
    int newSize = argSize1 + argSize2;

    T* merged = new T[newSize];

    for (int i = 0; i < argSize1; ++i) {
        merged[i] = argArr1[i];
    }

    int k = 0;

    for (int j = argSize1; j < newSize; ++j) {
        merged[j] = argArr2[k++];
    }

    return merged;
}

template <class T>
void printArray(const T* a, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "]\n";
}
