//https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        unordered_set<int> rows;
        unordered_set<int> cols;

        for(int i=0; i<matrix.size();i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        //Fill Rows
        for(int r : rows){
            for(int j=0;j<matrix[0].size();j++){
                matrix[r][j] = 0;
            }
        }

        //Fill Cols
        for(int c : cols){
            for(int i=0;i<matrix.size();i++){
                matrix[i][c] = 0;
            }
        }
    }
};
