// Code to implement Radix Sort on an unsorted array.
// Time: O(n), Space: O(n)

#include <iostream>
#include <vector>

using namespace std;

int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int val : arr) {
        if (val > maxVal)
            maxVal = val;
    }
    return maxVal;
}

void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array (Stable sort)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] using Radix Sort
void radixSort(vector<int>& arr) {
    int maxNum = getMax(arr);

    // Do counting sort for every digit, starting from least significant digit (LSD)
    for (int exp = 1; maxNum / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    printArray(arr);

    radixSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
