// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph
// Space Complexity: O(V) for visited array and result vector

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // function to perform DFS on the graph
    void dfs(int v, vector<int> adj[], vector<int>& visited, vector<int>& result){

        // mark current node as visited
        visited[v] = 1;

        // store node in result
        result.push_back(v);

        // traverse all neighbors
        for(int u: adj[v]){
            if(!visited[u]){
                dfs(u, adj, visited, result);
            }
        }
    }
};

int main(){
    // no. of vertices
    int V = 5;

    // adjacency list
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    // visited array
    vector<int> visited(V, 0);

    // result vector
    vector<int> result;

    // create object of Solution class
    Solution s;

    // perform DFS starting from vertex 0
    s.dfs(0, adj, visited, result);

    // print traversal
    cout << "DFS Traversal: ";
    for(int v: result){
        cout << v << " ";
    }
    cout << endl;

    return 0;
}