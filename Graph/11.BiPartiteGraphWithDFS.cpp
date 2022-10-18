//Link: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool checkBipartite(int nd, vector<int>& vis, vector<int> adj[]){
        for(auto item : adj[nd]){
            if(vis[item] == -1){
                vis[item] = !vis[nd];
                if(!checkBipartite(item, vis, adj)) return false;
            } 
            else if(vis[item] == vis[nd]){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        //Creating Adjacency List
        vector<int> adj[n+1];
        for(int i=0; i<graph.size(); i++){
            for(int j=0; j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        
        //Creating visited array and initializing with -1
        //Later it will be initialized with 0 and 1 colors for bipartite checking
        vector<int> vis(n+1, -1);
        
        //DFS
        for(int i=0; i<n; i++){
            if(vis[i] == -1){
                vis[i] = 0;
                if(!checkBipartite(i, vis, adj)) return false;
            }
        }
        return true;
    }
};
