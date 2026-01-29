#include <iostream>
#include <string>

using namespace std;

template<typename T>
T* pushBack(T* arr, int size, T argVal);

template <typename T>
T* popBack(T* arr, int size);

template<typename T>
void printArray(const T* a, int size);

int main() {

    // INSTANTIATE OG ARRAY --------------------------------
    cout << " \n============== Integer Examples ==============\n";
    
    int size = 10;
    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = (i + 1) * 10;
    }

    // PUSH BACK ARRAY --------------------------------
    int* newArr = pushBack<int>(arr, size, 123);

    cout << "\nNew Arr: \n";
    printArray(newArr, size + 1);

    delete[] arr;
    arr = nullptr;

    // POP BACK ARRAY --------------------------------

    int* shortArr = popBack<int>(newArr, size + 1);

    cout << "\nOG: \n";
    printArray(shortArr, size);

    delete[] newArr;
    newArr = nullptr;

    delete[] shortArr;
    shortArr = nullptr;

    cout << " \n============== String Examples ==============\n";

    int sizeStr = 5;
    string* strArr = new string[sizeStr];

     string strAr[]= {"Jesus", "Maria", "Fatima", "Joel", "Candi"};

    for (int i = 0; i < sizeStr; ++i) {
        strArr[i] = strAr[i];
    }

    // PUSH BACK ARRAY --------------------------------
    string* newStrArr = pushBack<string>(strArr, sizeStr, "Gustavo");

    cout << "\nNew String Arr: \n";
    printArray(newStrArr, sizeStr + 1);

    delete[] strArr;
    strArr = nullptr;

    // POP BACK ARRAY --------------------------------

    string* shortStrArr = popBack<string>(newStrArr, sizeStr + 1);

    cout << "\nOG String Array: \n";
    printArray(shortStrArr, sizeStr);

    delete[] newStrArr;
    newStrArr = nullptr;

    delete[] shortStrArr;
    shortStrArr = nullptr;

    return 0;
}

template<typename T>
T* pushBack(T* arr, int size, T argVal) {

    int newSize = size + 1;
    T* copy = new T[newSize];

    for (int i = 0; i < size; ++i) {
        copy[i] = arr[i];
    }

    copy[size] = argVal;

    return copy;
}

template <typename T>
T* popBack(T* arr, int size) {
    int newSize = size - 1;
    T* copy = new T[newSize];

    for (int i = 0; i < newSize; ++i) {
        copy[i] = arr[i];
    }

    return copy;
}
template<typename T>
void printArray(const T* a, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "]\n";
}
