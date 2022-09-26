// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int getPivot(vector<int>& nums, int size)
    {
        int left = 0, right = size - 1;
        while(left < right)
        {
            int mid = ((unsigned)left + (unsigned)right) / 2;
            if( nums[mid] >= nums[0] )
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    
    int binary_search(vector<int>& nums, int left, int right, int target)
    {
        while(left <= right)
        {
            int mid = ((unsigned)left + (unsigned)right) / 2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int size = nums.size();
        
        /*
        First find the pivot so that, we can decide which sorted part we can apply binary search on.
        */
        int pivot = getPivot(nums, size);
        //Apply the binary search on the left part if it falls in the range
        //Or else to the right part.
        
        // ** smaller numbers exist on the right side of pivot
        // ** bigger numbers exist on the left side of pivot
        if(target >= nums[pivot] and target <= nums[size - 1])
            return binary_search(nums, pivot, size - 1, target);
        else
            return binary_search(nums, 0, pivot -1, target);
    }
};
