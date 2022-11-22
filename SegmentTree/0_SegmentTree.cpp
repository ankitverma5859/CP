#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
5
1 2 0 -1 5
2
1 2
0 4
2
1 5
0 -2
2
0 2
1 4
*/
void build_segment_tree(int idx, int low, int high, int arr[], int seg[]){
	//This is the base case, i.e leaf node [0-0] [1-1] i.e only one element to compare
	if(low == high){
		seg[idx] = arr[low];
		return;
	}
	
	//Create two halves
	int mid = (low + high) >> 1;
	build_segment_tree(2*idx + 1, low, mid, arr, seg);			//Left Node
	build_segment_tree(2*idx + 2, mid+1, high, arr, seg);		//Right Node
	
	//Here, when recurion returns, both left and right values are filled in segment tree
	//Thus
	seg[idx] = min(seg[2*idx + 1], seg[2*idx + 2]);
}

int query_segment_tree(int idx, int low, int high, int l, int r, int seg[]){
	/*
		Here we have to deal with three conditions
		1) No-Overlap				(l r) [low - high] (l r)  return INT_MAX
		2) Complete Overlap			[l (low high) r]
		3) Partial Overap			Somepart is overlapped
	*/
	
	// Watch out the conditions ><
	
	//no-overlap
	if(r < low or high < l) return INT_MAX;
	
	//complete overlap
	if(low >= l and high <= r) return seg[idx];
	
	//partial overlap
	int mid = (low + high) >> 1;
	int left = query_segment_tree(2*idx+1, low, mid, l, r, seg);
	int right = query_segment_tree(2*idx+2, mid+1, high, l, r, seg);
	return min(left, right);
}

/*
	idx is the current index
	id is the index at which val needs to be updated
*/
void update_segment_tree(int idx, int low, int high, int id, int val, int seg[]){
	/*
		Two things need to be taken care
			1) Updating the value at the given index
			2) Updated nodes in the segment tree since the min/max will also change
	*/
	
	if(low == high){
		seg[idx] = val;
		return;
	}
		
	
	int mid = (low + high) >> 1;
	
	if(id <= mid) update_segment_tree(2*idx+1, low, mid, id, val, seg);
	else update_segment_tree(2*idx+2, mid+1, high, id, val, seg);
	
	//Here, both left(2*idx+1) and right(2*idx+2) have been updated so lets update
	seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
}

int main() {
	
	int n;
	cin>>n;
	
	// Create an array to store the input elements
	// Create a segment tree, size will be 4*n
	int arr[n], seg[4*n];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	/*
		Important Concept:
			A segment tree is build with the logic that the root node has the least value
			among all the elements i.e from range [0-n]
			
			Then, its children will have two nodes of equal halves i.e 
			Left : [0 - mid] 
			Right : [mid+1 - n]
			
			We also give index value to each node where root node's index is 0.
			And left node's index of a node is (2*idx + 1)
			and right node's index of a node is (2*idx + 2)
	*/
					  //idx, low, high, input arr, segment tree
	build_segment_tree(0, 0, n-1, arr, seg);
	
	//Now we will process queries
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int l, r;
		cin>>l>>r;
													//idx, low, high, l, r, seg
		cout<<"Min between "<<l<<" and "<<r<<" is "<<query_segment_tree(0, 0, n-1, l, r, seg)<<endl;
	}
	
	//Now lets process updates
	int u;
	cin>>u;
	for(int i=0;i<u;i++){
		int id, val;
		cin>>id>>val;
		update_segment_tree(0, 0, n-1, id, val, seg);
	}
	
	//Now we will process queries
	cout<<"After the updates:"<<endl;
	int q1;
	cin>>q1;
	for(int i=0;i<q1;i++){
		int l, r;
		cin>>l>>r;
													//idx, low, high, l, r, seg
		cout<<"Min between "<<l<<" and "<<r<<" is "<<query_segment_tree(0, 0, n-1, l, r, seg)<<endl;
	}
		
	return 0;
}
