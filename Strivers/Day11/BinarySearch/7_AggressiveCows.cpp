//Link: https://www.spoj.com/submit/AGGRCOW/
//Reference: https://www.youtube.com/watch?v=wSOfYesTBRk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=71&ab_channel=takeUforward

#include<bits/stdc++.h>
using namespace std;

bool canPlaceCows(vector<int>& barns, int n, int c, int mid){
	int currCow = barns[0];
	int count = 1;
	for(int i=1; i<n; i++){
		if(barns[i]-currCow >= mid){
			currCow = barns[i];
			count++;
		}
		
		if(count == c)
			return true;
	}
	return false;
}

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int n, c;
		cin>>n>>c;
		int total_barns = n;
		vector<int> barns;
		while(total_barns--){
			int i;
			cin>>i;
			barns.push_back(i);
		}
		
    // Sort the barns so that we can apply binary search
		sort(barns.begin(), barns.end());
		
		//for(auto i : barns)
		//	cout<<i<<" ";
			
    // We check if at a particular distance we can place the cows. Our search space is 1(min distance) and arr[n-1]-arr[0](largest distance)
    // if at mid distnace cows can be place, we try to see if cows can be place at a higher distance by checking in left side of the search space i.e left = mid +1
    // Otherwise we check for lower distance i.e right = mid -1
    
		//low and high is the distance space that we are considering
		int low = 1, high = barns[n-1] - barns[0];
		int res;
		while(low <= high){
			int mid = (low + high) >> 1;
			if(canPlaceCows(barns, n, c, mid)){
				res = mid;
				low = mid + 1;
			}
			else{
				high = mid -1;
			}
		}
		cout<<res;
	}
}
