'''
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
'''

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start_idx = -1
        end_idx = -1

        # BS for Last Occurance
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = (l+r)//2
            if target == nums[mid]:
                if mid-1 >= 0 and nums[mid] == nums[mid-1]:
                    r = mid - 1
                else:
                    start_idx = mid
                    break
            elif target > nums[mid]:
                l = mid + 1
            elif target < nums[mid]:
                r = mid - 1
        
        # BS for Last Occurance
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = (l+r)//2
            if target == nums[mid]:
                if mid+1 < len(nums) and nums[mid] == nums[mid+1]:
                    l = mid + 1
                else:
                    end_idx = mid
                    break
            elif target > nums[mid]:
                l = mid + 1
            elif target < nums[mid]:
                r = mid - 1

        return [start_idx, end_idx]
