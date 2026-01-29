#include <iostream>
#include <string>

using namespace std;

template<typename T>
int binarySearch(const T anArray[], int first, int last, T target);

int main() {

    string arr[] = {"Candio", "Gustavo", "Jesus", "Joel", "Maria"};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << binarySearch<string>(arr, 0, size - 1, "Maria") << endl;

    return 0;
}

template<typename T>
int binarySearch(const T anArray[], int first, int last, T target) {
    int index;
    if (first > last)
        index = -1;
    else {
        int mid = first + (last - first) / 2;
        if (target == anArray[mid])
            index = mid;
        else if(target < anArray[mid])
            index = binarySearch(anArray, first, mid - 1, target);
        else
            index = binarySearch(anArray, mid + 1, last, target);
    }
    return(index);
}
