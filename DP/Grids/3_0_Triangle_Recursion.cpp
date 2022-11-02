//Link: https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
//Ref:  https://www.youtube.com/watch?v=SrP-PiLSYC0&ab_channel=takeUforward

#include <bits/stdc++.h> 

int solve(int i, int j, vector<vector<int>>& triangle, int n){
    
    //Express
    //If it reaches the last row return
    if(i == n-1)
        return triangle[i][j];
    
    //It will not go out of bound as only down and diagonol moves are allowed
    
    //Explore
    //Take the current val and move in the possible direction
    int down = triangle[i][j] + solve(i+1, j, triangle, n);
    int diag = triangle[i][j] + solve(i+1, j+1, triangle, n);
    
    //Sum/Min/Max
    return min(down, diag);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    //In this case unlike the previous question we are starting from the source node. 
    //Since the destination node is not fixed(aka varible destination point we start from the fixed point)
    return solve(0,0, triangle, n);
}
