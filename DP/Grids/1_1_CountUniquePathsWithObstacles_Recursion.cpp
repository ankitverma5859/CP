//Link:https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//Ref: https://www.youtube.com/watch?v=TmhpgXScLyY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=10&ab_channel=takeUforward

int solve(int i, int j, vector<vector<int>>& mat){
    if(i>=0 and j>=0 and mat[i][j] == -1)
        return 0;
    
    if(i==0 and j==0)
       return 1;
    
    if(i<0 || j<0)
        return 0;
    
    int up = solve(i-1, j, mat);
    int left = solve(i, j-1, mat);
    return up+left;    
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    return solve(n-1, m-1, mat);
}
