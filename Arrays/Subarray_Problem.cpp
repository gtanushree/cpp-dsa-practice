#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool subarrayWithZeroSum(vector<int>& arr) {
    unordered_map<int, int> prefixSumMap;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // If prefix sum is 0 or already seen → subarray exists
        if (sum == 0 || prefixSumMap.find(sum) != prefixSumMap.end())
            return true;

        prefixSumMap[sum] = i;
    }

    return false;
}

int main() {
    vector<int> arr = {4, 2, -3, 1, 6};

    if (subarrayWithZeroSum(arr))
        cout << "Found a subarray with 0 sum." << endl;
    else
        cout << "No subarray with 0 sum found." << endl;

    return 0;
}
