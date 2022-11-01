//Link:https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?leftPanelTab=1
//Ref: https://www.youtube.com/watch?v=sdE0A2Oxofw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=10&ab_channel=takeUforward
#include <bits/stdc++.h> 
/*
    TC: O(m*n)
    SC: O(O(m*n)
          dp
*/
int uniquePaths(int m, int n) {
    int dp[m][n];
    dp[0][0] = 1;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 and j==0)
                dp[i][j] = 1;
            else{
                int up=0, left = 0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}
