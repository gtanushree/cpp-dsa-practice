#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Allocate memory
    int* arr = new int[n];

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Array elements:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Deallocate memory
    delete[] arr;

    return 0;
}
