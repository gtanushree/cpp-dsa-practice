// Code to generate power set of a given array
// Time: O(n*2^n), Space: O(n*2^n)

#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(int index, vector<int> &nums, vector<int> &current, vector<vector<int>> &result){
    if(index = nums.size()){
        result.push_back(current);
        return;
    }

    // Include the current element
    current.push_back(nums[index]);
    generateSubsets(index + 1, nums, current, result);

    // Exclude the current element (Backtrack)
    current.pop_back();
    generateSubsets(index + 1, nums, current, result);
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    vector<int> current;

    generateSubsets(0, nums, current, result);

    cout << "Subsets:" << endl;
    for (auto subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}