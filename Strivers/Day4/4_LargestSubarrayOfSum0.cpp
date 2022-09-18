// Link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Using Prefix Sum
// Approach: If you find prefix sum at two places as same, that means i+1 to j(last prefix) sum = 0.
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int i=0, j=0, sum =0;
        int max_len = 0;
        unordered_map<int, int> prefix_sum;
        while(j<n){
            sum += A[j];
            
            if(sum == 0)
                max_len = j + 1;
            
            if(prefix_sum.find(sum) != prefix_sum.end())
                max_len = max(max_len, j-prefix_sum[sum]);
            else{
                prefix_sum[sum] = j;
            }
            j++;
        }
        
        return max_len;
    }
};
