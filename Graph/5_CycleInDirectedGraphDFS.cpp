//Link: https://www.codingninjas.com/codestudio/problems/1062626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
//Ref:  https://www.youtube.com/watch?v=uzVUw90ZFIg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=11&ab_channel=takeUforward

bool hasCycle(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfsvis){
    vis[node] = 1;
    dfsvis[node] = 1;
    for(auto item : adj[node]){
        if(!vis[item]){
            if(hasCycle(item, adj, vis, dfsvis)) return true;
        }
        else if(dfsvis[item]){
            return true;
        }
    }
    dfsvis[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

    // Creating the adjacency matrix
    vector<int> adj[n+1];
    for(int i=0; i<edges.size(); i++){
        adj[edges[i].first].push_back(edges[i].second);
    }
    
    vector<int> vis(n+1, 0);
    vector<int> dfsvis(n+1, 0);
    for(int i=1; i<n+1; i++){
        if(!vis[i]){
            if(hasCycle(i, adj, vis, dfsvis)) return true;
        }
    }
    return false;
}
