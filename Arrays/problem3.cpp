// Code to find the subarray with given sum.
// Using Sliding Window

#include <iostream>

using namespace std;

bool subarraySum(int arr[], int n, int target) {
    int start = 0, sum = 0;

    for (int end = 0; end < n; end++) {
        sum += arr[end];

        // Shrink the window if sum exceeds the target
        while (sum > target && start <= end) {
            sum -= arr[start];
            start++;
        }

        if (sum == target) {
            cout << "Subarray found from index " << start << " to " << end << endl;
            return true;
        }
    }

    cout << "No subarray with given sum found." << endl;
    return false;
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 33;

    subarraySum(arr, n, target);
    return 0;
}
