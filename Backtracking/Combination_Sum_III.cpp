//

#include <iostream>
#include <vector>

using namespace std;

void backtrack(int start, int k, int target, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0 && current.size() == k) {
        result.push_back(current);
        return;
    }

    for (int i = start; i <= 9; i++) {
        if (i > target) break; // pruning

        current.push_back(i);
        backtrack(i + 1, k, target - i, current, result); // no reuse → i+1
        current.pop_back(); // backtrack
    }
}

vector<vector<int>> combinationSum3(int k, int target) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(1, k, target, current, result);
    return result;
}

int main() {
    int k = 3, target = 9;
    vector<vector<int>> result = combinationSum3(k, target);

    cout << "Combinations of " << k << " numbers summing to " << target << ":\n";
    for (auto combo : result) {
        cout << "[ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
