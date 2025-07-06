// Time: O(n*2^n), Space: O(n)

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

void backtrack(int start, string& s, vector<string>& current, vector<vector<string>>& result) {
    if (start == s.length()) {
        result.push_back(current);
        return;
    }

    for (int end = start; end < s.length(); end++) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));
            backtrack(end + 1, s, current, result);
            current.pop_back(); // backtrack
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;
    backtrack(0, s, current, result);
    return result;
}

int main() {
    string s = "aab";
    vector<vector<string>> partitions = partition(s);

    cout << "Palindrome partitions of \"" << s << "\":" << endl;
    for (auto partition : partitions) {
        cout << "[ ";
        for (auto word : partition) {
            cout << "\"" << word << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}
