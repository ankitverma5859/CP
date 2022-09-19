//Link: https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=1

#include <bits/stdc++.h> 

using namespace std;

int recur(int ind, vector<int>& heights, vector<int>& dp){
    if(ind == 0) 
        dp[ind] = 0;

    if(dp[ind] != INT_MAX)
        return dp[ind];
        
    int left  = INT_MAX, right = INT_MAX;
    left = recur(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);
    if(ind-2 >= 0) right = recur(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2]);
    return dp[ind] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, INT_MAX);
    //Start with n-1 because the stair number start from index 1
    return recur(n-1, heights, dp);
}
