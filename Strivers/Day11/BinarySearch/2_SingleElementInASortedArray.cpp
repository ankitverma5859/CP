// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        
        while(left < right){
            int mid = (left + right) >> 1;
            int next = mid % 2 == 0 ? mid+1 : mid -1;
            
            if(nums[mid] == nums[next])
                left = mid+1;
            else
                right = mid;
        }
        return left;
  }
};
