// Link: https://leetcode.com/problems/subsets/
/*
  This problem deals with generating subsets of an array which is prerequiste to the next problem subsets sum.
  Approach:
    Number of total subsets of an array = 2 ^ n (where n is the number of elements in the array.)
    We use the bits approach to find the subsets. (https://www.includehelp.com/cpp-programs/print-all-possible-subset-of-a-set.aspx)
    
    Formula: (i & (1 << j)) != 0 to check if a bit is set or not
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        
        int n = nums.size();
        int total_subsets = pow(2, n);
        
        for(int i=0; i<total_subsets; i++){
            vector<int> subset;
            for(int j=0; j<n; j++){
                if((i & (1 << j)) != 0)
                    subset.push_back(nums[j]);
            }
            subsets.push_back(subset);
            for(auto i : subset)
                cout<<i;
            cout<<endl;
        }
        
        
        return subsets;
    }
};
