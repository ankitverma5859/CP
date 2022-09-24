// Link: https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> result;
    
    void get_permutations(vector<int>& nums, int index){
        if(index == nums.size()){
            result.push_back(nums);
            return;
        }
        
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            get_permutations(nums, index+1);
            swap(nums[index], nums[i]);
        }
            
    }
    vector<vector<int>> permute(vector<int>& nums) {
        get_permutations(nums, 0);
        return result;
    }
};
