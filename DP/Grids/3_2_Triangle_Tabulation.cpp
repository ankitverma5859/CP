//Link: https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
//Ref:  https://www.youtube.com/watch?v=SrP-PiLSYC0&ab_channel=takeUforward

#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    //Base Condition
    for(int j=0; j<n; j++) dp[n-1][j] = triangle[n-1][j];
    
    //Tabulation is will just opposite of the recursion
    //In the recursion we moved from top to bottom of the triagle, here we move from bottom to up
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int down = triangle[i][j] + dp[i+1][j];
            int diag = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, diag);
        }
    }
  
    //Minimum will be stored at dp[0][0]
    return dp[0][0];
}
