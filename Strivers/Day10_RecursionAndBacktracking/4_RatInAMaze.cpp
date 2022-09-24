// Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    public:
    void solve(int i, int j, vector<vector<int>>& m, vector<vector<int>>& visited, int n, vector<string>& ans, string move){
        if(i == n-1 and j == n-1){
            ans.push_back(move);
            return;
        }
        
        //Since, we have to return in lexicographic order, we will move in DLRU sequene
        //Downward
        // i should be in range
        // visited(i+1, j) shouldn't be visited
        // there should be 1 i.e path should be there
        if(i+1<n and !visited[i+1][j] and m[i+1][j] == 1){
            visited[i][j] = 1;
            solve(i+1, j, m, visited, n, ans, move + "D");
            visited[i][j] = 0;
        }
        
        //Left
        if(j-1 >= 0  and !visited[i][j-1] and m[i][j-1] == 1){
            visited[i][j] = 1;
            solve(i, j-1, m, visited, n, ans, move + "L");
            visited[i][j] = 0;
        }
        
        //Right
        if(j+1<n and !visited[i][j+1] and m[i][j+1] == 1){
            visited[i][j] = 1;
            solve(i, j+1, m, visited, n, ans, move + "R");
            visited[i][j] = 0;
        }
        
        //Up
        if(i-1 >= 0 and !visited[i-1][j] and m[i-1][j] == 1){
            visited[i][j] = 1;
            solve(i-1, j, m, visited, n, ans, move + "U");
            visited[i][j] = 0;
        }
            
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        if(m[0][0] == 1) solve(0,0, m, visited, n, ans, "");
        return ans;
    }
};
