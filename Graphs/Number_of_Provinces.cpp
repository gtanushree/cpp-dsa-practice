// Problem Statement: Given an undirected graph with V vertices. Two vertices u and v belong to a single province if there is a path from u to v or v to u. Find the number of provinces. The graph is given as an n x n matrix adj where adj[i][j] = 1 if the ith city and the jth city are directly connected, and adj[i][j] = 0 otherwise.

#include <bits/stdc++.h>
using namespace std;

// Solution class to hold the main logic
class Solution {
private:
    // Function to perform DFS traversal
    void dfs(int node, vector<int> adjList[], int visited[]) {
        // Mark current node as visited
        visited[node] = 1;

        // Visit all adjacent unvisited nodes
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited);
            }
        }
    }

public:
    // Function to count number of connected components
    int numProvinces(vector<vector<int>> adj, int V) {
        // Create adjacency list from adjacency matrix
        vector<int> adjList[V];

        // Convert matrix to list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Ignore self-loops
                if (adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // Array to keep track of visited nodes
        int visited[V] = {0};

        // Count of connected components
        int count = 0;

        // Traverse all nodes
        for (int i = 0; i < V; i++) {
            // If node is not visited
            if (!visited[i]) {
                // Perform DFS and increment count
                count++;
                dfs(i, adjList, visited);
            }
        }

        // Return final count
        return count;
    }
};

// Main function to drive the program
int main() {
    // Adjacency matrix input
    vector<vector<int>> adj = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    // Number of vertices
    int V = 3;

    // Create object of Solution
    Solution obj;

    // Call the function and print result
    cout << obj.numProvinces(adj, V) << endl;

    return 0;
}

/*
for leetcode problem: https://leetcode.com/problems/number-of-provinces/#:~:text=A%20province%20is%20a%20group,the%20total%20number%20of%20provinces.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // DFS function
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;

        for(int j = 0; j < isConnected.size(); j++) {
            // Check connection and unvisited node
            if(isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> visited(n, 0);

        int provinces = 0;

        for(int i = 0; i < n; i++) {

            // New province found
            if(!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }

        return provinces;
    }
};

int main() {

    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    Solution s;

    cout << "Number of Provinces: "
         << s.findCircleNum(isConnected);

    return 0;
}
*/