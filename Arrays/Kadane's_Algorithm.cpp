#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArraySum(vector<int>& nums) {
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int num : nums) {
        currentSum += num;
        maxSum = max(maxSum, currentSum);

        // If current sum becomes negative, reset it to 0
        if (currentSum < 0)
            currentSum = 0;
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubArraySum(nums);
    cout << "Maximum subarray sum is: " << result << endl;

    return 0;
}
