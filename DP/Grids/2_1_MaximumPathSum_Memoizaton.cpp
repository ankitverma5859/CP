//Link: https://www.youtube.com/watch?v=_rgTlyky1uQ&ab_channel=takeUforward
//Ref:  https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include <bits/stdc++.h> 
int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //Express
    if(i==0 and j==0)
        return grid[i][j];
    
    if(i<0 or j<0)
        return 1e9+7; //a large number so that it is not considered in min function
    
    if(dp[i][j] != -1) return dp[i][j];
    
    //Explore
    //Take the current val and move up
    //Take the current val and move left
    int up = grid[i][j] + solve(i-1,j,grid, dp);
    int left = grid[i][j] + solve(i,j-1,grid, dp);
    
    //Minimize/Sum
    return dp[i][j] = min(up, left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    return solve(n-1,m-1,grid, dp);
}
