// Code to implement the rat in a maze problem.
// Time: O(4^(n^2)), Space: O(n^2)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(int x, int y, vector<vector<int>>& maze, int n, vector<vector<int>>& visited, string path, vector<string>& result) {
    // If destination is reached
    if (x == n-1 && y == n-1) {
        result.push_back(path);
        return;
    }

    // Directions: D, L, R, U
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    char dir[] = {'D', 'L', 'R', 'U'};

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        // Valid move
        if (newX >= 0 && newX < n && newY >= 0 && newY < n &&
            visited[newX][newY] == 0 && maze[newX][newY] == 1) {

            visited[x][y] = 1;
            solve(newX, newY, maze, n, visited, path + dir[i], result);
            visited[x][y] = 0;  // Backtrack
        }
    }
}

vector<string> findPaths(vector<vector<int>>& maze, int n) {
    vector<string> result;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    if (maze[0][0] == 1) {
        solve(0, 0, maze, n, visited, "", result);
    }

    return result;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int n = maze.size();
    vector<string> paths = findPaths(maze, n);

    if (paths.empty()) {
        cout << "No path exists" << endl;
    } else {
        cout << "Paths found:" << endl;
        for (string path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}
