

//Link: https://www.youtube.com/watch?v=_rgTlyky1uQ&ab_channel=takeUforward
//Ref:  https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include <bits/stdc++.h> 

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    //Creating the dp matrix
    vector<vector<int>> dp(n, vector<int>(m,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //Base Condition
            if(i==0 and j==0)
                dp[i][j] = grid[i][j];
            else{
                int up, left;
                if(i>0) up = grid[i][j] + dp[i-1][j];       //If the move is valid i.e within grid
                else up = INT_MAX;                          //If the move is out of grid
                
                if(j>0) left = grid[i][j] + dp[i][j-1];     //If the move is valid i.e within grid
                else left = INT_MAX;                        //If the move is out of grid
                
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n-1][m-1];
}
