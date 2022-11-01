//Link:https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?leftPanelTab=1
//Ref: https://www.youtube.com/watch?v=sdE0A2Oxofw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=10&ab_channel=takeUforward

#include <bits/stdc++.h> 
/*
    TC: O(m*n)
    SC: O((m-1)+(n-1)) + O(m*n)
        path             dp
*/
int solve(int i, int j, vector<vector<int>>& dp){
    if(i==0 and j==0)
        return 1;
    
    if(i<0 || j<0)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int up = solve(i-1, j, dp);
    int left = solve(i, j-1, dp);
    int ans = up+left;
    dp[i][j] = ans;
    return ans;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n,-1));
    return solve(m-1, n-1, dp);
}
