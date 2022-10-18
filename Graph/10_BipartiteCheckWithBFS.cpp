//Link: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool checkBipartite(int nd, vector<int>& vis, vector<int> adj[]){
        queue<int> q;
        q.push(nd);
        vis[nd] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int node_color = vis[node];
            
            for(auto item : adj[node]){
                if(vis[item] == -1){
                    q.push(item);
                    vis[item] = !node_color;
                }
                else if(vis[item] == vis[node]){
                    return false;
                }
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
        
        //BFS
        for(int i=0; i<n; i++){
            if(vis[i] == -1){
                if(!checkBipartite(i, vis, adj)) return false;
            }
        }
        return true;
    }
};
