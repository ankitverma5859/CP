/*
INPUT:
5

Bangalore Hyderabad

Bangalore Chennai

Hyderabad Mumbai

Hyderabad Delhi

Chennai Kerala

Bangalore

*/

// Link: https://discuss.codechef.com/t/interview-question-of-springworks-editorial/93073

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(int s_country, vector<int>& vis, vector<int>& res, vector<int> adj[]){
	//cout<<"C:"<<s_country<<endl;
	res.push_back(s_country);
	vis[s_country] = 1;
	
	for(auto item : adj[s_country]){
		//cout<<"Hello1 "<<item<<endl;
		if(!vis[item]){
			dfs(item, vis, res, adj);
		}
	}
}

int main() {
	
	// Reading the number of paths
	int n;
	cin>>n;
	string s;
	set<string> cities;
	
	// Printing the number of paths
	//cout<<"N:"<<n<<endl;
	
	// Reading the paths
	vector<pair<string, string>> paths;
	for(int i=0; i<n; i++){
		pair<string, string> path;
		string c1;
		string c2;
		cin>>c1;
		cin>>c2;
		path.first = c1;
		path.second = c2;
		cities.insert(c1);
		cities.insert(c2);
		paths.push_back(path);
	}
	cin>>s;
	
	
	//for(auto city : cities)
	//	cout<<city<<" "<<endl;
	
	// Map for City to Index
	map<string, int> c2i;
	int idx = 0;
	for(auto city : cities){
		c2i[city] = idx;
		idx++;
	}
	
	// Map for Index to City
	map<int, string> i2c;
	for(auto item : c2i){
		i2c[item.second] = item.first;
	}
	
	// Creating the adjacency list
	vector<pair<int, int>> paths_int;
	for(auto path : paths){
		pair<int, int> p;
		p.first = c2i[path.first];
		p.second = c2i[path.second];
		paths_int.push_back(p);
	}
	
	// Directed Paths
	//for(auto path : paths_int){
	//	cout<<path.first<<" "<<path.second<<endl;
	//}

	
	// Creating the adjacency list
	vector<int> adj[n+1];
	for(auto i : paths_int){
		adj[i.first].push_back(i.second);
	}
	
	// Print the index adjacency paths
	/*
	int index = 0;
	for(auto item : adj){
		cout<<index<<":";
		for(auto i : item)
			cout<<i<<" ";
		cout<<endl;
		index++;
		cout<<endl;
	}
	*/
	
	// Running the DFS
	vector<int> vis(n+1, 0);
	vector<int> res;
	cout<<"SC:"<<c2i[s]<<endl;
	dfs(c2i[s], vis, res, adj);
	
	cout<<"Path"<<endl;
	for(auto i : res)
		cout<<i2c[i]<<" -> ";
	
	cout<<"The End";
	return 0;
}
