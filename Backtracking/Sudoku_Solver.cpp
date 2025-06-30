// Code to solve a 9x9 Sudoku board using backtracking.
// Time: O(9^n), Space: O(n)

#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    // Check row and column
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) return false;
        if (board[i][col] == num) return false;
    }

    // Check 3x3 subgrid
    int startRow = 3 * (row / 3);
    int startCol = 3 * (col / 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) return true;
                        board[row][col] = '.'; // Backtrack
                    }
                }
                return false; // If no number fits
            }
        }
    }
    return true; // Solved
}

void printBoard(const vector<vector<char>>& board) {
    for (auto row : board) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << "Original Sudoku Board:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "\nSolved Sudoku Board:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
