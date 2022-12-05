//Ref: https://www.geeksforgeeks.org/find-all-occurrences-of-the-word-in-a-matrix/

#include <iostream>
#include <bits/stdc++.h>
#define m 3
#define n 5

using namespace std;

int rowNum[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int colNum[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isValid(int i, int j, int prevR, int prevC){
	return (i>=0 && i<m) &&
			(j>=0 && j<n) &&
			!(i == prevR && j == prevC);
}

void dfs(vector<vector<char>>& mat, int i, int j, int prevR, int prevC, string word, string res, int idx, int w_s){
	if(idx > n || (mat[i][j] != word[idx])) return;
	
	res += "(" + to_string(i) + "," + to_string(j) + ")";
	
	if(idx == w_s){
		cout<<res<<endl;
		return;
	}
	
	for(int k=0;k<8;k++){
		if(isValid(i+rowNum[k], j+colNum[k], i, j)){
			dfs(mat, i+rowNum[k], j+colNum[k], i, j, word, res, idx+1, w_s);
		}
	}
}

void findwords(vector<vector<char>>& mat, string word, int w_s){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j] == word[0])
				dfs(mat, i, j, -1, -1, word, "", 0, w_s);
		}
	}	
}

int main() {
	
	string word = "DES";
	
	vector<vector<char>> mat(m, vector<char>(n)); 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			char c;
			cin>>c;
			mat[i][j] = c;
		}
	}
	
	/*
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	
	//Find all the occurances
	findwords(mat, word, word.size() - 1);
	
	return 0;
}
