#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef pair<long double, vector<int>> pi;

long double find_dist(int x, int y){
	return sqrt(x*x + y*y);
}

int main() {
	vector<vector<int>> hotel_coords = {{1,2},{3,4},{1,-1}};
	int num_hotels = 2;
	
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	for(int i=0;i<hotel_coords.size(); i++){
		vector<int> coords;
		coords.push_back(hotel_coords[i][0]);
		coords.push_back(hotel_coords[i][1]);
		pq.push(make_pair(find_dist(hotel_coords[i][0], hotel_coords[i][1]), coords));
	}
	
	cout<<"Closest Restaurants: "<<endl;
	while(num_hotels--){
		auto res = pq.top();
		cout<<res.second[0]<<" "<<res.second[1]<<" Dist:"<<res.first<<endl;
		pq.pop();
	}

	return 0;
}
