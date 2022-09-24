class Solution {
public:
    // Since we are placing the queens on one column at a time.
    // We will only check for any clash on the left side directions i.e left, top-left, bottom-left.
    // We are excluding top, bottom because we will keep one queen in a column.
    bool is_safe(int row, int col, vector<string>& board, int n){
        
        int d_row = row;
        int d_col = col;
        // Check for top-left direction row-- and col--
        while(row>=0 and col>=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        row = d_row;
        col = d_col;
        //Check for left direction;
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        row = d_row;
        col = d_col;
        //Check for bottom-left col++, row--
        while(row<n and col>=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    void solve(int col, vector<string>& board, vector<vector<string>>& result, int n){
        if(col == n){
            result.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(is_safe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, result, n);
                board[row][col] = '.';
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        
        //Creating a board of size n
        vector<string> board(n);
        
        // Creating a row of the board
        string s(n, '.');
        
        //Filling the board with the row string i.e (.)
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        
        // 0 is the col where we try to palce the queen
        solve(0, board, result, n);
        return result;
    }
};
