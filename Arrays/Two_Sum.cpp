#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++){
            int comp = target - nums[i];
            for (int j = i+1; j<nums.size();j++){
                if(comp == nums[j]) return {i, j};
            }
        }
        return {};
    }
};

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution s;
    vector<int> result = s.twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices of the two numbers: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}