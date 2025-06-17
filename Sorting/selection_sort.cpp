// Selection Sort is a simple comparison-based sorting algorithm.
// In each iteration, it:
// Finds the minimum (or maximum) element from the unsorted part of the array.
// Swaps it with the first unsorted element.
// Expands the sorted part by one.

// Time: O(n^2), Space: O(n^2)

#include <iostream>

using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Original Array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout<<"Sorted Array: ";
    printArray(arr, n);

    return 0;
}