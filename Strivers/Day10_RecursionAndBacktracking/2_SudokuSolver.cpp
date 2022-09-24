// Link: https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    bool is_valid(vector<vector<char>>& board, int row, int col, char c){
        
        for(int i=0; i<9; i++){
            //Check Row
            if(board[i][col] == c) return false;
            
            
            //Check Col
            if(board[row][i] == c) return false;

            
            //Check Box
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++)
            {
                // Find the unfilled box/cell
                if(board[i][j] == '.'){
                    
                    // Try from 1-9 for this unfilled box/cell
                    for(char c='1'; c<='9'; c++){
                        
                        // Check if c will be valid for the board
                        if(is_valid(board, i, j, c)){
                            board[i][j] = c;
                            
                            //  Recurse for the next unfilled. 
                            //  If board is already filled, then L25 will return true;
                            if(solve(board) == true) return true;
                            else board[i][j] = '.';  // backtracking
                        }
                    }
                    
                    // If none of the numbers are valid, we are reached in-consistent
                    // state and hence return false;
                    return false;
                }
            }
        }
        
        // All the cells are filled up, so return true;
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
