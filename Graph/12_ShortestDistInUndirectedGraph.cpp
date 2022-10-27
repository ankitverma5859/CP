// Ref: https://www.youtube.com/watch?v=hwCWi7-bRfI&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=15&ab_channel=takeUforward

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void bfs(int src, vector<int>& vis, vector<vector<int>> adj[]){
	    queue<int> q;
	    q.push(src);
	    vis[src] = 0;
	    
	    while(!q.empty()){
	        auto nd = q.front();
	        q.pop();
	        
	        for(auto item : adj[nd]){
	            if(vis[nd] + 1 < vis[item]){ //WatchOUT
	                vis[item] = vis[nd] + 1;
	                q.push(item);
	            }
	        }
	    }
	}
	
	
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> shortestdist(int V, vector<int> adj[], int S)
    {
        // vis is dist vector
        vector<int> vis(V, INT_MAX);
        
        for(int i=0; i<len(adj); i++){
            cout<<adj[i]<<endl;
        }
        
        for(int i=0; i<V; i++){
                bfs(S, vis, adj);
        }
        
        return vis;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
