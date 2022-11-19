#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int l, int r){
	if(l == r) return true;
	
	while(l<r){
		if(s[l] != s[r]) return false;
		l++;
		r--;
	}
	return true;
}

int main() {
	string s;
	cin>>s;
	vector<int> res;
	
	int last = 0;
	for(int i=0;i<s.size();i++){
		bool isP = isPalindrome(s, 0, i);
		if(isP){
			res.push_back(i+1);
			last = i+1;
		}
		else{
			res.push_back(last);
		}
	}
	
	for(int i=0; i<res.size(); i++)
		cout<<res[i]<<" ";
	return 0;
}
