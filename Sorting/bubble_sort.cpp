// Code to implement Bubble Sort on an unsorted array.
// Time: O(n^2), Space: O(1)

#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        bool swapped = false;

        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if (!swapped) break;
    }
}

int printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {9, 4, 1, 13, 8, 7, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array: ";
    printArray(arr, n);

    bubbleSort(arr, n);
    cout<<"Sorted Array: ";
    printArray(arr, n);

    return 0;
}