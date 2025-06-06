#include <iostream>
using namespace std;

void rightRotate(int arr[], int n, int k) {
    k = k % n;
    int temp[k];

    // Store last k elements in temp
    for (int i = 0; i < k; i++)
        temp[i] = arr[n - k + i];

    // Shift remaining elements to the right
    for (int i = n - 1; i >= k; i--)
        arr[i] = arr[i - k];

    // Place temp elements at the front
    for (int i = 0; i < k; i++)
        arr[i] = temp[i];
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    cout << "Original array: ";
    printArray(arr, n);

    rightRotate(arr, n, k);

    cout << "Left rotated array by " << k << " positions: ";
    printArray(arr, n);

    return 0;
}
