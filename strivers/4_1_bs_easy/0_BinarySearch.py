'''
https://leetcode.com/problems/binary-search/
https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-search
'''

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1
        target_idx = -1
        
        while l <= r:
            mid = (l + r) // 2
            if target == nums[mid]:
                target_idx = mid
                break
            elif target > nums[mid]:
                l = mid + 1
            elif target < nums[mid]:
                r = mid - 1
            
        return target_idx
