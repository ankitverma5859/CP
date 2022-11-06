// 1 2 3 4
// 3 5 7
// 8 2(12%10)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> getres(vector<int>& arr){
	if(arr.size() == 2){
		return arr;
	}

	for(int i=0; i<arr.size()-1; i++){
		int num = arr[i] + arr[i+1]; 
		arr[i] = num > 9 ? num % 10 : num;
	}

	arr.pop_back();
	
	return getres(arr);
}

int main() {
	vector<int> a = {1,2,3,4};
	//3,5,147
	//8, 152
	
	vector<int> res = getres(a);
	for(int i=0; i<res.size(); i++)
		cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}
