// Given a list of numbers and a target, find all combinations that add up to the target.

#include <iostream>
#include <vector>

using namespace std;

void backtrack(int index, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = index; i < candidates.size(); i++) {
        if (candidates[i] > target) continue; 

        current.push_back(candidates[i]);                  
        backtrack(i, candidates, target - candidates[i], current, result); 
        current.pop_back();                                
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(0, candidates, target, current, result);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations summing to " << target << ":" << endl;
    for (auto combo : result) {
        cout << "[ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
