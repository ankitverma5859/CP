//Link: https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470


#include <bits/stdc++.h> 

int solve(int i, int j){
    /*
        Express   (Write the base case and the out of bounds)
        Explore   (The possible directions in which we can move)
        Sum       (Sum the explored directions)
    */
  
    //Explore
    //Base Case: When we reach the destination or out of bound
    if(i==0 and j==0) // When we reach the destination we return 1
        return 1;

    //Since only two movements are allowed, i.e down and right
    //                                       which becomes top and left as we are going in the reverse direction we return 0
    if(i<0 || j<0).   
        return 0;
    
    //Express
    int up = solve(i-1, j);         //Moving up
    int left = solve(i, j-1);       //Moving left
    
    //Sum
    return up+left;                 //Suming up the solution
}

int uniquePaths(int m, int n) {
    //We want to reach (m-1, n-1) as such we try find how many ways we can reach from (m-1, n-1) to (0,0).
    //Here, we try to walk from destination to source
    return solve(m-1, n-1);
}
