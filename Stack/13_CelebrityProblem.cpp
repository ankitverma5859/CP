//Link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // Created celeb vector to keep a count of how many people know an i-th person
        // if celeb[0] = 2 means 2 people know person-0
        vector<int> celeb(n, 0);
      
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(M[i][j] == 1){
                    // if M[i][j] == 1 i.e i-th person knows j-th person so we increment celeb[j] with 1
                    // Do not increment if this index already knows someone else, he fails the celebrity problem
                    if(celeb[j] != -1)
                        celeb[j] += 1;
                    celeb[i] = -1;    // Making i as non-celebrity as he knows j-th person
                }
            }
        }
        
        //Anyone who is know my all is the celebrity
        int result = -1;
        for(int i=0; i<n; i++)
            if(celeb[i] == n-1)
                result = i;
        return result;
    }
};
