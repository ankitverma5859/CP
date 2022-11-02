//Link: https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//Ref:  https://www.youtube.com/watch?v=TmhpgXScLyY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=10&ab_channel=takeUforward

int mod = (int)(1e9+7);

int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>> dp){

    //We return 1 when we reach a destinatino and 0 when out of bound or found an obstacle
    //Express
    //If an obstacle is found return
    if(i>=0 and j>=0 and mat[i][j] == -1)
        return 0;
    
    //If reached the source return 1
    if(i==0 and j==0)
       return 1;
    
    //if out of bound return
    if(i<0 || j<0)
        return 0;

    //if alreay calculated stack return the val
    if(dp[i][j] != -1) return dp[i][j];
            
    //Explore the directions
    int up = solve(i-1, j, mat, dp);
    int left = solve(i, j-1, mat, dp);
    
    //Sum the paths
    return dp[i][j] = (up+left) % mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n-1, m-1, mat, dp);
}
