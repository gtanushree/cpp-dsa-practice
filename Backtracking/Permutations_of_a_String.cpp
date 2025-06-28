// Code to find permutations of a String
// Time: O(n*n!), Space: O(n)

#include <iostream>
#include <string>

using namespace std;

void permute(string& str, int index) {
    if (index == str.length()) {
        cout << str << endl;
        return;
    }

    for (int i = index; i < str.length(); i++) {
        swap(str[index], str[i]);      // Place character at index
        permute(str, index + 1);       // Permute rest
        swap(str[index], str[i]);      // Backtrack
    }
}

int main() {
    string str = "ABC";
    cout << "Permutations are:" << endl;
    permute(str, 0);
    return 0;
}
