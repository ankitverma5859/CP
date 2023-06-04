'''
https://leetcode.com/problems/find-peak-element/submissions/963391566/
'''

# Time Complexity: O(n)
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        peak_element_idx = -1
        nums_len = len(nums)
        
        if nums_len == 1:
            return 0


        for idx in range(1, nums_len - 1):
            if nums[idx] > nums[idx-1] and nums[idx] > nums[idx+1]:
                peak_element_idx = idx
                break
        
        if peak_element_idx == -1:
            # Check for fist element
            if nums[0] > nums[1]:
                peak_element_idx = 0
            elif nums[len(nums)-1] > nums[len(nums)-2]:
                peak_element_idx = len(nums)-1

        return peak_element_idx
