#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
	How to find if the given graph as a mother vertex or not?
	Mother Vertex: A node in the graph from which all other nodes can be reached.
	
	Step 1: Run DFS on all the nodes in the graph and store all the visited nodes
			in a vector(perhaps order)
			
	Step 2: If a mother vertex exists then the last element in the order will be
			the mother vertex.
			
	Step 3: Run dfs on the last node in the order vector. If the returned order 
			has all the nodes then it is a mother vertex.
*/


void dfs(vector<int> adj[], vector<int>& vis, int node, vector<int>& order){
	vis[node] = 1;
	for(int ad_node : adj[node]){
		if(!vis[ad_node])
			dfs(adj, vis, ad_node, order);
	}
	order.push_back(node);
}

int main() {
	//vector<pair<int, int>> edges = {{1,3},{2,3}};
	vector<pair<int, int>> edges = {{4,6}, {7,6}, {7,4}, {7,1}, {7,8}, {4,5}, {1,2}, {2,3}};
	int n = 8;
	
	//Creating the Adjacency Matrix
	vector<int> adj[n];
	for(int i=0;i<edges.size();i++){
		adj[(edges[i].first) - 1].push_back((edges[i].second) - 1);
	}

	vector<int> res;
	vector<int> vis(n, 0);
	vector<int> order;
	
	//Runninf dfs on all the nodes to create order vector.
	for(int i=0;i<n;i++){
		if(!vis[i])
			dfs(adj, vis, i, order);
	}
	
	//Extracting the last element from the vertex
	int last_element = order[order.size() - 1];
	order.clear();
	
	//Running dfs on the last node to check if it can cover all the nodes
	vector<int> vis1(n,0);
	dfs(adj, vis1, last_element, order);
	
	//If size matches hola, the last node is a mother node.
	int result = order.size() == n;
	cout<<result;
	
	return 0;
}
