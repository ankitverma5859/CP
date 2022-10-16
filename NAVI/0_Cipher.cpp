#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	map<char, char> m;
	char A = 'A';
	for(auto c : s){
		if(m.find(c) == m.end()){
			m[c] = A;
			A = A + 1;	
		}
	}

	string res = "";
	for(auto c : s)
		res += m[c];
	
	cout<<res;
	return 0;
}
