//Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void dfs(int i, vector<int>& vis, vector<int>& dfs_res, vector<int> adj[]){
        dfs_res.push_back(i);;
        vis[i] = 1;
        
        for(auto item : adj[i]){
            if(!vis[item]){
                dfs(item, vis, dfs_res, adj);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfs_res;
        vector<int> vis(V, 0);
        
        //for(int i=0; i<V; i++){     //Uncomment for disconnected graph
        //  if(!vis[i]){
            //Starting with 0 node
            dfs(0, vis, dfs_res, adj);  
       //   }
       // }
            
        return dfs_res;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
