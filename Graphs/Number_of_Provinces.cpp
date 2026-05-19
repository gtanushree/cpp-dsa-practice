// Problem Statement: Given an undirected graph with V vertices. Two vertices u and v belong to a single province if there is a path from u to v or v to u. Find the number of provinces. The graph is given as an n x n matrix adj where adj[i][j] = 1 if the ith city and the jth city are directly connected, and adj[i][j] = 0 otherwise.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;

        for(int j = 0; j < adj.size(); j++) {
            if(adj[node][j] == 1 && !visited[j]) {
                dfs(j, adj, visited);
            }
        }
    }

    int numProvinces(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> visited(V, 0);
        int count = 0;

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                count++;
                dfs(i, adj, visited);
            }
        }

        return count;
    }
};

int main(){
    //int adj[4][4] = { {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1} };
    vector<vector<int>> adj = { {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1} };
    Solution s;
    int result = s.numProvinces(adj);
    cout << result << endl;
    return 0;
}