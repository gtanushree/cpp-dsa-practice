// Given a Directed Graph with V vertices and E edges, check whether it contains any cycle or not using BFS.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        return count != V;
    }
};

int main() {
    vector<int> adj[4];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    Solution ob;
    if(ob.isCyclic(4, adj)){
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }
     return 0;
}