// Link: https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> subsets;
        map<string, int> m;
        
        int n = nums.size();
        int total_subsets = pow(2, n); // or 1 << n
        
        for(int i=0; i<total_subsets; i++){
            vector<int> subset;
            string s = "";
            for(int j=0; j<n; j++){
                if((i & (1 << j)) != 0)
                {
                    s += to_string(nums[j]);
                    subset.push_back(nums[j]);
                }
            }
            if(m.find(s) == m.end()){
                m[s] = 1;
                subsets.push_back(subset);
            }
        }
        
        return subsets;
    }
};
