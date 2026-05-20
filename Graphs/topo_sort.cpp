/* Using DFS */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, st, adj);
            }
        }
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }

private:
    void dfs(int node, vector<int> &visited, stack<int> &st, vector<int> adj[]) {
        visited[node] = 1;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, st, adj);
            }
        }
        st.push(node);
    }
};

// This guarantees that all dependencies of a vertex are placed earlier in the order.