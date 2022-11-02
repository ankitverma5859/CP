#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    for(int j=0; j<m; j++)
        dp[0][j] = matrix[0][j];
        
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            
            int up = matrix[i][j] + dp[i-1][j];
            
            int up_r = -1e8;
            if(j-1 >= 0) up_r = matrix[i][j] + dp[i-1][j-1]; 
            
            int up_l = -1e8;
            if(j+1 < m) up_l = matrix[i][j] + dp[i-1][j+1];  
            
            dp[i][j] = max(up, max(up_r, up_l));
        }
    }
    
    int maxi = dp[n-1][0];
    for(int j=1; j<m; j++)
        maxi = max(maxi, dp[n-1][j]);
    
    return maxi;
}
