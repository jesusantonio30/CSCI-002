#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(vector<int>& arr, int begin, int mid, int end, int& counter) {
                         
    int n1 = mid - begin + 1;
    int n2 = end - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[begin + i];
        counter++;
    }
    counter++;

    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        counter++;
    }
    counter++;

    int i = 0, j = 0;
    int k = begin;

    // Merge the temp vectors back 
    // into arr[begin..end]
    counter += 2;
    while (i < n1 && j < n2) {
        counter++;

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            counter++;
        }
        else {
            arr[k] = R[j];
            j++;
            counter++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    counter++;
    while (i < n1) {
        counter++;
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    counter++;
    while (j < n2) {
        counter++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for begin index and end is end index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int begin, int end, int& counter){
    counter++;
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid, counter);
    mergeSort(arr, mid + 1, end, counter);
    merge(arr, begin, mid, end, counter);
}

// Driver code
int main(){

    srand(time(0));
    
    vector<int> arr;
    int count = 0;
    int size = 100;

    for (int i = 0; i < size; ++i) {
        arr.push_back(rand() % 1000);
    }

    int n = arr.size();

    mergeSort(arr, 0, n - 1, count);

    for (int num : arr) {
        cout << num << ' ';
    }
    cout << endl;

    cout << "Number of comparisons: " << count << endl;
    cout << "Average Comparisons: " << count / size << endl;
    
    return 0;
}