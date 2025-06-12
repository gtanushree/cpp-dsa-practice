// Time: O(n), Space: O(n)

#include <iostream>
#include <unordered_set>

using namespace std;

int longestConsecutive(int arr[], int n) {
    unordered_set<int> s;
    int maxLen = 0;

    // Insert all elements into the set
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);

    for (int i = 0; i < n; i++) {
        // Check if it’s the start of a sequence
        if (s.find(arr[i] - 1) == s.end()) {
            int currentNum = arr[i];
            int currentStreak = 1;

            // Count next elements in the sequence
            while (s.find(currentNum + 1) != s.end()) {
                currentNum++;
                currentStreak++;
            }

            maxLen = max(maxLen, currentStreak);
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {100, 4, 200, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Length of the Longest Consecutive Subsequence is: "
         << longestConsecutive(arr, n) << endl;

    return 0;
}
