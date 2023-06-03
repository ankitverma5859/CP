'''
https://leetcode.com/problems/search-insert-position/description/
'''

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1

        res_idx = -1

        if len(nums) == 0:          # Edge Case: empty list
            return 0

        while l < r:                # Watchout: 
            mid = (l+r)//2
            if target == nums[mid]:
                return mid
            elif target > nums[mid]:
                l = mid + 1         # mid+1 could also be the result
            elif  target < nums[mid]:
                r = mid             # mid could also be the result
        
        # condition for the last element.
        return l+1 if nums[l] < target else l
