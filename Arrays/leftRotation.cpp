#include <iostream>
using namespace std;

void leftRotate(int arr[], int n, int k) {
    k = k % n; // Handle k > n
    int temp[k];

    // Store first k elements in temp
    for (int i = 0; i < k; i++)
        temp[i] = arr[i];

    // Shift remaining elements to the left
    for (int i = k; i < n; i++)
        arr[i - k] = arr[i];

    // Put back the k elements at the end
    for (int i = 0; i < k; i++)
        arr[n - k + i] = temp[i];
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

    leftRotate(arr, n, k);

    cout << "Left rotated array by " << k << " positions: ";
    printArray(arr, n);

    return 0;
}
