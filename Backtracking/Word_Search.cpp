// Code to check if the word exists in the grid by moving left, right, up, or down.

#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<char>>& board, int i, int j, string word, int index) {
    if (index == word.length()) return true;

    // Check boundaries and match
    if (i < 0 || i >= board.size() ||
        j < 0 || j >= board[0].size() ||
        board[i][j] != word[index]) return false;

    // Mark as visited
    char temp = board[i][j];
    board[i][j] = '#';

    // Explore all 4 directions
    bool found = dfs(board, i + 1, j, word, index + 1) ||
                 dfs(board, i - 1, j, word, index + 1) ||
                 dfs(board, i, j + 1, word, index + 1) ||
                 dfs(board, i, j - 1, word, index + 1);

    // Backtrack
    board[i][j] = temp;

    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == word[0]) {
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    if (exist(board, word)) {
        cout << "Word exists in the grid." << endl;
    } else {
        cout << "Word does not exist in the grid." << endl;
    }

    return 0;
}
