// Link: https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<kArrays.size();i++){
        vector<int> arr = kArrays[i];
        for(int j=0;j<arr.size(); j++){
            pq.push(arr[j]);
        }
    }
    vector<int> res;
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
