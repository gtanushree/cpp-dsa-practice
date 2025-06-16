// Merge Sort is a Divide and Conquer algorithm that:
// Divides the array into two halves.
// Recursively sorts each half.
// Merges the sorted halves.

// Code to implement Merge Sort on an unsorted array.
// Time: O(n log n), Space: O(n)

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i=0; i<n1; ++i){
        L[i] = arr[left+i];
    }

    for(int j=0; j<n2; ++j){
        R[j] = arr[mid + 1 + j];
    }

    int i=0 , j=0, k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
    }

    // Merge remaining elements
    while(i<n1){
        arr[k++]=L[i++];
    }

    while(j<n2){
        arr[k++]=R[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    if(left>=right) return;

    int mid = left + (right-left)/2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);
}

int main(){
    vector<int> arr = {6, 3, 9, 5, 2, 8, 7, 1};
    
    cout<<"Array before sorting: ";
    for (int val : arr){
        cout << val << " ";
        cout << endl;
    }
    
    mergeSort(arr, 0, arr.size()-1);

    cout<<"Array after sorting: ";
    for(int val : arr){
        cout<<val<<" ";
        cout<<endl;
    }

    return 0;
}