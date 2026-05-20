/* Problem Statement: Given an undirected Graph consisting of V vertices numbered from 0 to V-1 and E edges. The ith edge is represented by [ai,bi], denoting a edge between vertex ai and bi. We say two vertices u and v belong to a same component if there is a path from u to v or v to u. Find the number of connected components in the graph. A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.  */
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        void dfs(int node, vector<int> adjList[], int visited[]) {
            visited[node] = 1;

            for (auto neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, adjList, visited);
                }
            }
        }
    public:
        int countComponents(int V, vector<vector<int>>& edges) {
            vector<int> adjList[V];

            for (auto edge : edges) {
                int u = edge[0];
                int v = edge[1];
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }

            int visited[V] = {0};
            int count = 0;

            for (int i = 0; i < V; i++) {
                if (!visited[i]) {
                    count++;
                    dfs(i, adjList, visited);
                }
            }

            return count;
        }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};

    Solution obj;
    cout << "Number of Connected Components: "
         << obj.countComponents(V, edges) << endl;

    return 0;
}