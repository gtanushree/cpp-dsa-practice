//
// Time: O(M^n), Space: O(n)

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int node, vector<vector<int>>& graph, vector<int>& color, int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool solve(int node, vector<vector<int>>& graph, vector<int>& color, int m, int n) {
    if (node == n) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, graph, color, c, n)) {
            color[node] = c;

            if (solve(node + 1, graph, color, m, n))
                return true;

            color[node] = 0; // backtrack
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> color(n, 0); // color array: 0 means uncolored

    return solve(0, graph, color, m, n);
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3;

    if (graphColoring(graph, m))
        cout << "Graph can be colored with " << m << " colors." << endl;
    else
        cout << "Graph cannot be colored with " << m << " colors." << endl;

    return 0;
}
