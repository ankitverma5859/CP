/*
INPUT
3 
ibl
olh
mkd
4 
1 1 2
3 1 2
2 4 3
1 1 3
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
	Erase x in nth set
*/
void type3(vector<set<char>>& sets, char x, int n){
	//cout<<"Erasing"<<endl;
	sets[n].erase(x);
	//cout<<"Successful"<<endl;
}


void type2(vector<set<char>>& sets, char x, int n){
	//cout<<"Inserting"<<endl;
	sets[n].insert(x);
	//cout<<"Successful"<<endl;
}

void type1(vector<set<char>>& sets, int l, int r){
	vector<int> alphabets(26,0);
	
	for(int i=l; i<=r; i++){
		for(auto c : sets[i]){
			int ch = c - 'a';
			alphabets[ch]++;
		}
	}
	
	int res = 0;
	for(int i=0;i<26;i++){
		res += alphabets[i] % 2;
	}
	cout<<res<<" ";
}


int main() {
	int n;
	cin>>n;
	vector<set<char>> sets;
	vector<vector<int>> queries;
	//Creating sets
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		set<char> s;
		for(int j=0; j<str.size(); j++)
			s.insert(str[j]);
		sets.push_back(s);
	}
	
	/*
	//Sets
	for(int i=0;i<n;i++){
		for(auto a : sets[i]){
			cout<<a<<" ";
		}
		cout<<endl;
	}
	*/
	
	int m ;
	cin>>m;
	for(int i=0; i<m; i++){
		int cmd_type, a, b;
		cin>>cmd_type;
		cin>>a;
		cin>>b;
		vector<int> q;
		q.push_back(cmd_type);
		q.push_back(a);
		q.push_back(b);
		queries.push_back(q);
	}
	
	/*
	//Queries
	for(int i=0; i<queries.size(); i++)
	{
		cout<<queries[i][0]<<" "<<queries[i][1]<<" "<<queries[i][2]<<endl;
	}
	*/
	
	for(int i=0; i<queries.size(); i++)
	{
		//cout<<queries[i][0]<<" "<<queries[i][1]<<" "<<queries[i][2]<<endl;
		switch(queries[i][0]){
			case 1: type1(sets, queries[i][1]-1, queries[i][2]-1);
				break;
			case 2: type2(sets, 'a' + queries[i][1] - 1, queries[i][2]-1);
				break;
			case 3: type3(sets, 'a' + queries[i][1] - 1, queries[i][2]-1);
				break;
		}
	}
	
	return 0;
}
