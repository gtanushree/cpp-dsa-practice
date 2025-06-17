// Insertion Sort builds the sorted array one item at a time. 
// It takes one element from the unsorted part and places it at the correct position in the sorted part.

// Code to sort an unsorted array using Insertion Sort Algorithm.
// Time: O(n^2), Space: O(n^2)

#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];       
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j--;
        }
        arr[j + 1] = key; 
    }
}

int main() {
    int arr[] = {9, 5, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<< "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout<<endl; 

    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout<<endl;
    return 0;
}
