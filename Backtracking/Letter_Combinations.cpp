//

#include <iostream>
#include <vector>

using namespace std;

void backtrack(string& digits, int index, string& current, vector<string>& result, const vector<string>& mapping) {
    if (index == digits.size()) {
        result.push_back(current);
        return;
    }

    int digit = digits[index] - '0';
    for (char ch : mapping[digit]) {
        current.push_back(ch);
        backtrack(digits, index + 1, current, result, mapping);
        current.pop_back(); // backtrack
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    vector<string> mapping = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    vector<string> result;
    string current;
    backtrack(digits, 0, current, result, mapping);
    return result;
}

int main() {
    string digits = "23";
    vector<string> result = letterCombinations(digits);

    cout << "Letter combinations for \"" << digits << "\":" << endl;
    for (string s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
