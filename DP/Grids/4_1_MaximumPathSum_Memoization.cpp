//Link: https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//Ref:  https://www.youtube.com/watch?v=_rgTlyky1uQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=11&t=2s&ab_channel=takeUforward

#include <bits/stdc++.h> 
int solve(int i, int j, vector<vector<int>>& matrix, int n, int m, vector<vector<int>>& dp){
    //Express
     if(j<0 || j>=m)
         return -1e7;  //very small number
    
     if(i==0) return matrix[i][j];
    
    if(dp[i][j] != -1) return dp[i][j];
    
    //Explore
    int up = matrix[i][j] + solve(i-1, j, matrix, n, m, dp);
    int up_r = matrix[i][j] + solve(i-1, j+1, matrix, n, m, dp);
    int up_l = matrix[i][j] + solve(i-1, j-1, matrix, n, m, dp);
    
    //max
    dp[i][j] = max(up, max(up_r, up_l));
    return dp[i][j];
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    int ans = -1e7;
    for(int i=0; i<m; i++){
        vector<vector<int>> dp(n, vector<int>(m, -1));
        ans = max(ans, solve(n-1, i, matrix, n, m, dp));
    }
    return ans;
}
