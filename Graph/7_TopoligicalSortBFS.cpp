//Link: https://practice.geeksforgeeks.org/problems/topological-sort/1
//Ref: https://www.youtube.com/watch?v=rZv_jHZva34&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=13&ab_channel=takeUforward

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //Resultant topological sorted list
	    vector<int> res;
	    
	    //Calsulate In-degrees
	    vector<int> indegrees(V, 0);
	    for(int i=0; i<V; i++){
	        for(auto it : adj[i]){
	            indegrees[it]++;
	        }
	    }
	    
	    //Create q for bfs and push elemetns which have indegree == 0
	    queue<int> q;
	    for(int i=0; i<V; i++){
	        if(indegrees[i] == 0) q.push(i);
	    }
	    
	    //Running the bfs
	    while(!q.empty()){
	        auto nd = q.front();
	        q.pop();
	        res.push_back(nd);  // as usual in bfs
	        
	        for(auto it : adj[nd]){
	            indegrees[it]--;
	            if(indegrees[it] == 0) q.push(it); //push the element in q only if indegree == 0
	        }
	    }
	    
	    return res;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
