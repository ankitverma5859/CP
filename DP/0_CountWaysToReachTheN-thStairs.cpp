//Link: https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0

#include <bits/stdc++.h> 
int mod = 1e9+7;

int countWays(int n, vector<int>& dp)
{
    if(dp[n] != -1)
        return dp[n];
    
    return dp[n] = (countWays(n-1, dp) + countWays(n-2, dp))%mod;
}

int countDistinctWays(int nStairs) {
    vector<int> dp(nStairs+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    return countWays(nStairs, dp);
}
