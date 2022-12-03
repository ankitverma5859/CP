#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr1[] = {9,9,1};
	int arr2[] = {1,2,1};
	int n = sizeof(arr1) / sizeof(arr1[0]);
	
	vector<int> res;
	int carry = 0;
	
	for(int i=n - 1; i>=0; i--){
		int sum = arr1[i] + arr2[i] + carry;
		
		if(sum < 10){
			res.push_back(sum);	
		} 
		else{
			res.push_back(sum%10);
			carry = sum/10;
		}
	}
	if(carry > 0)
		res.push_back(carry);
	
	reverse(res.begin(), res.end());
	
  cout<<"Sum: "<<endl;
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";	
	return 0;
}

