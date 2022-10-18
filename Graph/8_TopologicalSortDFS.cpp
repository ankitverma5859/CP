//Link: https://www.codingninjas.com/codestudio/problems/982938?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
// Ref: https://www.youtube.com/watch?v=Yh6EFazXipA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12&ab_channel=takeUforward

#include <bits/stdc++.h> 
void dfs(int i, vector<int>& vis, vector<int> adj[], stack<int>& s){
    vis[i] = 1;
    for(auto item : adj[i]){
        if(!vis[item]){
            dfs(item, vis, adj, s);
        }
    }
    s.push(i);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    //Creating the adjacency matrix
    vector<int> adj[v];
    for(int i=0; i<e; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    //Visited Array
    vector<int> vis(v, 0);
    
    //Stack to store the topological sorted items
    stack<int> s;
    
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, vis, adj, s);
        }
    }
    
    vector<int> res;
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}
