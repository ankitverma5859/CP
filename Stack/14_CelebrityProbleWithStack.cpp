// Link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
// O(N)

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        
        // Push all the elements in the stack
        for(int i=0; i<n; i++)
            s.push(i);
        
        // We take two elements from the stack 
        while(s.size() > 1){
            int i = s.top(); s.pop();
            int j = s.top(); s.pop();
            
            if(M[i][j] == 1)
                s.push(j);
            else
                s.push(i);
        }
        
        //Check row of s.top(); all should be zero
        bool rowCheck = true;
        for(int i=0; i<n; i++){
            if(M[s.top()][i] == 1){
                rowCheck = false;
                break;
            }
        }
        
        //Checl col of s.top(); all should be 1 except the its own
        bool colCheck = true;
        int oneCount = 0;
        for(int i=0; i<n; i++){
            if(M[i][s.top()] == 1){
                oneCount++;
            }
        }
        
        if(oneCount != n-1)
            colCheck = false;
            
        int result = -1;
        if(rowCheck and colCheck)
             result = s.top();
        
        return result;
    }
};
