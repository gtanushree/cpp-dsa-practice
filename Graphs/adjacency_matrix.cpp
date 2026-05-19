#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int adj[n+1][n+1] = {0}; // Initialize the adjacency matrix with 0s
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // Mark the presence of an edge from u to v
        adj[v][u] = 1; // Mark the presence of an edge from v to u (undirected graph)
    }
    
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}