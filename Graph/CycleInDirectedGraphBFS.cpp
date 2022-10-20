//Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//Ref: https://www.youtube.com/watch?v=V6GxfKDyLBM&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=14&ab_channel=takeUforward

/*
  We know that Kahn's Algo is used for topological sorting in Directed "Acyclic" Graph.
  If Kahn's algoright is able to return the topological sort then a given graph doesn't have a cycle.
  
  We make a lil modification in Kahn's also. Instead of inserting the nodes in the result vector, we keep a count. 
  If the final count is equal to the no of nodes in the graph, Kahn's also was able to give a topo sort and hence no cycle else there is a cycle.
*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        queue<int> q;
        
        //Calculating indegrees
        vector<int> indegrees(V, 0);
        for(int i=0; i<V; i++){
            for(auto it : adj[i])
                indegrees[it]++;
        }
        
        //Push nodes with indegreee = 0 in queue
        for(int i=0; i<V; i++){
            if(indegrees[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]){
                indegrees[it]--;
                if(indegrees[it] == 0) q.push(it);
            }
        }
        
        if(cnt == V) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
