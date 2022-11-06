#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> parcels = {2,3,6,10,11};
	int k = 9;
	
	
	int rem_k = k - parcels.size();
	cout<<"Rem_K: "<<rem_k<<endl;
	
	int i = 1, idx = 0;
	int j = rem_k;
	vector<int> res;
	while(j){
		if(i != parcels[idx]){
			res.push_back(i);
			i++;
			j--;
		}
		else{
			i++;
			idx++;
		}
	}
	
	int sum = 0;
	for(int i=0; i<rem_k; i++)
		sum+=res[i];
		
	cout<<"Result: "<<sum<<endl;
	
	return 0;
}
