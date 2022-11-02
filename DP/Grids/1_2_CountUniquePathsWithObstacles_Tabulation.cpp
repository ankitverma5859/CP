//Link:https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//Ref: https://www.youtube.com/watch?v=TmhpgXScLyY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=10&ab_channel=takeUforward

int mod = (int)(1e9+7);
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    //Declare the dp vector/mat
    vector<vector<int>> dp(n, vector<int>(m));
    
    //Run through each of the grid
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            
            //Obstacle Condition
            if(mat[i][j] == -1) dp[i][j] = 0;
            
            //Base Condition
            else if(i==0 and j==0) dp[i][j] = 1;
            
            else{
                //Exploring the directions
                int up=0,left=0;
                if(i>0) up = dp[i-1][j];        //If to take care of the outboutds
                if(j>0) left = dp[i][j-1];      //If to take care of the outboutds
                dp[i][j] = (up+left) % mod;
            }
        }
    }
    return dp[n-1][m-1];
}
