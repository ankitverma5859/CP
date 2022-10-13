//Link: https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        // Return if the indexes go out of bound
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size())
            return;
        
        // Return if the node is already visited or is a water block
        if(grid[i][j] == '2' or grid[i][j] == '0')
            return;
        
        // Marking the grid as visited
        grid[i][j] = '2';
        
        // Moving in all four directions
        dfs(grid, i-1, j); // top
        dfs(grid, i+1, j); // down
        dfs(grid, i, j+1); // right
        dfs(grid, i, j-1); // left
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                // If it is a land block we trace all the land pieces until done
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};
