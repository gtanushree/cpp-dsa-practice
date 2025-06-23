// Time: O(n), Space: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxSoFar = nums[0];
    int minSoFar = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int tempMax = max({nums[i], nums[i] * maxSoFar, nums[i] * minSoFar});
        minSoFar = min({nums[i], nums[i] * maxSoFar, nums[i] * minSoFar});
        maxSoFar = tempMax;

        result = max(result, maxSoFar);
    }

    return result;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product subarray: " << maxProduct(nums) << endl;
    return 0;
}
