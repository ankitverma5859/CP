//Link: https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//Ref:  https://www.youtube.com/watch?v=_rgTlyky1uQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=11&t=2s&ab_channel=takeUforward

#include <bits/stdc++.h> 
int solve(int i, int j, vector<vector<int>>& matrix, int n, int m){
    //Express
     if(j<0 || j>=m)
         return -1e7;  //very small number
    
     if(i==0) return matrix[i][j];
    
    //Explore
    //All the possible directions
    int up = matrix[i][j] + solve(i-1, j, matrix, n, m);
    int up_r = matrix[i][j] + solve(i-1, j+1, matrix, n, m);
    int up_l = matrix[i][j] + solve(i-1, j-1, matrix, n, m);
    
    //Sum
    //Taking the maximum among the directions
    return max(up, max(up_r, up_l));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
  
    //Since, the problem has variable starting point and variable ending point. We find max sum for each ending point i.e [0-m] each ending col
    //Like previous problems, we start from the end point and reach the start point.
    int ans = -1e7;
    for(int i=0; i<m; i++){
        //We solve for each ending point and find the max among them
        ans = max(ans, solve(n-1, i, matrix, n, m));
    }
    return ans;
}
