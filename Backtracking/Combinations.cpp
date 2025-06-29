// Code to find all combinations of elements in an array that sum to K.
// Time: O(n*2^n), Space: O(n)

#include <iostream>
#include <vector>

using namespace std;

void findCombinations(int index, vector<int>& nums, int target, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    if (index == nums.size() || target < 0) {
        return;
    }

    current.push_back(nums[index]);
    findCombinations(index + 1, nums, target - nums[index], current, result);

    current.pop_back();
    findCombinations(index + 1, nums, target, current, result);
}

int main() {
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result;
    vector<int> current;

    findCombinations(0, nums, target, current, result);

    cout << "Combinations with sum " << target << " are:" << endl;
    for (auto combo : result) {
        cout << "{ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
