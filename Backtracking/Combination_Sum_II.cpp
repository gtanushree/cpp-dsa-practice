//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(int start, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
        if (candidates[i] > target) break; // Early stopping

        current.push_back(candidates[i]);
        backtrack(i + 1, candidates, target - candidates[i], current, result); // i+1 since no reuse
        current.pop_back(); // Backtrack
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // Important!
    vector<vector<int>> result;
    vector<int> current;
    backtrack(0, candidates, target, current, result);
    return result;
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = combinationSum2(candidates, target);

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
