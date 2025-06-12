// Code to find the subarray with given sum.
// Using HashMap Approach

#include <iostream>
#include <unordered_map>

using namespace std;

bool subarraySumHash(int arr[], int n, int target) {
    unordered_map<int, int> prefixSumMap; // sum → index
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == target) {
            cout << "Subarray found from index 0 to " << i << endl;
            return true;
        }

        if (prefixSumMap.find(sum - target) != prefixSumMap.end()) {
            cout << "Subarray found from index " << prefixSumMap[sum - target] + 1 << " to " << i << endl;
            return true;
        }

        prefixSumMap[sum] = i;
    }

    cout << "No subarray with given sum found." << endl;
    return false;
}

int main() {
    int arr[] = {10, 2, -2, -20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = -10;

    subarraySumHash(arr, n, target);
    return 0;
}
