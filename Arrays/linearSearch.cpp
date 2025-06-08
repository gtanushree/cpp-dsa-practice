#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int num){
    for(int i=0; i<size; i++){
        if(arr[i]==num) return i;
    }
    return -1;
}

int main(){
    int arr[] = {10, 25, 30, 45, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num;

    cout << "Enter the element to search: ";
    cin >> num;

    int index = linearSearch(arr, size, num);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}