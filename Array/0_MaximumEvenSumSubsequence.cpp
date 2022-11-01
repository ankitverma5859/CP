//Link: https://www.hackerrank.com/contests/coding-fever/challenges/maximum-sum-11
//Tag: Paypal

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /*
        Problem: Find the maximum even sum of a subsequence
        Approach:
            1. Find the sum of all the positive integers.
            2. If the sum is even, you got your answer.
            3. If the sum is not ever:
            4.        Find max of (positive_sum - positive_odd_integers[i])
            5.        Find max of (positive_sum + negative_odd_integers[i])
    */
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    
    
    int pos_sum = 0;
    for(int i=0; i<n; i++){
        if(nums[i] > 0)
            pos_sum += nums[i];
    }
    
    if(pos_sum % 2 == 0){
        cout<<pos_sum;
        return 0;
    } 
    
    //Add a positive odd number and check           E.g  pos_sum = 7, odd_num = 1;  new_sum = 8
    //Subtract a negative odd number and check      E.g  pos_sum = 7, odd_num = -1; new_sum = 8
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        if(nums[i]%2 != 0){
            if(nums[i] > 0)
                ans = max(ans, pos_sum - nums[i]);
            else
                ans = max(ans, pos_sum + nums[i]);
        }
    }
    cout<<ans;
    return 0;
}
