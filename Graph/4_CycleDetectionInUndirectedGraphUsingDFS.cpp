//Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool hasCycleDFS(int nd, int p, vector<int>& vis, vector<int> adj[]){
        vis[nd] = 1;
        
        for(auto item : adj[nd]){
            if(!vis[item]){
                if(hasCycleDFS(item, nd, vis, adj)) return true; // LOOKOUT
            }
            else if(item != p){
                return true;
            }
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V+1, 0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(hasCycleDFS(i, -1, vis, adj)) return true;
            }
        }
        
        return false;
    }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
