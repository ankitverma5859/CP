//Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool hasCycleBFS(int s, vector<int>& vis, vector<int> adj[]){
       //Marking s aka starting nodes as visited
       vis[s] = 1;
       
       //Pair of {node, parent}
       //For starting node we declare -1 as its parent since it doesnt have any parent.
       queue<pair<int, int>> q;
       q.push({s, -1});
       
       while(!q.empty()){
           auto node = q.front();
           q.pop();
           int n = node.first;
           int p = node.second;
           
           for(auto item : adj[n]){
               if(!vis[item]){
                   vis[item] = 1;
                   q.push({item, n});
               }
               // Here we check if the current node is visited and is not the 
               // previous node/parent node, then it was visited earlier and hence 
               // we have reached the same place again visited by someone else
               // Thus cycle exists.
               else if(p != item) 
                return true;
           }
       }
       return false;
   }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        //Creating a visited array to track visited nodes
        vector<int> vis(V, 0);
        
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                //Check if cycle exists using BFS
                if(hasCycleBFS(i, vis, adj)) return true;
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
