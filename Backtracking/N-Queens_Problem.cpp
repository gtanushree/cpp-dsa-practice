// Code for implementing N-Queens Problem.
// Time: O(n!), Space: O(n^2)

#include <iostream>
#include <vector>

using namespace std;

void printSolution(vector<vector<int>>& board, int n) {
    for (auto row : board) {
        for (int cell : row) {
            cout << (cell == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // Check upper left diagonal
    for (int i = row-1, j = col-1; i >=0 && j >=0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check upper right diagonal
    for (int i = row-1, j = col+1; i >=0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

void solve(int row, vector<vector<int>>& board, int n) {
    if (row == n) {
        printSolution(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(row + 1, board, n);
            board[row][col] = 0; // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter N for N-Queens: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(0, board, n);

    return 0;
}
