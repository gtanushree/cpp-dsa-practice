#include <iostream>

using namespace std;

void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        // Swap elements at start and end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move pointers
        start++;
        end--;
    }
}

int main(){
    int n;

    cout<<"Enter the number of elements: ";
    cin>>n;

    // Allocate memory
    int* arr = new int[n];

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    reverseArray(arr, n);

    cout << "The array after reversing its elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}